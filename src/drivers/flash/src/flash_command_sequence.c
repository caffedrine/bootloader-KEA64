/*
 * Copyright (c) 2013, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "utilities/fsl_assert.h"
#include "SSD_FTFx_Common.h"
#include "flash/flash.h"
#include "device/fsl_device_registers.h"
#include "fsl_platform_status.h"
#include "bootloader_common.h"
#include <string.h>

#if BL_TARGET_FLASH
//! @brief A function pointer used to point to relocated flash_run_command()
#define FTFx_REG_ACCESS_TYPE  volatile uint8_t *
static void (*callFlashRunCommand)(FTFx_REG_ACCESS_TYPE);

//! @brief Run flash command
//!
//! This function should be copied to RAM for execution to make sure that code works
//! properly even flash cache is disabled.
//! It is for flash-resident bootloader only, not technically required for ROM or
//! flashloader (RAM-resident bootloader).
void flash_run_command(FTFx_REG_ACCESS_TYPE ftfx_fstat)
{
    // clear CCIF bit
    *ftfx_fstat = FTFx_FSTAT_CCIF_MASK;

    // Check CCIF bit of the flash status register, wait till it is set.
    // IP team indicates that this loop will always complete.
    while (!((*ftfx_fstat) & FTFx_FSTAT_CCIF_MASK));
}

//! @brief Be used for determining the size of flash_run_command()
//!
//! This function must be defined that lexically follows flash_run_command(),
//! so we can determine the size of flash_run_command() at runtime and not worry
//! about toolchain or code generation differences.
void flash_run_command_end(void)
{}

//! @brief Copy flash_run_command() to RAM
//!
//! This function copys the memory between flash_run_command() and flash_run_command_end()
//! into the buffer which is also means that copying flash_run_command() to RAM.
void copy_flash_run_command(uint8_t *flashRunCommand)
{
    // Calculate the valid length of flash_run_command() memory
    uint32_t funcLength = (uint32_t)flash_run_command_end - (uint32_t)flash_run_command;

    assert(funcLength <= kFlashExecuteInRamFunction_MaxSize);

    // Since the value of ARM function pointer is always odd, but the real start address
    // of function memory should be even, that's why -1 and +1 operation exist.
    memcpy((void *)flashRunCommand, (void *)((uint32_t)flash_run_command - 1), funcLength);
    callFlashRunCommand = (void (*)(FTFx_REG_ACCESS_TYPE))((uint32_t)flashRunCommand + 1);
}
#endif

////////////////////////////////////////////////////////////////////////////////
//!
//! @brief Flash Command Sequence
//!
//! This function is used to perform the command write sequence to the flash.
//!
//! @param index Maximum index value of the command array.
//! @param pCommandArray Pointer to the array which contains the data to be
//!        written to the FCCOB registers.
//!
//! @return An error code or kStatus_Success
//!
////////////////////////////////////////////////////////////////////////////////
status_t flash_command_sequence(flash_driver_t * driver)
{
    // clear RDCOLERR & ACCERR & FPVIOL flag in flash status register
    FTFx_WR_FSTAT(FTFx, FTFx_FSTAT_RDCOLERR_MASK | FTFx_FSTAT_ACCERR_MASK | FTFx_FSTAT_FPVIOL_MASK);

#if BL_TARGET_FLASH
    status_t returnCode = flash_check_execute_in_ram_function_info(driver);
    if (kStatus_Success != returnCode)
    {
        return returnCode;
    }

    // We pass the ftfx_fstat address as a parameter to flash_run_comamnd() instead of using
    // pre-processed MICRO sentences or operating global variable in flash_run_comamnd()
    // to make sure that flash_run_command() will be compiled into position-independent code (PIC).
    callFlashRunCommand((FTFx_REG_ACCESS_TYPE)(&FTFx_FSTAT));
#else
    // clear CCIF bit
    FTFx_WR_FSTAT(FTFx, FTFx_FSTAT_CCIF_MASK);

    // Check CCIF bit of the flash status register, wait till it is set.
    // IP team indicates that this loop will always complete.
    while (!(FTFx_RD_FSTAT_CCIF(FTFx)));
#endif

    // Check error bits
    // Get flash status register value
    uint8_t registerValue = FTFx->FSTAT;

    // checking access error
    if (registerValue & FTFx_FSTAT_ACCERR_MASK)
    {
        return kStatus_FlashAccessError;
    }
    // checking protection error
    else if (registerValue & FTFx_FSTAT_FPVIOL_MASK)
    {
        return kStatus_FlashProtectionViolation;
    }
    // checking MGSTAT0 non-correctable error
    else if (registerValue & FTFx_FSTAT_MGSTAT0_MASK)
    {
        return kStatus_FlashCommandFailure;
    }

    return kStatus_Success;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////


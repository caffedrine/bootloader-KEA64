/*
 * Copyright (c) 2013-2014, Freescale Semiconductor, Inc.
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

#include "SSD_FTFx_Common.h"
#include "device/fsl_device_registers.h"
#include "flash/flash.h"
#include "fsl_platform_status.h"
#include "bootloader_common.h"
#include "flash_densities.h"
#include "bootloader/context.h"

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////
enum
{
    kFlashAccessSegmentBase = 256UL,
};


////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////

volatile uint32_t * const restrict kFCCOBx =
#if FSL_FEATURE_FLASH_IS_FTFA
    (volatile uint32_t *)&FTFA->FCCOB3;
#elif FSL_FEATURE_FLASH_IS_FTFE
    (volatile uint32_t *)&FTFE->FCCOB3;
#elif FSL_FEATURE_FLASH_IS_FTFL
    (volatile uint32_t *)&FTFL->FCCOB3;
#else
    #error "Unknown flash controller"
#endif

#if BL_TARGET_FLASH
//! @brief A static buffer used to hold flash_run_command()
static uint8_t s_flashRunCommand[kFlashExecuteInRamFunction_MaxSize];
//! @brief A static buffer used to hold flash_cache_clear_command()
static uint8_t s_flashCacheClearCommand[kFlashExecuteInRamFunction_MaxSize];

static flash_execute_in_ram_function_info_t s_flashExecuteInRamFunctionInfo = {
    .activeFunctionCount = 0,
    .flashRunCommand = s_flashRunCommand,
    .flashCacheClearCommand = s_flashCacheClearCommand,
};
#endif

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////
#if BL_TARGET_FLASH
// See SSD_FTFx_Common.h for documentation of this function.
status_t flash_check_execute_in_ram_function_info(flash_driver_t * driver)
{
    if (driver == NULL)
    {
        return kStatus_InvalidArgument;
    }

    flash_execute_in_ram_function_info_t *flashExecuteInRamFunctionInfo = (flash_execute_in_ram_function_info_t *)driver->flashExecuteInRamFunctionInfo;

    if (driver->flashExecuteInRamFunctionInfo && (kFlashExecuteInRamFunction_TotalNum == flashExecuteInRamFunctionInfo->activeFunctionCount))
    {
        return kStatus_Success;
    }

    return kStatus_FlashExecuteInRamFunctionNotReady;
}

// See flash.h for documentation of this function.
status_t flash_prepare_execute_in_ram_functions(flash_driver_t * driver)
{
    if (driver == NULL)
    {
        return kStatus_InvalidArgument;
    }

    flash_execute_in_ram_function_info_t *flashExecuteInRamFunctionInfo = (flash_execute_in_ram_function_info_t *)driver->flashExecuteInRamFunctionInfo;

    copy_flash_run_command(flashExecuteInRamFunctionInfo->flashRunCommand);
    copy_flash_cache_clear_command(flashExecuteInRamFunctionInfo->flashCacheClearCommand);
    flashExecuteInRamFunctionInfo->activeFunctionCount = kFlashExecuteInRamFunction_TotalNum;

    return kStatus_Success;
}
#endif

// See flash.h for documentation of this function.
status_t flash_init(flash_driver_t * driver)
{
    if (driver == NULL)
    {
        return kStatus_InvalidArgument;
    }

    // calculate the flash density from SIM_FCFG1.PFSIZE
    uint32_t flashDensity = kFlashDensities[SIM_RD_FCFG1_PFSIZE(SIM)] << 12;
    if (flashDensity == 0)
    {
        return kStatus_FlashSizeError;
    }
    // Invalid value
    if (flashDensity == (2048 * 1024))
    {
        flashDensity = FSL_FEATURE_FLASH_PFLASH_BLOCK_SIZE * FSL_FEATURE_FLASH_PFLASH_BLOCK_COUNT;
    }

    // fill out a few of the structure members
    driver->PFlashBlockBase = FLASH_BLOCK_BASE;
    driver->PFlashTotalSize = flashDensity;
    driver->PFlashBlockCount = FSL_FEATURE_FLASH_PFLASH_BLOCK_COUNT;
    driver->PFlashSectorSize = FSL_FEATURE_FLASH_PFLASH_BLOCK_SECTOR_SIZE;

#if FSL_FEATURE_FLASH_HAS_ACCESS_CONTROL
    driver->PFlashAccessSegmentSize =  kFlashAccessSegmentBase << FTFx->FACSS;
    driver->PFlashAccessSegmentCount = FTFx->FACSN;
#else
    driver->PFlashAccessSegmentSize =  0;
    driver->PFlashAccessSegmentCount = 0;
#endif // FSL_FEATURE_FLASH_HAS_ACCESS_CONTROL

    driver->PFlashCallback = NULL;

    // copy required flash commands to RAM
#if BL_TARGET_FLASH
    if (kStatus_Success != flash_check_execute_in_ram_function_info(driver))
    {
        driver->flashExecuteInRamFunctionInfo = &s_flashExecuteInRamFunctionInfo.activeFunctionCount;
        flash_prepare_execute_in_ram_functions(driver);
    }
#endif

    return kStatus_Success;
}

// See flash.h for documentation of this function.
status_t flash_register_callback(flash_driver_t * driver, flash_callback_t callback)
{
    if (driver == NULL)
    {
        return kStatus_InvalidArgument;
    }

    driver->PFlashCallback = callback;

    return kStatus_Success;
}



// See SSD_FTFx_Common.h for documentation of this function.
status_t flash_check_range(flash_driver_t * driver, uint32_t start, uint32_t lengthInBytes, uint32_t alignmentBaseline)
{
    if (driver == NULL)
    {
        return kStatus_InvalidArgument;
    }

    // Verify the start and length are alignmentBaseline aligned.
    if ((start & (alignmentBaseline - 1))
        || (lengthInBytes & (alignmentBaseline - 1)))
    {
        return kStatus_FlashAlignmentError;
    }

    // check for valid range of the target addresses
    if ((start < driver->PFlashBlockBase) ||
        ((start+lengthInBytes) > (driver->PFlashBlockBase + driver->PFlashTotalSize)))
    {
        return kStatus_FlashAddressError;
    }

    return kStatus_Success;
}

// See SSD_FTFx_Common.h for documentation of this function.
status_t flash_check_user_key(uint32_t key)
{
    // Validate the user key
    if (key != kFlashEraseKey)
    {
        return kStatus_FlashEraseKeyError;
    }

    return kStatus_Success;
}

// See SSD_FTFx_Common.h for documentation of this function.
status_t flash_check_access_ifr_range(flash_driver_t * driver, uint32_t index, uint32_t lengthInBytes)
{
    if (driver == NULL)
    {
        return kStatus_InvalidArgument;
    }

    switch(lengthInBytes)
    {
        case FLASH_PROGRAM_ONCE_UNIT_4BYTES:
            // Note: Have to seperate the first index from the rest if it equals 0
            //       to avoid a pointless comparison of unsigned int to 0 compiler warning
            if (   (index == FLASH_PROGRAM_ONCE_LOWER_MIN_ID_4BYTES) ||
            // Compare to the rest of the range
                 ( (index >= FLASH_PROGRAM_ONCE_LOWER_MIN_ID_4BYTES + 1) &&
                   (index <= FLASH_PROGRAM_ONCE_LOWER_MAX_ID_4BYTES) ) ||

                    (index == FLASH_PROGRAM_ONCE_UPPER_MIN_ID_4BYTES) ||
            // Compare to the rest of the range
                 ( (index >= FLASH_PROGRAM_ONCE_UPPER_MIN_ID_4BYTES + 1) &&
                   (index <= FLASH_PROGRAM_ONCE_UPPER_MAX_ID_4BYTES) ) )
            {
                return kStatus_Success;
            }
            break;
        case FLASH_PROGRAM_ONCE_UNIT_8BYTES:
            if ((index == FLASH_PROGRAM_ONCE_MIN_ID_8BYTES) ||
              ((index >= FLASH_PROGRAM_ONCE_MIN_ID_8BYTES +1) &&
             (index <= FLASH_PROGRAM_ONCE_MAX_ID_8BYTES)) )
            {
                return kStatus_Success;
            }
            break;
    }

    return kStatus_InvalidArgument;
}
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////


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
#include "flash/flash.h"
#include "fsl_platform_status.h"
#include "fsl_platform_types.h"
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////
// Definitionss
////////////////////////////////////////////////////////////////////////////////
#if FSL_FEATURE_FLASH_HAS_FLEX_RAM
    #if  defined (FTFE)
        #define FTFx_FCNFG_RAMRDY_MASK    FTFE_FCNFG_RAMRDY_MASK
    #elif defined (FTFL)
        #define FTFx_FCNFG_RAMRDY_MASK    FTFL_FCNFG_RAMRDY_MASK
    #elif defined (FTFA)
        #define FTFx_FCNFG_RAMRDY_MASK    FTFA_FCNFG_RAMRDY_MASK
    #endif //

enum
{
    kFlash_AccelerationRam_Size = 0x400
};
#endif // FSL_FEATURE_FLASH_HAS_SET_FLEXRAM_FUNCTION_CMD

////////////////////////////////////////////////////////////////////////////////
// Declarations
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

// See flash.h for documentation of this function.
status_t flash_program_section(flash_driver_t * driver, uint32_t start, uint32_t * src, uint32_t lengthInBytes)
{
#if (!FSL_FEATURE_FLASH_HAS_PROGRAM_SECTION_CMD)
    {
        return kStatus_FlashCommandNotSupported;
    }

#else
    if (src == NULL)
    {
        return kStatus_InvalidArgument;
    }

    // Check the supplied address range.
    status_t returnCode = flash_check_range(driver, start, lengthInBytes, FSL_FEATURE_FLASH_PFLASH_SECTION_CMD_ADDRESS_ALIGMENT);
    if (returnCode)
    {
        return returnCode;
    }

#if FSL_FEATURE_FLASH_HAS_SET_FLEXRAM_FUNCTION_CMD
    // Switch function of FlexRAM if needed
    bool needSwitchFlexRamMode = false;
    if (!(FTFx->FCNFG & FTFx_FCNFG_RAMRDY_MASK))
    {
        needSwitchFlexRamMode = true;

        returnCode = flash_set_flexram_function(driver, kFlash_FlexRAM_Available_As_RAM);
        if (returnCode != kStatus_Success)
        {
            return returnCode;
        }
    }
#endif // FSL_FEATURE_FLASH_HAS_SET_FLEXRAM_FUNCTION_CMD

    while(lengthInBytes > 0)
    {
        // Make sure the write operation doesn't span two sectors
        uint32_t endAddressOfCurrentSector = ALIGN_UP(start, driver->PFlashSectorSize);
        if (endAddressOfCurrentSector == start)
        {
            endAddressOfCurrentSector += driver->PFlashSectorSize;
        }

        uint32_t lengthTobeProgrammedOfCurrentSector;
        if (lengthInBytes + start > endAddressOfCurrentSector)
        {
            lengthTobeProgrammedOfCurrentSector = endAddressOfCurrentSector - start;
        }
        else
        {
            lengthTobeProgrammedOfCurrentSector = lengthInBytes;
        }

        uint32_t currentOffset = 0;
        // Program Current Sector
        while(lengthTobeProgrammedOfCurrentSector > 0)
        {
            // Make sure the program size doesn't exceeds Acceleration RAM size
            uint32_t programSizeOfCurrentPass;
            if(lengthTobeProgrammedOfCurrentSector > kFlash_AccelerationRam_Size)
            {
                programSizeOfCurrentPass = kFlash_AccelerationRam_Size;
            }
            else
            {
                programSizeOfCurrentPass = lengthTobeProgrammedOfCurrentSector;
            }

            // Copy data to FlexRAM
            memcpy((void*)FSL_FEATURE_FLASH_FLEX_RAM_START_ADDRESS,
                   src + currentOffset/4, programSizeOfCurrentPass);
            // Set start address of the data to be programmed
            kFCCOBx[0] = start + currentOffset;
            // Set program size in terms of  FSL_FEATURE_FLASH_PFLASH_SECTION_CMD_ADDRESS_ALIGMENT
            uint32_t numberOfPhases = programSizeOfCurrentPass / FSL_FEATURE_FLASH_PFLASH_SECTION_CMD_ADDRESS_ALIGMENT;

            FTFx_WR_FCCOBx(FTFx_BASE, 4, numberOfPhases >> 8);
            FTFx_WR_FCCOBx(FTFx_BASE, 5, numberOfPhases & 0xFF);
            // Set FTFx Command to PSEC
            FTFx_WR_FCCOBx(FTFx_BASE, 0, FTFx_PROGRAM_SECTION);
            // Peform command sequence
            returnCode = flash_command_sequence();

            // calling flash callback function if it is available
            if (driver->PFlashCallback)
            {
                driver->PFlashCallback();
            }

            if (returnCode != kStatus_Success)
            {
                break;
            }

            lengthTobeProgrammedOfCurrentSector -= programSizeOfCurrentPass;
            currentOffset += programSizeOfCurrentPass;
        }

        if (returnCode != kStatus_Success)
        {
            break;
        }

        src += currentOffset/4;
        start += currentOffset;
        lengthInBytes -= currentOffset;
    }

#if FSL_FEATURE_FLASH_HAS_SET_FLEXRAM_FUNCTION_CMD
    // Restore function of FlexRAM if needed.
    if (needSwitchFlexRamMode)
    {
        returnCode = flash_set_flexram_function(driver, kFlash_FlexRAM_Available_For_EEPROM);
    }
#endif // FSL_FEATURE_FLASH_HAS_SET_FLEXRAM_FUNCTION_CMD

    return returnCode;

#endif // FSL_FEATURE_FLASH_HAS_PROGRAM_SECTION_CMD
}


////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////

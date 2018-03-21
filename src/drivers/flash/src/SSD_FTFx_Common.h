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

#ifndef _SSD_FTFx_COMMON_H_
#define _SSD_FTFx_COMMON_H_

#include "flash/flash.h"
#include "bootloader_common.h"
#include <stdint.h>

/*!
 * @addtogroup SSD_FTFx_Common
 * @{
 */

/*******************************************************************************
 * Definitions
 ******************************************************************************/

/*!
 * @name Flash Program Once Field defines
 * @{
 */
#if defined(MK65F18_SERIES) || defined(MK66F18_SERIES) || defined(MK64F12_SERIES)
// For K64, K65 and K66 program-once, read-once, program-once are all 8 bytes operations.
#define FLASH_PROGRAM_ONCE_MIN_ID_8BYTES            0x0   //!< Minimum Index indcating one of Progam Once Fields which is accessed in 8-byte records
#define FLASH_PROGRAM_ONCE_MAX_ID_8BYTES            0xB   //!< Maximum Index indcating one of Progam Once Fields which is accessed in 8-byte records
#define FLASH_PROGRAM_ONCE_UNIT_8BYTES              8

#define FLASH_PROGRAM_ONCE_LOWER_MIN_ID_4BYTES      0x00   /*!< Minimum Index indcating one of Progam Once Fields which is accessed in 4-byte records for the lower range of indexes*/
#define FLASH_PROGRAM_ONCE_LOWER_MAX_ID_4BYTES      0x00   /*!< Maximum Index indcating one of Progam Once Fields which is accessed in 4-byte records for the lower range of indexes*/
#define FLASH_PROGRAM_ONCE_UPPER_MIN_ID_4BYTES      0x00   /*!< Lower Index of the high index bytes indcating one of Progam Once Fields which is accessed in 4-byte records*/
#define FLASH_PROGRAM_ONCE_UPPER_MAX_ID_4BYTES      0x00   /*!< Upper Index of the high index bytes indcating one of Progam Once Fields which is accessed in 4-byte records*/
#define FLASH_PROGRAM_ONCE_UNIT_4BYTES                 0

#else

#define FLASH_PROGRAM_ONCE_LOWER_MIN_ID_4BYTES      0x00   /*!< Minimum Index indcating one of Progam Once Fields which is accessed in 4-byte records for the lower range of indexes*/
#define FLASH_PROGRAM_ONCE_LOWER_MAX_ID_4BYTES      0x0F   /*!< Maximum Index indcating one of Progam Once Fields which is accessed in 4-byte records for the lower range of indexes*/
#define FLASH_PROGRAM_ONCE_UPPER_MIN_ID_4BYTES      0x20   /*!< Lower Index of the high index bytes indcating one of Progam Once Fields which is accessed in 4-byte records*/
#define FLASH_PROGRAM_ONCE_UPPER_MAX_ID_4BYTES      0x33   /*!< Upper Index of the high index bytes indcating one of Progam Once Fields which is accessed in 4-byte records*/
#define FLASH_PROGRAM_ONCE_UNIT_4BYTES                 4

#define FLASH_PROGRAM_ONCE_MIN_ID_8BYTES            0x10   //!< Minimum Index indcating one of Progam Once Fields which is accessed in 8-byte records
#define FLASH_PROGRAM_ONCE_MAX_ID_8BYTES            0x13   //!< Maximum Index indcating one of Progam Once Fields which is accessed in 8-byte records
#define FLASH_PROGRAM_ONCE_UNIT_8BYTES              8
#endif //defined(MK65F18_SERIES) || defined(MK66F18_SERIES) || defined(MK64F18_SERIES)


/*@}*/

/*!
 * @name Flash security status defines
 * @{
 */
#define FLASH_SECURITY_STATE_KEYEN         0x80
#define FLASH_SECURITY_STATE_UNSECURED     0x02
#define FLASH_NOT_SECURE                   0x01
#define FLASH_SECURE_BACKDOOR_ENABLED      0x02
#define FLASH_SECURE_BACKDOOR_DISABLED     0x04
/*@}*/

/*!
 * @name Flash controller command numbers
 * @{
 */
#define FTFx_VERIFY_BLOCK                  0x00 /*!< RD1BLK*/
#define FTFx_VERIFY_SECTION                0x01 /*!< RD1SEC*/
#define FTFx_PROGRAM_CHECK                 0x02 /*!< PGMCHK*/
#define FTFx_READ_RESOURCE                 0x03 /*!< RDRSRC*/
#define FTFx_PROGRAM_LONGWORD              0x06 /*!< PGM4*/
#define FTFx_PROGRAM_PHRASE                0x07 /*!< PGM8*/
#define FTFx_ERASE_BLOCK                   0x08 /*!< ERSBLK*/
#define FTFx_ERASE_SECTOR                  0x09 /*!< ERSSCR*/
#define FTFx_PROGRAM_SECTION               0x0B /*!< PGMSEC*/
#define FTFx_VERIFY_ALL_BLOCK              0x40 /*!< RD1ALL*/
#define FTFx_READ_ONCE                     0x41 /*!< RDONCE*/
#define FTFx_PROGRAM_ONCE                  0x43 /*!< PGMONCE*/
#define FTFx_ERASE_ALL_BLOCK               0x44 /*!< ERSALL*/
#define FTFx_SECURITY_BY_PASS              0x45 /*!< VFYKEY*/
#define FTFx_ERASE_ALL_BLOCK_UNSECURE      0x49 /*!< ERSALLU*/
#define FTFx_SWAP_CONTROL                  0x46 /*!< SWAP*/
#define FTFx_SET_FLEXRAM_FUNCTION          0x81 /*!< SETRAM*/
/*@}*/

/*! @brief Flash block base address*/
#define FLASH_BLOCK_BASE                   0x00

#if defined(FTFA)
    #define FTFx FTFA
    #define FTFx_BASE FTFA_BASE

    #define FTFx_FSTAT FTFA_FSTAT
    #define FTFx_WR_FSTAT FTFA_WR_FSTAT

    #define FTFx_FSTAT_CCIF_MASK FTFA_FSTAT_CCIF_MASK
    #define FTFx_FSTAT_RDCOLERR_MASK FTFA_FSTAT_RDCOLERR_MASK
    #define FTFx_FSTAT_ACCERR_MASK FTFA_FSTAT_ACCERR_MASK
    #define FTFx_FSTAT_FPVIOL_MASK FTFA_FSTAT_FPVIOL_MASK
    #define FTFx_FSTAT_MGSTAT0_MASK FTFA_FSTAT_MGSTAT0_MASK

    #define FTFx_WR_FCCOBx(x, n, v) FTFA_WR_FCCOB##n(x, v)

    #define FTFx_FSEC_SEC_MASK FTFA_FSEC_SEC_MASK
    #define FTFx_FSEC_KEYEN_MASK FTFA_FSEC_KEYEN_MASK
    #define FTFx_RD_FSTAT_CCIF FTFA_RD_FSTAT_CCIF
#elif defined(FTFE)
    #define FTFx FTFE
    #define FTFx_BASE FTFE_BASE

    #define FTFx_FSTAT FTFE_FSTAT
    #define FTFx_WR_FSTAT FTFE_WR_FSTAT

    #define FTFx_FSTAT_CCIF_MASK FTFE_FSTAT_CCIF_MASK
    #define FTFx_FSTAT_RDCOLERR_MASK FTFE_FSTAT_RDCOLERR_MASK
    #define FTFx_FSTAT_ACCERR_MASK FTFE_FSTAT_ACCERR_MASK
    #define FTFx_FSTAT_FPVIOL_MASK FTFE_FSTAT_FPVIOL_MASK
    #define FTFx_FSTAT_MGSTAT0_MASK FTFE_FSTAT_MGSTAT0_MASK

    #define FTFx_WR_FCCOBx(x, n, v) FTFE_WR_FCCOB##n(x, v)

    #define FTFx_FSEC_SEC_MASK FTFE_FSEC_SEC_MASK
    #define FTFx_FSEC_KEYEN_MASK FTFE_FSEC_KEYEN_MASK
    #define FTFx_RD_FSTAT_CCIF FTFE_RD_FSTAT_CCIF
#elif defined(FTFL)
    #define FTFx FTFL
    #define FTFx_BASE FTFL_BASE

    #define FTFx_FSTAT FTFL_FSTAT
    #define FTFx_WR_FSTAT FTFL_WR_FSTAT

    #define FTFx_FSTAT_CCIF_MASK FTFL_FSTAT_CCIF_MASK
    #define FTFx_FSTAT_RDCOLERR_MASK FTFL_FSTAT_RDCOLERR_MASK
    #define FTFx_FSTAT_ACCERR_MASK FTFL_FSTAT_ACCERR_MASK
    #define FTFx_FSTAT_FPVIOL_MASK FTFL_FSTAT_FPVIOL_MASK
    #define FTFx_FSTAT_MGSTAT0_MASK FTFL_FSTAT_MGSTAT0_MASK

    #define FTFx_WR_FCCOBx(x, n, v) FTFL_WR_FCCOB##n(x, v)

    #define FTFx_FSEC_SEC_MASK FTFL_FSEC_SEC_MASK
    #define FTFx_FSEC_KEYEN_MASK FTFL_FSEC_KEYEN_MASK
    #define FTFx_RD_FSTAT_CCIF FTFL_RD_FSTAT_CCIF
#else
    #error "Unknown flash controller"
#endif

/*******************************************************************************
 * Externs
 ******************************************************************************/

/*! @brief Word-aligned access to FCCOB registers.
 *
 * The FCCOB registers are arranged in an order such that writing little-endian
 * words comes out correctly. For instance, FCCOB3 is the LSB of word 0.
 *   - (Word 0) 0:FCCOB3, 1:FCCOB2, 2:FCCOB1, 3:FCCOB0
 *   - (Word 1) 4:FCCOB7, 5:FCCOB6, 6:FCCOB5, 7:FCCOB4
 *   - (Word 2) 8:FCCOBB, 9:FCCOBA, 10:FCCOB9, 11:FCCOB8
 */
extern volatile uint32_t * const restrict kFCCOBx;

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

#if BL_TARGET_FLASH
/*! @brief Copy flash_run_command() to RAM*/
void copy_flash_run_command(uint8_t *flashRunCommand);
/*! @brief Copy flash_cache_clear_command() to RAM*/
void copy_flash_cache_clear_command(uint8_t *flashCacheClearCommand);
/*! @brief Check whether flash execute-in-ram functions are ready*/
status_t flash_check_execute_in_ram_function_info(flash_driver_t * driver);
#endif

/*! @brief Internal function Flash command sequence. Called by driver APIs only*/
status_t flash_command_sequence(flash_driver_t * driver);

/*! @brief Internal function Flash cache clear. Called by driver APIs only*/
void flash_cache_clear(flash_driver_t * driver);

/*! @brief Validates the range and alignment of the given address range.*/
status_t flash_check_range(flash_driver_t * driver, uint32_t startAddress, uint32_t lengthInBytes, uint32_t alignmentBaseline);

/*! @brief Validates the given user key for flash erase APIs.*/
status_t flash_check_user_key(uint32_t key);

/*! @brief Validates the range and alignment of the given address range.*/
status_t flash_check_access_ifr_range(flash_driver_t * driver, uint32_t index, uint32_t lengthInBytes);

/*! @}*/

#endif /* _SSD_FTFx_COMMON_H_ */

/*******************************************************************************
 * EOF
 ******************************************************************************/



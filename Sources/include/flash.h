#ifndef FLASH_H_
#define FLASH_H_

#include <stdint.h>
#include <stdbool.h>

#include "derivative.h"
#include "definitions.h"
#include "bl_core.h"
#include "bl_cfg.h"

/******************************************************************

 FLASH related definitions, functions and local variables

 *******************************************************************/
//! @name Flash controller command numbers
//@{
#define FTFx_VERIFY_BLOCK                  0x00 //!< RD1BLK
#define FTFx_VERIFY_SECTION                0x01 //!< RD1SEC
#define FTFx_PROGRAM_CHECK                 0x02 //!< PGMCHK
#define FTFx_READ_RESOURCE                 0x03 //!< RDRSRC
#define FTFx_PROGRAM_LONGWORD              0x06 //!< PGM4
#define FTFx_PROGRAM_PHRASE                0x07 //!< PGM8
#define FTFx_ERASE_BLOCK                   0x08 //!< ERSBLK
#define FTFx_ERASE_SECTOR                  0x09 //!< ERSSCR
#define FTFx_PROGRAM_SECTION               0x0B //!< PGMSEC
#define FTFx_VERIFY_ALL_BLOCK              0x40 //!< RD1ALL
#define FTFx_READ_ONCE                     0x41 //!< RDONCE
#define FTFx_PROGRAM_ONCE                  0x43 //!< PGMONCE
#define FTFx_ERASE_ALL_BLOCK               0x44 //!< ERSALL
#define FTFx_SECURITY_BY_PASS              0x45 //!< VFYKEY
#define FTFx_ERASE_ALL_BLOCK_UNSECURE      0x49 //!< ERSALLU
#define FTFx_SWAP_CONTROL                  0x46 //!< SWAP
#define FTFx_SET_FLEXRAM_FUNCTION          0x81 //!< SETRAM
//@}

#if defined (FTFE)
#define FTFx    FTFE
#define BL_FEATURE_PROGRAM_PHASE    1
#elif defined (FTFL)
#define FTFx    FTFL
#define BL_FEATURE_PROGRAM_PHASE    0
#elif defined (FTFA)
#define FTFx    FTFA
#define BL_FEATURE_PROGRAM_PHASE    0
#elif defined (FTMRE)
#define FTFx    FTMRE
#define BL_FEATURE_PROGRAM_PHASE    0
#endif //

#define FTFx_FSTAT_CCIF_MASK        0x80u
#define FTFx_FSTAT_RDCOLERR_MASK    0x40u
#define FTFx_FSTAT_ACCERR_MASK      0x20u
#define FTFx_FSTAT_FPVIOL_MASK      0x10u
#define FTFx_FSTAT_MGSTAT0_MASK     0x01u
#define FTFx_FSEC_SEC_MASK          0x03u

static uint32_t s_flash_ram_function[8];

typedef void (*flash_run_entry_t)(volatile uint8_t *reg);
flash_run_entry_t s_flash_run_entry;

bool is_valid_memory_range(uint32_t start, uint32_t length);
status_t flash_program(uint32_t start, uint32_t *src, uint32_t length);
status_t flash_erase(uint32_t start, uint32_t length);

#if BL_FEATURE_VERIFY
	status_t flash_verify_program(uint32_t start, const uint32_t *expectedData, uint32_t length);
#endif

void flash_init(void);

#endif

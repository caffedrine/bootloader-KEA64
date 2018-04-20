#include "flash.h"

/*	Local Variables
//	  _     ___   ____    _    _       __     ___    ____  ____
//	 | |   / _ \ / ___|  / \  | |      \ \   / / \  |  _ \/ ___|
//	 | |  | | | | |     / _ \ | |       \ \ / / _ \ | |_) \___ \
//	 | |__| |_| | |___ / ___ \| |___     \ V / ___ \|  _ < ___) |
//	 |_____\___/ \____/_/   \_\_____|     \_/_/   \_\_| \_\____/
*/
static const uint8_t s_flash_command_run[] = { 0x00, 0xB5, 0x80, 0x21, 0x01, 0x70, 0x01, 0x78, 0x09, 0x06, 0xFC, 0xD5, 0x00, 0xBD };

volatile uint32_t* const kFCCOBx =
#if defined(FTFE)
		(volatile uint32_t*)&FTFE->FCCOB3;
#elif defined (FTEL)
		(volatile uint32_t*)&FTFL->FCCOB3;
#elif defined (FTFA)
		(volatile uint32_t*)&FTFA->FCCOB3;
#elif defined (FTMRH)
		(volatile uint32_t*)&FTMRH->FCCOBIX;
#endif

//	 _     ___   ____    _    _        _____ _   _ _   _  ____ _____ ___ ___  _   _ ____
//  | |   / _ \ / ___|  / \  | |      |  ___| | | | \ | |/ ___|_   _|_ _/ _ \| \ | / ___|
//	| |  | | | | |     / _ \ | |      | |_  | | | |  \| | |     | |  | | | | |  \| \___ \
//	| |__| |_| | |___ / ___ \| |___   |  _| | |_| | |\  | |___  | |  | | |_| | |\  |___) |
//	|_____\___/ \____/_/   \_\_____|  |_|    \___/|_| \_|\____| |_| |___\___/|_| \_|____/

__STATIC_INLINE uint32_t align_down(uint32_t data, uint32_t base)
{
	return (data & ~(base - 1));
}

__STATIC_INLINE uint32_t align_up(uint32_t data, uint32_t base)
{
	return align_down( data + base - 1, base );
}


//	 _____ _   _ _   _  ____ _____ ___ ___  _   _ ____
//	|  ___| | | | \ | |/ ___|_   _|_ _/ _ \| \ | / ___|
//	| |_  | | | |  \| | |     | |  | | | | |  \| \___ \
//	|  _| | |_| | |\  | |___  | |  | | |_| | |\  |___) |
//	|_|    \___/|_| \_|\____| |_| |___\___/|_| \_|____/

void flash_init(void)
{
	uint32_t i;
	uint8_t *ram_func_start = (uint8_t*)&s_flash_ram_function[0];

	for ( i = 0; i < sizeof(s_flash_command_run); i++ )
	{
		*ram_func_start++ = s_flash_command_run[i];
	}

	s_flash_run_entry = (flash_run_entry_t)((uint32_t)s_flash_ram_function + 1);
}

status_t flash_command_sequence(void)
{
	uint8_t fstat;
	status_t status = kStatus_Success;
	FTMRH_FSTAT = (FTFx_FSTAT_RDCOLERR_MASK | FTFx_FSTAT_ACCERR_MASK | FTFx_FSTAT_FPVIOL_MASK);

	__disable_irq();
	s_flash_run_entry( &FTMRH_FSTAT );
	__enable_irq();

	fstat = FTMRH_FSTAT;

	if ( fstat & FTFx_FSTAT_ACCERR_MASK )
	{
		status = kStatus_FlashAccessError;
	}
	else if ( fstat & FTFx_FSTAT_FPVIOL_MASK )
	{
		status = kStatus_FlashProtectionViolation;
	}
	else if ( fstat & FTFx_FSTAT_MGSTAT0_MASK )
	{
		status = kStatus_FlashCommandFailure;
	}

	return status;
}

status_t flash_erase(uint32_t start, uint32_t length)
{
	uint32_t alignedStart;
	uint32_t alignedLength;
	status_t status = kStatus_Success;
	alignedStart = align_down( start, TARGET_FLASH_SECTOR_SIZE );
	alignedLength = align_up( start - alignedStart + length, TARGET_FLASH_SECTOR_SIZE );

	while ( alignedLength )
	{
#if defined (FTMRE)  //JJ ADDER
		// Clear error flags
		FTMRE_FSTAT = 0x30;

		// Write index to specify the command code to be loaded
		FTMRE_FCCOBIX = 0x0;
		// Write command code and memory address bits[23:16]
		FTMRE_FCCOBHI = 0x0A;// EEPROM FLASH command
		FTMRE_FCCOBLO = start>>16;// memory address bits[23:16]
		// Write index to specify the lower byte memory address bits[15:0] to be loaded
		FTMRE_FCCOBIX = 0x1;
		// Write the lower byte memory address bits[15:0]
		FTMRE_FCCOBLO = start;
		FTMRE_FCCOBHI = start>>8;
#else
		kFCCOBx[0] = alignedStart;
		FTMRH_FCCOBIX = FTFx_ERASE_SECTOR;
#endif
		status = flash_command_sequence();
		if ( status != kStatus_Success )
		{
			break;
		}
		alignedStart += TARGET_FLASH_SECTOR_SIZE;
		alignedLength -= TARGET_FLASH_SECTOR_SIZE;
	}

	return status;
}

status_t flash_program(uint32_t start, uint32_t *src, uint32_t length)
{
	status_t status = kStatus_Success;
	uint8_t *byteSrcStart;
	uint32_t i;
#if BL_FEATURE_PROGRAM_PHASE
	uint8_t alignmentSize = 8;
#else
	uint8_t alignmentSize = 4;
#endif

#if BL_FEATURE_VERIFY
	uint32_t *compareSrc = (uint32_t*)src;
	uint32_t compareDst = start;
	uint32_t compareLength = align_up(length, alignmentSize);
#endif

	if ( start & (alignmentSize - 1) )
	{
		status = kStatus_FlashAlignmentError;
	}
	else if ( !is_valid_memory_range( start, length ) )
	{
		status = kStatusMemoryRangeInvalid;
	}
	else
	{
		while ( length )
		{
			if ( length < alignmentSize )
			{
				byteSrcStart = (uint8_t*)src;
				for ( i = length; i < alignmentSize; i++ )
				{
					byteSrcStart[i] = 0xFF;
				}
			}
#if defined (FTMRE)  //JJ ADDER
			FTMRE_FSTAT = 0x30;
			// Write index to specify the command code to be loaded
			FTMRE_FCCOBIX = 0x0;
			// Write command code and memory address bits[23:16]
			FTMRE_FCCOBHI = 0x06;// program FLASH command
			FTMRE_FCCOBLO = start>>16;// memory address bits[23:16]
			// Write index to specify the lower byte memory address bits[15:0] to be loaded
			FTMRE_FCCOBIX = 0x1;
			// Write the lower byte memory address bits[15:0]
			FTMRE_FCCOBLO = start;
			FTMRE_FCCOBHI = start>>8;
			// Write index to specify the word0 (MSB word) to be programmed
			FTMRE_FCCOBIX = 0x2;
#if     defined(BIG_ENDIAN)
			// Write the word  0
			FTMRE_FCCOBHI = (*src>>16)>>8;
			FTMRE_FCCOBLO = (*src>>16);
#else
			FTMRE_FCCOBHI = (*src) >>8;
			FTMRE_FCCOBLO = (*src);
#endif
			// Write index to specify the word1 (LSB word) to be programmed
			FTMRE_FCCOBIX = 0x3;
			// Write the word1
#if     defined(BIG_ENDIAN)
			FTMRE_FCCOBHI = (*src) >>8;
			FTMRE_FCCOBLO = (*src);
#else
			FTMRE_FCCOBHI = (*src>>16)>>8;
			FTMRE_FCCOBLO = (*src>>16);
#endif

			src = src+1;

#else  //JJADDER

			kFCCOBx[0] = start;
			kFCCOBx[1] = *src++;
#if BL_FEATURE_PROGRAM_PHASE
			kFCCOBx[2] = *src++;
#endif
#if BL_FEATURE_PROGRAM_PHASE
			FTFx->FCCOB0 = FTFx_PROGRAM_PHRASE;
#else
			FTMRH_FCCOBIX = FTFx_PROGRAM_LONGWORD;
#endif

#endif
			status = flash_command_sequence();
			if ( status != kStatus_Success )
			{
				break;
			}
			start += alignmentSize;
			length -= (length > alignmentSize) ? alignmentSize : length;
		}
	}

#if BL_FEATURE_VERIFY  //zero, not used
	if (kStatus_Success == status)
	{
		status = flash_verify_program(compareDst, compareSrc, compareLength);
	}
#endif

	return status;
}

#if BL_FEATURE_VERIFY
status_t flash_verify_program(uint32_t start, const uint32_t *expectedData, uint32_t lengthInBytes)
{
	status_t status = kStatus_Success;
	while(lengthInBytes)
	{
		kFCCOBx[0] = start;
		FTFx->FCCOB0 = FTFx_PROGRAM_CHECK;
		FTFx->FCCOB4 = 1; // 0-Normal, 1-User, 2-Factory
		kFCCOBx[2] = *expectedData;

		status = flash_command_sequence();
		if (kStatus_Success != status)
		{
			break;
		}
		else
		{
			start += 4;
			expectedData++;
			lengthInBytes -= 4;
		}
	}
	return status;
}
#endif

bool is_valid_memory_range(uint32_t start, uint32_t length)
{
	bool isValid = true;
	if ( (start < APPLICATION_BASE) || ((start + length) < APPLICATION_BASE) )
	{
		isValid = false;
	}

	return isValid;
}


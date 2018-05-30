//	  _   ___        __    ____ ___  _   _ _____ ___ ____
//	 | | | \ \      / /   / ___/ _ \| \ | |  ___|_ _/ ___|
//	 | |_| |\ \ /\ / /   | |  | | | |  \| | |_   | | |  _
//	 |  _  | \ V  V /    | |__| |_| | |\  |  _|  | | |_| |
//	 |_| |_|  \_/\_/      \____\___/|_| \_|_|   |___\____|
#ifndef __BL_BSP_H__
#define __BL_BSP_H__

#include <stdint.h>
#include <stdbool.h>
#include <derivative.h>

#include "bl_cfg.h"
#include "GPIO/GPIO.h"
#include "UART/UART.h"

int hardware_init(void)
{
	uint16_t err = 0x3000;
	uint8_t clkDIV = 20000000L / 1000000L - 1;

	/* enable stalling flash controller when flash is busy */
	MCM_PLACR |= MCM_PLACR_ESFC_MASK;

	if ( !(FTMRH_FSTAT & FTMRH_FSTAT_CCIF_MASK) )
	{
		err |= 0x3000 + 0x14;
		return (err);
	}

	/* initialize the flash clock to be within spec 1MHz */
	if ( !(FTMRH_FCLKDIV & FTMRH_FCLKDIV_FDIVLCK_MASK) )
	{
		/* FCLKDIV register is not locked */
		if ( (FTMRH_FCLKDIV & FTMRH_FCLKDIV_FDIVLD_MASK) &&
				((FTMRH_FCLKDIV & FTMRH_FCLKDIV_FDIV_MASK) != FTMRH_FCLKDIV_FDIV( clkDIV )) )
		{
			/* flash clock prescaler is loaded but with wrong value */
			err |= 0x3000 + 0x18;
			return (err);
		}
		FTMRH_FCLKDIV = (FTMRH_FCLKDIV & ~(FTMRH_FCLKDIV_FDIV_MASK)) | FTMRH_FCLKDIV_FDIV( clkDIV );
	}
	else
	{
		/* FCLKDIV register is locked */
		if ( (FTMRH_FCLKDIV & FTMRH_FCLKDIV_FDIV_MASK) != FTMRH_FCLKDIV_FDIV( clkDIV ) )
		{
			/* flash clock prescaler is wrong */
			err |= 0x3000 + 0x18;
			return (err);
		}
	}

	/* No error */
	return 0;
}

void pins_init(void)
{
	// Init GPIO pin used to enter or not in bootloader
	CONFIG_PIN_AS_GPIO( ENB_BOOT_PORT, ENB_BOOT_PIN, INPUT );		// Button pin as input as it shall provide a digital value
	ENABLE_INPUT( ENB_BOOT_PORT, ENB_BOOT_PIN );					// Enable input on button

	// Indicator led
	CONFIG_PIN_AS_GPIO( LED_PORT, LED_PIN, OUTPUT );				// Led pin as output as there is a LED
	OUTPUT_CLEAR( LED_PORT, LED_PIN );								// Clear led pin at the beginning
}

bool stay_in_bootloader(void)
{
	uint32_t *vectorTable = (uint32_t*)APPLICATION_BASE;
	uint32_t pc = vectorTable[1];
	if ( pc < APPLICATION_BASE || pc > TARGET_FLASH_SIZE )
	{
		return true;
	}
	else
	{
		return false;
	}
}

void bl_hw_if_write(const uint8_t *buffer, uint32_t length)
{
	uint8_t bytesWritten = 0;

	while(bytesWritten < length)
	{
		Uart_Write((BL_UART == UART0) ? 0 : ((BL_UART == UART1) ? 1 : 2), buffer, length, &bytesWritten);
	}
}

uint8_t bl_hw_if_read_byte(void)
{
	uint8_t tmpBytesRead = 0, c;

	while(tmpBytesRead == 0)
	{
		Uart_Read((BL_UART == UART0) ? 0 : ((BL_UART == UART1) ? 1 : 2), &c, 1, &tmpBytesRead);
	}
	return c;
}

#endif // __BL_BSP_H__

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

__STATIC_INLINE void Uart_init(void)
{
    uint16_t u16Sbr;
    uint8_t u8Temp;

	/* Enable the clock to the selected UART */
    if (BL_UART == UART0)
	{
		SIM->SCGC |= SIM_SCGC_UART0_MASK;
	}
	else if (BL_UART == UART1)
	{
        SIM->SCGC |= SIM_SCGC_UART1_MASK;
	}
    else
	{
        SIM->SCGC |= SIM_SCGC_UART2_MASK;
	}

    /* Make sure that the transmitter and receiver are disabled while we
     * change settings.
     */
    BL_UART->C2 &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK );

    /* Configure the UART for 8-bit mode, no parity */
    BL_UART->C1 = 0;					//we need default settings so entire register is cleared

    /* Calculate baud settings */
    u16Sbr = ((( DEFAULT_SYSTEM_CLOCK / 2 )>>4) + (BL_UART_BAUDRATE>>1))/BL_UART_BAUDRATE;

    /* Save off the current value of the UARTx_BDH except for the SBR field */
    u8Temp = BL_UART->BDH & ~(UART_BDH_SBR_MASK);

    BL_UART->BDH = u8Temp |  UART_BDH_SBR(u16Sbr >> 8);
    BL_UART->BDL = 128;//(uint8_t)(u16Sbr & UART_BDL_SBR_MASK);								//!!!!!

    /* Enable receiver and transmitter */
    BL_UART->C2 |= (UART_C2_TE_MASK | UART_C2_RE_MASK );
}

__STATIC_INLINE int hardware_init(void)
{
	uint16_t err = 0x3000;
	uint8_t clkDIV = 20000000L / 1000000L - 1;

	MCM_PLACR |= MCM_PLACR_ESFC_MASK; 			/* enable stalling flash controller when flash is busy */

	if ( !(FTMRH_FSTAT & FTMRH_FSTAT_CCIF_MASK) )
	{
		err |= 0x3000 + 0x14;
		return (err);
	}

	/* initialize the flash clock to be within spec 1MHz 
	 */
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

	/*
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK
	        | SIM_SCGC5_PORTB_MASK
	        | SIM_SCGC5_PORTC_MASK
	        | SIM_SCGC5_PORTD_MASK
	        | SIM_SCGC5_PORTE_MASK;

	// Set Clock divider
	SIM->CLKDIV1 = SIM_CLKDIV1_OUTDIV1( 0 ) | SIM_CLKDIV1_OUTDIV2( 0 ) | SIM_CLKDIV1_OUTDIV3( 0 ) | SIM_CLKDIV1_OUTDIV4( 1 );

	PORTD->PCR[6] = PORT_PCR_MUX( 3 ); // UART_RX
	PORTD->PCR[7] = PORT_PCR_MUX( 3 ); // UART_TX
	//*/

	/* No error */
	return 0;
}

__STATIC_INLINE void pins_init(void)
{
	/* ENB_BOOT PIN */
	CONFIG_PIN_AS_GPIO( ENB_BOOT_PORT, ENB_BOOT_PIN, INPUT );		// Button pin as input as it shall provide a digital value
	ENABLE_INPUT( ENB_BOOT_PORT, ENB_BOOT_PIN );					// Enable input on button

	/* Signalizing LED */
	CONFIG_PIN_AS_GPIO( LED_PORT, LED_PIN, OUTPUT );				// Led pin as output
	OUTPUT_CLEAR( LED_PORT, LED_PIN );
}

__STATIC_INLINE bool stay_in_bootloader(void)
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

__STATIC_INLINE void bl_hw_if_write(const uint8_t *buffer, uint32_t length)
{
	while ( length-- )
	{
		while ( !(BL_UART->S1 & UART_S1_TDRE_MASK) );

		for(int i = 0; i <= 5000; i++);

		(void)BL_UART->S1;	/* Read UART2_S1 register*/
		BL_UART->D = *buffer++;
	}
}

__STATIC_INLINE uint8_t bl_hw_if_read_byte(void)
{
	while ( !(BL_UART->S1 & UART_S1_RDRF_MASK) );

	for(int i = 0; i <= 500; i++);


	(void)BL_UART->S1;	/* Read UART2_S1 register*/
	return BL_UART->D;	/* Return data */
}

#endif // __BL_BSP_H__

#ifndef __BL_BSP_H__
#define __BL_BSP_H__

#include <stdint.h>
#include <stdbool.h>
#include <derivative.h>
#include "bl_cfg.h"

#define BL_UART     UART2

__STATIC_INLINE void uart_init(void)
{
	/*
	 SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;

	 //Make sure that the transmitter and receiver are disabled while we
	 //change settings.
	 BL_UART->C2 &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK );

	 // Configure the uart for 8-bit mode, no parity
	 BL_UART->C1 = 0;    // We need all default settings, so entire register is cleared

	 BL_UART->BDH = 0x00;
	 BL_UART->BDL = 0x0B;
	 BL_UART->C4 = 0x0B;

	 // Flush the RX and TX FIFO's
	 BL_UART->CFIFO = UART_CFIFO_RXFLUSH_MASK | UART_CFIFO_TXFLUSH_MASK;

	 // Enable receiver and transmitter
	 BL_UART->C2 |= (UART_C2_TE_MASK | UART_C2_RE_MASK );
	 */
	SIM_SCGC |= SIM_SCGC_UART2_MASK;    /* Enable bus clock in UART2*/
	UART2_BDH = 0; 						/* One stop bit*/
	UART2_BDL = 128; 					/* Baud rate at 9600*/
	UART2_C1 = 0; 						/* No parity enable,8 bit format*/
	UART2_C2 |= UART_C2_TE_MASK; 		/* Enable Transmitter*/
	UART2_C2 |= UART_C2_RE_MASK; 		/* Enable Receiver*/
	UART2_C2 |= UART_C2_RIE_MASK; 		/* Enable Receiver interrupts*/
}

__STATIC_INLINE void hardware_init(void)
{
	uint16_t err = 0x3000;
	uint8_t clkDIV = 20000000L / 1000000L - 1;

	MCM_PLACR |= MCM_PLACR_ESFC_MASK; /* enable stalling flash controller when flash is busy */

	if ( !(FTMRH_FSTAT & FTMRH_FSTAT_CCIF_MASK) )
	{
		err |= 0x3000 + 0x14;
		//	return err;
	}
	/* initialize the flash clock to be within spec 1MHz 
	 * 
	 */
	if ( !(FTMRH_FCLKDIV & FTMRH_FCLKDIV_FDIVLCK_MASK) )
	{
		/* FCLKDIV register is not locked */
		if ( (FTMRH_FCLKDIV & FTMRH_FCLKDIV_FDIVLD_MASK) &&
				((FTMRH_FCLKDIV & FTMRH_FCLKDIV_FDIV_MASK) != FTMRH_FCLKDIV_FDIV( clkDIV )) )
		{
			/* flash clock prescaler is loaded but with wrong value */
			err |= 0x3000 + 0x18;
			//return (err);
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
		}
	}
	/*
	 SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK \
               | SIM_SCGC5_PORTB_MASK  \
               | SIM_SCGC5_PORTC_MASK  \
               | SIM_SCGC5_PORTD_MASK \
               | SIM_SCGC5_PORTE_MASK;

	 // Set Clock divider
	 SIM->CLKDIV1 = SIM_CLKDIV1_OUTDIV1(0) | SIM_CLKDIV1_OUTDIV2(0)|SIM_CLKDIV1_OUTDIV3(0)|SIM_CLKDIV1_OUTDIV4(1);

	 PORTD->PCR[6] = PORT_PCR_MUX(3); // UART_RX
	 PORTD->PCR[7] = PORT_PCR_MUX(3); // UART_TX
	 */
}

__STATIC_INLINE bool stay_in_bootloader(void)
{
	uint32_t *vectorTable = (uint32_t*)APPLICATION_BASE;
	uint32_t pc = vectorTable[1];
	if ( pc < APPLICATION_BASE || pc > TARGET_FLASH_SIZE )
	{
		uart_init();
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
		while ( !(BL_UART->S1 & UART_S1_TDRE_MASK) )
			;

//		for ( int i = 0; i <= 2000; i++ )
//			;						// This is devil!

		BL_UART->D = *buffer++;
	}
}

__STATIC_INLINE uint8_t bl_hw_if_read_byte(void)
{
	while ( !(BL_UART->S1 & UART_S1_RDRF_MASK) )
	{
	}
	return BL_UART->D;
}

#endif // __BL_BSP_H__

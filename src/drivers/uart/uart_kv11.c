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

#include "bootloader_common.h"
#include "fsl_platform_common.h"
#include "uart.h"
#include <stdarg.h>

#if BL_CONFIG_UART

static uart_data_sink_func_t s_uart_data_sink_callback;

/********************************************************************/
/*
 * Resets UART
 *
 * Parameters:
 */
void uart_reset (UART_Type * uartch)
{
    // Restore those control and configuration registers which are used to
    // be operated
    uartch->C2 = 0;
    uartch->C1 = 0;
    uartch->BDH = 0;
    uartch->BDL = 0x4u;
    uartch->C4 = 0;
    uartch->CFIFO = 0;
}
/********************************************************************/

/********************************************************************/
/*
 * Initialize the uart for 8N1 operation, interrupts disabled, and
 * no hardware flow-control
 *
 * NOTE: Since the uarts are pinned out in multiple locations on most
 *       Kinetis devices, this driver does not enable uart pin functions.
 *       The desired pins should be enabled before calling this init function.
 *
 * Parameters:
 *  uartch      uart channel to initialize
 *  uartclk     uart module Clock in Hz(used to calculate baud)
 *  baud        uart baud rate
 */
status_t uart_init (UART_Type * uartch, int uartclk, int baud, uart_data_sink_func_t function)
{
    uint8_t i;
    uint32_t calculatedBaud = 0;
    uint32_t baudDiff = ~0;
    uint32_t brfaVal = 0;
    uint32_t sbrVal;
    uint32_t temp = 0;

    s_uart_data_sink_callback = function;

    // Calculate the SBR with a BRFA of 0
    sbrVal = uartclk / (16 * (uint32_t)(baud));
    calculatedBaud = uartclk / (16 * sbrVal);

    // Make sure the SBR is at least a step higher than the baud we want
    // then tune it down by adding the fractional divisor below
    if (calculatedBaud < baud)
    {
        sbrVal -= 1;
    }

    if (calculatedBaud != baud)
    {
        // Now tune to the best BRFA value
        for (i = 1; i <= 32; i++)
        {
            calculatedBaud = (2 * uartclk) / ((32 * sbrVal) + i);
 //           calculatedBaud = (uartclk) / ((16 * sbrVal) + i);

            if (calculatedBaud > baud)
            {
                temp = calculatedBaud - baud;
            }
            else
            {
                temp = baud - calculatedBaud;
            }

            if (temp <= baudDiff)
            {
                baudDiff = temp;
                brfaVal = i;
            }
        }
    }
    if (baudDiff < ((baud / 100) * 3))
    {
        switch((uint32_t)uartch)
        {
            case (uint32_t)UART0:
                // Enable clocking to UART0
                NVIC_EnableIRQ(UART0_IRQn);
                SIM_SET_SCGC4(SIM, SIM_SCGC4_UART0_MASK);
                break;
        }

        //Make sure that the transmitter and receiver are disabled while we
        //change settings.

        uartch->C2 &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK );

        // Configure the uart for 8-bit mode, no parity
        uartch->C1 = 0;    // We need all default settings, so entire register is cleared

        // Save off the current value of the uartx_BDH except for the SBR field
        temp = uartch->BDH & ~(UART_BDH_SBR(0x1F));

        uartch->BDH = temp |  UART_BDH_SBR(((sbrVal & 0x1F00) >> 8));
        uartch->BDL = (uint8_t)(sbrVal & UART_BDL_SBR_MASK);
        uartch->C4 = (uartch->C4 & ~(UART_C4_BRFA_MASK)) | (brfaVal << UART_C4_BRFA_SHIFT);

        // Flush the RX and TX FIFO's
        uartch->CFIFO = UART_CFIFO_RXFLUSH_MASK | UART_CFIFO_TXFLUSH_MASK;

        // Enable receive interrupts
        uartch->C2 |= UART_C2_RIE_MASK;

        // Enable receiver and transmitter
        uartch->C2 |= (UART_C2_TE_MASK | UART_C2_RE_MASK );

        return kStatus_Success;
    }
    else
    {
        // Unacceptable baud rate difference
        // More than 3% difference!!
        return kStatus_Fail;
    }
}

/********************************************************************/
/*
 * UART1 IRQ Handler
 *
 */
void UART0_IRQHandler(void)
{
    if (UART0->S1 & UART_S1_RDRF_MASK)
    {
        s_uart_data_sink_callback(UART0->D);
    }
}

/********************************************************************/
/*
 * Wait for space in the uart Tx FIFO and then send a character
 *
 * Parameters:
 *  channel      uart channel to send to
 *  ch             character to send
 */
void uart_putchar (UART_Type * channel, char ch)
{
    // Wait until space is available in the FIFO
    while(!(channel->S1 & UART_S1_TDRE_MASK));

    // Send the character
    channel->D = (uint8_t)ch;
}

/********************************************************************/
/*
 * Shutdown UART1 or UART2
 *
 * Parameters:
 *  uartch      the UART to shutdown
 *
 */
void uart_shutdown (UART_Type * uartch)
{
    // Disable interrupt
    switch((uint32_t)uartch)
    {
        case (uint32_t)UART0:
            NVIC_DisableIRQ(UART0_IRQn);
            break;
    }

    // In case uart peripheral isn't active which also means uart clock doesn't open,
    // So enable clocking to UARTx in any case, then we can write control register.
    switch((uint32_t)uartch)
    {
        case (uint32_t)UART0:
            // Enable clocking to UART0
            SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;
            break;
    }

    // Reset UART registers
    uart_reset(uartch);

    // Gate the uart clock.
    switch((uint32_t)uartch)
    {
        case (uint32_t)UART0:
            // Disable clocking to UART0
            SIM_CLR_SCGC4(SIM, SIM_SCGC4_UART0_MASK);
            break;    }
}

#endif // BL_CONFIG_UART

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////

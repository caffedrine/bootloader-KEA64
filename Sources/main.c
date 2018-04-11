/******************************************************************************								
 *    LAB1 - Serial Communications Interface (UART)                            	*
 *                                                                             	*
 *       This lab demonstrates how to use the UART module to receive and send  	*
 *    characters. Using interrupts, it waits for characters sent from a PC     	*
 *    terminal and echoes the received data.									  									*
 *    										                                  											*
 *       To use this demo you need to open a  serial terminal. The OpenSDA port  *
 *       is used to communicate via UART2 to the KEA128 microcontroller.         *
 *                                                                             	*
 *       Open the Terminal Utility and set the baud rate to 9600, leave all    	*
 *    the other settings with the default values. Every character you write to 	*
 *		 the serial console will be replied by the KEA128 MCU.                  		*
 ******************************************************************************/

/**********************************************************************************************
 * External objects
 **********************************************************************************************/
#include "Headers/derivative.h" /* include peripheral declarations */
#include "Headers/UART.h"
#include "Headers/CLK.h"
/**********************************************************************************************
 * Global variables
 **********************************************************************************************/

/**********************************************************************************************
 * Constants and macros
 **********************************************************************************************/

/**********************************************************************************************
 * Local types
 **********************************************************************************************/

/**********************************************************************************************
 * Local function prototypes
 *********************************************************************************************/
void Enable_Interrupt(UINT8 vector_number);
void Uart_Interrupt(UINT8 data);

/**********************************************************************************************
 * Local variables
 **********************************************************************************************/

/**********************************************************************************************
 * Local functions
 **********************************************************************************************/

/**********************************************************************************************
 * Global functions
 **********************************************************************************************/

/***********************************************************************************************
 *
 * @brief    main() - Program entry function
 * @param    none
 * @return   none
 *
 ************************************************************************************************/
int main2(void)
{
	UINT32 counter = 0;
	Clk_Init(); /* Configure clocks to run at 20 Mhz */
	UART_Init(); /*Initialize Uart 2 at 9600 bauds */
	Uart_SetCallback( Uart_Interrupt ); /* Set the callback function that the UART driver will call when receiving a char */
	NVIC_EnableIRQ( UART2_IRQn ); /* Enable UART2 interrupt */

	Uart_SendChar( 0x55 );
	Uart_SendChar( 0x55 );
	Uart_SendChar( 0x55 );
	Uart_SendChar( 0x55 );

	for ( ;; )
	{
		counter++;
	}
}

/***********************************************************************************************
 *
 * @brief    Uart_Interrupt(UINT8 data). Serial reception callback. This function is called each time a character
 * 				is received on the serial port.
 * @param    data received from serial port
 * @return   none
 *
 ************************************************************************************************/
//void Uart_Interrupt(UINT8 data)
//{
//	Uart_SendChar( data ); /* Echos data that is received*/
//}


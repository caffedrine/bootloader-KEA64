/*
 * test_UART.h
 *
 *  Created on: May 31, 2018
 *      Author: Alex C.
 */
#ifndef TEST_UART_H_
#define TEST_UART_H_

#include "bl_core.h"
#include "bl_bsp.h"

#include "CLK/CLK.h"

void test_UART()
{
	/* Clock init */
	Clk_Init();

	/* Uart init */
	Uart_init();

	/* Init hardware and stuff */
	//int initState = hardware_init();

	/* Initialize GPIO pins. E.g. led used to signal bootloader running*/
	pins_init();

	int i = 0;
	uint8_t recvBytes[12] = {0};

	while(1)
	{
		uint8_t c = bl_hw_if_read_byte();
		recvBytes[i++] = c;

		if(i >= 12)
		{
			i = 0;
		}
	}
}


#endif /* TEST_UART_H_ */

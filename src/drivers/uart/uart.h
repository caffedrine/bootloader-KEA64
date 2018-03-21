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

#ifndef __uart_H__
#define __uart_H__

#include "device/fsl_device_registers.h"
#include "fsl_platform_status.h"

/*!
 * @addtogroup uart_driver
 * @{
 */

/////////////////////////////////////////////////////////////////////////////
// API
/////////////////////////////////////////////////////////////////////////////

//! @name UART Driver
//@{

//! @brief Type of callback for uart data sink
typedef void (*uart_data_sink_func_t)(uint8_t byte);

/*! @brief Reset UART peripheral
 *
 * @param uartch UART peripheral base address
 */
void uart_reset (UART_Type * uartch);

/*! @brief Initialize UART peripheral
 *
 * @param uartch UART peripheral base address
 * @param uartclk UART peripheral clock frequency
 * @param baud UART baud rate
 * @param function data sink callback function
 *
 * @return An error code or kStatus_Success
 */
status_t uart_init (UART_Type * uartch, int uartclk, int baud, uart_data_sink_func_t function);

/*! @brief Send data from UART with format 8-N-1
 *
 * @param channel UART peripheral base address
 * @param ch data to send
 *
 */
void uart_putchar (UART_Type * channel, char ch);

/*! @brief Shutdown UART peripheral
 *
 * @param uartch UART peripheral base address
 *
 */
void uart_shutdown (UART_Type * uartch);
//@}

/*! @}*/

#endif /* __uart_H__ */

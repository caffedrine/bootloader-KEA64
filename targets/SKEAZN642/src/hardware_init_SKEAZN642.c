/*
 * Copyright (c) 2013-2015, Freescale Semiconductor, Inc.
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
#include "bootloader/context.h"
#include "fsl_device_registers.h"
#include "drivers/uart/scuart.h"
#include "utilities/kinetis_family.h"
#include "smc/smc.h"

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

#define UART1_RX_GPIO_PIN_NUM 1  // PIN 1 in the PTE group
#define UART1_RX_ALT_MODE 3      // ALT mode for UART1 functionality for pin 1
#define UART1_RX_GPIO_ALT_MODE 1 // ALT mdoe for GPIO functionality for pin 1

#define UART1_TX_GPIO_PIN_NUM 0  // PIN 0 in the PTE group
#define UART1_TX_ALT_MODE 3      // ALT mode for UART1 TX functionality for pin 0

#define PORT_IRQC_INTERRUPT_FALLING_EDGE 0xA
#define PORT_IRQC_INTERRUPT_DISABLE 0

//! CAN pinmux configurations
#define CAN0_RX_PORT_BASE         PORTB
#define CAN0_RX_GPIO_PIN_NUM      19   // PIN 19 in the PTB group
#define CAN0_RX_FUNC_ALT_MODE     2    // ALT mode for CAN0 RX functionality
#define CAN0_TX_PORT_BASE         PORTB
#define CAN0_TX_GPIO_PIN_NUM      18   // PIN 18 in the PTB group
#define CAN0_TX_FUNC_ALT_MODE     2    // ALT mode for CAN0 TX functionality

#define BOOT_PIN_NUMBER     12
#define BOOT_PIN_PORT       PORTC
#define BOOT_PIN_GPIO       PTC
#define BOOT_PIN_ALT_MODE   1
#define BOOT_PIN_ASSERT_POL 0

#define BOOT_PIN_DEBOUNCE_READ_COUNT 500

////////////////////////////////////////////////////////////////////////////////
// Variables
////////////////////////////////////////////////////////////////////////////////
//! this is to store the function pointer for calling back to the function that wants
//! the UART RX instance pin that triggered the interrupt.
static pin_irq_callback_t s_pin_irq_func[UART_INSTANCE_COUNT] = {0};

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

/* This function is called for configurating pinmux for uart module
 * This function only support switching default or gpio or fixed-ALTx mode on fixed pins
 * (Although there are many ALTx-pinmux configuration choices on various pins for the same
 * peripheral module) */
void uart_pinmux_config(unsigned int instance, pinmux_type_t pinmux)
{
    switch(instance)
    {
        case 0:
            break;
#if BL_CONFIG_SCUART
        case 1:
            switch(pinmux)
            {
                case kPinmuxType_Default:
                    PORT_BWR_PCR_MUX(PORTE, UART1_RX_GPIO_PIN_NUM, 0);
                    PORT_BWR_PCR_MUX(PORTE, UART1_TX_GPIO_PIN_NUM, 0);
                    break;
                case kPinmuxType_GPIO:
                    PORT_BWR_PCR_MUX(PORTE, UART1_RX_GPIO_PIN_NUM, UART1_RX_GPIO_ALT_MODE); // Set UART1_RX pin in GPIO mode
                    GPIO_CLR_PDDR(PTE, 1 << UART1_RX_GPIO_PIN_NUM);                    // Set UART1_RX pin as an input
                    break;
                case kPinmuxType_Peripheral:
                    PORT_BWR_PCR_MUX(PORTE, UART1_RX_GPIO_PIN_NUM, UART1_RX_ALT_MODE);   // Set UART1_RX pin to UART1_RX functionality
                    PORT_BWR_PCR_MUX(PORTE, UART1_TX_GPIO_PIN_NUM, UART1_TX_ALT_MODE);   // Set UART1_TX pin to UART1_TX functionality
                    break;
                default:
                    break;
            }
            break;
#endif // BL_CONFIG_SCUART
        case 2:
            break;
        default:
            break;
    }
}

/* This function is called for configurating pinmux for i2c module
 * This function only support switching default or gpio or fixed-ALTx mode on fixed pins
 * (Although there are many ALTx-pinmux configuration choices on various pins for the same
 * peripheral module) */
void i2c_pinmux_config(unsigned int instance, pinmux_type_t pinmux)
{
    switch(instance)
    {
#if BL_CONFIG_LPI2C
        case 0:
            switch(pinmux)
            {
                case kPinmuxType_Default:
                    PORT_BWR_PCR_MUX(PORTB, 0, 0);
                    PORT_BWR_PCR_ODE(PORTB, 0, 0);
                    PORT_BWR_PCR_MUX(PORTB, 1, 0);
                    PORT_BWR_PCR_ODE(PORTB, 1, 0);
                    break;
                case kPinmuxType_Peripheral:
                    // Enable pins for I2C0.
                    PORT_BWR_PCR_MUX(PORTB, 0, 2);  // I2C0_SCL is ALT2 for pin PTB0
                    PORT_BWR_PCR_ODE(PORTB, 0, 1);  // I2C0_SCL set for open drain
                    PORT_BWR_PCR_MUX(PORTB, 1, 2);  // I2C0_SDA is ALT2 for pin PTB1
                    PORT_BWR_PCR_ODE(PORTB, 1, 1);  // I2C0_SDA set for open drain
                    break;
                default:
                    break;
            }
            break;
#endif // BL_CONFIG_LPI2C
        case 1:
            break;
        default:
            break;
    }
}

/* This function is called for configurating pinmux for spi module
 * This function only support switching default or gpio or fixed-ALTx mode on fixed pins
 * (Although there are many ALTx-pinmux configuration choices on various pins for the same
 * peripheral module) */
void spi_pinmux_config(unsigned int instance, pinmux_type_t pinmux)
{
    switch(instance)
    {
        case 0:
            break;
#if BL_CONFIG_DSPI
        case 1:
            switch(pinmux)
            {
                case kPinmuxType_Default:
                    PORT_BWR_PCR_MUX(PORTD, 4, 0);
                    PORT_BWR_PCR_MUX(PORTD, 5, 0);
                    PORT_BWR_PCR_MUX(PORTD, 6, 0);
                    PORT_BWR_PCR_MUX(PORTD, 7, 0);
                    break;
                case kPinmuxType_Peripheral:
                    // Enable pins for SPI0 on PTD4~7
                    PORT_BWR_PCR_MUX(PORTD, 4, 7);  // SPI1_PCS0 is ALT7 for pin PTD4
                    PORT_BWR_PCR_MUX(PORTD, 5, 7);  // SPI1_SCK is ALT7 for pin PTD5
                    PORT_BWR_PCR_MUX(PORTD, 6, 7);  // SPI1_SOUT is ALT7 for pin PTD6
                    PORT_BWR_PCR_MUX(PORTD, 7, 7);  // SPI1_SIN is ALT7 for pin PTD7
                    break;
                default:
                    break;
            }
            break;
#endif // BL_CONFIG_DSPI
        default:
            break;
    }
}

/*!
 * @brief Configure pinmux for CAN module.
 *
 * This function only support switching default or gpio or fixed-ALTx mode on fixed pins
 * (Although there are many ALTx-pinmux configuration choices on various pins for the same
 * peripheral module)
 */
void can_pinmux_config(unsigned int instance, pinmux_type_t pinmux)
{
    switch(instance)
    {
#if BL_CONFIG_CAN
        case 0:
            switch(pinmux)
            {
                case kPinmuxType_Default:
                    PORT_BWR_PCR_MUX(CAN0_RX_PORT_BASE, CAN0_RX_GPIO_PIN_NUM, 0);
                    PORT_BWR_PCR_MUX(CAN0_TX_PORT_BASE, CAN0_TX_GPIO_PIN_NUM, 0);
                    break;
                case kPinmuxType_Peripheral:
                    // Enable pins for CAN0
                    PORT_BWR_PCR_MUX(CAN0_RX_PORT_BASE, CAN0_RX_GPIO_PIN_NUM, CAN0_RX_FUNC_ALT_MODE);    // Set CAN0_RX pin to CAN0_RX functionality
                    PORT_BWR_PCR_MUX(CAN0_TX_PORT_BASE, CAN0_TX_GPIO_PIN_NUM, CAN0_TX_FUNC_ALT_MODE);    // Set CAN0_TX pin to CAN0_TX functionality
                    break;
                default:
                    break;
            }
            break;
#endif // #if BL_CONFIG_CAN

        default:
            break;
    }
}

void init_hardware(void)
{
    exit_vlpr();

    // Enable all the ports
    SIM->SCGC5 |= ( SIM_SCGC5_PORTA_MASK
                  | SIM_SCGC5_PORTB_MASK
                  | SIM_SCGC5_PORTC_MASK
                  | SIM_SCGC5_PORTD_MASK
                  | SIM_SCGC5_PORTE_MASK );

    SIM->SOPT2 |= SIM_SOPT2_PLLFLLSEL_MASK ; // set PLLFLLSEL to select the IRC48M for this clock source
    SIM->SOPT2 |= SIM_SOPT2_LPI2C0SRC(1); // Select MCFGFLLCLK as LPI2C0 peripheral clock source.
}

void deinit_hardware(void)
{
    SIM->SCGC5 &= (uint32_t)~( SIM_SCGC5_PORTA_MASK
                  | SIM_SCGC5_PORTB_MASK
                  | SIM_SCGC5_PORTC_MASK
                  | SIM_SCGC5_PORTD_MASK
                  | SIM_SCGC5_PORTE_MASK );

    // Restore SIM_SOPTx related bits being changed
    SIM->SOPT2 &= (uint32_t)~(SIM_SOPT2_USBSRC_MASK | SIM_SOPT2_PLLFLLSEL_MASK | SIM_SOPT2_LPI2C0SRC_MASK);
}

bool usb_clock_init(void)
{
    // Enable USB-OTG IP clocking
    SIM_SCGC4 |= (SIM_SCGC4_USBOTG_MASK);

    // If clock of usb module cannot be enabled, return false
    if( !(SIM_SCGC4 & SIM_SCGC4_USBOTG_MASK) )
    {
        return false;
    }

    // Reset the USB peripheral, this must be done here instead of USB driver due to silicon errata
    // for at least KL25 and K22
    USB0_USBTRC0 |= USB_USBTRC0_USBRESET_MASK;
    while (USB0_USBTRC0 & USB_USBTRC0_USBRESET_SHIFT);

    // Select IRC48M clock, SIM_SOPT2_USBSRC_MASK selects internal clock,
    // 0x30000 = SIM_SOPT2_PLLFLLSEL_MASK, selects IRC48MHz clock
    SIM_SOPT2 |= (SIM_SOPT2_USBSRC_MASK | SIM_SOPT2_PLLFLLSEL_MASK);

    // need to set the clock_recover_en and irc_en register
    USB_BWR_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN(USB0, 1);
    USB_BWR_CLK_RECOVER_IRC_EN_IRC_EN(USB0, 1);
    return true;
}

uint32_t get_bus_clock(void)
{
    uint32_t busClockDivider = ((SIM->CLKDIV1 & SIM_CLKDIV1_OUTDIV2_MASK) >> SIM_CLKDIV1_OUTDIV2_SHIFT) + 1;
    return (SystemCoreClock / busClockDivider);
}

uint32_t get_uart_clock( unsigned int instance )
{
    switch(instance)
    {
        case 0:
        case 1:
            // UART0 and UART1 always use the system clock
            return SystemCoreClock;
        case 2:
        default:
            return 0;
    }
}

unsigned int read_autobaud_pin( unsigned int instance )
{
    switch(instance)
    {
        case 1:
            return (GPIO_RD_PDIR(PTE) >> UART1_RX_GPIO_PIN_NUM) & 1;
        default:
            return 0;
    }
}

bool is_boot_pin_asserted(void)
{
#ifdef BL_TARGET_FLASH
    // Initialize boot pin for GPIO
    PORT_BWR_PCR_MUX(BOOT_PIN_PORT, BOOT_PIN_NUMBER, BOOT_PIN_ALT_MODE);
    // Set boot pin as an input
    GPIO_CLR_PDDR(BOOT_PIN_GPIO, 1 << BOOT_PIN_NUMBER);
    // Set boot pin pulldown enabled, pullup select, filter enable
    PORT_SET_PCR(BOOT_PIN_PORT, BOOT_PIN_NUMBER, PORT_PCR_PE_MASK | PORT_PCR_PS_MASK | PORT_PCR_PFE_MASK);

    unsigned int readCount = 0;

    // Sample the pin a number of times
    for (unsigned int i = 0; i < BOOT_PIN_DEBOUNCE_READ_COUNT; i++)
    {
        readCount += (GPIO_RD_PDIR(BOOT_PIN_GPIO) >> BOOT_PIN_NUMBER) & 1;
    }

#if (BOOT_PIN_ASSERT_POL == 0)
    // boot pin is pulled high so we are measuring lows, make sure most of our measurements
    // registered as low
    return (readCount < (BOOT_PIN_DEBOUNCE_READ_COUNT/2));
#elif (BOOT_PIN_ASSERT_POL == 1)
    // boot pin is pulled low so we are measuring highs, make sure most of our measurements
    // registered as high
    return (readCount > (BOOT_PIN_DEBOUNCE_READ_COUNT/2));
#endif // BOOT_PIN_ASSERT_POL
#else
    // Boot pin for Flash only target
    return false;
#endif
}

//! @brief this is going to be used for autobaud IRQ handling for UART5
void PORTE_IRQHandler(void)
{
    // Check if the pin for UART5 is what triggered the PORT E interrupt
    if (PORT_RD_PCR_ISF(PORTE, UART1_RX_GPIO_PIN_NUM) && s_pin_irq_func[1])
    {
        s_pin_irq_func[1](1);
        PORT_WR_ISFR(PORTE, ~0U);
    }
}

void enable_autobaud_pin_irq(unsigned int instance, pin_irq_callback_t func)
{
    switch(instance)
    {
        case 1:
            NVIC_SetPriority(PORTE_IRQn, 1);
            NVIC_EnableIRQ(PORTE_IRQn);
            // Only look for a falling edge for our interrupts
            PORT_BWR_PCR_IRQC(PORTE, UART1_RX_GPIO_PIN_NUM, PORT_IRQC_INTERRUPT_FALLING_EDGE);
            s_pin_irq_func[1] = func;
            break;
    }
}

void disable_autobaud_pin_irq(unsigned int instance)
{
    switch(instance)
    {
        case 1:
            NVIC_DisableIRQ(PORTE_IRQn);
            PORT_BWR_PCR_IRQC(PORTE, UART1_RX_GPIO_PIN_NUM, PORT_IRQC_INTERRUPT_DISABLE);
            s_pin_irq_func[1] = 0;
            break;
    }
}

void debug_init(void)
{
}

#if __ICCARM__

size_t __write(int handle, const unsigned char *buf, size_t size)
{
    return size;
}

#endif // __ICCARM__

void update_available_peripherals()
{

}


////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////


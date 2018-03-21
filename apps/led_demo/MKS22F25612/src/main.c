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

#include "fsl_device_registers.h"

#define LED1_OFFSET     3
#define LED2_OFFSET     9
#define LED3_OFFSET     10
#define LED4_OFFSET     11

#define LED1            (1)  //green
#define LED2            (2)  //yellow
#define LED3            (4)  //orange
#define LED4            (8)  //blue

#define LED1_GPIO       (PTB)
#define LED2_GPIO       (PTB)
#define LED3_GPIO       (PTB)
#define LED4_GPIO       (PTB)

static void init_hardware(void)
{    
    SIM->SCGC5 |= ( SIM_SCGC5_PORTA_MASK
                  | SIM_SCGC5_PORTB_MASK
                  | SIM_SCGC5_PORTC_MASK
                  | SIM_SCGC5_PORTD_MASK
                  | SIM_SCGC5_PORTE_MASK );
    
    SIM->SOPT2 |= SIM_SOPT2_PLLFLLSEL_MASK; // set PLLFLLSEL to select the PLL for this clock source
    
    // Enable the LED pins GPIO
    PORT_BWR_PCR_MUX(PORTB, 3, 1);
    PORT_BWR_PCR_MUX(PORTB, 9, 1);
    PORT_BWR_PCR_MUX(PORTB, 10, 1);
    PORT_BWR_PCR_MUX(PORTB, 11, 1);
    
    // Set ports to outputs
    PTB->PDDR |= (1<<LED1_OFFSET) | (1<<LED2_OFFSET) | (1<<LED3_OFFSET) | (1<<LED4_OFFSET);
}

static void led_toggle(uint32_t leds)
{
    if (leds & LED1)
    {
        PTB->PTOR  |= (1 << LED1_OFFSET);
    }
    if (leds & LED2)
    {
        PTB->PTOR |= (1 << LED2_OFFSET);
    }
    if (leds & LED3)
    {
        PTB->PTOR |= (1<< LED3_OFFSET);
    }
    if (leds & LED4)
    {
        PTB->PTOR |= (1<< LED4_OFFSET);
    }
}

void delay(void)
{
    volatile uint32_t delayTicks = 2000000;
    
    while(delayTicks--)
    {
        __ASM("nop");
    }
}


int main(void)
{
    init_hardware();
    
    uint32_t leds = LED1;
    while(1)
    {
        led_toggle(leds);
        delay();
        led_toggle(leds);
        
        leds <<= 1;
        if(leds > LED4)
        {
            leds = LED1;
        }
    }
    
}
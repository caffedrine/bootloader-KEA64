/*
** ###################################################################
**     Compilers:           ARM Compiler
**                          Freescale C/C++ for Embedded ARM
**                          GNU C Compiler
**                          GNU C Compiler - CodeSourcery Sourcery G++
**                          IAR ANSI C/C++ Compiler for ARM
**
**     Reference manual:    MKE02Z64M20SF0RM, Rev.2.1, Apr-23 2013; KEAZ64RM, Rev.1, Sep 2013
**     Version:             rev. 1.2, 2014-05-28
**     Build:               b140528
**
**     Abstract:
**         CMSIS Peripheral Access Layer for SKEAZN642
**
**     Copyright (c) 1997 - 2015 Freescale Semiconductor, Inc.
**     All rights reserved.
**
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
**     http:                 www.freescale.com
**     mail:                 support@freescale.com
**
**     Revisions:
**     - rev. 1.0 (2013-10-09)
**         Initial version.
**     - rev. 1.1 (2013-10-29)
**         Definition of BITBAND macros updated to support peripherals with 32-bit acces disabled.
**     - rev. 1.2 (2014-05-28)
**         The declaration of clock configurations has been moved to separate header file system_SKEAZN642.h
**         Module access macro {module}_BASES replaced by {module}_BASE_PTRS.
**         Added register accessor macros.
**
** ###################################################################
*/

/*!
 * @file SKEAZN642.h
 * @version 1.2
 * @date 2014-05-28
 * @brief CMSIS Peripheral Access Layer for SKEAZN642
 *
 * CMSIS Peripheral Access Layer for SKEAZN642
 */


/* ----------------------------------------------------------------------------
   -- MCU activation
   ---------------------------------------------------------------------------- */

/* Prevention from multiple including the same memory map */
#if !defined(MKE02Z2_H_) && !defined(MKE02Z4_H_) && !defined(SKEAZN642_H_)  /* Check if memory map has not been already included */
#define MKE02Z2_H_
#define MKE02Z4_H_
#define SKEAZN642_H_
#define MCU_MKE02Z2
#define MCU_MKE02Z4
#define MCU_SKEAZN642

/* Check if another memory map has not been also included */
#if (defined(MCU_ACTIVE))
  #error SKEAZN642 memory map: There is already included another memory map. Only one memory map can be included.
#endif /* (defined(MCU_ACTIVE)) */
#define MCU_ACTIVE

#include <stdint.h>

/** Memory map major version (memory maps with equal major version number are
 * compatible) */
#define MCU_MEM_MAP_VERSION 0x0100u
/** Memory map minor version */
#define MCU_MEM_MAP_VERSION_MINOR 0x0002u


/* ----------------------------------------------------------------------------
   -- Interrupt vector numbers
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Interrupt_vector_numbers Interrupt vector numbers
 * @{
 */

/** Interrupt Number Definitions */
#define NUMBER_OF_INT_VECTORS 48                 /**< Number of interrupts in the Vector table */

typedef enum IRQn {
	
	// Custom
	PIT0_IRQn                    = 48,               /**< PIT timer channel 0 interrupt */
	  PIT1_IRQn                    = 49,               /**< PIT timer channel 1 interrupt */
	  PIT2_IRQn                    = 50,               /**< PIT timer channel 2 interrupt */
	  PIT3_IRQn                    = 51,               /**< PIT timer channel 3 interrupt */
	  USB0_IRQn                    = 53,               /**< USB0 interrupt */
	
	
  /* Core interrupts */
  NonMaskableInt_IRQn          = -14,              /**< Non Maskable Interrupt */
  HardFault_IRQn               = -13,              /**< Cortex-M0 SV Hard Fault Interrupt */
  SVCall_IRQn                  = -5,               /**< Cortex-M0 SV Call Interrupt */
  PendSV_IRQn                  = -2,               /**< Cortex-M0 Pend SV Interrupt */
  SysTick_IRQn                 = -1,               /**< Cortex-M0 System Tick Interrupt */

  /* Device specific interrupts */
  Reserved16_IRQn              = 0,                /**< Reserved interrupt 16 */
  Reserved17_IRQn              = 1,                /**< Reserved interrupt 17 */
  Reserved18_IRQn              = 2,                /**< Reserved interrupt 18 */
  Reserved19_IRQn              = 3,                /**< Reserved interrupt 19 */
  Reserved20_IRQn              = 4,                /**< Reserved interrupt 20 */
  FTMRH_IRQn                   = 5,                /**< FTMRH command complete/read collision interrupt */
  LVD_LVW_IRQn                 = 6,                /**< Low Voltage Detect, Low Voltage Warning */
  IRQ_IRQn                     = 7,                /**< External interrupt */
  I2C0_IRQn                    = 8,                /**< I2C0 interrupt */
  Reserved25_IRQn              = 9,                /**< Reserved interrupt 25 */
  SPI0_IRQn                    = 10,               /**< SPI0 interrupt */
  SPI1_IRQn                    = 11,               /**< SPI1 interrupt */
  UART0_IRQn                   = 12,               /**< UART0 status/error interrupt */
  UART1_IRQn                   = 13,               /**< UART1 status/error interrupt */
  UART2_IRQn                   = 14,               /**< UART2 status/error interrupt */
  ADC0_IRQn                    = 15,               /**< ADC0 interrupt */
  ACMP0_IRQn                   = 16,               /**< ACMP0 interrupt */
  FTM0_IRQn                    = 17,               /**< FTM0 Single interrupt vector for all sources */
  FTM1_IRQn                    = 18,               /**< FTM1 Single interrupt vector for all sources */
  FTM2_IRQn                    = 19,               /**< FTM2 Single interrupt vector for all sources */
  RTC_IRQn                     = 20,               /**< RTC overflow */
  ACMP1_IRQn                   = 21,               /**< ACMP1 interrupt */
  PIT_CH0_IRQn                 = 22,               /**< PIT CH0 overflow */
  PIT_CH1_IRQn                 = 23,               /**< PIT CH1 overflow */
  KBI0_IRQn                    = 24,               /**< Keyboard interrupt 0 */
  KBI1_IRQn                    = 25,               /**< Keyboard interrupt 1 */
  Reserved42_IRQn              = 26,               /**< Reserved interrupt 42 */
  ICS_IRQn                     = 27,               /**< ICS interrupt */
  Watchdog_IRQn                = 28,               /**< WDOG Interrupt */
  Reserved45_IRQn              = 29,               /**< Reserved interrupt 45 */
  Reserved46_IRQn              = 30,               /**< Reserved interrupt 46 */
  Reserved47_IRQn              = 31                /**< Reserved interrupt 47 */
} IRQn_Type;

/*!
 * @}
 */ /* end of group Interrupt_vector_numbers */


/* ----------------------------------------------------------------------------
   -- Cortex M0 Core Configuration
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Cortex_Core_Configuration Cortex M0 Core Configuration
 * @{
 */

#define __CM0PLUS_REV                  0x0000    /**< Core revision r0p0 */
#define __MPU_PRESENT                  0         /**< Defines if an MPU is present or not */
#define __VTOR_PRESENT                 1         /**< Defines if an MPU is present or not */
#define __NVIC_PRIO_BITS               2         /**< Number of priority bits implemented in the NVIC */
#define __Vendor_SysTickConfig         0         /**< Vendor specific implementation of SysTickConfig is defined */

#include "core_cm0plus.h"              /* Core Peripheral Access Layer */
#include "system_SKEAZN642.h"          /* Device specific configuration file */

/*!
 * @}
 */ /* end of group Cortex_Core_Configuration */


/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #pragma push
  #pragma anon_unions
#elif defined(__CWCC__)
  #pragma push
  #pragma cpp_extensions on
#elif defined(__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=extended
#else
  #error Not supported compiler type
#endif

/* ----------------------------------------------------------------------------
   -- ACMP Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ACMP_Peripheral_Access_Layer ACMP Peripheral Access Layer
 * @{
 */

/** ACMP - Register Layout Typedef */
typedef struct {
  __IO uint8_t CS;                                 /**< ACMP Control and Status Register, offset: 0x0 */
  __IO uint8_t C0;                                 /**< ACMP Control Register 0, offset: 0x1 */
  __IO uint8_t C1;                                 /**< ACMP Control Register 1, offset: 0x2 */
  __IO uint8_t C2;                                 /**< ACMP Control Register 2, offset: 0x3 */
} ACMP_Type, *ACMP_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ACMP - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ACMP_Register_Accessor_Macros ACMP - Register accessor macros
 * @{
 */


/* ACMP - Register accessors */
#define ACMP_CS_REG(base)                        ((base)->CS)
#define ACMP_C0_REG(base)                        ((base)->C0)
#define ACMP_C1_REG(base)                        ((base)->C1)
#define ACMP_C2_REG(base)                        ((base)->C2)

/*!
 * @}
 */ /* end of group ACMP_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ACMP Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ACMP_Register_Masks ACMP Register Masks
 * @{
 */

/* CS Bit Fields */
#define ACMP_CS_ACMOD_MASK                       0x3u
#define ACMP_CS_ACMOD_SHIFT                      0
#define ACMP_CS_ACMOD(x)                         (((uint8_t)(((uint8_t)(x))<<ACMP_CS_ACMOD_SHIFT))&ACMP_CS_ACMOD_MASK)
#define ACMP_CS_ACOPE_MASK                       0x4u
#define ACMP_CS_ACOPE_SHIFT                      2
#define ACMP_CS_ACO_MASK                         0x8u
#define ACMP_CS_ACO_SHIFT                        3
#define ACMP_CS_ACIE_MASK                        0x10u
#define ACMP_CS_ACIE_SHIFT                       4
#define ACMP_CS_ACF_MASK                         0x20u
#define ACMP_CS_ACF_SHIFT                        5
#define ACMP_CS_HYST_MASK                        0x40u
#define ACMP_CS_HYST_SHIFT                       6
#define ACMP_CS_ACE_MASK                         0x80u
#define ACMP_CS_ACE_SHIFT                        7
/* C0 Bit Fields */
#define ACMP_C0_ACNSEL_MASK                      0x3u
#define ACMP_C0_ACNSEL_SHIFT                     0
#define ACMP_C0_ACNSEL(x)                        (((uint8_t)(((uint8_t)(x))<<ACMP_C0_ACNSEL_SHIFT))&ACMP_C0_ACNSEL_MASK)
#define ACMP_C0_ACPSEL_MASK                      0x30u
#define ACMP_C0_ACPSEL_SHIFT                     4
#define ACMP_C0_ACPSEL(x)                        (((uint8_t)(((uint8_t)(x))<<ACMP_C0_ACPSEL_SHIFT))&ACMP_C0_ACPSEL_MASK)
/* C1 Bit Fields */
#define ACMP_C1_DACVAL_MASK                      0x3Fu
#define ACMP_C1_DACVAL_SHIFT                     0
#define ACMP_C1_DACVAL(x)                        (((uint8_t)(((uint8_t)(x))<<ACMP_C1_DACVAL_SHIFT))&ACMP_C1_DACVAL_MASK)
#define ACMP_C1_DACREF_MASK                      0x40u
#define ACMP_C1_DACREF_SHIFT                     6
#define ACMP_C1_DACEN_MASK                       0x80u
#define ACMP_C1_DACEN_SHIFT                      7
/* C2 Bit Fields */
#define ACMP_C2_ACIPE_MASK                       0x7u
#define ACMP_C2_ACIPE_SHIFT                      0
#define ACMP_C2_ACIPE(x)                         (((uint8_t)(((uint8_t)(x))<<ACMP_C2_ACIPE_SHIFT))&ACMP_C2_ACIPE_MASK)

/*!
 * @}
 */ /* end of group ACMP_Register_Masks */


/* ACMP - Peripheral instance base addresses */
/** Peripheral ACMP0 base address */
#define ACMP0_BASE                               (0x40073000u)
/** Peripheral ACMP0 base pointer */
#define ACMP0                                    ((ACMP_Type *)ACMP0_BASE)
#define ACMP0_BASE_PTR                           (ACMP0)
/** Peripheral ACMP1 base address */
#define ACMP1_BASE                               (0x40074000u)
/** Peripheral ACMP1 base pointer */
#define ACMP1                                    ((ACMP_Type *)ACMP1_BASE)
#define ACMP1_BASE_PTR                           (ACMP1)
/** Array initializer of ACMP peripheral base addresses */
#define ACMP_BASE_ADDRS                          { ACMP0_BASE, ACMP1_BASE }
/** Array initializer of ACMP peripheral base pointers */
#define ACMP_BASE_PTRS                           { ACMP0, ACMP1 }

/* ----------------------------------------------------------------------------
   -- ACMP - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ACMP_Register_Accessor_Macros ACMP - Register accessor macros
 * @{
 */


/* ACMP - Register instance definitions */
/* ACMP0 */
#define ACMP0_CS                                 ACMP_CS_REG(ACMP0)
#define ACMP0_C0                                 ACMP_C0_REG(ACMP0)
#define ACMP0_C1                                 ACMP_C1_REG(ACMP0)
#define ACMP0_C2                                 ACMP_C2_REG(ACMP0)
/* ACMP1 */
#define ACMP1_CS                                 ACMP_CS_REG(ACMP1)
#define ACMP1_C0                                 ACMP_C0_REG(ACMP1)
#define ACMP1_C1                                 ACMP_C1_REG(ACMP1)
#define ACMP1_C2                                 ACMP_C2_REG(ACMP1)

/*!
 * @}
 */ /* end of group ACMP_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group ACMP_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- ADC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Peripheral_Access_Layer ADC Peripheral Access Layer
 * @{
 */

/** ADC - Register Layout Typedef */
typedef struct {
  __IO uint32_t SC1;                               /**< Status and Control Register 1, offset: 0x0 */
  __IO uint32_t SC2;                               /**< Status and Control Register 2, offset: 0x4 */
  __IO uint32_t SC3;                               /**< Status and Control Register 3, offset: 0x8 */
  __IO uint32_t SC4;                               /**< Status and Control Register 4, offset: 0xC */
  __I  uint32_t R;                                 /**< Conversion Result Register, offset: 0x10 */
  __IO uint32_t CV;                                /**< Compare Value Register, offset: 0x14 */
  __IO uint32_t APCTL1;                            /**< Pin Control 1 Register, offset: 0x18 */
} ADC_Type, *ADC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ADC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Accessor_Macros ADC - Register accessor macros
 * @{
 */


/* ADC - Register accessors */
#define ADC_SC1_REG(base)                        ((base)->SC1)
#define ADC_SC2_REG(base)                        ((base)->SC2)
#define ADC_SC3_REG(base)                        ((base)->SC3)
#define ADC_SC4_REG(base)                        ((base)->SC4)
#define ADC_R_REG(base)                          ((base)->R)
#define ADC_CV_REG(base)                         ((base)->CV)
#define ADC_APCTL1_REG(base)                     ((base)->APCTL1)

/*!
 * @}
 */ /* end of group ADC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ADC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Masks ADC Register Masks
 * @{
 */

/* SC1 Bit Fields */
#define ADC_SC1_ADCH_MASK                        0x1Fu
#define ADC_SC1_ADCH_SHIFT                       0
#define ADC_SC1_ADCH(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC1_ADCH_SHIFT))&ADC_SC1_ADCH_MASK)
#define ADC_SC1_ADCO_MASK                        0x20u
#define ADC_SC1_ADCO_SHIFT                       5
#define ADC_SC1_AIEN_MASK                        0x40u
#define ADC_SC1_AIEN_SHIFT                       6
#define ADC_SC1_COCO_MASK                        0x80u
#define ADC_SC1_COCO_SHIFT                       7
/* SC2 Bit Fields */
#define ADC_SC2_REFSEL_MASK                      0x3u
#define ADC_SC2_REFSEL_SHIFT                     0
#define ADC_SC2_REFSEL(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_SC2_REFSEL_SHIFT))&ADC_SC2_REFSEL_MASK)
#define ADC_SC2_FFULL_MASK                       0x4u
#define ADC_SC2_FFULL_SHIFT                      2
#define ADC_SC2_FEMPTY_MASK                      0x8u
#define ADC_SC2_FEMPTY_SHIFT                     3
#define ADC_SC2_ACFGT_MASK                       0x10u
#define ADC_SC2_ACFGT_SHIFT                      4
#define ADC_SC2_ACFE_MASK                        0x20u
#define ADC_SC2_ACFE_SHIFT                       5
#define ADC_SC2_ADTRG_MASK                       0x40u
#define ADC_SC2_ADTRG_SHIFT                      6
#define ADC_SC2_ADACT_MASK                       0x80u
#define ADC_SC2_ADACT_SHIFT                      7
/* SC3 Bit Fields */
#define ADC_SC3_ADICLK_MASK                      0x3u
#define ADC_SC3_ADICLK_SHIFT                     0
#define ADC_SC3_ADICLK(x)                        (((uint32_t)(((uint32_t)(x))<<ADC_SC3_ADICLK_SHIFT))&ADC_SC3_ADICLK_MASK)
#define ADC_SC3_MODE_MASK                        0xCu
#define ADC_SC3_MODE_SHIFT                       2
#define ADC_SC3_MODE(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_MODE_SHIFT))&ADC_SC3_MODE_MASK)
#define ADC_SC3_ADLSMP_MASK                      0x10u
#define ADC_SC3_ADLSMP_SHIFT                     4
#define ADC_SC3_ADIV_MASK                        0x60u
#define ADC_SC3_ADIV_SHIFT                       5
#define ADC_SC3_ADIV(x)                          (((uint32_t)(((uint32_t)(x))<<ADC_SC3_ADIV_SHIFT))&ADC_SC3_ADIV_MASK)
#define ADC_SC3_ADLPC_MASK                       0x80u
#define ADC_SC3_ADLPC_SHIFT                      7
/* SC4 Bit Fields */
#define ADC_SC4_AFDEP_MASK                       0x7u
#define ADC_SC4_AFDEP_SHIFT                      0
#define ADC_SC4_AFDEP(x)                         (((uint32_t)(((uint32_t)(x))<<ADC_SC4_AFDEP_SHIFT))&ADC_SC4_AFDEP_MASK)
#define ADC_SC4_ACFSEL_MASK                      0x20u
#define ADC_SC4_ACFSEL_SHIFT                     5
#define ADC_SC4_ASCANE_MASK                      0x40u
#define ADC_SC4_ASCANE_SHIFT                     6
/* R Bit Fields */
#define ADC_R_ADR_MASK                           0xFFFu
#define ADC_R_ADR_SHIFT                          0
#define ADC_R_ADR(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_R_ADR_SHIFT))&ADC_R_ADR_MASK)
/* CV Bit Fields */
#define ADC_CV_CV_MASK                           0xFFFu
#define ADC_CV_CV_SHIFT                          0
#define ADC_CV_CV(x)                             (((uint32_t)(((uint32_t)(x))<<ADC_CV_CV_SHIFT))&ADC_CV_CV_MASK)
/* APCTL1 Bit Fields */
#define ADC_APCTL1_ADPC_MASK                     0xFFFFu
#define ADC_APCTL1_ADPC_SHIFT                    0
#define ADC_APCTL1_ADPC(x)                       (((uint32_t)(((uint32_t)(x))<<ADC_APCTL1_ADPC_SHIFT))&ADC_APCTL1_ADPC_MASK)

/*!
 * @}
 */ /* end of group ADC_Register_Masks */


/* ADC - Peripheral instance base addresses */
/** Peripheral ADC base address */
#define ADC_BASE                                 (0x4003B000u)
/** Peripheral ADC base pointer */
#define ADC                                      ((ADC_Type *)ADC_BASE)
#define ADC_BASE_PTR                             (ADC)
/** Array initializer of ADC peripheral base addresses */
#define ADC_BASE_ADDRS                           { ADC_BASE }
/** Array initializer of ADC peripheral base pointers */
#define ADC_BASE_PTRS                            { ADC }

/* ----------------------------------------------------------------------------
   -- ADC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ADC_Register_Accessor_Macros ADC - Register accessor macros
 * @{
 */


/* ADC - Register instance definitions */
/* ADC */
#define ADC_SC1                                  ADC_SC1_REG(ADC)
#define ADC_SC2                                  ADC_SC2_REG(ADC)
#define ADC_SC3                                  ADC_SC3_REG(ADC)
#define ADC_SC4                                  ADC_SC4_REG(ADC)
#define ADC_R                                    ADC_R_REG(ADC)
#define ADC_CV                                   ADC_CV_REG(ADC)
#define ADC_APCTL1                               ADC_APCTL1_REG(ADC)

/*!
 * @}
 */ /* end of group ADC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group ADC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- CRC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Peripheral_Access_Layer CRC Peripheral Access Layer
 * @{
 */

/** CRC - Register Layout Typedef */
typedef struct {
  union {                                          /* offset: 0x0 */
    struct {                                         /* offset: 0x0 */
      __IO uint16_t DATAL;                             /**< CRC_DATAL register., offset: 0x0 */
      __IO uint16_t DATAH;                             /**< CRC_DATAH register., offset: 0x2 */
    } ACCESS16BIT;
    __IO uint32_t DATA;                              /**< CRC Data register, offset: 0x0 */
    struct {                                         /* offset: 0x0 */
      __IO uint8_t DATALL;                             /**< CRC_DATALL register., offset: 0x0 */
      __IO uint8_t DATALU;                             /**< CRC_DATALU register., offset: 0x1 */
      __IO uint8_t DATAHL;                             /**< CRC_DATAHL register., offset: 0x2 */
      __IO uint8_t DATAHU;                             /**< CRC_DATAHU register., offset: 0x3 */
    } ACCESS8BIT;
  };
  union {                                          /* offset: 0x4 */
    struct {                                         /* offset: 0x4 */
      __IO uint16_t GPOLYL;                            /**< CRC_GPOLYL register., offset: 0x4 */
      __IO uint16_t GPOLYH;                            /**< CRC_GPOLYH register., offset: 0x6 */
    } GPOLY_ACCESS16BIT;
    __IO uint32_t GPOLY;                             /**< CRC Polynomial register, offset: 0x4 */
    struct {                                         /* offset: 0x4 */
      __IO uint8_t GPOLYLL;                            /**< CRC_GPOLYLL register., offset: 0x4 */
      __IO uint8_t GPOLYLU;                            /**< CRC_GPOLYLU register., offset: 0x5 */
      __IO uint8_t GPOLYHL;                            /**< CRC_GPOLYHL register., offset: 0x6 */
      __IO uint8_t GPOLYHU;                            /**< CRC_GPOLYHU register., offset: 0x7 */
    } GPOLY_ACCESS8BIT;
  };
  union {                                          /* offset: 0x8 */
    __IO uint32_t CTRL;                              /**< CRC Control register, offset: 0x8 */
    struct {                                         /* offset: 0x8 */
           uint8_t RESERVED_0[3];
      __IO uint8_t CTRLHU;                             /**< CRC_CTRLHU register., offset: 0xB */
    } CTRL_ACCESS8BIT;
  };
} CRC_Type, *CRC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CRC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Register_Accessor_Macros CRC - Register accessor macros
 * @{
 */


/* CRC - Register accessors */
#define CRC_DATAL_REG(base)                      ((base)->ACCESS16BIT.DATAL)
#define CRC_DATAH_REG(base)                      ((base)->ACCESS16BIT.DATAH)
#define CRC_DATA_REG(base)                       ((base)->DATA)
#define CRC_DATALL_REG(base)                     ((base)->ACCESS8BIT.DATALL)
#define CRC_DATALU_REG(base)                     ((base)->ACCESS8BIT.DATALU)
#define CRC_DATAHL_REG(base)                     ((base)->ACCESS8BIT.DATAHL)
#define CRC_DATAHU_REG(base)                     ((base)->ACCESS8BIT.DATAHU)
#define CRC_GPOLYL_REG(base)                     ((base)->GPOLY_ACCESS16BIT.GPOLYL)
#define CRC_GPOLYH_REG(base)                     ((base)->GPOLY_ACCESS16BIT.GPOLYH)
#define CRC_GPOLY_REG(base)                      ((base)->GPOLY)
#define CRC_GPOLYLL_REG(base)                    ((base)->GPOLY_ACCESS8BIT.GPOLYLL)
#define CRC_GPOLYLU_REG(base)                    ((base)->GPOLY_ACCESS8BIT.GPOLYLU)
#define CRC_GPOLYHL_REG(base)                    ((base)->GPOLY_ACCESS8BIT.GPOLYHL)
#define CRC_GPOLYHU_REG(base)                    ((base)->GPOLY_ACCESS8BIT.GPOLYHU)
#define CRC_CTRL_REG(base)                       ((base)->CTRL)
#define CRC_CTRLHU_REG(base)                     ((base)->CTRL_ACCESS8BIT.CTRLHU)

/*!
 * @}
 */ /* end of group CRC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CRC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Register_Masks CRC Register Masks
 * @{
 */

/* DATAL Bit Fields */
#define CRC_DATAL_DATAL_MASK                     0xFFFFu
#define CRC_DATAL_DATAL_SHIFT                    0
#define CRC_DATAL_DATAL(x)                       (((uint16_t)(((uint16_t)(x))<<CRC_DATAL_DATAL_SHIFT))&CRC_DATAL_DATAL_MASK)
/* DATAH Bit Fields */
#define CRC_DATAH_DATAH_MASK                     0xFFFFu
#define CRC_DATAH_DATAH_SHIFT                    0
#define CRC_DATAH_DATAH(x)                       (((uint16_t)(((uint16_t)(x))<<CRC_DATAH_DATAH_SHIFT))&CRC_DATAH_DATAH_MASK)
/* DATA Bit Fields */
#define CRC_DATA_LL_MASK                         0xFFu
#define CRC_DATA_LL_SHIFT                        0
#define CRC_DATA_LL(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_LL_SHIFT))&CRC_DATA_LL_MASK)
#define CRC_DATA_LU_MASK                         0xFF00u
#define CRC_DATA_LU_SHIFT                        8
#define CRC_DATA_LU(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_LU_SHIFT))&CRC_DATA_LU_MASK)
#define CRC_DATA_HL_MASK                         0xFF0000u
#define CRC_DATA_HL_SHIFT                        16
#define CRC_DATA_HL(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_HL_SHIFT))&CRC_DATA_HL_MASK)
#define CRC_DATA_HU_MASK                         0xFF000000u
#define CRC_DATA_HU_SHIFT                        24
#define CRC_DATA_HU(x)                           (((uint32_t)(((uint32_t)(x))<<CRC_DATA_HU_SHIFT))&CRC_DATA_HU_MASK)
/* DATALL Bit Fields */
#define CRC_DATALL_DATALL_MASK                   0xFFu
#define CRC_DATALL_DATALL_SHIFT                  0
#define CRC_DATALL_DATALL(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATALL_DATALL_SHIFT))&CRC_DATALL_DATALL_MASK)
/* DATALU Bit Fields */
#define CRC_DATALU_DATALU_MASK                   0xFFu
#define CRC_DATALU_DATALU_SHIFT                  0
#define CRC_DATALU_DATALU(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATALU_DATALU_SHIFT))&CRC_DATALU_DATALU_MASK)
/* DATAHL Bit Fields */
#define CRC_DATAHL_DATAHL_MASK                   0xFFu
#define CRC_DATAHL_DATAHL_SHIFT                  0
#define CRC_DATAHL_DATAHL(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATAHL_DATAHL_SHIFT))&CRC_DATAHL_DATAHL_MASK)
/* DATAHU Bit Fields */
#define CRC_DATAHU_DATAHU_MASK                   0xFFu
#define CRC_DATAHU_DATAHU_SHIFT                  0
#define CRC_DATAHU_DATAHU(x)                     (((uint8_t)(((uint8_t)(x))<<CRC_DATAHU_DATAHU_SHIFT))&CRC_DATAHU_DATAHU_MASK)
/* GPOLYL Bit Fields */
#define CRC_GPOLYL_GPOLYL_MASK                   0xFFFFu
#define CRC_GPOLYL_GPOLYL_SHIFT                  0
#define CRC_GPOLYL_GPOLYL(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYL_GPOLYL_SHIFT))&CRC_GPOLYL_GPOLYL_MASK)
/* GPOLYH Bit Fields */
#define CRC_GPOLYH_GPOLYH_MASK                   0xFFFFu
#define CRC_GPOLYH_GPOLYH_SHIFT                  0
#define CRC_GPOLYH_GPOLYH(x)                     (((uint16_t)(((uint16_t)(x))<<CRC_GPOLYH_GPOLYH_SHIFT))&CRC_GPOLYH_GPOLYH_MASK)
/* GPOLY Bit Fields */
#define CRC_GPOLY_LOW_MASK                       0xFFFFu
#define CRC_GPOLY_LOW_SHIFT                      0
#define CRC_GPOLY_LOW(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_LOW_SHIFT))&CRC_GPOLY_LOW_MASK)
#define CRC_GPOLY_HIGH_MASK                      0xFFFF0000u
#define CRC_GPOLY_HIGH_SHIFT                     16
#define CRC_GPOLY_HIGH(x)                        (((uint32_t)(((uint32_t)(x))<<CRC_GPOLY_HIGH_SHIFT))&CRC_GPOLY_HIGH_MASK)
/* GPOLYLL Bit Fields */
#define CRC_GPOLYLL_GPOLYLL_MASK                 0xFFu
#define CRC_GPOLYLL_GPOLYLL_SHIFT                0
#define CRC_GPOLYLL_GPOLYLL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLL_GPOLYLL_SHIFT))&CRC_GPOLYLL_GPOLYLL_MASK)
/* GPOLYLU Bit Fields */
#define CRC_GPOLYLU_GPOLYLU_MASK                 0xFFu
#define CRC_GPOLYLU_GPOLYLU_SHIFT                0
#define CRC_GPOLYLU_GPOLYLU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYLU_GPOLYLU_SHIFT))&CRC_GPOLYLU_GPOLYLU_MASK)
/* GPOLYHL Bit Fields */
#define CRC_GPOLYHL_GPOLYHL_MASK                 0xFFu
#define CRC_GPOLYHL_GPOLYHL_SHIFT                0
#define CRC_GPOLYHL_GPOLYHL(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHL_GPOLYHL_SHIFT))&CRC_GPOLYHL_GPOLYHL_MASK)
/* GPOLYHU Bit Fields */
#define CRC_GPOLYHU_GPOLYHU_MASK                 0xFFu
#define CRC_GPOLYHU_GPOLYHU_SHIFT                0
#define CRC_GPOLYHU_GPOLYHU(x)                   (((uint8_t)(((uint8_t)(x))<<CRC_GPOLYHU_GPOLYHU_SHIFT))&CRC_GPOLYHU_GPOLYHU_MASK)
/* CTRL Bit Fields */
#define CRC_CTRL_TCRC_MASK                       0x1000000u
#define CRC_CTRL_TCRC_SHIFT                      24
#define CRC_CTRL_WAS_MASK                        0x2000000u
#define CRC_CTRL_WAS_SHIFT                       25
#define CRC_CTRL_FXOR_MASK                       0x4000000u
#define CRC_CTRL_FXOR_SHIFT                      26
#define CRC_CTRL_TOTR_MASK                       0x30000000u
#define CRC_CTRL_TOTR_SHIFT                      28
#define CRC_CTRL_TOTR(x)                         (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOTR_SHIFT))&CRC_CTRL_TOTR_MASK)
#define CRC_CTRL_TOT_MASK                        0xC0000000u
#define CRC_CTRL_TOT_SHIFT                       30
#define CRC_CTRL_TOT(x)                          (((uint32_t)(((uint32_t)(x))<<CRC_CTRL_TOT_SHIFT))&CRC_CTRL_TOT_MASK)
/* CTRLHU Bit Fields */
#define CRC_CTRLHU_TCRC_MASK                     0x1u
#define CRC_CTRLHU_TCRC_SHIFT                    0
#define CRC_CTRLHU_WAS_MASK                      0x2u
#define CRC_CTRLHU_WAS_SHIFT                     1
#define CRC_CTRLHU_FXOR_MASK                     0x4u
#define CRC_CTRLHU_FXOR_SHIFT                    2
#define CRC_CTRLHU_TOTR_MASK                     0x30u
#define CRC_CTRLHU_TOTR_SHIFT                    4
#define CRC_CTRLHU_TOTR(x)                       (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOTR_SHIFT))&CRC_CTRLHU_TOTR_MASK)
#define CRC_CTRLHU_TOT_MASK                      0xC0u
#define CRC_CTRLHU_TOT_SHIFT                     6
#define CRC_CTRLHU_TOT(x)                        (((uint8_t)(((uint8_t)(x))<<CRC_CTRLHU_TOT_SHIFT))&CRC_CTRLHU_TOT_MASK)

/*!
 * @}
 */ /* end of group CRC_Register_Masks */


/* CRC - Peripheral instance base addresses */
/** Peripheral CRC base address */
#define CRC_BASE                                 (0x40032000u)
/** Peripheral CRC base pointer */
#define CRC0                                     ((CRC_Type *)CRC_BASE)
#define CRC_BASE_PTR                             (CRC0)
/** Array initializer of CRC peripheral base addresses */
#define CRC_BASE_ADDRS                           { CRC_BASE }
/** Array initializer of CRC peripheral base pointers */
#define CRC_BASE_PTRS                            { CRC0 }

/* ----------------------------------------------------------------------------
   -- CRC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CRC_Register_Accessor_Macros CRC - Register accessor macros
 * @{
 */


/* CRC - Register instance definitions */
/* CRC */
#define CRC_DATA                                 CRC_DATA_REG(CRC0)
#define CRC_DATAL                                CRC_DATAL_REG(CRC0)
#define CRC_DATALL                               CRC_DATALL_REG(CRC0)
#define CRC_DATALU                               CRC_DATALU_REG(CRC0)
#define CRC_DATAH                                CRC_DATAH_REG(CRC0)
#define CRC_DATAHL                               CRC_DATAHL_REG(CRC0)
#define CRC_DATAHU                               CRC_DATAHU_REG(CRC0)
#define CRC_GPOLY                                CRC_GPOLY_REG(CRC0)
#define CRC_GPOLYL                               CRC_GPOLYL_REG(CRC0)
#define CRC_GPOLYLL                              CRC_GPOLYLL_REG(CRC0)
#define CRC_GPOLYLU                              CRC_GPOLYLU_REG(CRC0)
#define CRC_GPOLYH                               CRC_GPOLYH_REG(CRC0)
#define CRC_GPOLYHL                              CRC_GPOLYHL_REG(CRC0)
#define CRC_GPOLYHU                              CRC_GPOLYHU_REG(CRC0)
#define CRC_CTRL                                 CRC_CTRL_REG(CRC0)
#define CRC_CTRLHU                               CRC_CTRLHU_REG(CRC0)

/*!
 * @}
 */ /* end of group CRC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group CRC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- FGPIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FGPIO_Peripheral_Access_Layer FGPIO Peripheral Access Layer
 * @{
 */

/** FGPIO - Register Layout Typedef */
typedef struct {
  __IO uint32_t PDOR;                              /**< Port Data Output Register, offset: 0x0 */
  __O  uint32_t PSOR;                              /**< Port Set Output Register, offset: 0x4 */
  __O  uint32_t PCOR;                              /**< Port Clear Output Register, offset: 0x8 */
  __O  uint32_t PTOR;                              /**< Port Toggle Output Register, offset: 0xC */
  __I  uint32_t PDIR;                              /**< Port Data Input Register, offset: 0x10 */
  __IO uint32_t PDDR;                              /**< Port Data Direction Register, offset: 0x14 */
  __IO uint32_t PIDR;                              /**< Port Input Disable Register, offset: 0x18 */
} FGPIO_Type, *FGPIO_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FGPIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FGPIO_Register_Accessor_Macros FGPIO - Register accessor macros
 * @{
 */


/* FGPIO - Register accessors */
#define FGPIO_PDOR_REG(base)                     ((base)->PDOR)
#define FGPIO_PSOR_REG(base)                     ((base)->PSOR)
#define FGPIO_PCOR_REG(base)                     ((base)->PCOR)
#define FGPIO_PTOR_REG(base)                     ((base)->PTOR)
#define FGPIO_PDIR_REG(base)                     ((base)->PDIR)
#define FGPIO_PDDR_REG(base)                     ((base)->PDDR)
#define FGPIO_PIDR_REG(base)                     ((base)->PIDR)

/*!
 * @}
 */ /* end of group FGPIO_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FGPIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FGPIO_Register_Masks FGPIO Register Masks
 * @{
 */

/* PDOR Bit Fields */
#define FGPIO_PDOR_PDO_MASK                      0xFFFFFFFFu
#define FGPIO_PDOR_PDO_SHIFT                     0
#define FGPIO_PDOR_PDO(x)                        (((uint32_t)(((uint32_t)(x))<<FGPIO_PDOR_PDO_SHIFT))&FGPIO_PDOR_PDO_MASK)
/* PSOR Bit Fields */
#define FGPIO_PSOR_PTSO_MASK                     0xFFFFFFFFu
#define FGPIO_PSOR_PTSO_SHIFT                    0
#define FGPIO_PSOR_PTSO(x)                       (((uint32_t)(((uint32_t)(x))<<FGPIO_PSOR_PTSO_SHIFT))&FGPIO_PSOR_PTSO_MASK)
/* PCOR Bit Fields */
#define FGPIO_PCOR_PTCO_MASK                     0xFFFFFFFFu
#define FGPIO_PCOR_PTCO_SHIFT                    0
#define FGPIO_PCOR_PTCO(x)                       (((uint32_t)(((uint32_t)(x))<<FGPIO_PCOR_PTCO_SHIFT))&FGPIO_PCOR_PTCO_MASK)
/* PTOR Bit Fields */
#define FGPIO_PTOR_PTTO_MASK                     0xFFFFFFFFu
#define FGPIO_PTOR_PTTO_SHIFT                    0
#define FGPIO_PTOR_PTTO(x)                       (((uint32_t)(((uint32_t)(x))<<FGPIO_PTOR_PTTO_SHIFT))&FGPIO_PTOR_PTTO_MASK)
/* PDIR Bit Fields */
#define FGPIO_PDIR_PDI_MASK                      0xFFFFFFFFu
#define FGPIO_PDIR_PDI_SHIFT                     0
#define FGPIO_PDIR_PDI(x)                        (((uint32_t)(((uint32_t)(x))<<FGPIO_PDIR_PDI_SHIFT))&FGPIO_PDIR_PDI_MASK)
/* PDDR Bit Fields */
#define FGPIO_PDDR_PDD_MASK                      0xFFFFFFFFu
#define FGPIO_PDDR_PDD_SHIFT                     0
#define FGPIO_PDDR_PDD(x)                        (((uint32_t)(((uint32_t)(x))<<FGPIO_PDDR_PDD_SHIFT))&FGPIO_PDDR_PDD_MASK)
/* PIDR Bit Fields */
#define FGPIO_PIDR_PID_MASK                      0xFFFFFFFFu
#define FGPIO_PIDR_PID_SHIFT                     0
#define FGPIO_PIDR_PID(x)                        (((uint32_t)(((uint32_t)(x))<<FGPIO_PIDR_PID_SHIFT))&FGPIO_PIDR_PID_MASK)

/*!
 * @}
 */ /* end of group FGPIO_Register_Masks */


/* FGPIO - Peripheral instance base addresses */
/** Peripheral FGPIOA base address */
#define FGPIOA_BASE                              (0xF8000000u)
/** Peripheral FGPIOA base pointer */
#define FGPIOA                                   ((FGPIO_Type *)FGPIOA_BASE)
#define FGPIOA_BASE_PTR                          (FGPIOA)
/** Peripheral FGPIOB base address */
#define FGPIOB_BASE                              (0xF8000040u)
/** Peripheral FGPIOB base pointer */
#define FGPIOB                                   ((FGPIO_Type *)FGPIOB_BASE)
#define FGPIOB_BASE_PTR                          (FGPIOB)
/** Array initializer of FGPIO peripheral base addresses */
#define FGPIO_BASE_ADDRS                         { FGPIOA_BASE, FGPIOB_BASE }
/** Array initializer of FGPIO peripheral base pointers */
#define FGPIO_BASE_PTRS                          { FGPIOA, FGPIOB }

/* ----------------------------------------------------------------------------
   -- FGPIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FGPIO_Register_Accessor_Macros FGPIO - Register accessor macros
 * @{
 */


/* FGPIO - Register instance definitions */
/* FGPIOA */
#define FGPIOA_PDOR                              FGPIO_PDOR_REG(FGPIOA)
#define FGPIOA_PSOR                              FGPIO_PSOR_REG(FGPIOA)
#define FGPIOA_PCOR                              FGPIO_PCOR_REG(FGPIOA)
#define FGPIOA_PTOR                              FGPIO_PTOR_REG(FGPIOA)
#define FGPIOA_PDIR                              FGPIO_PDIR_REG(FGPIOA)
#define FGPIOA_PDDR                              FGPIO_PDDR_REG(FGPIOA)
#define FGPIOA_PIDR                              FGPIO_PIDR_REG(FGPIOA)
/* FGPIOB */
#define FGPIOB_PDOR                              FGPIO_PDOR_REG(FGPIOB)
#define FGPIOB_PSOR                              FGPIO_PSOR_REG(FGPIOB)
#define FGPIOB_PCOR                              FGPIO_PCOR_REG(FGPIOB)
#define FGPIOB_PTOR                              FGPIO_PTOR_REG(FGPIOB)
#define FGPIOB_PDIR                              FGPIO_PDIR_REG(FGPIOB)
#define FGPIOB_PDDR                              FGPIO_PDDR_REG(FGPIOB)
#define FGPIOB_PIDR                              FGPIO_PIDR_REG(FGPIOB)

/*!
 * @}
 */ /* end of group FGPIO_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group FGPIO_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- FTM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTM_Peripheral_Access_Layer FTM Peripheral Access Layer
 * @{
 */

/** FTM - Register Layout Typedef */
typedef struct {
  __IO uint32_t SC;                                /**< Status And Control, offset: 0x0 */
  __IO uint32_t CNT;                               /**< Counter, offset: 0x4 */
  __IO uint32_t MOD;                               /**< Modulo, offset: 0x8 */
  struct {                                         /* offset: 0xC, array step: 0x8 */
    __IO uint32_t CnSC;                              /**< Channel (n) Status And Control, array offset: 0xC, array step: 0x8 */
    __IO uint32_t CnV;                               /**< Channel (n) Value, array offset: 0x10, array step: 0x8 */
  } CONTROLS[6];
       uint8_t RESERVED_0[16];
  __IO uint32_t CNTIN;                             /**< Counter Initial Value, offset: 0x4C */
  __IO uint32_t STATUS;                            /**< Capture And Compare Status, offset: 0x50 */
  __IO uint32_t MODE;                              /**< Features Mode Selection, offset: 0x54 */
  __IO uint32_t SYNC;                              /**< Synchronization, offset: 0x58 */
  __IO uint32_t OUTINIT;                           /**< Initial State For Channels Output, offset: 0x5C */
  __IO uint32_t OUTMASK;                           /**< Output Mask, offset: 0x60 */
  __IO uint32_t COMBINE;                           /**< Function For Linked Channels, offset: 0x64 */
  __IO uint32_t DEADTIME;                          /**< Deadtime Insertion Control, offset: 0x68 */
  __IO uint32_t EXTTRIG;                           /**< FTM External Trigger, offset: 0x6C */
  __IO uint32_t POL;                               /**< Channels Polarity, offset: 0x70 */
  __IO uint32_t FMS;                               /**< Fault Mode Status, offset: 0x74 */
  __IO uint32_t FILTER;                            /**< Input Capture Filter Control, offset: 0x78 */
  __IO uint32_t FLTCTRL;                           /**< Fault Control, offset: 0x7C */
       uint8_t RESERVED_1[4];
  __IO uint32_t CONF;                              /**< Configuration, offset: 0x84 */
  __IO uint32_t FLTPOL;                            /**< FTM Fault Input Polarity, offset: 0x88 */
  __IO uint32_t SYNCONF;                           /**< Synchronization Configuration, offset: 0x8C */
  __IO uint32_t INVCTRL;                           /**< FTM Inverting Control, offset: 0x90 */
  __IO uint32_t SWOCTRL;                           /**< FTM Software Output Control, offset: 0x94 */
  __IO uint32_t PWMLOAD;                           /**< FTM PWM Load, offset: 0x98 */
} FTM_Type, *FTM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FTM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTM_Register_Accessor_Macros FTM - Register accessor macros
 * @{
 */


/* FTM - Register accessors */
#define FTM_SC_REG(base)                         ((base)->SC)
#define FTM_CNT_REG(base)                        ((base)->CNT)
#define FTM_MOD_REG(base)                        ((base)->MOD)
#define FTM_CnSC_REG(base,index)                 ((base)->CONTROLS[index].CnSC)
#define FTM_CnV_REG(base,index)                  ((base)->CONTROLS[index].CnV)
#define FTM_CNTIN_REG(base)                      ((base)->CNTIN)
#define FTM_STATUS_REG(base)                     ((base)->STATUS)
#define FTM_MODE_REG(base)                       ((base)->MODE)
#define FTM_SYNC_REG(base)                       ((base)->SYNC)
#define FTM_OUTINIT_REG(base)                    ((base)->OUTINIT)
#define FTM_OUTMASK_REG(base)                    ((base)->OUTMASK)
#define FTM_COMBINE_REG(base)                    ((base)->COMBINE)
#define FTM_DEADTIME_REG(base)                   ((base)->DEADTIME)
#define FTM_EXTTRIG_REG(base)                    ((base)->EXTTRIG)
#define FTM_POL_REG(base)                        ((base)->POL)
#define FTM_FMS_REG(base)                        ((base)->FMS)
#define FTM_FILTER_REG(base)                     ((base)->FILTER)
#define FTM_FLTCTRL_REG(base)                    ((base)->FLTCTRL)
#define FTM_CONF_REG(base)                       ((base)->CONF)
#define FTM_FLTPOL_REG(base)                     ((base)->FLTPOL)
#define FTM_SYNCONF_REG(base)                    ((base)->SYNCONF)
#define FTM_INVCTRL_REG(base)                    ((base)->INVCTRL)
#define FTM_SWOCTRL_REG(base)                    ((base)->SWOCTRL)
#define FTM_PWMLOAD_REG(base)                    ((base)->PWMLOAD)

/*!
 * @}
 */ /* end of group FTM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FTM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTM_Register_Masks FTM Register Masks
 * @{
 */

/* SC Bit Fields */
#define FTM_SC_PS_MASK                           0x7u
#define FTM_SC_PS_SHIFT                          0
#define FTM_SC_PS(x)                             (((uint32_t)(((uint32_t)(x))<<FTM_SC_PS_SHIFT))&FTM_SC_PS_MASK)
#define FTM_SC_CLKS_MASK                         0x18u
#define FTM_SC_CLKS_SHIFT                        3
#define FTM_SC_CLKS(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_SC_CLKS_SHIFT))&FTM_SC_CLKS_MASK)
#define FTM_SC_CPWMS_MASK                        0x20u
#define FTM_SC_CPWMS_SHIFT                       5
#define FTM_SC_TOIE_MASK                         0x40u
#define FTM_SC_TOIE_SHIFT                        6
#define FTM_SC_TOF_MASK                          0x80u
#define FTM_SC_TOF_SHIFT                         7
/* CNT Bit Fields */
#define FTM_CNT_COUNT_MASK                       0xFFFFu
#define FTM_CNT_COUNT_SHIFT                      0
#define FTM_CNT_COUNT(x)                         (((uint32_t)(((uint32_t)(x))<<FTM_CNT_COUNT_SHIFT))&FTM_CNT_COUNT_MASK)
/* MOD Bit Fields */
#define FTM_MOD_MOD_MASK                         0xFFFFu
#define FTM_MOD_MOD_SHIFT                        0
#define FTM_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_MOD_MOD_SHIFT))&FTM_MOD_MOD_MASK)
/* CnSC Bit Fields */
#define FTM_CnSC_ELSA_MASK                       0x4u
#define FTM_CnSC_ELSA_SHIFT                      2
#define FTM_CnSC_ELSB_MASK                       0x8u
#define FTM_CnSC_ELSB_SHIFT                      3
#define FTM_CnSC_MSA_MASK                        0x10u
#define FTM_CnSC_MSA_SHIFT                       4
#define FTM_CnSC_MSB_MASK                        0x20u
#define FTM_CnSC_MSB_SHIFT                       5
#define FTM_CnSC_CHIE_MASK                       0x40u
#define FTM_CnSC_CHIE_SHIFT                      6
#define FTM_CnSC_CHF_MASK                        0x80u
#define FTM_CnSC_CHF_SHIFT                       7
/* CnV Bit Fields */
#define FTM_CnV_VAL_MASK                         0xFFFFu
#define FTM_CnV_VAL_SHIFT                        0
#define FTM_CnV_VAL(x)                           (((uint32_t)(((uint32_t)(x))<<FTM_CnV_VAL_SHIFT))&FTM_CnV_VAL_MASK)
/* CNTIN Bit Fields */
#define FTM_CNTIN_INIT_MASK                      0xFFFFu
#define FTM_CNTIN_INIT_SHIFT                     0
#define FTM_CNTIN_INIT(x)                        (((uint32_t)(((uint32_t)(x))<<FTM_CNTIN_INIT_SHIFT))&FTM_CNTIN_INIT_MASK)
/* STATUS Bit Fields */
#define FTM_STATUS_CH0F_MASK                     0x1u
#define FTM_STATUS_CH0F_SHIFT                    0
#define FTM_STATUS_CH1F_MASK                     0x2u
#define FTM_STATUS_CH1F_SHIFT                    1
#define FTM_STATUS_CH2F_MASK                     0x4u
#define FTM_STATUS_CH2F_SHIFT                    2
#define FTM_STATUS_CH3F_MASK                     0x8u
#define FTM_STATUS_CH3F_SHIFT                    3
#define FTM_STATUS_CH4F_MASK                     0x10u
#define FTM_STATUS_CH4F_SHIFT                    4
#define FTM_STATUS_CH5F_MASK                     0x20u
#define FTM_STATUS_CH5F_SHIFT                    5
#define FTM_STATUS_CH6F_MASK                     0x40u
#define FTM_STATUS_CH6F_SHIFT                    6
#define FTM_STATUS_CH7F_MASK                     0x80u
#define FTM_STATUS_CH7F_SHIFT                    7
/* MODE Bit Fields */
#define FTM_MODE_FTMEN_MASK                      0x1u
#define FTM_MODE_FTMEN_SHIFT                     0
#define FTM_MODE_INIT_MASK                       0x2u
#define FTM_MODE_INIT_SHIFT                      1
#define FTM_MODE_WPDIS_MASK                      0x4u
#define FTM_MODE_WPDIS_SHIFT                     2
#define FTM_MODE_PWMSYNC_MASK                    0x8u
#define FTM_MODE_PWMSYNC_SHIFT                   3
#define FTM_MODE_CAPTEST_MASK                    0x10u
#define FTM_MODE_CAPTEST_SHIFT                   4
#define FTM_MODE_FAULTM_MASK                     0x60u
#define FTM_MODE_FAULTM_SHIFT                    5
#define FTM_MODE_FAULTM(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_MODE_FAULTM_SHIFT))&FTM_MODE_FAULTM_MASK)
#define FTM_MODE_FAULTIE_MASK                    0x80u
#define FTM_MODE_FAULTIE_SHIFT                   7
/* SYNC Bit Fields */
#define FTM_SYNC_CNTMIN_MASK                     0x1u
#define FTM_SYNC_CNTMIN_SHIFT                    0
#define FTM_SYNC_CNTMAX_MASK                     0x2u
#define FTM_SYNC_CNTMAX_SHIFT                    1
#define FTM_SYNC_REINIT_MASK                     0x4u
#define FTM_SYNC_REINIT_SHIFT                    2
#define FTM_SYNC_SYNCHOM_MASK                    0x8u
#define FTM_SYNC_SYNCHOM_SHIFT                   3
#define FTM_SYNC_TRIG0_MASK                      0x10u
#define FTM_SYNC_TRIG0_SHIFT                     4
#define FTM_SYNC_TRIG1_MASK                      0x20u
#define FTM_SYNC_TRIG1_SHIFT                     5
#define FTM_SYNC_TRIG2_MASK                      0x40u
#define FTM_SYNC_TRIG2_SHIFT                     6
#define FTM_SYNC_SWSYNC_MASK                     0x80u
#define FTM_SYNC_SWSYNC_SHIFT                    7
/* OUTINIT Bit Fields */
#define FTM_OUTINIT_CH0OI_MASK                   0x1u
#define FTM_OUTINIT_CH0OI_SHIFT                  0
#define FTM_OUTINIT_CH1OI_MASK                   0x2u
#define FTM_OUTINIT_CH1OI_SHIFT                  1
#define FTM_OUTINIT_CH2OI_MASK                   0x4u
#define FTM_OUTINIT_CH2OI_SHIFT                  2
#define FTM_OUTINIT_CH3OI_MASK                   0x8u
#define FTM_OUTINIT_CH3OI_SHIFT                  3
#define FTM_OUTINIT_CH4OI_MASK                   0x10u
#define FTM_OUTINIT_CH4OI_SHIFT                  4
#define FTM_OUTINIT_CH5OI_MASK                   0x20u
#define FTM_OUTINIT_CH5OI_SHIFT                  5
#define FTM_OUTINIT_CH6OI_MASK                   0x40u
#define FTM_OUTINIT_CH6OI_SHIFT                  6
#define FTM_OUTINIT_CH7OI_MASK                   0x80u
#define FTM_OUTINIT_CH7OI_SHIFT                  7
/* OUTMASK Bit Fields */
#define FTM_OUTMASK_CH0OM_MASK                   0x1u
#define FTM_OUTMASK_CH0OM_SHIFT                  0
#define FTM_OUTMASK_CH1OM_MASK                   0x2u
#define FTM_OUTMASK_CH1OM_SHIFT                  1
#define FTM_OUTMASK_CH2OM_MASK                   0x4u
#define FTM_OUTMASK_CH2OM_SHIFT                  2
#define FTM_OUTMASK_CH3OM_MASK                   0x8u
#define FTM_OUTMASK_CH3OM_SHIFT                  3
#define FTM_OUTMASK_CH4OM_MASK                   0x10u
#define FTM_OUTMASK_CH4OM_SHIFT                  4
#define FTM_OUTMASK_CH5OM_MASK                   0x20u
#define FTM_OUTMASK_CH5OM_SHIFT                  5
#define FTM_OUTMASK_CH6OM_MASK                   0x40u
#define FTM_OUTMASK_CH6OM_SHIFT                  6
#define FTM_OUTMASK_CH7OM_MASK                   0x80u
#define FTM_OUTMASK_CH7OM_SHIFT                  7
/* COMBINE Bit Fields */
#define FTM_COMBINE_COMBINE0_MASK                0x1u
#define FTM_COMBINE_COMBINE0_SHIFT               0
#define FTM_COMBINE_COMP0_MASK                   0x2u
#define FTM_COMBINE_COMP0_SHIFT                  1
#define FTM_COMBINE_DECAPEN0_MASK                0x4u
#define FTM_COMBINE_DECAPEN0_SHIFT               2
#define FTM_COMBINE_DECAP0_MASK                  0x8u
#define FTM_COMBINE_DECAP0_SHIFT                 3
#define FTM_COMBINE_DTEN0_MASK                   0x10u
#define FTM_COMBINE_DTEN0_SHIFT                  4
#define FTM_COMBINE_SYNCEN0_MASK                 0x20u
#define FTM_COMBINE_SYNCEN0_SHIFT                5
#define FTM_COMBINE_FAULTEN0_MASK                0x40u
#define FTM_COMBINE_FAULTEN0_SHIFT               6
#define FTM_COMBINE_COMBINE1_MASK                0x100u
#define FTM_COMBINE_COMBINE1_SHIFT               8
#define FTM_COMBINE_COMP1_MASK                   0x200u
#define FTM_COMBINE_COMP1_SHIFT                  9
#define FTM_COMBINE_DECAPEN1_MASK                0x400u
#define FTM_COMBINE_DECAPEN1_SHIFT               10
#define FTM_COMBINE_DECAP1_MASK                  0x800u
#define FTM_COMBINE_DECAP1_SHIFT                 11
#define FTM_COMBINE_DTEN1_MASK                   0x1000u
#define FTM_COMBINE_DTEN1_SHIFT                  12
#define FTM_COMBINE_SYNCEN1_MASK                 0x2000u
#define FTM_COMBINE_SYNCEN1_SHIFT                13
#define FTM_COMBINE_FAULTEN1_MASK                0x4000u
#define FTM_COMBINE_FAULTEN1_SHIFT               14
#define FTM_COMBINE_COMBINE2_MASK                0x10000u
#define FTM_COMBINE_COMBINE2_SHIFT               16
#define FTM_COMBINE_COMP2_MASK                   0x20000u
#define FTM_COMBINE_COMP2_SHIFT                  17
#define FTM_COMBINE_DECAPEN2_MASK                0x40000u
#define FTM_COMBINE_DECAPEN2_SHIFT               18
#define FTM_COMBINE_DECAP2_MASK                  0x80000u
#define FTM_COMBINE_DECAP2_SHIFT                 19
#define FTM_COMBINE_DTEN2_MASK                   0x100000u
#define FTM_COMBINE_DTEN2_SHIFT                  20
#define FTM_COMBINE_SYNCEN2_MASK                 0x200000u
#define FTM_COMBINE_SYNCEN2_SHIFT                21
#define FTM_COMBINE_FAULTEN2_MASK                0x400000u
#define FTM_COMBINE_FAULTEN2_SHIFT               22
#define FTM_COMBINE_COMBINE3_MASK                0x1000000u
#define FTM_COMBINE_COMBINE3_SHIFT               24
#define FTM_COMBINE_COMP3_MASK                   0x2000000u
#define FTM_COMBINE_COMP3_SHIFT                  25
#define FTM_COMBINE_DECAPEN3_MASK                0x4000000u
#define FTM_COMBINE_DECAPEN3_SHIFT               26
#define FTM_COMBINE_DECAP3_MASK                  0x8000000u
#define FTM_COMBINE_DECAP3_SHIFT                 27
#define FTM_COMBINE_DTEN3_MASK                   0x10000000u
#define FTM_COMBINE_DTEN3_SHIFT                  28
#define FTM_COMBINE_SYNCEN3_MASK                 0x20000000u
#define FTM_COMBINE_SYNCEN3_SHIFT                29
#define FTM_COMBINE_FAULTEN3_MASK                0x40000000u
#define FTM_COMBINE_FAULTEN3_SHIFT               30
/* DEADTIME Bit Fields */
#define FTM_DEADTIME_DTVAL_MASK                  0x3Fu
#define FTM_DEADTIME_DTVAL_SHIFT                 0
#define FTM_DEADTIME_DTVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_DEADTIME_DTVAL_SHIFT))&FTM_DEADTIME_DTVAL_MASK)
#define FTM_DEADTIME_DTPS_MASK                   0xC0u
#define FTM_DEADTIME_DTPS_SHIFT                  6
#define FTM_DEADTIME_DTPS(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_DEADTIME_DTPS_SHIFT))&FTM_DEADTIME_DTPS_MASK)
/* EXTTRIG Bit Fields */
#define FTM_EXTTRIG_CH2TRIG_MASK                 0x1u
#define FTM_EXTTRIG_CH2TRIG_SHIFT                0
#define FTM_EXTTRIG_CH3TRIG_MASK                 0x2u
#define FTM_EXTTRIG_CH3TRIG_SHIFT                1
#define FTM_EXTTRIG_CH4TRIG_MASK                 0x4u
#define FTM_EXTTRIG_CH4TRIG_SHIFT                2
#define FTM_EXTTRIG_CH5TRIG_MASK                 0x8u
#define FTM_EXTTRIG_CH5TRIG_SHIFT                3
#define FTM_EXTTRIG_CH0TRIG_MASK                 0x10u
#define FTM_EXTTRIG_CH0TRIG_SHIFT                4
#define FTM_EXTTRIG_CH1TRIG_MASK                 0x20u
#define FTM_EXTTRIG_CH1TRIG_SHIFT                5
#define FTM_EXTTRIG_INITTRIGEN_MASK              0x40u
#define FTM_EXTTRIG_INITTRIGEN_SHIFT             6
#define FTM_EXTTRIG_TRIGF_MASK                   0x80u
#define FTM_EXTTRIG_TRIGF_SHIFT                  7
/* POL Bit Fields */
#define FTM_POL_POL0_MASK                        0x1u
#define FTM_POL_POL0_SHIFT                       0
#define FTM_POL_POL1_MASK                        0x2u
#define FTM_POL_POL1_SHIFT                       1
#define FTM_POL_POL2_MASK                        0x4u
#define FTM_POL_POL2_SHIFT                       2
#define FTM_POL_POL3_MASK                        0x8u
#define FTM_POL_POL3_SHIFT                       3
#define FTM_POL_POL4_MASK                        0x10u
#define FTM_POL_POL4_SHIFT                       4
#define FTM_POL_POL5_MASK                        0x20u
#define FTM_POL_POL5_SHIFT                       5
#define FTM_POL_POL6_MASK                        0x40u
#define FTM_POL_POL6_SHIFT                       6
#define FTM_POL_POL7_MASK                        0x80u
#define FTM_POL_POL7_SHIFT                       7
/* FMS Bit Fields */
#define FTM_FMS_FAULTF0_MASK                     0x1u
#define FTM_FMS_FAULTF0_SHIFT                    0
#define FTM_FMS_FAULTF1_MASK                     0x2u
#define FTM_FMS_FAULTF1_SHIFT                    1
#define FTM_FMS_FAULTF2_MASK                     0x4u
#define FTM_FMS_FAULTF2_SHIFT                    2
#define FTM_FMS_FAULTF3_MASK                     0x8u
#define FTM_FMS_FAULTF3_SHIFT                    3
#define FTM_FMS_FAULTIN_MASK                     0x20u
#define FTM_FMS_FAULTIN_SHIFT                    5
#define FTM_FMS_WPEN_MASK                        0x40u
#define FTM_FMS_WPEN_SHIFT                       6
#define FTM_FMS_FAULTF_MASK                      0x80u
#define FTM_FMS_FAULTF_SHIFT                     7
/* FILTER Bit Fields */
#define FTM_FILTER_CH0FVAL_MASK                  0xFu
#define FTM_FILTER_CH0FVAL_SHIFT                 0
#define FTM_FILTER_CH0FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH0FVAL_SHIFT))&FTM_FILTER_CH0FVAL_MASK)
#define FTM_FILTER_CH1FVAL_MASK                  0xF0u
#define FTM_FILTER_CH1FVAL_SHIFT                 4
#define FTM_FILTER_CH1FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH1FVAL_SHIFT))&FTM_FILTER_CH1FVAL_MASK)
#define FTM_FILTER_CH2FVAL_MASK                  0xF00u
#define FTM_FILTER_CH2FVAL_SHIFT                 8
#define FTM_FILTER_CH2FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH2FVAL_SHIFT))&FTM_FILTER_CH2FVAL_MASK)
#define FTM_FILTER_CH3FVAL_MASK                  0xF000u
#define FTM_FILTER_CH3FVAL_SHIFT                 12
#define FTM_FILTER_CH3FVAL(x)                    (((uint32_t)(((uint32_t)(x))<<FTM_FILTER_CH3FVAL_SHIFT))&FTM_FILTER_CH3FVAL_MASK)
/* FLTCTRL Bit Fields */
#define FTM_FLTCTRL_FAULT0EN_MASK                0x1u
#define FTM_FLTCTRL_FAULT0EN_SHIFT               0
#define FTM_FLTCTRL_FAULT1EN_MASK                0x2u
#define FTM_FLTCTRL_FAULT1EN_SHIFT               1
#define FTM_FLTCTRL_FAULT2EN_MASK                0x4u
#define FTM_FLTCTRL_FAULT2EN_SHIFT               2
#define FTM_FLTCTRL_FAULT3EN_MASK                0x8u
#define FTM_FLTCTRL_FAULT3EN_SHIFT               3
#define FTM_FLTCTRL_FFLTR0EN_MASK                0x10u
#define FTM_FLTCTRL_FFLTR0EN_SHIFT               4
#define FTM_FLTCTRL_FFLTR1EN_MASK                0x20u
#define FTM_FLTCTRL_FFLTR1EN_SHIFT               5
#define FTM_FLTCTRL_FFLTR2EN_MASK                0x40u
#define FTM_FLTCTRL_FFLTR2EN_SHIFT               6
#define FTM_FLTCTRL_FFLTR3EN_MASK                0x80u
#define FTM_FLTCTRL_FFLTR3EN_SHIFT               7
#define FTM_FLTCTRL_FFVAL_MASK                   0xF00u
#define FTM_FLTCTRL_FFVAL_SHIFT                  8
#define FTM_FLTCTRL_FFVAL(x)                     (((uint32_t)(((uint32_t)(x))<<FTM_FLTCTRL_FFVAL_SHIFT))&FTM_FLTCTRL_FFVAL_MASK)
/* CONF Bit Fields */
#define FTM_CONF_NUMTOF_MASK                     0x1Fu
#define FTM_CONF_NUMTOF_SHIFT                    0
#define FTM_CONF_NUMTOF(x)                       (((uint32_t)(((uint32_t)(x))<<FTM_CONF_NUMTOF_SHIFT))&FTM_CONF_NUMTOF_MASK)
#define FTM_CONF_BDMMODE_MASK                    0xC0u
#define FTM_CONF_BDMMODE_SHIFT                   6
#define FTM_CONF_BDMMODE(x)                      (((uint32_t)(((uint32_t)(x))<<FTM_CONF_BDMMODE_SHIFT))&FTM_CONF_BDMMODE_MASK)
#define FTM_CONF_GTBEEN_MASK                     0x200u
#define FTM_CONF_GTBEEN_SHIFT                    9
#define FTM_CONF_GTBEOUT_MASK                    0x400u
#define FTM_CONF_GTBEOUT_SHIFT                   10
/* FLTPOL Bit Fields */
#define FTM_FLTPOL_FLT0POL_MASK                  0x1u
#define FTM_FLTPOL_FLT0POL_SHIFT                 0
#define FTM_FLTPOL_FLT1POL_MASK                  0x2u
#define FTM_FLTPOL_FLT1POL_SHIFT                 1
#define FTM_FLTPOL_FLT2POL_MASK                  0x4u
#define FTM_FLTPOL_FLT2POL_SHIFT                 2
#define FTM_FLTPOL_FLT3POL_MASK                  0x8u
#define FTM_FLTPOL_FLT3POL_SHIFT                 3
/* SYNCONF Bit Fields */
#define FTM_SYNCONF_HWTRIGMODE_MASK              0x1u
#define FTM_SYNCONF_HWTRIGMODE_SHIFT             0
#define FTM_SYNCONF_CNTINC_MASK                  0x4u
#define FTM_SYNCONF_CNTINC_SHIFT                 2
#define FTM_SYNCONF_INVC_MASK                    0x10u
#define FTM_SYNCONF_INVC_SHIFT                   4
#define FTM_SYNCONF_SWOC_MASK                    0x20u
#define FTM_SYNCONF_SWOC_SHIFT                   5
#define FTM_SYNCONF_SYNCMODE_MASK                0x80u
#define FTM_SYNCONF_SYNCMODE_SHIFT               7
#define FTM_SYNCONF_SWRSTCNT_MASK                0x100u
#define FTM_SYNCONF_SWRSTCNT_SHIFT               8
#define FTM_SYNCONF_SWWRBUF_MASK                 0x200u
#define FTM_SYNCONF_SWWRBUF_SHIFT                9
#define FTM_SYNCONF_SWOM_MASK                    0x400u
#define FTM_SYNCONF_SWOM_SHIFT                   10
#define FTM_SYNCONF_SWINVC_MASK                  0x800u
#define FTM_SYNCONF_SWINVC_SHIFT                 11
#define FTM_SYNCONF_SWSOC_MASK                   0x1000u
#define FTM_SYNCONF_SWSOC_SHIFT                  12
#define FTM_SYNCONF_HWRSTCNT_MASK                0x10000u
#define FTM_SYNCONF_HWRSTCNT_SHIFT               16
#define FTM_SYNCONF_HWWRBUF_MASK                 0x20000u
#define FTM_SYNCONF_HWWRBUF_SHIFT                17
#define FTM_SYNCONF_HWOM_MASK                    0x40000u
#define FTM_SYNCONF_HWOM_SHIFT                   18
#define FTM_SYNCONF_HWINVC_MASK                  0x80000u
#define FTM_SYNCONF_HWINVC_SHIFT                 19
#define FTM_SYNCONF_HWSOC_MASK                   0x100000u
#define FTM_SYNCONF_HWSOC_SHIFT                  20
/* INVCTRL Bit Fields */
#define FTM_INVCTRL_INV0EN_MASK                  0x1u
#define FTM_INVCTRL_INV0EN_SHIFT                 0
#define FTM_INVCTRL_INV1EN_MASK                  0x2u
#define FTM_INVCTRL_INV1EN_SHIFT                 1
#define FTM_INVCTRL_INV2EN_MASK                  0x4u
#define FTM_INVCTRL_INV2EN_SHIFT                 2
#define FTM_INVCTRL_INV3EN_MASK                  0x8u
#define FTM_INVCTRL_INV3EN_SHIFT                 3
/* SWOCTRL Bit Fields */
#define FTM_SWOCTRL_CH0OC_MASK                   0x1u
#define FTM_SWOCTRL_CH0OC_SHIFT                  0
#define FTM_SWOCTRL_CH1OC_MASK                   0x2u
#define FTM_SWOCTRL_CH1OC_SHIFT                  1
#define FTM_SWOCTRL_CH2OC_MASK                   0x4u
#define FTM_SWOCTRL_CH2OC_SHIFT                  2
#define FTM_SWOCTRL_CH3OC_MASK                   0x8u
#define FTM_SWOCTRL_CH3OC_SHIFT                  3
#define FTM_SWOCTRL_CH4OC_MASK                   0x10u
#define FTM_SWOCTRL_CH4OC_SHIFT                  4
#define FTM_SWOCTRL_CH5OC_MASK                   0x20u
#define FTM_SWOCTRL_CH5OC_SHIFT                  5
#define FTM_SWOCTRL_CH6OC_MASK                   0x40u
#define FTM_SWOCTRL_CH6OC_SHIFT                  6
#define FTM_SWOCTRL_CH7OC_MASK                   0x80u
#define FTM_SWOCTRL_CH7OC_SHIFT                  7
#define FTM_SWOCTRL_CH0OCV_MASK                  0x100u
#define FTM_SWOCTRL_CH0OCV_SHIFT                 8
#define FTM_SWOCTRL_CH1OCV_MASK                  0x200u
#define FTM_SWOCTRL_CH1OCV_SHIFT                 9
#define FTM_SWOCTRL_CH2OCV_MASK                  0x400u
#define FTM_SWOCTRL_CH2OCV_SHIFT                 10
#define FTM_SWOCTRL_CH3OCV_MASK                  0x800u
#define FTM_SWOCTRL_CH3OCV_SHIFT                 11
#define FTM_SWOCTRL_CH4OCV_MASK                  0x1000u
#define FTM_SWOCTRL_CH4OCV_SHIFT                 12
#define FTM_SWOCTRL_CH5OCV_MASK                  0x2000u
#define FTM_SWOCTRL_CH5OCV_SHIFT                 13
#define FTM_SWOCTRL_CH6OCV_MASK                  0x4000u
#define FTM_SWOCTRL_CH6OCV_SHIFT                 14
#define FTM_SWOCTRL_CH7OCV_MASK                  0x8000u
#define FTM_SWOCTRL_CH7OCV_SHIFT                 15
/* PWMLOAD Bit Fields */
#define FTM_PWMLOAD_CH0SEL_MASK                  0x1u
#define FTM_PWMLOAD_CH0SEL_SHIFT                 0
#define FTM_PWMLOAD_CH1SEL_MASK                  0x2u
#define FTM_PWMLOAD_CH1SEL_SHIFT                 1
#define FTM_PWMLOAD_CH2SEL_MASK                  0x4u
#define FTM_PWMLOAD_CH2SEL_SHIFT                 2
#define FTM_PWMLOAD_CH3SEL_MASK                  0x8u
#define FTM_PWMLOAD_CH3SEL_SHIFT                 3
#define FTM_PWMLOAD_CH4SEL_MASK                  0x10u
#define FTM_PWMLOAD_CH4SEL_SHIFT                 4
#define FTM_PWMLOAD_CH5SEL_MASK                  0x20u
#define FTM_PWMLOAD_CH5SEL_SHIFT                 5
#define FTM_PWMLOAD_CH6SEL_MASK                  0x40u
#define FTM_PWMLOAD_CH6SEL_SHIFT                 6
#define FTM_PWMLOAD_CH7SEL_MASK                  0x80u
#define FTM_PWMLOAD_CH7SEL_SHIFT                 7
#define FTM_PWMLOAD_LDOK_MASK                    0x200u
#define FTM_PWMLOAD_LDOK_SHIFT                   9

/*!
 * @}
 */ /* end of group FTM_Register_Masks */


/* FTM - Peripheral instance base addresses */
/** Peripheral FTM0 base address */
#define FTM0_BASE                                (0x40038000u)
/** Peripheral FTM0 base pointer */
#define FTM0                                     ((FTM_Type *)FTM0_BASE)
#define FTM0_BASE_PTR                            (FTM0)
/** Peripheral FTM1 base address */
#define FTM1_BASE                                (0x40039000u)
/** Peripheral FTM1 base pointer */
#define FTM1                                     ((FTM_Type *)FTM1_BASE)
#define FTM1_BASE_PTR                            (FTM1)
/** Peripheral FTM2 base address */
#define FTM2_BASE                                (0x4003A000u)
/** Peripheral FTM2 base pointer */
#define FTM2                                     ((FTM_Type *)FTM2_BASE)
#define FTM2_BASE_PTR                            (FTM2)
/** Array initializer of FTM peripheral base addresses */
#define FTM_BASE_ADDRS                           { FTM0_BASE, FTM1_BASE, FTM2_BASE }
/** Array initializer of FTM peripheral base pointers */
#define FTM_BASE_PTRS                            { FTM0, FTM1, FTM2 }

/* ----------------------------------------------------------------------------
   -- FTM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTM_Register_Accessor_Macros FTM - Register accessor macros
 * @{
 */


/* FTM - Register instance definitions */
/* FTM0 */
#define FTM0_SC                                  FTM_SC_REG(FTM0)
#define FTM0_CNT                                 FTM_CNT_REG(FTM0)
#define FTM0_MOD                                 FTM_MOD_REG(FTM0)
#define FTM0_C0SC                                FTM_CnSC_REG(FTM0,0)
#define FTM0_C0V                                 FTM_CnV_REG(FTM0,0)
#define FTM0_C1SC                                FTM_CnSC_REG(FTM0,1)
#define FTM0_C1V                                 FTM_CnV_REG(FTM0,1)
/* FTM1 */
#define FTM1_SC                                  FTM_SC_REG(FTM1)
#define FTM1_CNT                                 FTM_CNT_REG(FTM1)
#define FTM1_MOD                                 FTM_MOD_REG(FTM1)
#define FTM1_C0SC                                FTM_CnSC_REG(FTM1,0)
#define FTM1_C0V                                 FTM_CnV_REG(FTM1,0)
#define FTM1_C1SC                                FTM_CnSC_REG(FTM1,1)
#define FTM1_C1V                                 FTM_CnV_REG(FTM1,1)
/* FTM2 */
#define FTM2_SC                                  FTM_SC_REG(FTM2)
#define FTM2_CNT                                 FTM_CNT_REG(FTM2)
#define FTM2_MOD                                 FTM_MOD_REG(FTM2)
#define FTM2_C0SC                                FTM_CnSC_REG(FTM2,0)
#define FTM2_C0V                                 FTM_CnV_REG(FTM2,0)
#define FTM2_C1SC                                FTM_CnSC_REG(FTM2,1)
#define FTM2_C1V                                 FTM_CnV_REG(FTM2,1)
#define FTM2_C2SC                                FTM_CnSC_REG(FTM2,2)
#define FTM2_C2V                                 FTM_CnV_REG(FTM2,2)
#define FTM2_C3SC                                FTM_CnSC_REG(FTM2,3)
#define FTM2_C3V                                 FTM_CnV_REG(FTM2,3)
#define FTM2_C4SC                                FTM_CnSC_REG(FTM2,4)
#define FTM2_C4V                                 FTM_CnV_REG(FTM2,4)
#define FTM2_C5SC                                FTM_CnSC_REG(FTM2,5)
#define FTM2_C5V                                 FTM_CnV_REG(FTM2,5)
#define FTM2_CNTIN                               FTM_CNTIN_REG(FTM2)
#define FTM2_STATUS                              FTM_STATUS_REG(FTM2)
#define FTM2_MODE                                FTM_MODE_REG(FTM2)
#define FTM2_SYNC                                FTM_SYNC_REG(FTM2)
#define FTM2_OUTINIT                             FTM_OUTINIT_REG(FTM2)
#define FTM2_OUTMASK                             FTM_OUTMASK_REG(FTM2)
#define FTM2_COMBINE                             FTM_COMBINE_REG(FTM2)
#define FTM2_DEADTIME                            FTM_DEADTIME_REG(FTM2)
#define FTM2_EXTTRIG                             FTM_EXTTRIG_REG(FTM2)
#define FTM2_POL                                 FTM_POL_REG(FTM2)
#define FTM2_FMS                                 FTM_FMS_REG(FTM2)
#define FTM2_FILTER                              FTM_FILTER_REG(FTM2)
#define FTM2_FLTCTRL                             FTM_FLTCTRL_REG(FTM2)
#define FTM2_CONF                                FTM_CONF_REG(FTM2)
#define FTM2_FLTPOL                              FTM_FLTPOL_REG(FTM2)
#define FTM2_SYNCONF                             FTM_SYNCONF_REG(FTM2)
#define FTM2_INVCTRL                             FTM_INVCTRL_REG(FTM2)
#define FTM2_SWOCTRL                             FTM_SWOCTRL_REG(FTM2)
#define FTM2_PWMLOAD                             FTM_PWMLOAD_REG(FTM2)

/* FTM - Register array accessors */
#define FTM0_CnSC(index)                         FTM_CnSC_REG(FTM0,index)
#define FTM1_CnSC(index)                         FTM_CnSC_REG(FTM1,index)
#define FTM2_CnSC(index)                         FTM_CnSC_REG(FTM2,index)
#define FTM0_CnV(index)                          FTM_CnV_REG(FTM0,index)
#define FTM1_CnV(index)                          FTM_CnV_REG(FTM1,index)
#define FTM2_CnV(index)                          FTM_CnV_REG(FTM2,index)

/*!
 * @}
 */ /* end of group FTM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group FTM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- FTMRH Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTMRH_Peripheral_Access_Layer FTMRH Peripheral Access Layer
 * @{
 */

/** FTMRH - Register Layout Typedef */
typedef struct {
  __IO uint8_t FCLKDIV;                            /**< Flash Clock Divider Register, offset: 0x0 */
  __I  uint8_t FSEC;                               /**< Flash Security Register, offset: 0x1 */
  __IO uint8_t FCCOBIX;                            /**< Flash CCOB Index Register, offset: 0x2 */
       uint8_t RESERVED_0[1];
  __IO uint8_t FCNFG;                              /**< Flash Configuration Register, offset: 0x4 */
  __IO uint8_t FERCNFG;                            /**< Flash Error Configuration Register, offset: 0x5 */
  __IO uint8_t FSTAT;                              /**< Flash Status Register, offset: 0x6 */
  __IO uint8_t FERSTAT;                            /**< Flash Error Status Register, offset: 0x7 */
  __IO uint8_t FPROT;                              /**< Flash Protection Register, offset: 0x8 */
  __IO uint8_t EEPROT;                             /**< EEPROM Protection Register, offset: 0x9 */
  __IO uint8_t FCCOBHI;                            /**< Flash Common Command Object Register:High, offset: 0xA */
  __IO uint8_t FCCOBLO;                            /**< Flash Common Command Object Register: Low, offset: 0xB */
  __I  uint8_t FOPT;                               /**< Flash Option Register, offset: 0xC */
} FTMRH_Type, *FTMRH_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FTMRH - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTMRH_Register_Accessor_Macros FTMRH - Register accessor macros
 * @{
 */


/* FTMRH - Register accessors */
#define FTMRH_FCLKDIV_REG(base)                  ((base)->FCLKDIV)
#define FTMRH_FSEC_REG(base)                     ((base)->FSEC)
#define FTMRH_FCCOBIX_REG(base)                  ((base)->FCCOBIX)
#define FTMRH_FCNFG_REG(base)                    ((base)->FCNFG)
#define FTMRH_FERCNFG_REG(base)                  ((base)->FERCNFG)
#define FTMRH_FSTAT_REG(base)                    ((base)->FSTAT)
#define FTMRH_FERSTAT_REG(base)                  ((base)->FERSTAT)
#define FTMRH_FPROT_REG(base)                    ((base)->FPROT)
#define FTMRH_EEPROT_REG(base)                   ((base)->EEPROT)
#define FTMRH_FCCOBHI_REG(base)                  ((base)->FCCOBHI)
#define FTMRH_FCCOBLO_REG(base)                  ((base)->FCCOBLO)
#define FTMRH_FOPT_REG(base)                     ((base)->FOPT)

/*!
 * @}
 */ /* end of group FTMRH_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- FTMRH Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTMRH_Register_Masks FTMRH Register Masks
 * @{
 */

/* FCLKDIV Bit Fields */
#define FTMRH_FCLKDIV_FDIV_MASK                  0x3Fu
#define FTMRH_FCLKDIV_FDIV_SHIFT                 0
#define FTMRH_FCLKDIV_FDIV(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRH_FCLKDIV_FDIV_SHIFT))&FTMRH_FCLKDIV_FDIV_MASK)
#define FTMRH_FCLKDIV_FDIVLCK_MASK               0x40u
#define FTMRH_FCLKDIV_FDIVLCK_SHIFT              6
#define FTMRH_FCLKDIV_FDIVLD_MASK                0x80u
#define FTMRH_FCLKDIV_FDIVLD_SHIFT               7
/* FSEC Bit Fields */
#define FTMRH_FSEC_SEC_MASK                      0x3u
#define FTMRH_FSEC_SEC_SHIFT                     0
#define FTMRH_FSEC_SEC(x)                        (((uint8_t)(((uint8_t)(x))<<FTMRH_FSEC_SEC_SHIFT))&FTMRH_FSEC_SEC_MASK)
#define FTMRH_FSEC_KEYEN_MASK                    0xC0u
#define FTMRH_FSEC_KEYEN_SHIFT                   6
#define FTMRH_FSEC_KEYEN(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRH_FSEC_KEYEN_SHIFT))&FTMRH_FSEC_KEYEN_MASK)
/* FCCOBIX Bit Fields */
#define FTMRH_FCCOBIX_CCOBIX_MASK                0x7u
#define FTMRH_FCCOBIX_CCOBIX_SHIFT               0
#define FTMRH_FCCOBIX_CCOBIX(x)                  (((uint8_t)(((uint8_t)(x))<<FTMRH_FCCOBIX_CCOBIX_SHIFT))&FTMRH_FCCOBIX_CCOBIX_MASK)
/* FCNFG Bit Fields */
#define FTMRH_FCNFG_FSFD_MASK                    0x1u
#define FTMRH_FCNFG_FSFD_SHIFT                   0
#define FTMRH_FCNFG_FDFD_MASK                    0x2u
#define FTMRH_FCNFG_FDFD_SHIFT                   1
#define FTMRH_FCNFG_IGNSF_MASK                   0x10u
#define FTMRH_FCNFG_IGNSF_SHIFT                  4
#define FTMRH_FCNFG_CCIE_MASK                    0x80u
#define FTMRH_FCNFG_CCIE_SHIFT                   7
/* FERCNFG Bit Fields */
#define FTMRH_FERCNFG_SFDIE_MASK                 0x1u
#define FTMRH_FERCNFG_SFDIE_SHIFT                0
#define FTMRH_FERCNFG_DFDIE_MASK                 0x2u
#define FTMRH_FERCNFG_DFDIE_SHIFT                1
/* FSTAT Bit Fields */
#define FTMRH_FSTAT_MGSTAT_MASK                  0x3u
#define FTMRH_FSTAT_MGSTAT_SHIFT                 0
#define FTMRH_FSTAT_MGSTAT(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRH_FSTAT_MGSTAT_SHIFT))&FTMRH_FSTAT_MGSTAT_MASK)
#define FTMRH_FSTAT_MGBUSY_MASK                  0x8u
#define FTMRH_FSTAT_MGBUSY_SHIFT                 3
#define FTMRH_FSTAT_FPVIOL_MASK                  0x10u
#define FTMRH_FSTAT_FPVIOL_SHIFT                 4
#define FTMRH_FSTAT_ACCERR_MASK                  0x20u
#define FTMRH_FSTAT_ACCERR_SHIFT                 5
#define FTMRH_FSTAT_CCIF_MASK                    0x80u
#define FTMRH_FSTAT_CCIF_SHIFT                   7
/* FERSTAT Bit Fields */
#define FTMRH_FERSTAT_SFDIF_MASK                 0x1u
#define FTMRH_FERSTAT_SFDIF_SHIFT                0
#define FTMRH_FERSTAT_DFDIF_MASK                 0x2u
#define FTMRH_FERSTAT_DFDIF_SHIFT                1
/* FPROT Bit Fields */
#define FTMRH_FPROT_FPLS_MASK                    0x3u
#define FTMRH_FPROT_FPLS_SHIFT                   0
#define FTMRH_FPROT_FPLS(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRH_FPROT_FPLS_SHIFT))&FTMRH_FPROT_FPLS_MASK)
#define FTMRH_FPROT_FPLDIS_MASK                  0x4u
#define FTMRH_FPROT_FPLDIS_SHIFT                 2
#define FTMRH_FPROT_FPHS_MASK                    0x18u
#define FTMRH_FPROT_FPHS_SHIFT                   3
#define FTMRH_FPROT_FPHS(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRH_FPROT_FPHS_SHIFT))&FTMRH_FPROT_FPHS_MASK)
#define FTMRH_FPROT_FPHDIS_MASK                  0x20u
#define FTMRH_FPROT_FPHDIS_SHIFT                 5
#define FTMRH_FPROT_RNV6_MASK                    0x40u
#define FTMRH_FPROT_RNV6_SHIFT                   6
#define FTMRH_FPROT_FPOPEN_MASK                  0x80u
#define FTMRH_FPROT_FPOPEN_SHIFT                 7
/* EEPROT Bit Fields */
#define FTMRH_EEPROT_DPS_MASK                    0x7u
#define FTMRH_EEPROT_DPS_SHIFT                   0
#define FTMRH_EEPROT_DPS(x)                      (((uint8_t)(((uint8_t)(x))<<FTMRH_EEPROT_DPS_SHIFT))&FTMRH_EEPROT_DPS_MASK)
#define FTMRH_EEPROT_DPOPEN_MASK                 0x80u
#define FTMRH_EEPROT_DPOPEN_SHIFT                7
/* FCCOBHI Bit Fields */
#define FTMRH_FCCOBHI_CCOB_MASK                  0xFFu
#define FTMRH_FCCOBHI_CCOB_SHIFT                 0
#define FTMRH_FCCOBHI_CCOB(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRH_FCCOBHI_CCOB_SHIFT))&FTMRH_FCCOBHI_CCOB_MASK)
/* FCCOBLO Bit Fields */
#define FTMRH_FCCOBLO_CCOB_MASK                  0xFFu
#define FTMRH_FCCOBLO_CCOB_SHIFT                 0
#define FTMRH_FCCOBLO_CCOB(x)                    (((uint8_t)(((uint8_t)(x))<<FTMRH_FCCOBLO_CCOB_SHIFT))&FTMRH_FCCOBLO_CCOB_MASK)
/* FOPT Bit Fields */
#define FTMRH_FOPT_NV_MASK                       0xFFu
#define FTMRH_FOPT_NV_SHIFT                      0
#define FTMRH_FOPT_NV(x)                         (((uint8_t)(((uint8_t)(x))<<FTMRH_FOPT_NV_SHIFT))&FTMRH_FOPT_NV_MASK)

/*!
 * @}
 */ /* end of group FTMRH_Register_Masks */


/* FTMRH - Peripheral instance base addresses */
/** Peripheral FTMRH base address */
#define FTMRH_BASE                               (0x40020000u)
/** Peripheral FTMRH base pointer */
#define FTMRH                                    ((FTMRH_Type *)FTMRH_BASE)
#define FTMRH_BASE_PTR                           (FTMRH)
/** Array initializer of FTMRH peripheral base addresses */
#define FTMRH_BASE_ADDRS                         { FTMRH_BASE }
/** Array initializer of FTMRH peripheral base pointers */
#define FTMRH_BASE_PTRS                          { FTMRH }

/* ----------------------------------------------------------------------------
   -- FTMRH - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup FTMRH_Register_Accessor_Macros FTMRH - Register accessor macros
 * @{
 */


/* FTMRH - Register instance definitions */
/* FTMRH */
#define FTMRH_FCLKDIV                            FTMRH_FCLKDIV_REG(FTMRH)
#define FTMRH_FSEC                               FTMRH_FSEC_REG(FTMRH)
#define FTMRH_FCCOBIX                            FTMRH_FCCOBIX_REG(FTMRH)
#define FTMRH_FCNFG                              FTMRH_FCNFG_REG(FTMRH)
#define FTMRH_FERCNFG                            FTMRH_FERCNFG_REG(FTMRH)
#define FTMRH_FSTAT                              FTMRH_FSTAT_REG(FTMRH)
#define FTMRH_FERSTAT                            FTMRH_FERSTAT_REG(FTMRH)
#define FTMRH_FPROT                              FTMRH_FPROT_REG(FTMRH)
#define FTMRH_EEPROT                             FTMRH_EEPROT_REG(FTMRH)
#define FTMRH_FCCOBHI                            FTMRH_FCCOBHI_REG(FTMRH)
#define FTMRH_FCCOBLO                            FTMRH_FCCOBLO_REG(FTMRH)
#define FTMRH_FOPT                               FTMRH_FOPT_REG(FTMRH)

/*!
 * @}
 */ /* end of group FTMRH_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group FTMRH_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- GPIO Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Peripheral_Access_Layer GPIO Peripheral Access Layer
 * @{
 */

/** GPIO - Register Layout Typedef */
typedef struct {
  __IO uint32_t PDOR;                              /**< Port Data Output Register, offset: 0x0 */
  __O  uint32_t PSOR;                              /**< Port Set Output Register, offset: 0x4 */
  __O  uint32_t PCOR;                              /**< Port Clear Output Register, offset: 0x8 */
  __O  uint32_t PTOR;                              /**< Port Toggle Output Register, offset: 0xC */
  __I  uint32_t PDIR;                              /**< Port Data Input Register, offset: 0x10 */
  __IO uint32_t PDDR;                              /**< Port Data Direction Register, offset: 0x14 */
  __IO uint32_t PIDR;                              /**< Port Input Disable Register, offset: 0x18 */
} GPIO_Type, *GPIO_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- GPIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Accessor_Macros GPIO - Register accessor macros
 * @{
 */


/* GPIO - Register accessors */
#define GPIO_PDOR_REG(base)                      ((base)->PDOR)
#define GPIO_PSOR_REG(base)                      ((base)->PSOR)
#define GPIO_PCOR_REG(base)                      ((base)->PCOR)
#define GPIO_PTOR_REG(base)                      ((base)->PTOR)
#define GPIO_PDIR_REG(base)                      ((base)->PDIR)
#define GPIO_PDDR_REG(base)                      ((base)->PDDR)
#define GPIO_PIDR_REG(base)                      ((base)->PIDR)

/*!
 * @}
 */ /* end of group GPIO_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Masks GPIO Register Masks
 * @{
 */

/* PDOR Bit Fields */
#define GPIO_PDOR_PDO_MASK                       0xFFFFFFFFu
#define GPIO_PDOR_PDO_SHIFT                      0
#define GPIO_PDOR_PDO(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_PDOR_PDO_SHIFT))&GPIO_PDOR_PDO_MASK)
/* PSOR Bit Fields */
#define GPIO_PSOR_PTSO_MASK                      0xFFFFFFFFu
#define GPIO_PSOR_PTSO_SHIFT                     0
#define GPIO_PSOR_PTSO(x)                        (((uint32_t)(((uint32_t)(x))<<GPIO_PSOR_PTSO_SHIFT))&GPIO_PSOR_PTSO_MASK)
/* PCOR Bit Fields */
#define GPIO_PCOR_PTCO_MASK                      0xFFFFFFFFu
#define GPIO_PCOR_PTCO_SHIFT                     0
#define GPIO_PCOR_PTCO(x)                        (((uint32_t)(((uint32_t)(x))<<GPIO_PCOR_PTCO_SHIFT))&GPIO_PCOR_PTCO_MASK)
/* PTOR Bit Fields */
#define GPIO_PTOR_PTTO_MASK                      0xFFFFFFFFu
#define GPIO_PTOR_PTTO_SHIFT                     0
#define GPIO_PTOR_PTTO(x)                        (((uint32_t)(((uint32_t)(x))<<GPIO_PTOR_PTTO_SHIFT))&GPIO_PTOR_PTTO_MASK)
/* PDIR Bit Fields */
#define GPIO_PDIR_PDI_MASK                       0xFFFFFFFFu
#define GPIO_PDIR_PDI_SHIFT                      0
#define GPIO_PDIR_PDI(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_PDIR_PDI_SHIFT))&GPIO_PDIR_PDI_MASK)
/* PDDR Bit Fields */
#define GPIO_PDDR_PDD_MASK                       0xFFFFFFFFu
#define GPIO_PDDR_PDD_SHIFT                      0
#define GPIO_PDDR_PDD(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_PDDR_PDD_SHIFT))&GPIO_PDDR_PDD_MASK)
/* PIDR Bit Fields */
#define GPIO_PIDR_PID_MASK                       0xFFFFFFFFu
#define GPIO_PIDR_PID_SHIFT                      0
#define GPIO_PIDR_PID(x)                         (((uint32_t)(((uint32_t)(x))<<GPIO_PIDR_PID_SHIFT))&GPIO_PIDR_PID_MASK)

/*!
 * @}
 */ /* end of group GPIO_Register_Masks */


/* GPIO - Peripheral instance base addresses */
/** Peripheral GPIOA base address */
#define GPIOA_BASE                               (0x400FF000u)
/** Peripheral GPIOA base pointer */
#define GPIOA                                    ((GPIO_Type *)GPIOA_BASE)
#define GPIOA_BASE_PTR                           (GPIOA)
/** Peripheral GPIOB base address */
#define GPIOB_BASE                               (0x400FF040u)
/** Peripheral GPIOB base pointer */
#define GPIOB                                    ((GPIO_Type *)GPIOB_BASE)
#define GPIOB_BASE_PTR                           (GPIOB)
/** Array initializer of GPIO peripheral base addresses */
#define GPIO_BASE_ADDRS                          { GPIOA_BASE, GPIOB_BASE }
/** Array initializer of GPIO peripheral base pointers */
#define GPIO_BASE_PTRS                           { GPIOA, GPIOB }

/* ----------------------------------------------------------------------------
   -- GPIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup GPIO_Register_Accessor_Macros GPIO - Register accessor macros
 * @{
 */


/* GPIO - Register instance definitions */
/* GPIOA */
#define GPIOA_PDOR                               GPIO_PDOR_REG(GPIOA)
#define GPIOA_PSOR                               GPIO_PSOR_REG(GPIOA)
#define GPIOA_PCOR                               GPIO_PCOR_REG(GPIOA)
#define GPIOA_PTOR                               GPIO_PTOR_REG(GPIOA)
#define GPIOA_PDIR                               GPIO_PDIR_REG(GPIOA)
#define GPIOA_PDDR                               GPIO_PDDR_REG(GPIOA)
#define GPIOA_PIDR                               GPIO_PIDR_REG(GPIOA)
/* GPIOB */
#define GPIOB_PDOR                               GPIO_PDOR_REG(GPIOB)
#define GPIOB_PSOR                               GPIO_PSOR_REG(GPIOB)
#define GPIOB_PCOR                               GPIO_PCOR_REG(GPIOB)
#define GPIOB_PTOR                               GPIO_PTOR_REG(GPIOB)
#define GPIOB_PDIR                               GPIO_PDIR_REG(GPIOB)
#define GPIOB_PDDR                               GPIO_PDDR_REG(GPIOB)
#define GPIOB_PIDR                               GPIO_PIDR_REG(GPIOB)

/*!
 * @}
 */ /* end of group GPIO_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group GPIO_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- I2C Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C_Peripheral_Access_Layer I2C Peripheral Access Layer
 * @{
 */

/** I2C - Register Layout Typedef */
typedef struct {
  __IO uint8_t A1;                                 /**< I2C Address Register 1, offset: 0x0 */
  __IO uint8_t F;                                  /**< I2C Frequency Divider register, offset: 0x1 */
  __IO uint8_t C1;                                 /**< I2C Control Register 1, offset: 0x2 */
  __IO uint8_t S;                                  /**< I2C Status register, offset: 0x3 */
  __IO uint8_t D;                                  /**< I2C Data I/O register, offset: 0x4 */
  __IO uint8_t C2;                                 /**< I2C Control Register 2, offset: 0x5 */
  __IO uint8_t FLT;                                /**< I2C Programmable Input Glitch Filter register, offset: 0x6 */
  __IO uint8_t RA;                                 /**< I2C Range Address register, offset: 0x7 */
  __IO uint8_t SMB;                                /**< I2C SMBus Control and Status register, offset: 0x8 */
  __IO uint8_t A2;                                 /**< I2C Address Register 2, offset: 0x9 */
  __IO uint8_t SLTH;                               /**< I2C SCL Low Timeout Register High, offset: 0xA */
  __IO uint8_t SLTL;                               /**< I2C SCL Low Timeout Register Low, offset: 0xB */
} I2C_Type, *I2C_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- I2C - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C_Register_Accessor_Macros I2C - Register accessor macros
 * @{
 */


/* I2C - Register accessors */
#define I2C_A1_REG(base)                         ((base)->A1)
#define I2C_F_REG(base)                          ((base)->F)
#define I2C_C1_REG(base)                         ((base)->C1)
#define I2C_S_REG(base)                          ((base)->S)
#define I2C_D_REG(base)                          ((base)->D)
#define I2C_C2_REG(base)                         ((base)->C2)
#define I2C_FLT_REG(base)                        ((base)->FLT)
#define I2C_RA_REG(base)                         ((base)->RA)
#define I2C_SMB_REG(base)                        ((base)->SMB)
#define I2C_A2_REG(base)                         ((base)->A2)
#define I2C_SLTH_REG(base)                       ((base)->SLTH)
#define I2C_SLTL_REG(base)                       ((base)->SLTL)

/*!
 * @}
 */ /* end of group I2C_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- I2C Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C_Register_Masks I2C Register Masks
 * @{
 */

/* A1 Bit Fields */
#define I2C_A1_AD_MASK                           0xFEu
#define I2C_A1_AD_SHIFT                          1
#define I2C_A1_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_A1_AD_SHIFT))&I2C_A1_AD_MASK)
/* F Bit Fields */
#define I2C_F_ICR_MASK                           0x3Fu
#define I2C_F_ICR_SHIFT                          0
#define I2C_F_ICR(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_F_ICR_SHIFT))&I2C_F_ICR_MASK)
#define I2C_F_MULT_MASK                          0xC0u
#define I2C_F_MULT_SHIFT                         6
#define I2C_F_MULT(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_F_MULT_SHIFT))&I2C_F_MULT_MASK)
/* C1 Bit Fields */
#define I2C_C1_WUEN_MASK                         0x2u
#define I2C_C1_WUEN_SHIFT                        1
#define I2C_C1_RSTA_MASK                         0x4u
#define I2C_C1_RSTA_SHIFT                        2
#define I2C_C1_TXAK_MASK                         0x8u
#define I2C_C1_TXAK_SHIFT                        3
#define I2C_C1_TX_MASK                           0x10u
#define I2C_C1_TX_SHIFT                          4
#define I2C_C1_MST_MASK                          0x20u
#define I2C_C1_MST_SHIFT                         5
#define I2C_C1_IICIE_MASK                        0x40u
#define I2C_C1_IICIE_SHIFT                       6
#define I2C_C1_IICEN_MASK                        0x80u
#define I2C_C1_IICEN_SHIFT                       7
/* S Bit Fields */
#define I2C_S_RXAK_MASK                          0x1u
#define I2C_S_RXAK_SHIFT                         0
#define I2C_S_IICIF_MASK                         0x2u
#define I2C_S_IICIF_SHIFT                        1
#define I2C_S_SRW_MASK                           0x4u
#define I2C_S_SRW_SHIFT                          2
#define I2C_S_RAM_MASK                           0x8u
#define I2C_S_RAM_SHIFT                          3
#define I2C_S_ARBL_MASK                          0x10u
#define I2C_S_ARBL_SHIFT                         4
#define I2C_S_BUSY_MASK                          0x20u
#define I2C_S_BUSY_SHIFT                         5
#define I2C_S_IAAS_MASK                          0x40u
#define I2C_S_IAAS_SHIFT                         6
#define I2C_S_TCF_MASK                           0x80u
#define I2C_S_TCF_SHIFT                          7
/* D Bit Fields */
#define I2C_D_DATA_MASK                          0xFFu
#define I2C_D_DATA_SHIFT                         0
#define I2C_D_DATA(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_D_DATA_SHIFT))&I2C_D_DATA_MASK)
/* C2 Bit Fields */
#define I2C_C2_AD_MASK                           0x7u
#define I2C_C2_AD_SHIFT                          0
#define I2C_C2_AD(x)                             (((uint8_t)(((uint8_t)(x))<<I2C_C2_AD_SHIFT))&I2C_C2_AD_MASK)
#define I2C_C2_RMEN_MASK                         0x8u
#define I2C_C2_RMEN_SHIFT                        3
#define I2C_C2_SBRC_MASK                         0x10u
#define I2C_C2_SBRC_SHIFT                        4
#define I2C_C2_ADEXT_MASK                        0x40u
#define I2C_C2_ADEXT_SHIFT                       6
#define I2C_C2_GCAEN_MASK                        0x80u
#define I2C_C2_GCAEN_SHIFT                       7
/* FLT Bit Fields */
#define I2C_FLT_FLT_MASK                         0xFu
#define I2C_FLT_FLT_SHIFT                        0
#define I2C_FLT_FLT(x)                           (((uint8_t)(((uint8_t)(x))<<I2C_FLT_FLT_SHIFT))&I2C_FLT_FLT_MASK)
#define I2C_FLT_STARTF_MASK                      0x10u
#define I2C_FLT_STARTF_SHIFT                     4
#define I2C_FLT_SSIE_MASK                        0x20u
#define I2C_FLT_SSIE_SHIFT                       5
#define I2C_FLT_STOPF_MASK                       0x40u
#define I2C_FLT_STOPF_SHIFT                      6
#define I2C_FLT_SHEN_MASK                        0x80u
#define I2C_FLT_SHEN_SHIFT                       7
/* RA Bit Fields */
#define I2C_RA_RAD_MASK                          0xFEu
#define I2C_RA_RAD_SHIFT                         1
#define I2C_RA_RAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_RA_RAD_SHIFT))&I2C_RA_RAD_MASK)
/* SMB Bit Fields */
#define I2C_SMB_SHTF2IE_MASK                     0x1u
#define I2C_SMB_SHTF2IE_SHIFT                    0
#define I2C_SMB_SHTF2_MASK                       0x2u
#define I2C_SMB_SHTF2_SHIFT                      1
#define I2C_SMB_SHTF1_MASK                       0x4u
#define I2C_SMB_SHTF1_SHIFT                      2
#define I2C_SMB_SLTF_MASK                        0x8u
#define I2C_SMB_SLTF_SHIFT                       3
#define I2C_SMB_TCKSEL_MASK                      0x10u
#define I2C_SMB_TCKSEL_SHIFT                     4
#define I2C_SMB_SIICAEN_MASK                     0x20u
#define I2C_SMB_SIICAEN_SHIFT                    5
#define I2C_SMB_ALERTEN_MASK                     0x40u
#define I2C_SMB_ALERTEN_SHIFT                    6
#define I2C_SMB_FACK_MASK                        0x80u
#define I2C_SMB_FACK_SHIFT                       7
/* A2 Bit Fields */
#define I2C_A2_SAD_MASK                          0xFEu
#define I2C_A2_SAD_SHIFT                         1
#define I2C_A2_SAD(x)                            (((uint8_t)(((uint8_t)(x))<<I2C_A2_SAD_SHIFT))&I2C_A2_SAD_MASK)
/* SLTH Bit Fields */
#define I2C_SLTH_SSLT_MASK                       0xFFu
#define I2C_SLTH_SSLT_SHIFT                      0
#define I2C_SLTH_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTH_SSLT_SHIFT))&I2C_SLTH_SSLT_MASK)
/* SLTL Bit Fields */
#define I2C_SLTL_SSLT_MASK                       0xFFu
#define I2C_SLTL_SSLT_SHIFT                      0
#define I2C_SLTL_SSLT(x)                         (((uint8_t)(((uint8_t)(x))<<I2C_SLTL_SSLT_SHIFT))&I2C_SLTL_SSLT_MASK)

/*!
 * @}
 */ /* end of group I2C_Register_Masks */


/* I2C - Peripheral instance base addresses */
/** Peripheral I2C0 base address */
#define I2C0_BASE                                (0x40066000u)
/** Peripheral I2C0 base pointer */
#define I2C0                                     ((I2C_Type *)I2C0_BASE)
#define I2C0_BASE_PTR                            (I2C0)
/** Array initializer of I2C peripheral base addresses */
#define I2C_BASE_ADDRS                           { I2C0_BASE }
/** Array initializer of I2C peripheral base pointers */
#define I2C_BASE_PTRS                            { I2C0 }

/* ----------------------------------------------------------------------------
   -- I2C - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup I2C_Register_Accessor_Macros I2C - Register accessor macros
 * @{
 */


/* I2C - Register instance definitions */
/* I2C0 */
#define I2C0_A1                                  I2C_A1_REG(I2C0)
#define I2C0_F                                   I2C_F_REG(I2C0)
#define I2C0_C1                                  I2C_C1_REG(I2C0)
#define I2C0_S                                   I2C_S_REG(I2C0)
#define I2C0_D                                   I2C_D_REG(I2C0)
#define I2C0_C2                                  I2C_C2_REG(I2C0)
#define I2C0_FLT                                 I2C_FLT_REG(I2C0)
#define I2C0_RA                                  I2C_RA_REG(I2C0)
#define I2C0_SMB                                 I2C_SMB_REG(I2C0)
#define I2C0_A2                                  I2C_A2_REG(I2C0)
#define I2C0_SLTH                                I2C_SLTH_REG(I2C0)
#define I2C0_SLTL                                I2C_SLTL_REG(I2C0)

/*!
 * @}
 */ /* end of group I2C_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group I2C_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- ICS Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ICS_Peripheral_Access_Layer ICS Peripheral Access Layer
 * @{
 */

/** ICS - Register Layout Typedef */
typedef struct {
  __IO uint8_t C1;                                 /**< ICS Control Register 1, offset: 0x0 */
  __IO uint8_t C2;                                 /**< ICS Control Register 2, offset: 0x1 */
  __IO uint8_t C3;                                 /**< ICS Control Register 3, offset: 0x2 */
  __IO uint8_t C4;                                 /**< ICS Control Register 4, offset: 0x3 */
  __I  uint8_t S;                                  /**< ICS Status Register, offset: 0x4 */
} ICS_Type, *ICS_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ICS - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ICS_Register_Accessor_Macros ICS - Register accessor macros
 * @{
 */


/* ICS - Register accessors */
#define ICS_C1_REG(base)                         ((base)->C1)
#define ICS_C2_REG(base)                         ((base)->C2)
#define ICS_C3_REG(base)                         ((base)->C3)
#define ICS_C4_REG(base)                         ((base)->C4)
#define ICS_S_REG(base)                          ((base)->S)

/*!
 * @}
 */ /* end of group ICS_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ICS Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ICS_Register_Masks ICS Register Masks
 * @{
 */

/* C1 Bit Fields */
#define ICS_C1_IREFSTEN_MASK                     0x1u
#define ICS_C1_IREFSTEN_SHIFT                    0
#define ICS_C1_IRCLKEN_MASK                      0x2u
#define ICS_C1_IRCLKEN_SHIFT                     1
#define ICS_C1_IREFS_MASK                        0x4u
#define ICS_C1_IREFS_SHIFT                       2
#define ICS_C1_RDIV_MASK                         0x38u
#define ICS_C1_RDIV_SHIFT                        3
#define ICS_C1_RDIV(x)                           (((uint8_t)(((uint8_t)(x))<<ICS_C1_RDIV_SHIFT))&ICS_C1_RDIV_MASK)
#define ICS_C1_CLKS_MASK                         0xC0u
#define ICS_C1_CLKS_SHIFT                        6
#define ICS_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x))<<ICS_C1_CLKS_SHIFT))&ICS_C1_CLKS_MASK)
/* C2 Bit Fields */
#define ICS_C2_LP_MASK                           0x10u
#define ICS_C2_LP_SHIFT                          4
#define ICS_C2_BDIV_MASK                         0xE0u
#define ICS_C2_BDIV_SHIFT                        5
#define ICS_C2_BDIV(x)                           (((uint8_t)(((uint8_t)(x))<<ICS_C2_BDIV_SHIFT))&ICS_C2_BDIV_MASK)
/* C3 Bit Fields */
#define ICS_C3_SCTRIM_MASK                       0xFFu
#define ICS_C3_SCTRIM_SHIFT                      0
#define ICS_C3_SCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<ICS_C3_SCTRIM_SHIFT))&ICS_C3_SCTRIM_MASK)
/* C4 Bit Fields */
#define ICS_C4_SCFTRIM_MASK                      0x1u
#define ICS_C4_SCFTRIM_SHIFT                     0
#define ICS_C4_CME_MASK                          0x20u
#define ICS_C4_CME_SHIFT                         5
#define ICS_C4_LOLIE_MASK                        0x80u
#define ICS_C4_LOLIE_SHIFT                       7
/* S Bit Fields */
#define ICS_S_CLKST_MASK                         0xCu
#define ICS_S_CLKST_SHIFT                        2
#define ICS_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x))<<ICS_S_CLKST_SHIFT))&ICS_S_CLKST_MASK)
#define ICS_S_IREFST_MASK                        0x10u
#define ICS_S_IREFST_SHIFT                       4
#define ICS_S_LOCK_MASK                          0x40u
#define ICS_S_LOCK_SHIFT                         6
#define ICS_S_LOLS_MASK                          0x80u
#define ICS_S_LOLS_SHIFT                         7

/*!
 * @}
 */ /* end of group ICS_Register_Masks */


/* ICS - Peripheral instance base addresses */
/** Peripheral ICS base address */
#define ICS_BASE                                 (0x40064000u)
/** Peripheral ICS base pointer */
#define ICS                                      ((ICS_Type *)ICS_BASE)
#define ICS_BASE_PTR                             (ICS)
/** Array initializer of ICS peripheral base addresses */
#define ICS_BASE_ADDRS                           { ICS_BASE }
/** Array initializer of ICS peripheral base pointers */
#define ICS_BASE_PTRS                            { ICS }

/* ----------------------------------------------------------------------------
   -- ICS - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ICS_Register_Accessor_Macros ICS - Register accessor macros
 * @{
 */


/* ICS - Register instance definitions */
/* ICS */
#define ICS_C1                                   ICS_C1_REG(ICS)
#define ICS_C2                                   ICS_C2_REG(ICS)
#define ICS_C3                                   ICS_C3_REG(ICS)
#define ICS_C4                                   ICS_C4_REG(ICS)
#define ICS_S                                    ICS_S_REG(ICS)

/*!
 * @}
 */ /* end of group ICS_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group ICS_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- IRQ Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IRQ_Peripheral_Access_Layer IRQ Peripheral Access Layer
 * @{
 */

/** IRQ - Register Layout Typedef */
typedef struct {
  __IO uint8_t SC;                                 /**< Interrupt Pin Request Status and Control Register, offset: 0x0 */
} IRQ_Type, *IRQ_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- IRQ - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IRQ_Register_Accessor_Macros IRQ - Register accessor macros
 * @{
 */


/* IRQ - Register accessors */
#define IRQ_SC_REG(base)                         ((base)->SC)

/*!
 * @}
 */ /* end of group IRQ_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- IRQ Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IRQ_Register_Masks IRQ Register Masks
 * @{
 */

/* SC Bit Fields */
#define IRQ_SC_IRQMOD_MASK                       0x1u
#define IRQ_SC_IRQMOD_SHIFT                      0
#define IRQ_SC_IRQIE_MASK                        0x2u
#define IRQ_SC_IRQIE_SHIFT                       1
#define IRQ_SC_IRQACK_MASK                       0x4u
#define IRQ_SC_IRQACK_SHIFT                      2
#define IRQ_SC_IRQF_MASK                         0x8u
#define IRQ_SC_IRQF_SHIFT                        3
#define IRQ_SC_IRQPE_MASK                        0x10u
#define IRQ_SC_IRQPE_SHIFT                       4
#define IRQ_SC_IRQEDG_MASK                       0x20u
#define IRQ_SC_IRQEDG_SHIFT                      5
#define IRQ_SC_IRQPDD_MASK                       0x40u
#define IRQ_SC_IRQPDD_SHIFT                      6

/*!
 * @}
 */ /* end of group IRQ_Register_Masks */


/* IRQ - Peripheral instance base addresses */
/** Peripheral IRQ base address */
#define IRQ_BASE                                 (0x40031000u)
/** Peripheral IRQ base pointer */
#define IRQ                                      ((IRQ_Type *)IRQ_BASE)
#define IRQ_BASE_PTR                             (IRQ)
/** Array initializer of IRQ peripheral base addresses */
#define IRQ_BASE_ADDRS                           { IRQ_BASE }
/** Array initializer of IRQ peripheral base pointers */
#define IRQ_BASE_PTRS                            { IRQ }

/* ----------------------------------------------------------------------------
   -- IRQ - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IRQ_Register_Accessor_Macros IRQ - Register accessor macros
 * @{
 */


/* IRQ - Register instance definitions */
/* IRQ */
#define IRQ_SC                                   IRQ_SC_REG(IRQ)

/*!
 * @}
 */ /* end of group IRQ_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group IRQ_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- KBI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup KBI_Peripheral_Access_Layer KBI Peripheral Access Layer
 * @{
 */

/** KBI - Register Layout Typedef */
typedef struct {
  __IO uint8_t SC;                                 /**< KBI Status and Control Register, offset: 0x0 */
  __IO uint8_t PE;                                 /**< KBIx Pin Enable Register, offset: 0x1 */
  __IO uint8_t ES;                                 /**< KBIx Edge Select Register, offset: 0x2 */
} KBI_Type, *KBI_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- KBI - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup KBI_Register_Accessor_Macros KBI - Register accessor macros
 * @{
 */


/* KBI - Register accessors */
#define KBI_SC_REG(base)                         ((base)->SC)
#define KBI_PE_REG(base)                         ((base)->PE)
#define KBI_ES_REG(base)                         ((base)->ES)

/*!
 * @}
 */ /* end of group KBI_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- KBI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup KBI_Register_Masks KBI Register Masks
 * @{
 */

/* SC Bit Fields */
#define KBI_SC_KBMOD_MASK                        0x1u
#define KBI_SC_KBMOD_SHIFT                       0
#define KBI_SC_KBIE_MASK                         0x2u
#define KBI_SC_KBIE_SHIFT                        1
#define KBI_SC_KBACK_MASK                        0x4u
#define KBI_SC_KBACK_SHIFT                       2
#define KBI_SC_KBF_MASK                          0x8u
#define KBI_SC_KBF_SHIFT                         3
/* PE Bit Fields */
#define KBI_PE_KBIPE_MASK                        0xFFu
#define KBI_PE_KBIPE_SHIFT                       0
#define KBI_PE_KBIPE(x)                          (((uint8_t)(((uint8_t)(x))<<KBI_PE_KBIPE_SHIFT))&KBI_PE_KBIPE_MASK)
/* ES Bit Fields */
#define KBI_ES_KBEDG_MASK                        0xFFu
#define KBI_ES_KBEDG_SHIFT                       0
#define KBI_ES_KBEDG(x)                          (((uint8_t)(((uint8_t)(x))<<KBI_ES_KBEDG_SHIFT))&KBI_ES_KBEDG_MASK)

/*!
 * @}
 */ /* end of group KBI_Register_Masks */


/* KBI - Peripheral instance base addresses */
/** Peripheral KBI0 base address */
#define KBI0_BASE                                (0x40079000u)
/** Peripheral KBI0 base pointer */
#define KBI0                                     ((KBI_Type *)KBI0_BASE)
#define KBI0_BASE_PTR                            (KBI0)
/** Peripheral KBI1 base address */
#define KBI1_BASE                                (0x4007A000u)
/** Peripheral KBI1 base pointer */
#define KBI1                                     ((KBI_Type *)KBI1_BASE)
#define KBI1_BASE_PTR                            (KBI1)
/** Array initializer of KBI peripheral base addresses */
#define KBI_BASE_ADDRS                           { KBI0_BASE, KBI1_BASE }
/** Array initializer of KBI peripheral base pointers */
#define KBI_BASE_PTRS                            { KBI0, KBI1 }

/* ----------------------------------------------------------------------------
   -- KBI - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup KBI_Register_Accessor_Macros KBI - Register accessor macros
 * @{
 */


/* KBI - Register instance definitions */
/* KBI0 */
#define KBI0_SC                                  KBI_SC_REG(KBI0)
#define KBI0_PE                                  KBI_PE_REG(KBI0)
#define KBI0_ES                                  KBI_ES_REG(KBI0)
/* KBI1 */
#define KBI1_SC                                  KBI_SC_REG(KBI1)
#define KBI1_PE                                  KBI_PE_REG(KBI1)
#define KBI1_ES                                  KBI_ES_REG(KBI1)

/*!
 * @}
 */ /* end of group KBI_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group KBI_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- MCM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Peripheral_Access_Layer MCM Peripheral Access Layer
 * @{
 */

/** MCM - Register Layout Typedef */
typedef struct {
       uint8_t RESERVED_0[8];
  __I  uint16_t PLASC;                             /**< Crossbar Switch (AXBS) Slave Configuration, offset: 0x8 */
  __I  uint16_t PLAMC;                             /**< Crossbar Switch (AXBS) Master Configuration, offset: 0xA */
  __IO uint32_t PLACR;                             /**< Platform Control Register, offset: 0xC */
} MCM_Type, *MCM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Accessor_Macros MCM - Register accessor macros
 * @{
 */


/* MCM - Register accessors */
#define MCM_PLASC_REG(base)                      ((base)->PLASC)
#define MCM_PLAMC_REG(base)                      ((base)->PLAMC)
#define MCM_PLACR_REG(base)                      ((base)->PLACR)

/*!
 * @}
 */ /* end of group MCM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MCM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Masks MCM Register Masks
 * @{
 */

/* PLASC Bit Fields */
#define MCM_PLASC_ASC_MASK                       0xFFu
#define MCM_PLASC_ASC_SHIFT                      0
#define MCM_PLASC_ASC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLASC_ASC_SHIFT))&MCM_PLASC_ASC_MASK)
/* PLAMC Bit Fields */
#define MCM_PLAMC_AMC_MASK                       0xFFu
#define MCM_PLAMC_AMC_SHIFT                      0
#define MCM_PLAMC_AMC(x)                         (((uint16_t)(((uint16_t)(x))<<MCM_PLAMC_AMC_SHIFT))&MCM_PLAMC_AMC_MASK)
/* PLACR Bit Fields */
#define MCM_PLACR_CFCC_MASK                      0x400u
#define MCM_PLACR_CFCC_SHIFT                     10
#define MCM_PLACR_DFCDA_MASK                     0x800u
#define MCM_PLACR_DFCDA_SHIFT                    11
#define MCM_PLACR_DFCIC_MASK                     0x1000u
#define MCM_PLACR_DFCIC_SHIFT                    12
#define MCM_PLACR_DFCC_MASK                      0x2000u
#define MCM_PLACR_DFCC_SHIFT                     13
#define MCM_PLACR_EFDS_MASK                      0x4000u
#define MCM_PLACR_EFDS_SHIFT                     14
#define MCM_PLACR_DFCS_MASK                      0x8000u
#define MCM_PLACR_DFCS_SHIFT                     15
#define MCM_PLACR_ESFC_MASK                      0x10000u
#define MCM_PLACR_ESFC_SHIFT                     16

/*!
 * @}
 */ /* end of group MCM_Register_Masks */


/* MCM - Peripheral instance base addresses */
/** Peripheral MCM base address */
#define MCM_BASE                                 (0xF0003000u)
/** Peripheral MCM base pointer */
#define MCM                                      ((MCM_Type *)MCM_BASE)
#define MCM_BASE_PTR                             (MCM)
/** Array initializer of MCM peripheral base addresses */
#define MCM_BASE_ADDRS                           { MCM_BASE }
/** Array initializer of MCM peripheral base pointers */
#define MCM_BASE_PTRS                            { MCM }

/* ----------------------------------------------------------------------------
   -- MCM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCM_Register_Accessor_Macros MCM - Register accessor macros
 * @{
 */


/* MCM - Register instance definitions */
/* MCM */
#define MCM_PLASC                                MCM_PLASC_REG(MCM)
#define MCM_PLAMC                                MCM_PLAMC_REG(MCM)
#define MCM_PLACR                                MCM_PLACR_REG(MCM)

/*!
 * @}
 */ /* end of group MCM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group MCM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- NV Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Peripheral_Access_Layer NV Peripheral Access Layer
 * @{
 */

/** NV - Register Layout Typedef */
typedef struct {
  __I  uint8_t BACKKEY0;                           /**< Backdoor Comparison Key 0, offset: 0x0 */
  __I  uint8_t BACKKEY1;                           /**< Backdoor Comparison Key 1, offset: 0x1 */
  __I  uint8_t BACKKEY2;                           /**< Backdoor Comparison Key 2, offset: 0x2 */
  __I  uint8_t BACKKEY3;                           /**< Backdoor Comparison Key 3, offset: 0x3 */
  __I  uint8_t BACKKEY4;                           /**< Backdoor Comparison Key 4, offset: 0x4 */
  __I  uint8_t BACKKEY5;                           /**< Backdoor Comparison Key 5, offset: 0x5 */
  __I  uint8_t BACKKEY6;                           /**< Backdoor Comparison Key 6, offset: 0x6 */
  __I  uint8_t BACKKEY7;                           /**< Backdoor Comparison Key 7, offset: 0x7 */
       uint8_t RESERVED_0[4];
  __I  uint8_t EEPROT;                             /**< Non-volatile E-Flash Protection Register, offset: 0xC */
  __I  uint8_t FPROT;                              /**< Non-volatile P-Flash Protection Register, offset: 0xD */
  __I  uint8_t FSEC;                               /**< Non-volatile Flash Security Register, offset: 0xE */
  __I  uint8_t FOPT;                               /**< Non-volatile Flash Option Register, offset: 0xF */
} NV_Type, *NV_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- NV - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Register_Accessor_Macros NV - Register accessor macros
 * @{
 */


/* NV - Register accessors */
#define NV_BACKKEY0_REG(base)                    ((base)->BACKKEY0)
#define NV_BACKKEY1_REG(base)                    ((base)->BACKKEY1)
#define NV_BACKKEY2_REG(base)                    ((base)->BACKKEY2)
#define NV_BACKKEY3_REG(base)                    ((base)->BACKKEY3)
#define NV_BACKKEY4_REG(base)                    ((base)->BACKKEY4)
#define NV_BACKKEY5_REG(base)                    ((base)->BACKKEY5)
#define NV_BACKKEY6_REG(base)                    ((base)->BACKKEY6)
#define NV_BACKKEY7_REG(base)                    ((base)->BACKKEY7)
#define NV_EEPROT_REG(base)                      ((base)->EEPROT)
#define NV_FPROT_REG(base)                       ((base)->FPROT)
#define NV_FSEC_REG(base)                        ((base)->FSEC)
#define NV_FOPT_REG(base)                        ((base)->FOPT)

/*!
 * @}
 */ /* end of group NV_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- NV Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Register_Masks NV Register Masks
 * @{
 */

/* BACKKEY0 Bit Fields */
#define NV_BACKKEY0_KEY_MASK                     0xFFu
#define NV_BACKKEY0_KEY_SHIFT                    0
#define NV_BACKKEY0_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY0_KEY_SHIFT))&NV_BACKKEY0_KEY_MASK)
/* BACKKEY1 Bit Fields */
#define NV_BACKKEY1_KEY_MASK                     0xFFu
#define NV_BACKKEY1_KEY_SHIFT                    0
#define NV_BACKKEY1_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY1_KEY_SHIFT))&NV_BACKKEY1_KEY_MASK)
/* BACKKEY2 Bit Fields */
#define NV_BACKKEY2_KEY_MASK                     0xFFu
#define NV_BACKKEY2_KEY_SHIFT                    0
#define NV_BACKKEY2_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY2_KEY_SHIFT))&NV_BACKKEY2_KEY_MASK)
/* BACKKEY3 Bit Fields */
#define NV_BACKKEY3_KEY_MASK                     0xFFu
#define NV_BACKKEY3_KEY_SHIFT                    0
#define NV_BACKKEY3_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY3_KEY_SHIFT))&NV_BACKKEY3_KEY_MASK)
/* BACKKEY4 Bit Fields */
#define NV_BACKKEY4_KEY_MASK                     0xFFu
#define NV_BACKKEY4_KEY_SHIFT                    0
#define NV_BACKKEY4_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY4_KEY_SHIFT))&NV_BACKKEY4_KEY_MASK)
/* BACKKEY5 Bit Fields */
#define NV_BACKKEY5_KEY_MASK                     0xFFu
#define NV_BACKKEY5_KEY_SHIFT                    0
#define NV_BACKKEY5_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY5_KEY_SHIFT))&NV_BACKKEY5_KEY_MASK)
/* BACKKEY6 Bit Fields */
#define NV_BACKKEY6_KEY_MASK                     0xFFu
#define NV_BACKKEY6_KEY_SHIFT                    0
#define NV_BACKKEY6_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY6_KEY_SHIFT))&NV_BACKKEY6_KEY_MASK)
/* BACKKEY7 Bit Fields */
#define NV_BACKKEY7_KEY_MASK                     0xFFu
#define NV_BACKKEY7_KEY_SHIFT                    0
#define NV_BACKKEY7_KEY(x)                       (((uint8_t)(((uint8_t)(x))<<NV_BACKKEY7_KEY_SHIFT))&NV_BACKKEY7_KEY_MASK)
/* EEPROT Bit Fields */
#define NV_EEPROT_DPS_MASK                       0x7u
#define NV_EEPROT_DPS_SHIFT                      0
#define NV_EEPROT_DPS(x)                         (((uint8_t)(((uint8_t)(x))<<NV_EEPROT_DPS_SHIFT))&NV_EEPROT_DPS_MASK)
#define NV_EEPROT_DPOPEN_MASK                    0x80u
#define NV_EEPROT_DPOPEN_SHIFT                   7
/* FPROT Bit Fields */
#define NV_FPROT_FPLS_MASK                       0x3u
#define NV_FPROT_FPLS_SHIFT                      0
#define NV_FPROT_FPLS(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FPROT_FPLS_SHIFT))&NV_FPROT_FPLS_MASK)
#define NV_FPROT_FPLDIS_MASK                     0x4u
#define NV_FPROT_FPLDIS_SHIFT                    2
#define NV_FPROT_FPHS_MASK                       0x18u
#define NV_FPROT_FPHS_SHIFT                      3
#define NV_FPROT_FPHS(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FPROT_FPHS_SHIFT))&NV_FPROT_FPHS_MASK)
#define NV_FPROT_FPHDIS_MASK                     0x20u
#define NV_FPROT_FPHDIS_SHIFT                    5
#define NV_FPROT_FPOPEN_MASK                     0x80u
#define NV_FPROT_FPOPEN_SHIFT                    7
/* FSEC Bit Fields */
#define NV_FSEC_SEC_MASK                         0x3u
#define NV_FSEC_SEC_SHIFT                        0
#define NV_FSEC_SEC(x)                           (((uint8_t)(((uint8_t)(x))<<NV_FSEC_SEC_SHIFT))&NV_FSEC_SEC_MASK)
#define NV_FSEC_KEYEN_MASK                       0xC0u
#define NV_FSEC_KEYEN_SHIFT                      6
#define NV_FSEC_KEYEN(x)                         (((uint8_t)(((uint8_t)(x))<<NV_FSEC_KEYEN_SHIFT))&NV_FSEC_KEYEN_MASK)

/*!
 * @}
 */ /* end of group NV_Register_Masks */


/* NV - Peripheral instance base addresses */
/** Peripheral FTMRH_FlashConfig base address */
#define FTMRH_FlashConfig_BASE                   (0x400u)
/** Peripheral FTMRH_FlashConfig base pointer */
#define FTMRH_FlashConfig                        ((NV_Type *)FTMRH_FlashConfig_BASE)
#define FTMRH_FlashConfig_BASE_PTR               (FTMRH_FlashConfig)
/** Array initializer of NV peripheral base addresses */
#define NV_BASE_ADDRS                            { FTMRH_FlashConfig_BASE }
/** Array initializer of NV peripheral base pointers */
#define NV_BASE_PTRS                             { FTMRH_FlashConfig }

/* ----------------------------------------------------------------------------
   -- NV - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup NV_Register_Accessor_Macros NV - Register accessor macros
 * @{
 */


/* NV - Register instance definitions */
/* FTMRH_FlashConfig */
#define NV_BACKKEY0                              NV_BACKKEY0_REG(FTMRH_FlashConfig)
#define NV_BACKKEY1                              NV_BACKKEY1_REG(FTMRH_FlashConfig)
#define NV_BACKKEY2                              NV_BACKKEY2_REG(FTMRH_FlashConfig)
#define NV_BACKKEY3                              NV_BACKKEY3_REG(FTMRH_FlashConfig)
#define NV_BACKKEY4                              NV_BACKKEY4_REG(FTMRH_FlashConfig)
#define NV_BACKKEY5                              NV_BACKKEY5_REG(FTMRH_FlashConfig)
#define NV_BACKKEY6                              NV_BACKKEY6_REG(FTMRH_FlashConfig)
#define NV_BACKKEY7                              NV_BACKKEY7_REG(FTMRH_FlashConfig)
#define NV_EEPROT                                NV_EEPROT_REG(FTMRH_FlashConfig)
#define NV_FPROT                                 NV_FPROT_REG(FTMRH_FlashConfig)
#define NV_FSEC                                  NV_FSEC_REG(FTMRH_FlashConfig)
#define NV_FOPT                                  NV_FOPT_REG(FTMRH_FlashConfig)

/*!
 * @}
 */ /* end of group NV_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group NV_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- OSC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_Peripheral_Access_Layer OSC Peripheral Access Layer
 * @{
 */

/** OSC - Register Layout Typedef */
typedef struct {
  __IO uint8_t CR;                                 /**< OSC Control Register, offset: 0x0 */
} OSC_Type, *OSC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- OSC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_Register_Accessor_Macros OSC - Register accessor macros
 * @{
 */


/* OSC - Register accessors */
#define OSC_CR_REG(base)                         ((base)->CR)

/*!
 * @}
 */ /* end of group OSC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- OSC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_Register_Masks OSC Register Masks
 * @{
 */

/* CR Bit Fields */
#define OSC_CR_OSCINIT_MASK                      0x1u
#define OSC_CR_OSCINIT_SHIFT                     0
#define OSC_CR_HGO_MASK                          0x2u
#define OSC_CR_HGO_SHIFT                         1
#define OSC_CR_RANGE_MASK                        0x4u
#define OSC_CR_RANGE_SHIFT                       2
#define OSC_CR_OSCOS_MASK                        0x10u
#define OSC_CR_OSCOS_SHIFT                       4
#define OSC_CR_OSCSTEN_MASK                      0x20u
#define OSC_CR_OSCSTEN_SHIFT                     5
#define OSC_CR_OSCEN_MASK                        0x80u
#define OSC_CR_OSCEN_SHIFT                       7

/*!
 * @}
 */ /* end of group OSC_Register_Masks */


/* OSC - Peripheral instance base addresses */
/** Peripheral OSC base address */
#define OSC_BASE                                 (0x40065000u)
/** Peripheral OSC base pointer */
#define OSC                                      ((OSC_Type *)OSC_BASE)
#define OSC_BASE_PTR                             (OSC)
/** Array initializer of OSC peripheral base addresses */
#define OSC_BASE_ADDRS                           { OSC_BASE }
/** Array initializer of OSC peripheral base pointers */
#define OSC_BASE_PTRS                            { OSC }

/* ----------------------------------------------------------------------------
   -- OSC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup OSC_Register_Accessor_Macros OSC - Register accessor macros
 * @{
 */


/* OSC - Register instance definitions */
/* OSC */
#define OSC_CR                                   OSC_CR_REG(OSC)

/*!
 * @}
 */ /* end of group OSC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group OSC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PIT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Peripheral_Access_Layer PIT Peripheral Access Layer
 * @{
 */

/** PIT - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< PIT Module Control Register, offset: 0x0 */
       uint8_t RESERVED_0[252];
  struct {                                         /* offset: 0x100, array step: 0x10 */
    __IO uint32_t LDVAL;                             /**< Timer Load Value Register, array offset: 0x100, array step: 0x10 */
    __I  uint32_t CVAL;                              /**< Current Timer Value Register, array offset: 0x104, array step: 0x10 */
    __IO uint32_t TCTRL;                             /**< Timer Control Register, array offset: 0x108, array step: 0x10 */
    __IO uint32_t TFLG;                              /**< Timer Flag Register, array offset: 0x10C, array step: 0x10 */
  } CHANNEL[2];
} PIT_Type, *PIT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PIT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Register_Accessor_Macros PIT - Register accessor macros
 * @{
 */


/* PIT - Register accessors */
#define PIT_MCR_REG(base)                        ((base)->MCR)
#define PIT_LDVAL_REG(base,index)                ((base)->CHANNEL[index].LDVAL)
#define PIT_CVAL_REG(base,index)                 ((base)->CHANNEL[index].CVAL)
#define PIT_TCTRL_REG(base,index)                ((base)->CHANNEL[index].TCTRL)
#define PIT_TFLG_REG(base,index)                 ((base)->CHANNEL[index].TFLG)

/*!
 * @}
 */ /* end of group PIT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PIT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Register_Masks PIT Register Masks
 * @{
 */

/* MCR Bit Fields */
#define PIT_MCR_FRZ_MASK                         0x1u
#define PIT_MCR_FRZ_SHIFT                        0
#define PIT_MCR_MDIS_MASK                        0x2u
#define PIT_MCR_MDIS_SHIFT                       1
/* LDVAL Bit Fields */
#define PIT_LDVAL_TSV_MASK                       0xFFFFFFFFu
#define PIT_LDVAL_TSV_SHIFT                      0
#define PIT_LDVAL_TSV(x)                         (((uint32_t)(((uint32_t)(x))<<PIT_LDVAL_TSV_SHIFT))&PIT_LDVAL_TSV_MASK)
/* CVAL Bit Fields */
#define PIT_CVAL_TVL_MASK                        0xFFFFFFFFu
#define PIT_CVAL_TVL_SHIFT                       0
#define PIT_CVAL_TVL(x)                          (((uint32_t)(((uint32_t)(x))<<PIT_CVAL_TVL_SHIFT))&PIT_CVAL_TVL_MASK)
/* TCTRL Bit Fields */
#define PIT_TCTRL_TEN_MASK                       0x1u
#define PIT_TCTRL_TEN_SHIFT                      0
#define PIT_TCTRL_TIE_MASK                       0x2u
#define PIT_TCTRL_TIE_SHIFT                      1
#define PIT_TCTRL_CHN_MASK                       0x4u
#define PIT_TCTRL_CHN_SHIFT                      2
/* TFLG Bit Fields */
#define PIT_TFLG_TIF_MASK                        0x1u
#define PIT_TFLG_TIF_SHIFT                       0

/*!
 * @}
 */ /* end of group PIT_Register_Masks */


/* PIT - Peripheral instance base addresses */
/** Peripheral PIT base address */
#define PIT_BASE                                 (0x40037000u)
/** Peripheral PIT base pointer */
#define PIT                                      ((PIT_Type *)PIT_BASE)
#define PIT_BASE_PTR                             (PIT)
/** Array initializer of PIT peripheral base addresses */
#define PIT_BASE_ADDRS                           { PIT_BASE }
/** Array initializer of PIT peripheral base pointers */
#define PIT_BASE_PTRS                            { PIT }

/* ----------------------------------------------------------------------------
   -- PIT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PIT_Register_Accessor_Macros PIT - Register accessor macros
 * @{
 */


/* PIT - Register instance definitions */
/* PIT */
#define PIT_MCR                                  PIT_MCR_REG(PIT)
#define PIT_LDVAL0                               PIT_LDVAL_REG(PIT,0)
#define PIT_CVAL0                                PIT_CVAL_REG(PIT,0)
#define PIT_TCTRL0                               PIT_TCTRL_REG(PIT,0)
#define PIT_TFLG0                                PIT_TFLG_REG(PIT,0)
#define PIT_LDVAL1                               PIT_LDVAL_REG(PIT,1)
#define PIT_CVAL1                                PIT_CVAL_REG(PIT,1)
#define PIT_TCTRL1                               PIT_TCTRL_REG(PIT,1)
#define PIT_TFLG1                                PIT_TFLG_REG(PIT,1)

/* PIT - Register array accessors */
#define PIT_LDVAL(index)                         PIT_LDVAL_REG(PIT,index)
#define PIT_CVAL(index)                          PIT_CVAL_REG(PIT,index)
#define PIT_TCTRL(index)                         PIT_TCTRL_REG(PIT,index)
#define PIT_TFLG(index)                          PIT_TFLG_REG(PIT,index)

/*!
 * @}
 */ /* end of group PIT_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group PIT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PMC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Peripheral_Access_Layer PMC Peripheral Access Layer
 * @{
 */

/** PMC - Register Layout Typedef */
typedef struct {
  __IO uint8_t SPMSC1;                             /**< System Power Management Status and Control 1 Register, offset: 0x0 */
  __IO uint8_t SPMSC2;                             /**< System Power Management Status and Control 2 Register, offset: 0x1 */
} PMC_Type, *PMC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Accessor_Macros PMC - Register accessor macros
 * @{
 */


/* PMC - Register accessors */
#define PMC_SPMSC1_REG(base)                     ((base)->SPMSC1)
#define PMC_SPMSC2_REG(base)                     ((base)->SPMSC2)

/*!
 * @}
 */ /* end of group PMC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PMC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Masks PMC Register Masks
 * @{
 */

/* SPMSC1 Bit Fields */
#define PMC_SPMSC1_BGBE_MASK                     0x1u
#define PMC_SPMSC1_BGBE_SHIFT                    0
#define PMC_SPMSC1_LVDE_MASK                     0x4u
#define PMC_SPMSC1_LVDE_SHIFT                    2
#define PMC_SPMSC1_LVDSE_MASK                    0x8u
#define PMC_SPMSC1_LVDSE_SHIFT                   3
#define PMC_SPMSC1_LVDRE_MASK                    0x10u
#define PMC_SPMSC1_LVDRE_SHIFT                   4
#define PMC_SPMSC1_LVWIE_MASK                    0x20u
#define PMC_SPMSC1_LVWIE_SHIFT                   5
#define PMC_SPMSC1_LVWACK_MASK                   0x40u
#define PMC_SPMSC1_LVWACK_SHIFT                  6
#define PMC_SPMSC1_LVWF_MASK                     0x80u
#define PMC_SPMSC1_LVWF_SHIFT                    7
/* SPMSC2 Bit Fields */
#define PMC_SPMSC2_LVWV_MASK                     0x30u
#define PMC_SPMSC2_LVWV_SHIFT                    4
#define PMC_SPMSC2_LVWV(x)                       (((uint8_t)(((uint8_t)(x))<<PMC_SPMSC2_LVWV_SHIFT))&PMC_SPMSC2_LVWV_MASK)
#define PMC_SPMSC2_LVDV_MASK                     0x40u
#define PMC_SPMSC2_LVDV_SHIFT                    6

/*!
 * @}
 */ /* end of group PMC_Register_Masks */


/* PMC - Peripheral instance base addresses */
/** Peripheral PMC base address */
#define PMC_BASE                                 (0x4007D000u)
/** Peripheral PMC base pointer */
#define PMC                                      ((PMC_Type *)PMC_BASE)
#define PMC_BASE_PTR                             (PMC)
/** Array initializer of PMC peripheral base addresses */
#define PMC_BASE_ADDRS                           { PMC_BASE }
/** Array initializer of PMC peripheral base pointers */
#define PMC_BASE_PTRS                            { PMC }

/* ----------------------------------------------------------------------------
   -- PMC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PMC_Register_Accessor_Macros PMC - Register accessor macros
 * @{
 */


/* PMC - Register instance definitions */
/* PMC */
#define PMC_SPMSC1                               PMC_SPMSC1_REG(PMC)
#define PMC_SPMSC2                               PMC_SPMSC2_REG(PMC)

/*!
 * @}
 */ /* end of group PMC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group PMC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PORT Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Peripheral_Access_Layer PORT Peripheral Access Layer
 * @{
 */

/** PORT - Register Layout Typedef */
typedef struct {
  __IO uint32_t IOFLT;                             /**< Port Filter Register, offset: 0x0 */
  __IO uint32_t PUEL;                              /**< Port Pullup Enable Low Register, offset: 0x4 */
  __IO uint32_t PUEH;                              /**< Port Pullup Enable High Register, offset: 0x8 */
  __IO uint32_t HDRVE;                             /**< Port High Drive Enable Register, offset: 0xC */
} PORT_Type, *PORT_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- PORT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Accessor_Macros PORT - Register accessor macros
 * @{
 */


/* PORT - Register accessors */
#define PORT_IOFLT_REG(base)                     ((base)->IOFLT)
#define PORT_PUEL_REG(base)                      ((base)->PUEL)
#define PORT_PUEH_REG(base)                      ((base)->PUEH)
#define PORT_HDRVE_REG(base)                     ((base)->HDRVE)

/*!
 * @}
 */ /* end of group PORT_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- PORT Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Masks PORT Register Masks
 * @{
 */

/* IOFLT Bit Fields */
#define PORT_IOFLT_FLTA_MASK                     0x3u
#define PORT_IOFLT_FLTA_SHIFT                    0
#define PORT_IOFLT_FLTA(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTA_SHIFT))&PORT_IOFLT_FLTA_MASK)
#define PORT_IOFLT_FLTB_MASK                     0xCu
#define PORT_IOFLT_FLTB_SHIFT                    2
#define PORT_IOFLT_FLTB(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTB_SHIFT))&PORT_IOFLT_FLTB_MASK)
#define PORT_IOFLT_FLTC_MASK                     0x30u
#define PORT_IOFLT_FLTC_SHIFT                    4
#define PORT_IOFLT_FLTC(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTC_SHIFT))&PORT_IOFLT_FLTC_MASK)
#define PORT_IOFLT_FLTD_MASK                     0xC0u
#define PORT_IOFLT_FLTD_SHIFT                    6
#define PORT_IOFLT_FLTD(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTD_SHIFT))&PORT_IOFLT_FLTD_MASK)
#define PORT_IOFLT_FLTE_MASK                     0x300u
#define PORT_IOFLT_FLTE_SHIFT                    8
#define PORT_IOFLT_FLTE(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTE_SHIFT))&PORT_IOFLT_FLTE_MASK)
#define PORT_IOFLT_FLTF_MASK                     0xC00u
#define PORT_IOFLT_FLTF_SHIFT                    10
#define PORT_IOFLT_FLTF(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTF_SHIFT))&PORT_IOFLT_FLTF_MASK)
#define PORT_IOFLT_FLTG_MASK                     0x3000u
#define PORT_IOFLT_FLTG_SHIFT                    12
#define PORT_IOFLT_FLTG(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTG_SHIFT))&PORT_IOFLT_FLTG_MASK)
#define PORT_IOFLT_FLTH_MASK                     0xC000u
#define PORT_IOFLT_FLTH_SHIFT                    14
#define PORT_IOFLT_FLTH(x)                       (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTH_SHIFT))&PORT_IOFLT_FLTH_MASK)
#define PORT_IOFLT_FLTRST_MASK                   0x30000u
#define PORT_IOFLT_FLTRST_SHIFT                  16
#define PORT_IOFLT_FLTRST(x)                     (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTRST_SHIFT))&PORT_IOFLT_FLTRST_MASK)
#define PORT_IOFLT_FLTKBI0_MASK                  0xC0000u
#define PORT_IOFLT_FLTKBI0_SHIFT                 18
#define PORT_IOFLT_FLTKBI0(x)                    (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTKBI0_SHIFT))&PORT_IOFLT_FLTKBI0_MASK)
#define PORT_IOFLT_FLTKBI1_MASK                  0x300000u
#define PORT_IOFLT_FLTKBI1_SHIFT                 20
#define PORT_IOFLT_FLTKBI1(x)                    (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTKBI1_SHIFT))&PORT_IOFLT_FLTKBI1_MASK)
#define PORT_IOFLT_FLTNMI_MASK                   0xC00000u
#define PORT_IOFLT_FLTNMI_SHIFT                  22
#define PORT_IOFLT_FLTNMI(x)                     (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTNMI_SHIFT))&PORT_IOFLT_FLTNMI_MASK)
#define PORT_IOFLT_FLTDIV1_MASK                  0x3000000u
#define PORT_IOFLT_FLTDIV1_SHIFT                 24
#define PORT_IOFLT_FLTDIV1(x)                    (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTDIV1_SHIFT))&PORT_IOFLT_FLTDIV1_MASK)
#define PORT_IOFLT_FLTDIV2_MASK                  0x1C000000u
#define PORT_IOFLT_FLTDIV2_SHIFT                 26
#define PORT_IOFLT_FLTDIV2(x)                    (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTDIV2_SHIFT))&PORT_IOFLT_FLTDIV2_MASK)
#define PORT_IOFLT_FLTDIV3_MASK                  0xE0000000u
#define PORT_IOFLT_FLTDIV3_SHIFT                 29
#define PORT_IOFLT_FLTDIV3(x)                    (((uint32_t)(((uint32_t)(x))<<PORT_IOFLT_FLTDIV3_SHIFT))&PORT_IOFLT_FLTDIV3_MASK)
/* PUEL Bit Fields */
#define PORT_PUEL_PTAPE0_MASK                    0x1u
#define PORT_PUEL_PTAPE0_SHIFT                   0
#define PORT_PUEL_PTAPE1_MASK                    0x2u
#define PORT_PUEL_PTAPE1_SHIFT                   1
#define PORT_PUEL_PTAPE2_MASK                    0x4u
#define PORT_PUEL_PTAPE2_SHIFT                   2
#define PORT_PUEL_PTAPE3_MASK                    0x8u
#define PORT_PUEL_PTAPE3_SHIFT                   3
#define PORT_PUEL_PTAPE4_MASK                    0x10u
#define PORT_PUEL_PTAPE4_SHIFT                   4
#define PORT_PUEL_PTAPE5_MASK                    0x20u
#define PORT_PUEL_PTAPE5_SHIFT                   5
#define PORT_PUEL_PTAPE6_MASK                    0x40u
#define PORT_PUEL_PTAPE6_SHIFT                   6
#define PORT_PUEL_PTAPE7_MASK                    0x80u
#define PORT_PUEL_PTAPE7_SHIFT                   7
#define PORT_PUEL_PTBPE0_MASK                    0x100u
#define PORT_PUEL_PTBPE0_SHIFT                   8
#define PORT_PUEL_PTBPE1_MASK                    0x200u
#define PORT_PUEL_PTBPE1_SHIFT                   9
#define PORT_PUEL_PTBPE2_MASK                    0x400u
#define PORT_PUEL_PTBPE2_SHIFT                   10
#define PORT_PUEL_PTBPE3_MASK                    0x800u
#define PORT_PUEL_PTBPE3_SHIFT                   11
#define PORT_PUEL_PTBPE4_MASK                    0x1000u
#define PORT_PUEL_PTBPE4_SHIFT                   12
#define PORT_PUEL_PTBPE5_MASK                    0x2000u
#define PORT_PUEL_PTBPE5_SHIFT                   13
#define PORT_PUEL_PTBPE6_MASK                    0x4000u
#define PORT_PUEL_PTBPE6_SHIFT                   14
#define PORT_PUEL_PTBPE7_MASK                    0x8000u
#define PORT_PUEL_PTBPE7_SHIFT                   15
#define PORT_PUEL_PTCPE0_MASK                    0x10000u
#define PORT_PUEL_PTCPE0_SHIFT                   16
#define PORT_PUEL_PTCPE1_MASK                    0x20000u
#define PORT_PUEL_PTCPE1_SHIFT                   17
#define PORT_PUEL_PTCPE2_MASK                    0x40000u
#define PORT_PUEL_PTCPE2_SHIFT                   18
#define PORT_PUEL_PTCPE3_MASK                    0x80000u
#define PORT_PUEL_PTCPE3_SHIFT                   19
#define PORT_PUEL_PTCPE4_MASK                    0x100000u
#define PORT_PUEL_PTCPE4_SHIFT                   20
#define PORT_PUEL_PTCPE5_MASK                    0x200000u
#define PORT_PUEL_PTCPE5_SHIFT                   21
#define PORT_PUEL_PTCPE6_MASK                    0x400000u
#define PORT_PUEL_PTCPE6_SHIFT                   22
#define PORT_PUEL_PTCPE7_MASK                    0x800000u
#define PORT_PUEL_PTCPE7_SHIFT                   23
#define PORT_PUEL_PTDPE0_MASK                    0x1000000u
#define PORT_PUEL_PTDPE0_SHIFT                   24
#define PORT_PUEL_PTDPE1_MASK                    0x2000000u
#define PORT_PUEL_PTDPE1_SHIFT                   25
#define PORT_PUEL_PTDPE2_MASK                    0x4000000u
#define PORT_PUEL_PTDPE2_SHIFT                   26
#define PORT_PUEL_PTDPE3_MASK                    0x8000000u
#define PORT_PUEL_PTDPE3_SHIFT                   27
#define PORT_PUEL_PTDPE4_MASK                    0x10000000u
#define PORT_PUEL_PTDPE4_SHIFT                   28
#define PORT_PUEL_PTDPE5_MASK                    0x20000000u
#define PORT_PUEL_PTDPE5_SHIFT                   29
#define PORT_PUEL_PTDPE6_MASK                    0x40000000u
#define PORT_PUEL_PTDPE6_SHIFT                   30
#define PORT_PUEL_PTDPE7_MASK                    0x80000000u
#define PORT_PUEL_PTDPE7_SHIFT                   31
/* PUEH Bit Fields */
#define PORT_PUEH_PTEPE0_MASK                    0x1u
#define PORT_PUEH_PTEPE0_SHIFT                   0
#define PORT_PUEH_PTEPE1_MASK                    0x2u
#define PORT_PUEH_PTEPE1_SHIFT                   1
#define PORT_PUEH_PTEPE2_MASK                    0x4u
#define PORT_PUEH_PTEPE2_SHIFT                   2
#define PORT_PUEH_PTEPE3_MASK                    0x8u
#define PORT_PUEH_PTEPE3_SHIFT                   3
#define PORT_PUEH_PTEPE4_MASK                    0x10u
#define PORT_PUEH_PTEPE4_SHIFT                   4
#define PORT_PUEH_PTEPE5_MASK                    0x20u
#define PORT_PUEH_PTEPE5_SHIFT                   5
#define PORT_PUEH_PTEPE6_MASK                    0x40u
#define PORT_PUEH_PTEPE6_SHIFT                   6
#define PORT_PUEH_PTEPE7_MASK                    0x80u
#define PORT_PUEH_PTEPE7_SHIFT                   7
#define PORT_PUEH_PTFPE0_MASK                    0x100u
#define PORT_PUEH_PTFPE0_SHIFT                   8
#define PORT_PUEH_PTFPE1_MASK                    0x200u
#define PORT_PUEH_PTFPE1_SHIFT                   9
#define PORT_PUEH_PTFPE2_MASK                    0x400u
#define PORT_PUEH_PTFPE2_SHIFT                   10
#define PORT_PUEH_PTFPE3_MASK                    0x800u
#define PORT_PUEH_PTFPE3_SHIFT                   11
#define PORT_PUEH_PTFPE4_MASK                    0x1000u
#define PORT_PUEH_PTFPE4_SHIFT                   12
#define PORT_PUEH_PTFPE5_MASK                    0x2000u
#define PORT_PUEH_PTFPE5_SHIFT                   13
#define PORT_PUEH_PTFPE6_MASK                    0x4000u
#define PORT_PUEH_PTFPE6_SHIFT                   14
#define PORT_PUEH_PTFPE7_MASK                    0x8000u
#define PORT_PUEH_PTFPE7_SHIFT                   15
#define PORT_PUEH_PTGPE0_MASK                    0x10000u
#define PORT_PUEH_PTGPE0_SHIFT                   16
#define PORT_PUEH_PTGPE1_MASK                    0x20000u
#define PORT_PUEH_PTGPE1_SHIFT                   17
#define PORT_PUEH_PTGPE2_MASK                    0x40000u
#define PORT_PUEH_PTGPE2_SHIFT                   18
#define PORT_PUEH_PTGPE3_MASK                    0x80000u
#define PORT_PUEH_PTGPE3_SHIFT                   19
#define PORT_PUEH_PTHPE0_MASK                    0x1000000u
#define PORT_PUEH_PTHPE0_SHIFT                   24
#define PORT_PUEH_PTHPE1_MASK                    0x2000000u
#define PORT_PUEH_PTHPE1_SHIFT                   25
#define PORT_PUEH_PTHPE2_MASK                    0x4000000u
#define PORT_PUEH_PTHPE2_SHIFT                   26
#define PORT_PUEH_PTHPE6_MASK                    0x40000000u
#define PORT_PUEH_PTHPE6_SHIFT                   30
#define PORT_PUEH_PTHPE7_MASK                    0x80000000u
#define PORT_PUEH_PTHPE7_SHIFT                   31
/* HDRVE Bit Fields */
#define PORT_HDRVE_PTB4_MASK                     0x1u
#define PORT_HDRVE_PTB4_SHIFT                    0
#define PORT_HDRVE_PTB5_MASK                     0x2u
#define PORT_HDRVE_PTB5_SHIFT                    1
#define PORT_HDRVE_PTD0_MASK                     0x4u
#define PORT_HDRVE_PTD0_SHIFT                    2
#define PORT_HDRVE_PTD1_MASK                     0x8u
#define PORT_HDRVE_PTD1_SHIFT                    3
#define PORT_HDRVE_PTE0_MASK                     0x10u
#define PORT_HDRVE_PTE0_SHIFT                    4
#define PORT_HDRVE_PTE1_MASK                     0x20u
#define PORT_HDRVE_PTE1_SHIFT                    5
#define PORT_HDRVE_PTH0_MASK                     0x40u
#define PORT_HDRVE_PTH0_SHIFT                    6
#define PORT_HDRVE_PTH1_MASK                     0x80u
#define PORT_HDRVE_PTH1_SHIFT                    7

/*!
 * @}
 */ /* end of group PORT_Register_Masks */


/* PORT - Peripheral instance base addresses */
/** Peripheral PORT base address */
#define PORT_BASE                                (0x40049000u)
/** Peripheral PORT base pointer */
#define PORT                                     ((PORT_Type *)PORT_BASE)
#define PORT_BASE_PTR                            (PORT)
/** Array initializer of PORT peripheral base addresses */
#define PORT_BASE_ADDRS                          { PORT_BASE }
/** Array initializer of PORT peripheral base pointers */
#define PORT_BASE_PTRS                           { PORT }

/* ----------------------------------------------------------------------------
   -- PORT - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PORT_Register_Accessor_Macros PORT - Register accessor macros
 * @{
 */


/* PORT - Register instance definitions */
/* PORT */
#define PORT_IOFLT                               PORT_IOFLT_REG(PORT)
#define PORT_PUEL                                PORT_PUEL_REG(PORT)
#define PORT_PUEH                                PORT_PUEH_REG(PORT)
#define PORT_HDRVE                               PORT_HDRVE_REG(PORT)

/*!
 * @}
 */ /* end of group PORT_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group PORT_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- ROM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ROM_Peripheral_Access_Layer ROM Peripheral Access Layer
 * @{
 */

/** ROM - Register Layout Typedef */
typedef struct {
  __I  uint32_t ENTRY[1];                          /**< Entry, array offset: 0x0, array step: 0x4 */
  __I  uint32_t TABLEMARK;                         /**< End of Table Marker Register, offset: 0x4 */
       uint8_t RESERVED_0[4036];
  __I  uint32_t SYSACCESS;                         /**< System Access Register, offset: 0xFCC */
  __I  uint32_t PERIPHID4;                         /**< Peripheral ID Register, offset: 0xFD0 */
  __I  uint32_t PERIPHID5;                         /**< Peripheral ID Register, offset: 0xFD4 */
  __I  uint32_t PERIPHID6;                         /**< Peripheral ID Register, offset: 0xFD8 */
  __I  uint32_t PERIPHID7;                         /**< Peripheral ID Register, offset: 0xFDC */
  __I  uint32_t PERIPHID0;                         /**< Peripheral ID Register, offset: 0xFE0 */
  __I  uint32_t PERIPHID1;                         /**< Peripheral ID Register, offset: 0xFE4 */
  __I  uint32_t PERIPHID2;                         /**< Peripheral ID Register, offset: 0xFE8 */
  __I  uint32_t PERIPHID3;                         /**< Peripheral ID Register, offset: 0xFEC */
  __I  uint32_t COMPID[4];                         /**< Component ID Register, array offset: 0xFF0, array step: 0x4 */
} ROM_Type, *ROM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ROM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ROM_Register_Accessor_Macros ROM - Register accessor macros
 * @{
 */


/* ROM - Register accessors */
#define ROM_ENTRY_REG(base,index)                ((base)->ENTRY[index])
#define ROM_TABLEMARK_REG(base)                  ((base)->TABLEMARK)
#define ROM_SYSACCESS_REG(base)                  ((base)->SYSACCESS)
#define ROM_PERIPHID4_REG(base)                  ((base)->PERIPHID4)
#define ROM_PERIPHID5_REG(base)                  ((base)->PERIPHID5)
#define ROM_PERIPHID6_REG(base)                  ((base)->PERIPHID6)
#define ROM_PERIPHID7_REG(base)                  ((base)->PERIPHID7)
#define ROM_PERIPHID0_REG(base)                  ((base)->PERIPHID0)
#define ROM_PERIPHID1_REG(base)                  ((base)->PERIPHID1)
#define ROM_PERIPHID2_REG(base)                  ((base)->PERIPHID2)
#define ROM_PERIPHID3_REG(base)                  ((base)->PERIPHID3)
#define ROM_COMPID_REG(base,index)               ((base)->COMPID[index])

/*!
 * @}
 */ /* end of group ROM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- ROM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ROM_Register_Masks ROM Register Masks
 * @{
 */

/* ENTRY Bit Fields */
#define ROM_ENTRY_ENTRY_MASK                     0xFFFFFFFFu
#define ROM_ENTRY_ENTRY_SHIFT                    0
#define ROM_ENTRY_ENTRY(x)                       (((uint32_t)(((uint32_t)(x))<<ROM_ENTRY_ENTRY_SHIFT))&ROM_ENTRY_ENTRY_MASK)
/* TABLEMARK Bit Fields */
#define ROM_TABLEMARK_MARK_MASK                  0xFFFFFFFFu
#define ROM_TABLEMARK_MARK_SHIFT                 0
#define ROM_TABLEMARK_MARK(x)                    (((uint32_t)(((uint32_t)(x))<<ROM_TABLEMARK_MARK_SHIFT))&ROM_TABLEMARK_MARK_MASK)
/* SYSACCESS Bit Fields */
#define ROM_SYSACCESS_SYSACCESS_MASK             0xFFFFFFFFu
#define ROM_SYSACCESS_SYSACCESS_SHIFT            0
#define ROM_SYSACCESS_SYSACCESS(x)               (((uint32_t)(((uint32_t)(x))<<ROM_SYSACCESS_SYSACCESS_SHIFT))&ROM_SYSACCESS_SYSACCESS_MASK)
/* PERIPHID4 Bit Fields */
#define ROM_PERIPHID4_PERIPHID_MASK              0xFFFFFFFFu
#define ROM_PERIPHID4_PERIPHID_SHIFT             0
#define ROM_PERIPHID4_PERIPHID(x)                (((uint32_t)(((uint32_t)(x))<<ROM_PERIPHID4_PERIPHID_SHIFT))&ROM_PERIPHID4_PERIPHID_MASK)
/* PERIPHID5 Bit Fields */
#define ROM_PERIPHID5_PERIPHID_MASK              0xFFFFFFFFu
#define ROM_PERIPHID5_PERIPHID_SHIFT             0
#define ROM_PERIPHID5_PERIPHID(x)                (((uint32_t)(((uint32_t)(x))<<ROM_PERIPHID5_PERIPHID_SHIFT))&ROM_PERIPHID5_PERIPHID_MASK)
/* PERIPHID6 Bit Fields */
#define ROM_PERIPHID6_PERIPHID_MASK              0xFFFFFFFFu
#define ROM_PERIPHID6_PERIPHID_SHIFT             0
#define ROM_PERIPHID6_PERIPHID(x)                (((uint32_t)(((uint32_t)(x))<<ROM_PERIPHID6_PERIPHID_SHIFT))&ROM_PERIPHID6_PERIPHID_MASK)
/* PERIPHID7 Bit Fields */
#define ROM_PERIPHID7_PERIPHID_MASK              0xFFFFFFFFu
#define ROM_PERIPHID7_PERIPHID_SHIFT             0
#define ROM_PERIPHID7_PERIPHID(x)                (((uint32_t)(((uint32_t)(x))<<ROM_PERIPHID7_PERIPHID_SHIFT))&ROM_PERIPHID7_PERIPHID_MASK)
/* PERIPHID0 Bit Fields */
#define ROM_PERIPHID0_PERIPHID_MASK              0xFFFFFFFFu
#define ROM_PERIPHID0_PERIPHID_SHIFT             0
#define ROM_PERIPHID0_PERIPHID(x)                (((uint32_t)(((uint32_t)(x))<<ROM_PERIPHID0_PERIPHID_SHIFT))&ROM_PERIPHID0_PERIPHID_MASK)
/* PERIPHID1 Bit Fields */
#define ROM_PERIPHID1_PERIPHID_MASK              0xFFFFFFFFu
#define ROM_PERIPHID1_PERIPHID_SHIFT             0
#define ROM_PERIPHID1_PERIPHID(x)                (((uint32_t)(((uint32_t)(x))<<ROM_PERIPHID1_PERIPHID_SHIFT))&ROM_PERIPHID1_PERIPHID_MASK)
/* PERIPHID2 Bit Fields */
#define ROM_PERIPHID2_PERIPHID_MASK              0xFFFFFFFFu
#define ROM_PERIPHID2_PERIPHID_SHIFT             0
#define ROM_PERIPHID2_PERIPHID(x)                (((uint32_t)(((uint32_t)(x))<<ROM_PERIPHID2_PERIPHID_SHIFT))&ROM_PERIPHID2_PERIPHID_MASK)
/* PERIPHID3 Bit Fields */
#define ROM_PERIPHID3_PERIPHID_MASK              0xFFFFFFFFu
#define ROM_PERIPHID3_PERIPHID_SHIFT             0
#define ROM_PERIPHID3_PERIPHID(x)                (((uint32_t)(((uint32_t)(x))<<ROM_PERIPHID3_PERIPHID_SHIFT))&ROM_PERIPHID3_PERIPHID_MASK)
/* COMPID Bit Fields */
#define ROM_COMPID_COMPID_MASK                   0xFFFFFFFFu
#define ROM_COMPID_COMPID_SHIFT                  0
#define ROM_COMPID_COMPID(x)                     (((uint32_t)(((uint32_t)(x))<<ROM_COMPID_COMPID_SHIFT))&ROM_COMPID_COMPID_MASK)

/*!
 * @}
 */ /* end of group ROM_Register_Masks */


/* ROM - Peripheral instance base addresses */
/** Peripheral ROM base address */
#define ROM_BASE                                 (0xF0002000u)
/** Peripheral ROM base pointer */
#define ROM                                      ((ROM_Type *)ROM_BASE)
#define ROM_BASE_PTR                             (ROM)
/** Array initializer of ROM peripheral base addresses */
#define ROM_BASE_ADDRS                           { ROM_BASE }
/** Array initializer of ROM peripheral base pointers */
#define ROM_BASE_PTRS                            { ROM }

/* ----------------------------------------------------------------------------
   -- ROM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ROM_Register_Accessor_Macros ROM - Register accessor macros
 * @{
 */


/* ROM - Register instance definitions */
/* ROM */
#define ROM_ENTRY0                               ROM_ENTRY_REG(ROM,0)
#define ROM_TABLEMARK                            ROM_TABLEMARK_REG(ROM)
#define ROM_SYSACCESS                            ROM_SYSACCESS_REG(ROM)
#define ROM_PERIPHID4                            ROM_PERIPHID4_REG(ROM)
#define ROM_PERIPHID5                            ROM_PERIPHID5_REG(ROM)
#define ROM_PERIPHID6                            ROM_PERIPHID6_REG(ROM)
#define ROM_PERIPHID7                            ROM_PERIPHID7_REG(ROM)
#define ROM_PERIPHID0                            ROM_PERIPHID0_REG(ROM)
#define ROM_PERIPHID1                            ROM_PERIPHID1_REG(ROM)
#define ROM_PERIPHID2                            ROM_PERIPHID2_REG(ROM)
#define ROM_PERIPHID3                            ROM_PERIPHID3_REG(ROM)
#define ROM_COMPID0                              ROM_COMPID_REG(ROM,0)
#define ROM_COMPID1                              ROM_COMPID_REG(ROM,1)
#define ROM_COMPID2                              ROM_COMPID_REG(ROM,2)
#define ROM_COMPID3                              ROM_COMPID_REG(ROM,3)

/* ROM - Register array accessors */
#define ROM_ENTRY(index)                         ROM_ENTRY_REG(ROM,index)
#define ROM_COMPID(index)                        ROM_COMPID_REG(ROM,index)

/*!
 * @}
 */ /* end of group ROM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group ROM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- RTC Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Peripheral_Access_Layer RTC Peripheral Access Layer
 * @{
 */

/** RTC - Register Layout Typedef */
typedef struct {
  __IO uint32_t SC;                                /**< RTC Status and Control Register, offset: 0x0 */
  __IO uint32_t MOD;                               /**< RTC Modulo Register, offset: 0x4 */
  __I  uint32_t CNT;                               /**< RTC Counter Register, offset: 0x8 */
} RTC_Type, *RTC_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- RTC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Register_Accessor_Macros RTC - Register accessor macros
 * @{
 */


/* RTC - Register accessors */
#define RTC_SC_REG(base)                         ((base)->SC)
#define RTC_MOD_REG(base)                        ((base)->MOD)
#define RTC_CNT_REG(base)                        ((base)->CNT)

/*!
 * @}
 */ /* end of group RTC_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- RTC Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Register_Masks RTC Register Masks
 * @{
 */

/* SC Bit Fields */
#define RTC_SC_RTCO_MASK                         0x10u
#define RTC_SC_RTCO_SHIFT                        4
#define RTC_SC_RTIE_MASK                         0x40u
#define RTC_SC_RTIE_SHIFT                        6
#define RTC_SC_RTIF_MASK                         0x80u
#define RTC_SC_RTIF_SHIFT                        7
#define RTC_SC_RTCPS_MASK                        0x700u
#define RTC_SC_RTCPS_SHIFT                       8
#define RTC_SC_RTCPS(x)                          (((uint32_t)(((uint32_t)(x))<<RTC_SC_RTCPS_SHIFT))&RTC_SC_RTCPS_MASK)
#define RTC_SC_RTCLKS_MASK                       0xC000u
#define RTC_SC_RTCLKS_SHIFT                      14
#define RTC_SC_RTCLKS(x)                         (((uint32_t)(((uint32_t)(x))<<RTC_SC_RTCLKS_SHIFT))&RTC_SC_RTCLKS_MASK)
/* MOD Bit Fields */
#define RTC_MOD_MOD_MASK                         0xFFFFu
#define RTC_MOD_MOD_SHIFT                        0
#define RTC_MOD_MOD(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_MOD_MOD_SHIFT))&RTC_MOD_MOD_MASK)
/* CNT Bit Fields */
#define RTC_CNT_CNT_MASK                         0xFFFFu
#define RTC_CNT_CNT_SHIFT                        0
#define RTC_CNT_CNT(x)                           (((uint32_t)(((uint32_t)(x))<<RTC_CNT_CNT_SHIFT))&RTC_CNT_CNT_MASK)

/*!
 * @}
 */ /* end of group RTC_Register_Masks */


/* RTC - Peripheral instance base addresses */
/** Peripheral RTC base address */
#define RTC_BASE                                 (0x4003D000u)
/** Peripheral RTC base pointer */
#define RTC                                      ((RTC_Type *)RTC_BASE)
#define RTC_BASE_PTR                             (RTC)
/** Array initializer of RTC peripheral base addresses */
#define RTC_BASE_ADDRS                           { RTC_BASE }
/** Array initializer of RTC peripheral base pointers */
#define RTC_BASE_PTRS                            { RTC }

/* ----------------------------------------------------------------------------
   -- RTC - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup RTC_Register_Accessor_Macros RTC - Register accessor macros
 * @{
 */


/* RTC - Register instance definitions */
/* RTC */
#define RTC_SC                                   RTC_SC_REG(RTC)
#define RTC_MOD                                  RTC_MOD_REG(RTC)
#define RTC_CNT                                  RTC_CNT_REG(RTC)

/*!
 * @}
 */ /* end of group RTC_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group RTC_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SIM Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Peripheral_Access_Layer SIM Peripheral Access Layer
 * @{
 */

/** SIM - Register Layout Typedef */
typedef struct {
  __I  uint32_t SRSID;                             /**< System Reset Status and ID Register, offset: 0x0 */
  __IO uint32_t SOPT;                              /**< System Options Register, offset: 0x4 */
  __IO uint32_t PINSEL;                            /**< Pin Selection Register, offset: 0x8 */
  __IO uint32_t SCGC;                              /**< System Clock Gating Control Register, offset: 0xC */
  __I  uint32_t UUIDL;                             /**< Universally Unique Identifier Low Register, offset: 0x10 */
  __I  uint32_t UUIDH;                             /**< Universally Unique Identifier High Register, offset: 0x14 */
  __IO uint32_t BUSDIV;                            /**< BUS Clock Divider Register, offset: 0x18 */
} SIM_Type, *SIM_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SIM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Accessor_Macros SIM - Register accessor macros
 * @{
 */


/* SIM - Register accessors */
#define SIM_SRSID_REG(base)                      ((base)->SRSID)
#define SIM_SOPT_REG(base)                       ((base)->SOPT)
#define SIM_PINSEL_REG(base)                     ((base)->PINSEL)
#define SIM_SCGC_REG(base)                       ((base)->SCGC)
#define SIM_UUIDL_REG(base)                      ((base)->UUIDL)
#define SIM_UUIDH_REG(base)                      ((base)->UUIDH)
#define SIM_BUSDIV_REG(base)                     ((base)->BUSDIV)

/*!
 * @}
 */ /* end of group SIM_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SIM Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Masks SIM Register Masks
 * @{
 */

/* SRSID Bit Fields */
#define SIM_SRSID_LVD_MASK                       0x2u
#define SIM_SRSID_LVD_SHIFT                      1
#define SIM_SRSID_LOC_MASK                       0x4u
#define SIM_SRSID_LOC_SHIFT                      2
#define SIM_SRSID_WDOG_MASK                      0x20u
#define SIM_SRSID_WDOG_SHIFT                     5
#define SIM_SRSID_PIN_MASK                       0x40u
#define SIM_SRSID_PIN_SHIFT                      6
#define SIM_SRSID_POR_MASK                       0x80u
#define SIM_SRSID_POR_SHIFT                      7
#define SIM_SRSID_LOCKUP_MASK                    0x200u
#define SIM_SRSID_LOCKUP_SHIFT                   9
#define SIM_SRSID_SW_MASK                        0x400u
#define SIM_SRSID_SW_SHIFT                       10
#define SIM_SRSID_MDMAP_MASK                     0x800u
#define SIM_SRSID_MDMAP_SHIFT                    11
#define SIM_SRSID_SACKERR_MASK                   0x2000u
#define SIM_SRSID_SACKERR_SHIFT                  13
#define SIM_SRSID_PINID_MASK                     0xF0000u
#define SIM_SRSID_PINID_SHIFT                    16
#define SIM_SRSID_PINID(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SRSID_PINID_SHIFT))&SIM_SRSID_PINID_MASK)
#define SIM_SRSID_RevID_MASK                     0xF00000u
#define SIM_SRSID_RevID_SHIFT                    20
#define SIM_SRSID_RevID(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SRSID_RevID_SHIFT))&SIM_SRSID_RevID_MASK)
#define SIM_SRSID_SUBFAMID_MASK                  0xF000000u
#define SIM_SRSID_SUBFAMID_SHIFT                 24
#define SIM_SRSID_SUBFAMID(x)                    (((uint32_t)(((uint32_t)(x))<<SIM_SRSID_SUBFAMID_SHIFT))&SIM_SRSID_SUBFAMID_MASK)
#define SIM_SRSID_FAMID_MASK                     0xF0000000u
#define SIM_SRSID_FAMID_SHIFT                    28
#define SIM_SRSID_FAMID(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SRSID_FAMID_SHIFT))&SIM_SRSID_FAMID_MASK)
/* SOPT Bit Fields */
#define SIM_SOPT_NMIE_MASK                       0x2u
#define SIM_SOPT_NMIE_SHIFT                      1
#define SIM_SOPT_RSTPE_MASK                      0x4u
#define SIM_SOPT_RSTPE_SHIFT                     2
#define SIM_SOPT_SWDE_MASK                       0x8u
#define SIM_SOPT_SWDE_SHIFT                      3
#define SIM_SOPT_ADHWT_MASK                      0x300u
#define SIM_SOPT_ADHWT_SHIFT                     8
#define SIM_SOPT_ADHWT(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SOPT_ADHWT_SHIFT))&SIM_SOPT_ADHWT_MASK)
#define SIM_SOPT_RTCC_MASK                       0x400u
#define SIM_SOPT_RTCC_SHIFT                      10
#define SIM_SOPT_ACIC_MASK                       0x800u
#define SIM_SOPT_ACIC_SHIFT                      11
#define SIM_SOPT_RXDCE_MASK                      0x1000u
#define SIM_SOPT_RXDCE_SHIFT                     12
#define SIM_SOPT_RXDFE_MASK                      0x2000u
#define SIM_SOPT_RXDFE_SHIFT                     13
#define SIM_SOPT_FTMSYNC_MASK                    0x4000u
#define SIM_SOPT_FTMSYNC_SHIFT                   14
#define SIM_SOPT_TXDME_MASK                      0x8000u
#define SIM_SOPT_TXDME_SHIFT                     15
#define SIM_SOPT_BUSREF_MASK                     0x70000u
#define SIM_SOPT_BUSREF_SHIFT                    16
#define SIM_SOPT_BUSREF(x)                       (((uint32_t)(((uint32_t)(x))<<SIM_SOPT_BUSREF_SHIFT))&SIM_SOPT_BUSREF_MASK)
#define SIM_SOPT_CLKOE_MASK                      0x80000u
#define SIM_SOPT_CLKOE_SHIFT                     19
#define SIM_SOPT_DLYACT_MASK                     0x800000u
#define SIM_SOPT_DLYACT_SHIFT                    23
#define SIM_SOPT_DELAY_MASK                      0xFF000000u
#define SIM_SOPT_DELAY_SHIFT                     24
#define SIM_SOPT_DELAY(x)                        (((uint32_t)(((uint32_t)(x))<<SIM_SOPT_DELAY_SHIFT))&SIM_SOPT_DELAY_MASK)
/* PINSEL Bit Fields */
#define SIM_PINSEL_RTCPS_MASK                    0x10u
#define SIM_PINSEL_RTCPS_SHIFT                   4
#define SIM_PINSEL_I2C0PS_MASK                   0x20u
#define SIM_PINSEL_I2C0PS_SHIFT                  5
#define SIM_PINSEL_SPI0PS_MASK                   0x40u
#define SIM_PINSEL_SPI0PS_SHIFT                  6
#define SIM_PINSEL_UART0PS_MASK                  0x80u
#define SIM_PINSEL_UART0PS_SHIFT                 7
#define SIM_PINSEL_FTM0PS0_MASK                  0x100u
#define SIM_PINSEL_FTM0PS0_SHIFT                 8
#define SIM_PINSEL_FTM0PS1_MASK                  0x200u
#define SIM_PINSEL_FTM0PS1_SHIFT                 9
#define SIM_PINSEL_FTM1PS0_MASK                  0x400u
#define SIM_PINSEL_FTM1PS0_SHIFT                 10
#define SIM_PINSEL_FTM1PS1_MASK                  0x800u
#define SIM_PINSEL_FTM1PS1_SHIFT                 11
#define SIM_PINSEL_FTM2PS0_MASK                  0x1000u
#define SIM_PINSEL_FTM2PS0_SHIFT                 12
#define SIM_PINSEL_FTM2PS1_MASK                  0x2000u
#define SIM_PINSEL_FTM2PS1_SHIFT                 13
#define SIM_PINSEL_FTM2PS2_MASK                  0x4000u
#define SIM_PINSEL_FTM2PS2_SHIFT                 14
#define SIM_PINSEL_FTM2PS3_MASK                  0x8000u
#define SIM_PINSEL_FTM2PS3_SHIFT                 15
/* SCGC Bit Fields */
#define SIM_SCGC_RTC_MASK                        0x1u
#define SIM_SCGC_RTC_SHIFT                       0
#define SIM_SCGC_PIT_MASK                        0x2u
#define SIM_SCGC_PIT_SHIFT                       1
#define SIM_SCGC_FTM0_MASK                       0x20u
#define SIM_SCGC_FTM0_SHIFT                      5
#define SIM_SCGC_FTM1_MASK                       0x40u
#define SIM_SCGC_FTM1_SHIFT                      6
#define SIM_SCGC_FTM2_MASK                       0x80u
#define SIM_SCGC_FTM2_SHIFT                      7
#define SIM_SCGC_CRC_MASK                        0x400u
#define SIM_SCGC_CRC_SHIFT                       10
#define SIM_SCGC_FLASH_MASK                      0x1000u
#define SIM_SCGC_FLASH_SHIFT                     12
#define SIM_SCGC_SWD_MASK                        0x2000u
#define SIM_SCGC_SWD_SHIFT                       13
#define SIM_SCGC_I2C_MASK                        0x20000u
#define SIM_SCGC_I2C_SHIFT                       17
#define SIM_SCGC_SPI0_MASK                       0x40000u
#define SIM_SCGC_SPI0_SHIFT                      18
#define SIM_SCGC_SPI1_MASK                       0x80000u
#define SIM_SCGC_SPI1_SHIFT                      19
#define SIM_SCGC_UART0_MASK                      0x100000u
#define SIM_SCGC_UART0_SHIFT                     20
#define SIM_SCGC_UART1_MASK                      0x200000u
#define SIM_SCGC_UART1_SHIFT                     21
#define SIM_SCGC_UART2_MASK                      0x400000u
#define SIM_SCGC_UART2_SHIFT                     22
#define SIM_SCGC_KBI0_MASK                       0x1000000u
#define SIM_SCGC_KBI0_SHIFT                      24
#define SIM_SCGC_KBI1_MASK                       0x2000000u
#define SIM_SCGC_KBI1_SHIFT                      25
#define SIM_SCGC_IRQ_MASK                        0x8000000u
#define SIM_SCGC_IRQ_SHIFT                       27
#define SIM_SCGC_ADC_MASK                        0x20000000u
#define SIM_SCGC_ADC_SHIFT                       29
#define SIM_SCGC_ACMP0_MASK                      0x40000000u
#define SIM_SCGC_ACMP0_SHIFT                     30
#define SIM_SCGC_ACMP1_MASK                      0x80000000u
#define SIM_SCGC_ACMP1_SHIFT                     31
/* UUIDL Bit Fields */
#define SIM_UUIDL_ID_MASK                        0xFFFFFFFFu
#define SIM_UUIDL_ID_SHIFT                       0
#define SIM_UUIDL_ID(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_UUIDL_ID_SHIFT))&SIM_UUIDL_ID_MASK)
/* UUIDH Bit Fields */
#define SIM_UUIDH_ID_MASK                        0xFFFFFFFFu
#define SIM_UUIDH_ID_SHIFT                       0
#define SIM_UUIDH_ID(x)                          (((uint32_t)(((uint32_t)(x))<<SIM_UUIDH_ID_SHIFT))&SIM_UUIDH_ID_MASK)
/* BUSDIV Bit Fields */
#define SIM_BUSDIV_BUSDIV_MASK                   0x1u
#define SIM_BUSDIV_BUSDIV_SHIFT                  0

/*!
 * @}
 */ /* end of group SIM_Register_Masks */


/* SIM - Peripheral instance base addresses */
/** Peripheral SIM base address */
#define SIM_BASE                                 (0x40048000u)
/** Peripheral SIM base pointer */
#define SIM                                      ((SIM_Type *)SIM_BASE)
#define SIM_BASE_PTR                             (SIM)
/** Array initializer of SIM peripheral base addresses */
#define SIM_BASE_ADDRS                           { SIM_BASE }
/** Array initializer of SIM peripheral base pointers */
#define SIM_BASE_PTRS                            { SIM }

/* ----------------------------------------------------------------------------
   -- SIM - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SIM_Register_Accessor_Macros SIM - Register accessor macros
 * @{
 */


/* SIM - Register instance definitions */
/* SIM */
#define SIM_SRSID                                SIM_SRSID_REG(SIM)
#define SIM_SOPT                                 SIM_SOPT_REG(SIM)
#define SIM_PINSEL                               SIM_PINSEL_REG(SIM)
#define SIM_SCGC                                 SIM_SCGC_REG(SIM)
#define SIM_UUIDL                                SIM_UUIDL_REG(SIM)
#define SIM_UUIDH                                SIM_UUIDH_REG(SIM)
#define SIM_BUSDIV                               SIM_BUSDIV_REG(SIM)

/*!
 * @}
 */ /* end of group SIM_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group SIM_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- SPI Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Peripheral_Access_Layer SPI Peripheral Access Layer
 * @{
 */

/** SPI - Register Layout Typedef */
typedef struct {
  __IO uint8_t C1;                                 /**< SPI Control Register 1, offset: 0x0 */
  __IO uint8_t C2;                                 /**< SPI Control Register 2, offset: 0x1 */
  __IO uint8_t BR;                                 /**< SPI Baud Rate Register, offset: 0x2 */
  __I  uint8_t S;                                  /**< SPI Status Register, offset: 0x3 */
       uint8_t RESERVED_0[1];
  __IO uint8_t D;                                  /**< SPI Data Register, offset: 0x5 */
       uint8_t RESERVED_1[1];
  __IO uint8_t M;                                  /**< SPI Match Register, offset: 0x7 */
} SPI_Type, *SPI_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- SPI - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Register_Accessor_Macros SPI - Register accessor macros
 * @{
 */


/* SPI - Register accessors */
#define SPI_C1_REG(base)                         ((base)->C1)
#define SPI_C2_REG(base)                         ((base)->C2)
#define SPI_BR_REG(base)                         ((base)->BR)
#define SPI_S_REG(base)                          ((base)->S)
#define SPI_D_REG(base)                          ((base)->D)
#define SPI_M_REG(base)                          ((base)->M)

/*!
 * @}
 */ /* end of group SPI_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- SPI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Register_Masks SPI Register Masks
 * @{
 */

/* C1 Bit Fields */
#define SPI_C1_LSBFE_MASK                        0x1u
#define SPI_C1_LSBFE_SHIFT                       0
#define SPI_C1_SSOE_MASK                         0x2u
#define SPI_C1_SSOE_SHIFT                        1
#define SPI_C1_CPHA_MASK                         0x4u
#define SPI_C1_CPHA_SHIFT                        2
#define SPI_C1_CPOL_MASK                         0x8u
#define SPI_C1_CPOL_SHIFT                        3
#define SPI_C1_MSTR_MASK                         0x10u
#define SPI_C1_MSTR_SHIFT                        4
#define SPI_C1_SPTIE_MASK                        0x20u
#define SPI_C1_SPTIE_SHIFT                       5
#define SPI_C1_SPE_MASK                          0x40u
#define SPI_C1_SPE_SHIFT                         6
#define SPI_C1_SPIE_MASK                         0x80u
#define SPI_C1_SPIE_SHIFT                        7
/* C2 Bit Fields */
#define SPI_C2_SPC0_MASK                         0x1u
#define SPI_C2_SPC0_SHIFT                        0
#define SPI_C2_SPISWAI_MASK                      0x2u
#define SPI_C2_SPISWAI_SHIFT                     1
#define SPI_C2_BIDIROE_MASK                      0x8u
#define SPI_C2_BIDIROE_SHIFT                     3
#define SPI_C2_MODFEN_MASK                       0x10u
#define SPI_C2_MODFEN_SHIFT                      4
#define SPI_C2_SPMIE_MASK                        0x80u
#define SPI_C2_SPMIE_SHIFT                       7
/* BR Bit Fields */
#define SPI_BR_SPR_MASK                          0xFu
#define SPI_BR_SPR_SHIFT                         0
#define SPI_BR_SPR(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_BR_SPR_SHIFT))&SPI_BR_SPR_MASK)
#define SPI_BR_SPPR_MASK                         0x70u
#define SPI_BR_SPPR_SHIFT                        4
#define SPI_BR_SPPR(x)                           (((uint8_t)(((uint8_t)(x))<<SPI_BR_SPPR_SHIFT))&SPI_BR_SPPR_MASK)
/* S Bit Fields */
#define SPI_S_MODF_MASK                          0x10u
#define SPI_S_MODF_SHIFT                         4
#define SPI_S_SPTEF_MASK                         0x20u
#define SPI_S_SPTEF_SHIFT                        5
#define SPI_S_SPMF_MASK                          0x40u
#define SPI_S_SPMF_SHIFT                         6
#define SPI_S_SPRF_MASK                          0x80u
#define SPI_S_SPRF_SHIFT                         7
/* D Bit Fields */
#define SPI_D_Bits_MASK                          0xFFu
#define SPI_D_Bits_SHIFT                         0
#define SPI_D_Bits(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_D_Bits_SHIFT))&SPI_D_Bits_MASK)
/* M Bit Fields */
#define SPI_M_Bits_MASK                          0xFFu
#define SPI_M_Bits_SHIFT                         0
#define SPI_M_Bits(x)                            (((uint8_t)(((uint8_t)(x))<<SPI_M_Bits_SHIFT))&SPI_M_Bits_MASK)

/*!
 * @}
 */ /* end of group SPI_Register_Masks */


/* SPI - Peripheral instance base addresses */
/** Peripheral SPI0 base address */
#define SPI0_BASE                                (0x40076000u)
/** Peripheral SPI0 base pointer */
#define SPI0                                     ((SPI_Type *)SPI0_BASE)
#define SPI0_BASE_PTR                            (SPI0)
/** Peripheral SPI1 base address */
#define SPI1_BASE                                (0x40077000u)
/** Peripheral SPI1 base pointer */
#define SPI1                                     ((SPI_Type *)SPI1_BASE)
#define SPI1_BASE_PTR                            (SPI1)
/** Array initializer of SPI peripheral base addresses */
#define SPI_BASE_ADDRS                           { SPI0_BASE, SPI1_BASE }
/** Array initializer of SPI peripheral base pointers */
#define SPI_BASE_PTRS                            { SPI0, SPI1 }

/* ----------------------------------------------------------------------------
   -- SPI - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup SPI_Register_Accessor_Macros SPI - Register accessor macros
 * @{
 */


/* SPI - Register instance definitions */
/* SPI0 */
#define SPI0_C1                                  SPI_C1_REG(SPI0)
#define SPI0_C2                                  SPI_C2_REG(SPI0)
#define SPI0_BR                                  SPI_BR_REG(SPI0)
#define SPI0_S                                   SPI_S_REG(SPI0)
#define SPI0_D                                   SPI_D_REG(SPI0)
#define SPI0_M                                   SPI_M_REG(SPI0)
/* SPI1 */
#define SPI1_C1                                  SPI_C1_REG(SPI1)
#define SPI1_C2                                  SPI_C2_REG(SPI1)
#define SPI1_BR                                  SPI_BR_REG(SPI1)
#define SPI1_S                                   SPI_S_REG(SPI1)
#define SPI1_D                                   SPI_D_REG(SPI1)
#define SPI1_M                                   SPI_M_REG(SPI1)

/*!
 * @}
 */ /* end of group SPI_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group SPI_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- UART Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Peripheral_Access_Layer UART Peripheral Access Layer
 * @{
 */

/** UART - Register Layout Typedef */
typedef struct {
  __IO uint8_t BDH;                                /**< UART Baud Rate Register: High, offset: 0x0 */
  __IO uint8_t BDL;                                /**< UART Baud Rate Register: Low, offset: 0x1 */
  __IO uint8_t C1;                                 /**< UART Control Register 1, offset: 0x2 */
  __IO uint8_t C2;                                 /**< UART Control Register 2, offset: 0x3 */
  __I  uint8_t S1;                                 /**< UART Status Register 1, offset: 0x4 */
  __IO uint8_t S2;                                 /**< UART Status Register 2, offset: 0x5 */
  __IO uint8_t C3;                                 /**< UART Control Register 3, offset: 0x6 */
  __IO uint8_t D;                                  /**< UART Data Register, offset: 0x7 */
} UART_Type, *UART_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- UART - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Register_Accessor_Macros UART - Register accessor macros
 * @{
 */


/* UART - Register accessors */
#define UART_BDH_REG(base)                       ((base)->BDH)
#define UART_BDL_REG(base)                       ((base)->BDL)
#define UART_C1_REG(base)                        ((base)->C1)
#define UART_C2_REG(base)                        ((base)->C2)
#define UART_S1_REG(base)                        ((base)->S1)
#define UART_S2_REG(base)                        ((base)->S2)
#define UART_C3_REG(base)                        ((base)->C3)
#define UART_D_REG(base)                         ((base)->D)

/*!
 * @}
 */ /* end of group UART_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- UART Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Register_Masks UART Register Masks
 * @{
 */

/* BDH Bit Fields */
#define UART_BDH_SBR_MASK                        0x1Fu
#define UART_BDH_SBR_SHIFT                       0
#define UART_BDH_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDH_SBR_SHIFT))&UART_BDH_SBR_MASK)
#define UART_BDH_SBNS_MASK                       0x20u
#define UART_BDH_SBNS_SHIFT                      5
#define UART_BDH_RXEDGIE_MASK                    0x40u
#define UART_BDH_RXEDGIE_SHIFT                   6
#define UART_BDH_LBKDIE_MASK                     0x80u
#define UART_BDH_LBKDIE_SHIFT                    7
/* BDL Bit Fields */
#define UART_BDL_SBR_MASK                        0xFFu
#define UART_BDL_SBR_SHIFT                       0
#define UART_BDL_SBR(x)                          (((uint8_t)(((uint8_t)(x))<<UART_BDL_SBR_SHIFT))&UART_BDL_SBR_MASK)
/* C1 Bit Fields */
#define UART_C1_PT_MASK                          0x1u
#define UART_C1_PT_SHIFT                         0
#define UART_C1_PE_MASK                          0x2u
#define UART_C1_PE_SHIFT                         1
#define UART_C1_ILT_MASK                         0x4u
#define UART_C1_ILT_SHIFT                        2
#define UART_C1_WAKE_MASK                        0x8u
#define UART_C1_WAKE_SHIFT                       3
#define UART_C1_M_MASK                           0x10u
#define UART_C1_M_SHIFT                          4
#define UART_C1_RSRC_MASK                        0x20u
#define UART_C1_RSRC_SHIFT                       5
#define UART_C1_UARTSWAI_MASK                    0x40u
#define UART_C1_UARTSWAI_SHIFT                   6
#define UART_C1_LOOPS_MASK                       0x80u
#define UART_C1_LOOPS_SHIFT                      7
/* C2 Bit Fields */
#define UART_C2_SBK_MASK                         0x1u
#define UART_C2_SBK_SHIFT                        0
#define UART_C2_RWU_MASK                         0x2u
#define UART_C2_RWU_SHIFT                        1
#define UART_C2_RE_MASK                          0x4u
#define UART_C2_RE_SHIFT                         2
#define UART_C2_TE_MASK                          0x8u
#define UART_C2_TE_SHIFT                         3
#define UART_C2_ILIE_MASK                        0x10u
#define UART_C2_ILIE_SHIFT                       4
#define UART_C2_RIE_MASK                         0x20u
#define UART_C2_RIE_SHIFT                        5
#define UART_C2_TCIE_MASK                        0x40u
#define UART_C2_TCIE_SHIFT                       6
#define UART_C2_TIE_MASK                         0x80u
#define UART_C2_TIE_SHIFT                        7
/* S1 Bit Fields */
#define UART_S1_PF_MASK                          0x1u
#define UART_S1_PF_SHIFT                         0
#define UART_S1_FE_MASK                          0x2u
#define UART_S1_FE_SHIFT                         1
#define UART_S1_NF_MASK                          0x4u
#define UART_S1_NF_SHIFT                         2
#define UART_S1_OR_MASK                          0x8u
#define UART_S1_OR_SHIFT                         3
#define UART_S1_IDLE_MASK                        0x10u
#define UART_S1_IDLE_SHIFT                       4
#define UART_S1_RDRF_MASK                        0x20u
#define UART_S1_RDRF_SHIFT                       5
#define UART_S1_TC_MASK                          0x40u
#define UART_S1_TC_SHIFT                         6
#define UART_S1_TDRE_MASK                        0x80u
#define UART_S1_TDRE_SHIFT                       7
/* S2 Bit Fields */
#define UART_S2_RAF_MASK                         0x1u
#define UART_S2_RAF_SHIFT                        0
#define UART_S2_LBKDE_MASK                       0x2u
#define UART_S2_LBKDE_SHIFT                      1
#define UART_S2_BRK13_MASK                       0x4u
#define UART_S2_BRK13_SHIFT                      2
#define UART_S2_RWUID_MASK                       0x8u
#define UART_S2_RWUID_SHIFT                      3
#define UART_S2_RXINV_MASK                       0x10u
#define UART_S2_RXINV_SHIFT                      4
#define UART_S2_RXEDGIF_MASK                     0x40u
#define UART_S2_RXEDGIF_SHIFT                    6
#define UART_S2_LBKDIF_MASK                      0x80u
#define UART_S2_LBKDIF_SHIFT                     7
/* C3 Bit Fields */
#define UART_C3_PEIE_MASK                        0x1u
#define UART_C3_PEIE_SHIFT                       0
#define UART_C3_FEIE_MASK                        0x2u
#define UART_C3_FEIE_SHIFT                       1
#define UART_C3_NEIE_MASK                        0x4u
#define UART_C3_NEIE_SHIFT                       2
#define UART_C3_ORIE_MASK                        0x8u
#define UART_C3_ORIE_SHIFT                       3
#define UART_C3_TXINV_MASK                       0x10u
#define UART_C3_TXINV_SHIFT                      4
#define UART_C3_TXDIR_MASK                       0x20u
#define UART_C3_TXDIR_SHIFT                      5
#define UART_C3_T8_MASK                          0x40u
#define UART_C3_T8_SHIFT                         6
#define UART_C3_R8_MASK                          0x80u
#define UART_C3_R8_SHIFT                         7
/* D Bit Fields */
#define UART_D_R0T0_MASK                         0x1u
#define UART_D_R0T0_SHIFT                        0
#define UART_D_R1T1_MASK                         0x2u
#define UART_D_R1T1_SHIFT                        1
#define UART_D_R2T2_MASK                         0x4u
#define UART_D_R2T2_SHIFT                        2
#define UART_D_R3T3_MASK                         0x8u
#define UART_D_R3T3_SHIFT                        3
#define UART_D_R4T4_MASK                         0x10u
#define UART_D_R4T4_SHIFT                        4
#define UART_D_R5T5_MASK                         0x20u
#define UART_D_R5T5_SHIFT                        5
#define UART_D_R6T6_MASK                         0x40u
#define UART_D_R6T6_SHIFT                        6
#define UART_D_R7T7_MASK                         0x80u
#define UART_D_R7T7_SHIFT                        7

/*!
 * @}
 */ /* end of group UART_Register_Masks */


/* UART - Peripheral instance base addresses */
/** Peripheral UART0 base address */
#define UART0_BASE                               (0x4006A000u)
/** Peripheral UART0 base pointer */
#define UART0                                    ((UART_Type *)UART0_BASE)
#define UART0_BASE_PTR                           (UART0)
/** Peripheral UART1 base address */
#define UART1_BASE                               (0x4006B000u)
/** Peripheral UART1 base pointer */
#define UART1                                    ((UART_Type *)UART1_BASE)
#define UART1_BASE_PTR                           (UART1)
/** Peripheral UART2 base address */
#define UART2_BASE                               (0x4006C000u)
/** Peripheral UART2 base pointer */
#define UART2                                    ((UART_Type *)UART2_BASE)
#define UART2_BASE_PTR                           (UART2)
/** Array initializer of UART peripheral base addresses */
#define UART_BASE_ADDRS                          { UART0_BASE, UART1_BASE, UART2_BASE }
/** Array initializer of UART peripheral base pointers */
#define UART_BASE_PTRS                           { UART0, UART1, UART2 }

/* ----------------------------------------------------------------------------
   -- UART - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup UART_Register_Accessor_Macros UART - Register accessor macros
 * @{
 */


/* UART - Register instance definitions */
/* UART0 */
#define UART0_BDH                                UART_BDH_REG(UART0)
#define UART0_BDL                                UART_BDL_REG(UART0)
#define UART0_C1                                 UART_C1_REG(UART0)
#define UART0_C2                                 UART_C2_REG(UART0)
#define UART0_S1                                 UART_S1_REG(UART0)
#define UART0_S2                                 UART_S2_REG(UART0)
#define UART0_C3                                 UART_C3_REG(UART0)
#define UART0_D                                  UART_D_REG(UART0)
/* UART1 */
#define UART1_BDH                                UART_BDH_REG(UART1)
#define UART1_BDL                                UART_BDL_REG(UART1)
#define UART1_C1                                 UART_C1_REG(UART1)
#define UART1_C2                                 UART_C2_REG(UART1)
#define UART1_S1                                 UART_S1_REG(UART1)
#define UART1_S2                                 UART_S2_REG(UART1)
#define UART1_C3                                 UART_C3_REG(UART1)
#define UART1_D                                  UART_D_REG(UART1)
/* UART2 */
#define UART2_BDH                                UART_BDH_REG(UART2)
#define UART2_BDL                                UART_BDL_REG(UART2)
#define UART2_C1                                 UART_C1_REG(UART2)
#define UART2_C2                                 UART_C2_REG(UART2)
#define UART2_S1                                 UART_S1_REG(UART2)
#define UART2_S2                                 UART_S2_REG(UART2)
#define UART2_C3                                 UART_C3_REG(UART2)
#define UART2_D                                  UART_D_REG(UART2)

/*!
 * @}
 */ /* end of group UART_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group UART_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- WDOG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Peripheral_Access_Layer WDOG Peripheral Access Layer
 * @{
 */

/** WDOG - Register Layout Typedef */
typedef struct {
  __IO uint8_t CS1;                                /**< Watchdog Control and Status Register 1, offset: 0x0 */
  __IO uint8_t CS2;                                /**< Watchdog Control and Status Register 2, offset: 0x1 */
  union {                                          /* offset: 0x2 */
    __IO uint16_t CNT;                               /**< Watchdog Counter Register., offset: 0x2 */
    struct {                                         /* offset: 0x2 */
      __I  uint8_t CNTH;                               /**< Watchdog Counter Register: High, offset: 0x2 */
      __I  uint8_t CNTL;                               /**< Watchdog Counter Register: Low, offset: 0x3 */
    } CNT8B;
  };
  union {                                          /* offset: 0x4 */
    __IO uint16_t TOVAL;                             /**< Watchdog Timeout Value Register., offset: 0x4 */
    struct {                                         /* offset: 0x4 */
      __IO uint8_t TOVALH;                             /**< Watchdog Timeout Value Register: High, offset: 0x4 */
      __IO uint8_t TOVALL;                             /**< Watchdog Timeout Value Register: Low, offset: 0x5 */
    } TOVAL8B;
  };
  union {                                          /* offset: 0x6 */
    __IO uint16_t WIN;                               /**< Watchdog Window Register., offset: 0x6 */
    struct {                                         /* offset: 0x6 */
      __IO uint8_t WINH;                               /**< Watchdog Window Register: High, offset: 0x6 */
      __IO uint8_t WINL;                               /**< Watchdog Window Register: Low, offset: 0x7 */
    } WIN8B;
  };
} WDOG_Type, *WDOG_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- WDOG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Register_Accessor_Macros WDOG - Register accessor macros
 * @{
 */


/* WDOG - Register accessors */
#define WDOG_CS1_REG(base)                       ((base)->CS1)
#define WDOG_CS2_REG(base)                       ((base)->CS2)
#define WDOG_CNT_REG(base)                       ((base)->CNT)
#define WDOG_CNTH_REG(base)                      ((base)->CNT8B.CNTH)
#define WDOG_CNTL_REG(base)                      ((base)->CNT8B.CNTL)
#define WDOG_TOVAL_REG(base)                     ((base)->TOVAL)
#define WDOG_TOVALH_REG(base)                    ((base)->TOVAL8B.TOVALH)
#define WDOG_TOVALL_REG(base)                    ((base)->TOVAL8B.TOVALL)
#define WDOG_WIN_REG(base)                       ((base)->WIN)
#define WDOG_WINH_REG(base)                      ((base)->WIN8B.WINH)
#define WDOG_WINL_REG(base)                      ((base)->WIN8B.WINL)

/*!
 * @}
 */ /* end of group WDOG_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- WDOG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Register_Masks WDOG Register Masks
 * @{
 */

/* CS1 Bit Fields */
#define WDOG_CS1_STOP_MASK                       0x1u
#define WDOG_CS1_STOP_SHIFT                      0
#define WDOG_CS1_WAIT_MASK                       0x2u
#define WDOG_CS1_WAIT_SHIFT                      1
#define WDOG_CS1_DBG_MASK                        0x4u
#define WDOG_CS1_DBG_SHIFT                       2
#define WDOG_CS1_TST_MASK                        0x18u
#define WDOG_CS1_TST_SHIFT                       3
#define WDOG_CS1_TST(x)                          (((uint8_t)(((uint8_t)(x))<<WDOG_CS1_TST_SHIFT))&WDOG_CS1_TST_MASK)
#define WDOG_CS1_UPDATE_MASK                     0x20u
#define WDOG_CS1_UPDATE_SHIFT                    5
#define WDOG_CS1_INT_MASK                        0x40u
#define WDOG_CS1_INT_SHIFT                       6
#define WDOG_CS1_EN_MASK                         0x80u
#define WDOG_CS1_EN_SHIFT                        7
/* CS2 Bit Fields */
#define WDOG_CS2_CLK_MASK                        0x3u
#define WDOG_CS2_CLK_SHIFT                       0
#define WDOG_CS2_CLK(x)                          (((uint8_t)(((uint8_t)(x))<<WDOG_CS2_CLK_SHIFT))&WDOG_CS2_CLK_MASK)
#define WDOG_CS2_PRES_MASK                       0x10u
#define WDOG_CS2_PRES_SHIFT                      4
#define WDOG_CS2_FLG_MASK                        0x40u
#define WDOG_CS2_FLG_SHIFT                       6
#define WDOG_CS2_WIN_MASK                        0x80u
#define WDOG_CS2_WIN_SHIFT                       7
/* CNT Bit Fields */
#define WDOG_CNT_CNT_MASK                        0xFFFFu
#define WDOG_CNT_CNT_SHIFT                       0
#define WDOG_CNT_CNT(x)                          (((uint16_t)(((uint16_t)(x))<<WDOG_CNT_CNT_SHIFT))&WDOG_CNT_CNT_MASK)
/* CNTH Bit Fields */
#define WDOG_CNTH_CNTHIGH_MASK                   0xFFu
#define WDOG_CNTH_CNTHIGH_SHIFT                  0
#define WDOG_CNTH_CNTHIGH(x)                     (((uint8_t)(((uint8_t)(x))<<WDOG_CNTH_CNTHIGH_SHIFT))&WDOG_CNTH_CNTHIGH_MASK)
/* CNTL Bit Fields */
#define WDOG_CNTL_CNTLOW_MASK                    0xFFu
#define WDOG_CNTL_CNTLOW_SHIFT                   0
#define WDOG_CNTL_CNTLOW(x)                      (((uint8_t)(((uint8_t)(x))<<WDOG_CNTL_CNTLOW_SHIFT))&WDOG_CNTL_CNTLOW_MASK)
/* TOVAL Bit Fields */
#define WDOG_TOVAL_TOVAL_MASK                    0xFFFFu
#define WDOG_TOVAL_TOVAL_SHIFT                   0
#define WDOG_TOVAL_TOVAL(x)                      (((uint16_t)(((uint16_t)(x))<<WDOG_TOVAL_TOVAL_SHIFT))&WDOG_TOVAL_TOVAL_MASK)
/* TOVALH Bit Fields */
#define WDOG_TOVALH_TOVALHIGH_MASK               0xFFu
#define WDOG_TOVALH_TOVALHIGH_SHIFT              0
#define WDOG_TOVALH_TOVALHIGH(x)                 (((uint8_t)(((uint8_t)(x))<<WDOG_TOVALH_TOVALHIGH_SHIFT))&WDOG_TOVALH_TOVALHIGH_MASK)
/* TOVALL Bit Fields */
#define WDOG_TOVALL_TOVALLOW_MASK                0xFFu
#define WDOG_TOVALL_TOVALLOW_SHIFT               0
#define WDOG_TOVALL_TOVALLOW(x)                  (((uint8_t)(((uint8_t)(x))<<WDOG_TOVALL_TOVALLOW_SHIFT))&WDOG_TOVALL_TOVALLOW_MASK)
/* WIN Bit Fields */
#define WDOG_WIN_WIN_MASK                        0xFFFFu
#define WDOG_WIN_WIN_SHIFT                       0
#define WDOG_WIN_WIN(x)                          (((uint16_t)(((uint16_t)(x))<<WDOG_WIN_WIN_SHIFT))&WDOG_WIN_WIN_MASK)
/* WINH Bit Fields */
#define WDOG_WINH_WINHIGH_MASK                   0xFFu
#define WDOG_WINH_WINHIGH_SHIFT                  0
#define WDOG_WINH_WINHIGH(x)                     (((uint8_t)(((uint8_t)(x))<<WDOG_WINH_WINHIGH_SHIFT))&WDOG_WINH_WINHIGH_MASK)
/* WINL Bit Fields */
#define WDOG_WINL_WINLOW_MASK                    0xFFu
#define WDOG_WINL_WINLOW_SHIFT                   0
#define WDOG_WINL_WINLOW(x)                      (((uint8_t)(((uint8_t)(x))<<WDOG_WINL_WINLOW_SHIFT))&WDOG_WINL_WINLOW_MASK)

/*!
 * @}
 */ /* end of group WDOG_Register_Masks */


/* WDOG - Peripheral instance base addresses */
/** Peripheral WDOG base address */
#define WDOG_BASE                                (0x40052000u)
/** Peripheral WDOG base pointer */
#define WDOG                                     ((WDOG_Type *)WDOG_BASE)
#define WDOG_BASE_PTR                            (WDOG)
/** Array initializer of WDOG peripheral base addresses */
#define WDOG_BASE_ADDRS                          { WDOG_BASE }
/** Array initializer of WDOG peripheral base pointers */
#define WDOG_BASE_PTRS                           { WDOG }

/* ----------------------------------------------------------------------------
   -- WDOG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup WDOG_Register_Accessor_Macros WDOG - Register accessor macros
 * @{
 */


/* WDOG - Register instance definitions */
/* WDOG */
#define WDOG_CS1                                 WDOG_CS1_REG(WDOG)
#define WDOG_CS2                                 WDOG_CS2_REG(WDOG)
#define WDOG_CNT                                 WDOG_CNT_REG(WDOG)
#define WDOG_CNTH                                WDOG_CNTH_REG(WDOG)
#define WDOG_CNTL                                WDOG_CNTL_REG(WDOG)
#define WDOG_TOVAL                               WDOG_TOVAL_REG(WDOG)
#define WDOG_TOVALH                              WDOG_TOVALH_REG(WDOG)
#define WDOG_TOVALL                              WDOG_TOVALL_REG(WDOG)
#define WDOG_WIN                                 WDOG_WIN_REG(WDOG)
#define WDOG_WINH                                WDOG_WINH_REG(WDOG)
#define WDOG_WINL                                WDOG_WINL_REG(WDOG)

/*!
 * @}
 */ /* end of group WDOG_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group WDOG_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

#if defined(__ARMCC_VERSION)
  #pragma pop
#elif defined(__CWCC__)
  #pragma pop
#elif defined(__GNUC__)
  /* leave anonymous unions enabled */
#elif defined(__IAR_SYSTEMS_ICC__)
  #pragma language=default
#else
  #error Not supported compiler type
#endif

/*!
 * @}
 */ /* end of group Peripheral_access_layer */


/* ----------------------------------------------------------------------------
   -- Backward Compatibility
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Backward_Compatibility_Symbols Backward Compatibility
 * @{
 */

#define FPTA_BASE                         FGPIOA_BASE
#define FPTA                              FGPIOA
#define FPTB_BASE                         FGPIOB_BASE
#define FPTB                              FGPIOB
#define PTA_BASE                          GPIOA_BASE
#define PTA                               GPIOA
#define PTB_BASE                          GPIOB_BASE
#define FPTB                              FGPIOB
#define NV_DFPROT_DPS_MASK                NV_EEPROT_DPS_MASK
#define NV_DFPROT_DPS_SHIFT               NV_EEPROT_DPS_SHIFT
#define NV_DFPROT_DPS(x)                  NV_EEPROT_DPS(x)
#define NV_DFPROT_DPOPEN_MASK             NV_EEPROT_DPOPEN_MASK
#define NV_DFPROT_DPOPEN_SHIFT            NV_EEPROT_DPOPEN_SHIFT
#define NV_DFPROT_DPOPEN_SHIFT            NV_EEPROT_DPOPEN_SHIFT
#define PMC_SPMSC1_BGBDS_MASK             This_symbol_has_been_deprecated
#define PMC_SPMSC1_BGBDS_SHIFT            This_symbol_has_been_deprecated
#define SIM_PINSEL_IICPS_MASK             SIM_PINSEL_I2C0PS_MASK
#define SIM_PINSEL_IICPS_SHIFT            SIM_PINSEL_I2C0PS_SHIFT
#define SIM_SCGC_IIC_MASK                 SIM_SCGC_I2C_MASK
#define SIM_SCGC_IIC_SHIFT                SIM_SCGC_I2C_SHIFT
#define ACMP_BASES                        ACMP_BASE_PTRS
#define ADC_BASES                         ADC_BASE_PTRS
#define CRC_BASES                         CRC_BASE_PTRS
#define FGPIO_BASES                       FGPIO_BASE_PTRS
#define FTM_BASES                         FTM_BASE_PTRS
#define FTMRH_BASES                       FTMRH_BASE_PTRS
#define GPIO_BASES                        GPIO_BASE_PTRS
#define I2C_BASES                         I2C_BASE_PTRS
#define ICS_BASES                         ICS_BASE_PTRS
#define IRQ_BASES                         IRQ_BASE_PTRS
#define KBI_BASES                         KBI_BASE_PTRS
#define MCM_BASES                         MCM_BASE_PTRS
#define NV_BASES                          NV_BASE_PTRS
#define OSC_BASES                         OSC_BASE_PTRS
#define PIT_BASES                         PIT_BASE_PTRS
#define PMC_BASES                         PMC_BASE_PTRS
#define PORT_BASES                        PORT_BASE_PTRS
#define ROM_BASES                         ROM_BASE_PTRS
#define RTC_BASES                         RTC_BASE_PTRS
#define SIM_BASES                         SIM_BASE_PTRS
#define SPI_BASES                         SPI_BASE_PTRS
#define UART_BASES                        UART_BASE_PTRS
#define WDOG_BASES                        WDOG_BASE_PTRS

/*!
 * @}
 */ /* end of group Backward_Compatibility_Symbols */

//////////////// Added @ Alex //////////////////////////////////////////

/* RSER Bit Fields */
#define SPI_RSER_RFDF_DIRS_MASK                  0x10000u
#define SPI_RSER_RFDF_DIRS_SHIFT                 16
#define SPI_RSER_RFDF_DIRS_WIDTH                 1
#define SPI_RSER_RFDF_DIRS(x)                    (((uint32_t)(((uint32_t)(x))<<SPI_RSER_RFDF_DIRS_SHIFT))&SPI_RSER_RFDF_DIRS_MASK)
#define SPI_RSER_RFDF_RE_MASK                    0x20000u
#define SPI_RSER_RFDF_RE_SHIFT                   17
#define SPI_RSER_RFDF_RE_WIDTH                   1
#define SPI_RSER_RFDF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RSER_RFDF_RE_SHIFT))&SPI_RSER_RFDF_RE_MASK)
#define SPI_RSER_RFOF_RE_MASK                    0x80000u
#define SPI_RSER_RFOF_RE_SHIFT                   19
#define SPI_RSER_RFOF_RE_WIDTH                   1
#define SPI_RSER_RFOF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RSER_RFOF_RE_SHIFT))&SPI_RSER_RFOF_RE_MASK)
#define SPI_RSER_TFFF_DIRS_MASK                  0x1000000u
#define SPI_RSER_TFFF_DIRS_SHIFT                 24
#define SPI_RSER_TFFF_DIRS_WIDTH                 1
#define SPI_RSER_TFFF_DIRS(x)                    (((uint32_t)(((uint32_t)(x))<<SPI_RSER_TFFF_DIRS_SHIFT))&SPI_RSER_TFFF_DIRS_MASK)
#define SPI_RSER_TFFF_RE_MASK                    0x2000000u
#define SPI_RSER_TFFF_RE_SHIFT                   25
#define SPI_RSER_TFFF_RE_WIDTH                   1
#define SPI_RSER_TFFF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RSER_TFFF_RE_SHIFT))&SPI_RSER_TFFF_RE_MASK)
#define SPI_RSER_TFUF_RE_MASK                    0x8000000u
#define SPI_RSER_TFUF_RE_SHIFT                   27
#define SPI_RSER_TFUF_RE_WIDTH                   1
#define SPI_RSER_TFUF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RSER_TFUF_RE_SHIFT))&SPI_RSER_TFUF_RE_MASK)
#define SPI_RSER_EOQF_RE_MASK                    0x10000000u
#define SPI_RSER_EOQF_RE_SHIFT                   28
#define SPI_RSER_EOQF_RE_WIDTH                   1
#define SPI_RSER_EOQF_RE(x)                      (((uint32_t)(((uint32_t)(x))<<SPI_RSER_EOQF_RE_SHIFT))&SPI_RSER_EOQF_RE_MASK)
#define SPI_RSER_TCF_RE_MASK                     0x80000000u
#define SPI_RSER_TCF_RE_SHIFT                    31
#define SPI_RSER_TCF_RE_WIDTH                    1
#define SPI_RSER_TCF_RE(x)                       (((uint32_t)(((uint32_t)(x))<<SPI_RSER_TCF_RE_SHIFT))&SPI_RSER_TCF_RE_MASK)

/* ----------------------------------------------------------------------------
   -- USB Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USB_Peripheral_Access_Layer USB Peripheral Access Layer
 * @{
 */

/** USB - Register Layout Typedef */
typedef struct {
  __I  uint8_t PERID;                              /**< Peripheral ID register, offset: 0x0 */
       uint8_t RESERVED_0[3];
  __I  uint8_t IDCOMP;                             /**< Peripheral ID Complement register, offset: 0x4 */
       uint8_t RESERVED_1[3];
  __I  uint8_t REV;                                /**< Peripheral Revision register, offset: 0x8 */
       uint8_t RESERVED_2[3];
  __I  uint8_t ADDINFO;                            /**< Peripheral Additional Info register, offset: 0xC */
       uint8_t RESERVED_3[3];
  __IO uint8_t OTGISTAT;                           /**< OTG Interrupt Status register, offset: 0x10 */
       uint8_t RESERVED_4[3];
  __IO uint8_t OTGICR;                             /**< OTG Interrupt Control register, offset: 0x14 */
       uint8_t RESERVED_5[3];
  __IO uint8_t OTGSTAT;                            /**< OTG Status register, offset: 0x18 */
       uint8_t RESERVED_6[3];
  __IO uint8_t OTGCTL;                             /**< OTG Control register, offset: 0x1C */
       uint8_t RESERVED_7[99];
  __IO uint8_t ISTAT;                              /**< Interrupt Status register, offset: 0x80 */
       uint8_t RESERVED_8[3];
  __IO uint8_t INTEN;                              /**< Interrupt Enable register, offset: 0x84 */
       uint8_t RESERVED_9[3];
  __IO uint8_t ERRSTAT;                            /**< Error Interrupt Status register, offset: 0x88 */
       uint8_t RESERVED_10[3];
  __IO uint8_t ERREN;                              /**< Error Interrupt Enable register, offset: 0x8C */
       uint8_t RESERVED_11[3];
  __I  uint8_t STAT;                               /**< Status register, offset: 0x90 */
       uint8_t RESERVED_12[3];
  __IO uint8_t CTL;                                /**< Control register, offset: 0x94 */
       uint8_t RESERVED_13[3];
  __IO uint8_t ADDR;                               /**< Address register, offset: 0x98 */
       uint8_t RESERVED_14[3];
  __IO uint8_t BDTPAGE1;                           /**< BDT Page register 1, offset: 0x9C */
       uint8_t RESERVED_15[3];
  __IO uint8_t FRMNUML;                            /**< Frame Number register Low, offset: 0xA0 */
       uint8_t RESERVED_16[3];
  __IO uint8_t FRMNUMH;                            /**< Frame Number register High, offset: 0xA4 */
       uint8_t RESERVED_17[3];
  __IO uint8_t TOKEN;                              /**< Token register, offset: 0xA8 */
       uint8_t RESERVED_18[3];
  __IO uint8_t SOFTHLD;                            /**< SOF Threshold register, offset: 0xAC */
       uint8_t RESERVED_19[3];
  __IO uint8_t BDTPAGE2;                           /**< BDT Page Register 2, offset: 0xB0 */
       uint8_t RESERVED_20[3];
  __IO uint8_t BDTPAGE3;                           /**< BDT Page Register 3, offset: 0xB4 */
       uint8_t RESERVED_21[11];
  struct {                                         /* offset: 0xC0, array step: 0x4 */
    __IO uint8_t ENDPT;                              /**< Endpoint Control register, array offset: 0xC0, array step: 0x4 */
         uint8_t RESERVED_0[3];
  } ENDPOINT[16];
  __IO uint8_t USBCTRL;                            /**< USB Control register, offset: 0x100 */
       uint8_t RESERVED_22[3];
  __I  uint8_t OBSERVE;                            /**< USB OTG Observe register, offset: 0x104 */
       uint8_t RESERVED_23[3];
  __IO uint8_t CONTROL;                            /**< USB OTG Control register, offset: 0x108 */
       uint8_t RESERVED_24[3];
  __IO uint8_t USBTRC0;                            /**< USB Transceiver Control register 0, offset: 0x10C */
       uint8_t RESERVED_25[7];
  __IO uint8_t USBFRMADJUST;                       /**< Frame Adjust Register, offset: 0x114 */
       uint8_t RESERVED_26[23];
  __IO uint8_t MISCCTRL;                           /**< Miscellaneous Control register, offset: 0x12C */
       uint8_t RESERVED_27[19];
  __IO uint8_t CLK_RECOVER_CTRL;                   /**< USB Clock recovery control, offset: 0x140 */
       uint8_t RESERVED_28[3];
  __IO uint8_t CLK_RECOVER_IRC_EN;                 /**< IRC48M oscillator enable register, offset: 0x144 */
       uint8_t RESERVED_29[15];
  __IO uint8_t CLK_RECOVER_INT_EN;                 /**< Clock recovery combined interrupt enable, offset: 0x154 */
       uint8_t RESERVED_30[7];
  __IO uint8_t CLK_RECOVER_INT_STATUS;             /**< Clock recovery separated interrupt status, offset: 0x15C */
} USB_Type, *USB_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- USB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USB_Register_Accessor_Macros USB - Register accessor macros
 * @{
 */


/* USB - Register accessors */
#define USB_PERID_REG(base)                      ((base)->PERID)
#define USB_IDCOMP_REG(base)                     ((base)->IDCOMP)
#define USB_REV_REG(base)                        ((base)->REV)
#define USB_ADDINFO_REG(base)                    ((base)->ADDINFO)
#define USB_OTGISTAT_REG(base)                   ((base)->OTGISTAT)
#define USB_OTGICR_REG(base)                     ((base)->OTGICR)
#define USB_OTGSTAT_REG(base)                    ((base)->OTGSTAT)
#define USB_OTGCTL_REG(base)                     ((base)->OTGCTL)
#define USB_ISTAT_REG(base)                      ((base)->ISTAT)
#define USB_INTEN_REG(base)                      ((base)->INTEN)
#define USB_ERRSTAT_REG(base)                    ((base)->ERRSTAT)
#define USB_ERREN_REG(base)                      ((base)->ERREN)
#define USB_STAT_REG(base)                       ((base)->STAT)
#define USB_CTL_REG(base)                        ((base)->CTL)
#define USB_ADDR_REG(base)                       ((base)->ADDR)
#define USB_BDTPAGE1_REG(base)                   ((base)->BDTPAGE1)
#define USB_FRMNUML_REG(base)                    ((base)->FRMNUML)
#define USB_FRMNUMH_REG(base)                    ((base)->FRMNUMH)
#define USB_TOKEN_REG(base)                      ((base)->TOKEN)
#define USB_SOFTHLD_REG(base)                    ((base)->SOFTHLD)
#define USB_BDTPAGE2_REG(base)                   ((base)->BDTPAGE2)
#define USB_BDTPAGE3_REG(base)                   ((base)->BDTPAGE3)
#define USB_ENDPT_REG(base,index)                ((base)->ENDPOINT[index].ENDPT)
#define USB_ENDPT_COUNT                          16
#define USB_USBCTRL_REG(base)                    ((base)->USBCTRL)
#define USB_OBSERVE_REG(base)                    ((base)->OBSERVE)
#define USB_CONTROL_REG(base)                    ((base)->CONTROL)
#define USB_USBTRC0_REG(base)                    ((base)->USBTRC0)
#define USB_USBFRMADJUST_REG(base)               ((base)->USBFRMADJUST)
#define USB_MISCCTRL_REG(base)                   ((base)->MISCCTRL)
#define USB_CLK_RECOVER_CTRL_REG(base)           ((base)->CLK_RECOVER_CTRL)
#define USB_CLK_RECOVER_IRC_EN_REG(base)         ((base)->CLK_RECOVER_IRC_EN)
#define USB_CLK_RECOVER_INT_EN_REG(base)         ((base)->CLK_RECOVER_INT_EN)
#define USB_CLK_RECOVER_INT_STATUS_REG(base)     ((base)->CLK_RECOVER_INT_STATUS)

/*!
 * @}
 */ /* end of group USB_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- USB Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USB_Register_Masks USB Register Masks
 * @{
 */

/* PERID Bit Fields */
#define USB_PERID_ID_MASK                        0x3Fu
#define USB_PERID_ID_SHIFT                       0
#define USB_PERID_ID_WIDTH                       6
#define USB_PERID_ID(x)                          (((uint8_t)(((uint8_t)(x))<<USB_PERID_ID_SHIFT))&USB_PERID_ID_MASK)
/* IDCOMP Bit Fields */
#define USB_IDCOMP_NID_MASK                      0x3Fu
#define USB_IDCOMP_NID_SHIFT                     0
#define USB_IDCOMP_NID_WIDTH                     6
#define USB_IDCOMP_NID(x)                        (((uint8_t)(((uint8_t)(x))<<USB_IDCOMP_NID_SHIFT))&USB_IDCOMP_NID_MASK)
/* REV Bit Fields */
#define USB_REV_REV_MASK                         0xFFu
#define USB_REV_REV_SHIFT                        0
#define USB_REV_REV_WIDTH                        8
#define USB_REV_REV(x)                           (((uint8_t)(((uint8_t)(x))<<USB_REV_REV_SHIFT))&USB_REV_REV_MASK)
/* ADDINFO Bit Fields */
#define USB_ADDINFO_IEHOST_MASK                  0x1u
#define USB_ADDINFO_IEHOST_SHIFT                 0
#define USB_ADDINFO_IEHOST_WIDTH                 1
#define USB_ADDINFO_IEHOST(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ADDINFO_IEHOST_SHIFT))&USB_ADDINFO_IEHOST_MASK)
/* OTGISTAT Bit Fields */
#define USB_OTGISTAT_AVBUSCHG_MASK               0x1u
#define USB_OTGISTAT_AVBUSCHG_SHIFT              0
#define USB_OTGISTAT_AVBUSCHG_WIDTH              1
#define USB_OTGISTAT_AVBUSCHG(x)                 (((uint8_t)(((uint8_t)(x))<<USB_OTGISTAT_AVBUSCHG_SHIFT))&USB_OTGISTAT_AVBUSCHG_MASK)
#define USB_OTGISTAT_B_SESS_CHG_MASK             0x4u
#define USB_OTGISTAT_B_SESS_CHG_SHIFT            2
#define USB_OTGISTAT_B_SESS_CHG_WIDTH            1
#define USB_OTGISTAT_B_SESS_CHG(x)               (((uint8_t)(((uint8_t)(x))<<USB_OTGISTAT_B_SESS_CHG_SHIFT))&USB_OTGISTAT_B_SESS_CHG_MASK)
#define USB_OTGISTAT_SESSVLDCHG_MASK             0x8u
#define USB_OTGISTAT_SESSVLDCHG_SHIFT            3
#define USB_OTGISTAT_SESSVLDCHG_WIDTH            1
#define USB_OTGISTAT_SESSVLDCHG(x)               (((uint8_t)(((uint8_t)(x))<<USB_OTGISTAT_SESSVLDCHG_SHIFT))&USB_OTGISTAT_SESSVLDCHG_MASK)
#define USB_OTGISTAT_LINE_STATE_CHG_MASK         0x20u
#define USB_OTGISTAT_LINE_STATE_CHG_SHIFT        5
#define USB_OTGISTAT_LINE_STATE_CHG_WIDTH        1
#define USB_OTGISTAT_LINE_STATE_CHG(x)           (((uint8_t)(((uint8_t)(x))<<USB_OTGISTAT_LINE_STATE_CHG_SHIFT))&USB_OTGISTAT_LINE_STATE_CHG_MASK)
#define USB_OTGISTAT_ONEMSEC_MASK                0x40u
#define USB_OTGISTAT_ONEMSEC_SHIFT               6
#define USB_OTGISTAT_ONEMSEC_WIDTH               1
#define USB_OTGISTAT_ONEMSEC(x)                  (((uint8_t)(((uint8_t)(x))<<USB_OTGISTAT_ONEMSEC_SHIFT))&USB_OTGISTAT_ONEMSEC_MASK)
#define USB_OTGISTAT_IDCHG_MASK                  0x80u
#define USB_OTGISTAT_IDCHG_SHIFT                 7
#define USB_OTGISTAT_IDCHG_WIDTH                 1
#define USB_OTGISTAT_IDCHG(x)                    (((uint8_t)(((uint8_t)(x))<<USB_OTGISTAT_IDCHG_SHIFT))&USB_OTGISTAT_IDCHG_MASK)
/* OTGICR Bit Fields */
#define USB_OTGICR_AVBUSEN_MASK                  0x1u
#define USB_OTGICR_AVBUSEN_SHIFT                 0
#define USB_OTGICR_AVBUSEN_WIDTH                 1
#define USB_OTGICR_AVBUSEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_OTGICR_AVBUSEN_SHIFT))&USB_OTGICR_AVBUSEN_MASK)
#define USB_OTGICR_BSESSEN_MASK                  0x4u
#define USB_OTGICR_BSESSEN_SHIFT                 2
#define USB_OTGICR_BSESSEN_WIDTH                 1
#define USB_OTGICR_BSESSEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_OTGICR_BSESSEN_SHIFT))&USB_OTGICR_BSESSEN_MASK)
#define USB_OTGICR_SESSVLDEN_MASK                0x8u
#define USB_OTGICR_SESSVLDEN_SHIFT               3
#define USB_OTGICR_SESSVLDEN_WIDTH               1
#define USB_OTGICR_SESSVLDEN(x)                  (((uint8_t)(((uint8_t)(x))<<USB_OTGICR_SESSVLDEN_SHIFT))&USB_OTGICR_SESSVLDEN_MASK)
#define USB_OTGICR_LINESTATEEN_MASK              0x20u
#define USB_OTGICR_LINESTATEEN_SHIFT             5
#define USB_OTGICR_LINESTATEEN_WIDTH             1
#define USB_OTGICR_LINESTATEEN(x)                (((uint8_t)(((uint8_t)(x))<<USB_OTGICR_LINESTATEEN_SHIFT))&USB_OTGICR_LINESTATEEN_MASK)
#define USB_OTGICR_ONEMSECEN_MASK                0x40u
#define USB_OTGICR_ONEMSECEN_SHIFT               6
#define USB_OTGICR_ONEMSECEN_WIDTH               1
#define USB_OTGICR_ONEMSECEN(x)                  (((uint8_t)(((uint8_t)(x))<<USB_OTGICR_ONEMSECEN_SHIFT))&USB_OTGICR_ONEMSECEN_MASK)
#define USB_OTGICR_IDEN_MASK                     0x80u
#define USB_OTGICR_IDEN_SHIFT                    7
#define USB_OTGICR_IDEN_WIDTH                    1
#define USB_OTGICR_IDEN(x)                       (((uint8_t)(((uint8_t)(x))<<USB_OTGICR_IDEN_SHIFT))&USB_OTGICR_IDEN_MASK)
/* OTGSTAT Bit Fields */
#define USB_OTGSTAT_AVBUSVLD_MASK                0x1u
#define USB_OTGSTAT_AVBUSVLD_SHIFT               0
#define USB_OTGSTAT_AVBUSVLD_WIDTH               1
#define USB_OTGSTAT_AVBUSVLD(x)                  (((uint8_t)(((uint8_t)(x))<<USB_OTGSTAT_AVBUSVLD_SHIFT))&USB_OTGSTAT_AVBUSVLD_MASK)
#define USB_OTGSTAT_BSESSEND_MASK                0x4u
#define USB_OTGSTAT_BSESSEND_SHIFT               2
#define USB_OTGSTAT_BSESSEND_WIDTH               1
#define USB_OTGSTAT_BSESSEND(x)                  (((uint8_t)(((uint8_t)(x))<<USB_OTGSTAT_BSESSEND_SHIFT))&USB_OTGSTAT_BSESSEND_MASK)
#define USB_OTGSTAT_SESS_VLD_MASK                0x8u
#define USB_OTGSTAT_SESS_VLD_SHIFT               3
#define USB_OTGSTAT_SESS_VLD_WIDTH               1
#define USB_OTGSTAT_SESS_VLD(x)                  (((uint8_t)(((uint8_t)(x))<<USB_OTGSTAT_SESS_VLD_SHIFT))&USB_OTGSTAT_SESS_VLD_MASK)
#define USB_OTGSTAT_LINESTATESTABLE_MASK         0x20u
#define USB_OTGSTAT_LINESTATESTABLE_SHIFT        5
#define USB_OTGSTAT_LINESTATESTABLE_WIDTH        1
#define USB_OTGSTAT_LINESTATESTABLE(x)           (((uint8_t)(((uint8_t)(x))<<USB_OTGSTAT_LINESTATESTABLE_SHIFT))&USB_OTGSTAT_LINESTATESTABLE_MASK)
#define USB_OTGSTAT_ONEMSECEN_MASK               0x40u
#define USB_OTGSTAT_ONEMSECEN_SHIFT              6
#define USB_OTGSTAT_ONEMSECEN_WIDTH              1
#define USB_OTGSTAT_ONEMSECEN(x)                 (((uint8_t)(((uint8_t)(x))<<USB_OTGSTAT_ONEMSECEN_SHIFT))&USB_OTGSTAT_ONEMSECEN_MASK)
#define USB_OTGSTAT_ID_MASK                      0x80u
#define USB_OTGSTAT_ID_SHIFT                     7
#define USB_OTGSTAT_ID_WIDTH                     1
#define USB_OTGSTAT_ID(x)                        (((uint8_t)(((uint8_t)(x))<<USB_OTGSTAT_ID_SHIFT))&USB_OTGSTAT_ID_MASK)
/* OTGCTL Bit Fields */
#define USB_OTGCTL_OTGEN_MASK                    0x4u
#define USB_OTGCTL_OTGEN_SHIFT                   2
#define USB_OTGCTL_OTGEN_WIDTH                   1
#define USB_OTGCTL_OTGEN(x)                      (((uint8_t)(((uint8_t)(x))<<USB_OTGCTL_OTGEN_SHIFT))&USB_OTGCTL_OTGEN_MASK)
#define USB_OTGCTL_DMLOW_MASK                    0x10u
#define USB_OTGCTL_DMLOW_SHIFT                   4
#define USB_OTGCTL_DMLOW_WIDTH                   1
#define USB_OTGCTL_DMLOW(x)                      (((uint8_t)(((uint8_t)(x))<<USB_OTGCTL_DMLOW_SHIFT))&USB_OTGCTL_DMLOW_MASK)
#define USB_OTGCTL_DPLOW_MASK                    0x20u
#define USB_OTGCTL_DPLOW_SHIFT                   5
#define USB_OTGCTL_DPLOW_WIDTH                   1
#define USB_OTGCTL_DPLOW(x)                      (((uint8_t)(((uint8_t)(x))<<USB_OTGCTL_DPLOW_SHIFT))&USB_OTGCTL_DPLOW_MASK)
#define USB_OTGCTL_DPHIGH_MASK                   0x80u
#define USB_OTGCTL_DPHIGH_SHIFT                  7
#define USB_OTGCTL_DPHIGH_WIDTH                  1
#define USB_OTGCTL_DPHIGH(x)                     (((uint8_t)(((uint8_t)(x))<<USB_OTGCTL_DPHIGH_SHIFT))&USB_OTGCTL_DPHIGH_MASK)
/* ISTAT Bit Fields */
#define USB_ISTAT_USBRST_MASK                    0x1u
#define USB_ISTAT_USBRST_SHIFT                   0
#define USB_ISTAT_USBRST_WIDTH                   1
#define USB_ISTAT_USBRST(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_USBRST_SHIFT))&USB_ISTAT_USBRST_MASK)
#define USB_ISTAT_ERROR_MASK                     0x2u
#define USB_ISTAT_ERROR_SHIFT                    1
#define USB_ISTAT_ERROR_WIDTH                    1
#define USB_ISTAT_ERROR(x)                       (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_ERROR_SHIFT))&USB_ISTAT_ERROR_MASK)
#define USB_ISTAT_SOFTOK_MASK                    0x4u
#define USB_ISTAT_SOFTOK_SHIFT                   2
#define USB_ISTAT_SOFTOK_WIDTH                   1
#define USB_ISTAT_SOFTOK(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_SOFTOK_SHIFT))&USB_ISTAT_SOFTOK_MASK)
#define USB_ISTAT_TOKDNE_MASK                    0x8u
#define USB_ISTAT_TOKDNE_SHIFT                   3
#define USB_ISTAT_TOKDNE_WIDTH                   1
#define USB_ISTAT_TOKDNE(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_TOKDNE_SHIFT))&USB_ISTAT_TOKDNE_MASK)
#define USB_ISTAT_SLEEP_MASK                     0x10u
#define USB_ISTAT_SLEEP_SHIFT                    4
#define USB_ISTAT_SLEEP_WIDTH                    1
#define USB_ISTAT_SLEEP(x)                       (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_SLEEP_SHIFT))&USB_ISTAT_SLEEP_MASK)
#define USB_ISTAT_RESUME_MASK                    0x20u
#define USB_ISTAT_RESUME_SHIFT                   5
#define USB_ISTAT_RESUME_WIDTH                   1
#define USB_ISTAT_RESUME(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_RESUME_SHIFT))&USB_ISTAT_RESUME_MASK)
#define USB_ISTAT_ATTACH_MASK                    0x40u
#define USB_ISTAT_ATTACH_SHIFT                   6
#define USB_ISTAT_ATTACH_WIDTH                   1
#define USB_ISTAT_ATTACH(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_ATTACH_SHIFT))&USB_ISTAT_ATTACH_MASK)
#define USB_ISTAT_STALL_MASK                     0x80u
#define USB_ISTAT_STALL_SHIFT                    7
#define USB_ISTAT_STALL_WIDTH                    1
#define USB_ISTAT_STALL(x)                       (((uint8_t)(((uint8_t)(x))<<USB_ISTAT_STALL_SHIFT))&USB_ISTAT_STALL_MASK)
/* INTEN Bit Fields */
#define USB_INTEN_USBRSTEN_MASK                  0x1u
#define USB_INTEN_USBRSTEN_SHIFT                 0
#define USB_INTEN_USBRSTEN_WIDTH                 1
#define USB_INTEN_USBRSTEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_INTEN_USBRSTEN_SHIFT))&USB_INTEN_USBRSTEN_MASK)
#define USB_INTEN_ERROREN_MASK                   0x2u
#define USB_INTEN_ERROREN_SHIFT                  1
#define USB_INTEN_ERROREN_WIDTH                  1
#define USB_INTEN_ERROREN(x)                     (((uint8_t)(((uint8_t)(x))<<USB_INTEN_ERROREN_SHIFT))&USB_INTEN_ERROREN_MASK)
#define USB_INTEN_SOFTOKEN_MASK                  0x4u
#define USB_INTEN_SOFTOKEN_SHIFT                 2
#define USB_INTEN_SOFTOKEN_WIDTH                 1
#define USB_INTEN_SOFTOKEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_INTEN_SOFTOKEN_SHIFT))&USB_INTEN_SOFTOKEN_MASK)
#define USB_INTEN_TOKDNEEN_MASK                  0x8u
#define USB_INTEN_TOKDNEEN_SHIFT                 3
#define USB_INTEN_TOKDNEEN_WIDTH                 1
#define USB_INTEN_TOKDNEEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_INTEN_TOKDNEEN_SHIFT))&USB_INTEN_TOKDNEEN_MASK)
#define USB_INTEN_SLEEPEN_MASK                   0x10u
#define USB_INTEN_SLEEPEN_SHIFT                  4
#define USB_INTEN_SLEEPEN_WIDTH                  1
#define USB_INTEN_SLEEPEN(x)                     (((uint8_t)(((uint8_t)(x))<<USB_INTEN_SLEEPEN_SHIFT))&USB_INTEN_SLEEPEN_MASK)
#define USB_INTEN_RESUMEEN_MASK                  0x20u
#define USB_INTEN_RESUMEEN_SHIFT                 5
#define USB_INTEN_RESUMEEN_WIDTH                 1
#define USB_INTEN_RESUMEEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_INTEN_RESUMEEN_SHIFT))&USB_INTEN_RESUMEEN_MASK)
#define USB_INTEN_ATTACHEN_MASK                  0x40u
#define USB_INTEN_ATTACHEN_SHIFT                 6
#define USB_INTEN_ATTACHEN_WIDTH                 1
#define USB_INTEN_ATTACHEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_INTEN_ATTACHEN_SHIFT))&USB_INTEN_ATTACHEN_MASK)
#define USB_INTEN_STALLEN_MASK                   0x80u
#define USB_INTEN_STALLEN_SHIFT                  7
#define USB_INTEN_STALLEN_WIDTH                  1
#define USB_INTEN_STALLEN(x)                     (((uint8_t)(((uint8_t)(x))<<USB_INTEN_STALLEN_SHIFT))&USB_INTEN_STALLEN_MASK)
/* ERRSTAT Bit Fields */
#define USB_ERRSTAT_PIDERR_MASK                  0x1u
#define USB_ERRSTAT_PIDERR_SHIFT                 0
#define USB_ERRSTAT_PIDERR_WIDTH                 1
#define USB_ERRSTAT_PIDERR(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_PIDERR_SHIFT))&USB_ERRSTAT_PIDERR_MASK)
#define USB_ERRSTAT_CRC5EOF_MASK                 0x2u
#define USB_ERRSTAT_CRC5EOF_SHIFT                1
#define USB_ERRSTAT_CRC5EOF_WIDTH                1
#define USB_ERRSTAT_CRC5EOF(x)                   (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_CRC5EOF_SHIFT))&USB_ERRSTAT_CRC5EOF_MASK)
#define USB_ERRSTAT_CRC16_MASK                   0x4u
#define USB_ERRSTAT_CRC16_SHIFT                  2
#define USB_ERRSTAT_CRC16_WIDTH                  1
#define USB_ERRSTAT_CRC16(x)                     (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_CRC16_SHIFT))&USB_ERRSTAT_CRC16_MASK)
#define USB_ERRSTAT_DFN8_MASK                    0x8u
#define USB_ERRSTAT_DFN8_SHIFT                   3
#define USB_ERRSTAT_DFN8_WIDTH                   1
#define USB_ERRSTAT_DFN8(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_DFN8_SHIFT))&USB_ERRSTAT_DFN8_MASK)
#define USB_ERRSTAT_BTOERR_MASK                  0x10u
#define USB_ERRSTAT_BTOERR_SHIFT                 4
#define USB_ERRSTAT_BTOERR_WIDTH                 1
#define USB_ERRSTAT_BTOERR(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_BTOERR_SHIFT))&USB_ERRSTAT_BTOERR_MASK)
#define USB_ERRSTAT_DMAERR_MASK                  0x20u
#define USB_ERRSTAT_DMAERR_SHIFT                 5
#define USB_ERRSTAT_DMAERR_WIDTH                 1
#define USB_ERRSTAT_DMAERR(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_DMAERR_SHIFT))&USB_ERRSTAT_DMAERR_MASK)
#define USB_ERRSTAT_OWNERR_MASK                  0x40u
#define USB_ERRSTAT_OWNERR_SHIFT                 6
#define USB_ERRSTAT_OWNERR_WIDTH                 1
#define USB_ERRSTAT_OWNERR(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_OWNERR_SHIFT))&USB_ERRSTAT_OWNERR_MASK)
#define USB_ERRSTAT_BTSERR_MASK                  0x80u
#define USB_ERRSTAT_BTSERR_SHIFT                 7
#define USB_ERRSTAT_BTSERR_WIDTH                 1
#define USB_ERRSTAT_BTSERR(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERRSTAT_BTSERR_SHIFT))&USB_ERRSTAT_BTSERR_MASK)
/* ERREN Bit Fields */
#define USB_ERREN_PIDERREN_MASK                  0x1u
#define USB_ERREN_PIDERREN_SHIFT                 0
#define USB_ERREN_PIDERREN_WIDTH                 1
#define USB_ERREN_PIDERREN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERREN_PIDERREN_SHIFT))&USB_ERREN_PIDERREN_MASK)
#define USB_ERREN_CRC5EOFEN_MASK                 0x2u
#define USB_ERREN_CRC5EOFEN_SHIFT                1
#define USB_ERREN_CRC5EOFEN_WIDTH                1
#define USB_ERREN_CRC5EOFEN(x)                   (((uint8_t)(((uint8_t)(x))<<USB_ERREN_CRC5EOFEN_SHIFT))&USB_ERREN_CRC5EOFEN_MASK)
#define USB_ERREN_CRC16EN_MASK                   0x4u
#define USB_ERREN_CRC16EN_SHIFT                  2
#define USB_ERREN_CRC16EN_WIDTH                  1
#define USB_ERREN_CRC16EN(x)                     (((uint8_t)(((uint8_t)(x))<<USB_ERREN_CRC16EN_SHIFT))&USB_ERREN_CRC16EN_MASK)
#define USB_ERREN_DFN8EN_MASK                    0x8u
#define USB_ERREN_DFN8EN_SHIFT                   3
#define USB_ERREN_DFN8EN_WIDTH                   1
#define USB_ERREN_DFN8EN(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ERREN_DFN8EN_SHIFT))&USB_ERREN_DFN8EN_MASK)
#define USB_ERREN_BTOERREN_MASK                  0x10u
#define USB_ERREN_BTOERREN_SHIFT                 4
#define USB_ERREN_BTOERREN_WIDTH                 1
#define USB_ERREN_BTOERREN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERREN_BTOERREN_SHIFT))&USB_ERREN_BTOERREN_MASK)
#define USB_ERREN_DMAERREN_MASK                  0x20u
#define USB_ERREN_DMAERREN_SHIFT                 5
#define USB_ERREN_DMAERREN_WIDTH                 1
#define USB_ERREN_DMAERREN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERREN_DMAERREN_SHIFT))&USB_ERREN_DMAERREN_MASK)
#define USB_ERREN_OWNERREN_MASK                  0x40u
#define USB_ERREN_OWNERREN_SHIFT                 6
#define USB_ERREN_OWNERREN_WIDTH                 1
#define USB_ERREN_OWNERREN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERREN_OWNERREN_SHIFT))&USB_ERREN_OWNERREN_MASK)
#define USB_ERREN_BTSERREN_MASK                  0x80u
#define USB_ERREN_BTSERREN_SHIFT                 7
#define USB_ERREN_BTSERREN_WIDTH                 1
#define USB_ERREN_BTSERREN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ERREN_BTSERREN_SHIFT))&USB_ERREN_BTSERREN_MASK)
/* STAT Bit Fields */
#define USB_STAT_ODD_MASK                        0x4u
#define USB_STAT_ODD_SHIFT                       2
#define USB_STAT_ODD_WIDTH                       1
#define USB_STAT_ODD(x)                          (((uint8_t)(((uint8_t)(x))<<USB_STAT_ODD_SHIFT))&USB_STAT_ODD_MASK)
#define USB_STAT_TX_MASK                         0x8u
#define USB_STAT_TX_SHIFT                        3
#define USB_STAT_TX_WIDTH                        1
#define USB_STAT_TX(x)                           (((uint8_t)(((uint8_t)(x))<<USB_STAT_TX_SHIFT))&USB_STAT_TX_MASK)
#define USB_STAT_ENDP_MASK                       0xF0u
#define USB_STAT_ENDP_SHIFT                      4
#define USB_STAT_ENDP_WIDTH                      4
#define USB_STAT_ENDP(x)                         (((uint8_t)(((uint8_t)(x))<<USB_STAT_ENDP_SHIFT))&USB_STAT_ENDP_MASK)
/* CTL Bit Fields */
#define USB_CTL_USBENSOFEN_MASK                  0x1u
#define USB_CTL_USBENSOFEN_SHIFT                 0
#define USB_CTL_USBENSOFEN_WIDTH                 1
#define USB_CTL_USBENSOFEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_CTL_USBENSOFEN_SHIFT))&USB_CTL_USBENSOFEN_MASK)
#define USB_CTL_ODDRST_MASK                      0x2u
#define USB_CTL_ODDRST_SHIFT                     1
#define USB_CTL_ODDRST_WIDTH                     1
#define USB_CTL_ODDRST(x)                        (((uint8_t)(((uint8_t)(x))<<USB_CTL_ODDRST_SHIFT))&USB_CTL_ODDRST_MASK)
#define USB_CTL_RESUME_MASK                      0x4u
#define USB_CTL_RESUME_SHIFT                     2
#define USB_CTL_RESUME_WIDTH                     1
#define USB_CTL_RESUME(x)                        (((uint8_t)(((uint8_t)(x))<<USB_CTL_RESUME_SHIFT))&USB_CTL_RESUME_MASK)
#define USB_CTL_HOSTMODEEN_MASK                  0x8u
#define USB_CTL_HOSTMODEEN_SHIFT                 3
#define USB_CTL_HOSTMODEEN_WIDTH                 1
#define USB_CTL_HOSTMODEEN(x)                    (((uint8_t)(((uint8_t)(x))<<USB_CTL_HOSTMODEEN_SHIFT))&USB_CTL_HOSTMODEEN_MASK)
#define USB_CTL_RESET_MASK                       0x10u
#define USB_CTL_RESET_SHIFT                      4
#define USB_CTL_RESET_WIDTH                      1
#define USB_CTL_RESET(x)                         (((uint8_t)(((uint8_t)(x))<<USB_CTL_RESET_SHIFT))&USB_CTL_RESET_MASK)
#define USB_CTL_TXSUSPENDTOKENBUSY_MASK          0x20u
#define USB_CTL_TXSUSPENDTOKENBUSY_SHIFT         5
#define USB_CTL_TXSUSPENDTOKENBUSY_WIDTH         1
#define USB_CTL_TXSUSPENDTOKENBUSY(x)            (((uint8_t)(((uint8_t)(x))<<USB_CTL_TXSUSPENDTOKENBUSY_SHIFT))&USB_CTL_TXSUSPENDTOKENBUSY_MASK)
#define USB_CTL_SE0_MASK                         0x40u
#define USB_CTL_SE0_SHIFT                        6
#define USB_CTL_SE0_WIDTH                        1
#define USB_CTL_SE0(x)                           (((uint8_t)(((uint8_t)(x))<<USB_CTL_SE0_SHIFT))&USB_CTL_SE0_MASK)
#define USB_CTL_JSTATE_MASK                      0x80u
#define USB_CTL_JSTATE_SHIFT                     7
#define USB_CTL_JSTATE_WIDTH                     1
#define USB_CTL_JSTATE(x)                        (((uint8_t)(((uint8_t)(x))<<USB_CTL_JSTATE_SHIFT))&USB_CTL_JSTATE_MASK)
/* ADDR Bit Fields */
#define USB_ADDR_ADDR_MASK                       0x7Fu
#define USB_ADDR_ADDR_SHIFT                      0
#define USB_ADDR_ADDR_WIDTH                      7
#define USB_ADDR_ADDR(x)                         (((uint8_t)(((uint8_t)(x))<<USB_ADDR_ADDR_SHIFT))&USB_ADDR_ADDR_MASK)
#define USB_ADDR_LSEN_MASK                       0x80u
#define USB_ADDR_LSEN_SHIFT                      7
#define USB_ADDR_LSEN_WIDTH                      1
#define USB_ADDR_LSEN(x)                         (((uint8_t)(((uint8_t)(x))<<USB_ADDR_LSEN_SHIFT))&USB_ADDR_LSEN_MASK)
/* BDTPAGE1 Bit Fields */
#define USB_BDTPAGE1_BDTBA_MASK                  0xFEu
#define USB_BDTPAGE1_BDTBA_SHIFT                 1
#define USB_BDTPAGE1_BDTBA_WIDTH                 7
#define USB_BDTPAGE1_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE1_BDTBA_SHIFT))&USB_BDTPAGE1_BDTBA_MASK)
/* FRMNUML Bit Fields */
#define USB_FRMNUML_FRM_MASK                     0xFFu
#define USB_FRMNUML_FRM_SHIFT                    0
#define USB_FRMNUML_FRM_WIDTH                    8
#define USB_FRMNUML_FRM(x)                       (((uint8_t)(((uint8_t)(x))<<USB_FRMNUML_FRM_SHIFT))&USB_FRMNUML_FRM_MASK)
/* FRMNUMH Bit Fields */
#define USB_FRMNUMH_FRM_MASK                     0x7u
#define USB_FRMNUMH_FRM_SHIFT                    0
#define USB_FRMNUMH_FRM_WIDTH                    3
#define USB_FRMNUMH_FRM(x)                       (((uint8_t)(((uint8_t)(x))<<USB_FRMNUMH_FRM_SHIFT))&USB_FRMNUMH_FRM_MASK)
/* TOKEN Bit Fields */
#define USB_TOKEN_TOKENENDPT_MASK                0xFu
#define USB_TOKEN_TOKENENDPT_SHIFT               0
#define USB_TOKEN_TOKENENDPT_WIDTH               4
#define USB_TOKEN_TOKENENDPT(x)                  (((uint8_t)(((uint8_t)(x))<<USB_TOKEN_TOKENENDPT_SHIFT))&USB_TOKEN_TOKENENDPT_MASK)
#define USB_TOKEN_TOKENPID_MASK                  0xF0u
#define USB_TOKEN_TOKENPID_SHIFT                 4
#define USB_TOKEN_TOKENPID_WIDTH                 4
#define USB_TOKEN_TOKENPID(x)                    (((uint8_t)(((uint8_t)(x))<<USB_TOKEN_TOKENPID_SHIFT))&USB_TOKEN_TOKENPID_MASK)
/* SOFTHLD Bit Fields */
#define USB_SOFTHLD_CNT_MASK                     0xFFu
#define USB_SOFTHLD_CNT_SHIFT                    0
#define USB_SOFTHLD_CNT_WIDTH                    8
#define USB_SOFTHLD_CNT(x)                       (((uint8_t)(((uint8_t)(x))<<USB_SOFTHLD_CNT_SHIFT))&USB_SOFTHLD_CNT_MASK)
/* BDTPAGE2 Bit Fields */
#define USB_BDTPAGE2_BDTBA_MASK                  0xFFu
#define USB_BDTPAGE2_BDTBA_SHIFT                 0
#define USB_BDTPAGE2_BDTBA_WIDTH                 8
#define USB_BDTPAGE2_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE2_BDTBA_SHIFT))&USB_BDTPAGE2_BDTBA_MASK)
/* BDTPAGE3 Bit Fields */
#define USB_BDTPAGE3_BDTBA_MASK                  0xFFu
#define USB_BDTPAGE3_BDTBA_SHIFT                 0
#define USB_BDTPAGE3_BDTBA_WIDTH                 8
#define USB_BDTPAGE3_BDTBA(x)                    (((uint8_t)(((uint8_t)(x))<<USB_BDTPAGE3_BDTBA_SHIFT))&USB_BDTPAGE3_BDTBA_MASK)
/* ENDPT Bit Fields */
#define USB_ENDPT_EPHSHK_MASK                    0x1u
#define USB_ENDPT_EPHSHK_SHIFT                   0
#define USB_ENDPT_EPHSHK_WIDTH                   1
#define USB_ENDPT_EPHSHK(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_EPHSHK_SHIFT))&USB_ENDPT_EPHSHK_MASK)
#define USB_ENDPT_EPSTALL_MASK                   0x2u
#define USB_ENDPT_EPSTALL_SHIFT                  1
#define USB_ENDPT_EPSTALL_WIDTH                  1
#define USB_ENDPT_EPSTALL(x)                     (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_EPSTALL_SHIFT))&USB_ENDPT_EPSTALL_MASK)
#define USB_ENDPT_EPTXEN_MASK                    0x4u
#define USB_ENDPT_EPTXEN_SHIFT                   2
#define USB_ENDPT_EPTXEN_WIDTH                   1
#define USB_ENDPT_EPTXEN(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_EPTXEN_SHIFT))&USB_ENDPT_EPTXEN_MASK)
#define USB_ENDPT_EPRXEN_MASK                    0x8u
#define USB_ENDPT_EPRXEN_SHIFT                   3
#define USB_ENDPT_EPRXEN_WIDTH                   1
#define USB_ENDPT_EPRXEN(x)                      (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_EPRXEN_SHIFT))&USB_ENDPT_EPRXEN_MASK)
#define USB_ENDPT_EPCTLDIS_MASK                  0x10u
#define USB_ENDPT_EPCTLDIS_SHIFT                 4
#define USB_ENDPT_EPCTLDIS_WIDTH                 1
#define USB_ENDPT_EPCTLDIS(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_EPCTLDIS_SHIFT))&USB_ENDPT_EPCTLDIS_MASK)
#define USB_ENDPT_RETRYDIS_MASK                  0x40u
#define USB_ENDPT_RETRYDIS_SHIFT                 6
#define USB_ENDPT_RETRYDIS_WIDTH                 1
#define USB_ENDPT_RETRYDIS(x)                    (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_RETRYDIS_SHIFT))&USB_ENDPT_RETRYDIS_MASK)
#define USB_ENDPT_HOSTWOHUB_MASK                 0x80u
#define USB_ENDPT_HOSTWOHUB_SHIFT                7
#define USB_ENDPT_HOSTWOHUB_WIDTH                1
#define USB_ENDPT_HOSTWOHUB(x)                   (((uint8_t)(((uint8_t)(x))<<USB_ENDPT_HOSTWOHUB_SHIFT))&USB_ENDPT_HOSTWOHUB_MASK)
/* USBCTRL Bit Fields */
#define USB_USBCTRL_UARTSEL_MASK                 0x10u
#define USB_USBCTRL_UARTSEL_SHIFT                4
#define USB_USBCTRL_UARTSEL_WIDTH                1
#define USB_USBCTRL_UARTSEL(x)                   (((uint8_t)(((uint8_t)(x))<<USB_USBCTRL_UARTSEL_SHIFT))&USB_USBCTRL_UARTSEL_MASK)
#define USB_USBCTRL_UARTCHLS_MASK                0x20u
#define USB_USBCTRL_UARTCHLS_SHIFT               5
#define USB_USBCTRL_UARTCHLS_WIDTH               1
#define USB_USBCTRL_UARTCHLS(x)                  (((uint8_t)(((uint8_t)(x))<<USB_USBCTRL_UARTCHLS_SHIFT))&USB_USBCTRL_UARTCHLS_MASK)
#define USB_USBCTRL_PDE_MASK                     0x40u
#define USB_USBCTRL_PDE_SHIFT                    6
#define USB_USBCTRL_PDE_WIDTH                    1
#define USB_USBCTRL_PDE(x)                       (((uint8_t)(((uint8_t)(x))<<USB_USBCTRL_PDE_SHIFT))&USB_USBCTRL_PDE_MASK)
#define USB_USBCTRL_SUSP_MASK                    0x80u
#define USB_USBCTRL_SUSP_SHIFT                   7
#define USB_USBCTRL_SUSP_WIDTH                   1
#define USB_USBCTRL_SUSP(x)                      (((uint8_t)(((uint8_t)(x))<<USB_USBCTRL_SUSP_SHIFT))&USB_USBCTRL_SUSP_MASK)
/* OBSERVE Bit Fields */
#define USB_OBSERVE_DMPD_MASK                    0x10u
#define USB_OBSERVE_DMPD_SHIFT                   4
#define USB_OBSERVE_DMPD_WIDTH                   1
#define USB_OBSERVE_DMPD(x)                      (((uint8_t)(((uint8_t)(x))<<USB_OBSERVE_DMPD_SHIFT))&USB_OBSERVE_DMPD_MASK)
#define USB_OBSERVE_DPPD_MASK                    0x40u
#define USB_OBSERVE_DPPD_SHIFT                   6
#define USB_OBSERVE_DPPD_WIDTH                   1
#define USB_OBSERVE_DPPD(x)                      (((uint8_t)(((uint8_t)(x))<<USB_OBSERVE_DPPD_SHIFT))&USB_OBSERVE_DPPD_MASK)
#define USB_OBSERVE_DPPU_MASK                    0x80u
#define USB_OBSERVE_DPPU_SHIFT                   7
#define USB_OBSERVE_DPPU_WIDTH                   1
#define USB_OBSERVE_DPPU(x)                      (((uint8_t)(((uint8_t)(x))<<USB_OBSERVE_DPPU_SHIFT))&USB_OBSERVE_DPPU_MASK)
/* CONTROL Bit Fields */
#define USB_CONTROL_DPPULLUPNONOTG_MASK          0x10u
#define USB_CONTROL_DPPULLUPNONOTG_SHIFT         4
#define USB_CONTROL_DPPULLUPNONOTG_WIDTH         1
#define USB_CONTROL_DPPULLUPNONOTG(x)            (((uint8_t)(((uint8_t)(x))<<USB_CONTROL_DPPULLUPNONOTG_SHIFT))&USB_CONTROL_DPPULLUPNONOTG_MASK)
/* USBTRC0 Bit Fields */
#define USB_USBTRC0_USB_RESUME_INT_MASK          0x1u
#define USB_USBTRC0_USB_RESUME_INT_SHIFT         0
#define USB_USBTRC0_USB_RESUME_INT_WIDTH         1
#define USB_USBTRC0_USB_RESUME_INT(x)            (((uint8_t)(((uint8_t)(x))<<USB_USBTRC0_USB_RESUME_INT_SHIFT))&USB_USBTRC0_USB_RESUME_INT_MASK)
#define USB_USBTRC0_SYNC_DET_MASK                0x2u
#define USB_USBTRC0_SYNC_DET_SHIFT               1
#define USB_USBTRC0_SYNC_DET_WIDTH               1
#define USB_USBTRC0_SYNC_DET(x)                  (((uint8_t)(((uint8_t)(x))<<USB_USBTRC0_SYNC_DET_SHIFT))&USB_USBTRC0_SYNC_DET_MASK)
#define USB_USBTRC0_USB_CLK_RECOVERY_INT_MASK    0x4u
#define USB_USBTRC0_USB_CLK_RECOVERY_INT_SHIFT   2
#define USB_USBTRC0_USB_CLK_RECOVERY_INT_WIDTH   1
#define USB_USBTRC0_USB_CLK_RECOVERY_INT(x)      (((uint8_t)(((uint8_t)(x))<<USB_USBTRC0_USB_CLK_RECOVERY_INT_SHIFT))&USB_USBTRC0_USB_CLK_RECOVERY_INT_MASK)
#define USB_USBTRC0_VREDG_DET_MASK               0x8u
#define USB_USBTRC0_VREDG_DET_SHIFT              3
#define USB_USBTRC0_VREDG_DET_WIDTH              1
#define USB_USBTRC0_VREDG_DET(x)                 (((uint8_t)(((uint8_t)(x))<<USB_USBTRC0_VREDG_DET_SHIFT))&USB_USBTRC0_VREDG_DET_MASK)
#define USB_USBTRC0_VFEDG_DET_MASK               0x10u
#define USB_USBTRC0_VFEDG_DET_SHIFT              4
#define USB_USBTRC0_VFEDG_DET_WIDTH              1
#define USB_USBTRC0_VFEDG_DET(x)                 (((uint8_t)(((uint8_t)(x))<<USB_USBTRC0_VFEDG_DET_SHIFT))&USB_USBTRC0_VFEDG_DET_MASK)
#define USB_USBTRC0_USBRESMEN_MASK               0x20u
#define USB_USBTRC0_USBRESMEN_SHIFT              5
#define USB_USBTRC0_USBRESMEN_WIDTH              1
#define USB_USBTRC0_USBRESMEN(x)                 (((uint8_t)(((uint8_t)(x))<<USB_USBTRC0_USBRESMEN_SHIFT))&USB_USBTRC0_USBRESMEN_MASK)
#define USB_USBTRC0_USBRESET_MASK                0x80u
#define USB_USBTRC0_USBRESET_SHIFT               7
#define USB_USBTRC0_USBRESET_WIDTH               1
#define USB_USBTRC0_USBRESET(x)                  (((uint8_t)(((uint8_t)(x))<<USB_USBTRC0_USBRESET_SHIFT))&USB_USBTRC0_USBRESET_MASK)
/* USBFRMADJUST Bit Fields */
#define USB_USBFRMADJUST_ADJ_MASK                0xFFu
#define USB_USBFRMADJUST_ADJ_SHIFT               0
#define USB_USBFRMADJUST_ADJ_WIDTH               8
#define USB_USBFRMADJUST_ADJ(x)                  (((uint8_t)(((uint8_t)(x))<<USB_USBFRMADJUST_ADJ_SHIFT))&USB_USBFRMADJUST_ADJ_MASK)
/* MISCCTRL Bit Fields */
#define USB_MISCCTRL_SOFDYNTHLD_MASK             0x1u
#define USB_MISCCTRL_SOFDYNTHLD_SHIFT            0
#define USB_MISCCTRL_SOFDYNTHLD_WIDTH            1
#define USB_MISCCTRL_SOFDYNTHLD(x)               (((uint8_t)(((uint8_t)(x))<<USB_MISCCTRL_SOFDYNTHLD_SHIFT))&USB_MISCCTRL_SOFDYNTHLD_MASK)
#define USB_MISCCTRL_SOFBUSSET_MASK              0x2u
#define USB_MISCCTRL_SOFBUSSET_SHIFT             1
#define USB_MISCCTRL_SOFBUSSET_WIDTH             1
#define USB_MISCCTRL_SOFBUSSET(x)                (((uint8_t)(((uint8_t)(x))<<USB_MISCCTRL_SOFBUSSET_SHIFT))&USB_MISCCTRL_SOFBUSSET_MASK)
#define USB_MISCCTRL_OWNERRISODIS_MASK           0x4u
#define USB_MISCCTRL_OWNERRISODIS_SHIFT          2
#define USB_MISCCTRL_OWNERRISODIS_WIDTH          1
#define USB_MISCCTRL_OWNERRISODIS(x)             (((uint8_t)(((uint8_t)(x))<<USB_MISCCTRL_OWNERRISODIS_SHIFT))&USB_MISCCTRL_OWNERRISODIS_MASK)
#define USB_MISCCTRL_VREDG_EN_MASK               0x8u
#define USB_MISCCTRL_VREDG_EN_SHIFT              3
#define USB_MISCCTRL_VREDG_EN_WIDTH              1
#define USB_MISCCTRL_VREDG_EN(x)                 (((uint8_t)(((uint8_t)(x))<<USB_MISCCTRL_VREDG_EN_SHIFT))&USB_MISCCTRL_VREDG_EN_MASK)
#define USB_MISCCTRL_VFEDG_EN_MASK               0x10u
#define USB_MISCCTRL_VFEDG_EN_SHIFT              4
#define USB_MISCCTRL_VFEDG_EN_WIDTH              1
#define USB_MISCCTRL_VFEDG_EN(x)                 (((uint8_t)(((uint8_t)(x))<<USB_MISCCTRL_VFEDG_EN_SHIFT))&USB_MISCCTRL_VFEDG_EN_MASK)
#define USB_MISCCTRL_STL_ADJ_EN_MASK             0x80u
#define USB_MISCCTRL_STL_ADJ_EN_SHIFT            7
#define USB_MISCCTRL_STL_ADJ_EN_WIDTH            1
#define USB_MISCCTRL_STL_ADJ_EN(x)               (((uint8_t)(((uint8_t)(x))<<USB_MISCCTRL_STL_ADJ_EN_SHIFT))&USB_MISCCTRL_STL_ADJ_EN_MASK)
/* CLK_RECOVER_CTRL Bit Fields */
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_MASK 0x20u
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_SHIFT 5
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_WIDTH 1
#define USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN(x) (((uint8_t)(((uint8_t)(x))<<USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_SHIFT))&USB_CLK_RECOVER_CTRL_RESTART_IFRTRIM_EN_MASK)
#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_MASK 0x40u
#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_SHIFT 6
#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_WIDTH 1
#define USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN(x) (((uint8_t)(((uint8_t)(x))<<USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_SHIFT))&USB_CLK_RECOVER_CTRL_RESET_RESUME_ROUGH_EN_MASK)
#define USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_MASK 0x80u
#define USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_SHIFT 7
#define USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_WIDTH 1
#define USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN(x) (((uint8_t)(((uint8_t)(x))<<USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_SHIFT))&USB_CLK_RECOVER_CTRL_CLOCK_RECOVER_EN_MASK)
/* CLK_RECOVER_IRC_EN Bit Fields */
#define USB_CLK_RECOVER_IRC_EN_REG_EN_MASK       0x1u
#define USB_CLK_RECOVER_IRC_EN_REG_EN_SHIFT      0
#define USB_CLK_RECOVER_IRC_EN_REG_EN_WIDTH      1
#define USB_CLK_RECOVER_IRC_EN_REG_EN(x)         (((uint8_t)(((uint8_t)(x))<<USB_CLK_RECOVER_IRC_EN_REG_EN_SHIFT))&USB_CLK_RECOVER_IRC_EN_REG_EN_MASK)
#define USB_CLK_RECOVER_IRC_EN_IRC_EN_MASK       0x2u
#define USB_CLK_RECOVER_IRC_EN_IRC_EN_SHIFT      1
#define USB_CLK_RECOVER_IRC_EN_IRC_EN_WIDTH      1
#define USB_CLK_RECOVER_IRC_EN_IRC_EN(x)         (((uint8_t)(((uint8_t)(x))<<USB_CLK_RECOVER_IRC_EN_IRC_EN_SHIFT))&USB_CLK_RECOVER_IRC_EN_IRC_EN_MASK)
/* CLK_RECOVER_INT_EN Bit Fields */
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_MASK 0x10u
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_SHIFT 4
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_WIDTH 1
#define USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN(x)   (((uint8_t)(((uint8_t)(x))<<USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_SHIFT))&USB_CLK_RECOVER_INT_EN_OVF_ERROR_EN_MASK)
/* CLK_RECOVER_INT_STATUS Bit Fields */
#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_MASK 0x10u
#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_SHIFT 4
#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_WIDTH 1
#define USB_CLK_RECOVER_INT_STATUS_OVF_ERROR(x)  (((uint8_t)(((uint8_t)(x))<<USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_SHIFT))&USB_CLK_RECOVER_INT_STATUS_OVF_ERROR_MASK)

/*!
 * @}
 */ /* end of group USB_Register_Masks */


/* USB - Peripheral instance base addresses */
/** Peripheral USB0 base address */
#define USB0_BASE                                (0x40072000u)
/** Peripheral USB0 base pointer */
#define USB0                                     ((USB_Type *)USB0_BASE)
#define USB0_BASE_PTR                            (USB0)
/** Array initializer of USB peripheral base addresses */
#define USB_BASE_ADDRS                           { USB0_BASE }
/** Array initializer of USB peripheral base pointers */
#define USB_BASE_PTRS                            { USB0 }
/** Interrupt vectors for the USB peripheral type */
#define USB_IRQS                                 { USB0_IRQn }

/* ----------------------------------------------------------------------------
   -- USB - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup USB_Register_Accessor_Macros USB - Register accessor macros
 * @{
 */


/* USB - Register instance definitions */
/* USB0 */
#define USB0_PERID                               USB_PERID_REG(USB0)
#define USB0_IDCOMP                              USB_IDCOMP_REG(USB0)
#define USB0_REV                                 USB_REV_REG(USB0)
#define USB0_ADDINFO                             USB_ADDINFO_REG(USB0)
#define USB0_OTGISTAT                            USB_OTGISTAT_REG(USB0)
#define USB0_OTGICR                              USB_OTGICR_REG(USB0)
#define USB0_OTGSTAT                             USB_OTGSTAT_REG(USB0)
#define USB0_OTGCTL                              USB_OTGCTL_REG(USB0)
#define USB0_ISTAT                               USB_ISTAT_REG(USB0)
#define USB0_INTEN                               USB_INTEN_REG(USB0)
#define USB0_ERRSTAT                             USB_ERRSTAT_REG(USB0)
#define USB0_ERREN                               USB_ERREN_REG(USB0)
#define USB0_STAT                                USB_STAT_REG(USB0)
#define USB0_CTL                                 USB_CTL_REG(USB0)
#define USB0_ADDR                                USB_ADDR_REG(USB0)
#define USB0_BDTPAGE1                            USB_BDTPAGE1_REG(USB0)
#define USB0_FRMNUML                             USB_FRMNUML_REG(USB0)
#define USB0_FRMNUMH                             USB_FRMNUMH_REG(USB0)
#define USB0_TOKEN                               USB_TOKEN_REG(USB0)
#define USB0_SOFTHLD                             USB_SOFTHLD_REG(USB0)
#define USB0_BDTPAGE2                            USB_BDTPAGE2_REG(USB0)
#define USB0_BDTPAGE3                            USB_BDTPAGE3_REG(USB0)
#define USB0_ENDPT0                              USB_ENDPT_REG(USB0,0)
#define USB0_ENDPT1                              USB_ENDPT_REG(USB0,1)
#define USB0_ENDPT2                              USB_ENDPT_REG(USB0,2)
#define USB0_ENDPT3                              USB_ENDPT_REG(USB0,3)
#define USB0_ENDPT4                              USB_ENDPT_REG(USB0,4)
#define USB0_ENDPT5                              USB_ENDPT_REG(USB0,5)
#define USB0_ENDPT6                              USB_ENDPT_REG(USB0,6)
#define USB0_ENDPT7                              USB_ENDPT_REG(USB0,7)
#define USB0_ENDPT8                              USB_ENDPT_REG(USB0,8)
#define USB0_ENDPT9                              USB_ENDPT_REG(USB0,9)
#define USB0_ENDPT10                             USB_ENDPT_REG(USB0,10)
#define USB0_ENDPT11                             USB_ENDPT_REG(USB0,11)
#define USB0_ENDPT12                             USB_ENDPT_REG(USB0,12)
#define USB0_ENDPT13                             USB_ENDPT_REG(USB0,13)
#define USB0_ENDPT14                             USB_ENDPT_REG(USB0,14)
#define USB0_ENDPT15                             USB_ENDPT_REG(USB0,15)
#define USB0_USBCTRL                             USB_USBCTRL_REG(USB0)
#define USB0_OBSERVE                             USB_OBSERVE_REG(USB0)
#define USB0_CONTROL                             USB_CONTROL_REG(USB0)
#define USB0_USBTRC0                             USB_USBTRC0_REG(USB0)
#define USB0_USBFRMADJUST                        USB_USBFRMADJUST_REG(USB0)
#define USB0_MISCCTRL                            USB_MISCCTRL_REG(USB0)
#define USB0_CLK_RECOVER_CTRL                    USB_CLK_RECOVER_CTRL_REG(USB0)
#define USB0_CLK_RECOVER_IRC_EN                  USB_CLK_RECOVER_IRC_EN_REG(USB0)
#define USB0_CLK_RECOVER_INT_EN                  USB_CLK_RECOVER_INT_EN_REG(USB0)
#define USB0_CLK_RECOVER_INT_STATUS              USB_CLK_RECOVER_INT_STATUS_REG(USB0)

/* USB - Register array accessors */
#define USB0_ENDPT(index)                        USB_ENDPT_REG(USB0,index)

/*!
 * @}
 */ /* end of group USB_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group USB_Peripheral_Access_Layer */
 
 // SIM stuff - useless but required
 #define SIM_SCGC6_REG(base)                      ((base)->SCGC6)
 #define SIM_SCGC6                                SIM_SCGC6_REG(SIM)
 #define SIM_SCGC6_PIT_MASK                       0x800000u
#define SIM_UIDH_REG(base)                       ((base)->UIDH)
#define SIM_UIDMH_REG(base)                      ((base)->UIDMH)
#define SIM_UIDML_REG(base)                      ((base)->UIDML)
#define SIM_UIDL_REG(base)                       ((base)->UIDL)
 #define SIM_SDID_REG(base)                       ((base)->SDID)
#define SIM_UIDL                                 SIM_UIDL_REG(SIM)
#define SIM_UIDH                                 SIM_UIDH_REG(SIM)
#define SIM_UIDMH                                SIM_UIDMH_REG(SIM)
#define SIM_UIDML                                SIM_UIDML_REG(SIM)
/* ----------------------------------------------------------------------------
   -- LPI2C Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPI2C_Peripheral_Access_Layer LPI2C Peripheral Access Layer
 * @{
 */

/** LPI2C - Register Layout Typedef */
typedef struct {
  __I  uint32_t VERID;                             /**< Version ID Register, offset: 0x0 */
  __I  uint32_t PARAM;                             /**< Parameter Register, offset: 0x4 */
       uint8_t RESERVED_0[8];
  __IO uint32_t MCR;                               /**< Master Control Register, offset: 0x10 */
  __IO uint32_t MSR;                               /**< Master Status Register, offset: 0x14 */
  __IO uint32_t MIER;                              /**< Master Interrupt Enable Register, offset: 0x18 */
  __IO uint32_t MDER;                              /**< Master DMA Enable Register, offset: 0x1C */
  __IO uint32_t MCFGR0;                            /**< Master Configuration Register 0, offset: 0x20 */
  __IO uint32_t MCFGR1;                            /**< Master Configuration Register 1, offset: 0x24 */
  __IO uint32_t MCFGR2;                            /**< Master Configuration Register 2, offset: 0x28 */
  __IO uint32_t MCFGR3;                            /**< Master Configuration Register 3, offset: 0x2C */
       uint8_t RESERVED_1[16];
  __IO uint32_t MDMR;                              /**< Master Data Match Register, offset: 0x40 */
       uint8_t RESERVED_2[4];
  __IO uint32_t MCCR0;                             /**< Master Clock Configuration Register 0, offset: 0x48 */
       uint8_t RESERVED_3[4];
  __IO uint32_t MCCR1;                             /**< Master Clock Configuration Register 1, offset: 0x50 */
       uint8_t RESERVED_4[4];
  __IO uint32_t MFCR;                              /**< Master FIFO Control Register, offset: 0x58 */
  __I  uint32_t MFSR;                              /**< Master FIFO Status Register, offset: 0x5C */
  __O  uint32_t MTDR;                              /**< Master Transmit Data Register, offset: 0x60 */
       uint8_t RESERVED_5[12];
  __I  uint32_t MRDR;                              /**< Master Receive Data Register, offset: 0x70 */
       uint8_t RESERVED_6[156];
  __IO uint32_t SCR;                               /**< Slave Control Register, offset: 0x110 */
  __IO uint32_t SSR;                               /**< Slave Status Register, offset: 0x114 */
  __IO uint32_t SIER;                              /**< Slave Interrupt Enable Register, offset: 0x118 */
  __IO uint32_t SDER;                              /**< Slave DMA Enable Register, offset: 0x11C */
       uint8_t RESERVED_7[4];
  __IO uint32_t SCFGR1;                            /**< Slave Configuration Register 1, offset: 0x124 */
  __IO uint32_t SCFGR2;                            /**< Slave Configuration Register 2, offset: 0x128 */
       uint8_t RESERVED_8[20];
  __IO uint32_t SAMR;                              /**< Slave Address Match Register, offset: 0x140 */
       uint8_t RESERVED_9[12];
  __I  uint32_t SASR;                              /**< Slave Address Status Register, offset: 0x150 */
  __IO uint32_t STAR;                              /**< Slave Transmit ACK Register, offset: 0x154 */
       uint8_t RESERVED_10[8];
  __O  uint32_t STDR;                              /**< Slave Transmit Data Register, offset: 0x160 */
       uint8_t RESERVED_11[12];
  __I  uint32_t SRDR;                              /**< Slave Receive Data Register, offset: 0x170 */
} LPI2C_Type, *LPI2C_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- LPI2C - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPI2C_Register_Accessor_Macros LPI2C - Register accessor macros
 * @{
 */


/* LPI2C - Register accessors */
#define LPI2C_VERID_REG(base)                    ((base)->VERID)
#define LPI2C_PARAM_REG(base)                    ((base)->PARAM)
#define LPI2C_MCR_REG(base)                      ((base)->MCR)
#define LPI2C_MSR_REG(base)                      ((base)->MSR)
#define LPI2C_MIER_REG(base)                     ((base)->MIER)
#define LPI2C_MDER_REG(base)                     ((base)->MDER)
#define LPI2C_MCFGR0_REG(base)                   ((base)->MCFGR0)
#define LPI2C_MCFGR1_REG(base)                   ((base)->MCFGR1)
#define LPI2C_MCFGR2_REG(base)                   ((base)->MCFGR2)
#define LPI2C_MCFGR3_REG(base)                   ((base)->MCFGR3)
#define LPI2C_MDMR_REG(base)                     ((base)->MDMR)
#define LPI2C_MCCR0_REG(base)                    ((base)->MCCR0)
#define LPI2C_MCCR1_REG(base)                    ((base)->MCCR1)
#define LPI2C_MFCR_REG(base)                     ((base)->MFCR)
#define LPI2C_MFSR_REG(base)                     ((base)->MFSR)
#define LPI2C_MTDR_REG(base)                     ((base)->MTDR)
#define LPI2C_MRDR_REG(base)                     ((base)->MRDR)
#define LPI2C_SCR_REG(base)                      ((base)->SCR)
#define LPI2C_SSR_REG(base)                      ((base)->SSR)
#define LPI2C_SIER_REG(base)                     ((base)->SIER)
#define LPI2C_SDER_REG(base)                     ((base)->SDER)
#define LPI2C_SCFGR1_REG(base)                   ((base)->SCFGR1)
#define LPI2C_SCFGR2_REG(base)                   ((base)->SCFGR2)
#define LPI2C_SAMR_REG(base)                     ((base)->SAMR)
#define LPI2C_SASR_REG(base)                     ((base)->SASR)
#define LPI2C_STAR_REG(base)                     ((base)->STAR)
#define LPI2C_STDR_REG(base)                     ((base)->STDR)
#define LPI2C_SRDR_REG(base)                     ((base)->SRDR)

/*!
 * @}
 */ /* end of group LPI2C_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- LPI2C Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPI2C_Register_Masks LPI2C Register Masks
 * @{
 */

/* VERID Bit Fields */
#define LPI2C_VERID_FEATURE_MASK                 0xFFFFu
#define LPI2C_VERID_FEATURE_SHIFT                0
#define LPI2C_VERID_FEATURE_WIDTH                16
#define LPI2C_VERID_FEATURE(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_VERID_FEATURE_SHIFT))&LPI2C_VERID_FEATURE_MASK)
#define LPI2C_VERID_MINOR_MASK                   0xFF0000u
#define LPI2C_VERID_MINOR_SHIFT                  16
#define LPI2C_VERID_MINOR_WIDTH                  8
#define LPI2C_VERID_MINOR(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_VERID_MINOR_SHIFT))&LPI2C_VERID_MINOR_MASK)
#define LPI2C_VERID_MAJOR_MASK                   0xFF000000u
#define LPI2C_VERID_MAJOR_SHIFT                  24
#define LPI2C_VERID_MAJOR_WIDTH                  8
#define LPI2C_VERID_MAJOR(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_VERID_MAJOR_SHIFT))&LPI2C_VERID_MAJOR_MASK)
/* PARAM Bit Fields */
#define LPI2C_PARAM_MTXFIFO_MASK                 0xFu
#define LPI2C_PARAM_MTXFIFO_SHIFT                0
#define LPI2C_PARAM_MTXFIFO_WIDTH                4
#define LPI2C_PARAM_MTXFIFO(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_PARAM_MTXFIFO_SHIFT))&LPI2C_PARAM_MTXFIFO_MASK)
#define LPI2C_PARAM_MRXFIFO_MASK                 0xF00u
#define LPI2C_PARAM_MRXFIFO_SHIFT                8
#define LPI2C_PARAM_MRXFIFO_WIDTH                4
#define LPI2C_PARAM_MRXFIFO(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_PARAM_MRXFIFO_SHIFT))&LPI2C_PARAM_MRXFIFO_MASK)
/* MCR Bit Fields */
#define LPI2C_MCR_MEN_MASK                       0x1u
#define LPI2C_MCR_MEN_SHIFT                      0
#define LPI2C_MCR_MEN_WIDTH                      1
#define LPI2C_MCR_MEN(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MCR_MEN_SHIFT))&LPI2C_MCR_MEN_MASK)
#define LPI2C_MCR_RST_MASK                       0x2u
#define LPI2C_MCR_RST_SHIFT                      1
#define LPI2C_MCR_RST_WIDTH                      1
#define LPI2C_MCR_RST(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MCR_RST_SHIFT))&LPI2C_MCR_RST_MASK)
#define LPI2C_MCR_DOZEN_MASK                     0x4u
#define LPI2C_MCR_DOZEN_SHIFT                    2
#define LPI2C_MCR_DOZEN_WIDTH                    1
#define LPI2C_MCR_DOZEN(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MCR_DOZEN_SHIFT))&LPI2C_MCR_DOZEN_MASK)
#define LPI2C_MCR_DBGEN_MASK                     0x8u
#define LPI2C_MCR_DBGEN_SHIFT                    3
#define LPI2C_MCR_DBGEN_WIDTH                    1
#define LPI2C_MCR_DBGEN(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MCR_DBGEN_SHIFT))&LPI2C_MCR_DBGEN_MASK)
#define LPI2C_MCR_RTF_MASK                       0x100u
#define LPI2C_MCR_RTF_SHIFT                      8
#define LPI2C_MCR_RTF_WIDTH                      1
#define LPI2C_MCR_RTF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MCR_RTF_SHIFT))&LPI2C_MCR_RTF_MASK)
#define LPI2C_MCR_RRF_MASK                       0x200u
#define LPI2C_MCR_RRF_SHIFT                      9
#define LPI2C_MCR_RRF_WIDTH                      1
#define LPI2C_MCR_RRF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MCR_RRF_SHIFT))&LPI2C_MCR_RRF_MASK)
/* MSR Bit Fields */
#define LPI2C_MSR_TDF_MASK                       0x1u
#define LPI2C_MSR_TDF_SHIFT                      0
#define LPI2C_MSR_TDF_WIDTH                      1
#define LPI2C_MSR_TDF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_TDF_SHIFT))&LPI2C_MSR_TDF_MASK)
#define LPI2C_MSR_RDF_MASK                       0x2u
#define LPI2C_MSR_RDF_SHIFT                      1
#define LPI2C_MSR_RDF_WIDTH                      1
#define LPI2C_MSR_RDF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_RDF_SHIFT))&LPI2C_MSR_RDF_MASK)
#define LPI2C_MSR_EPF_MASK                       0x100u
#define LPI2C_MSR_EPF_SHIFT                      8
#define LPI2C_MSR_EPF_WIDTH                      1
#define LPI2C_MSR_EPF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_EPF_SHIFT))&LPI2C_MSR_EPF_MASK)
#define LPI2C_MSR_SDF_MASK                       0x200u
#define LPI2C_MSR_SDF_SHIFT                      9
#define LPI2C_MSR_SDF_WIDTH                      1
#define LPI2C_MSR_SDF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_SDF_SHIFT))&LPI2C_MSR_SDF_MASK)
#define LPI2C_MSR_NDF_MASK                       0x400u
#define LPI2C_MSR_NDF_SHIFT                      10
#define LPI2C_MSR_NDF_WIDTH                      1
#define LPI2C_MSR_NDF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_NDF_SHIFT))&LPI2C_MSR_NDF_MASK)
#define LPI2C_MSR_ALF_MASK                       0x800u
#define LPI2C_MSR_ALF_SHIFT                      11
#define LPI2C_MSR_ALF_WIDTH                      1
#define LPI2C_MSR_ALF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_ALF_SHIFT))&LPI2C_MSR_ALF_MASK)
#define LPI2C_MSR_FEF_MASK                       0x1000u
#define LPI2C_MSR_FEF_SHIFT                      12
#define LPI2C_MSR_FEF_WIDTH                      1
#define LPI2C_MSR_FEF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_FEF_SHIFT))&LPI2C_MSR_FEF_MASK)
#define LPI2C_MSR_PLTF_MASK                      0x2000u
#define LPI2C_MSR_PLTF_SHIFT                     13
#define LPI2C_MSR_PLTF_WIDTH                     1
#define LPI2C_MSR_PLTF(x)                        (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_PLTF_SHIFT))&LPI2C_MSR_PLTF_MASK)
#define LPI2C_MSR_DMF_MASK                       0x4000u
#define LPI2C_MSR_DMF_SHIFT                      14
#define LPI2C_MSR_DMF_WIDTH                      1
#define LPI2C_MSR_DMF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_DMF_SHIFT))&LPI2C_MSR_DMF_MASK)
#define LPI2C_MSR_MBF_MASK                       0x1000000u
#define LPI2C_MSR_MBF_SHIFT                      24
#define LPI2C_MSR_MBF_WIDTH                      1
#define LPI2C_MSR_MBF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_MBF_SHIFT))&LPI2C_MSR_MBF_MASK)
#define LPI2C_MSR_BBF_MASK                       0x2000000u
#define LPI2C_MSR_BBF_SHIFT                      25
#define LPI2C_MSR_BBF_WIDTH                      1
#define LPI2C_MSR_BBF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_MSR_BBF_SHIFT))&LPI2C_MSR_BBF_MASK)
/* MIER Bit Fields */
#define LPI2C_MIER_TDIE_MASK                     0x1u
#define LPI2C_MIER_TDIE_SHIFT                    0
#define LPI2C_MIER_TDIE_WIDTH                    1
#define LPI2C_MIER_TDIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MIER_TDIE_SHIFT))&LPI2C_MIER_TDIE_MASK)
#define LPI2C_MIER_RDIE_MASK                     0x2u
#define LPI2C_MIER_RDIE_SHIFT                    1
#define LPI2C_MIER_RDIE_WIDTH                    1
#define LPI2C_MIER_RDIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MIER_RDIE_SHIFT))&LPI2C_MIER_RDIE_MASK)
#define LPI2C_MIER_EPIE_MASK                     0x100u
#define LPI2C_MIER_EPIE_SHIFT                    8
#define LPI2C_MIER_EPIE_WIDTH                    1
#define LPI2C_MIER_EPIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MIER_EPIE_SHIFT))&LPI2C_MIER_EPIE_MASK)
#define LPI2C_MIER_SDIE_MASK                     0x200u
#define LPI2C_MIER_SDIE_SHIFT                    9
#define LPI2C_MIER_SDIE_WIDTH                    1
#define LPI2C_MIER_SDIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MIER_SDIE_SHIFT))&LPI2C_MIER_SDIE_MASK)
#define LPI2C_MIER_NDIE_MASK                     0x400u
#define LPI2C_MIER_NDIE_SHIFT                    10
#define LPI2C_MIER_NDIE_WIDTH                    1
#define LPI2C_MIER_NDIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MIER_NDIE_SHIFT))&LPI2C_MIER_NDIE_MASK)
#define LPI2C_MIER_ALIE_MASK                     0x800u
#define LPI2C_MIER_ALIE_SHIFT                    11
#define LPI2C_MIER_ALIE_WIDTH                    1
#define LPI2C_MIER_ALIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MIER_ALIE_SHIFT))&LPI2C_MIER_ALIE_MASK)
#define LPI2C_MIER_FEIE_MASK                     0x1000u
#define LPI2C_MIER_FEIE_SHIFT                    12
#define LPI2C_MIER_FEIE_WIDTH                    1
#define LPI2C_MIER_FEIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MIER_FEIE_SHIFT))&LPI2C_MIER_FEIE_MASK)
#define LPI2C_MIER_PLTIE_MASK                    0x2000u
#define LPI2C_MIER_PLTIE_SHIFT                   13
#define LPI2C_MIER_PLTIE_WIDTH                   1
#define LPI2C_MIER_PLTIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPI2C_MIER_PLTIE_SHIFT))&LPI2C_MIER_PLTIE_MASK)
#define LPI2C_MIER_DMIE_MASK                     0x4000u
#define LPI2C_MIER_DMIE_SHIFT                    14
#define LPI2C_MIER_DMIE_WIDTH                    1
#define LPI2C_MIER_DMIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MIER_DMIE_SHIFT))&LPI2C_MIER_DMIE_MASK)
/* MDER Bit Fields */
#define LPI2C_MDER_TDDE_MASK                     0x1u
#define LPI2C_MDER_TDDE_SHIFT                    0
#define LPI2C_MDER_TDDE_WIDTH                    1
#define LPI2C_MDER_TDDE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MDER_TDDE_SHIFT))&LPI2C_MDER_TDDE_MASK)
#define LPI2C_MDER_RDDE_MASK                     0x2u
#define LPI2C_MDER_RDDE_SHIFT                    1
#define LPI2C_MDER_RDDE_WIDTH                    1
#define LPI2C_MDER_RDDE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MDER_RDDE_SHIFT))&LPI2C_MDER_RDDE_MASK)
/* MCFGR0 Bit Fields */
#define LPI2C_MCFGR0_HREN_MASK                   0x1u
#define LPI2C_MCFGR0_HREN_SHIFT                  0
#define LPI2C_MCFGR0_HREN_WIDTH                  1
#define LPI2C_MCFGR0_HREN(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR0_HREN_SHIFT))&LPI2C_MCFGR0_HREN_MASK)
#define LPI2C_MCFGR0_HRPOL_MASK                  0x2u
#define LPI2C_MCFGR0_HRPOL_SHIFT                 1
#define LPI2C_MCFGR0_HRPOL_WIDTH                 1
#define LPI2C_MCFGR0_HRPOL(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR0_HRPOL_SHIFT))&LPI2C_MCFGR0_HRPOL_MASK)
#define LPI2C_MCFGR0_HRSEL_MASK                  0x4u
#define LPI2C_MCFGR0_HRSEL_SHIFT                 2
#define LPI2C_MCFGR0_HRSEL_WIDTH                 1
#define LPI2C_MCFGR0_HRSEL(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR0_HRSEL_SHIFT))&LPI2C_MCFGR0_HRSEL_MASK)
#define LPI2C_MCFGR0_CIRFIFO_MASK                0x100u
#define LPI2C_MCFGR0_CIRFIFO_SHIFT               8
#define LPI2C_MCFGR0_CIRFIFO_WIDTH               1
#define LPI2C_MCFGR0_CIRFIFO(x)                  (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR0_CIRFIFO_SHIFT))&LPI2C_MCFGR0_CIRFIFO_MASK)
#define LPI2C_MCFGR0_RDMO_MASK                   0x200u
#define LPI2C_MCFGR0_RDMO_SHIFT                  9
#define LPI2C_MCFGR0_RDMO_WIDTH                  1
#define LPI2C_MCFGR0_RDMO(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR0_RDMO_SHIFT))&LPI2C_MCFGR0_RDMO_MASK)
/* MCFGR1 Bit Fields */
#define LPI2C_MCFGR1_PRESCALE_MASK               0x7u
#define LPI2C_MCFGR1_PRESCALE_SHIFT              0
#define LPI2C_MCFGR1_PRESCALE_WIDTH              3
#define LPI2C_MCFGR1_PRESCALE(x)                 (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR1_PRESCALE_SHIFT))&LPI2C_MCFGR1_PRESCALE_MASK)
#define LPI2C_MCFGR1_AUTOSTOP_MASK               0x100u
#define LPI2C_MCFGR1_AUTOSTOP_SHIFT              8
#define LPI2C_MCFGR1_AUTOSTOP_WIDTH              1
#define LPI2C_MCFGR1_AUTOSTOP(x)                 (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR1_AUTOSTOP_SHIFT))&LPI2C_MCFGR1_AUTOSTOP_MASK)
#define LPI2C_MCFGR1_IGNACK_MASK                 0x200u
#define LPI2C_MCFGR1_IGNACK_SHIFT                9
#define LPI2C_MCFGR1_IGNACK_WIDTH                1
#define LPI2C_MCFGR1_IGNACK(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR1_IGNACK_SHIFT))&LPI2C_MCFGR1_IGNACK_MASK)
#define LPI2C_MCFGR1_TIMECFG_MASK                0x400u
#define LPI2C_MCFGR1_TIMECFG_SHIFT               10
#define LPI2C_MCFGR1_TIMECFG_WIDTH               1
#define LPI2C_MCFGR1_TIMECFG(x)                  (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR1_TIMECFG_SHIFT))&LPI2C_MCFGR1_TIMECFG_MASK)
#define LPI2C_MCFGR1_MATCFG_MASK                 0x70000u
#define LPI2C_MCFGR1_MATCFG_SHIFT                16
#define LPI2C_MCFGR1_MATCFG_WIDTH                3
#define LPI2C_MCFGR1_MATCFG(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR1_MATCFG_SHIFT))&LPI2C_MCFGR1_MATCFG_MASK)
#define LPI2C_MCFGR1_PINCFG_MASK                 0x7000000u
#define LPI2C_MCFGR1_PINCFG_SHIFT                24
#define LPI2C_MCFGR1_PINCFG_WIDTH                3
#define LPI2C_MCFGR1_PINCFG(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR1_PINCFG_SHIFT))&LPI2C_MCFGR1_PINCFG_MASK)
/* MCFGR2 Bit Fields */
#define LPI2C_MCFGR2_BUSIDLE_MASK                0xFFFu
#define LPI2C_MCFGR2_BUSIDLE_SHIFT               0
#define LPI2C_MCFGR2_BUSIDLE_WIDTH               12
#define LPI2C_MCFGR2_BUSIDLE(x)                  (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR2_BUSIDLE_SHIFT))&LPI2C_MCFGR2_BUSIDLE_MASK)
#define LPI2C_MCFGR2_FILTSCL_MASK                0xF0000u
#define LPI2C_MCFGR2_FILTSCL_SHIFT               16
#define LPI2C_MCFGR2_FILTSCL_WIDTH               4
#define LPI2C_MCFGR2_FILTSCL(x)                  (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR2_FILTSCL_SHIFT))&LPI2C_MCFGR2_FILTSCL_MASK)
#define LPI2C_MCFGR2_FILTSDA_MASK                0xF000000u
#define LPI2C_MCFGR2_FILTSDA_SHIFT               24
#define LPI2C_MCFGR2_FILTSDA_WIDTH               4
#define LPI2C_MCFGR2_FILTSDA(x)                  (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR2_FILTSDA_SHIFT))&LPI2C_MCFGR2_FILTSDA_MASK)
/* MCFGR3 Bit Fields */
#define LPI2C_MCFGR3_PINLOW_MASK                 0xFFF00u
#define LPI2C_MCFGR3_PINLOW_SHIFT                8
#define LPI2C_MCFGR3_PINLOW_WIDTH                12
#define LPI2C_MCFGR3_PINLOW(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_MCFGR3_PINLOW_SHIFT))&LPI2C_MCFGR3_PINLOW_MASK)
/* MDMR Bit Fields */
#define LPI2C_MDMR_MATCH0_MASK                   0xFFu
#define LPI2C_MDMR_MATCH0_SHIFT                  0
#define LPI2C_MDMR_MATCH0_WIDTH                  8
#define LPI2C_MDMR_MATCH0(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_MDMR_MATCH0_SHIFT))&LPI2C_MDMR_MATCH0_MASK)
#define LPI2C_MDMR_MATCH1_MASK                   0xFF0000u
#define LPI2C_MDMR_MATCH1_SHIFT                  16
#define LPI2C_MDMR_MATCH1_WIDTH                  8
#define LPI2C_MDMR_MATCH1(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_MDMR_MATCH1_SHIFT))&LPI2C_MDMR_MATCH1_MASK)
/* MCCR0 Bit Fields */
#define LPI2C_MCCR0_CLKLO_MASK                   0x3Fu
#define LPI2C_MCCR0_CLKLO_SHIFT                  0
#define LPI2C_MCCR0_CLKLO_WIDTH                  6
#define LPI2C_MCCR0_CLKLO(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_MCCR0_CLKLO_SHIFT))&LPI2C_MCCR0_CLKLO_MASK)
#define LPI2C_MCCR0_CLKHI_MASK                   0x3F00u
#define LPI2C_MCCR0_CLKHI_SHIFT                  8
#define LPI2C_MCCR0_CLKHI_WIDTH                  6
#define LPI2C_MCCR0_CLKHI(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_MCCR0_CLKHI_SHIFT))&LPI2C_MCCR0_CLKHI_MASK)
#define LPI2C_MCCR0_SETHOLD_MASK                 0x3F0000u
#define LPI2C_MCCR0_SETHOLD_SHIFT                16
#define LPI2C_MCCR0_SETHOLD_WIDTH                6
#define LPI2C_MCCR0_SETHOLD(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_MCCR0_SETHOLD_SHIFT))&LPI2C_MCCR0_SETHOLD_MASK)
#define LPI2C_MCCR0_DATAVD_MASK                  0x3F000000u
#define LPI2C_MCCR0_DATAVD_SHIFT                 24
#define LPI2C_MCCR0_DATAVD_WIDTH                 6
#define LPI2C_MCCR0_DATAVD(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_MCCR0_DATAVD_SHIFT))&LPI2C_MCCR0_DATAVD_MASK)
/* MCCR1 Bit Fields */
#define LPI2C_MCCR1_CLKLO_MASK                   0x3Fu
#define LPI2C_MCCR1_CLKLO_SHIFT                  0
#define LPI2C_MCCR1_CLKLO_WIDTH                  6
#define LPI2C_MCCR1_CLKLO(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_MCCR1_CLKLO_SHIFT))&LPI2C_MCCR1_CLKLO_MASK)
#define LPI2C_MCCR1_CLKHI_MASK                   0x3F00u
#define LPI2C_MCCR1_CLKHI_SHIFT                  8
#define LPI2C_MCCR1_CLKHI_WIDTH                  6
#define LPI2C_MCCR1_CLKHI(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_MCCR1_CLKHI_SHIFT))&LPI2C_MCCR1_CLKHI_MASK)
#define LPI2C_MCCR1_SETHOLD_MASK                 0x3F0000u
#define LPI2C_MCCR1_SETHOLD_SHIFT                16
#define LPI2C_MCCR1_SETHOLD_WIDTH                6
#define LPI2C_MCCR1_SETHOLD(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_MCCR1_SETHOLD_SHIFT))&LPI2C_MCCR1_SETHOLD_MASK)
#define LPI2C_MCCR1_DATAVD_MASK                  0x3F000000u
#define LPI2C_MCCR1_DATAVD_SHIFT                 24
#define LPI2C_MCCR1_DATAVD_WIDTH                 6
#define LPI2C_MCCR1_DATAVD(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_MCCR1_DATAVD_SHIFT))&LPI2C_MCCR1_DATAVD_MASK)
/* MFCR Bit Fields */
#define LPI2C_MFCR_TXWATER_MASK                  0xFFu
#define LPI2C_MFCR_TXWATER_SHIFT                 0
#define LPI2C_MFCR_TXWATER_WIDTH                 8
#define LPI2C_MFCR_TXWATER(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_MFCR_TXWATER_SHIFT))&LPI2C_MFCR_TXWATER_MASK)
#define LPI2C_MFCR_RXWATER_MASK                  0xFF0000u
#define LPI2C_MFCR_RXWATER_SHIFT                 16
#define LPI2C_MFCR_RXWATER_WIDTH                 8
#define LPI2C_MFCR_RXWATER(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_MFCR_RXWATER_SHIFT))&LPI2C_MFCR_RXWATER_MASK)
/* MFSR Bit Fields */
#define LPI2C_MFSR_TXCOUNT_MASK                  0xFFu
#define LPI2C_MFSR_TXCOUNT_SHIFT                 0
#define LPI2C_MFSR_TXCOUNT_WIDTH                 8
#define LPI2C_MFSR_TXCOUNT(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_MFSR_TXCOUNT_SHIFT))&LPI2C_MFSR_TXCOUNT_MASK)
#define LPI2C_MFSR_RXCOUNT_MASK                  0xFF0000u
#define LPI2C_MFSR_RXCOUNT_SHIFT                 16
#define LPI2C_MFSR_RXCOUNT_WIDTH                 8
#define LPI2C_MFSR_RXCOUNT(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_MFSR_RXCOUNT_SHIFT))&LPI2C_MFSR_RXCOUNT_MASK)
/* MTDR Bit Fields */
#define LPI2C_MTDR_DATA_MASK                     0xFFu
#define LPI2C_MTDR_DATA_SHIFT                    0
#define LPI2C_MTDR_DATA_WIDTH                    8
#define LPI2C_MTDR_DATA(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MTDR_DATA_SHIFT))&LPI2C_MTDR_DATA_MASK)
#define LPI2C_MTDR_CMD_MASK                      0x700u
#define LPI2C_MTDR_CMD_SHIFT                     8
#define LPI2C_MTDR_CMD_WIDTH                     3
#define LPI2C_MTDR_CMD(x)                        (((uint32_t)(((uint32_t)(x))<<LPI2C_MTDR_CMD_SHIFT))&LPI2C_MTDR_CMD_MASK)
/* MRDR Bit Fields */
#define LPI2C_MRDR_DATA_MASK                     0xFFu
#define LPI2C_MRDR_DATA_SHIFT                    0
#define LPI2C_MRDR_DATA_WIDTH                    8
#define LPI2C_MRDR_DATA(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_MRDR_DATA_SHIFT))&LPI2C_MRDR_DATA_MASK)
#define LPI2C_MRDR_RXEMPTY_MASK                  0x4000u
#define LPI2C_MRDR_RXEMPTY_SHIFT                 14
#define LPI2C_MRDR_RXEMPTY_WIDTH                 1
#define LPI2C_MRDR_RXEMPTY(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_MRDR_RXEMPTY_SHIFT))&LPI2C_MRDR_RXEMPTY_MASK)
/* SCR Bit Fields */
#define LPI2C_SCR_SEN_MASK                       0x1u
#define LPI2C_SCR_SEN_SHIFT                      0
#define LPI2C_SCR_SEN_WIDTH                      1
#define LPI2C_SCR_SEN(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SCR_SEN_SHIFT))&LPI2C_SCR_SEN_MASK)
#define LPI2C_SCR_RST_MASK                       0x2u
#define LPI2C_SCR_RST_SHIFT                      1
#define LPI2C_SCR_RST_WIDTH                      1
#define LPI2C_SCR_RST(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SCR_RST_SHIFT))&LPI2C_SCR_RST_MASK)
#define LPI2C_SCR_FILTEN_MASK                    0x10u
#define LPI2C_SCR_FILTEN_SHIFT                   4
#define LPI2C_SCR_FILTEN_WIDTH                   1
#define LPI2C_SCR_FILTEN(x)                      (((uint32_t)(((uint32_t)(x))<<LPI2C_SCR_FILTEN_SHIFT))&LPI2C_SCR_FILTEN_MASK)
#define LPI2C_SCR_FILTDZ_MASK                    0x20u
#define LPI2C_SCR_FILTDZ_SHIFT                   5
#define LPI2C_SCR_FILTDZ_WIDTH                   1
#define LPI2C_SCR_FILTDZ(x)                      (((uint32_t)(((uint32_t)(x))<<LPI2C_SCR_FILTDZ_SHIFT))&LPI2C_SCR_FILTDZ_MASK)
#define LPI2C_SCR_RTF_MASK                       0x100u
#define LPI2C_SCR_RTF_SHIFT                      8
#define LPI2C_SCR_RTF_WIDTH                      1
#define LPI2C_SCR_RTF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SCR_RTF_SHIFT))&LPI2C_SCR_RTF_MASK)
#define LPI2C_SCR_RRF_MASK                       0x200u
#define LPI2C_SCR_RRF_SHIFT                      9
#define LPI2C_SCR_RRF_WIDTH                      1
#define LPI2C_SCR_RRF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SCR_RRF_SHIFT))&LPI2C_SCR_RRF_MASK)
/* SSR Bit Fields */
#define LPI2C_SSR_TDF_MASK                       0x1u
#define LPI2C_SSR_TDF_SHIFT                      0
#define LPI2C_SSR_TDF_WIDTH                      1
#define LPI2C_SSR_TDF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_TDF_SHIFT))&LPI2C_SSR_TDF_MASK)
#define LPI2C_SSR_RDF_MASK                       0x2u
#define LPI2C_SSR_RDF_SHIFT                      1
#define LPI2C_SSR_RDF_WIDTH                      1
#define LPI2C_SSR_RDF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_RDF_SHIFT))&LPI2C_SSR_RDF_MASK)
#define LPI2C_SSR_AVF_MASK                       0x4u
#define LPI2C_SSR_AVF_SHIFT                      2
#define LPI2C_SSR_AVF_WIDTH                      1
#define LPI2C_SSR_AVF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_AVF_SHIFT))&LPI2C_SSR_AVF_MASK)
#define LPI2C_SSR_TAF_MASK                       0x8u
#define LPI2C_SSR_TAF_SHIFT                      3
#define LPI2C_SSR_TAF_WIDTH                      1
#define LPI2C_SSR_TAF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_TAF_SHIFT))&LPI2C_SSR_TAF_MASK)
#define LPI2C_SSR_RSF_MASK                       0x100u
#define LPI2C_SSR_RSF_SHIFT                      8
#define LPI2C_SSR_RSF_WIDTH                      1
#define LPI2C_SSR_RSF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_RSF_SHIFT))&LPI2C_SSR_RSF_MASK)
#define LPI2C_SSR_SDF_MASK                       0x200u
#define LPI2C_SSR_SDF_SHIFT                      9
#define LPI2C_SSR_SDF_WIDTH                      1
#define LPI2C_SSR_SDF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_SDF_SHIFT))&LPI2C_SSR_SDF_MASK)
#define LPI2C_SSR_BEF_MASK                       0x400u
#define LPI2C_SSR_BEF_SHIFT                      10
#define LPI2C_SSR_BEF_WIDTH                      1
#define LPI2C_SSR_BEF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_BEF_SHIFT))&LPI2C_SSR_BEF_MASK)
#define LPI2C_SSR_FEF_MASK                       0x800u
#define LPI2C_SSR_FEF_SHIFT                      11
#define LPI2C_SSR_FEF_WIDTH                      1
#define LPI2C_SSR_FEF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_FEF_SHIFT))&LPI2C_SSR_FEF_MASK)
#define LPI2C_SSR_AM0F_MASK                      0x1000u
#define LPI2C_SSR_AM0F_SHIFT                     12
#define LPI2C_SSR_AM0F_WIDTH                     1
#define LPI2C_SSR_AM0F(x)                        (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_AM0F_SHIFT))&LPI2C_SSR_AM0F_MASK)
#define LPI2C_SSR_AM1F_MASK                      0x2000u
#define LPI2C_SSR_AM1F_SHIFT                     13
#define LPI2C_SSR_AM1F_WIDTH                     1
#define LPI2C_SSR_AM1F(x)                        (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_AM1F_SHIFT))&LPI2C_SSR_AM1F_MASK)
#define LPI2C_SSR_GCF_MASK                       0x4000u
#define LPI2C_SSR_GCF_SHIFT                      14
#define LPI2C_SSR_GCF_WIDTH                      1
#define LPI2C_SSR_GCF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_GCF_SHIFT))&LPI2C_SSR_GCF_MASK)
#define LPI2C_SSR_SARF_MASK                      0x8000u
#define LPI2C_SSR_SARF_SHIFT                     15
#define LPI2C_SSR_SARF_WIDTH                     1
#define LPI2C_SSR_SARF(x)                        (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_SARF_SHIFT))&LPI2C_SSR_SARF_MASK)
#define LPI2C_SSR_SBF_MASK                       0x1000000u
#define LPI2C_SSR_SBF_SHIFT                      24
#define LPI2C_SSR_SBF_WIDTH                      1
#define LPI2C_SSR_SBF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_SBF_SHIFT))&LPI2C_SSR_SBF_MASK)
#define LPI2C_SSR_BBF_MASK                       0x2000000u
#define LPI2C_SSR_BBF_SHIFT                      25
#define LPI2C_SSR_BBF_WIDTH                      1
#define LPI2C_SSR_BBF(x)                         (((uint32_t)(((uint32_t)(x))<<LPI2C_SSR_BBF_SHIFT))&LPI2C_SSR_BBF_MASK)
/* SIER Bit Fields */
#define LPI2C_SIER_TDIE_MASK                     0x1u
#define LPI2C_SIER_TDIE_SHIFT                    0
#define LPI2C_SIER_TDIE_WIDTH                    1
#define LPI2C_SIER_TDIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_TDIE_SHIFT))&LPI2C_SIER_TDIE_MASK)
#define LPI2C_SIER_RDIE_MASK                     0x2u
#define LPI2C_SIER_RDIE_SHIFT                    1
#define LPI2C_SIER_RDIE_WIDTH                    1
#define LPI2C_SIER_RDIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_RDIE_SHIFT))&LPI2C_SIER_RDIE_MASK)
#define LPI2C_SIER_AVIE_MASK                     0x4u
#define LPI2C_SIER_AVIE_SHIFT                    2
#define LPI2C_SIER_AVIE_WIDTH                    1
#define LPI2C_SIER_AVIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_AVIE_SHIFT))&LPI2C_SIER_AVIE_MASK)
#define LPI2C_SIER_TAIE_MASK                     0x8u
#define LPI2C_SIER_TAIE_SHIFT                    3
#define LPI2C_SIER_TAIE_WIDTH                    1
#define LPI2C_SIER_TAIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_TAIE_SHIFT))&LPI2C_SIER_TAIE_MASK)
#define LPI2C_SIER_RSIE_MASK                     0x100u
#define LPI2C_SIER_RSIE_SHIFT                    8
#define LPI2C_SIER_RSIE_WIDTH                    1
#define LPI2C_SIER_RSIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_RSIE_SHIFT))&LPI2C_SIER_RSIE_MASK)
#define LPI2C_SIER_SDIE_MASK                     0x200u
#define LPI2C_SIER_SDIE_SHIFT                    9
#define LPI2C_SIER_SDIE_WIDTH                    1
#define LPI2C_SIER_SDIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_SDIE_SHIFT))&LPI2C_SIER_SDIE_MASK)
#define LPI2C_SIER_BEIE_MASK                     0x400u
#define LPI2C_SIER_BEIE_SHIFT                    10
#define LPI2C_SIER_BEIE_WIDTH                    1
#define LPI2C_SIER_BEIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_BEIE_SHIFT))&LPI2C_SIER_BEIE_MASK)
#define LPI2C_SIER_FEIE_MASK                     0x800u
#define LPI2C_SIER_FEIE_SHIFT                    11
#define LPI2C_SIER_FEIE_WIDTH                    1
#define LPI2C_SIER_FEIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_FEIE_SHIFT))&LPI2C_SIER_FEIE_MASK)
#define LPI2C_SIER_AM0IE_MASK                    0x1000u
#define LPI2C_SIER_AM0IE_SHIFT                   12
#define LPI2C_SIER_AM0IE_WIDTH                   1
#define LPI2C_SIER_AM0IE(x)                      (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_AM0IE_SHIFT))&LPI2C_SIER_AM0IE_MASK)
#define LPI2C_SIER_AM1F_MASK                     0x2000u
#define LPI2C_SIER_AM1F_SHIFT                    13
#define LPI2C_SIER_AM1F_WIDTH                    1
#define LPI2C_SIER_AM1F(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_AM1F_SHIFT))&LPI2C_SIER_AM1F_MASK)
#define LPI2C_SIER_GCIE_MASK                     0x4000u
#define LPI2C_SIER_GCIE_SHIFT                    14
#define LPI2C_SIER_GCIE_WIDTH                    1
#define LPI2C_SIER_GCIE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_GCIE_SHIFT))&LPI2C_SIER_GCIE_MASK)
#define LPI2C_SIER_SARIE_MASK                    0x8000u
#define LPI2C_SIER_SARIE_SHIFT                   15
#define LPI2C_SIER_SARIE_WIDTH                   1
#define LPI2C_SIER_SARIE(x)                      (((uint32_t)(((uint32_t)(x))<<LPI2C_SIER_SARIE_SHIFT))&LPI2C_SIER_SARIE_MASK)
/* SDER Bit Fields */
#define LPI2C_SDER_TDDE_MASK                     0x1u
#define LPI2C_SDER_TDDE_SHIFT                    0
#define LPI2C_SDER_TDDE_WIDTH                    1
#define LPI2C_SDER_TDDE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SDER_TDDE_SHIFT))&LPI2C_SDER_TDDE_MASK)
#define LPI2C_SDER_RDDE_MASK                     0x2u
#define LPI2C_SDER_RDDE_SHIFT                    1
#define LPI2C_SDER_RDDE_WIDTH                    1
#define LPI2C_SDER_RDDE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SDER_RDDE_SHIFT))&LPI2C_SDER_RDDE_MASK)
#define LPI2C_SDER_AVDE_MASK                     0x4u
#define LPI2C_SDER_AVDE_SHIFT                    2
#define LPI2C_SDER_AVDE_WIDTH                    1
#define LPI2C_SDER_AVDE(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SDER_AVDE_SHIFT))&LPI2C_SDER_AVDE_MASK)
/* SCFGR1 Bit Fields */
#define LPI2C_SCFGR1_ADRSTALL_MASK               0x1u
#define LPI2C_SCFGR1_ADRSTALL_SHIFT              0
#define LPI2C_SCFGR1_ADRSTALL_WIDTH              1
#define LPI2C_SCFGR1_ADRSTALL(x)                 (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_ADRSTALL_SHIFT))&LPI2C_SCFGR1_ADRSTALL_MASK)
#define LPI2C_SCFGR1_RXSTALL_MASK                0x2u
#define LPI2C_SCFGR1_RXSTALL_SHIFT               1
#define LPI2C_SCFGR1_RXSTALL_WIDTH               1
#define LPI2C_SCFGR1_RXSTALL(x)                  (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_RXSTALL_SHIFT))&LPI2C_SCFGR1_RXSTALL_MASK)
#define LPI2C_SCFGR1_TXDSTALL_MASK               0x4u
#define LPI2C_SCFGR1_TXDSTALL_SHIFT              2
#define LPI2C_SCFGR1_TXDSTALL_WIDTH              1
#define LPI2C_SCFGR1_TXDSTALL(x)                 (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_TXDSTALL_SHIFT))&LPI2C_SCFGR1_TXDSTALL_MASK)
#define LPI2C_SCFGR1_ACKSTALL_MASK               0x8u
#define LPI2C_SCFGR1_ACKSTALL_SHIFT              3
#define LPI2C_SCFGR1_ACKSTALL_WIDTH              1
#define LPI2C_SCFGR1_ACKSTALL(x)                 (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_ACKSTALL_SHIFT))&LPI2C_SCFGR1_ACKSTALL_MASK)
#define LPI2C_SCFGR1_GCEN_MASK                   0x100u
#define LPI2C_SCFGR1_GCEN_SHIFT                  8
#define LPI2C_SCFGR1_GCEN_WIDTH                  1
#define LPI2C_SCFGR1_GCEN(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_GCEN_SHIFT))&LPI2C_SCFGR1_GCEN_MASK)
#define LPI2C_SCFGR1_SAEN_MASK                   0x200u
#define LPI2C_SCFGR1_SAEN_SHIFT                  9
#define LPI2C_SCFGR1_SAEN_WIDTH                  1
#define LPI2C_SCFGR1_SAEN(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_SAEN_SHIFT))&LPI2C_SCFGR1_SAEN_MASK)
#define LPI2C_SCFGR1_TXCFG_MASK                  0x400u
#define LPI2C_SCFGR1_TXCFG_SHIFT                 10
#define LPI2C_SCFGR1_TXCFG_WIDTH                 1
#define LPI2C_SCFGR1_TXCFG(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_TXCFG_SHIFT))&LPI2C_SCFGR1_TXCFG_MASK)
#define LPI2C_SCFGR1_RXCFG_MASK                  0x800u
#define LPI2C_SCFGR1_RXCFG_SHIFT                 11
#define LPI2C_SCFGR1_RXCFG_WIDTH                 1
#define LPI2C_SCFGR1_RXCFG(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_RXCFG_SHIFT))&LPI2C_SCFGR1_RXCFG_MASK)
#define LPI2C_SCFGR1_IGNACK_MASK                 0x1000u
#define LPI2C_SCFGR1_IGNACK_SHIFT                12
#define LPI2C_SCFGR1_IGNACK_WIDTH                1
#define LPI2C_SCFGR1_IGNACK(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_IGNACK_SHIFT))&LPI2C_SCFGR1_IGNACK_MASK)
#define LPI2C_SCFGR1_HSMEN_MASK                  0x2000u
#define LPI2C_SCFGR1_HSMEN_SHIFT                 13
#define LPI2C_SCFGR1_HSMEN_WIDTH                 1
#define LPI2C_SCFGR1_HSMEN(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_HSMEN_SHIFT))&LPI2C_SCFGR1_HSMEN_MASK)
#define LPI2C_SCFGR1_ADDRCFG_MASK                0x70000u
#define LPI2C_SCFGR1_ADDRCFG_SHIFT               16
#define LPI2C_SCFGR1_ADDRCFG_WIDTH               3
#define LPI2C_SCFGR1_ADDRCFG(x)                  (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR1_ADDRCFG_SHIFT))&LPI2C_SCFGR1_ADDRCFG_MASK)
/* SCFGR2 Bit Fields */
#define LPI2C_SCFGR2_CLKHOLD_MASK                0xFu
#define LPI2C_SCFGR2_CLKHOLD_SHIFT               0
#define LPI2C_SCFGR2_CLKHOLD_WIDTH               4
#define LPI2C_SCFGR2_CLKHOLD(x)                  (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR2_CLKHOLD_SHIFT))&LPI2C_SCFGR2_CLKHOLD_MASK)
#define LPI2C_SCFGR2_DATAVD_MASK                 0x3F00u
#define LPI2C_SCFGR2_DATAVD_SHIFT                8
#define LPI2C_SCFGR2_DATAVD_WIDTH                6
#define LPI2C_SCFGR2_DATAVD(x)                   (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR2_DATAVD_SHIFT))&LPI2C_SCFGR2_DATAVD_MASK)
#define LPI2C_SCFGR2_FILTSCL_MASK                0xF0000u
#define LPI2C_SCFGR2_FILTSCL_SHIFT               16
#define LPI2C_SCFGR2_FILTSCL_WIDTH               4
#define LPI2C_SCFGR2_FILTSCL(x)                  (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR2_FILTSCL_SHIFT))&LPI2C_SCFGR2_FILTSCL_MASK)
#define LPI2C_SCFGR2_FILTSDA_MASK                0xF000000u
#define LPI2C_SCFGR2_FILTSDA_SHIFT               24
#define LPI2C_SCFGR2_FILTSDA_WIDTH               4
#define LPI2C_SCFGR2_FILTSDA(x)                  (((uint32_t)(((uint32_t)(x))<<LPI2C_SCFGR2_FILTSDA_SHIFT))&LPI2C_SCFGR2_FILTSDA_MASK)
/* SAMR Bit Fields */
#define LPI2C_SAMR_ADDR0_MASK                    0x7FEu
#define LPI2C_SAMR_ADDR0_SHIFT                   1
#define LPI2C_SAMR_ADDR0_WIDTH                   10
#define LPI2C_SAMR_ADDR0(x)                      (((uint32_t)(((uint32_t)(x))<<LPI2C_SAMR_ADDR0_SHIFT))&LPI2C_SAMR_ADDR0_MASK)
#define LPI2C_SAMR_ADDR1_MASK                    0x7FE0000u
#define LPI2C_SAMR_ADDR1_SHIFT                   17
#define LPI2C_SAMR_ADDR1_WIDTH                   10
#define LPI2C_SAMR_ADDR1(x)                      (((uint32_t)(((uint32_t)(x))<<LPI2C_SAMR_ADDR1_SHIFT))&LPI2C_SAMR_ADDR1_MASK)
/* SASR Bit Fields */
#define LPI2C_SASR_RADDR_MASK                    0x7FFu
#define LPI2C_SASR_RADDR_SHIFT                   0
#define LPI2C_SASR_RADDR_WIDTH                   11
#define LPI2C_SASR_RADDR(x)                      (((uint32_t)(((uint32_t)(x))<<LPI2C_SASR_RADDR_SHIFT))&LPI2C_SASR_RADDR_MASK)
#define LPI2C_SASR_ANV_MASK                      0x4000u
#define LPI2C_SASR_ANV_SHIFT                     14
#define LPI2C_SASR_ANV_WIDTH                     1
#define LPI2C_SASR_ANV(x)                        (((uint32_t)(((uint32_t)(x))<<LPI2C_SASR_ANV_SHIFT))&LPI2C_SASR_ANV_MASK)
/* STAR Bit Fields */
#define LPI2C_STAR_TXNACK_MASK                   0x1u
#define LPI2C_STAR_TXNACK_SHIFT                  0
#define LPI2C_STAR_TXNACK_WIDTH                  1
#define LPI2C_STAR_TXNACK(x)                     (((uint32_t)(((uint32_t)(x))<<LPI2C_STAR_TXNACK_SHIFT))&LPI2C_STAR_TXNACK_MASK)
/* STDR Bit Fields */
#define LPI2C_STDR_DATA_MASK                     0xFFu
#define LPI2C_STDR_DATA_SHIFT                    0
#define LPI2C_STDR_DATA_WIDTH                    8
#define LPI2C_STDR_DATA(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_STDR_DATA_SHIFT))&LPI2C_STDR_DATA_MASK)
/* SRDR Bit Fields */
#define LPI2C_SRDR_DATA_MASK                     0xFFu
#define LPI2C_SRDR_DATA_SHIFT                    0
#define LPI2C_SRDR_DATA_WIDTH                    8
#define LPI2C_SRDR_DATA(x)                       (((uint32_t)(((uint32_t)(x))<<LPI2C_SRDR_DATA_SHIFT))&LPI2C_SRDR_DATA_MASK)
#define LPI2C_SRDR_RXEMPTY_MASK                  0x4000u
#define LPI2C_SRDR_RXEMPTY_SHIFT                 14
#define LPI2C_SRDR_RXEMPTY_WIDTH                 1
#define LPI2C_SRDR_RXEMPTY(x)                    (((uint32_t)(((uint32_t)(x))<<LPI2C_SRDR_RXEMPTY_SHIFT))&LPI2C_SRDR_RXEMPTY_MASK)
#define LPI2C_SRDR_SOF_MASK                      0x8000u
#define LPI2C_SRDR_SOF_SHIFT                     15
#define LPI2C_SRDR_SOF_WIDTH                     1
#define LPI2C_SRDR_SOF(x)                        (((uint32_t)(((uint32_t)(x))<<LPI2C_SRDR_SOF_SHIFT))&LPI2C_SRDR_SOF_MASK)

/*!
 * @}
 */ /* end of group LPI2C_Register_Masks */


/* LPI2C - Peripheral instance base addresses */
/** Peripheral LPI2C0 base address */
#define LPI2C0_BASE                              (0x40066000u)
/** Peripheral LPI2C0 base pointer */
#define LPI2C0                                   ((LPI2C_Type *)LPI2C0_BASE)
#define LPI2C0_BASE_PTR                          (LPI2C0)
/** Peripheral LPI2C1 base address */
#define LPI2C1_BASE                              (0x40067000u)
/** Peripheral LPI2C1 base pointer */
#define LPI2C1                                   ((LPI2C_Type *)LPI2C1_BASE)
#define LPI2C1_BASE_PTR                          (LPI2C1)
/** Array initializer of LPI2C peripheral base addresses */
#define LPI2C_BASE_ADDRS                         { LPI2C0_BASE, LPI2C1_BASE }
/** Array initializer of LPI2C peripheral base pointers */
#define LPI2C_BASE_PTRS                          { LPI2C0, LPI2C1 }

/* ----------------------------------------------------------------------------
   -- LPI2C - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup LPI2C_Register_Accessor_Macros LPI2C - Register accessor macros
 * @{
 */


/* LPI2C - Register instance definitions */
/* LPI2C0 */
#define LPI2C0_VERID                             LPI2C_VERID_REG(LPI2C0)
#define LPI2C0_PARAM                             LPI2C_PARAM_REG(LPI2C0)
#define LPI2C0_MCR                               LPI2C_MCR_REG(LPI2C0)
#define LPI2C0_MSR                               LPI2C_MSR_REG(LPI2C0)
#define LPI2C0_MIER                              LPI2C_MIER_REG(LPI2C0)
#define LPI2C0_MDER                              LPI2C_MDER_REG(LPI2C0)
#define LPI2C0_MCFGR0                            LPI2C_MCFGR0_REG(LPI2C0)
#define LPI2C0_MCFGR1                            LPI2C_MCFGR1_REG(LPI2C0)
#define LPI2C0_MCFGR2                            LPI2C_MCFGR2_REG(LPI2C0)
#define LPI2C0_MCFGR3                            LPI2C_MCFGR3_REG(LPI2C0)
#define LPI2C0_MDMR                              LPI2C_MDMR_REG(LPI2C0)
#define LPI2C0_MCCR0                             LPI2C_MCCR0_REG(LPI2C0)
#define LPI2C0_MCCR1                             LPI2C_MCCR1_REG(LPI2C0)
#define LPI2C0_MFCR                              LPI2C_MFCR_REG(LPI2C0)
#define LPI2C0_MFSR                              LPI2C_MFSR_REG(LPI2C0)
#define LPI2C0_MTDR                              LPI2C_MTDR_REG(LPI2C0)
#define LPI2C0_MRDR                              LPI2C_MRDR_REG(LPI2C0)
#define LPI2C0_SCR                               LPI2C_SCR_REG(LPI2C0)
#define LPI2C0_SSR                               LPI2C_SSR_REG(LPI2C0)
#define LPI2C0_SIER                              LPI2C_SIER_REG(LPI2C0)
#define LPI2C0_SDER                              LPI2C_SDER_REG(LPI2C0)
#define LPI2C0_SCFGR1                            LPI2C_SCFGR1_REG(LPI2C0)
#define LPI2C0_SCFGR2                            LPI2C_SCFGR2_REG(LPI2C0)
#define LPI2C0_SAMR                              LPI2C_SAMR_REG(LPI2C0)
#define LPI2C0_SASR                              LPI2C_SASR_REG(LPI2C0)
#define LPI2C0_STAR                              LPI2C_STAR_REG(LPI2C0)
#define LPI2C0_STDR                              LPI2C_STDR_REG(LPI2C0)
#define LPI2C0_SRDR                              LPI2C_SRDR_REG(LPI2C0)
/* LPI2C1 */
#define LPI2C1_VERID                             LPI2C_VERID_REG(LPI2C1)
#define LPI2C1_PARAM                             LPI2C_PARAM_REG(LPI2C1)
#define LPI2C1_MCR                               LPI2C_MCR_REG(LPI2C1)
#define LPI2C1_MSR                               LPI2C_MSR_REG(LPI2C1)
#define LPI2C1_MIER                              LPI2C_MIER_REG(LPI2C1)
#define LPI2C1_MDER                              LPI2C_MDER_REG(LPI2C1)
#define LPI2C1_MCFGR0                            LPI2C_MCFGR0_REG(LPI2C1)
#define LPI2C1_MCFGR1                            LPI2C_MCFGR1_REG(LPI2C1)
#define LPI2C1_MCFGR2                            LPI2C_MCFGR2_REG(LPI2C1)
#define LPI2C1_MCFGR3                            LPI2C_MCFGR3_REG(LPI2C1)
#define LPI2C1_MDMR                              LPI2C_MDMR_REG(LPI2C1)
#define LPI2C1_MCCR0                             LPI2C_MCCR0_REG(LPI2C1)
#define LPI2C1_MCCR1                             LPI2C_MCCR1_REG(LPI2C1)
#define LPI2C1_MFCR                              LPI2C_MFCR_REG(LPI2C1)
#define LPI2C1_MFSR                              LPI2C_MFSR_REG(LPI2C1)
#define LPI2C1_MTDR                              LPI2C_MTDR_REG(LPI2C1)
#define LPI2C1_MRDR                              LPI2C_MRDR_REG(LPI2C1)
#define LPI2C1_SCR                               LPI2C_SCR_REG(LPI2C1)
#define LPI2C1_SSR                               LPI2C_SSR_REG(LPI2C1)
#define LPI2C1_SIER                              LPI2C_SIER_REG(LPI2C1)
#define LPI2C1_SDER                              LPI2C_SDER_REG(LPI2C1)
#define LPI2C1_SCFGR1                            LPI2C_SCFGR1_REG(LPI2C1)
#define LPI2C1_SCFGR2                            LPI2C_SCFGR2_REG(LPI2C1)
#define LPI2C1_SAMR                              LPI2C_SAMR_REG(LPI2C1)
#define LPI2C1_SASR                              LPI2C_SASR_REG(LPI2C1)
#define LPI2C1_STAR                              LPI2C_STAR_REG(LPI2C1)
#define LPI2C1_STDR                              LPI2C_STDR_REG(LPI2C1)
#define LPI2C1_SRDR                              LPI2C_SRDR_REG(LPI2C1)

/*!
 * @}
 */ /* end of group LPI2C_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group LPI2C_Peripheral_Access_Layer */
 
 
 /* ----------------------------------------------------------------------------
   -- MCG Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCG_Peripheral_Access_Layer MCG Peripheral Access Layer
 * @{
 */

/** MCG - Register Layout Typedef */
typedef struct {
  __IO uint8_t C1;                                 /**< MCG Control 1 Register, offset: 0x0 */
  __IO uint8_t C2;                                 /**< MCG Control 2 Register, offset: 0x1 */
  __IO uint8_t C3;                                 /**< MCG Control 3 Register, offset: 0x2 */
  __IO uint8_t C4;                                 /**< MCG Control 4 Register, offset: 0x3 */
  __IO uint8_t C5;                                 /**< MCG Control 5 Register, offset: 0x4 */
  __IO uint8_t C6;                                 /**< MCG Control 6 Register, offset: 0x5 */
  __IO uint8_t S;                                  /**< MCG Status Register, offset: 0x6 */
       uint8_t RESERVED_0[1];
  __IO uint8_t SC;                                 /**< MCG Status and Control Register, offset: 0x8 */
       uint8_t RESERVED_1[1];
  __IO uint8_t ATCVH;                              /**< MCG Auto Trim Compare Value High Register, offset: 0xA */
  __IO uint8_t ATCVL;                              /**< MCG Auto Trim Compare Value Low Register, offset: 0xB */
  __IO uint8_t C7;                                 /**< MCG Control 7 Register, offset: 0xC */
  __IO uint8_t C8;                                 /**< MCG Control 8 Register, offset: 0xD */
} MCG_Type, *MCG_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- MCG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCG_Register_Accessor_Macros MCG - Register accessor macros
 * @{
 */


/* MCG - Register accessors */
#define MCG_C1_REG(base)                         ((base)->C1)
#define MCG_C2_REG(base)                         ((base)->C2)
#define MCG_C3_REG(base)                         ((base)->C3)
#define MCG_C4_REG(base)                         ((base)->C4)
#define MCG_C5_REG(base)                         ((base)->C5)
#define MCG_C6_REG(base)                         ((base)->C6)
#define MCG_S_REG(base)                          ((base)->S)
#define MCG_SC_REG(base)                         ((base)->SC)
#define MCG_ATCVH_REG(base)                      ((base)->ATCVH)
#define MCG_ATCVL_REG(base)                      ((base)->ATCVL)
#define MCG_C7_REG(base)                         ((base)->C7)
#define MCG_C8_REG(base)                         ((base)->C8)

/*!
 * @}
 */ /* end of group MCG_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- MCG Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCG_Register_Masks MCG Register Masks
 * @{
 */

/* C1 Bit Fields */
#define MCG_C1_IREFSTEN_MASK                     0x1u
#define MCG_C1_IREFSTEN_SHIFT                    0
#define MCG_C1_IREFSTEN_WIDTH                    1
#define MCG_C1_IREFSTEN(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_C1_IREFSTEN_SHIFT))&MCG_C1_IREFSTEN_MASK)
#define MCG_C1_IRCLKEN_MASK                      0x2u
#define MCG_C1_IRCLKEN_SHIFT                     1
#define MCG_C1_IRCLKEN_WIDTH                     1
#define MCG_C1_IRCLKEN(x)                        (((uint8_t)(((uint8_t)(x))<<MCG_C1_IRCLKEN_SHIFT))&MCG_C1_IRCLKEN_MASK)
#define MCG_C1_IREFS_MASK                        0x4u
#define MCG_C1_IREFS_SHIFT                       2
#define MCG_C1_IREFS_WIDTH                       1
#define MCG_C1_IREFS(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C1_IREFS_SHIFT))&MCG_C1_IREFS_MASK)
#define MCG_C1_FRDIV_MASK                        0x38u
#define MCG_C1_FRDIV_SHIFT                       3
#define MCG_C1_FRDIV_WIDTH                       3
#define MCG_C1_FRDIV(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C1_FRDIV_SHIFT))&MCG_C1_FRDIV_MASK)
#define MCG_C1_CLKS_MASK                         0xC0u
#define MCG_C1_CLKS_SHIFT                        6
#define MCG_C1_CLKS_WIDTH                        2
#define MCG_C1_CLKS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C1_CLKS_SHIFT))&MCG_C1_CLKS_MASK)
/* C2 Bit Fields */
#define MCG_C2_IRCS_MASK                         0x1u
#define MCG_C2_IRCS_SHIFT                        0
#define MCG_C2_IRCS_WIDTH                        1
#define MCG_C2_IRCS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C2_IRCS_SHIFT))&MCG_C2_IRCS_MASK)
#define MCG_C2_LP_MASK                           0x2u
#define MCG_C2_LP_SHIFT                          1
#define MCG_C2_LP_WIDTH                          1
#define MCG_C2_LP(x)                             (((uint8_t)(((uint8_t)(x))<<MCG_C2_LP_SHIFT))&MCG_C2_LP_MASK)
#define MCG_C2_EREFS_MASK                        0x4u
#define MCG_C2_EREFS_SHIFT                       2
#define MCG_C2_EREFS_WIDTH                       1
#define MCG_C2_EREFS(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C2_EREFS_SHIFT))&MCG_C2_EREFS_MASK)
#define MCG_C2_HGO_MASK                          0x8u
#define MCG_C2_HGO_SHIFT                         3
#define MCG_C2_HGO_WIDTH                         1
#define MCG_C2_HGO(x)                            (((uint8_t)(((uint8_t)(x))<<MCG_C2_HGO_SHIFT))&MCG_C2_HGO_MASK)
#define MCG_C2_RANGE_MASK                        0x30u
#define MCG_C2_RANGE_SHIFT                       4
#define MCG_C2_RANGE_WIDTH                       2
#define MCG_C2_RANGE(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C2_RANGE_SHIFT))&MCG_C2_RANGE_MASK)
#define MCG_C2_FCFTRIM_MASK                      0x40u
#define MCG_C2_FCFTRIM_SHIFT                     6
#define MCG_C2_FCFTRIM_WIDTH                     1
#define MCG_C2_FCFTRIM(x)                        (((uint8_t)(((uint8_t)(x))<<MCG_C2_FCFTRIM_SHIFT))&MCG_C2_FCFTRIM_MASK)
#define MCG_C2_LOCRE0_MASK                       0x80u
#define MCG_C2_LOCRE0_SHIFT                      7
#define MCG_C2_LOCRE0_WIDTH                      1
#define MCG_C2_LOCRE0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C2_LOCRE0_SHIFT))&MCG_C2_LOCRE0_MASK)
/* C3 Bit Fields */
#define MCG_C3_SCTRIM_MASK                       0xFFu
#define MCG_C3_SCTRIM_SHIFT                      0
#define MCG_C3_SCTRIM_WIDTH                      8
#define MCG_C3_SCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C3_SCTRIM_SHIFT))&MCG_C3_SCTRIM_MASK)
/* C4 Bit Fields */
#define MCG_C4_SCFTRIM_MASK                      0x1u
#define MCG_C4_SCFTRIM_SHIFT                     0
#define MCG_C4_SCFTRIM_WIDTH                     1
#define MCG_C4_SCFTRIM(x)                        (((uint8_t)(((uint8_t)(x))<<MCG_C4_SCFTRIM_SHIFT))&MCG_C4_SCFTRIM_MASK)
#define MCG_C4_FCTRIM_MASK                       0x1Eu
#define MCG_C4_FCTRIM_SHIFT                      1
#define MCG_C4_FCTRIM_WIDTH                      4
#define MCG_C4_FCTRIM(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C4_FCTRIM_SHIFT))&MCG_C4_FCTRIM_MASK)
#define MCG_C4_DRST_DRS_MASK                     0x60u
#define MCG_C4_DRST_DRS_SHIFT                    5
#define MCG_C4_DRST_DRS_WIDTH                    2
#define MCG_C4_DRST_DRS(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_C4_DRST_DRS_SHIFT))&MCG_C4_DRST_DRS_MASK)
#define MCG_C4_DMX32_MASK                        0x80u
#define MCG_C4_DMX32_SHIFT                       7
#define MCG_C4_DMX32_WIDTH                       1
#define MCG_C4_DMX32(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C4_DMX32_SHIFT))&MCG_C4_DMX32_MASK)
/* C5 Bit Fields */
#define MCG_C5_PRDIV0_MASK                       0x1Fu
#define MCG_C5_PRDIV0_SHIFT                      0
#define MCG_C5_PRDIV0_WIDTH                      5
#define MCG_C5_PRDIV0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C5_PRDIV0_SHIFT))&MCG_C5_PRDIV0_MASK)
#define MCG_C5_PLLSTEN0_MASK                     0x20u
#define MCG_C5_PLLSTEN0_SHIFT                    5
#define MCG_C5_PLLSTEN0_WIDTH                    1
#define MCG_C5_PLLSTEN0(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_C5_PLLSTEN0_SHIFT))&MCG_C5_PLLSTEN0_MASK)
#define MCG_C5_PLLCLKEN0_MASK                    0x40u
#define MCG_C5_PLLCLKEN0_SHIFT                   6
#define MCG_C5_PLLCLKEN0_WIDTH                   1
#define MCG_C5_PLLCLKEN0(x)                      (((uint8_t)(((uint8_t)(x))<<MCG_C5_PLLCLKEN0_SHIFT))&MCG_C5_PLLCLKEN0_MASK)
/* C6 Bit Fields */
#define MCG_C6_VDIV0_MASK                        0x1Fu
#define MCG_C6_VDIV0_SHIFT                       0
#define MCG_C6_VDIV0_WIDTH                       5
#define MCG_C6_VDIV0(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C6_VDIV0_SHIFT))&MCG_C6_VDIV0_MASK)
#define MCG_C6_CME0_MASK                         0x20u
#define MCG_C6_CME0_SHIFT                        5
#define MCG_C6_CME0_WIDTH                        1
#define MCG_C6_CME0(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C6_CME0_SHIFT))&MCG_C6_CME0_MASK)
#define MCG_C6_PLLS_MASK                         0x40u
#define MCG_C6_PLLS_SHIFT                        6
#define MCG_C6_PLLS_WIDTH                        1
#define MCG_C6_PLLS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C6_PLLS_SHIFT))&MCG_C6_PLLS_MASK)
#define MCG_C6_LOLIE0_MASK                       0x80u
#define MCG_C6_LOLIE0_SHIFT                      7
#define MCG_C6_LOLIE0_WIDTH                      1
#define MCG_C6_LOLIE0(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C6_LOLIE0_SHIFT))&MCG_C6_LOLIE0_MASK)
/* S Bit Fields */
#define MCG_S_IRCST_MASK                         0x1u
#define MCG_S_IRCST_SHIFT                        0
#define MCG_S_IRCST_WIDTH                        1
#define MCG_S_IRCST(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_IRCST_SHIFT))&MCG_S_IRCST_MASK)
#define MCG_S_OSCINIT0_MASK                      0x2u
#define MCG_S_OSCINIT0_SHIFT                     1
#define MCG_S_OSCINIT0_WIDTH                     1
#define MCG_S_OSCINIT0(x)                        (((uint8_t)(((uint8_t)(x))<<MCG_S_OSCINIT0_SHIFT))&MCG_S_OSCINIT0_MASK)
#define MCG_S_CLKST_MASK                         0xCu
#define MCG_S_CLKST_SHIFT                        2
#define MCG_S_CLKST_WIDTH                        2
#define MCG_S_CLKST(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_CLKST_SHIFT))&MCG_S_CLKST_MASK)
#define MCG_S_IREFST_MASK                        0x10u
#define MCG_S_IREFST_SHIFT                       4
#define MCG_S_IREFST_WIDTH                       1
#define MCG_S_IREFST(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_S_IREFST_SHIFT))&MCG_S_IREFST_MASK)
#define MCG_S_PLLST_MASK                         0x20u
#define MCG_S_PLLST_SHIFT                        5
#define MCG_S_PLLST_WIDTH                        1
#define MCG_S_PLLST(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_PLLST_SHIFT))&MCG_S_PLLST_MASK)
#define MCG_S_LOCK0_MASK                         0x40u
#define MCG_S_LOCK0_SHIFT                        6
#define MCG_S_LOCK0_WIDTH                        1
#define MCG_S_LOCK0(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_LOCK0_SHIFT))&MCG_S_LOCK0_MASK)
#define MCG_S_LOLS0_MASK                         0x80u
#define MCG_S_LOLS0_SHIFT                        7
#define MCG_S_LOLS0_WIDTH                        1
#define MCG_S_LOLS0(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_S_LOLS0_SHIFT))&MCG_S_LOLS0_MASK)
/* SC Bit Fields */
#define MCG_SC_LOCS0_MASK                        0x1u
#define MCG_SC_LOCS0_SHIFT                       0
#define MCG_SC_LOCS0_WIDTH                       1
#define MCG_SC_LOCS0(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_SC_LOCS0_SHIFT))&MCG_SC_LOCS0_MASK)
#define MCG_SC_FCRDIV_MASK                       0xEu
#define MCG_SC_FCRDIV_SHIFT                      1
#define MCG_SC_FCRDIV_WIDTH                      3
#define MCG_SC_FCRDIV(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_SC_FCRDIV_SHIFT))&MCG_SC_FCRDIV_MASK)
#define MCG_SC_FLTPRSRV_MASK                     0x10u
#define MCG_SC_FLTPRSRV_SHIFT                    4
#define MCG_SC_FLTPRSRV_WIDTH                    1
#define MCG_SC_FLTPRSRV(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_SC_FLTPRSRV_SHIFT))&MCG_SC_FLTPRSRV_MASK)
#define MCG_SC_ATMF_MASK                         0x20u
#define MCG_SC_ATMF_SHIFT                        5
#define MCG_SC_ATMF_WIDTH                        1
#define MCG_SC_ATMF(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_SC_ATMF_SHIFT))&MCG_SC_ATMF_MASK)
#define MCG_SC_ATMS_MASK                         0x40u
#define MCG_SC_ATMS_SHIFT                        6
#define MCG_SC_ATMS_WIDTH                        1
#define MCG_SC_ATMS(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_SC_ATMS_SHIFT))&MCG_SC_ATMS_MASK)
#define MCG_SC_ATME_MASK                         0x80u
#define MCG_SC_ATME_SHIFT                        7
#define MCG_SC_ATME_WIDTH                        1
#define MCG_SC_ATME(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_SC_ATME_SHIFT))&MCG_SC_ATME_MASK)
/* ATCVH Bit Fields */
#define MCG_ATCVH_ATCVH_MASK                     0xFFu
#define MCG_ATCVH_ATCVH_SHIFT                    0
#define MCG_ATCVH_ATCVH_WIDTH                    8
#define MCG_ATCVH_ATCVH(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_ATCVH_ATCVH_SHIFT))&MCG_ATCVH_ATCVH_MASK)
/* ATCVL Bit Fields */
#define MCG_ATCVL_ATCVL_MASK                     0xFFu
#define MCG_ATCVL_ATCVL_SHIFT                    0
#define MCG_ATCVL_ATCVL_WIDTH                    8
#define MCG_ATCVL_ATCVL(x)                       (((uint8_t)(((uint8_t)(x))<<MCG_ATCVL_ATCVL_SHIFT))&MCG_ATCVL_ATCVL_MASK)
/* C7 Bit Fields */
#define MCG_C7_OSCSEL_MASK                       0x3u
#define MCG_C7_OSCSEL_SHIFT                      0
#define MCG_C7_OSCSEL_WIDTH                      2
#define MCG_C7_OSCSEL(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C7_OSCSEL_SHIFT))&MCG_C7_OSCSEL_MASK)
/* C8 Bit Fields */
#define MCG_C8_LOCS1_MASK                        0x1u
#define MCG_C8_LOCS1_SHIFT                       0
#define MCG_C8_LOCS1_WIDTH                       1
#define MCG_C8_LOCS1(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C8_LOCS1_SHIFT))&MCG_C8_LOCS1_MASK)
#define MCG_C8_CME1_MASK                         0x20u
#define MCG_C8_CME1_SHIFT                        5
#define MCG_C8_CME1_WIDTH                        1
#define MCG_C8_CME1(x)                           (((uint8_t)(((uint8_t)(x))<<MCG_C8_CME1_SHIFT))&MCG_C8_CME1_MASK)
#define MCG_C8_LOLRE_MASK                        0x40u
#define MCG_C8_LOLRE_SHIFT                       6
#define MCG_C8_LOLRE_WIDTH                       1
#define MCG_C8_LOLRE(x)                          (((uint8_t)(((uint8_t)(x))<<MCG_C8_LOLRE_SHIFT))&MCG_C8_LOLRE_MASK)
#define MCG_C8_LOCRE1_MASK                       0x80u
#define MCG_C8_LOCRE1_SHIFT                      7
#define MCG_C8_LOCRE1_WIDTH                      1
#define MCG_C8_LOCRE1(x)                         (((uint8_t)(((uint8_t)(x))<<MCG_C8_LOCRE1_SHIFT))&MCG_C8_LOCRE1_MASK)

/*!
 * @}
 */ /* end of group MCG_Register_Masks */


/* MCG - Peripheral instance base addresses */
/** Peripheral MCG base address */
#define MCG_BASE                                 (0x40064000u)
/** Peripheral MCG base pointer */
#define MCG                                      ((MCG_Type *)MCG_BASE)
#define MCG_BASE_PTR                             (MCG)
/** Array initializer of MCG peripheral base addresses */
#define MCG_BASE_ADDRS                           { MCG_BASE }
/** Array initializer of MCG peripheral base pointers */
#define MCG_BASE_PTRS                            { MCG }

/* ----------------------------------------------------------------------------
   -- MCG - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MCG_Register_Accessor_Macros MCG - Register accessor macros
 * @{
 */


/* MCG - Register instance definitions */
/* MCG */
#define MCG_C1                                   MCG_C1_REG(MCG)
#define MCG_C2                                   MCG_C2_REG(MCG)
#define MCG_C3                                   MCG_C3_REG(MCG)
#define MCG_C4                                   MCG_C4_REG(MCG)
#define MCG_C5                                   MCG_C5_REG(MCG)
#define MCG_C6                                   MCG_C6_REG(MCG)
#define MCG_S                                    MCG_S_REG(MCG)
#define MCG_SC                                   MCG_SC_REG(MCG)
#define MCG_ATCVH                                MCG_ATCVH_REG(MCG)
#define MCG_ATCVL                                MCG_ATCVL_REG(MCG)
#define MCG_C7                                   MCG_C7_REG(MCG)
#define MCG_C8                                   MCG_C8_REG(MCG)

/*!
 * @}
 */ /* end of group MCG_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group MCG_Peripheral_Access_Layer */
 
 
 #define PORTE                                    ((PORT_Type *)PORTE_BASE)
 #define PORT_PCR_MUX_MASK                        0xF00u
#define PORT_PCR_ISF_MASK                        0x1000000u
#define PTE                                      ((GPIO_Type *)PTE_BASE)
#define SIM_UIDMH                                SIM_UIDMH_REG(SIM)


/* ----------------------------------------------------------------------------
   -- CAN Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_Peripheral_Access_Layer CAN Peripheral Access Layer
 * @{
 */

/** CAN - Register Layout Typedef */
typedef struct {
  __IO uint32_t MCR;                               /**< Module Configuration Register, offset: 0x0 */
  __IO uint32_t CTRL1;                             /**< Control 1 register, offset: 0x4 */
  __IO uint32_t TIMER;                             /**< Free Running Timer, offset: 0x8 */
       uint8_t RESERVED_0[4];
  __IO uint32_t RXMGMASK;                          /**< Rx Mailboxes Global Mask Register, offset: 0x10 */
  __IO uint32_t RX14MASK;                          /**< Rx 14 Mask register, offset: 0x14 */
  __IO uint32_t RX15MASK;                          /**< Rx 15 Mask register, offset: 0x18 */
  __IO uint32_t ECR;                               /**< Error Counter, offset: 0x1C */
  __IO uint32_t ESR1;                              /**< Error and Status 1 register, offset: 0x20 */
       uint8_t RESERVED_1[4];
  __IO uint32_t IMASK1;                            /**< Interrupt Masks 1 register, offset: 0x28 */
       uint8_t RESERVED_2[4];
  __IO uint32_t IFLAG1;                            /**< Interrupt Flags 1 register, offset: 0x30 */
  __IO uint32_t CTRL2;                             /**< Control 2 register, offset: 0x34 */
  __I  uint32_t ESR2;                              /**< Error and Status 2 register, offset: 0x38 */
       uint8_t RESERVED_3[8];
  __I  uint32_t CRCR;                              /**< CRC Register, offset: 0x44 */
  __IO uint32_t RXFGMASK;                          /**< Rx FIFO Global Mask register, offset: 0x48 */
  __I  uint32_t RXFIR;                             /**< Rx FIFO Information Register, offset: 0x4C */
  __IO uint32_t CBT;                               /**< CAN Bit Timing Register, offset: 0x50 */
       uint8_t RESERVED_4[44];
  struct {                                         /* offset: 0x80, array step: 0x10 */
    __IO uint32_t CS;                                /**< Message Buffer 0 CS Register..Message Buffer 15 CS Register, array offset: 0x80, array step: 0x10 */
    __IO uint32_t ID;                                /**< Message Buffer 0 ID Register..Message Buffer 15 ID Register, array offset: 0x84, array step: 0x10 */
    __IO uint32_t WORD0;                             /**< Message Buffer 0 WORD0 Register..Message Buffer 15 WORD0 Register, array offset: 0x88, array step: 0x10 */
    __IO uint32_t WORD1;                             /**< Message Buffer 0 WORD1 Register..Message Buffer 15 WORD1 Register, array offset: 0x8C, array step: 0x10 */
  } MB[16];
       uint8_t RESERVED_5[1792];
  __IO uint32_t RXIMR[16];                         /**< Rx Individual Mask Registers, array offset: 0x880, array step: 0x4 */
} CAN_Type, *CAN_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CAN - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_Register_Accessor_Macros CAN - Register accessor macros
 * @{
 */


/* CAN - Register accessors */
#define CAN_MCR_REG(base)                        ((base)->MCR)
#define CAN_CTRL1_REG(base)                      ((base)->CTRL1)
#define CAN_TIMER_REG(base)                      ((base)->TIMER)
#define CAN_RXMGMASK_REG(base)                   ((base)->RXMGMASK)
#define CAN_RX14MASK_REG(base)                   ((base)->RX14MASK)
#define CAN_RX15MASK_REG(base)                   ((base)->RX15MASK)
#define CAN_ECR_REG(base)                        ((base)->ECR)
#define CAN_ESR1_REG(base)                       ((base)->ESR1)
#define CAN_IMASK1_REG(base)                     ((base)->IMASK1)
#define CAN_IFLAG1_REG(base)                     ((base)->IFLAG1)
#define CAN_CTRL2_REG(base)                      ((base)->CTRL2)
#define CAN_ESR2_REG(base)                       ((base)->ESR2)
#define CAN_CRCR_REG(base)                       ((base)->CRCR)
#define CAN_RXFGMASK_REG(base)                   ((base)->RXFGMASK)
#define CAN_RXFIR_REG(base)                      ((base)->RXFIR)
#define CAN_CBT_REG(base)                        ((base)->CBT)
#define CAN_CS_REG(base,index)                   ((base)->MB[index].CS)
#define CAN_CS_COUNT                             16
#define CAN_ID_REG(base,index)                   ((base)->MB[index].ID)
#define CAN_ID_COUNT                             16
#define CAN_WORD0_REG(base,index)                ((base)->MB[index].WORD0)
#define CAN_WORD0_COUNT                          16
#define CAN_WORD1_REG(base,index)                ((base)->MB[index].WORD1)
#define CAN_WORD1_COUNT                          16
#define CAN_RXIMR_REG(base,index)                ((base)->RXIMR[index])
#define CAN_RXIMR_COUNT                          16

/*!
 * @}
 */ /* end of group CAN_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CAN Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_Register_Masks CAN Register Masks
 * @{
 */

/* MCR Bit Fields */
#define CAN_MCR_MAXMB_MASK                       0x7Fu
#define CAN_MCR_MAXMB_SHIFT                      0
#define CAN_MCR_MAXMB_WIDTH                      7
#define CAN_MCR_MAXMB(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_MCR_MAXMB_SHIFT))&CAN_MCR_MAXMB_MASK)
#define CAN_MCR_IDAM_MASK                        0x300u
#define CAN_MCR_IDAM_SHIFT                       8
#define CAN_MCR_IDAM_WIDTH                       2
#define CAN_MCR_IDAM(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_MCR_IDAM_SHIFT))&CAN_MCR_IDAM_MASK)
#define CAN_MCR_AEN_MASK                         0x1000u
#define CAN_MCR_AEN_SHIFT                        12
#define CAN_MCR_AEN_WIDTH                        1
#define CAN_MCR_AEN(x)                           (((uint32_t)(((uint32_t)(x))<<CAN_MCR_AEN_SHIFT))&CAN_MCR_AEN_MASK)
#define CAN_MCR_LPRIOEN_MASK                     0x2000u
#define CAN_MCR_LPRIOEN_SHIFT                    13
#define CAN_MCR_LPRIOEN_WIDTH                    1
#define CAN_MCR_LPRIOEN(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_MCR_LPRIOEN_SHIFT))&CAN_MCR_LPRIOEN_MASK)
#define CAN_MCR_DMA_MASK                         0x8000u
#define CAN_MCR_DMA_SHIFT                        15
#define CAN_MCR_DMA_WIDTH                        1
#define CAN_MCR_DMA(x)                           (((uint32_t)(((uint32_t)(x))<<CAN_MCR_DMA_SHIFT))&CAN_MCR_DMA_MASK)
#define CAN_MCR_IRMQ_MASK                        0x10000u
#define CAN_MCR_IRMQ_SHIFT                       16
#define CAN_MCR_IRMQ_WIDTH                       1
#define CAN_MCR_IRMQ(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_MCR_IRMQ_SHIFT))&CAN_MCR_IRMQ_MASK)
#define CAN_MCR_SRXDIS_MASK                      0x20000u
#define CAN_MCR_SRXDIS_SHIFT                     17
#define CAN_MCR_SRXDIS_WIDTH                     1
#define CAN_MCR_SRXDIS(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_MCR_SRXDIS_SHIFT))&CAN_MCR_SRXDIS_MASK)
#define CAN_MCR_DOZE_MASK                        0x40000u
#define CAN_MCR_DOZE_SHIFT                       18
#define CAN_MCR_DOZE_WIDTH                       1
#define CAN_MCR_DOZE(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_MCR_DOZE_SHIFT))&CAN_MCR_DOZE_MASK)
#define CAN_MCR_WAKSRC_MASK                      0x80000u
#define CAN_MCR_WAKSRC_SHIFT                     19
#define CAN_MCR_WAKSRC_WIDTH                     1
#define CAN_MCR_WAKSRC(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_MCR_WAKSRC_SHIFT))&CAN_MCR_WAKSRC_MASK)
#define CAN_MCR_LPMACK_MASK                      0x100000u
#define CAN_MCR_LPMACK_SHIFT                     20
#define CAN_MCR_LPMACK_WIDTH                     1
#define CAN_MCR_LPMACK(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_MCR_LPMACK_SHIFT))&CAN_MCR_LPMACK_MASK)
#define CAN_MCR_WRNEN_MASK                       0x200000u
#define CAN_MCR_WRNEN_SHIFT                      21
#define CAN_MCR_WRNEN_WIDTH                      1
#define CAN_MCR_WRNEN(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_MCR_WRNEN_SHIFT))&CAN_MCR_WRNEN_MASK)
#define CAN_MCR_SLFWAK_MASK                      0x400000u
#define CAN_MCR_SLFWAK_SHIFT                     22
#define CAN_MCR_SLFWAK_WIDTH                     1
#define CAN_MCR_SLFWAK(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_MCR_SLFWAK_SHIFT))&CAN_MCR_SLFWAK_MASK)
#define CAN_MCR_SUPV_MASK                        0x800000u
#define CAN_MCR_SUPV_SHIFT                       23
#define CAN_MCR_SUPV_WIDTH                       1
#define CAN_MCR_SUPV(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_MCR_SUPV_SHIFT))&CAN_MCR_SUPV_MASK)
#define CAN_MCR_FRZACK_MASK                      0x1000000u
#define CAN_MCR_FRZACK_SHIFT                     24
#define CAN_MCR_FRZACK_WIDTH                     1
#define CAN_MCR_FRZACK(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_MCR_FRZACK_SHIFT))&CAN_MCR_FRZACK_MASK)
#define CAN_MCR_SOFTRST_MASK                     0x2000000u
#define CAN_MCR_SOFTRST_SHIFT                    25
#define CAN_MCR_SOFTRST_WIDTH                    1
#define CAN_MCR_SOFTRST(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_MCR_SOFTRST_SHIFT))&CAN_MCR_SOFTRST_MASK)
#define CAN_MCR_WAKMSK_MASK                      0x4000000u
#define CAN_MCR_WAKMSK_SHIFT                     26
#define CAN_MCR_WAKMSK_WIDTH                     1
#define CAN_MCR_WAKMSK(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_MCR_WAKMSK_SHIFT))&CAN_MCR_WAKMSK_MASK)
#define CAN_MCR_NOTRDY_MASK                      0x8000000u
#define CAN_MCR_NOTRDY_SHIFT                     27
#define CAN_MCR_NOTRDY_WIDTH                     1
#define CAN_MCR_NOTRDY(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_MCR_NOTRDY_SHIFT))&CAN_MCR_NOTRDY_MASK)
#define CAN_MCR_HALT_MASK                        0x10000000u
#define CAN_MCR_HALT_SHIFT                       28
#define CAN_MCR_HALT_WIDTH                       1
#define CAN_MCR_HALT(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_MCR_HALT_SHIFT))&CAN_MCR_HALT_MASK)
#define CAN_MCR_RFEN_MASK                        0x20000000u
#define CAN_MCR_RFEN_SHIFT                       29
#define CAN_MCR_RFEN_WIDTH                       1
#define CAN_MCR_RFEN(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_MCR_RFEN_SHIFT))&CAN_MCR_RFEN_MASK)
#define CAN_MCR_FRZ_MASK                         0x40000000u
#define CAN_MCR_FRZ_SHIFT                        30
#define CAN_MCR_FRZ_WIDTH                        1
#define CAN_MCR_FRZ(x)                           (((uint32_t)(((uint32_t)(x))<<CAN_MCR_FRZ_SHIFT))&CAN_MCR_FRZ_MASK)
#define CAN_MCR_MDIS_MASK                        0x80000000u
#define CAN_MCR_MDIS_SHIFT                       31
#define CAN_MCR_MDIS_WIDTH                       1
#define CAN_MCR_MDIS(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_MCR_MDIS_SHIFT))&CAN_MCR_MDIS_MASK)
/* CTRL1 Bit Fields */
#define CAN_CTRL1_PROPSEG_MASK                   0x7u
#define CAN_CTRL1_PROPSEG_SHIFT                  0
#define CAN_CTRL1_PROPSEG_WIDTH                  3
#define CAN_CTRL1_PROPSEG(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_PROPSEG_SHIFT))&CAN_CTRL1_PROPSEG_MASK)
#define CAN_CTRL1_LOM_MASK                       0x8u
#define CAN_CTRL1_LOM_SHIFT                      3
#define CAN_CTRL1_LOM_WIDTH                      1
#define CAN_CTRL1_LOM(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_LOM_SHIFT))&CAN_CTRL1_LOM_MASK)
#define CAN_CTRL1_LBUF_MASK                      0x10u
#define CAN_CTRL1_LBUF_SHIFT                     4
#define CAN_CTRL1_LBUF_WIDTH                     1
#define CAN_CTRL1_LBUF(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_LBUF_SHIFT))&CAN_CTRL1_LBUF_MASK)
#define CAN_CTRL1_TSYN_MASK                      0x20u
#define CAN_CTRL1_TSYN_SHIFT                     5
#define CAN_CTRL1_TSYN_WIDTH                     1
#define CAN_CTRL1_TSYN(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_TSYN_SHIFT))&CAN_CTRL1_TSYN_MASK)
#define CAN_CTRL1_BOFFREC_MASK                   0x40u
#define CAN_CTRL1_BOFFREC_SHIFT                  6
#define CAN_CTRL1_BOFFREC_WIDTH                  1
#define CAN_CTRL1_BOFFREC(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_BOFFREC_SHIFT))&CAN_CTRL1_BOFFREC_MASK)
#define CAN_CTRL1_SMP_MASK                       0x80u
#define CAN_CTRL1_SMP_SHIFT                      7
#define CAN_CTRL1_SMP_WIDTH                      1
#define CAN_CTRL1_SMP(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_SMP_SHIFT))&CAN_CTRL1_SMP_MASK)
#define CAN_CTRL1_RWRNMSK_MASK                   0x400u
#define CAN_CTRL1_RWRNMSK_SHIFT                  10
#define CAN_CTRL1_RWRNMSK_WIDTH                  1
#define CAN_CTRL1_RWRNMSK(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_RWRNMSK_SHIFT))&CAN_CTRL1_RWRNMSK_MASK)
#define CAN_CTRL1_TWRNMSK_MASK                   0x800u
#define CAN_CTRL1_TWRNMSK_SHIFT                  11
#define CAN_CTRL1_TWRNMSK_WIDTH                  1
#define CAN_CTRL1_TWRNMSK(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_TWRNMSK_SHIFT))&CAN_CTRL1_TWRNMSK_MASK)
#define CAN_CTRL1_LPB_MASK                       0x1000u
#define CAN_CTRL1_LPB_SHIFT                      12
#define CAN_CTRL1_LPB_WIDTH                      1
#define CAN_CTRL1_LPB(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_LPB_SHIFT))&CAN_CTRL1_LPB_MASK)
#define CAN_CTRL1_CLKSRC_MASK                    0x2000u
#define CAN_CTRL1_CLKSRC_SHIFT                   13
#define CAN_CTRL1_CLKSRC_WIDTH                   1
#define CAN_CTRL1_CLKSRC(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_CLKSRC_SHIFT))&CAN_CTRL1_CLKSRC_MASK)
#define CAN_CTRL1_ERRMSK_MASK                    0x4000u
#define CAN_CTRL1_ERRMSK_SHIFT                   14
#define CAN_CTRL1_ERRMSK_WIDTH                   1
#define CAN_CTRL1_ERRMSK(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_ERRMSK_SHIFT))&CAN_CTRL1_ERRMSK_MASK)
#define CAN_CTRL1_BOFFMSK_MASK                   0x8000u
#define CAN_CTRL1_BOFFMSK_SHIFT                  15
#define CAN_CTRL1_BOFFMSK_WIDTH                  1
#define CAN_CTRL1_BOFFMSK(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_BOFFMSK_SHIFT))&CAN_CTRL1_BOFFMSK_MASK)
#define CAN_CTRL1_PSEG2_MASK                     0x70000u
#define CAN_CTRL1_PSEG2_SHIFT                    16
#define CAN_CTRL1_PSEG2_WIDTH                    3
#define CAN_CTRL1_PSEG2(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_PSEG2_SHIFT))&CAN_CTRL1_PSEG2_MASK)
#define CAN_CTRL1_PSEG1_MASK                     0x380000u
#define CAN_CTRL1_PSEG1_SHIFT                    19
#define CAN_CTRL1_PSEG1_WIDTH                    3
#define CAN_CTRL1_PSEG1(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_PSEG1_SHIFT))&CAN_CTRL1_PSEG1_MASK)
#define CAN_CTRL1_RJW_MASK                       0xC00000u
#define CAN_CTRL1_RJW_SHIFT                      22
#define CAN_CTRL1_RJW_WIDTH                      2
#define CAN_CTRL1_RJW(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_RJW_SHIFT))&CAN_CTRL1_RJW_MASK)
#define CAN_CTRL1_PRESDIV_MASK                   0xFF000000u
#define CAN_CTRL1_PRESDIV_SHIFT                  24
#define CAN_CTRL1_PRESDIV_WIDTH                  8
#define CAN_CTRL1_PRESDIV(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CTRL1_PRESDIV_SHIFT))&CAN_CTRL1_PRESDIV_MASK)
/* TIMER Bit Fields */
#define CAN_TIMER_TIMER_MASK                     0xFFFFu
#define CAN_TIMER_TIMER_SHIFT                    0
#define CAN_TIMER_TIMER_WIDTH                    16
#define CAN_TIMER_TIMER(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_TIMER_TIMER_SHIFT))&CAN_TIMER_TIMER_MASK)
/* RXMGMASK Bit Fields */
#define CAN_RXMGMASK_MG_MASK                     0xFFFFFFFFu
#define CAN_RXMGMASK_MG_SHIFT                    0
#define CAN_RXMGMASK_MG_WIDTH                    32
#define CAN_RXMGMASK_MG(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_RXMGMASK_MG_SHIFT))&CAN_RXMGMASK_MG_MASK)
/* RX14MASK Bit Fields */
#define CAN_RX14MASK_RX14M_MASK                  0xFFFFFFFFu
#define CAN_RX14MASK_RX14M_SHIFT                 0
#define CAN_RX14MASK_RX14M_WIDTH                 32
#define CAN_RX14MASK_RX14M(x)                    (((uint32_t)(((uint32_t)(x))<<CAN_RX14MASK_RX14M_SHIFT))&CAN_RX14MASK_RX14M_MASK)
/* RX15MASK Bit Fields */
#define CAN_RX15MASK_RX15M_MASK                  0xFFFFFFFFu
#define CAN_RX15MASK_RX15M_SHIFT                 0
#define CAN_RX15MASK_RX15M_WIDTH                 32
#define CAN_RX15MASK_RX15M(x)                    (((uint32_t)(((uint32_t)(x))<<CAN_RX15MASK_RX15M_SHIFT))&CAN_RX15MASK_RX15M_MASK)
/* ECR Bit Fields */
#define CAN_ECR_TXERRCNT_MASK                    0xFFu
#define CAN_ECR_TXERRCNT_SHIFT                   0
#define CAN_ECR_TXERRCNT_WIDTH                   8
#define CAN_ECR_TXERRCNT(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ECR_TXERRCNT_SHIFT))&CAN_ECR_TXERRCNT_MASK)
#define CAN_ECR_RXERRCNT_MASK                    0xFF00u
#define CAN_ECR_RXERRCNT_SHIFT                   8
#define CAN_ECR_RXERRCNT_WIDTH                   8
#define CAN_ECR_RXERRCNT(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ECR_RXERRCNT_SHIFT))&CAN_ECR_RXERRCNT_MASK)
/* ESR1 Bit Fields */
#define CAN_ESR1_WAKINT_MASK                     0x1u
#define CAN_ESR1_WAKINT_SHIFT                    0
#define CAN_ESR1_WAKINT_WIDTH                    1
#define CAN_ESR1_WAKINT(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_WAKINT_SHIFT))&CAN_ESR1_WAKINT_MASK)
#define CAN_ESR1_ERRINT_MASK                     0x2u
#define CAN_ESR1_ERRINT_SHIFT                    1
#define CAN_ESR1_ERRINT_WIDTH                    1
#define CAN_ESR1_ERRINT(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_ERRINT_SHIFT))&CAN_ESR1_ERRINT_MASK)
#define CAN_ESR1_BOFFINT_MASK                    0x4u
#define CAN_ESR1_BOFFINT_SHIFT                   2
#define CAN_ESR1_BOFFINT_WIDTH                   1
#define CAN_ESR1_BOFFINT(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_BOFFINT_SHIFT))&CAN_ESR1_BOFFINT_MASK)
#define CAN_ESR1_RX_MASK                         0x8u
#define CAN_ESR1_RX_SHIFT                        3
#define CAN_ESR1_RX_WIDTH                        1
#define CAN_ESR1_RX(x)                           (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_RX_SHIFT))&CAN_ESR1_RX_MASK)
#define CAN_ESR1_FLTCONF_MASK                    0x30u
#define CAN_ESR1_FLTCONF_SHIFT                   4
#define CAN_ESR1_FLTCONF_WIDTH                   2
#define CAN_ESR1_FLTCONF(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_FLTCONF_SHIFT))&CAN_ESR1_FLTCONF_MASK)
#define CAN_ESR1_TX_MASK                         0x40u
#define CAN_ESR1_TX_SHIFT                        6
#define CAN_ESR1_TX_WIDTH                        1
#define CAN_ESR1_TX(x)                           (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_TX_SHIFT))&CAN_ESR1_TX_MASK)
#define CAN_ESR1_IDLE_MASK                       0x80u
#define CAN_ESR1_IDLE_SHIFT                      7
#define CAN_ESR1_IDLE_WIDTH                      1
#define CAN_ESR1_IDLE(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_IDLE_SHIFT))&CAN_ESR1_IDLE_MASK)
#define CAN_ESR1_RXWRN_MASK                      0x100u
#define CAN_ESR1_RXWRN_SHIFT                     8
#define CAN_ESR1_RXWRN_WIDTH                     1
#define CAN_ESR1_RXWRN(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_RXWRN_SHIFT))&CAN_ESR1_RXWRN_MASK)
#define CAN_ESR1_TXWRN_MASK                      0x200u
#define CAN_ESR1_TXWRN_SHIFT                     9
#define CAN_ESR1_TXWRN_WIDTH                     1
#define CAN_ESR1_TXWRN(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_TXWRN_SHIFT))&CAN_ESR1_TXWRN_MASK)
#define CAN_ESR1_STFERR_MASK                     0x400u
#define CAN_ESR1_STFERR_SHIFT                    10
#define CAN_ESR1_STFERR_WIDTH                    1
#define CAN_ESR1_STFERR(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_STFERR_SHIFT))&CAN_ESR1_STFERR_MASK)
#define CAN_ESR1_FRMERR_MASK                     0x800u
#define CAN_ESR1_FRMERR_SHIFT                    11
#define CAN_ESR1_FRMERR_WIDTH                    1
#define CAN_ESR1_FRMERR(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_FRMERR_SHIFT))&CAN_ESR1_FRMERR_MASK)
#define CAN_ESR1_CRCERR_MASK                     0x1000u
#define CAN_ESR1_CRCERR_SHIFT                    12
#define CAN_ESR1_CRCERR_WIDTH                    1
#define CAN_ESR1_CRCERR(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_CRCERR_SHIFT))&CAN_ESR1_CRCERR_MASK)
#define CAN_ESR1_ACKERR_MASK                     0x2000u
#define CAN_ESR1_ACKERR_SHIFT                    13
#define CAN_ESR1_ACKERR_WIDTH                    1
#define CAN_ESR1_ACKERR(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_ACKERR_SHIFT))&CAN_ESR1_ACKERR_MASK)
#define CAN_ESR1_BIT0ERR_MASK                    0x4000u
#define CAN_ESR1_BIT0ERR_SHIFT                   14
#define CAN_ESR1_BIT0ERR_WIDTH                   1
#define CAN_ESR1_BIT0ERR(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_BIT0ERR_SHIFT))&CAN_ESR1_BIT0ERR_MASK)
#define CAN_ESR1_BIT1ERR_MASK                    0x8000u
#define CAN_ESR1_BIT1ERR_SHIFT                   15
#define CAN_ESR1_BIT1ERR_WIDTH                   1
#define CAN_ESR1_BIT1ERR(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_BIT1ERR_SHIFT))&CAN_ESR1_BIT1ERR_MASK)
#define CAN_ESR1_RWRNINT_MASK                    0x10000u
#define CAN_ESR1_RWRNINT_SHIFT                   16
#define CAN_ESR1_RWRNINT_WIDTH                   1
#define CAN_ESR1_RWRNINT(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_RWRNINT_SHIFT))&CAN_ESR1_RWRNINT_MASK)
#define CAN_ESR1_TWRNINT_MASK                    0x20000u
#define CAN_ESR1_TWRNINT_SHIFT                   17
#define CAN_ESR1_TWRNINT_WIDTH                   1
#define CAN_ESR1_TWRNINT(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_TWRNINT_SHIFT))&CAN_ESR1_TWRNINT_MASK)
#define CAN_ESR1_SYNCH_MASK                      0x40000u
#define CAN_ESR1_SYNCH_SHIFT                     18
#define CAN_ESR1_SYNCH_WIDTH                     1
#define CAN_ESR1_SYNCH(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_SYNCH_SHIFT))&CAN_ESR1_SYNCH_MASK)
#define CAN_ESR1_BOFFDONEINT_MASK                0x80000u
#define CAN_ESR1_BOFFDONEINT_SHIFT               19
#define CAN_ESR1_BOFFDONEINT_WIDTH               1
#define CAN_ESR1_BOFFDONEINT(x)                  (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_BOFFDONEINT_SHIFT))&CAN_ESR1_BOFFDONEINT_MASK)
#define CAN_ESR1_ERROVR_MASK                     0x200000u
#define CAN_ESR1_ERROVR_SHIFT                    21
#define CAN_ESR1_ERROVR_WIDTH                    1
#define CAN_ESR1_ERROVR(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_ESR1_ERROVR_SHIFT))&CAN_ESR1_ERROVR_MASK)
/* IMASK1 Bit Fields */
#define CAN_IMASK1_BUF31TO0M_MASK                0xFFFFFFFFu
#define CAN_IMASK1_BUF31TO0M_SHIFT               0
#define CAN_IMASK1_BUF31TO0M_WIDTH               32
#define CAN_IMASK1_BUF31TO0M(x)                  (((uint32_t)(((uint32_t)(x))<<CAN_IMASK1_BUF31TO0M_SHIFT))&CAN_IMASK1_BUF31TO0M_MASK)
/* IFLAG1 Bit Fields */
#define CAN_IFLAG1_BUF0I_MASK                    0x1u
#define CAN_IFLAG1_BUF0I_SHIFT                   0
#define CAN_IFLAG1_BUF0I_WIDTH                   1
#define CAN_IFLAG1_BUF0I(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_IFLAG1_BUF0I_SHIFT))&CAN_IFLAG1_BUF0I_MASK)
#define CAN_IFLAG1_BUF4TO1I_MASK                 0x1Eu
#define CAN_IFLAG1_BUF4TO1I_SHIFT                1
#define CAN_IFLAG1_BUF4TO1I_WIDTH                4
#define CAN_IFLAG1_BUF4TO1I(x)                   (((uint32_t)(((uint32_t)(x))<<CAN_IFLAG1_BUF4TO1I_SHIFT))&CAN_IFLAG1_BUF4TO1I_MASK)
#define CAN_IFLAG1_BUF5I_MASK                    0x20u
#define CAN_IFLAG1_BUF5I_SHIFT                   5
#define CAN_IFLAG1_BUF5I_WIDTH                   1
#define CAN_IFLAG1_BUF5I(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_IFLAG1_BUF5I_SHIFT))&CAN_IFLAG1_BUF5I_MASK)
#define CAN_IFLAG1_BUF6I_MASK                    0x40u
#define CAN_IFLAG1_BUF6I_SHIFT                   6
#define CAN_IFLAG1_BUF6I_WIDTH                   1
#define CAN_IFLAG1_BUF6I(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_IFLAG1_BUF6I_SHIFT))&CAN_IFLAG1_BUF6I_MASK)
#define CAN_IFLAG1_BUF7I_MASK                    0x80u
#define CAN_IFLAG1_BUF7I_SHIFT                   7
#define CAN_IFLAG1_BUF7I_WIDTH                   1
#define CAN_IFLAG1_BUF7I(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_IFLAG1_BUF7I_SHIFT))&CAN_IFLAG1_BUF7I_MASK)
#define CAN_IFLAG1_BUF31TO8I_MASK                0xFFFFFF00u
#define CAN_IFLAG1_BUF31TO8I_SHIFT               8
#define CAN_IFLAG1_BUF31TO8I_WIDTH               24
#define CAN_IFLAG1_BUF31TO8I(x)                  (((uint32_t)(((uint32_t)(x))<<CAN_IFLAG1_BUF31TO8I_SHIFT))&CAN_IFLAG1_BUF31TO8I_MASK)
/* CTRL2 Bit Fields */
#define CAN_CTRL2_EACEN_MASK                     0x10000u
#define CAN_CTRL2_EACEN_SHIFT                    16
#define CAN_CTRL2_EACEN_WIDTH                    1
#define CAN_CTRL2_EACEN(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_CTRL2_EACEN_SHIFT))&CAN_CTRL2_EACEN_MASK)
#define CAN_CTRL2_RRS_MASK                       0x20000u
#define CAN_CTRL2_RRS_SHIFT                      17
#define CAN_CTRL2_RRS_WIDTH                      1
#define CAN_CTRL2_RRS(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_CTRL2_RRS_SHIFT))&CAN_CTRL2_RRS_MASK)
#define CAN_CTRL2_MRP_MASK                       0x40000u
#define CAN_CTRL2_MRP_SHIFT                      18
#define CAN_CTRL2_MRP_WIDTH                      1
#define CAN_CTRL2_MRP(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_CTRL2_MRP_SHIFT))&CAN_CTRL2_MRP_MASK)
#define CAN_CTRL2_TASD_MASK                      0xF80000u
#define CAN_CTRL2_TASD_SHIFT                     19
#define CAN_CTRL2_TASD_WIDTH                     5
#define CAN_CTRL2_TASD(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CTRL2_TASD_SHIFT))&CAN_CTRL2_TASD_MASK)
#define CAN_CTRL2_RFFN_MASK                      0xF000000u
#define CAN_CTRL2_RFFN_SHIFT                     24
#define CAN_CTRL2_RFFN_WIDTH                     4
#define CAN_CTRL2_RFFN(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CTRL2_RFFN_SHIFT))&CAN_CTRL2_RFFN_MASK)
#define CAN_CTRL2_BOFFDONEMSK_MASK               0x40000000u
#define CAN_CTRL2_BOFFDONEMSK_SHIFT              30
#define CAN_CTRL2_BOFFDONEMSK_WIDTH              1
#define CAN_CTRL2_BOFFDONEMSK(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_CTRL2_BOFFDONEMSK_SHIFT))&CAN_CTRL2_BOFFDONEMSK_MASK)
/* ESR2 Bit Fields */
#define CAN_ESR2_IMB_MASK                        0x2000u
#define CAN_ESR2_IMB_SHIFT                       13
#define CAN_ESR2_IMB_WIDTH                       1
#define CAN_ESR2_IMB(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_ESR2_IMB_SHIFT))&CAN_ESR2_IMB_MASK)
#define CAN_ESR2_VPS_MASK                        0x4000u
#define CAN_ESR2_VPS_SHIFT                       14
#define CAN_ESR2_VPS_WIDTH                       1
#define CAN_ESR2_VPS(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_ESR2_VPS_SHIFT))&CAN_ESR2_VPS_MASK)
#define CAN_ESR2_LPTM_MASK                       0x7F0000u
#define CAN_ESR2_LPTM_SHIFT                      16
#define CAN_ESR2_LPTM_WIDTH                      7
#define CAN_ESR2_LPTM(x)                         (((uint32_t)(((uint32_t)(x))<<CAN_ESR2_LPTM_SHIFT))&CAN_ESR2_LPTM_MASK)
/* CRCR Bit Fields */
#define CAN_CRCR_TXCRC_MASK                      0x7FFFu
#define CAN_CRCR_TXCRC_SHIFT                     0
#define CAN_CRCR_TXCRC_WIDTH                     15
#define CAN_CRCR_TXCRC(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CRCR_TXCRC_SHIFT))&CAN_CRCR_TXCRC_MASK)
#define CAN_CRCR_MBCRC_MASK                      0x7F0000u
#define CAN_CRCR_MBCRC_SHIFT                     16
#define CAN_CRCR_MBCRC_WIDTH                     7
#define CAN_CRCR_MBCRC(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CRCR_MBCRC_SHIFT))&CAN_CRCR_MBCRC_MASK)
/* RXFGMASK Bit Fields */
#define CAN_RXFGMASK_FGM_MASK                    0xFFFFFFFFu
#define CAN_RXFGMASK_FGM_SHIFT                   0
#define CAN_RXFGMASK_FGM_WIDTH                   32
#define CAN_RXFGMASK_FGM(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_RXFGMASK_FGM_SHIFT))&CAN_RXFGMASK_FGM_MASK)
/* RXFIR Bit Fields */
#define CAN_RXFIR_IDHIT_MASK                     0x1FFu
#define CAN_RXFIR_IDHIT_SHIFT                    0
#define CAN_RXFIR_IDHIT_WIDTH                    9
#define CAN_RXFIR_IDHIT(x)                       (((uint32_t)(((uint32_t)(x))<<CAN_RXFIR_IDHIT_SHIFT))&CAN_RXFIR_IDHIT_MASK)
/* CBT Bit Fields */
#define CAN_CBT_EPSEG2_MASK                      0x1Fu
#define CAN_CBT_EPSEG2_SHIFT                     0
#define CAN_CBT_EPSEG2_WIDTH                     5
#define CAN_CBT_EPSEG2(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CBT_EPSEG2_SHIFT))&CAN_CBT_EPSEG2_MASK)
#define CAN_CBT_EPSEG1_MASK                      0x3E0u
#define CAN_CBT_EPSEG1_SHIFT                     5
#define CAN_CBT_EPSEG1_WIDTH                     5
#define CAN_CBT_EPSEG1(x)                        (((uint32_t)(((uint32_t)(x))<<CAN_CBT_EPSEG1_SHIFT))&CAN_CBT_EPSEG1_MASK)
#define CAN_CBT_EPROPSEG_MASK                    0xFC00u
#define CAN_CBT_EPROPSEG_SHIFT                   10
#define CAN_CBT_EPROPSEG_WIDTH                   6
#define CAN_CBT_EPROPSEG(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_CBT_EPROPSEG_SHIFT))&CAN_CBT_EPROPSEG_MASK)
#define CAN_CBT_ERJW_MASK                        0xF0000u
#define CAN_CBT_ERJW_SHIFT                       16
#define CAN_CBT_ERJW_WIDTH                       4
#define CAN_CBT_ERJW(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_CBT_ERJW_SHIFT))&CAN_CBT_ERJW_MASK)
#define CAN_CBT_EPRESDIV_MASK                    0x7FE00000u
#define CAN_CBT_EPRESDIV_SHIFT                   21
#define CAN_CBT_EPRESDIV_WIDTH                   10
#define CAN_CBT_EPRESDIV(x)                      (((uint32_t)(((uint32_t)(x))<<CAN_CBT_EPRESDIV_SHIFT))&CAN_CBT_EPRESDIV_MASK)
#define CAN_CBT_BTF_MASK                         0x80000000u
#define CAN_CBT_BTF_SHIFT                        31
#define CAN_CBT_BTF_WIDTH                        1
#define CAN_CBT_BTF(x)                           (((uint32_t)(((uint32_t)(x))<<CAN_CBT_BTF_SHIFT))&CAN_CBT_BTF_MASK)
/* CS Bit Fields */
#define CAN_CS_TIME_STAMP_MASK                   0xFFFFu
#define CAN_CS_TIME_STAMP_SHIFT                  0
#define CAN_CS_TIME_STAMP_WIDTH                  16
#define CAN_CS_TIME_STAMP(x)                     (((uint32_t)(((uint32_t)(x))<<CAN_CS_TIME_STAMP_SHIFT))&CAN_CS_TIME_STAMP_MASK)
#define CAN_CS_DLC_MASK                          0xF0000u
#define CAN_CS_DLC_SHIFT                         16
#define CAN_CS_DLC_WIDTH                         4
#define CAN_CS_DLC(x)                            (((uint32_t)(((uint32_t)(x))<<CAN_CS_DLC_SHIFT))&CAN_CS_DLC_MASK)
#define CAN_CS_RTR_MASK                          0x100000u
#define CAN_CS_RTR_SHIFT                         20
#define CAN_CS_RTR_WIDTH                         1
#define CAN_CS_RTR(x)                            (((uint32_t)(((uint32_t)(x))<<CAN_CS_RTR_SHIFT))&CAN_CS_RTR_MASK)
#define CAN_CS_IDE_MASK                          0x200000u
#define CAN_CS_IDE_SHIFT                         21
#define CAN_CS_IDE_WIDTH                         1
#define CAN_CS_IDE(x)                            (((uint32_t)(((uint32_t)(x))<<CAN_CS_IDE_SHIFT))&CAN_CS_IDE_MASK)
#define CAN_CS_SRR_MASK                          0x400000u
#define CAN_CS_SRR_SHIFT                         22
#define CAN_CS_SRR_WIDTH                         1
#define CAN_CS_SRR(x)                            (((uint32_t)(((uint32_t)(x))<<CAN_CS_SRR_SHIFT))&CAN_CS_SRR_MASK)
#define CAN_CS_CODE_MASK                         0xF000000u
#define CAN_CS_CODE_SHIFT                        24
#define CAN_CS_CODE_WIDTH                        4
#define CAN_CS_CODE(x)                           (((uint32_t)(((uint32_t)(x))<<CAN_CS_CODE_SHIFT))&CAN_CS_CODE_MASK)
/* ID Bit Fields */
#define CAN_ID_EXT_MASK                          0x3FFFFu
#define CAN_ID_EXT_SHIFT                         0
#define CAN_ID_EXT_WIDTH                         18
#define CAN_ID_EXT(x)                            (((uint32_t)(((uint32_t)(x))<<CAN_ID_EXT_SHIFT))&CAN_ID_EXT_MASK)
#define CAN_ID_STD_MASK                          0x1FFC0000u
#define CAN_ID_STD_SHIFT                         18
#define CAN_ID_STD_WIDTH                         11
#define CAN_ID_STD(x)                            (((uint32_t)(((uint32_t)(x))<<CAN_ID_STD_SHIFT))&CAN_ID_STD_MASK)
#define CAN_ID_PRIO_MASK                         0xE0000000u
#define CAN_ID_PRIO_SHIFT                        29
#define CAN_ID_PRIO_WIDTH                        3
#define CAN_ID_PRIO(x)                           (((uint32_t)(((uint32_t)(x))<<CAN_ID_PRIO_SHIFT))&CAN_ID_PRIO_MASK)
/* WORD0 Bit Fields */
#define CAN_WORD0_DATA_BYTE_3_MASK               0xFFu
#define CAN_WORD0_DATA_BYTE_3_SHIFT              0
#define CAN_WORD0_DATA_BYTE_3_WIDTH              8
#define CAN_WORD0_DATA_BYTE_3(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD0_DATA_BYTE_3_SHIFT))&CAN_WORD0_DATA_BYTE_3_MASK)
#define CAN_WORD0_DATA_BYTE_2_MASK               0xFF00u
#define CAN_WORD0_DATA_BYTE_2_SHIFT              8
#define CAN_WORD0_DATA_BYTE_2_WIDTH              8
#define CAN_WORD0_DATA_BYTE_2(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD0_DATA_BYTE_2_SHIFT))&CAN_WORD0_DATA_BYTE_2_MASK)
#define CAN_WORD0_DATA_BYTE_1_MASK               0xFF0000u
#define CAN_WORD0_DATA_BYTE_1_SHIFT              16
#define CAN_WORD0_DATA_BYTE_1_WIDTH              8
#define CAN_WORD0_DATA_BYTE_1(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD0_DATA_BYTE_1_SHIFT))&CAN_WORD0_DATA_BYTE_1_MASK)
#define CAN_WORD0_DATA_BYTE_0_MASK               0xFF000000u
#define CAN_WORD0_DATA_BYTE_0_SHIFT              24
#define CAN_WORD0_DATA_BYTE_0_WIDTH              8
#define CAN_WORD0_DATA_BYTE_0(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD0_DATA_BYTE_0_SHIFT))&CAN_WORD0_DATA_BYTE_0_MASK)
/* WORD1 Bit Fields */
#define CAN_WORD1_DATA_BYTE_7_MASK               0xFFu
#define CAN_WORD1_DATA_BYTE_7_SHIFT              0
#define CAN_WORD1_DATA_BYTE_7_WIDTH              8
#define CAN_WORD1_DATA_BYTE_7(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD1_DATA_BYTE_7_SHIFT))&CAN_WORD1_DATA_BYTE_7_MASK)
#define CAN_WORD1_DATA_BYTE_6_MASK               0xFF00u
#define CAN_WORD1_DATA_BYTE_6_SHIFT              8
#define CAN_WORD1_DATA_BYTE_6_WIDTH              8
#define CAN_WORD1_DATA_BYTE_6(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD1_DATA_BYTE_6_SHIFT))&CAN_WORD1_DATA_BYTE_6_MASK)
#define CAN_WORD1_DATA_BYTE_5_MASK               0xFF0000u
#define CAN_WORD1_DATA_BYTE_5_SHIFT              16
#define CAN_WORD1_DATA_BYTE_5_WIDTH              8
#define CAN_WORD1_DATA_BYTE_5(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD1_DATA_BYTE_5_SHIFT))&CAN_WORD1_DATA_BYTE_5_MASK)
#define CAN_WORD1_DATA_BYTE_4_MASK               0xFF000000u
#define CAN_WORD1_DATA_BYTE_4_SHIFT              24
#define CAN_WORD1_DATA_BYTE_4_WIDTH              8
#define CAN_WORD1_DATA_BYTE_4(x)                 (((uint32_t)(((uint32_t)(x))<<CAN_WORD1_DATA_BYTE_4_SHIFT))&CAN_WORD1_DATA_BYTE_4_MASK)
/* RXIMR Bit Fields */
#define CAN_RXIMR_MI_MASK                        0xFFFFFFFFu
#define CAN_RXIMR_MI_SHIFT                       0
#define CAN_RXIMR_MI_WIDTH                       32
#define CAN_RXIMR_MI(x)                          (((uint32_t)(((uint32_t)(x))<<CAN_RXIMR_MI_SHIFT))&CAN_RXIMR_MI_MASK)

/*!
 * @}
 */ /* end of group CAN_Register_Masks */


/* CAN - Peripheral instance base addresses */
/** Peripheral CAN0 base address */
#define CAN0_BASE                                (0x40024000u)
/** Peripheral CAN0 base pointer */
#define CAN0                                     ((CAN_Type *)CAN0_BASE)
#define CAN0_BASE_PTR                            (CAN0)
/** Peripheral CAN1 base address */
#define CAN1_BASE                                (0x40025000u)
/** Peripheral CAN1 base pointer */
#define CAN1                                     ((CAN_Type *)CAN1_BASE)
#define CAN1_BASE_PTR                            (CAN1)
/** Array initializer of CAN peripheral base addresses */
#define CAN_BASE_ADDRS                           { CAN0_BASE, CAN1_BASE }
/** Array initializer of CAN peripheral base pointers */
#define CAN_BASE_PTRS                            { CAN0, CAN1 }
/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                      { CAN0_Rx_Warning_IRQn, CAN1_Rx_Warning_IRQn }
#define CAN_Tx_Warning_IRQS                      { CAN0_Tx_Warning_IRQn, CAN1_Tx_Warning_IRQn }
#define CAN_Wake_Up_IRQS                         { CAN0_Wake_Up_IRQn, CAN1_Wake_Up_IRQn }
#define CAN_Error_IRQS                           { CAN0_Error_IRQn, CAN1_Error_IRQn }
#define CAN_Bus_Off_IRQS                         { CAN0_Bus_Off_IRQn, CAN1_Bus_Off_IRQn }
#define CAN_ORed_Message_buffer_IRQS             { CAN0_ORed_Message_buffer_IRQn, CAN1_ORed_Message_buffer_IRQn }

/* ----------------------------------------------------------------------------
   -- CAN - Register accessor macros
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup CAN_Register_Accessor_Macros CAN - Register accessor macros
 * @{
 */


/* CAN - Register instance definitions */
/* CAN0 */
#define CAN0_MCR                                 CAN_MCR_REG(CAN0)
#define CAN0_CTRL1                               CAN_CTRL1_REG(CAN0)
#define CAN0_TIMER                               CAN_TIMER_REG(CAN0)
#define CAN0_RXMGMASK                            CAN_RXMGMASK_REG(CAN0)
#define CAN0_RX14MASK                            CAN_RX14MASK_REG(CAN0)
#define CAN0_RX15MASK                            CAN_RX15MASK_REG(CAN0)
#define CAN0_ECR                                 CAN_ECR_REG(CAN0)
#define CAN0_ESR1                                CAN_ESR1_REG(CAN0)
#define CAN0_IMASK1                              CAN_IMASK1_REG(CAN0)
#define CAN0_IFLAG1                              CAN_IFLAG1_REG(CAN0)
#define CAN0_CTRL2                               CAN_CTRL2_REG(CAN0)
#define CAN0_ESR2                                CAN_ESR2_REG(CAN0)
#define CAN0_CRCR                                CAN_CRCR_REG(CAN0)
#define CAN0_RXFGMASK                            CAN_RXFGMASK_REG(CAN0)
#define CAN0_RXFIR                               CAN_RXFIR_REG(CAN0)
#define CAN0_CBT                                 CAN_CBT_REG(CAN0)
#define CAN0_CS0                                 CAN_CS_REG(CAN0,0)
#define CAN0_ID0                                 CAN_ID_REG(CAN0,0)
#define CAN0_WORD00                              CAN_WORD0_REG(CAN0,0)
#define CAN0_WORD10                              CAN_WORD1_REG(CAN0,0)
#define CAN0_CS1                                 CAN_CS_REG(CAN0,1)
#define CAN0_ID1                                 CAN_ID_REG(CAN0,1)
#define CAN0_WORD01                              CAN_WORD0_REG(CAN0,1)
#define CAN0_WORD11                              CAN_WORD1_REG(CAN0,1)
#define CAN0_CS2                                 CAN_CS_REG(CAN0,2)
#define CAN0_ID2                                 CAN_ID_REG(CAN0,2)
#define CAN0_WORD02                              CAN_WORD0_REG(CAN0,2)
#define CAN0_WORD12                              CAN_WORD1_REG(CAN0,2)
#define CAN0_CS3                                 CAN_CS_REG(CAN0,3)
#define CAN0_ID3                                 CAN_ID_REG(CAN0,3)
#define CAN0_WORD03                              CAN_WORD0_REG(CAN0,3)
#define CAN0_WORD13                              CAN_WORD1_REG(CAN0,3)
#define CAN0_CS4                                 CAN_CS_REG(CAN0,4)
#define CAN0_ID4                                 CAN_ID_REG(CAN0,4)
#define CAN0_WORD04                              CAN_WORD0_REG(CAN0,4)
#define CAN0_WORD14                              CAN_WORD1_REG(CAN0,4)
#define CAN0_CS5                                 CAN_CS_REG(CAN0,5)
#define CAN0_ID5                                 CAN_ID_REG(CAN0,5)
#define CAN0_WORD05                              CAN_WORD0_REG(CAN0,5)
#define CAN0_WORD15                              CAN_WORD1_REG(CAN0,5)
#define CAN0_CS6                                 CAN_CS_REG(CAN0,6)
#define CAN0_ID6                                 CAN_ID_REG(CAN0,6)
#define CAN0_WORD06                              CAN_WORD0_REG(CAN0,6)
#define CAN0_WORD16                              CAN_WORD1_REG(CAN0,6)
#define CAN0_CS7                                 CAN_CS_REG(CAN0,7)
#define CAN0_ID7                                 CAN_ID_REG(CAN0,7)
#define CAN0_WORD07                              CAN_WORD0_REG(CAN0,7)
#define CAN0_WORD17                              CAN_WORD1_REG(CAN0,7)
#define CAN0_CS8                                 CAN_CS_REG(CAN0,8)
#define CAN0_ID8                                 CAN_ID_REG(CAN0,8)
#define CAN0_WORD08                              CAN_WORD0_REG(CAN0,8)
#define CAN0_WORD18                              CAN_WORD1_REG(CAN0,8)
#define CAN0_CS9                                 CAN_CS_REG(CAN0,9)
#define CAN0_ID9                                 CAN_ID_REG(CAN0,9)
#define CAN0_WORD09                              CAN_WORD0_REG(CAN0,9)
#define CAN0_WORD19                              CAN_WORD1_REG(CAN0,9)
#define CAN0_CS10                                CAN_CS_REG(CAN0,10)
#define CAN0_ID10                                CAN_ID_REG(CAN0,10)
#define CAN0_WORD010                             CAN_WORD0_REG(CAN0,10)
#define CAN0_WORD110                             CAN_WORD1_REG(CAN0,10)
#define CAN0_CS11                                CAN_CS_REG(CAN0,11)
#define CAN0_ID11                                CAN_ID_REG(CAN0,11)
#define CAN0_WORD011                             CAN_WORD0_REG(CAN0,11)
#define CAN0_WORD111                             CAN_WORD1_REG(CAN0,11)
#define CAN0_CS12                                CAN_CS_REG(CAN0,12)
#define CAN0_ID12                                CAN_ID_REG(CAN0,12)
#define CAN0_WORD012                             CAN_WORD0_REG(CAN0,12)
#define CAN0_WORD112                             CAN_WORD1_REG(CAN0,12)
#define CAN0_CS13                                CAN_CS_REG(CAN0,13)
#define CAN0_ID13                                CAN_ID_REG(CAN0,13)
#define CAN0_WORD013                             CAN_WORD0_REG(CAN0,13)
#define CAN0_WORD113                             CAN_WORD1_REG(CAN0,13)
#define CAN0_CS14                                CAN_CS_REG(CAN0,14)
#define CAN0_ID14                                CAN_ID_REG(CAN0,14)
#define CAN0_WORD014                             CAN_WORD0_REG(CAN0,14)
#define CAN0_WORD114                             CAN_WORD1_REG(CAN0,14)
#define CAN0_CS15                                CAN_CS_REG(CAN0,15)
#define CAN0_ID15                                CAN_ID_REG(CAN0,15)
#define CAN0_WORD015                             CAN_WORD0_REG(CAN0,15)
#define CAN0_WORD115                             CAN_WORD1_REG(CAN0,15)
#define CAN0_RXIMR0                              CAN_RXIMR_REG(CAN0,0)
#define CAN0_RXIMR1                              CAN_RXIMR_REG(CAN0,1)
#define CAN0_RXIMR2                              CAN_RXIMR_REG(CAN0,2)
#define CAN0_RXIMR3                              CAN_RXIMR_REG(CAN0,3)
#define CAN0_RXIMR4                              CAN_RXIMR_REG(CAN0,4)
#define CAN0_RXIMR5                              CAN_RXIMR_REG(CAN0,5)
#define CAN0_RXIMR6                              CAN_RXIMR_REG(CAN0,6)
#define CAN0_RXIMR7                              CAN_RXIMR_REG(CAN0,7)
#define CAN0_RXIMR8                              CAN_RXIMR_REG(CAN0,8)
#define CAN0_RXIMR9                              CAN_RXIMR_REG(CAN0,9)
#define CAN0_RXIMR10                             CAN_RXIMR_REG(CAN0,10)
#define CAN0_RXIMR11                             CAN_RXIMR_REG(CAN0,11)
#define CAN0_RXIMR12                             CAN_RXIMR_REG(CAN0,12)
#define CAN0_RXIMR13                             CAN_RXIMR_REG(CAN0,13)
#define CAN0_RXIMR14                             CAN_RXIMR_REG(CAN0,14)
#define CAN0_RXIMR15                             CAN_RXIMR_REG(CAN0,15)
/* CAN1 */
#define CAN1_MCR                                 CAN_MCR_REG(CAN1)
#define CAN1_CTRL1                               CAN_CTRL1_REG(CAN1)
#define CAN1_TIMER                               CAN_TIMER_REG(CAN1)
#define CAN1_RXMGMASK                            CAN_RXMGMASK_REG(CAN1)
#define CAN1_RX14MASK                            CAN_RX14MASK_REG(CAN1)
#define CAN1_RX15MASK                            CAN_RX15MASK_REG(CAN1)
#define CAN1_ECR                                 CAN_ECR_REG(CAN1)
#define CAN1_ESR1                                CAN_ESR1_REG(CAN1)
#define CAN1_IMASK1                              CAN_IMASK1_REG(CAN1)
#define CAN1_IFLAG1                              CAN_IFLAG1_REG(CAN1)
#define CAN1_CTRL2                               CAN_CTRL2_REG(CAN1)
#define CAN1_ESR2                                CAN_ESR2_REG(CAN1)
#define CAN1_CRCR                                CAN_CRCR_REG(CAN1)
#define CAN1_RXFGMASK                            CAN_RXFGMASK_REG(CAN1)
#define CAN1_RXFIR                               CAN_RXFIR_REG(CAN1)
#define CAN1_CBT                                 CAN_CBT_REG(CAN1)
#define CAN1_CS0                                 CAN_CS_REG(CAN1,0)
#define CAN1_ID0                                 CAN_ID_REG(CAN1,0)
#define CAN1_WORD00                              CAN_WORD0_REG(CAN1,0)
#define CAN1_WORD10                              CAN_WORD1_REG(CAN1,0)
#define CAN1_CS1                                 CAN_CS_REG(CAN1,1)
#define CAN1_ID1                                 CAN_ID_REG(CAN1,1)
#define CAN1_WORD01                              CAN_WORD0_REG(CAN1,1)
#define CAN1_WORD11                              CAN_WORD1_REG(CAN1,1)
#define CAN1_CS2                                 CAN_CS_REG(CAN1,2)
#define CAN1_ID2                                 CAN_ID_REG(CAN1,2)
#define CAN1_WORD02                              CAN_WORD0_REG(CAN1,2)
#define CAN1_WORD12                              CAN_WORD1_REG(CAN1,2)
#define CAN1_CS3                                 CAN_CS_REG(CAN1,3)
#define CAN1_ID3                                 CAN_ID_REG(CAN1,3)
#define CAN1_WORD03                              CAN_WORD0_REG(CAN1,3)
#define CAN1_WORD13                              CAN_WORD1_REG(CAN1,3)
#define CAN1_CS4                                 CAN_CS_REG(CAN1,4)
#define CAN1_ID4                                 CAN_ID_REG(CAN1,4)
#define CAN1_WORD04                              CAN_WORD0_REG(CAN1,4)
#define CAN1_WORD14                              CAN_WORD1_REG(CAN1,4)
#define CAN1_CS5                                 CAN_CS_REG(CAN1,5)
#define CAN1_ID5                                 CAN_ID_REG(CAN1,5)
#define CAN1_WORD05                              CAN_WORD0_REG(CAN1,5)
#define CAN1_WORD15                              CAN_WORD1_REG(CAN1,5)
#define CAN1_CS6                                 CAN_CS_REG(CAN1,6)
#define CAN1_ID6                                 CAN_ID_REG(CAN1,6)
#define CAN1_WORD06                              CAN_WORD0_REG(CAN1,6)
#define CAN1_WORD16                              CAN_WORD1_REG(CAN1,6)
#define CAN1_CS7                                 CAN_CS_REG(CAN1,7)
#define CAN1_ID7                                 CAN_ID_REG(CAN1,7)
#define CAN1_WORD07                              CAN_WORD0_REG(CAN1,7)
#define CAN1_WORD17                              CAN_WORD1_REG(CAN1,7)
#define CAN1_CS8                                 CAN_CS_REG(CAN1,8)
#define CAN1_ID8                                 CAN_ID_REG(CAN1,8)
#define CAN1_WORD08                              CAN_WORD0_REG(CAN1,8)
#define CAN1_WORD18                              CAN_WORD1_REG(CAN1,8)
#define CAN1_CS9                                 CAN_CS_REG(CAN1,9)
#define CAN1_ID9                                 CAN_ID_REG(CAN1,9)
#define CAN1_WORD09                              CAN_WORD0_REG(CAN1,9)
#define CAN1_WORD19                              CAN_WORD1_REG(CAN1,9)
#define CAN1_CS10                                CAN_CS_REG(CAN1,10)
#define CAN1_ID10                                CAN_ID_REG(CAN1,10)
#define CAN1_WORD010                             CAN_WORD0_REG(CAN1,10)
#define CAN1_WORD110                             CAN_WORD1_REG(CAN1,10)
#define CAN1_CS11                                CAN_CS_REG(CAN1,11)
#define CAN1_ID11                                CAN_ID_REG(CAN1,11)
#define CAN1_WORD011                             CAN_WORD0_REG(CAN1,11)
#define CAN1_WORD111                             CAN_WORD1_REG(CAN1,11)
#define CAN1_CS12                                CAN_CS_REG(CAN1,12)
#define CAN1_ID12                                CAN_ID_REG(CAN1,12)
#define CAN1_WORD012                             CAN_WORD0_REG(CAN1,12)
#define CAN1_WORD112                             CAN_WORD1_REG(CAN1,12)
#define CAN1_CS13                                CAN_CS_REG(CAN1,13)
#define CAN1_ID13                                CAN_ID_REG(CAN1,13)
#define CAN1_WORD013                             CAN_WORD0_REG(CAN1,13)
#define CAN1_WORD113                             CAN_WORD1_REG(CAN1,13)
#define CAN1_CS14                                CAN_CS_REG(CAN1,14)
#define CAN1_ID14                                CAN_ID_REG(CAN1,14)
#define CAN1_WORD014                             CAN_WORD0_REG(CAN1,14)
#define CAN1_WORD114                             CAN_WORD1_REG(CAN1,14)
#define CAN1_CS15                                CAN_CS_REG(CAN1,15)
#define CAN1_ID15                                CAN_ID_REG(CAN1,15)
#define CAN1_WORD015                             CAN_WORD0_REG(CAN1,15)
#define CAN1_WORD115                             CAN_WORD1_REG(CAN1,15)
#define CAN1_RXIMR0                              CAN_RXIMR_REG(CAN1,0)
#define CAN1_RXIMR1                              CAN_RXIMR_REG(CAN1,1)
#define CAN1_RXIMR2                              CAN_RXIMR_REG(CAN1,2)
#define CAN1_RXIMR3                              CAN_RXIMR_REG(CAN1,3)
#define CAN1_RXIMR4                              CAN_RXIMR_REG(CAN1,4)
#define CAN1_RXIMR5                              CAN_RXIMR_REG(CAN1,5)
#define CAN1_RXIMR6                              CAN_RXIMR_REG(CAN1,6)
#define CAN1_RXIMR7                              CAN_RXIMR_REG(CAN1,7)
#define CAN1_RXIMR8                              CAN_RXIMR_REG(CAN1,8)
#define CAN1_RXIMR9                              CAN_RXIMR_REG(CAN1,9)
#define CAN1_RXIMR10                             CAN_RXIMR_REG(CAN1,10)
#define CAN1_RXIMR11                             CAN_RXIMR_REG(CAN1,11)
#define CAN1_RXIMR12                             CAN_RXIMR_REG(CAN1,12)
#define CAN1_RXIMR13                             CAN_RXIMR_REG(CAN1,13)
#define CAN1_RXIMR14                             CAN_RXIMR_REG(CAN1,14)
#define CAN1_RXIMR15                             CAN_RXIMR_REG(CAN1,15)

/* CAN - Register array accessors */
#define CAN0_CS(index)                           CAN_CS_REG(CAN0,index)
#define CAN1_CS(index)                           CAN_CS_REG(CAN1,index)
#define CAN0_ID(index)                           CAN_ID_REG(CAN0,index)
#define CAN1_ID(index)                           CAN_ID_REG(CAN1,index)
#define CAN0_WORD0(index)                        CAN_WORD0_REG(CAN0,index)
#define CAN1_WORD0(index)                        CAN_WORD0_REG(CAN1,index)
#define CAN0_WORD1(index)                        CAN_WORD1_REG(CAN0,index)
#define CAN1_WORD1(index)                        CAN_WORD1_REG(CAN1,index)
#define CAN0_RXIMR(index)                        CAN_RXIMR_REG(CAN0,index)
#define CAN1_RXIMR(index)                        CAN_RXIMR_REG(CAN1,index)

/*!
 * @}
 */ /* end of group CAN_Register_Accessor_Macros */


/*!
 * @}
 */ /* end of group CAN_Peripheral_Access_Layer */

 
 
 
 
////////////////////////////////////////////////////////////////////////
 
 
#else /* #if !defined(MKE02Z2_H_) && !defined(MKE02Z4_H_) && !defined(SKEAZN642_H_) */
  /* There is already included the same memory map. Check if it is compatible (has the same major version) */
  #if (MCU_MEM_MAP_VERSION != 0x0100u)
    #if (!defined(MCU_MEM_MAP_SUPPRESS_VERSION_WARNING))
      #warning There are included two not compatible versions of memory maps. Please check possible differences.
    #endif /* (!defined(MCU_MEM_MAP_SUPPRESS_VERSION_WARNING)) */
  #endif /* (MCU_MEM_MAP_VERSION != 0x0100u) */
#endif  /* #if !defined(MKE02Z2_H_) && !defined(MKE02Z4_H_) && !defined(SKEAZN642_H_) */

/* SKEAZN642.h, eof. */
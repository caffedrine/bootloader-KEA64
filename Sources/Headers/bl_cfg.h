#ifndef __BL_CFG_H__
#define __BL_CFG_H__

/* Base address of user application */
#define APPLICATION_BASE		0x2000UL

/* UART Interface */
#define BL_UART					UART2
/* UART Buadrate */
#define BL_UART_BAUDRATE        9600 //115200

/* Pin used to determine which should be loaded on reset: bootloader or user application */
#ifdef SKEAZ1284
	#define ENB_BOOT_PIN	PTE4
	#define ENB_BOOT_PORT	PTE
#elif defined(SKEAZN642)
	#define ENB_BOOT_PIN	PTE4
	#define ENB_BOOT_PORT	PTE
#endif

/* Led will be TRUE (5V) when bootloader is running */
#ifdef SKEAZ1284
	#define LED_PIN 	PTH0
	#define LED_PORT	PTH
#elif defined(SKEAZN642)
	#define LED_PIN 	PTE0
	#define LED_PORT	PTE
#endif

/****************************************************
 *    Target specific attributes
 ****************************************************/
/* Flash sector size */
#define TARGET_FLASH_SECTOR_SIZE    512			//4096
/* Flash total size */
#define TARGET_FLASH_SIZE       	64*1024u	//1024*1024u
/* SRAM start address */
#define TARGET_RAM_START        	0x1FFFFC00	//0x1FFF0000
/* SRAM total size */
#define TARGET_RAM_SIZE         	0x1000		//0x40000 -> 16k

/****************************************************
 *    Bootloader features
 ****************************************************/
#define BL_FEATURE_VERIFY       			0
#define BL_FEATURE_APP_CHECK    			0
#define BL_FEATURE_FLASH_SECURITY_DISABLE   0			/// TODO: Implement flash security and backdoor key

#endif // __BL_CFG_H__

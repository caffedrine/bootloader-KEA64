#include <stdint.h>

// Device specific file
#include "derivative.h"

// Config files
#include "bl_bsp.h"		// Hardware initialization
#include "bl_core.h"
#include "bl_cfg.h"

// Drivers
#include "CLK.h"
#include "CRC.h"
#include "flash.h"

// Handle interrupts here
#include "Events.h"

// Common definitions
#include "definitions.h"

//   ____ ___  _   _ ____ _____ ____    _    _   _ _____ ____
//  / ___/ _ \| \ | / ___|_   _/ ___|  / \  | \ | |_   _/ ___|
// | |  | | | |  \| \___ \ | | \___ \ / _ \ |  \| | | | \___ \
// | |__| |_| | |\  |___) || |  ___) / ___ \| |\  | | |  ___) |
//  \____\___/|_| \_|____/ |_| |____/_/   \_\_| \_| |_| |____/

enum
{
	kCallbackBufferSize = 64,
	kPacket_MaxPayloadSize = 32,
};

//! @brief Serial framing packet constants.
enum _framing_packet_constants
{
	kFramingPacketStartByte = 0x5a,
	kFramingPacketType_Ack = 0xa1,
	kFramingPacketType_Nak = 0xa2,
	kFramingPacketType_AckAbort = 0xa3,
	kFramingPacketType_Command = 0xa4,
	kFramingPacketType_Data = 0xa5,
	kFramingPacketType_Ping = 0xa6,
	kFramingPacketType_PingResponse = 0xa7
};

enum
{
	kPacketState_StartByte,
	kPacketState_PacketTye,
	kPacketState_Length,
	kPacketState_CRC,
	kPacketState_Payload
};

//	 ____    _  _____  _  _______   ______  _____ ____
//	|  _ \  / \|_   _|/ \|_   _\ \ / /  _ \| ____/ ___|
//	| | | |/ _ \ | | / _ \ | |  \ V /| |_) |  _| \___ \
//	| |_| / ___ \| |/ ___ \| |   | | |  __/| |___ ___) |
//	|____/_/   \_\_/_/   \_\_|   |_| |_|   |_____|____/

typedef struct _serial_packet
{
	uint8_t startByte;
	uint8_t packetType;
	uint8_t lengthInBytes[2];
	uint8_t crc16[2];
	uint32_t payload[32 / sizeof(uint32_t)];
} serial_packet_t;

typedef enum
{
	kCommandPhase_Command,
	kCommandPhase_Data,
} command_state_t;

typedef struct
{
	volatile uint32_t writeOffset;
	uint32_t readOffset;
	uint8_t callbackBuffer[kCallbackBufferSize];

	bool isAckNeeded;
	bool isAckAbortNeeded;
} serial_context_t;

typedef struct
{
	command_state_t state;

	uint8_t *data;
	uint32_t address;
	uint32_t count;
	uint8_t commandTag;
	uint8_t option;
} bootloader_context_t;


/*****************************************************************************************

 Packet related definitions, functions and variables.

 ******************************************************************************************/
static const uint8_t s_pingPacket[] = { kFramingPacketStartByte, kFramingPacketType_PingResponse, 0, 2, 1, 'P', 0, 0, 0xaa, 0xea };
static const uint8_t s_packet_ack[] = { kFramingPacketStartByte, kFramingPacketType_Ack };
static const uint8_t s_packet_nak[] = { kFramingPacketStartByte, kFramingPacketType_Nak };
static const uint8_t s_packet_abort[] = { kFramingPacketStartByte, kFramingPacketType_AckAbort };
static serial_context_t s_serialContext;

static serial_packet_t s_readPacket;	// Read packet
static serial_packet_t s_writePacket;	// Write packet

static uint8_t read_byte(void);
static status_t serial_packet_read(uint8_t packetType);
status_t serial_packet_write(void);
uint16_t calculate_crc(serial_packet_t *packet);


//	__     ___    ____  ____
//	\ \   / / \  |  _ \/ ___|
//	 \ \ / / _ \ | |_) \___ \
//	  \ V / ___ \|  _ < ___) |
//	   \_/_/   \_\_| \_\____/

static bootloader_context_t bl_ctx;
static _Bool ENB_BOOT = 0;						// Load user application by default

//	  ____ ___  ____  _____
//	 / ___/ _ \|  _ \| ____|
//	| |  | | | | | | |  _|
//	| |__| |_| | |_| | |___
//	 \____\___/|____/|_____|

static bool is_application_valid(uint32_t sp, uint32_t pc)
{
	bool spValid = ((sp > TARGET_RAM_START) && (sp <= (TARGET_RAM_START + TARGET_RAM_SIZE)));
	bool pcValid = ((pc >= APPLICATION_BASE) && (pc < TARGET_FLASH_SIZE));

	return spValid && pcValid;
}

uint16_t calculate_crc(serial_packet_t *packet)
{
	uint16_t crc_val = 0;
	uint8_t *start = (uint8_t*)packet;
	uint16_t payloadLength;

	crc16_update( &crc_val, start, 4 );
	start = (uint8_t*)&packet->payload[0];

	payloadLength = *(uint16_t*)&packet->lengthInBytes[0];
	crc16_update( &crc_val, start, payloadLength );

	return crc_val;
}

static uint8_t read_byte(void)
{
	return bl_hw_if_read_byte();
}

static status_t serial_packet_read(uint8_t packetType)
{
	static int32_t s_packetState = kPacketState_StartByte;
	static uint32_t s_stateCnt;
	uint16_t calculatedCrc;
	uint16_t receivedCrc;
	uint16_t *packetLength;
	uint8_t *payloadStart = (uint8_t*)&s_readPacket.payload[0];
	bool isPacketComplete = false;
	uint8_t tmp;

	if ( s_serialContext.isAckNeeded )
	{
		s_serialContext.isAckNeeded = false;
		bl_hw_if_write( s_packet_ack, sizeof(s_packet_ack) );
	}

	tmp = read_byte();
	switch ( s_packetState )
	{
		case kPacketState_StartByte:
			if ( tmp == kFramingPacketStartByte )
			{
				s_readPacket.startByte = kFramingPacketStartByte;
				s_packetState = kPacketState_PacketTye;
			}
			break;
		case kPacketState_PacketTye:
			if ( tmp == kFramingPacketType_Ping )
			{
				// Send ping packet here.
				bl_hw_if_write( (void*)s_pingPacket, sizeof(s_pingPacket) );
				s_packetState = kPacketState_StartByte;
			}
			else if ( tmp == packetType )
			{
				s_readPacket.packetType = packetType;
				s_packetState = kPacketState_Length;
				s_stateCnt = 0;
			}
			else
			{
				s_packetState = kFramingPacketStartByte;
			}
			break;
		case kPacketState_Length:
			s_readPacket.lengthInBytes[s_stateCnt++] = tmp;
			if ( s_stateCnt >= 2 )
			{
				s_packetState = kPacketState_CRC;
				s_stateCnt = 0;

				packetLength = (uint16_t*)&s_writePacket.lengthInBytes[0];
				if ( *packetLength > kPacket_MaxPayloadSize )
				{
					*packetLength = kPacket_MaxPayloadSize;
				}
			}
			break;
		case kPacketState_CRC:
			s_readPacket.crc16[s_stateCnt++] = tmp;
			if ( s_stateCnt >= 2 )
			{
				s_packetState = kPacketState_Payload;
				s_stateCnt = 0;
			}
			break;
		case kPacketState_Payload:
			payloadStart[s_stateCnt++] = tmp;
			if ( s_stateCnt >= *(uint16_t*)&s_readPacket.lengthInBytes[0] )
			{
				s_packetState = kPacketState_StartByte;
				isPacketComplete = true;
			}
			break;
	}

	if ( isPacketComplete )
	{
		calculatedCrc = calculate_crc( &s_readPacket );
		receivedCrc = *(uint16_t*)&s_readPacket.crc16[0];

		if ( calculatedCrc == receivedCrc )
		{
			s_serialContext.isAckNeeded = true;
			return kStatus_Success;
		}
		else
		{
			bl_hw_if_write( s_packet_nak, sizeof(s_packet_nak) );
			return kStatus_Fail;
		}
	}
	else
	{
		return kStatus_Busy;
	}
}

status_t serial_packet_write(void)
{
	uint16_t packetLength;
	uint16_t crc16;
	uint8_t startByte;
	uint8_t packetType;
	command_packet_t *cmdPacket;

	if ( s_serialContext.isAckNeeded )
	{
		s_serialContext.isAckNeeded = false;
		bl_hw_if_write( s_packet_ack, sizeof(s_packet_ack) );
	}

	if ( s_serialContext.isAckAbortNeeded )
	{
		s_serialContext.isAckAbortNeeded = false;
		bl_hw_if_write( s_packet_abort, sizeof(s_packet_abort) );
	}

	cmdPacket = (command_packet_t*)&s_writePacket.payload[0];

	s_writePacket.startByte = kFramingPacketStartByte;
	s_writePacket.packetType = kFramingPacketType_Command;
	packetLength = (1 + cmdPacket->parameterCount) * sizeof(uint32_t);

	*(uint16_t*)&s_writePacket.lengthInBytes[0] = packetLength;
	crc16 = calculate_crc( &s_writePacket );
	*(uint16_t*)&s_writePacket.crc16[0] = crc16;

	bl_hw_if_write( (void*)&s_writePacket, 6 );
	bl_hw_if_write( (void*)&s_writePacket.payload, packetLength );
// Wait ACK
	startByte = read_byte();
	packetType = read_byte();

	if ( startByte == kFramingPacketStartByte && packetType == kFramingPacketType_Ack )
	{
		return kStatus_Success;
	}
	return kStatus_Fail;
}

static status_t handle_get_property(void)
{
	get_property_packet_t *getPropertyPkt = (get_property_packet_t*)&s_readPacket.payload[0];
	get_property_response_packet_t *packet = (get_property_response_packet_t*)&s_writePacket.payload[0];
	uint32_t propertySize = 1;

	packet->commandPacket.commandTag = kCommandTag_GetPropertyResponse;
	packet->commandPacket.flags = 0;
	packet->commandPacket.parameterCount = 1;
	packet->status = kStatus_Success;

	switch ( getPropertyPkt->propertyTag )
	{
		case kPropertyTag_BootloaderVersion:
			packet->propertyValue[0] = 0x4b010300;  // K1.3.0
			break;
		case kPropertyTag_AvailablePeripherals:
			packet->propertyValue[0] = 0x01; 		// Only UART peripheral is available;
			break;
		case kPropertyTag_FlashStartAddress:
			packet->propertyValue[0] = 0x00;
			break;
		case kPropertyTag_FlashSizeInBytes:
			packet->propertyValue[0] = TARGET_FLASH_SIZE;
			break;
		case kPropertyTag_FlashSectorSize:
			packet->propertyValue[0] = TARGET_FLASH_SECTOR_SIZE;
			break;
		case kPropertyTag_AvailableCommands:
			packet->propertyValue[0] = kCommandTag_FlashEraseRegion |
					kCommandTag_WriteMemory |
					kCommandTag_GetProperty |
					kCommandTag_Reset;
			break;
		case kPropertyTag_MaxPacketSize:
			packet->propertyValue[0] = kPacket_MaxPayloadSize;
			break;
		case kPropertyTag_ReservedRegions:
			propertySize = 4;
			packet->propertyValue[0] = 0;
			packet->propertyValue[1] = APPLICATION_BASE - 1;
			packet->propertyValue[2] = 0x20000000;
			packet->propertyValue[3] = 0x200003FF;
			break;
		case kPropertyTag_ValidateRegions:
			packet->propertyValue[0] = 1;
			break;
		case kPropertyTag_RAMStartAddress:
			packet->propertyValue[0] = TARGET_RAM_START;
			break;
		case kPropertyTag_RAMSizeInBytes:
			packet->propertyValue[0] = TARGET_RAM_SIZE;
			break;
		case kPropertyTag_SystemDeviceId:
			packet->propertyValue[0] = 0x00; //SIM->SDID
			break;
		case kPropertyTag_FlashSecurityState:
			packet->propertyValue[0] = 0;
			break;
		default:
			propertySize = 0;
			packet->status = kStatus_UnknownProperty;
			break;
	}
	packet->commandPacket.parameterCount += propertySize;

	return serial_packet_write();
}

status_t send_generic_response(uint32_t commandTag, uint32_t status)
{
	generic_response_packet_t *packet = (generic_response_packet_t*)&s_writePacket.payload[0];
	packet->commandPacket.commandTag = kCommandTag_GenericResponse;
	packet->commandPacket.flags = 0;
	packet->commandPacket.reserved = 0;
	packet->commandPacket.parameterCount = 2;
	packet->commandTag = commandTag;
	packet->status = status;

	return serial_packet_write();
}

static status_t handle_flash_erase_region(void)
{
	status_t status = kStatus_Success;
	flash_erase_region_packet_t *packet = (flash_erase_region_packet_t*)&s_readPacket.payload[0];

	uint32_t start = packet->startAddress;
	uint32_t length = packet->byteCount;
	if ( !is_valid_memory_range( start, length ) )
	{
		status = kStatusMemoryRangeInvalid;
	}
	else
	{
		status = flash_erase( start, length );
	}
	return send_generic_response( kCommandTag_FlashEraseRegion, status );
}

static status_t handle_write_memory(void)
{
	write_memory_packet_t *packet = (write_memory_packet_t*)&s_readPacket.payload[0];

	bl_ctx.address = packet->startAddress;
	bl_ctx.count = packet->byteCount;
	return send_generic_response( kCommandTag_WriteMemory, kStatus_Success );
}

static status_t handle_reset(void)
{
	send_generic_response( kCommandTag_Reset, kStatus_Success );

	NVIC_SystemReset();

	return kStatus_Success;
}

static status_t handle_execute(void)
{
	execute_call_packet_t *packet = (execute_call_packet_t*)&s_readPacket.payload[0];
	status_t status;
	bool isArgmentValid = false;
	isArgmentValid = is_application_valid( packet->stackpointer, packet->callAddress );

	status = send_generic_response( kCommandTag_Reset, isArgmentValid ? kStatus_Success : kStatus_InvalidArgument );

	if ( isArgmentValid )
	{
		application_run( packet->stackpointer, packet->callAddress );
	}

	return status;
}

static void finalize_data_phase(status_t status)
{
	send_generic_response( kCommandTag_WriteMemory, status );
}

static void data_phase_abort(void)
{
	s_serialContext.isAckAbortNeeded = true;
	s_serialContext.isAckNeeded = false;
}

static status_t handle_data_phase(bool *hasMoreData)
{
	uint16_t packetLength = *(uint16_t*)&s_readPacket.lengthInBytes[0];
	uint32_t *src = (uint32_t*)&s_readPacket.payload[0];
	uint32_t writeLength;
	status_t status = kStatus_Success;

	if ( bl_ctx.count )
	{
		writeLength = (packetLength < bl_ctx.count) ? packetLength : bl_ctx.count;
		{
			status = flash_program( bl_ctx.address, src, writeLength );
			if ( status != kStatus_Success )
			{
				data_phase_abort();
				finalize_data_phase( status );
				*hasMoreData = false;
				return kStatus_Success;
			}
		}
		bl_ctx.count -= writeLength;
		bl_ctx.address += writeLength;
	}

	if ( bl_ctx.count )
	{
		*hasMoreData = true;
	}
	else
	{
		*hasMoreData = false;
		finalize_data_phase( status );
	}

	return kStatus_Success;
}

void application_run(uint32_t sp, uint32_t pc)
{
	typedef void (*app_entry_t)(void);

	static uint32_t s_stackPointer = 0;
	static uint32_t s_applicationEntry = 0;
	static app_entry_t s_application = 0;

	s_stackPointer = sp;
	s_applicationEntry = pc;
	s_application = (app_entry_t)s_applicationEntry;

// Change MSP and PSP
	__set_MSP( s_stackPointer );
	__set_PSP( s_stackPointer );

// Jump to application
	s_application();

// Should never reach here.
	__NOP();
}

void bootloader_run(void)
{
	command_packet_t *commandPkt;
	status_t status;
	bool hasMoreData = false;
	flash_init();

	while ( 1 )
	{
		// Read data from host
		uint8_t packetType = (bl_ctx.state == kCommandPhase_Command) ? kFramingPacketType_Command : kFramingPacketType_Data;
		status = serial_packet_read( packetType );

		if ( status != kStatus_Success )
		{
			continue;
		}

		switch ( bl_ctx.state )
		{
			case kCommandPhase_Command:
				commandPkt = (command_packet_t*)&s_readPacket.payload[0];
				switch ( commandPkt->commandTag )
				{
					case kCommandTag_GetProperty:
						handle_get_property();
						break;
					case kCommandTag_FlashEraseRegion:
						handle_flash_erase_region();
						break;
					case kCommandTag_WriteMemory:
						handle_write_memory();
						bl_ctx.state = kCommandPhase_Data;
						break;
					case kCommandTag_Execute:
						handle_execute();
						break;
					case kCommandTag_Reset:
						handle_reset();
						break;
				}
				break;
			case kCommandPhase_Data:
				status = handle_data_phase( &hasMoreData );
				if ( (status != kStatus_Success) || (!hasMoreData) )
				{
					bl_ctx.state = kCommandPhase_Command;
				}
				break;
			default:
				break;
		}
	}
}

int main(void)
{
	/* Configure clocks to run at 20 Mhz */
	Clk_Init();

	/*Initialize UART2 at 9600 bauds */
	Uart_init();

	/* Init hardware and stuff */
	hardware_init();

	/* Initialize GPIO pins. E.g. led used to signal bootloader runing*/
	pins_init();

	// Enter in in bootloader if defined button is pressed
	ENB_BOOT = READ_INPUT(ENB_BOOT_PORT, ENB_BOOT_PIN);			// read ENB_BOOT flag

	/* Debug serial *//*
	while ( 1 )
	{
		uint8_t c = read_byte();
		OUTPUT_SET(LED_PORT, LED_PIN);
		Uart_SendChar( c );
		OUTPUT_CLEAR(LED_PORT, LED_PIN);
	}
	//*/

	if ( ENB_BOOT == 1 ) //&& stay_in_bootloader() )
	{
		OUTPUT_SET(LED_PORT, LED_PIN);		// signal bootloader running by turning on led set
		bootloader_run();
	}
	else
	{
		stay_in_bootloader();

		uint32_t *vectorTable = (uint32_t*)APPLICATION_BASE;
		uint32_t sp = vectorTable[0];
		uint32_t pc = vectorTable[1];
		application_run( sp, pc );
	}

	// Should never reach here.
	return 0;
}

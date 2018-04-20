#ifndef CRC_H_
#define CRC_H_

//	  ____  _____ ____ _        _    ____      _  _____ ___ ___  _   _ ____
//	 |  _ \| ____/ ___| |      / \  |  _ \    / \|_   _|_ _/ _ \| \ | / ___|
//	 | | | |  _|| |   | |     / _ \ | |_) |  / _ \ | |  | | | | |  \| \___ \
//	 | |_| | |__| |___| |___ / ___ \|  _ <  / ___ \| |  | | |_| | |\  |___) |
//	 |____/|_____\____|_____/_/   \_\_| \_\/_/   \_\_| |___\___/|_| \_|____/

void crc16_update(uint16_t *currectCrc, const uint8_t *src, uint32_t lengthInBytes);

//	  ____  _____ _____ ___ _   _ ___ _____ ___ ___  _   _ ____
//	 |  _ \| ____|  ___|_ _| \ | |_ _|_   _|_ _/ _ \| \ | / ___|
//	 | | | |  _| | |_   | ||  \| || |  | |  | | | | |  \| \___ \
//	 | |_| | |___|  _|  | || |\  || |  | |  | | |_| | |\  |___) |
//	 |____/|_____|_|   |___|_| \_|___| |_| |___\___/|_| \_|____/


void crc16_update(uint16_t *currentCrc, const uint8_t *src, uint32_t lengthInBytes)
{
	uint32_t crc = *currentCrc;
	uint32_t j;
	for ( j = 0; j < lengthInBytes; ++j )
	{
		uint32_t i;
		uint32_t byte = src[j];
		crc ^= byte << 8;
		for ( i = 0; i < 8; ++i )
		{
			uint32_t temp = crc << 1;
			if ( crc & 0x8000 )
			{
				temp ^= 0x1021;
			}
			crc = temp;
		}
	}
	*currentCrc = crc;
}

#endif /* CRC_H_ */

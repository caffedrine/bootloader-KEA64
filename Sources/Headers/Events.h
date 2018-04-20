#ifndef EVENTS_H_
#define EVENTS_H_

// Reset uC in case of HardFault
void HardFault_Handler(void)
{
	NVIC_SystemReset();

	while ( 1 )
	{
	}
}

#endif

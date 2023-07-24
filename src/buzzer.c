#include "buzzer.h"

void beep(void)
{
	uint32_t output = 0x00000000;
	output = (GPIOC->ODR & 0xFFFFFFBF); //mask odr to clear PC6
	output |= 0x00000040;
	GPIOC->ODR = output;
	delay(1500000);
	output = 0x00000000;
	output = (GPIOC->ODR & 0xFFFFFFBF); //mask odr to clear PC6
	output |= 0x00000000;
	GPIOC->ODR = output;
}

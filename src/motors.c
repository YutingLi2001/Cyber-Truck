#include "stm32f10x.h"
#include "motors.h"

void stop(void)
	{
	uint32_t output = 0x00000000;
	output = (GPIOB->ODR & 0xFFFF0FFF); //mask odr to clear PB15-12
	GPIOB->ODR = output;
}
	
void forward(void)
{
	uint32_t output = 0x00000000;
	output = (GPIOB->ODR & 0xFFFF0FFF); 
	output |= 0x0000C000;
	GPIOB->ODR = output;
}
	
void turnLeft(void)
{
	uint32_t output = 0x00000000;
	output = (GPIOB->ODR & 0xFFFF0FFF); 
	output |= 0x00006000;
	GPIOB->ODR = output;
}

void turnRight(void)
{
	uint32_t output = 0x00000000;
	output = (GPIOB->ODR & 0xFFFF0FFF); 
	output |= 0x00009000;
	GPIOB->ODR = output;
}

void reverse(void)
{
	uint32_t output = 0x00000000;
	output = (GPIOB->ODR & 0xFFFF0FFF); 
	output |= 0x00003000;
	GPIOB->ODR = output;
}

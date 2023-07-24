#include "stm32f10x.h"
#include "ir_sensors.h"

bool leftIR(void)
{
	uint8_t leftSensor;
	leftSensor = (( GPIOB->IDR & ( GPIO_IDR_IDR7 )) >> 7 );
	if (leftSensor == 0x01){
		return false;
	}
	else{
		return true;
	}
}

bool rightIR(void)
{
	uint8_t rightSensor;
	rightSensor = (( GPIOB->IDR & ( GPIO_IDR_IDR6 )) >> 6);
	if (rightSensor == 0x01){
	 return false;
	}
	else{
	 return true;
	}
}

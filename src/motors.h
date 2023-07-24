#include "stm32f10x.h"
/*
	I used PB12, 13, 14 ,15 for motor controll
	PB12: left motor reverse
	PB13: right motor reverse
	PB14: left motor forward
	PB15: right motor forward
*/

//14&15
void forward(void);
//clear bits
void stop(void);
//13&14
void turnLeft(void);
//12&15
void turnRight(void);
//12&13
void reverse(void);

#include "clock.h"
#include "gpio.h"
#include "subsystemInit.h"
#include "motors.h"
#include "delay.h"
#include "ir_sensors.h"
#include "pwm.h"
#include "buzzer.h"
#include "ADC.h"

void driving(void);

int main()
{
	//init syb-systems 
	initPLL_24MHz();
	initAPB2_GPIO();
	initAPB2_AFIO();
	initAPB2_TIM1();
	
	/*
	init PWM
	2399: 10kHZ
	100: frequency, 0.1ms
	50: 50% pulse width
	*/
	initTIM1(2399, 100, 50);
	initADC();
	
	//init GPIO
	configAFIO_Output('A', 8); //PWM Channel
	configGPIO_Output('B', 12); //Motor
	configGPIO_Output('B', 13); //Motor
	configGPIO_Output('B', 14); //Motor
	configGPIO_Output('B', 15); //Motor
	configGPIO_Output('C', 6); //Buzzer
	configGPIO_Input('B', 6); //Right IR Sensor
	configGPIO_Input('B', 7); //Left IR Sensor
	
	

	while(1)
	{
		driving();
	}

	return 0;
}

void driving(void){
	//booleans to store sensor pass-in values
	bool left = false;
	bool right = false;
	
	while(1){
		left = leftIR();
		right = rightIR();

		//if no obstacles at both directions, driving forward
		if(left==false && right==false){
			forward();
		}
		//if the obstacle is on the left, turn right to avoid 
		else if(left==true && right ==false){
			turnLeft();
		}
		//if the obstacle is on the right, turn left to avoid 
		else if(left==false && right==true){
			turnRight();
		}
		//if both sides have obstacle, beep, wait for a while, and then reverse
		else if(left==true && right==true){
			beep();
			stop();
			//reverse();
		}
	}
}










#include "stm32f10x.h"
#include <stdint.h>

//Initialize sub-system clocks for GPIOx
void initAPB2_GPIO(void);
void initAPB2_AFIO(void);
void initAPB2_TIM1(void);
void init_APB2ADC(void);
void initAPB1_USART(void);
void initEXTI0(void);
void initSysTick(uint32_t);

#include "stm32f10x.h"
#include "clock.h"
void initPLL_24MHz(void)
{
uint32_t temp = 0x00;
//PLLMUL X3, PLL clock = PREDIV1, SW = PLL as system clock
RCC->CFGR |= RCC_CFGR_PLLMULL_0 | RCC_CFGR_PLLSRC | RCC_CFGR_SW_1;
//Turn on PLL, HSE, HSI
RCC->CR |= RCC_CR_PLLON | RCC_CR_HSEON | RCC_CR_HSION;
//Loop until PLLRDY goes high
while (temp != 0x02000000)
{
 temp = RCC->CR & 0x02000000;
} 
}
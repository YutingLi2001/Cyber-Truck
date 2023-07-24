#include "stm32f10x.h"
#include "subSystemSetup.h"

void initAPB2_GPIO(void)
{
RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
}
void initAPB2_AFIO(void)
{
RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
}
void initAPB2_TIM1(void)
{
RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
}
void init_APB2ADC(void)
{
RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;
}
void initAPB1_USART(void)
{
RCC->APB1ENR |= RCC_APB1ENR_USART3EN;
}
//Not finished, should be able to pass port and pin
//and init for that combination
void initEXTI0(void)
{
RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
AFIO->EXTICR[1] &= ~AFIO_EXTICR1_EXTI0;
EXTI->IMR |= EXTI_IMR_MR0;
EXTI->FTSR |= EXTI_FTSR_TR0;
NVIC->ISER[0] |= NVIC_ISER_SETENA_6;
}
void initSysTick(uint32_t countVal)
{
SysTick->CTRL = 0x00;
SysTick->VAL = 0x00;
SysTick->LOAD = countVal;
SysTick->CTRL = 0x07;
}
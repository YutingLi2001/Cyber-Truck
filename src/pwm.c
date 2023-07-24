#include "stm32f10x.h"
#include "pwm.h"
void initTIM1(uint32_t divider, uint32_t reload_val, uint32_t cmp_val)
{
	TIM1->CR1 |= TIM_CR1_CEN;
	TIM1->CR2 |= TIM_CR2_OIS1;
	TIM1->EGR |= TIM_EGR_UG;
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE | 
	TIM_CCMR1_OC1FE;
	TIM1->CCER |= TIM_CCER_CC1E;
	TIM1->PSC = divider;
	TIM1->ARR = reload_val;
	TIM1->CCR1 = cmp_val;
	TIM1->BDTR |= TIM_BDTR_MOE | TIM_BDTR_OSSI;
	TIM1->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN;
}
void updatePWM(uint32_t update_val)
{
	TIM1->CCR1 = update_val;
	TIM1->EGR |= TIM_EGR_UG;
}
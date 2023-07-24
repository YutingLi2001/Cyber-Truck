#include "stm32f10x.h"
#include "gpio.h"

bool configGPIO_Input(char port, int pin)
{
uint32_t CNF_MODE = 0x00000004;
//Ensure pin is not greater than 15
if (pin <= 15)
{
 //If pin greater than 7 then CRH else CRL
 if (pin > 7)
 {
 int shiftAmnt = pin - 8;
 CNF_MODE = CNF_MODE << (shiftAmnt * 4);
 
 switch (port)
 {
 case 'A':
 GPIOA->CRH |= CNF_MODE;
 break;
 case 'B':
 GPIOB->CRH |= CNF_MODE;
 break;
 case 'C':
 GPIOC->CRH |= CNF_MODE;
 break;
 default:
 return 0;
 }
 
 return 1;
 }
 else
 {
 int shiftAmnt = pin;
 CNF_MODE = CNF_MODE << (shiftAmnt * 4);
 
 switch (port)
 {
 case 'A':
 GPIOA->CRL |= CNF_MODE;
 break;
 case 'B':
 GPIOB->CRL |= CNF_MODE;
 break;
 case 'C':
 GPIOC->CRL |= CNF_MODE;
 break;
 default:
 return 0;
 }
 
 return 1;
 } }
else
{
 return 0;
} }
bool configGPIO_Output(char port, int pin)
{
uint32_t CNF_MODE = 0x00000003;
uint32_t CNF_CLEAR_MASK = 0x33333333;
//Ensure pin is not greater than 15
if (pin <= 15)
{
 //If pin greater than 7 then CRH else CRL
 if (pin > 7)
 {
 int shiftAmnt = pin - 8;
 CNF_MODE = CNF_MODE << (shiftAmnt * 4);
 
 switch (port)
 {
 case 'A':
 GPIOA->CRH &= CNF_CLEAR_MASK;
 GPIOA->CRH |= CNF_MODE;
 break;
 case 'B':
 GPIOB->CRH &= CNF_CLEAR_MASK;
 GPIOB->CRH |= CNF_MODE;
 break;
 case 'C':
 GPIOC->CRH &= CNF_CLEAR_MASK;
 GPIOC->CRH |= CNF_MODE;
 break;
 default:
 return 0;
 }
 
 return 1;
 }
 else
 {
 int shiftAmnt = pin;
 CNF_MODE = CNF_MODE << (shiftAmnt * 4);
 
 switch (port)
 {
 case 'A':
 GPIOA->CRL &= CNF_CLEAR_MASK;
 GPIOA->CRL |= CNF_MODE;
 break;
 case 'B':
 GPIOB->CRL &= CNF_CLEAR_MASK;
 GPIOB->CRL |= CNF_MODE;
 break;
 case 'C':
 GPIOC->CRL &= CNF_CLEAR_MASK;
 GPIOC->CRL |= CNF_MODE;
 break;
 default:
 return 0;
 }
 
 return 1;
 } }
else
{
 return 0;
} }
bool configGPIO_AnalogIn(char port, int pin)
{
uint32_t CNF_MODE = 0xFFFFFFF0;
 uint32_t MASK = 0x0000000F;
//Ensure pin is not greater than 15
if (pin <= 15)
{
 //If pin greater than 7 then CRH else CRL
 if (pin > 7)
 {
 int shiftAmnt = pin - 8;
 CNF_MODE = CNF_MODE << (shiftAmnt * 4);
 MASK = MASK << ((shiftAmnt - 1) * 4);
 CNF_MODE = CNF_MODE ^ MASK;
 
 switch (port)
 {
 case 'A':
 GPIOA->CRH &= CNF_MODE;
 break;
 case 'B':
 GPIOB->CRH &= CNF_MODE;
 break;
 case 'C':
 GPIOC->CRH &= CNF_MODE;
 break;
 default:
 return 0;
 }
 
 return 1;
 }
 else
 {
 int shiftAmnt = pin;
 CNF_MODE = CNF_MODE << (shiftAmnt * 4);
 MASK = MASK << ((shiftAmnt - 1) * 4);
 CNF_MODE = CNF_MODE ^ MASK;
 
 switch (port)
 {
 case 'A':
 GPIOA->CRL &= CNF_MODE;
 break;
 case 'B':
 GPIOB->CRL &= CNF_MODE;
 break;
 case 'C':
 GPIOC->CRL &= CNF_MODE;
 break;
 default:
 return 0;
 }
 
 return 1;
 } }
else
{
 return 0;
} }
bool configAFIO_Output(char port, int pin)
{
uint32_t CNF_MODE = 0x0000000B;
uint32_t MASK = 0x00000000;
//Ensure pin is not greater than 15
if (pin <= 15)
{
 //If pin greater than 7 then CRH else CRL
 if (pin > 7)
 {
 int shiftAmnt = pin - 8;
 MASK = ~(0x0F << (shiftAmnt * 4));
 CNF_MODE = CNF_MODE << (shiftAmnt * 4);
 
 switch (port)
 {
 case 'A':
 GPIOA->CRH &= MASK;
 GPIOA->CRH |= CNF_MODE;
 break;
 case 'B':
 GPIOB->CRH &= MASK;
 GPIOB->CRH |= CNF_MODE;
 break;
 case 'C':
 GPIOC->CRH &= MASK;
 GPIOC->CRH |= CNF_MODE;
 break;
 default:
 return 0;
 }
 
 return 1;
 }
 else
 {
 int shiftAmnt = pin;
 MASK = ~(0x0F << (shiftAmnt * 4));
 CNF_MODE = CNF_MODE << (shiftAmnt * 4);
 
 switch (port)
 {
 case 'A':
 GPIOA->CRL &= MASK;
 GPIOA->CRL |= CNF_MODE;
 break;
 case 'B':
 GPIOB->CRL &= MASK;
 GPIOB->CRL |= CNF_MODE;
 break;
 case 'C':
 GPIOC->CRL &= MASK;
 GPIOC->CRL |= CNF_MODE;
 break;
 default:
 return 0;
 }
 
 return 1;
 } }
else
{
 return 0;
}
}

#include "stm32f10x.h"
#include <stdint.h>
#include <stdbool.h>

bool configGPIO_Input(char, int);
bool configGPIO_Output(char, int);
bool configGPIO_AnalogIn(char, int);
bool configAFIO_Output(char, int);
#pragma once

#include "stm32f0xx.h"
#include "xprintf.h"
#include "nrfDefine.h"

#define resCE GPIOA->BSRR = GPIO_BSRR_BR_1
#define setCE GPIOA->BSRR = GPIO_BSRR_BS_1

#define BOAD 500000

void sysInit();
uint8_t nrfR(uint8_t reg);
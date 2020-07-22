#pragma once

#include "stm32f0xx.h"
#include "config.h"

#include "xprintf.h"
#include "nrfDefine.h"
#ifdef SSD1306_MODULE
#include "ssd1306.h"
#endif

#define resCE GPIOA->BSRR = GPIO_BSRR_BR_1
#define setCE GPIOA->BSRR = GPIO_BSRR_BS_1

#define BOAD 500000

void sysInit();
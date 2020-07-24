#pragma once

#include "stm32f0xx.h"
#include "config.h"

#include "xprintf.h"
#include "nrfDefine.h"
#ifdef SSD1306_MODULE
#include "ssd1306.h"
#endif

#define BOAD 500000

void sysInit();
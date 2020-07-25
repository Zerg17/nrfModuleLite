#pragma once

#include "stm32f0xx.h"
#include "config.h"
#include "nrf.h"
#include "xprintf.h"
#ifdef SSD1306_MODULE
#include "ssd1306.h"
#endif

#define _delay_us(a) for(volatile uint32_t i=0;i<a*8/12;i++)

extern uint32_t volatile tick;
extern uint32_t sec_d;
extern uint32_t volatile sec;

void sysInit();
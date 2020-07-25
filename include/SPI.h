#pragma once
#ifndef SPI
#define SPI

#include "stm32f0xx.h"

void spiInit(void);             //Инициализация SPI
uint8_t spiWR(uint8_t data);    //Прием и передача данных в SPI

#endif
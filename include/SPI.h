#pragma once
#ifndef SPI
#define SPI

#include "stm32f0xx.h"

//Инициализация SPI
void spiInit(void);

//Прием и передача данных в SPI
uint8_t spiWR(uint8_t data);

#endif
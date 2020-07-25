#pragma once
#ifndef UART
#define UART

#include "stm32f0xx.h"

#define BAUD 500000        //Скорость UART в baud

void uartInit();           //Инициализация UART
void uartWrite(uint8_t d); //Передача байта

#endif
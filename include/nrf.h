#pragma once
#ifndef NRF
#define NRF

#include "nrfDefine.h"
#include "system.h"
#include "spi.h"

#define nrfCH(a) nrfW(RF_CH,(a))

#define resCE  GPIOA->BSRR = GPIO_BSRR_BR_0
#define resCSN GPIOA->BSRR = GPIO_BSRR_BR_1
#define setCE  GPIOA->BSRR = GPIO_BSRR_BS_0
#define setCSN GPIOA->BSRR = GPIO_BSRR_BS_1

#define nrfST nrfW(CONFIG, 0b1110)
#define nrfSR nrfW(CONFIG, 0b1111)
#define nrfEP(a) nrfW(EN_RXADDR, a)
#define nrfAW(a) nrfW(SETUP_AW, a)
#define nrfRETR(a) nrfW(SETUP_RETR, a)
#define nrfPDP(a,b) nrfW(RX_PW_P0 + b, a)
#define nrfFR(a) nrfW(FEATURE, a)
#define nrfDPL(a) nrfW(DYNPD, a)
#define nrfRF(a) nrfW(RF_SETUP, a)
#define nrfAD ((nrfR() >> 1 ) | 0x7)

#include "stm32f0xx.h"
#include "nrfDefine.h"

uint8_t nrfR(uint8_t reg); //Чтение регистра из nrf
uint8_t nrfStatus();
void nrfSD(uint8_t* send);
void nrfRD(uint8_t* buf); 
void nrfConfig();
void nrfPrintReg();
#endif
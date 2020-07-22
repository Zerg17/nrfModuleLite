#include "system.h"
#include "UART.h"
#include "SPI.h"

void rccInit(){
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOBEN;
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_SPI1EN;
    
}

void gpioInit(){
    // PA3  - DEBUG_RX      - USART2_RX
    // PA2  - DEBUG_TX      - USART2_TX

    //Инициализация GPIO для UART
    GPIOA->MODER |= GPIO_MODER_MODER3_1 | GPIO_MODER_MODER2_1; 
    GPIOA->AFR[0]|= 0x00001100;
    //Инициализация GPIO для SPI
    GPIOA->MODER |= GPIO_MODER_MODER0_0 | GPIO_MODER_MODER1_0 |GPIO_MODER_MODER5_1 | GPIO_MODER_MODER6_1 | GPIO_MODER_MODER7_1;
}

void sysInit(){
    xdev_out(uartWrite);
    rccInit();
    gpioInit();
    uartInit();
    spiInit();
    SysTick_Config(F_CPU/100);
}
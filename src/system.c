#include "system.h"

void rccInit(){
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOBEN;
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;
}

void gpioInit(){
    // PA3  - DEBUG_RX      - USART2_RX
    // PA2  - DEBUG_TX      - USART2_TX

    GPIOA->MODER |= GPIO_MODER_MODER3_1 | GPIO_MODER_MODER2_1;
    GPIOA->AFR[0]|= 0x00001100;
}

void uartWrite(uint8_t d){
    while(!(USART1->ISR & USART_ISR_TXE));
    USART1->TDR=d;
}

void uartInit(){
    USART1->BRR = (F_CPU+BOAD/2)/BOAD;
    USART1->CR1 = USART_CR1_TE;
    USART1->CR1 |= USART_CR1_UE;
}

void sysInit(){
    xdev_out(uartWrite);
    rccInit();
    gpioInit();
    SysTick_Config(F_CPU/100);
}


#include "system.h"
#include "UART.h"
#include "SPI.h"

void rccInit(){
    RCC->AHBENR |= RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOBEN;
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN | RCC_APB2ENR_SPI1EN;
    #ifdef I2C_MODULE
    RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
    #endif
}

void gpioInit(){
    // PA3  - DEBUG_RX      - USART2_RX
    // PA2  - DEBUG_TX      - USART2_TX

    //Инициализация GPIO для UART
    GPIOA->MODER |= GPIO_MODER_MODER3_1 | GPIO_MODER_MODER2_1; 
    GPIOA->AFR[0]|= 0x00001100;
    //Инициализация GPIO для SPI  
    GPIOA->MODER |= GPIO_MODER_MODER0_0 | GPIO_MODER_MODER1_0 |GPIO_MODER_MODER5_1 | GPIO_MODER_MODER6_1 | GPIO_MODER_MODER7_1;
    
    #ifdef I2C_MODULE
    //Инициализация GPIO для I2C
    GPIOA->MODER |= GPIO_MODER_MODER9_1 | GPIO_MODER_MODER10_1;
    GPIOA->AFR[1] |= 0x00000440;
    #endif
}

void i2cInit(){
    I2C1->TIMINGR = 0x00000404;
    I2C1->CR1 = I2C_CR1_PE;
}

void sysInit(){
    xdev_out(uartWrite);
    rccInit();
    gpioInit();
    uartInit();
    spiInit();
    #ifdef I2C_MODULE
    i2cInit();
    #endif
    #ifdef SSD1306_MODULE
    ssd1306_Init(0x3C);
    #endif
    SysTick_Config(F_CPU/100);
}
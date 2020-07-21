#include "system.h"

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

void uartWrite(uint8_t d){
    while(!(USART1->ISR & USART_ISR_TXE));
    USART1->TDR=d;
}

void uartInit(){
    USART1->BRR = (F_CPU+BOAD/2)/BOAD;
    USART1->CR1 = USART_CR1_TE;
    USART1->CR1 |= USART_CR1_UE;
}

void spiInit(void){
    SPI1->CR1 = SPI_CR1_SSM | SPI_CR1_SSI | SPI_CR1_MSTR;
    SPI1->CR1 |= SPI_CR1_SPE;
    SPI1->CR2 |= SPI_CR2_FRXTH;
}

void sysInit(){
    xdev_out(uartWrite);
    rccInit();
    gpioInit();
    uartInit();
    spiInit();
    SysTick_Config(F_CPU/100);
}



uint8_t spiWR(uint8_t data){
	*(uint8_t *)&(SPI1->DR) = data;
	while(!(SPI1->SR & SPI_SR_RXNE));
    return SPI1->DR;
}


uint8_t nrfR(uint8_t reg)
{
  resCE;                                      //Выбираем устройство для работы по spi
//   spiWR(R_REGISTER | (REGISTER_MASK & reg)); //Передаем адрес регистра с маской чтения
  uint8_t result = spiWR(reg);               //Холостая передача для приема значения
  setCE;                                      //Останавливаем работу с устройством
  return result;
}
#include "SPI.h"

//Инициализация SPI
void spiInit(void){
    GPIOA->MODER |= GPIO_MODER_MODER0_0 | GPIO_MODER_MODER1_0
                                          //Output для CE и CSN
                 |GPIO_MODER_MODER5_1 | GPIO_MODER_MODER6_1 
                 | GPIO_MODER_MODER7_1;   //Альтернативный режим для SPI
                                          
    SPI1->CR1 = SPI_CR1_SSM | SPI_CR1_SSI //Используем программный SS пин = 1
              | SPI_CR1_MSTR;             //Работаем в качестве мастера
    SPI1->CR2 |= SPI_CR2_FRXTH;           //Принимаем данные по 8 бит (1/4 FIFO)
    SPI1->CR1 |= SPI_CR1_SPE;             //Включаем SPI модуль
}

//Прием и передача данных в SPI
uint8_t spiWR(uint8_t data){
	*(uint8_t *)&(SPI1->DR) = data;   //Записываем байт в TX FIFO
	while(!(SPI1->SR & SPI_SR_RXNE)); //Пока RX FIFO пустой, ждем (пока передача не завершится)
    return SPI1->DR;                  //Возвращаем данные из RX FIFO
}
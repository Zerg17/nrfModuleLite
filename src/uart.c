#include "uart.h"

void uartWrite(uint8_t d){                 //Инициализация UART
    while(!(USART1->ISR & USART_ISR_TXE)); //ждем, пока буффер не освободится
    USART1->TDR=d;                         //Записываем данные в буффер
}

void uartInit(){                        //Передача одного байта
    USART1->BRR = (F_CPU+BAUD/2)/BAUD;  //Выставляем скорость
    USART1->CR1 = USART_CR1_TE;         //Включаем передатчик
    USART1->CR1 |= USART_CR1_UE;        //Включаем USART модуль
}

#include "nrf.h"

uint8_t nrfR(uint8_t reg) {                               //Считать значение произвольного регистра NRF                  
    resCSN;                                               //Активируем SPI slave
    spiWR(R_REGISTER | (REGISTER_MASK & reg));            //Передаем команду на чтение регистра
    uint8_t result = spiWR(NOP);                          //Передаем пустой пакет, чтобы получить запрошенное значение
    setCSN;                                               //Отключаем SPI slave
    return result;                                        //Возвращаем полученное значение
}

uint8_t nrfStatus() {                                     //Считать значение статусного регистра NRF
    resCSN;                                               //Активируем SPI slave
    uint8_t result = spiWR(NOP);                          //Если не было никакой команды, NRF возвращает значение статусного регистра
    setCSN;                                               //Отключаем SPI slave
    return result;                                        //Возвращаем полученное значение
}

//Все функции ниже еще не были протестированны!

void nrfW(uint8_t reg, uint8_t value) {                   //Записать значение в произвольный регистр NRF  
    resCSN;                                               //Активируем SPI slave
    spiWR(W_REGISTER | (REGISTER_MASK & reg));            //Передаем команду на запись регистра
    spiWR(value);                                         //Передаем значение для записи в регистр
    setCSN;                                               //Отключаем SPI slave
}

void nrfSD(uint8_t* send) {                               //Отправить данные по радиоканалу NRF
    nrfW(STATUS, nrfStatus());                            //Обнуляем флаги прерываний ????????????? ПАША, ПРОВЕРЬ ЭТОТ МОМЕНТ!!!! ?????????????
    resCSN;                                               //Активируем SPI slave
    spiWR(FLUSH_TX);                                      //Очистка передающего FIFO буффера
    setCSN;                                               //Отключаем SPI slave

    resCSN;                                               //Активируем SPI slave
    spiWR(W_TX_PAYLOAD);                                  //Передаем команду на запись данных в FIFO
    for (uint8_t i = 0; i < 32; i++) spiWR(send[i]);      //Передаем данные (FIFO - 32 байта максимум)
    setCSN;                                               //Отключаем SPI slave

    setCE;                                                //Активируем радиоканал
    _delay_cs(1);                                        //Ждем (окончания передачи)
    resCE;                                                //Отключаем радиоканал
}

void nrfRD(uint8_t* buf) {                                //Принять данные по радиоканалу NRF
    resCSN;                                               //Активируем SPI slave
    spiWR(R_RX_PAYLOAD);                                  //Передаем команду на считывание данных с FIFO
    for (uint8_t i = 0; i < 32; i++) buf[i] = spiWR(0);   //Принимаем данные с FIFO - 32 байта
    setCSN;                                               //Отключаем SPI slave
    nrfW(STATUS, nrfStatus());                            //Обнуляем флаги прерываний ????????????? ПАША, ПРОВЕРЬ ЭТОТ МОМЕНТ!!!! ?????????????
}

void nrfSAD(uint32_t value, uint8_t nPipe) {              //Смена адреса труб
    if (nPipe > 6) nPipe = 0;                             //Всего 7 труб 0,1 - RX трубы адрес: 40 бит 
                                                          //2-5 - RX трубы адрес: старшие 32 бита 1 трубы + младший байт из регистра
                                                          //6 - TX труба 40 бит адрес, только для Enhanced ShockBurst™ передачи
    resCSN;                                               //Активируем SPI slave
    spiWR(W_REGISTER | (RX_ADDR_P0 + nPipe));             //Передаем команду на запись регистра
    spiWR(value);                                         //Передаем значение для записи в регистр
    spiWR(value >> 8);                                    //   --//--
    spiWR(value >> 16);                                   //   --//--
    spiWR(value >> 24);                                   //   --//--
    spiWR(0);                                             //   --//--
    setCSN;                                               //Отключаем SPI slave
}

void nrfConfig(){
    nrfW(CONFIG, EN_CRC | CRCO | PWR_UP); //powerUp=1, CRC = 2 байта, Включить CRC
    _delay_cs(1);
    nrfW(RF_SETUP, 0b100110); //0 дБл мощность, 250 кбит/с скорость
}
#include "nrf.h"
#include "system.h"

uint8_t nrfR(uint8_t reg)
{
  resCE;                                        //Выбираем устройство для работы по spi
//   spiWR(R_REGISTER | (REGISTER_MASK & reg)); //Передаем адрес регистра с маской чтения
  uint8_t result = spiWR(reg);                  //Холостая передача для приема значения
  setCE;                                        //Останавливаем работу с устройством
  return result;
}
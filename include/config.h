#pragma once

#define SSD1306_MODULE
#define TX_MODULE
//#define RX_MODULE

#ifdef SSD1306_MODULE
    #define I2C_MODULE
#endif
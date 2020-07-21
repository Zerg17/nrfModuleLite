// #ifndef NRFLIB
// #define NRFLIB


// #include "system.h"
// #include "nrfDefine.h"

// #define nrfCH(a) nrfW(RF_CH,(a))

// #define nrfST nrfW(CONFIG, 0b1110)
// #define nrfSR nrfW(CONFIG, 0b1111)
// #define nrfEP(a) nrfW(EN_RXADDR, a)
// #define nrfAW(a) nrfW(SETUP_AW, a)
// #define nrfRETR(a) nrfW(SETUP_RETR, a)
// #define nrfPDP(a,b) nrfW(RX_PW_P0 + b, a)
// #define nrfFR(a) nrfW(FEATURE, a)
// #define nrfDPL(a) nrfW(DYNPD, a)
// #define nrfRF(a) nrfW(RF_SETUP, a)
// #define nrfAD ((nrfR() >> 1 ) | 0x7)
// #define nrfAA(a) nrfW(EN_AA, a)

// #define SCE  setB(2)
// #define SCSN setB(1)
// #define RCE  resB(2)
// #define RCSN resB(1)

// extern uint8_t CH;

// void nrfInit();
// void nrfConf();
// uint8_t nrfR(uint8_t);

// #endif

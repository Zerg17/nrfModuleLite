#include "system.h"

uint32_t tim1 = 100;

int main(void){
    sysInit();
    xprintf("initialization...\n");
  
    nrfConfig();
    uint8_t data[32];
    
    while(1){
#ifdef RX_MODULE
        setCE;
        xprintf("waiting for packet");
        while(!(nrfStatus()&RX_DR)){
            xprintf("%08b\n",nrfStatus());
            _delay_cs(100);
        };
        xprintf("\n");
        resCE;
        nrfRD(data);
        xprintf("%3d\n",data[0]);
#endif    
<<<<<<< HEAD
        // xprintf("CONFIG      = %08b\n",nrfR(CONFIG));//         0x00
        // xprintf("EN_RXADDR   = %08b\n",nrfR(EN_RXADDR));//      0x02
        // xprintf("SETUP_AW    = %08b\n",nrfR(SETUP_AW));//       0x03
        // xprintf("SETUP_RETR  = %08b\n",nrfR(SETUP_RETR));//     0x04
        // xprintf("RF_CH       = %08b\n",nrfR(RF_CH));//          0x05
        // xprintf("RF_SETUP    = %08b\n",nrfR(RF_SETUP));//       0x06
        // xprintf("STATUS      = %08b\n",nrfR(STATUS));//         0x07
        // xprintf("OBSERVE_TX  = %08b\n",nrfR(OBSERVE_TX));//     0x08
        // xprintf("CD          = %08b\n",nrfR(CD));//             0x09
        // xprintf("RX_ADDR_P0  = %08b\n",nrfR(RX_ADDR_P0));//     0x0A
        // xprintf("RX_ADDR_P1  = %08b\n",nrfR(RX_ADDR_P1));//     0x0B
        // xprintf("RX_ADDR_P2  = %08b\n",nrfR(RX_ADDR_P2));//     0x0C
        // xprintf("RX_ADDR_P3  = %08b\n",nrfR(RX_ADDR_P3));//     0x0D
        // xprintf("RX_ADDR_P4  = %08b\n",nrfR(RX_ADDR_P4));//     0x0E
        // xprintf("RX_ADDR_P5  = %08b\n",nrfR(RX_ADDR_P5));//     0x0F
        // xprintf("TX_ADDR     = %08b\n",nrfR(TX_ADDR));//        0x10
        // xprintf("RX_PW_P0    = %08b\n",nrfR(RX_PW_P0));//       0x11
        // xprintf("RX_PW_P1    = %08b\n",nrfR(RX_PW_P1));//       0x12
        // xprintf("RX_PW_P2    = %08b\n",nrfR(RX_PW_P2));//       0x13
        // xprintf("RX_PW_P3    = %08b\n",nrfR(RX_PW_P3));//       0x14
        // xprintf("RX_PW_P4    = %08b\n",nrfR(RX_PW_P4));//       0x15
        // xprintf("RX_PW_P5    = %08b\n",nrfR(RX_PW_P5));//       0x16
        // xprintf("FIFO_STATUS = %08b\n",nrfR(FIFO_STATUS));//    0x17
        // xprintf("DYNPD       = %08b\n",nrfR(DYNPD));//	        0x1C
        // xprintf("FEATURE     = %08b\n",nrfR(FEATURE));//	    0x1D
        // xprintf("==================\n");
        // _delay_cs(100);
#ifdef TX_MODULE
        nrfSD(data);
        data[0]++;
=======

#ifdef TX_MODULE
        nrfSD(data);
        xsprintf(data, "%u Hello, World!\n", sec);
>>>>>>> dc42ee8bb96a4202e8938eb870115d4053e46e44
        _delay_cs(100);
#endif

#ifdef SSD1306_MODULE
        ssd1306_Fill(0);
        ssd1306_SetCursor(0, 0);
        xfprintf(ssd1306_Char, "%d", tick);
        ssd1306_UpdateScreen();
#endif
        
    }
}
#include "system.h"

uint32_t tim1 = 100;

int main(void){
    sysInit();
    xprintf("initialization...\n");
    _delay_cs(20)
    nrfConfig();
    uint8_t *data;
    
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
        xprintf("%S\n",(char *)data);
#endif    

#ifdef TX_MODULE
        nrfSD(data);
        xsprintf(data, "%u Hello, World!\n", sec);
        nrfPrintReg();
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
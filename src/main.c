#include "system.h"

uint32_t tim1 = 100;

int main(void){
    sysInit();
    xprintf("initialization...\n");
    uint8_t data[32];
    
    while(1){
#ifdef RX_MODULE
        setCE;
        while(!(nrfStatus()&RX_DR));
        resCE;
        nrfRD(data);
        xprintf("%3d\n",data[0]);
#endif    

#ifdef TX_MODULE
        nrfSD(data);
        xsprintf(data, "%u Hello, World!\n", sec);
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
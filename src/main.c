#include "system.h"

uint32_t tim1 = 100;

int main(void){
    sysInit();
    xprintf("initialization...\n");
    uint8_t data[32];
    data[0]=0;
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
        data[0]++;
        _delay_us(1000000);
#endif

#ifdef SSD1306_MODULE
        ssd1306_Fill(0);
        ssd1306_SetCursor(0, 0);
        xfprintf(ssd1306_Char, "%d", tick);
        ssd1306_UpdateScreen();
#endif
        xprintf("Hello Sanya!  %d (%u)\n",tick,(uint8_t)(tick-255U));
        sanyaDelay(100);
    }
}

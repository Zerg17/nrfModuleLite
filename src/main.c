#include "system.h"

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
        // xprintf("%02X\n",nrfStatus());
        // _delay_us(1000000);
    }
}

#include "system.h"

int main(void){
    sysInit();
    xprintf("initialization...\n");
    while(1){
#ifdef RX_MODULE
        x
#elif TX_MODULE
        s
#else
        xprintf("%02X\n",nrfStatus());
#endif
        _delay_us(1000000);
        
    }
}

#include "system.h"

int main(void){
    sysInit();
    xprintf("initialization...\n");
    while(1){
        xprintf("%02X\n",nrfStatus());
        _delay_us(1000000);
    }
}

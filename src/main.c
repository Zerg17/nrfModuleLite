#include "system.h"

int main(void){
    sysInit();
    xprintf("initialization...\n");
    while(1){
        xprintf("%02X\n",nrfR(NOP));
        for(volatile uint32_t i=0;i<1000000;i++);
    }
}

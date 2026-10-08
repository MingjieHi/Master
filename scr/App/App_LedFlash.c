#include "App_LedFlash.h"
void App_Led_Blink(){
    static u16 count = 500;
    count --;
    if(count == 0){
        LED1 = ~LED1;
        count = 500;
    }
}
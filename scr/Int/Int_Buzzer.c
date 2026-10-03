#include "Int_Buzzer.h"

void Int_Buzzer_01s()
{
    u8 times = 100;
    while (times > 0)
    {
        BUZZER = ~BUZZER;
        Com_Delay_1ms(1);//500hz
        times--;
    }
}

void Int_Buzzer_01s_var(u16 Hz, double time)
{
    u16 curcle_times = 0;
    u16 delay_time_oncetime = 0;
    if(Hz == 0){
        Hz = 500;
    }
delay_time_oncetime = 500/Hz;
    curcle_times = (u16)(time*900/delay_time_oncetime);
    while (curcle_times > 0)
    {
        BUZZER = ~BUZZER;
        Com_Delay_1ms(delay_time_oncetime);//500hz
        curcle_times--;
    }
}

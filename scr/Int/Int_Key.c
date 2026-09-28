#include "Int_Key.h"


bit Int_Key_IsSW1Pressed()//按键按下返回1，没按下返回0
{
    if(SW1 == 0){
        Com_Delay_1ms(10); //销振
        if (SW1 == 0)
        {
            while (SW1 == 0)
                ;
            return 1;
        }else{
             return 0;
        }
    }


}

bit Int_Key_IsSW2Pressed()
{
        if(SW2 == 0){
        Com_Delay_1ms(10); //销振
        if (SW2 == 0)
        {
            while (SW2 == 0)
                ;
            return 1;
        }else{
             return 0;
        }
    }}

bit Int_Key_IsSW3Pressed()
{
        if(SW3 == 0){
        Com_Delay_1ms(10); //销振
        if (SW3 == 0)
        {
            while (SW3 == 0)
                ;
            return 1;
        }else{
             return 0;
        }
    }
}

bit Int_Key_IsSW4Pressed()
{
        if(SW4 == 0){
        Com_Delay_1ms(10); //销振
        if (SW4 == 0)
        {
            while (SW4 == 0)
                ;
            return 1;
        }else{
             return 0;
        }
    }
}





// P10-P17
// row: 17 16 15 14
// cols: 13 12 11 10
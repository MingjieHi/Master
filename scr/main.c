// #include "Int/Int_Digital.h"
#include "App/App_CalNumber.h"
#include "Int/Int_Key.h"
#include "Int/Int_KeyMatrix.h"
#include "Int/Int_Led.h"
#include "Com/Com_Util.h"
#include "DIr/Dir_Timer0.h"
#define LED1 P20
#define LED2 P21
#define LED3 P22
#define LED4 P23
#define BUZZER P25


void INT0_INIT(){
    // 启用终端部
    EA = 1;
    EX0 = 1;
    // 设置触发方式
    IT0 = 1;//下降沿
}


void INT0_Handler() interrupt 0
{
    LED1 = ~LED1;
}


void main()
{
    // INT0_INIT();
    Dir_Timer0_Init();
    while (1)
    {

    }
    
    // u8 key = 0;
    // u8 temp = 0;

    // App_CalNumTube();
    // App_Binprocess();

    // while (1)
    // {
    //     temp = Int_KeyMatrix_CheckKeyIsPreesed();
    //     if (temp != 0)
    //     { // 不能一直刷新！！！！不按的时候刷新之前的
    //         key = temp;
    //     }
    //     Int_DigitalTube_DisplayAllNums(key);
    //     Com_Delay_1ms(1);
    // }

    // if (Int_Key_IsSW1Pressed() == 1)
    // {
    //     LED1 = ~LED1
    // }
    // if (Int_Key_IsSW2Pressed() == 1)
    // {
    //     LED2 = ~LED2
    // }
    // if (Int_Key_IsSW3Pressed() == 1)
    // {
    //     LED3 = ~LED4
    // }
    // if (Int_Key_IsSW4Pressed() == 1)
    // {
    //     LED4 = ~LED4
    // }

    // Int_LED_OrderOnOff();
    // Int_Led_Flow();
    // Int_DigitalTube_DisplayAllNums(2256);
}
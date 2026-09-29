// #include "Int/Int_Digital.h"
#include "Int/Int_Key.h"
#include "Int/Int_Led.h"
#include "Int/Int_KeyMatrix.h"
#include "App/App_CalNumber.h"
#define LED1 P20
#define LED2 P21
#define LED3 P22
#define LED4 P23
void main()
{
    u8 key = 0;
    u8 temp = 0;
    while (1)
    {

    // App_CalNumTube();
    // App_Binprocess();
    

        temp = Int_KeyMatrix_CheckKeyIsPreesed();
        if (temp != 0){
            key = temp;
        }
        Int_DigitalTube_DisplayAllNums(key);
        // Com_Delay_1ms(100);

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
}}
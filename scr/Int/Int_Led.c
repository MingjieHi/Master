#include "Int_Led.h"
static u8 s_temp_P2 = RIGHT_LED;
enum FLAG
{
    LEFT_DREC,
    RIGHT_DERC
};
enum FLAG flag = LEFT_DREC; // LEFT往左移动，RIGHT往右移动

void Int_Led_Flow()
{

    while (1)
    {
        P2 = ~s_temp_P2;
        if (flag == LEFT_DREC)
        {
            s_temp_P2 <<= 1;
            if (s_temp_P2 == LEFT_LED)
            {
                flag = RIGHT_DERC;
            }
        }
        else if (flag == RIGHT_DERC)
        {
            s_temp_P2 >>= 1;
            if (s_temp_P2 == RIGHT_LED)
            {
                flag = LEFT_DREC;
            }
        }
        Com_Delay_1ms(100);
    }
}

void Int_LED_OrderOnOff()
{
    flag = LEFT_DREC;
    // 从左到右
    // 0x01
    // 0000 0001 0x01
    // 0000 0011 0x03 0000 0110 + 0000 0001; = 0x07;
    // 0000 0111 0x07 1111 1111

    s_temp_P2 = LED_OFF;
    while (1)
    {

        // 方向转换
        if (s_temp_P2 == 0x00)
        {
            flag = LEFT_DREC;
            s_temp_P2 = 0x01;
                    // 亮灯
        P2 = ~s_temp_P2;
        Com_Delay_1ms(500); // 500um
        }
        else if (s_temp_P2 == 0xff)
        {
            flag = RIGHT_DERC;
        }




        // 移位
        if (flag == LEFT_DREC)
        {
            s_temp_P2 = (s_temp_P2 << 1) | RIGHT_LED;
        }
        else if (flag == RIGHT_DERC)
        {
            s_temp_P2 >>= 1;
        }

                P2 = ~s_temp_P2;
        Com_Delay_1ms(500); // 500um


 
    }
}

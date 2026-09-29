#include "App_CalNumber.h"
static u8 s_digital_numcode[16] = {      // 数码管的段点位值对应表
                                   0x3f, // 0011 1111  #1
                                   0x06,
                                   0x5b,
                                   0x4f,
                                   0x66,
                                   0x6d,
                                   0x7d,
                                   0x07,
                                   0x7f,
                                   0x6f,
                                   0x77,
                                   0x7c,
                                   0x39,
                                   0x5e,
                                   0x79,
                                   0x71};

void App_CalNumTube()
{
    u8 i = 0;
    u8 s_tempnum1 = 0;
    u8 s_tempnum2 = 0;
    u8 s_tempnum3 = 0;
    u8 s_tempnum4 = 0;
    u32 s_numtotal = 0;
    u8 *ptr1;
    // 获取信号 最高两位 00 - 99
    while (1)
    {
        // 一轮计数
        if (Int_Key_IsSW1Pressed())
        {
            s_tempnum1++;
            if (s_tempnum1 == 100)
            {
                s_tempnum1 = 0;
            }
        }
        else if (Int_Key_IsSW2Pressed())
        {
            s_tempnum2++;
            if (s_tempnum2 == 100)
            {
                s_tempnum2 = 0;
            }
        }
        else if (Int_Key_IsSW3Pressed())
        {
            s_tempnum3++;
            if (s_tempnum3 == 100)
            {
                s_tempnum3 = 0;
            }
        }
        else if (Int_Key_IsSW4Pressed())
        {
            s_tempnum4++;
            if (s_tempnum4 == 100)
            {
                s_tempnum4 = 0;
            }
        }
        // 获取number
        Int_DigitalTube_GetDoubleNum(4, s_tempnum1);
        Int_DigitalTube_GetDoubleNum(3, s_tempnum2);
        Int_DigitalTube_GetDoubleNum(2, s_tempnum3);
        ptr1 = Int_DigitalTube_GetDoubleNum(1, s_tempnum4); // 指针接住
        for (i = 0; i < 8; i++)
        {
            {
                Int_DigitalTube_DisplaySingleNum(i, ptr1[i]);
            }
        }
        Com_Delay_1ms(10);
    }

    // 累加计数
    // 输出显示
}

void App_CalNumTube_easy()
{
    u8 s_tempnum1 = 0;
    u8 s_tempnum2 = 0;
    u8 s_tempnum3 = 0;
    u8 s_tempnum4 = 0;
    u32 s_numtotal = 0;
    // 获取信号 最高两位 00 - 99
    while (1)
    {
        // 一轮计数
        if (Int_Key_IsSW1Pressed())
        {
            s_tempnum1++;
            if (s_tempnum1 == 100)
            {
                s_tempnum1 = 0;
            }
        }
        else if (Int_Key_IsSW2Pressed())
        {
            s_tempnum2++;
            if (s_tempnum2 == 100)
            {
                s_tempnum2 = 0;
            }
        }
        else if (Int_Key_IsSW3Pressed())
        {
            s_tempnum3++;
            if (s_tempnum3 == 100)
            {
                s_tempnum3 = 0;
            }
        }
        else if (Int_Key_IsSW4Pressed())
        {
            s_tempnum4++;
            if (s_tempnum4 == 100)
            {
                s_tempnum4 = 0;
            }
        }
        // 获取number
        s_numtotal = s_tempnum1 * 1000000 + s_tempnum2 * 10000 + s_tempnum3 * 100 + s_tempnum4;
        Int_DigitalTube_DisplayAllNums(s_numtotal);
    }

    // 累加计数
    // 输出显示
}

void App_Binprocess()
{
    static u8 buf[8];
    u8 *ptr;
    u8 i = 0;
    ptr = buf;
    // 1111 1111
    // c初始化为 11111111
    // butom1 是左移 右 +1 和清零
    // 操作数组
    // +1怎么搞 1101 +1 = 1110 写二进制算法 =2 下一个+1 =2 再加
    ptr = Int_DigitalTube_GetDesplayNumCode(11111111);
    // s_digitaltube_numcode
    //  检测按键
    while (1)
    {
        if (Int_Key_IsSW1Pressed())
        {

            for (i = 7; i > 0; i--)
            {
                ptr[i] = ptr[i - 1];
            }
            ptr[0] = s_digital_numcode[0];
        }
        if (Int_Key_IsSW2Pressed())
        {

            for (i = 0; i < 7; i++)
            {
                ptr[i] = ptr[i + 1];
            }
            ptr[7] = s_digital_numcode[0];
        }

        if (Int_Key_IsSW3Pressed())
        { //+1
            for (i = 0; i < 8; i++)
            {
                if (ptr[i] == s_digital_numcode[0])
                {
                    ptr[i] = s_digital_numcode[1];
                    break;
                }
                else
                {
                    ptr[i] = s_digital_numcode[0];
                }
            }
        }
        if (Int_Key_IsSW4Pressed())
        {

            for (i = 0; i < 8; i++)
            {
                ptr[i] = s_digital_numcode[0];
            }
        }
        Int_DigitalTube_FlasNum(ptr);
    }
}

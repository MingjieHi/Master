#include "Int_Digital.h"


static u8  s_digitaltube_numcode[8];//用于存储显示的8个数码管的段点位bit值
static u8 temp_numcode[8];//用于存储显示的8个数码管的段点位bit值
static u8 s_digital_numcode[17] = {//数码管的段点位值对应表
    0x3f, // 0011 1111  #1 0100 0000
    0x06,
    0x5b,
    0x4f,
    0x66,
    0x6d,
    0x7d,
    0x07,
    0x7f,
    0x6f,
    0x40,
    0x77,
    0x7c,
    0x39,
    0x5e,
    0x79,
    0x71};



void Int_DigitalTube_DisplaySingleNum(u8 pos, u8 numbercode)
{
    P2 &= 0xe3; //38译码器的对应引脚置为0
    P2 |= (pos <<= 2); // 完成位置的电平输出,让某个位置的数码管处于低电平。通过38译码器实现。
    P0 = numbercode; 
    Com_Delay_1ms(10);
    P0 = 0x00;//置零
}

// 显示某个数字 0000 0000
//             8765 4321
u8 * Int_DigitalTube_GetDesplayNumCode(u32 number)
{ // 4294967295
    u8 i = 7;
    u8 j = 0;
    // 数码管初始化，全部不显示,所有段都是低电平
    for (j = 0; j < 7; j++)
    {
        s_digitaltube_numcode[i] = 0x00;
    }
    // 循环取出数字，从个位数开始，从最右侧开始村。i=7
    if (number == 0)
    {
        s_digitaltube_numcode[7] = s_digital_numcode[0];
    }
    
    while (number > 0)
    {
        s_digitaltube_numcode[i] = s_digital_numcode[number% 10];
        number = number / 10;
        i--;
    }
    return s_digitaltube_numcode;
}




u8 * Int_DigitalTube_GetDesplaNegtiveNumCode(long number)
{ // 4294967295
    u8 i = 7;
    u8 j = 0;
    // 数码管初始化，全部不显示,所有段都是低电平
    for (j = 0; j < 7; j++)
    {
        s_digitaltube_numcode[i] = 0x00;
    }
    if(number < 0){
        number = -number;
         while (number > 0)
    {
        s_digitaltube_numcode[i] = s_digital_numcode[number% 10];
        number = number/ 10;
        i--;
    }
    s_digitaltube_numcode[i] = s_digital_numcode[10];
    }
    // 循环取出数字，从个位数开始，从最右侧开始村。i=7
    if (number == 0)
    {
        s_digitaltube_numcode[7] = s_digital_numcode[0];
    }
    
    while (number > 0)
    {
        s_digitaltube_numcode[i] = s_digital_numcode[number% 10];
        number = number / 10;
        i--;
    }
    return s_digitaltube_numcode;
}





u8 * Int_DigitalTube_DisplayAllNums(u32 All_Numbers){
    u8 *p; 
    u8 i = 0;
    p = Int_DigitalTube_GetDesplayNumCode(All_Numbers);
    while (1)
    {
        for (i = 0; i < 7; i++)
        {
            {
                Int_DigitalTube_DisplaySingleNum(i, s_digitaltube_numcode[i]);
            }
        }
    }
}



void Int_InitialTube(){
        u8 j = 0;
    // 数码管初始化，全部不显示,所有段都是低电平
    for (j = 0; j < 7; j++)
    {
        temp_numcode[j] = 0x00;
    }
}

u8 * Int_DigitalTube_GetDoubleNum(u8 TubeNumber, u32 number)
{ // 4294967295   1  2  3  4
    u8 i = 2;//只取两位

    // 循环取出数字，从个位数开始，从最右侧开始村。i=7
    if (number == 0)
    {
        temp_numcode[2*TubeNumber-2] = s_digital_numcode[0];
        temp_numcode[2*TubeNumber-1] = 0x00;
    }
    while (number > 0)
    {
        temp_numcode[2*TubeNumber-i] = s_digital_numcode[number% 10];
        number = number / 10;
        i--;
    }
     return temp_numcode;
}


void Int_DigitalTube_FlasNum(u8 arrr[]){
u8 i = 0;
    for ( i = 0; i < 8; i++)
    {
        Int_DigitalTube_DisplaySingleNum(i, arrr[i]);
    }
    
}
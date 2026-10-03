#include "Dir_Timer0.h"

void Dir_Timer0_Init()
{
    //开启中断
    EA = 1;
    ET0 = 1;
    //工作模式 16位计数 Gate =0； C/T = 0; M1=0,M2=1; TR控制
    TMOD &= 0xf0;
    TMOD |= 0x01;
    //c初始值
    TL0 = 64614;
    TH0 = 64614 >> 8;
    //开始计时
    TR0 = 1;

}


void Dri_Timer0_Handler() interrupt 1
{
    static u16 times = 500;
    //重置计数器
    TL0 = 64614;
    TH0 = 64614 >> 8;
    //统计计算次数，500次LED取反
    if (times > 0)
    {
        times --;
    }else{
        LED1 = ~LED1;
        times = 500;
    }
}
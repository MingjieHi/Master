#include "Dir_Timer0.h"

static Timer0Callback s_timer0callbacks[MAX_CALLBACK_COUNT];
void Dir_Timer0_Init()
{
    u8 i = 0;
    // 开启中断
    EA = 1;
    ET0 = 1;
    // 工作模式 16位计数 Gate =0； C/T = 0; M1=0,M2=1; TR控制
    TMOD &= 0xf0;
    TMOD |= 0x01;
    // c初始值
    TL0 = 64614;
    TH0 = 64614 >> 8;
    // 开始计时
    TR0 = 1;
    // 初始化函数数组
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        s_timer0callbacks[i] = NULL;
    }
}

bit Dri_Tier0_RegisterCallback(Timer0Callback callback)
{
    u8 i = 0;
    // 确保不能重复着注册
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (s_timer0callbacks[i] == callback)
        {
            return 1;
        }
    }
    // 注册函数
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (s_timer0callbacks[i] == NULL)
        {
            s_timer0callbacks[i] = callback;
            return 1;
        }
    }
    return 0;
}

bit Dri_Tier0_DeregisterCallback(Timer0Callback callback)
{
    u8 i = 0;
    // 注册函数
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (s_timer0callbacks[i] == callback)
        {
            s_timer0callbacks[i] = NULL;
            return 1;
        }
    }
    return 1;
}

void Dri_Timer0_Handler() interrupt 1
{
    u8 i = 0;
    // 重置计数器
    TL0 = 64614;
    TH0 = 64614 >> 8;
    // 统计计算次数，500次LED取反
    // 轮询调用函数指针数组
    for (i = 0; i < MAX_CALLBACK_COUNT; i++)
    {
        if (s_timer0callbacks[i] != NULL)
        {
            s_timer0callbacks[i]();//遍历数组函数
        }
    }
}

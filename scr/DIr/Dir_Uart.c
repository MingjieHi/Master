#include "Dir_Uart.h"

void Dir_UART_Init()
{
    // 配置接收模式 带不带校验
    SM0 = 0;
    SM1 = 1;
    // 波特lv
    // SMOD
    PCON &= 0x7f; // SMOD 设置为0；i进行2分频
    // 溢出频率
    // 定时器工作模式，初始值
    // 开启定时器

    // 使用8为自动冲转载
    TMOD &= 0x0f;
    TMOD |= 0x20;

    // 初始值 timer buffer 初始值和自动重装载；
    TH1 = 0xfd;
    TL1 = 0xfd;

    // 开启定时器 Timer run
    TR1 = 1;

    // 接收相关
    REN = 1; // 开启接收
    SM2 = 0; // 关闭校验

    // 中断相关
    // 开启中断
    EA = 1;
    ES = 1; // 开启串口中断

    // 复位中断标记位RI TI

    RI = 0;
    TI = 0;
}

void Dir_UART_SendChar(char c)
{
    // 加锁，防止调用混乱，等待锁开；
    while (s_issending == 1)
        ;
    SBUF = c;
    s_issending = 1; // 加锁
}

void Dir_UART_SendSTR(char *str)
{
    // 遍历字符串
    while (*str != '\0')
    {
        Dir_UART_SendChar(str);
        str++;
    }
}

// bit Dir_UART_RsvChar(char *cmd)
// {
//     if (s_buffer)
//     {
//         *cmd = s_buffer;
//         s_buffer = 0; // 维护s_buffer 的值；
//         return 1;
//     }
//     else
//     {
//         return 0;
//     };
// }

bit Dir_UART_RsvStr(char *cmd)
{
    u8 i = 0;
    if (s_buffer[s_index--] == '\n') // 判断结束符
    {
        for (i = 0; i < s_index - 1; i++)
        {
            cmd[i] = s_buffer[i]; //s_buffer 不清不影响;
        }
        cmd[s_index -1] = '\0'; //添加结束符
        s_index = 0;
        return 1;
    }
    else
    {
        return 0;
    }
}

void Dir_UART_Handler() interrupt 4
{

    if (RI == 1)
    {
        s_buffer[s_index] = SBUF;
        s_index++;
        RI = 0;
    }
    if (TI == 1)
    {
        s_issending = 0; // 发送完成调用中断程序，将锁打开；
        TI = 0;
    }
}
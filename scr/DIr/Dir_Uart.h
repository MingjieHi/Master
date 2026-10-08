#ifndef __DIR_UART_H__
#define __DIR_UART_H__
#include "Com/Com_Util.h"
static bit s_issending = 0; //1正在发送
static char s_buffer[10] = {0};
 static u8 s_index = 0;
void Dir_UART_Init();

// void Dir_UART_SendChar(char aaa);
void Dir_UART_SendSTR(char *str);
// bit Dir_UART_RsvChar(char *cmd);
bit Dir_UART_RsvStr(char *cmd);
#endif /* __DIR_UART_H__ */
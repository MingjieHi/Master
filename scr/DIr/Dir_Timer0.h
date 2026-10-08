#ifndef __DIR_TIMER0_H__
#define __DIR_TIMER0_H__
#include "STC89C5xRC.H"
#include "Com/Com_Util.h"
#include "STDIO.H"
#define MAX_CALLBACK_COUNT 4
typedef void (*Timer0Callback)(void); 
void Dir_Timer0_Init();

bit Dri_Tier0_RegisterCallback(Timer0Callback callback);
//void Dri_Timer0_Handler();
bit Dri_Tier0_DeregisterCallback(Timer0Callback callback);
#endif /* __DIR_TIMER0_H__ */
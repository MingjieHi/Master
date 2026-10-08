#ifndef __INT_LEDMATRIX_H__
#define __INT_LEDMATRIX_H__
#include "DIr/Dir_Timer0.h"
#include "Com/Com_Util.h"
// #define LED_MATRIX_EN P35
// #define LED_EN P34
#define SER P34
#define SCK P36
#define RCK P35


// void Int_LEDMatrix_RefreshByTimer0();
void Int_LEDMatrix_Init();
void Int_LEDMatrix_SetPic(u8 pic[]);
void Int_LEDMatrix_ShiftPic(u8 line);
#endif /* __INT_LEDMATRIX_H__ */
#ifndef __INT_DIGITAL_H__
#define __INT_DIGITAL_H__



#include "MATH.H"
#include "Com/Com_Util.h"

u8 * Int_DigitalTube_GetDesplaNegtiveNumCode(long number);
u8 * Int_DigitalTube_GetDoubleNum(u8 TubeNumber, u32 number);
u8 * Int_DigitalTube_DisplayAllNums(u32 All_Numbers);
u8 * Int_DigitalTube_GetDesplayNumCode(u32 number);
void Int_DigitalTube_DisplaySingleNum(u8 pos, u8 numbercode);
void Int_InitialTube();
void Int_DigitalTube_FlasNum(u8 arrr[]);
#endif /* __INT_DIGITAL_H__ */


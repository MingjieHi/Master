#ifndef __INT_BUZZER_H__
#define __INT_BUZZER_H__

#include "Com/Com_Util.h"

#define BUZZER P25
void Int_Buzzer_01s();
void Int_Buzzer_01s_var(u16 Hz, double time);

#endif /* __INT_BUZZER_H__ */
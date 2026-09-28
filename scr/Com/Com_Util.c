#include "Com_Util.h"
void Com_Delay_1ms(count) //@11.0592MHz
{
    u8 data i, j;
    while (count > 0)
    {
        count--;
        _nop_();
        _nop_();
        _nop_();
        i = 11;
        j = 190;
        do
        {
            while (--j)
                ;
        } while (--i);
    }
}
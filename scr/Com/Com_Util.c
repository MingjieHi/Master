#include "Com_Util.h"
void Com_Delay_1ms(u32 count) //@11.0592MHz
{
    while (count > 0)
    {

        u8 data i, j;
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j)
                ;
        } while (--i);

        count--;
    }
}
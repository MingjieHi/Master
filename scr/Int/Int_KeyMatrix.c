#include "Int_KeyMatrix.h"

u8 Int_KeyMatrix_CheckKeyIsPreesed()
{
    // 扫描第一行
    // P10-P17
    // row: 17 16 15 14
    // cols: 13 12 11 10
    u8 rows;
    static u8 s_pressed_button[4][4] = { 1,2,3,4,
                                5,6,7,8,
                                9,10,11,12,
                                13,14,15,16};
    // 0111 1111 0111 1111 > 1 0011 1111 | 1000 0000 > 1 0101 1111 | 1000 0000
    static u8 s_rowsP1x[4] = {0x7f,0xbf,0xdf,0xef};
    // P1 = 0x7f;
    for (rows = 0; rows < 4; rows++)
    {
            P1 = s_rowsP1x[rows];
            // 扫描cols是否被按下
            if (SWx1 == 0)
            {
                Com_Delay_1ms(10); // 销振
                if (SWx1 == 0)
                {
                    while (SWx1 == 0)
                        ;
                    return s_pressed_button[rows][0];
                }
            }

            // 扫描cols是否被按下
            if (SWx2 == 0)
            {
                Com_Delay_1ms(10); // 销振
                if (SWx2 == 0)
                {
                    while (SWx2 == 0)
                        ;
                    return s_pressed_button[rows][1];
                }
            }

            // 扫描cols是否被按下
            if (SWx3 == 0)
            {
                Com_Delay_1ms(10); // 销振
                if (SWx3 == 0)
                {
                    while (SWx3 == 0)
                        ;
                    return s_pressed_button[rows][2];
                }

            }

            // 扫描cols是否被按下
            if (SWx4 == 0)
            {
                Com_Delay_1ms(10); // 销振
                if (SWx4 == 0)
                {
                    while (SWx4 == 0)
                        ;
                    return s_pressed_button[rows][3];
                }

            }
            // P1 = (P1 >1) | 0x80;
    }
        return 99;
    }
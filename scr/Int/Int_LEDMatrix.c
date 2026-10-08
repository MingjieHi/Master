#include "Int_LEDMatrix.h"
void Int_LEDMatrix_RefreshByTimer0();

static u8 s_led_buffer[8];


void Int_LEDMatrix_Init(){
    u8 i;
    for ( i = 0; i < 8; i++)
    {
        s_led_buffer[i] = 0x00;
    }
    //注册刷新函数
    Dri_Tier0_RegisterCallback(Int_LEDMatrix_RefreshByTimer0);    
}


void Int_LEDMatrix_SetPic(u8 pic[]){
    u8 i;
    for ( i = 0; i < 8; i++)
    {
        s_led_buffer[i] = pic[i]; //获取图像信息
    }
    
}

void Int_LEDMatrix_ShiftPic(u8 line)
{
    u8 i = 0;
    for ( i = 7; i >= 1; i--)
    {
        s_led_buffer[i] = s_led_buffer[i-1];
    }
    s_led_buffer[0] = line;
}

void Int_LEDMatrix_RefreshByTimer0()
{
    static u8 i = 0;
    P0 = 0xff;
    //确定行号 完成逐行扫描
    if (i == 0)
    {
        SER = 1; //将1推到右侧完成1000 0100 0010 0001；
    }else{
        SER = 0;
    }
    SCK = 0;
    SCK = 1;

    RCK = 0;
    RCK = 1;



    //确定行的显示内容
    P0 = ~s_led_buffer[i]; //对应阴极取低电平，其他高电平

    i++;
    if (i == 8)
    {
        i=0;
    }
    



}
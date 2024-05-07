#include <REGX52.H>
#include "intrins.h"

// 延迟一毫秒
void Delay1ms(unsigned int xms) //@11.0592MHz
{
    unsigned char i, j;
    while (xms)
    {
        _nop_();
        i = 2;
        j = 199;
        do
        {
            while (--j)
                ;
        } while (--i);
        xms--;
    }
}
// 静态数码管显示

void Nixie(unsigned char Location, unsigned char Number)
{
    unsigned char NixieTable[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
    switch (Location)
    {
    case 1:
        P2_4 = 1;
        P2_3 = 1;
        P2_2 = 1;
        break;
    case 2:
        P2_4 = 1;
        P2_3 = 1;
        P2_2 = 0;
        break;
    case 3:
        P2_4 = 1;
        P2_3 = 0;
        P2_2 = 1;
        break;
    case 4:
        P2_4 = 1;
        P2_3 = 0;
        P2_2 = 0;
        break;
    case 5:
        P2_4 = 0;
        P2_3 = 1;
        P2_2 = 1;
        break;
    case 6:
        P2_4 = 0;
        P2_3 = 1;
        P2_2 = 0;
        break;
    case 7:
        P2_4 = 0;
        P2_3 = 0;
        P2_2 = 1;
        break;
    case 8:
        P2_4 = 0;
        P2_3 = 0;
        P2_2 = 0;
        break;
    }

    P0 = NixieTable[Number];
    Delay1ms(1);
    P0 = 0x00;
}//获取独立按键码
unsigned char Key(){
    unsigned char KeyNumber = 0;
    if(P3_1 ==0){
        Delay1ms(20);
        while(P3_1 ==0)
            ;
        Delay1ms(20);
        KeyNumber = 1;
    }
    if(P3_0 ==0){
        Delay1ms(20);
        while(P3_0 ==0)
            ;
        Delay1ms(20);
        KeyNumber = 2;
    }
    if(P3_2 ==0){
        Delay1ms(20);
        while(P3_2 ==0)
            ;
        Delay1ms(20);
        KeyNumber = 3;
    }
    if(P3_3 ==0){
        Delay1ms(20);
        while(P3_3 ==0)
            ;
        Delay1ms(20);
        KeyNumber = 4;
    }
    return KeyNumber;
}
//定时器
void Timer0Init(void) // 1毫秒@11.0592MHz
{
    TMOD &= 0xF0; // 设置定时器模式
    TMOD |= 0x01; // 设置定时器模式
    TL0 = 0x66;   // 设置定时初值
    TH0 = 0xFC;   // 设置定时初值
    TF0 = 0;      // 清除TF0标志
    TR0 = 1;      // 定时器0开始计时
    ET0 = 1;
    EA = 1;
    PT0 = 0;
}
// 定时器中断模板
// void Timer0_Routine() interrupt 1
// {
//     static unsigned int T0Count = 0;
//     TL0 = 0x66; // 设置定时初值
//     TH0 = 0xFC; // 设置定时初值
//     T0Count++;
//     if (T0Count >= 1000)
//     {
//         T0Count = 0;
//         P2_0 = ~P2_0;
//     }
// }
// 初始化串口
void Uart_Init(void) // 4800bps@11.0592MHz
{
    PCON &= 0x7F; // 波特率不倍速
    SCON = 0x40;  // 8位数据,可变波特率

    TMOD &= 0x0F; // 清除定时器1模式位
    TMOD |= 0x20; // 设定定时器1为8位自动重装方式
    TL1 = 0xFA;   // 设定定时初值
    TH1 = 0xFA;   // 设定定时器重装值
    ET1 = 0;      // 禁止定时器1中断
    TR1 = 1;      // 启动定时器1
}

// 串口向电脑发送数据
void UART_SendByte(unsigned char Byte)
{
    SBUF = Byte;
    while (TI == 0)
        ;
    TI = 0;
}
// LED点阵屏显示图形
sbit RCK = P3 ^ 5; // RCLK
sbit SCK = P3 ^ 6; // SRCLK
sbit SER = P3 ^ 4; // SER
// 74HC595写入一个字节
void _74HC595_WriteByte(unsigned char Byte)
{
    unsigned char i;
    for (i = 0; i < 8; i++)
    {
        SER = Byte & (0x80 >> i);
        SCK = 1;
        SCK = 0;
    }
    RCK = 1;
    RCK = 0;
}
// LED点阵屏显示一列数据
void MatrixLED_ShowColumn(unsigned char Column, unsigned char Data)
{
    _74HC595_WriteByte(Data);
    P0 = ~(0x80 >> Column);
    Delay1ms(1);
    P0 = 0xFF;
}
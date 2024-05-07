#include "LBL.H"

// 2-1 led点亮
// void main()
//  {

//     // P2 = 0x55; //0101 0101
//     // P2 = 0xAA; //1010 1010
// }
// //延时100ms
// void Delay100ms() //@11.0592MHz
// {
//     unsigned char i, j;

//     i = 180;
//     j = 73;
//     do
//     {
//         while (--j)
//             ;
//     } while (--i);
// }
// //延时500ms
// void Delay500ms() //@11.0592MHz
// {
//     unsigned char i, j, k;

//     _nop_();
//     i = 4;
//     j = 129;
//     k = 119;
//     do
//     {
//         do
//         {
//             while (--k)
//                 ;
//         } while (--j);
//     } while (--i);
// }

// 2-2
//  void main()
//  {
//      while (1)
//      {
//          P2 = 0xFE;
//          //延时
//          Delay500ms();
//          P2 = 0xFF;
//          //延时
//          Delay100ms();
//      }
//  }
// 2-3led流水灯
// void main()
// {
//     // int i = 0;//0000 0000为全亮1111 1111为全灭
//     while (1)
//     {
//         P2 = 0xFE; // 1111 1110
//         Delay1ms(100);
//         P2 = 0xFD; // 1111 1101
//         Delay1ms(100);
//         P2 = 0xFB; // 1111 1011
//         Delay1ms(100);
//         P2 = 0xF7; // 1111 0111
//         Delay1ms(100);
//         P2 = 0xEF; // 1110 1111
//         Delay1ms(100);
//         P2 = 0xDF; // 1011 1111
//         Delay1ms(100);
//         P2 = 0xBF; // 1011 1111
//         Delay1ms(100);
//         P2 = 0x7F; // 0111 1111
//         Delay1ms(100);
//         //     Delay500ms();
//         //     P2<<1;
//         //     if(i==0xff){
//         //         P2 = 0x00;
//         //     }
//         // }
//     }
// }
// LED流水灯
// void main(){
//     while(1){
//         if(P2==0xFF){
//             P2 == 0xFE;
//         }
//         P2 = 0xFE;
//         Delay1ms(200);
//         P2 = P2 << 1;
//         P2++;

//     }
// }
// 按键点亮LED
// void main(){

//      while(1){
//          if(P3_1==0){
//             //消除按键抖动
//              Delay1ms(20);
//              while (P3_1 == 0)
//                  ;
//              Delay1ms(20);
//              P2_0 = ~P2_0;

//          }
//      }
// }

// 独立按键控制LED显示二进制
//  void main(){

//     while(1){
//         if(P3_1==0){
//             Delay1ms(20);
//             while(P3_1==1){

//             }
//             Delay1ms(200);
//             P2++;
//         }
//         if (P3_0 == 0)
//         {
//             Delay1ms(20);
//             while (P3_0 == 1)
//             {
//             }
//             Delay1ms(200);
//             P2--;
//         }
//     }
// }
// 独立按键控制LED流水灯
// void main()
// {
//     P2 = 0xFE; // 1111 1110
//     while (1)
//     {
//         if (P3_0 == 0)
//         {
//             Delay1ms(20);
//             while (P3_0 == 1)
//                 ;
//             Delay1ms(20);
//             Delay1ms(200);
//             P2 = P2 << 1;
//             if (P2 != 0xFE)
//             { // 1111 1110
//                 P2++;
//             }
//         }
//         if (P3_1 == 0)
//         {
//             Delay1ms(20);
//             while (P3_1 == 1)
//                 ;
//             Delay1ms(20);
//            Delay1ms(200);
//             P2 = P2 >> 1; // 0111 1111
//             P2 = P2 + 0x80; // 1111 1111
//             if (P2 == 0xFF) // 1111 1110 //1111 1111
//             {
//                 P2 = 0x7F; //
//             }
//         }
//     }
// }

// 数码管动态显示
//   void main(){

//     while(1){
//         Nixie(1,1);
//         Delay1ms(50);
//         Nixie(2, 2);
//         Delay1ms(50);

//         Nixie(3, 3);
//         Delay1ms(50);

//         Nixie(4, 4);
//         Delay1ms(50);

//         Nixie(5, 5);
//         Delay1ms(50);

//         Nixie(6, 6);
//         Delay1ms(50);

//         Nixie(7, 7);
//         Delay1ms(50);

//         Nixie(8,
// LCD函数
// void main(){
//     LCD_Init();//初始化
//     //LCD_ShowChar(1,1,'A');//打印单个字符
//     LCD_ShowString(1, 3, "LBLLBL");//打印字符串
//     LCD_ShowNum(2, 1, 666, 3);//打印最大65536的数字
//     LCD_ShowSignedNum(2, 4, 666, 3);//打印+-32768的数字
//     LCD_ShowHexNum(2,1,0xA8,2)//打印十六进制数
//     LCD_ShowBinNum(2,4,0xAA,8)//打印二进制数
//     while(1){
//     }
// }
// // 读秒
// void main()
// { int s = 0;
//     LCD_Init();

//     while(1){
//         LCD_ShowNum(1, 1, s, 5);
//         Delay1ms(1000);
//         s++;

//     }
// }
// 矩阵键盘测试
// void main(){
//     unsigned char KeyNum ;
//     LCD_Init();
//     LCD_ShowString(1, 1, "HelloLBL");

//     while(1){
//         KeyNum = (char)MatrixKey();
//         if(KeyNum){
//             LCD_ShowNum(2, 1, KeyNum, 2);
//         }
//     }
// }
///////////////////////////////////////////////////////
// 矩阵键盘密码锁
// void main()
// {
//     unsigned char KeyNum;
//     unsigned int Password;
//     LCD_Init();
//     LCD_ShowString(1, 1, "HelloLBL");
//     while (1)
//     {
//         KeyNum = (char)MatrixKey();
//         if (KeyNum)
//         {
//             if (KeyNum <= 10 && Password < 1000) // 限制位数
//             {
//                 Password = Password * 10;          // 密码左移一位
//                 Password = Password + KeyNum % 10; // 密码添加一位
//             }
//             if (KeyNum == 11)
//             {
//                 // 确认键
//                 if (Password == 2345)
//                 { // 比较密码
//                     LCD_ShowString(1, 14, "OK ");
//                     Password = 0;
//                     LCD_ShowNum(2, 1, Password, 4);
//                 }
//                 else
//                 {
//                     LCD_ShowString(1, 14, "ERR");
//                     Password = 0;
//                     LCD_ShowNum(2, 1, Password, 4);
//                 }
//             }
//             if (KeyNum == 12){
//                 Password = 0;
//                 LCD_ShowNum(2, 1, Password, 4);
//             }
//                 LCD_ShowNum(2, 1, Password, 4);
//         }
//     }
// }
///////////////////////////////////////////////////////
// 定时器
// 控制小灯左右循环点亮
// unsigned char LEDMode = 0;

// void main()
// {P2 = 0xFE;
//     Timer0Init();
//     while (1)
//     {
//         unsigned char KeyNum = Key();

//         if (KeyNum)
//         {
//             if (KeyNum == 1)
//             {
//                 LEDMode++;
//                 if(LEDMode ==2){
//                     LEDMode = 0;
//                 }
//             }
//         }
//     }
// }
// //定时器中断模板
// void Timer0_Routine() interrupt 1
// {
//     static unsigned int T0Count = 0;
//     TL0 = 0x66; // 设置定时初值
//     TH0 = 0xFC; // 设置定时初值
//     T0Count++;
//     if (T0Count >= 200)
//     {
//         T0Count = 0;
//         if (LEDMode == 0){
//             P2 = _crol_(P2, 1);

//         }else if(LEDMode ==1){
//             P2 = _cror_(P2, 1);
//         }
//     }
// }
// //定时器___时钟
//  unsigned int ms = 0;
//  unsigned int Sec = 0;
//  unsigned int Min = 0;
//  unsigned int Hour = 0;
//  unsigned int Day = 0;
// void main(){
//     LCD_Init();
//     Timer0Init();
//     LCD_ShowString(2, 1, "  DAY  :  :  :");
//     LCD_ShowString(1, 1, "CLOCK:");
//     while(1){
//         LCD_ShowNum(2, 1, Day, 2);
//         LCD_ShowNum(2, 6, Hour, 2);
//         LCD_ShowNum(2, 9, Min, 2);
//         LCD_ShowNum(2, 12, Sec, 2);
//         LCD_ShowNum(2, 15, ms, 2);
//     }

// }
// void Timer0_Routine() interrupt 1{

//         TL0 = 0x66; // 设置定时初值
//          TH0 = 0xFC; // 设置定时初值
//          ms++;
//          if(ms==1000){
//              Sec++;
//              ms = 0;
//              if(Sec ==60){
//                  Min++;
//                  Sec = 0;
//                  if(Min==60){
//                      Hour++;
//                      Min = 0;
//                      if(Hour==24){
//                          Day++;
//                          Hour = 0;
//                          if(Day == 99){
//                              Day = 0;
//                          }
//                      }

//                  }
//              }
//          }
// }
//
// 初始化单片机向电脑发送数据
// void Uart_Init(void) // 4800bps@11.0592MHz
// {
//     PCON &= 0x7F; // 波特率不倍速
//     SCON = 0x40;  // 8位数据,可变波特率

//     TMOD &= 0x0F; // 清除定时器1模式位
//     TMOD |= 0x20; // 设定定时器1为8位自动重装方式
//     TL1 = 0xFA;   // 设定定时初值
//     TH1 = 0xFA;   // 设定定时器重装值
//     ET1 = 0;      // 禁止定时器1中断
//     TR1 = 1;      // 启动定时器1
// }

// //单片机向电脑发送数据
// void UART_SendByte(unsigned char Byte){
//     SBUF = Byte;
//     while(TI==0)
//         ;
//     TI = 0;
// }
// void main(){
//     Uart_Init();
//     while(1){
//         UART_SendByte(0x66);
//     }
// }
// //
//////////////////////////////////////////////////////////////////////
// 初始化电脑向单片机发送数据
//  void Uart_Init1(void) // 4800bps@11.0592MHz
//  {
//      PCON &= 0x7F; // 波特率不倍速
//      SCON = 0x50;  // 8位数据,可变波特率

//     TMOD &= 0x0F; // 清除定时器1模式位
//     TMOD |= 0x20; // 设定定时器1为8位自动重装方式
//     TL1 = 0xFA;   // 设定定时初值
//     TH1 = 0xFA;   // 设定定时器重装值
//     ET1 = 0;      // 禁止定时器1中断
//     TR1 = 1;      // 启动定时器1
//     EA = 1;
//     ES = 1;
// }
//
// void main(){
//     Uart_Init1();
//     while(1){

//     }
// }
// void UART_Routine(void) interrupt 4{
//     if(RI ==1){
//         P2 = ~SBUF;
//         RI = 0;
//     }
// }
//////////////////////////////////////////////////////////////////////////////////
// // LED点阵屏显示图形
// sbit RCK = P3 ^ 5; // RCLK
// sbit SCK = P3 ^ 6; // SRCLK
// sbit SER = P3 ^ 4; // SER
// // 74HC595写入一个字节
// void _74HC595_WriteByte(unsigned char Byte)
// {
//     unsigned char i;
//     for (i = 0; i < 8; i++)
//     {
//         SER = Byte & (0x80 >> i);
//         SCK = 1;
//         SCK = 0;
//     }
//     RCK = 1;
//     RCK = 0;
// }
// //LED点阵屏显示一列数据
// void MatrixLED_ShowColumn(unsigned char Column, unsigned char Data)
// {
//     _74HC595_WriteByte(Data);
//     P0 = ~(0x80 >> Column);
//     Delay1ms(1);
//     P0 = 0xFF;
// }
// void main()
// {
//     SCK = 0;
//     RCK = 0;
//     while (1)
//     {
//         MatrixLED_ShowColumn(0, 0x38);
//         MatrixLED_ShowColumn(1, 0x7C);
//         MatrixLED_ShowColumn(2, 0x7E);
//         MatrixLED_ShowColumn(3, 0x3F);
//         MatrixLED_ShowColumn(4, 0x3F);
//         MatrixLED_ShowColumn(5, 0x7E);
//         MatrixLED_ShowColumn(6, 0x7C);
//         MatrixLED_ShowColumn(7, 0x38);
//     }
// }
////////////////////////////////////////////////////////////////////
// LED显示动画LBL
unsigned char code Animation[] = {//code关键字会存储到flash,缺点是不能更改
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0xFF,
    0x01,
    0x01,
    0x01,
    0x01,
    0x00,
    0xFF,
    0x91,
    0x91,
    0x69,
    0x06,
    0x00,
    0xFF,
    0x01,
    0x01,
    0x01,
    0x01,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,

};
void main()
{
    char i = 0;
    char count = 10;
    while (1)
    {
        if (i >= 25)
        {
            i = 0;
        }
        MatrixLED_ShowColumn(0, Animation[0+i]);
        MatrixLED_ShowColumn(1, Animation[1 + i]);
        MatrixLED_ShowColumn(2, Animation[2 + i]);
        MatrixLED_ShowColumn(3, Animation[3 + i]);
        MatrixLED_ShowColumn(4, Animation[4 + i]);
        MatrixLED_ShowColumn(5, Animation[5 + i]);
        MatrixLED_ShowColumn(6, Animation[6 + i]);
        MatrixLED_ShowColumn(7, Animation[7 + i]);
if(count ==10){
    count = 0;
    i++;
}
count++;
    }
}
//////////////////////////////////////////////////////////////////////////////////////////
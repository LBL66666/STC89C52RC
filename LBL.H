#ifndef __LBL_H__
#define __LBL_H__
#include <REGX52.H>
#include "intrins.h"
#include "LCD1602.h"//LCD屏幕
#include "MatrixKey.h"//矩阵键盘

// 延迟一毫秒//@11.0592MHz
void Delay1ms(unsigned int xms); 
// 静态数码管显示
void Nixie(unsigned char Location, unsigned char Number);
// 获取独立按键码
unsigned char Key();
// 定时器
void Timer0Init(void); // 1毫秒@11.0592MHz
//初始化串口
void Uart_Init(void);
// 串口向电脑发送数据
void UART_SendByte(unsigned char Byte);
// 74HC595写入一个字节
void _74HC595_WriteByte(unsigned char Byte);
// LED点阵屏显示一列数据
void MatrixLED_ShowColumn(unsigned char Column, unsigned char Data);

#endif
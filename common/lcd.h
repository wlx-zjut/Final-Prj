/*
 * lcd.h
 *
 *  Created on: 2017-3-30
 *      Author: Administrator
 */

#ifndef LCD_H_
#define LCD_H_
#include "ICETEK-VC5509-EDU.h"
#include "include.h"

#define LCDDELAY 1

// ICETEK-CTR  --------------------------------------------------
#define CTRGR (*(unsigned int *)0x600800)
#define CTRKEY (*(unsigned int *)0x602800)
#define CTRCLKEY (*(unsigned int *)0x600801)
#define CTRLA (*(unsigned int *)0x602802)
#define CTRLR (*(unsigned int *)0x602803)
#define CTRLCDCMDR (*(unsigned int *)0x602800)
#define CTRLCDCR (*(unsigned int *)0x600801)
#define CTRLCDLCR (*(unsigned int *)0x602801)
#define CTRLCDRCR (*(unsigned int *)0x600802)
// Special values -----------------------------------------------
#define LCDCMDTURNON 0x3f
#define LCDCMDTURNOFF 0x3e
#define LCDCMDSTARTLINE 0xc0
#define LCDCMDPAGE 0xb8
#define LCDCMDVERADDRESS 0x40
// C6713DSP Registers  ------------------------------------------
//cregister unsigned int IER,IFR,CSR,ICR,ISTP;


#define nMusicNumber 52



// Functions
//void InitInterrupt(void);			// ��ʼ���ж�
void Lcd_Show();
void Lcd_Test();
void Lcd_Paint(const uint8 data[]);
void InitCTR();						// ��ʼ��ICETEK-CTR
void CloseCTR();					// �ر�ICETEK-CTR�ϸ��豸
void Delay(unsigned int nTime);		// ��ʱ�ӳ���
void Delay1(unsigned int nTime);	// ��ʱ�ӳ���(��LED��ʾˢ��)
unsigned char GetKey();				// ��ȡ��������
void RefreshLEDArray();				// ˢ�·��������������ʾ
void SetLEDArray(int nNumber);		// �޸ķ��������������ʾ����
char ConvertScanToChar(unsigned char cScanCode);	// ������ɨ����ת�����ַ�
void LCDCMD(unsigned char dbCommand);	// ��Һ����ʾ����������
void LCDWriteLeft(unsigned char dbData);	// дҺ����ʾ�������
void LCDWriteRight(unsigned char dbData);   // дҺ�����Ұ���
void LCDCLS();							// ���Һ����ʾ����ʾ
void TurnOnLCD();						// ��Һ����ʾ��
void Lcd_Wave();
void Lcd_SimpleWave(int *p,int N);
void Lcd_PrintChar(int x,int y,int c);

void Lcd_Draw_Line(int x, int y) ;
void Lcd_Draw_Line2(int x, int y) ;
void Lcd_Draw_Axes();
void yzhou1();//0-56
void yzhou2();//0-42
void yzhou3();//0-28
void yzhou4();//0-14
void Writee(int wpage,int m);

void Lcd_Tune();
void Lcd_Print(int,int,int,int,int);
void Lcd_PrintF();

void showhz(int flag);
void showvalue(int x, int y ,int n);

#endif /* LCD_H_ */

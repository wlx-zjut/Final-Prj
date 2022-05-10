#include "scancode.h"

// emif  --------------------------------------------------------
/*
#define EMIF_GCTL       0x01800000
#define EMIF_CE1        0x01800004
#define EMIF_CE0        0x01800008
#define EMIF_CE2        0x01800010
#define EMIF_CE3        0x01800014
#define EMIF_SDRAMCTL   0x01800018
#define EMIF_SDRAMTIM   0x0180001C
#define EMIF_SDRAMEXT   0x01800020
#define EMIF_CCFG       0x01840000;
*/
// interrupt  --------------------------------------------------
/*
#define IMH (*(unsigned int *)0x19c0000)
#define IML (*(unsigned int *)0x19c0004)
*/
// timer  -------------------------------------------------------
/*
#define TIMER1CTL (*(unsigned int *)0x01980000)
#define TIMER1PRD (*(unsigned int *)0x01980004)
*/
// McBSP0  ------------------------------------------------------
#define SPCR0 (*(unsigned int *)0x018c0008)
#define PCR0 (*(unsigned int *)0x018c0024)
#define SPCR01 (*(unsigned int *)0x01900008)
#define SPCR02 (*(unsigned int *)0x0)
// McBSP1  ------------------------------------------------------
ioport unsigned int *SPCR21=(unsigned int *)0x2c04;
ioport unsigned int *PCR_1=(unsigned int *)0x2c12;
#define SPCR2_1 (*SPCR21)
#define PCR1 (*PCR_1)

// ICETEK-VC5509-A -----------------------------------------------
#define LBDS (*((unsigned int *)0x400001))
#define DIPS (*(unsigned int *)0x400002)
// ICETEK-CTR  --------------------------------------------------
#define CTRGR (*(unsigned int *)0x600800)		//ȫ�ֿ��ƼĴ���
#define CTRKEY (*(unsigned int *)0x602800)		//�������ݻض��Ĵ���
#define CTRCLKEY (*(unsigned int *)0x600801)	//������̼Ĵ���
#define CTRLA (*(unsigned int *)0x602802)		//��������ܿ��ƼĴ���
#define CTRLR (*(unsigned int *)0x602803)		//�������ƼĴ���
#define CTRLCDCMDR (*(unsigned int *)0x602800)	//Һ����Ļָ��Ĵ���
#define CTRLCDCR (*(unsigned int *)0x600801)	//Һ����Ļ�����Ĵ���
#define CTRLCDLCR (*(unsigned int *)0x602801)	//�����Ļ����д�Ĵ���
#define CTRLCDRCR (*(unsigned int *)0x600802)	//�Ұ���Ļ����д�Ĵ���
// Special values -----------------------------------------------
#define LCDCMDTURNON 0x3f
#define LCDCMDTURNOFF 0x3e
#define LCDCMDSTARTLINE 0xc0
#define LCDCMDPAGE 0xb8
#define LCDCMDVERADDRESS 0x40
// C6713DSP Registers  ------------------------------------------
//cregister unsigned int IER,IFR,CSR,ICR,ISTP;

// Variables
unsigned char ledbuf[8],ledx[8];
unsigned char ledkey[10][8]=
{
	{0x00,0x00,0x7C,0x82,0x82,0x82,0x7C,0x00},	//0
	{0x00,0x00,0x00,0x84,0xFE,0x80,0x00,0x00},	//1
	{0x00,0x00,0x84,0xC2,0xA2,0x92,0x8C,0x00},	//2
	{0x00,0x00,0x44,0x92,0x92,0x92,0x6C,0x00},
	{0x00,0x00,0x30,0x28,0x24,0xFE,0x20,0x00},
	{0x00,0x00,0x4E,0x92,0x92,0x92,0x62,0x00},
	{0x00,0x00,0x7C,0x92,0x92,0x92,0x64,0x00},
	{0x00,0x00,0x02,0xC2,0x32,0x0A,0x06,0x00},
	{0x00,0x00,0x6C,0x92,0x92,0x92,0x6C,0x00},
	{0x00,0x00,0x4C,0x92,0x92,0x92,0x7C,0x00}
};
#define nMusicNumber 52
unsigned int music[nMusicNumber][2]=
{
	{101,1920},{121,1440},{114,480},{101,1920},{151,1920},
	{151,480},{135,480},{121,480},{101,480},{114,960},{121,960},{135,3840},
	{121,480},{114,480},{101,480},{91,480},{101,960},{101,960},
	{76,1920},{101,1920},{114,960},{121,960},{135,1440},{151,480},{151,1920},{0,1920},
	{101,1920},{121,1440},{114,480},{101,1920},{151,1920},
	{151,480},{135,480},{121,480},{101,480},{114,960},{121,960},{135,3840},
	{121,480},{114,480},{101,480},{91,480},{101,960},{101,960},
	{76,1920},{101,1920},{114,960},{121,960},{135,1440},{151,480},{151,1920},{0,1920}
};
unsigned int pwm[8]={ 0x86,0x87,0x83,0x8b,0x89,0x8d,0x8c,0x8e };
unsigned char dbClearKey;

// Functions
void InitInterrupt(void);			// ��ʼ���ж�
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
void LCDCLS();							// ���Һ����ʾ����ʾ
void TurnOnLCD();						// ��Һ����ʾ��

void CloseCTR()
{
    CTRGR=0; 				 
    CTRLR=0; CTRLR=0x40;
    CTRLR=0x0c0;
	LCDCMD(LCDCMDTURNOFF);	
	dbClearKey=CTRCLKEY;
	LBDS=0;
}

void LCDCMD(unsigned char dbCommand)
{
	CTRLCDCMDR=dbCommand;		
	CTRLCDCR=0;
}

unsigned char GetKey(){
	unsigned char dbReturn;
	
	dbReturn=CTRKEY;
	Delay(200);
	if(CTRKEY!=0)
	{
		dbReturn=CTRKEY;
		dbClearKey=CTRCLKEY;   //��һ�¾�����
		return dbReturn;
	}
	else return 0;
}

char ConvertScanToChar(unsigned char cScanCode)
{
	char cReturn;
	
	cReturn=0;
	switch ( cScanCode )
	{
		case SCANCODE_1: cReturn='1'; break;
		case SCANCODE_2: cReturn='2'; break;
		case SCANCODE_3: cReturn='3'; break;
		case SCANCODE_4: cReturn='4'; break;
		case SCANCODE_5: cReturn='5'; break;
		case SCANCODE_6: cReturn='6'; break;
		case SCANCODE_7: cReturn='7'; break;
		case SCANCODE_8: cReturn='8'; break;
		case SCANCODE_9: cReturn='9'; break;
	}
	return cReturn;
}

void InitCTR()
{
    CTRGR=0; CTRGR=0x80; CTRGR=0;
    CTRLR=0; CTRLR=0x40;
    CTRLR=0x0c0;
	LCDCMD(LCDCMDTURNOFF);	
	dbClearKey=CTRCLKEY;
	LBDS=0;
}

void Delay(unsigned int nDelay)
{
	int ii,jj,kk=0;
	for ( ii=0;ii<nDelay;ii++ )
	{
		for ( jj=0;jj<1024;jj++ )
		{
			kk++;
		}
	}
}

void Delay1(unsigned int nDelay)
{
	int ii,jj,kk=0;
	for ( ii=0;ii<nDelay;ii++ )
	{
		for ( jj=0;jj<64;jj++ )
		{
			RefreshLEDArray();
			kk++;
		}
	}
}

void RefreshLEDArray()
{
	int i;
	for ( i=0;i<8;i++ )
	{
		CTRGR=ledx[i];
		CTRLA=ledbuf[i];
	}
}

void SetLEDArray(int nNumber)
{
	int i;
	for ( i=0;i<8;i++ )
		ledbuf[i]=~ledkey[nNumber][7-i];
}

void LCDWriteLeft(unsigned char dbData)
{
	CTRLCDLCR=dbData;
	CTRLCDCR=0;
}

void LCDWriteRight(unsigned char dbData)
{
	CTRLCDRCR=dbData;
	CTRLCDCR=0;
}

void TurnOnLCD()
{
	LCDCMD(LCDCMDTURNON);
}

void LCDCLS()
{
	int i,j;
	LCDCMD(LCDCMDSTARTLINE);
	for ( i=0;i<8;i++ )
	{
		LCDCMD(LCDCMDPAGE+i);
		LCDCMD(LCDCMDVERADDRESS);
		for ( j=0;j<64;j++ )
			LCDWriteLeft(0);
		LCDCMD(LCDCMDPAGE+i);
		LCDCMD(LCDCMDVERADDRESS);
		for ( j=0;j<64;j++ )
			LCDWriteRight(0);
	}
}





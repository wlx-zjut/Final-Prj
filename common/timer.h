/*
 * timer.h
 *
 *  Created on: 2017-3-29
 *      Author: Administrator
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "5509.h"
#include "C5509.h"
//#include "func.h"
#include "ICETEK-VC5509-EDU.h"
#include "typede.h"
// ����ָʾ�ƼĴ�����ַ�ͼĴ�������
//#define LBDS (*((unsigned int *)0x400001))


//void PLL_Init(int freq);
void INTR_init( );
void TIMER1_init(void);
void TIMER_init(void);


#endif /* TIMER_H_ */

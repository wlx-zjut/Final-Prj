//  ����ʱ��Ƶ���J5����Դ��J7����������
#include "5509.h"
#include "util.h"
#include "func.h"
#include <dsplib.h>
#include <TMS320.H>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
void wait( unsigned int cycles );
void EnableAPLL( );
extern short sample[256];
long final[128];

int i;
void main()
{
    SDRAM_init();
    EnableAPLL();
    PLL_Init(40);
    AIC23_Init();
    AIC23_Mixer_Init();
    while(1){
        AIC23_Mixer();
        rfft(sample,256,SCALE);
        for(i=0;i<128;i++){
           final[i]=sqrt((long)sample[2*i]*(long)sample[2*i]+(long)sample[2*i+1]*(long)sample[2*i+1]);
        }
    }
}
void wait( unsigned int cycles )
{
    int i;
    for ( i = 0 ; i < cycles ; i++ ){ }
}

void EnableAPLL( )
{
    /* Enusre DPLL is running */
    *( ioport volatile unsigned short* )0x1f00 = 4;

    wait( 25 );

    *( ioport volatile unsigned short* )0x1f00 = 0;

    // MULITPLY
    *( ioport volatile unsigned short* )0x1f00 = 0x3000;

    // COUNT
    *( ioport volatile unsigned short* )0x1f00 |= 0x4F8;

    wait( 25 );

    //*( ioport volatile unsigned short* )0x1f00 |= 0x800

    // MODE
    *( ioport volatile unsigned short* )0x1f00 |= 2;

    wait( 30000 );

    // APLL Select
    *( ioport volatile unsigned short* )0x1e80 = 1;

    // DELAY
    wait( 60000 );
}
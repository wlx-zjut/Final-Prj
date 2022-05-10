#include "ICETEK-VC5509-EDU.h"
#include "WordLibrary.h"//字符库
#include "lcddisplay.h"
#define LCDDELAY 1
void lcdInit()//初始化LCD屏幕
{
    TurnOnLCD();                // 打开显示
    LCDCLS();               // 清除显示内存
    CTRLCDCMDR=LCDCMDSTARTLINE;     // 设置显示起始行
    Delay(LCDDELAY);
    CTRLCDCR=0;
    Delay(LCDDELAY);
}

void showChar(int x,int y,int num)//列，页，显示字符  16行x8列
{
    int i,j,Left_or_Right;
    num=num-' ';//得到与' '的ASC码差值
    Left_or_Right=x;//变量Left_or_Right用来判断处于左右半屏的哪一块，统一屏幕显示代码

    for(i=0;i<2;i++)
    {
        CTRLCDCMDR=LCDCMDPAGE+i+y;  //选页
        CTRLCDCR=0;
        if(Left_or_Right<64)//在左半屏幕
            CTRLCDCMDR=LCDCMDVERADDRESS+x;  // 起始列
        else//右半屏额外-64
            CTRLCDCMDR=LCDCMDVERADDRESS+x-64;
        CTRLCDCR=0;
        for(j=0;j<8;j++)
        {
            if(Left_or_Right<64)
                CTRLCDLCR =  Word[num][j+i*8];//左半屏数据写入
            else
                CTRLCDRCR=Word[num][j+i*8];//右半屏数据写入
            Delay(LCDDELAY);
            CTRLCDCR=0;
            Delay(LCDDELAY);
        }
    }
}
//显示字符串函数
void showString(int x,int y,char*p)//页，列，字符串  16行x8列
{
    while ((*p <= '~') && (*p >= ' '))       //判断是不是非法字符!
    {
        showChar(x, y, *p);
        x += 8;
        p++;
    }
}
//横向写汉字，起始页，起始列,字数
void showcharacter_h(int x,int y,int length)//       16行x16列
{
    int k,i,j,Left_or_Right;
    for(k=0;k<length;k++)
    {
        for(i=0;i<2;i++)
        {
            CTRLCDCMDR=LCDCMDPAGE+i+x;   //选页
            CTRLCDCR=0;
            Left_or_Right=k*16+y;           //为让左右屏代码一样
            if(Left_or_Right<64)
               CTRLCDCMDR=LCDCMDVERADDRESS+k*16+y;    // 起始列
            else
               CTRLCDCMDR=LCDCMDVERADDRESS+k*16+y-64; // 起始列
               CTRLCDCR=0;
            for(j=0;j<16;j++)
            {
               if(Left_or_Right<64)//如果列号小于64说明在左半屏显示
                    CTRLCDLCR =  character[i+2*k][j];//所以调用左半屏的写入函数
               else//否则就在右半屏显示
                    CTRLCDRCR =  character[i+2*k][j];
               Delay(LCDDELAY);
               CTRLCDCR=0;
               Delay(LCDDELAY);
            }
        }
    }
}
//纵向显示
void showcharacter_v(int x,int y,int length)//       16行x16列
{
    int i,j,k,Left_or_Right;
    Left_or_Right = y;
    for(k = 0;k<length;k++)
    {
        for(i=0;i<2;i++)
                     {
                       CTRLCDCMDR=LCDCMDPAGE+x+i+2*k;//显示页
                       CTRLCDCR=0;
                       if(Left_or_Right<64)
                           CTRLCDCMDR=LCDCMDVERADDRESS+y;    // 起始列
                       else
                           CTRLCDCMDR=LCDCMDVERADDRESS+y-64;
                       CTRLCDCR=0;
                       for(j=0;j<16;j++)
                          {
                            if(Left_or_Right<64)
                                CTRLCDLCR =character[i+2*k][j];//显示字
                            else
                                CTRLCDRCR =character[i+2*k][j];
                            Delay(LCDDELAY);
                            CTRLCDCR=0;
                          }
                     }
    }
}
void setpage(int page)                  // 设置操作页
{
    CTRLCDCMDR=LCDCMDPAGE+7-page;
    Delay(LCDDELAY);
    CTRLCDCR=0;
    Delay(LCDDELAY);
}
void setcolumn(int column)              //设置列
{
    CTRLCDCMDR=LCDCMDVERADDRESS+column;
    Delay(LCDDELAY);
    CTRLCDCR=0;
    Delay(LCDDELAY);
}
void printleft(unsigned char data)      //画左半屏
{
    CTRLCDLCR=data;                     //将显示数组送入左半屏数据控制接口
    Delay(LCDDELAY);
    CTRLCDCR=0;
    Delay(LCDDELAY);
}
void printright(unsigned char data)     //画右半屏
{
    CTRLCDRCR=data;                     //将显示数组送入右左半屏数据控制接口
    Delay(LCDDELAY);
    CTRLCDCR=0;
    Delay(LCDDELAY);
}

unsigned char ledpoint[8]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};//ledpoint[8]为由下到上依次点亮一个像素点数组
void ShowPoint(int j,int i)             //画单点函数
    {
        setpage(i/8);
        if(j<64)                        //判断点所在列在左半屏
        {
            setcolumn(j);
            printleft(ledpoint[i%8]);
        }
        else                            //判断点所在列在右半屏
        {
            setcolumn(j-64);
            printright(ledpoint[i%8]);
        }
    }


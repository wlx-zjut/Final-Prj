#include "5509.h"
#include "util.h"
extern DSPCLK dspclk;
I2C_Init()
{
    PC55XX_I2C pI2C = (PC55XX_I2C)C55XX_I2C_ADDR;

    //��I2C��������λ
    ClearMask(pI2C -> icmdr, ICMDR_IRS);
    
    //����Ԥ��Ƶ������12MHzʱ��
    pI2C -> icpsc = dspclk.pllmult;
       
    //����ʱ�ӿ��ƼĴ���(100KHzʱ�����)
    Write(pI2C -> icclkl, 10);  // For 400KHz, use 47 for 100KHz
    Write(pI2C -> icclkh, 10);
        
    //�������ʹӵ�ַ
    WriteMask(pI2C -> icoar, ICOAR_OADDR, ICOAR_MASK_7);

    //��I2C�������Ӹ�λ��ȡ����������ģʽ
    SetMask(pI2C -> icmdr, ICMDR_IRS | ICMDR_MST);
}

I2C_Disable()
{
    PC55XX_I2C pI2C = (PC55XX_I2C)C55XX_I2C_ADDR;

    //��I2C��������λ
    ClearMask(pI2C -> icmdr, ICMDR_IRS);    
}

void I2C_Write(unsigned short int device, int count, unsigned char *bytedata)
{
    PC55XX_I2C pI2C = (PC55XX_I2C)C55XX_I2C_ADDR;  //I2C��λ
    int i;
        
    //����I2C������д��һ�������ֽ���
    Write(pI2C -> iccnt, count);      //��countд��iccnt
    WriteMask(pI2C -> icsar, device, ICSAR_MASK_7);
    WriteMask(pI2C -> icmdr,
        ICMDR_STT | ICMDR_STP | ICMDR_TRX,
        ICMDR_STT | ICMDR_STP | ICMDR_TRX);
        
    //��������
    for (i = 0; i < count ; i++) {
        Write(pI2C -> icdxr, bytedata[i]);   //�ѼĴ�����ַ�����ݶ���I2C�Ľ��ռĴ�����
        while(!(pI2C -> icstr & ICSTR_ICXRDY));
    }
}

void I2C_Read(unsigned short int device, int count, unsigned char *bytedata)
{
    PC55XX_I2C pI2C = (PC55XX_I2C)C55XX_I2C_ADDR;
    int i;
       
    //��I2C����������Ϊ��ȡ�����ֽ���
    Write(pI2C -> iccnt, count);
    WriteMask(pI2C -> icsar, device, ICSAR_MASK_7);
    WriteMask(pI2C -> icmdr,
        ICMDR_STT | ICMDR_STP,
        ICMDR_STT | ICMDR_STP | ICMDR_TRX);
    
    // ��������
    for (i = 0; i < count; i++)
    {
        //�ȴ��������ݷ���
        while(!(pI2C -> icstr & ICSTR_ICRRDY));

        //��������
        bytedata[i] = pI2C -> icdrr;
    }
}


#include "MyApplication.h"
#include <stdbool.h>
#include <stdint.h>

#include "DSP.h"
#include "math.h"
#include "FFTInc.h"
struct  compx s[MAX_FFT_N];
float MagValue[MAX_FFT_N];
uint16_t Freflag=0;
void cfft_f32_mag(void)
{
    uint16_t i;
    float Max;
    uint16_t num=0;
    uint16_t j2,j3,j4,j5;//j为最大值的下标
    float wave2Max=0,wave3Max=0,wave4Max=0,wave5Max=0;//六个变量分别为第二三四五六七谐波；
    float THD=0.0;
    float Uo=0.0;
/* 计算一批sin，cos系数 */
#if (MAX_FFT_N != 8192) && (MAX_FFT_N != 16384)
    InitTableFFT(MAX_FFT_N);
#endif
    for(i=0; i<MAX_FFT_N; i++)
    {
        s[i].real =1.2+(uint16_t)FPGA_ADC[i]*3.3/255;
        s[i].imag = 0;
    }
    /* MAX_FFT_N点快速FFT */
    cfft(s, MAX_FFT_N);
    /* 计算幅频 */
    for(i=0; i<MAX_FFT_N; i++)
    {
        s[i].real = sqrt((float)(s[i].real *s[i].real+ s[i].imag*s[i].imag ));
    }
    Max = 0;
    for(i=0; i<MAX_FFT_N; i++)//从中找到最大值
    {
        MagValue[i]=s[i].real;
        if(i!=0)
        {
            if(Max<s[i].real)
            {
                Max = s[i].real;
                num = i;
            }
        }
    }
    printf("第%d个值%f\r\n",num,Max);
    Freflag = num;
		printf("Freflag=%d\r\n",Freflag*200);
		HAL_Delay(5);
    j2 = 2*num;
    j3 = 3*num;
    j4 = 4*num;
		j5 = 5*num;
    if(num<20)                          //由于采样频率设置不够精确，所以需要分段求THD;
    {
        wave2Max=MagValue[j2];
        wave3Max=MagValue[j3];
        wave4Max=MagValue[j4];
        wave5Max=MagValue[j5];
    }
    else
    {
        for(i=j2-3;i<=j2+3;i++)//找到谐波2  频率为基波的两倍
            if(wave2Max <=  MagValue[i])
                wave2Max =  MagValue[i];
        for(i=j3-3;i<=j3+3;i++)//找到谐波3 频率为基波的三倍
            if(wave3Max <=  MagValue[i])
                wave3Max =  MagValue[i];
        for(i=j4-3;i<=j4+3;i++)//找到谐波4 X轴为基波的四倍
            if(wave4Max <=  MagValue[i])
               wave4Max =  MagValue[i];
        for(i=j5-3;i<=j5+3;i++)//找到谐波5 X轴为基波的5
            if(wave5Max <  MagValue[i])
                wave5Max =  MagValue[i];
    }
    Uo = (wave2Max*wave2Max+wave3Max*wave3Max+wave4Max*wave4Max+wave5Max*wave5Max);
    THD = sqrt(Uo)/Max;
		printf("THD=%f\r\n",THD);

}


#ifndef _MATLAB_H_
#define _MATLAB_H_
#include "MyApplication.h"
#define  PI 3.141592653589793238462643383279
#define LENGTH 4     													//接受缓冲区大小
extern uint16_t x;														//握手信号
extern double input[3000];										//matlab实验数组
extern uint8_t	RxBuffer[LENGTH];  					  //接受缓冲区 
extern uint8_t RxFlag;      								  //接收完成标志；0表示接受未完成，1表示接收完成
extern uint8_t TransferComplete;							//DMA传输完毕标志：0表示接受未完成，1表示接受完成
extern uint16_t InBufArray[2048];							//ADC_采样数组





#endif


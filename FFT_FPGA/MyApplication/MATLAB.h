#ifndef _MATLAB_H_
#define _MATLAB_H_
#include "MyApplication.h"
#define  PI 3.141592653589793238462643383279
#define LENGTH 4     													//���ܻ�������С
extern uint16_t x;														//�����ź�
extern double input[3000];										//matlabʵ������
extern uint8_t	RxBuffer[LENGTH];  					  //���ܻ����� 
extern uint8_t RxFlag;      								  //������ɱ�־��0��ʾ����δ��ɣ�1��ʾ�������
extern uint8_t TransferComplete;							//DMA������ϱ�־��0��ʾ����δ��ɣ�1��ʾ�������
extern uint16_t InBufArray[2048];							//ADC_��������





#endif


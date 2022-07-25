#ifndef __KEY_H__
#define __KEY_H__

#include "MyApplication.h"

//����ṹ������
typedef struct
{
	uint8_t  volatile KEY_Flag;  //������־λ
	uint8_t  Click;              //����
	uint8_t  Press;              //����
	void (*KEY_Detect)(void);    //�������
} KEY_t;

/* extern variables-----------------------------------------------------------*/
extern KEY_t   KEY1;
extern KEY_t   KEY2;


/* extern function prototypes-------------------------------------------------*/

#endif
/********************************************************
  End Of File
********************************************************/

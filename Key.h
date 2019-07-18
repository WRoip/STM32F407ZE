#ifndef _KEY_H_
#define _KEY_H_
#define IF_KEY if(1 == Key_Open())goto Led_Off;\
								if(2 == Key_Open())goto Led_On;\
								if(4 == Key_Open())goto beep_Off;\
								if(8 == Key_Open())goto beep_On;

#include "stm32f4xx.h"

 /*
  * ��  �ܣ��жϰ����Ƿ񴥷�
  * ��  ����void
  * ����ֵ��uint8_t-->1:��s1; 2:��s2; 4:��s3; 8:��s4
  *
 */
uint8_t Key_Open(void);

 /*
  * ��  �ܣ���ʼ������
  * ��  ����void
  * ����ֵ��void
  *
 */
void Init_Key(void);

#endif

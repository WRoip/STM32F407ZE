#ifndef _BEEP_H_
#define _BEEP_H_

#include "stm32f4xx.h"
 /*
  * ��  �ܣ�����
  * ��  ����void
  * ����ֵ��void
  *
 */
void Beep_Off(void);

 /*
  * ��  �ܣ�����ֹͣ
  * ��  ����void
  * ����ֵ��void
  *
 */
void Beep_On(void);

 /*
  * ��  �ܣ���ʼ��Beep
  * ��  ����void
  * ����ֵ��void
  *
 */
void Init_Beep(void);

#endif

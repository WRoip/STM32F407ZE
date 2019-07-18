#ifndef _LED_H_
#define _LED_H_

#include "stm32f4xx_gpio.h"

/****************************** �궨�� ***************************/
#define B1111 15
#define B1110 14
#define B1101 13
#define B1100 12
#define B1011 11
#define B1010 10
#define B1001 9
#define B1000 8
#define B0111 7
#define B0110 6
#define B0101 5
#define B0100 4
#define B0011 3
#define B0010 2
#define B0001 1
#define B0000 0

/****************************** �������� ***************************/


/*
  * ��  �ܣ���ʼ��GPIOx
  * ��  ����void
  * ����ֵ��void
  *
*/
void Init(void);

/*
  * ��  �ܣ�����
  * ��  ����u8-->1:D1; 2:D2; 4:D3; 8:D4;
  * ����ֵ��void
  *
*/
void Off_Led(u8 led);

/*
  * ��  �ܣ��ص�
  * ��  ����u8-->1:D1; 2:D2; 4:D3; 8:D4;
  * ����ֵ��void
  *
*/
void On_Led(u8 led);

/*
  * ��  �ܣ��๦��
  * ��  ����int n;
  * ����ֵ��void
  *
*/
void Multi_Function(volatile int *n);

/****************************** �������� ***************************/

#endif

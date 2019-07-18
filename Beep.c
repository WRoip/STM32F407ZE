#include "Beep.h"

void Beep_Off(void)
{
	GPIO_SetBits(GPIOF, GPIO_Pin_8);
}

void Beep_On(void)
{
	GPIO_ResetBits(GPIOF,GPIO_Pin_8);
}

void Init_Beep(void)
{
	//�����Ĵ�����
	GPIO_InitTypeDef GPIOF_InitTypeDef;
	//����Ĵ�����
	GPIOF_InitTypeDef.GPIO_Mode		= GPIO_Mode_OUT;
	GPIOF_InitTypeDef.GPIO_Pin		= GPIO_Pin_8;
	GPIOF_InitTypeDef.GPIO_OType	= GPIO_OType_PP;
	GPIOF_InitTypeDef.GPIO_PuPd		= GPIO_PuPd_UP;
	GPIOF_InitTypeDef.GPIO_Speed	= GPIO_Speed_2MHz;
	
	//����ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	
	//��ʼ���Ĵ�����F
	GPIO_Init(GPIOF, &GPIOF_InitTypeDef);
	
	//��ʼ����
	GPIO_ResetBits(GPIOF,GPIO_Pin_8);
}

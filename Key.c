#include "Key.h"

uint8_t Key_Open()
{
	uint8_t Bit = 0;
	if(0 == GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0))return 1;
	if(0 == GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_2))return 2;
	if(0 == GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3))return 4;
	if(0 == GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4))return 8;
	return Bit;
}

void Init_Key()
{
	//�����Ĵ�����
	GPIO_InitTypeDef GPIOA_InitTypeDef;
	GPIO_InitTypeDef GPIOE_InitTypeDef;
	//����Ĵ�����
	GPIOA_InitTypeDef.GPIO_Mode		= GPIO_Mode_IN;
	GPIOA_InitTypeDef.GPIO_Pin		= GPIO_Pin_0;
	GPIOA_InitTypeDef.GPIO_OType	= GPIO_OType_PP;
	GPIOA_InitTypeDef.GPIO_PuPd		= GPIO_PuPd_UP;
	GPIOA_InitTypeDef.GPIO_Speed	= GPIO_Speed_2MHz;
	
	GPIOE_InitTypeDef.GPIO_Mode		= GPIO_Mode_IN;
	GPIOE_InitTypeDef.GPIO_Pin		= GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;
	GPIOE_InitTypeDef.GPIO_OType	= GPIO_OType_PP;
	GPIOE_InitTypeDef.GPIO_PuPd		= GPIO_PuPd_UP;
	GPIOE_InitTypeDef.GPIO_Speed	= GPIO_Speed_2MHz;
	
	//����ʱ��
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOE, ENABLE);
	
	//��ʼ���Ĵ�����A
	GPIO_Init(GPIOA, &GPIOA_InitTypeDef);
	//��ʼ���Ĵ�����E
	GPIO_Init(GPIOE, &GPIOE_InitTypeDef);
}

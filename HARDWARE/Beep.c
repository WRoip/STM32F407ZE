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
	//声明寄存器组
	GPIO_InitTypeDef GPIOF_InitTypeDef;
	//定义寄存器组
	GPIOF_InitTypeDef.GPIO_Mode		= GPIO_Mode_OUT;
	GPIOF_InitTypeDef.GPIO_Pin		= GPIO_Pin_8;
	GPIOF_InitTypeDef.GPIO_OType	= GPIO_OType_PP;
	GPIOF_InitTypeDef.GPIO_PuPd		= GPIO_PuPd_UP;
	GPIOF_InitTypeDef.GPIO_Speed	= GPIO_Speed_2MHz;
	
	//设置时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	
	//初始化寄存器组F
	GPIO_Init(GPIOF, &GPIOF_InitTypeDef);
	
	//初始灯灭
	GPIO_ResetBits(GPIOF,GPIO_Pin_8);
}

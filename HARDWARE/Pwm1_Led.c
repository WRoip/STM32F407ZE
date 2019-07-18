#include "Pwm1_Led.h"

void Pwm14_Init(uint32_t pre, uint16_t psc)
{
	GPIO_InitTypeDef					GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef		TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef					TIM_OCInitStruct;
	
	//开启TIM14，GPIOF时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	
	//选择GPIOF9作为TIM功能
	GPIO_PinAFConfig(GPIOF,GPIO_PinSource9, GPIO_AF_TIM14);
	
	//设置GPIO9的模式
	GPIO_InitStructure.GPIO_Mode	= GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Pin		= GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd	= GPIO_PuPd_UP;
	GPIO_Init(GPIOF,&GPIO_InitStructure);
	
	//配置TIM14
	TIM_TimeBaseInitStructure.TIM_Period				= pre;								//预装值
	TIM_TimeBaseInitStructure.TIM_Prescaler			= psc;								//预分频系数
	TIM_TimeBaseInitStructure.TIM_ClockDivision	= TIM_CKD_DIV1;				//固定不变
	TIM_TimeBaseInitStructure.TIM_CounterMode		= TIM_CounterMode_Up;	//向上计数
	TIM_TimeBaseInit(TIM14,&TIM_TimeBaseInitStructure);
	
	//选择PWM1模式
	TIM_OCInitStruct.TIM_OCMode						= TIM_OCMode_PWM1;
	TIM_OCInitStruct.TIM_OCPolarity				= TIM_OCPolarity_Low;
	TIM_OCInitStruct.TIM_OutputState			= TIM_OutputState_Enable;
	//TIM_OCInitStruct.TIM_OCIdleState		=
	//TIM_OCInitStruct.TIM_OCNIdleState		=
	//TIM_OCInitStruct.TIM_OCNPolarity		=
	//TIM_OCInitStruct.TIM_OutputNState		=
	//TIM_OCInitStruct.TIM_Pulse					=
	
	//初始化TIM14
	TIM_OC1Init(TIM14, &TIM_OCInitStruct);
	
	//开启TIM14
	TIM_Cmd(TIM14,ENABLE);
	
	//灯灭
	GPIO_SetBits(GPIOF,GPIO_Pin_9);
}

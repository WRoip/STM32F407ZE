#include "exti_0234.h"
#include "Key.h"
#include "Led.h"

volatile int light = 0;

void Exti_Init()
{
	EXTI_InitTypeDef	EXTI_InitStruct;
	NVIC_InitTypeDef	NVIC_InitStruct;
	
	//开时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	
	//初始化按键
	Init_Key();
	
	//选择中断端口EXTI0,EXTI2,EXTI3,EXTI4
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource2);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource3);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE, EXTI_PinSource4);
	
	//EXTI0,EXTI2,EXTI3,EXTI4中断模式与触发方式
	EXTI_InitStruct.EXTI_Line = EXTI_Line0;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStruct);
	
	EXTI_InitStruct.EXTI_Line = EXTI_Line2;
	EXTI_Init(&EXTI_InitStruct);
	
	EXTI_InitStruct.EXTI_Line = EXTI_Line3;
	EXTI_Init(&EXTI_InitStruct);
	
	EXTI_InitStruct.EXTI_Line = EXTI_Line4;
	EXTI_Init(&EXTI_InitStruct);
	
	//EXTI0,EXTI2,EXTI3,EXTI4开中断与设置优先级
	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority  = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStruct);
	
	NVIC_InitStruct.NVIC_IRQChannel = EXTI2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority  = 1;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStruct);
	
	NVIC_InitStruct.NVIC_IRQChannel = EXTI3_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority  = 2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;
	NVIC_Init(&NVIC_InitStruct);
	
	NVIC_InitStruct.NVIC_IRQChannel = EXTI4_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority  = 3;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 4;
	NVIC_Init(&NVIC_InitStruct);
	
}

 /*
  * 功  能：EXTI0中断处理
  * 参  数：void
  * 返回值：void
  *
 */
void EXTI0_IRQHandler(void)
{
	if(RESET != EXTI_GetITStatus(EXTI_Line0)){
		EXTI_ClearITPendingBit(EXTI_Line0);
		//Off_Led(B1111);
		light = 1;
	}
}

 /*
  * 功  能：EXTI2中断处理
  * 参  数：void
  * 返回值：void
  *
 */
void EXTI2_IRQHandler(void)
{
	if(RESET != EXTI_GetITStatus(EXTI_Line2)){
		EXTI_ClearITPendingBit(EXTI_Line2);
		//On_Led(B1111);
		light = 2;
	}
}

 /*
  * 功  能：EXTI3中断处理
  * 参  数：void
  * 返回值：void
  *
 */
void EXTI3_IRQHandler(void)
{
	if(RESET != EXTI_GetITStatus(EXTI_Line3)){
		EXTI_ClearITPendingBit(EXTI_Line3);
		//On_Led(B1111);
		light = 3;
	}
}

 /*
  * 功  能：EXTI4中断处理
  * 参  数：void
  * 返回值：void
  *
 */
void EXTI4_IRQHandler(void)
{
	if(RESET != EXTI_GetITStatus(EXTI_Line4)){
		EXTI_ClearITPendingBit(EXTI_Line4);
		//On_Led(B1111);
	}
}

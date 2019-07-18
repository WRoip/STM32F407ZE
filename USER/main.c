#include "stm32f4xx.h"
#include "Led.h"
#include "Wait_Clock.h"
#include "Key.h"
#include "Beep.h"
#include "exti_0234.h"
#include "Pwm1_Led.h"

extern volatile int light;

int main(void)
{
	int i = 0;
	Init_Key();
	Init_Beep();
	Exti_Init();
	
	
	
	while(1){
		Multi_Function(&light);
	}
Start:
	while(1){
		if(1 == Key_Open())goto Led_Off;
		if(2 == Key_Open())goto Led_On;
		if(4 == Key_Open())goto beep_Off;
		if(8 == Key_Open())goto beep_On;
	}


Led_Off:
		Off_Led(B1111);
		On_Led(B1111);
		Wait_Clock(1,0);
		for(i = 8; i > 1; i = (i /2)){
			Off_Led((u8)i);
			Wait_Clock(500,1);
			On_Led(B1111);
			IF_KEY;
			Wait_Clock(100,1);
		}

		for(i = 1; i <= 8; i = i * 2){
			Off_Led((u8)i);
			Wait_Clock(500,1);
			On_Led(B1111);
			IF_KEY;
			Wait_Clock(100,1);
		}
		
		while(1){
			Off_Led(B1111);
			Wait_Clock(1,0);
			On_Led(B1111);
			Wait_Clock(500,1);
			IF_KEY;
		}
		//goto Start;

	
Led_On:
		On_Led(B1111);
		Wait_Clock(100,1);
		goto Start;
	
beep_Off:
		Off_Led(B1111);
		Beep_Off();
		goto Start;
	
beep_On:
		On_Led(B1111);
		Beep_On();
		goto Start;
	
}

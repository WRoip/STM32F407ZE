#ifndef _BEEP_H_
#define _BEEP_H_

#include "stm32f4xx.h"
 /*
  * 功  能：蜂鸣
  * 参  数：void
  * 返回值：void
  *
 */
void Beep_Off(void);

 /*
  * 功  能：蜂鸣停止
  * 参  数：void
  * 返回值：void
  *
 */
void Beep_On(void);

 /*
  * 功  能：初始化Beep
  * 参  数：void
  * 返回值：void
  *
 */
void Init_Beep(void);

#endif

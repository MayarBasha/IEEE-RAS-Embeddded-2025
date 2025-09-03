#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define INT0    0
#define INT1    1
#define INT2    2


#define  FALLING_EDGE        0
#define  RAISING_EDGE        1
#define  LOW_LEVEL           2
#define  ON_CHANGE           3


void EXTI_voidEnable      (u8 copy_u8INTnum  ,  u8 copy_u8ControlSense);
void EXTI_voidDisable     (u8 copy_u8INTnum);
void EXTI_voidSetCallBack (u8 copy_u8INTnum  ,void (*LocalPointerToFunction)(void));

#endif
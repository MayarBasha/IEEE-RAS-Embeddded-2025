#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "EXTI_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"


void (*global_PF_vector1)(void) = NULL;
void (*global_PF_vector2)(void) = NULL;
void (*global_PF_vector3)(void) = NULL;




void EXTI_voidEnable  (u8 copy_u8INTnum  ,  u8 copy_u8ControlSense){

switch(copy_u8INTnum ){
case INT0 : SET_BIT(GICR_REG,PIN6);
  switch(copy_u8ControlSense){
   case  FALLING_EDGE:    SET_BIT(MCUCR_REG ,PIN1);      CLEAR_BIT(MCUCR_REG ,PIN0);    break;
   case  RAISING_EDGE:    SET_BIT(MCUCR_REG ,PIN1);      SET_BIT(MCUCR_REG ,PIN0);      break;
   case  LOW_LEVEL:       CLEAR_BIT(MCUCR_REG ,PIN1);    CLEAR_BIT(MCUCR_REG ,PIN0);    break;
   case  ON_CHANGE:       CLEAR_BIT(MCUCR_REG ,PIN1);    SET_BIT(MCUCR_REG ,PIN0);      break;
  } break;

case INT1 : SET_BIT(GICR_REG,PIN7);
  switch(copy_u8ControlSense){
   case  FALLING_EDGE:    SET_BIT(MCUCR_REG ,PIN3);      CLEAR_BIT(MCUCR_REG ,PIN2);    break;
   case  RAISING_EDGE:    SET_BIT(MCUCR_REG ,PIN3);      SET_BIT(MCUCR_REG ,PIN2);      break;
   case  LOW_LEVEL:       CLEAR_BIT(MCUCR_REG ,PIN3);    CLEAR_BIT(MCUCR_REG ,PIN2);    break;
   case  ON_CHANGE:       CLEAR_BIT(MCUCR_REG ,PIN3);    SET_BIT(MCUCR_REG ,PIN2);      break;
  } break;

case INT2 : SET_BIT(GICR_REG,PIN5);
  switch(copy_u8ControlSense){
   case  FALLING_EDGE:    CLEAR_BIT(MCUCR_REG ,PIN6);    break;
   case  RAISING_EDGE:    SET_BIT(MCUCR_REG ,PIN6);      break;
  } break;

 }
}


void EXTI_voidDisable     (u8 copy_u8INTnum){
switch(copy_u8INTnum){
  case INT0 : CLEAR_BIT(GICR_REG,PIN6);    break;
  case INT1 : CLEAR_BIT(GICR_REG,PIN7);    break;
  case INT2 : CLEAR_BIT(GICR_REG,PIN5);    break;
 }
}



void EXTI_voidSetCallBack (u8 copy_u8INTnum  ,void (*LocalPointerToFunction)(void)){
switch(copy_u8INTnum){
  case INT0 :  global_PF_vector1 = LocalPointerToFunction;  break;
  case INT1 :  global_PF_vector2 = LocalPointerToFunction;  break;
  case INT2 :  global_PF_vector3 = LocalPointerToFunction;  break;
 }
}


void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void){

if(global_PF_vector1 != NULL){
    global_PF_vector1();
 }
}


void __vector_2 (void)  __attribute__((signal));
void __vector_2 (void){

if(global_PF_vector2 != NULL){
    global_PF_vector2();
 }
}



void __vector_3 (void)  __attribute__((signal));
void __vector_3 (void){

if(global_PF_vector3 != NULL){
    global_PF_vector3();
 }
}
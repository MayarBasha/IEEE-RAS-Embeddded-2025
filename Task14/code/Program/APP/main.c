#include <util/delay.h>
#include <stdbool.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../HAL/_7_SEGMENT/_7_SEGMENT_Interface.h"
#include "../HAL/MOTOR/MOTOR_Interface.h"

int main(){

 DIO_voidSetPORTDirction(PORTA,INPUT);
 DIO_voidSetPORTDirction(PORTC,OUTPUT);

u8 loc_u8forward=0;
u8 loc_u8reverse=0;
u8 loc_u8right=0;
u8 loc_u8left =0;
u8 loc_u8stop =0;
while(1){
  loc_u8forward =  DIO_voidGetPinValue(PORTA,PIN0);
  loc_u8reverse =  DIO_voidGetPinValue(PORTA,PIN1);
  loc_u8right =    DIO_voidGetPinValue(PORTA,PIN2);
  loc_u8left =     DIO_voidGetPinValue(PORTA,PIN3);
  loc_u8stop =     DIO_voidGetPinValue(PORTA,PIN4);
  if(loc_u8stop >0){
MOTOR_voidStop();
}else if(loc_u8stop == 0){

if(loc_u8forward > 0){
MOTOR_voidForward();
}else if(loc_u8forward ==0){
 MOTOR_voidStop();
}

if(loc_u8reverse >0){
MOTOR_voidReverse();
}else if(loc_u8reverse == 0){
MOTOR_voidStop();
}

if(loc_u8right >0){
MOTOR_voidTurnRight();
}else if(loc_u8right == 0){
MOTOR_voidStop();
}

if(loc_u8left >0){
MOTOR_voidTurnLeft();
}else if(loc_u8left == 0){
MOTOR_voidStop();
}



}


}
return 0;

}
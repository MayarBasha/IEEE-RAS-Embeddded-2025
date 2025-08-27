#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "MOTOR_Interface.h"
#include "MOTOR_Private.h"
#include "MOTOR_Config.h"

#include "../../MCAL/DIO/DIO_Interface.h"

void MOTOR_voidForward(void){
DIO_voidSetPinValue(MOTOR_PORT,MOTOR_LEFT_IN1,HIGH);
DIO_voidSetPinValue(MOTOR_PORT,MOTOR_LEFT_IN2,LOW);
DIO_voidSetPinValue(MOTOR_PORT,MOTOR_RIGHT_IN1,HIGH);
DIO_voidSetPinValue(MOTOR_PORT,MOTOR_RIGHT_IN2,LOW);
}

void MOTOR_voidReverse(void){
DIO_voidSetPinValue(MOTOR_PORT,MOTOR_LEFT_IN1,LOW);
DIO_voidSetPinValue(MOTOR_PORT,MOTOR_LEFT_IN2,HIGH);
DIO_voidSetPinValue(MOTOR_PORT,MOTOR_RIGHT_IN1,LOW);
DIO_voidSetPinValue(MOTOR_PORT,MOTOR_RIGHT_IN2,HIGH);

}

void MOTOR_voidTurnRight(void){
DIO_voidSetPinValue(MOTOR_PORT,MOTOR_LEFT_IN1,HIGH);
DIO_voidSetPinValue(MOTOR_PORT,MOTOR_LEFT_IN2,LOW);
DIO_voidSetPinValue(MOTOR_PORT,MOTOR_RIGHT_IN1,LOW);
DIO_voidSetPinValue(MOTOR_PORT,MOTOR_RIGHT_IN2,LOW);

}
void MOTOR_voidTurnLeft(void){
DIO_voidSetPinValue(MOTOR_PORT,MOTOR_LEFT_IN1,LOW);
DIO_voidSetPinValue(MOTOR_PORT,MOTOR_LEFT_IN2,LOW);
DIO_voidSetPinValue(MOTOR_PORT,MOTOR_RIGHT_IN1,HIGH);
DIO_voidSetPinValue(MOTOR_PORT,MOTOR_RIGHT_IN2,LOW);

}



void MOTOR_voidStop(void){
DIO_voidSetPinValue(MOTOR_PORT,MOTOR_LEFT_IN1,LOW);
DIO_voidSetPinValue(MOTOR_PORT,MOTOR_LEFT_IN2,LOW);
DIO_voidSetPinValue(MOTOR_PORT,MOTOR_RIGHT_IN1,LOW);
DIO_voidSetPinValue(MOTOR_PORT,MOTOR_RIGHT_IN2,LOW);


}
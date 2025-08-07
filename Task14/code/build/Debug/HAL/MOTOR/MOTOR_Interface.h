#ifndef MOTOR_INTERFACE_H
#define MOTOR_INTERFACE_H


#define MOTOR_LEFT_IN1   PIN0
#define MOTOR_LEFT_IN2   PIN1

#define MOTOR_RIGHT_IN1  PIN2
#define MOTOR_RIGHT_IN2  PIN3

#define MOTOR_PORT       PORTC

void MOTOR_voidForward(void);
void MOTOR_voidReverse(void);
void MOTOR_voidTurnRight(void);
void MOTOR_voidTurnLeft(void);
void MOTOR_voidStop(void);

#endif
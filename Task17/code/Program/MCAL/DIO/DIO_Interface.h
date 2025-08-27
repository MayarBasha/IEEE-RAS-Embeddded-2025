#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define OUTPUT     1
#define INPUT      0

#define HIGH       1
#define LOW        0

#define ON         1
#define OFF        0

#define PORTA      0
#define PORTB      1
#define PORTC      2
#define PORTD      3

#define PIN0       0
#define PIN1       1
#define PIN2       2
#define PIN3       3
#define PIN4       4
#define PIN5       5
#define PIN6       6
#define PIN7       7






void DIO_voidSetPinDirction (u8 copy_u8PORT ,u8 copy_u8PIN ,u8 copy_u8Dirction );
void DIO_voidSetPinValue    (u8 copy_u8PORT ,u8 copy_u8PIN , u8 copy_u8Value);
u8 DIO_voidGetPinValue     (u8 copy_u8PORT ,u8 copy_u8PIN  );

void DIO_voidSetPORTDirction (u8 copy_u8PORT  ,u8 copy_u8Dirction );
void DIO_voidSetPortValue    (u8 copy_u8PORT  , u8 copy_u8Value);
u8 DIO_voidGetPortValue     (u8 copy_u8PORT  );

void DIO_voidTogglePortValue (u8 copy_u8PORT  );
void DIO_voidTogglePinValue    (u8 copy_u8PORT ,u8 copy_u8PIN );

void DIO_voidConfigPullUpPin (u8 copy_u8PORT ,u8 copy_u8PIN , u8 copy_u8pullUpStatus);
void DIO_voidConfigPullUpPort (u8 copy_u8PORT , u8 copy_u8pullUpStatus);



#endif
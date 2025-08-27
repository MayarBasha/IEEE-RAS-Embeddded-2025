#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Config.h"


void DIO_voidSetPinDirction (u8 copy_u8PORT ,u8 copy_u8PIN ,u8 copy_u8Dirction ){
if (copy_u8PORT <= PORTD && copy_u8PIN <= PIN7 ){
if(copy_u8Dirction == OUTPUT){

    switch(copy_u8PORT){
     case PORTA : SET_BIT(DDRA_REG,copy_u8PIN );    break;
     case PORTB : SET_BIT(DDRB_REG,copy_u8PIN );    break;
     case PORTC : SET_BIT(DDRC_REG,copy_u8PIN );    break;
     case PORTD : SET_BIT(DDRD_REG,copy_u8PIN );    break;

    }
}else if(copy_u8Dirction == INPUT){

 switch(copy_u8PORT){
     case PORTA : CLEAR_BIT(DDRA_REG,copy_u8PIN );    break;
     case PORTB : CLEAR_BIT(DDRB_REG,copy_u8PIN );    break;
     case PORTC : CLEAR_BIT(DDRC_REG,copy_u8PIN );    break;
     case PORTD : CLEAR_BIT(DDRD_REG,copy_u8PIN );    break;
     }
   }
 }
}



void DIO_voidSetPinValue(u8 copy_u8PORT ,u8 copy_u8PIN , u8 copy_u8Value){
if (copy_u8PORT <= PORTD && copy_u8PIN <= PIN7 ){
if(copy_u8Value == HIGH){

    switch(copy_u8PORT){
     case PORTA : SET_BIT(PORTA_REG,copy_u8PIN );    break;
     case PORTB : SET_BIT(PORTB_REG,copy_u8PIN );    break;
     case PORTC : SET_BIT(PORTC_REG,copy_u8PIN );    break;
     case PORTD : SET_BIT(PORTD_REG,copy_u8PIN );    break;

    }
}else if(copy_u8Value == LOW){

 switch(copy_u8PORT){
     case PORTA : CLEAR_BIT(PORTA_REG,copy_u8PIN );    break;
     case PORTB : CLEAR_BIT(PORTB_REG,copy_u8PIN );    break;
     case PORTC : CLEAR_BIT(PORTC_REG,copy_u8PIN );    break;
     case PORTD : CLEAR_BIT(PORTD_REG,copy_u8PIN );    break;
    }
  }
 }
}


u8 DIO_voidGetPinValue     (u8 copy_u8PORT ,u8 copy_u8PIN  ){

  if (copy_u8PORT <= PORTD && copy_u8PIN <= PIN7 ){
    u8 loc_u8Status =0;
switch(copy_u8PORT){
     case PORTA :  loc_u8Status = GET_BIT(PINA_REG,copy_u8PIN );    break;
     case PORTB :  loc_u8Status = GET_BIT(PINB_REG,copy_u8PIN );    break;
     case PORTC :  loc_u8Status = GET_BIT(PINC_REG,copy_u8PIN );    break;
     case PORTD :  loc_u8Status = GET_BIT(PIND_REG,copy_u8PIN );    break;
     }
    return loc_u8Status;
  }
}

void DIO_voidSetPORTDirction (u8 copy_u8PORT  ,u8 copy_u8Dirction ){

if (copy_u8PORT <= PORTD  ){
if(copy_u8Dirction == OUTPUT){

    switch(copy_u8PORT){
     case PORTA : DDRA_REG  = 0xff;    break;
     case PORTB : DDRB_REG  = 0xff;    break;
     case PORTC : DDRC_REG  = 0xff;    break;
     case PORTD : DDRD_REG  = 0xff;    break;

    }
}else if(copy_u8Dirction == INPUT){

 switch(copy_u8PORT){
     case PORTA : DDRA_REG  = 0x00;    break;
     case PORTB : DDRB_REG  = 0x00;    break;
     case PORTC : DDRC_REG  = 0x00;    break;
     case PORTD : DDRD_REG  = 0x00;    break;
     }
   }
 }


}
void DIO_voidSetPortValue    (u8 copy_u8PORT  , u8 copy_u8Value){

    if (copy_u8PORT <= PORTD  ){
switch(copy_u8PORT){
     case PORTA : PORTA_REG  = copy_u8Value;    break;
     case PORTB : PORTB_REG  = copy_u8Value;    break;
     case PORTC : PORTC_REG  = copy_u8Value;    break;
     case PORTD : PORTD_REG  = copy_u8Value;    break;
     }

  }

}

u8 DIO_voidGetPortValue     (u8 copy_u8PORT  ){
if (copy_u8PORT <= PORTD ){
    u8 loc_u8Status =0;
switch(copy_u8PORT){
     case PORTA :  loc_u8Status = PINA_REG;    break;
     case PORTB :  loc_u8Status = PINB_REG;    break;
     case PORTC :  loc_u8Status = PINC_REG;    break;
     case PORTD :  loc_u8Status = PIND_REG;    break;
     }
    return loc_u8Status;
  }

}


void DIO_voidTogglePinValue    (u8 copy_u8PORT ,u8 copy_u8PIN ){
  if (copy_u8PORT <= PORTD && copy_u8PIN <= PIN7 ){
switch(copy_u8PORT){
     case PORTA : TOGGLE_BIT(PORTA_REG,copy_u8PIN );    break;
     case PORTB : TOGGLE_BIT(PORTB_REG,copy_u8PIN );    break;
     case PORTC : TOGGLE_BIT(PORTC_REG,copy_u8PIN );    break;
     case PORTD : TOGGLE_BIT(PORTD_REG,copy_u8PIN );    break;
    }
  }
    
}

void DIO_voidTogglePortValue (u8 copy_u8PORT  ){

if (copy_u8PORT <= PORTD  ){
switch(copy_u8PORT){
     case PORTA : PORTA_REG  ^= 0xff;    break;
     case PORTB : PORTB_REG  ^= 0xff;    break;
     case PORTC : PORTC_REG  ^= 0xff;    break;
     case PORTD : PORTD_REG  ^= 0xff;    break;
     }

  }

}

void DIO_voidConfigPullUpPin (u8 copy_u8PORT ,u8 copy_u8PIN , u8 copy_u8pullUpStatus){
 if (copy_u8PORT <= PORTD && copy_u8PIN <= PIN7 ){
   
  switch(copy_u8pullUpStatus ){
  case ON  : DIO_voidSetPinValue(copy_u8PORT,copy_u8PIN , HIGH);   break;
  case OFF : DIO_voidSetPinValue(copy_u8PORT,copy_u8PIN , LOW);    break;


     }


 }
}
void DIO_voidConfigPullUpPort (u8 copy_u8PORT , u8 copy_u8pullUpStatus){

if (copy_u8PORT <= PORTD  ){
   
  switch(copy_u8pullUpStatus ){
  case ON  : DIO_voidSetPortValue(copy_u8PORT, HIGH);   break;
  case OFF : DIO_voidSetPortValue(copy_u8PORT, LOW);    break;


     }


 }


}



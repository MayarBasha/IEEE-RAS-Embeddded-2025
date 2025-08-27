#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "_7_SEGMENT_Interface.h"
#include "_7_SEGMENT_Private.h"
#include "_7_SEGMENT_Config.h"

#include "../../MCAL/DIO/DIO_Interface.h"

u8 common_anode_arr[10]={ZERO ,ONE ,TWO ,THREE,FOUR ,FIVE ,SEX  ,SEVEN,EIGHT,NINE };



void _7_SEGMENT_voidInIt(u8 copy_u8PORT){

if (copy_u8PORT <= PORTD  ){
switch(copy_u8PORT){
     case PORTA : DIO_voidSetPORTDirction(PORTA,OUTPUT);    break;
     case PORTB : DIO_voidSetPORTDirction(PORTB,OUTPUT);    break;
     case PORTC : DIO_voidSetPORTDirction(PORTC,OUTPUT);    break;
     case PORTD : DIO_voidSetPORTDirction(PORTD,OUTPUT);    break;
     }

  }

}



void _7_SEGMENT_voidprintnumber(u8 copy_u8PORT, u8 copy_u8Polarity, u8 copy_number){

if (copy_u8PORT <= PORTD  ){
switch(copy_u8Polarity){
    case COMMON_ANODE : {
     switch(copy_u8PORT){
     case PORTA : DIO_voidSetPortValue(PORTA,common_anode_arr[copy_number]);    break;
     case PORTB : DIO_voidSetPortValue(PORTB,common_anode_arr[copy_number]);    break;
     case PORTC : DIO_voidSetPortValue(PORTC,common_anode_arr[copy_number]);    break;
     case PORTD : DIO_voidSetPortValue(PORTD,common_anode_arr[copy_number]);    break;
    }

    }break;

 case COMMON_CATHODE: {
     switch(copy_u8PORT){
     case PORTA : DIO_voidSetPortValue(PORTA,~common_anode_arr[copy_number]);    break;
     case PORTB : DIO_voidSetPortValue(PORTB,~common_anode_arr[copy_number]);    break;
     case PORTC : DIO_voidSetPortValue(PORTC,~common_anode_arr[copy_number]);    break;
     case PORTD : DIO_voidSetPortValue(PORTD,~common_anode_arr[copy_number]);    break;
    }

    }break;    

  }
 }
}
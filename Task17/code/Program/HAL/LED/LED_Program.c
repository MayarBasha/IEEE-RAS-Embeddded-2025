#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "LED_Interface.h"
#include "LED_Private.h"
#include "LED_Config.h"

#include "../../MCAL/DIO/DIO_Interface.h"



void LED_voidLedInIt(u8 copy_u8PORT , u8 copy_u8PIN ){
  if (copy_u8PORT <= PORTD && copy_u8PIN <= PIN7 ){

     DIO_voidSetPinDirction(copy_u8PORT,copy_u8PIN , OUTPUT);

  }
}
void LED_voidLedStatus(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8status ){


    if (copy_u8PORT <= PORTD && copy_u8PIN <= PIN7 ){

switch(copy_u8status ){
  case ON  : DIO_voidSetPinValue(copy_u8PORT,copy_u8PIN , HIGH);   break;
  case OFF : DIO_voidSetPinValue(copy_u8PORT,copy_u8PIN , LOW);    break;


     }
  }
}

void LED_voidLedToggle(u8 copy_u8PORT ,u8 copy_u8PIN ){
if (copy_u8PORT <= PORTD && copy_u8PIN <= PIN7 ){


  DIO_voidTogglePinValue(copy_u8PORT,copy_u8PIN);
}

}

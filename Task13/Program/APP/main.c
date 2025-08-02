#include <util/delay.h>
#include <stdbool.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../HAL/_7_SEGMENT/_7_SEGMENT_Interface.h"

int main(){
 LED_voidLedInIt(PORTA,PIN0);
 LED_voidLedInIt(PORTA,PIN1);
 LED_voidLedInIt(PORTA,PIN2);
_7_SEGMENT_voidInIt(PORTC);
_7_SEGMENT_voidInIt(PORTD);

while(1){
//RED LED
  LED_voidLedStatus(PORTA,PIN0,ON);
 
  for(s16 i=0; i<=1;i++ ){
    _7_SEGMENT_voidprintnumber(PORTC,COMMON_ANODE,i);
    for(s16 j=0;j<=9;j++){
    _7_SEGMENT_voidprintnumber(PORTD,COMMON_CATHODE,j);
    if(i==1 && j==4){
      break;
    }
    _delay_ms(50);
  }
  }
  //yellow led
  LED_voidLedStatus(PORTA,PIN0,OFF);
  LED_voidLedStatus(PORTA,PIN1,ON);
   _7_SEGMENT_voidprintnumber(PORTC,COMMON_ANODE,0);
    for(s16 j=0;j<=4;j++){
   _7_SEGMENT_voidprintnumber(PORTD,COMMON_CATHODE,j);
    _delay_ms(50);
  
  }



 
  LED_voidLedStatus(PORTA,PIN1,OFF);
  LED_voidLedStatus(PORTA,PIN2,ON);
 
   
    _7_SEGMENT_voidprintnumber(PORTC,COMMON_ANODE,0);
    for(s16 j=0;j<=9;j++){
    _7_SEGMENT_voidprintnumber(PORTD,COMMON_CATHODE,j);

   _delay_ms(50);
  }
   
  
  
  LED_voidLedStatus(PORTA,PIN2,OFF);

 

}
return 0;

}
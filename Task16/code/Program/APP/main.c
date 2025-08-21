#include <util/delay.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../HAL/_7_SEGMENT/_7_SEGMENT_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"


void toggelLed(void);
void resetSevenSegment(void);
 void lcdDisplay(void);
u8 global_counter=1;
int main(){
_7_SEGMENT_voidInIt(PORTC);
LED_voidLedInIt(PORTA ,PIN0 );

GIE_voidEnable(ON);
EXTI_voidEnable(INT0, FALLING_EDGE );
EXTI_voidSetCallBack(INT0 , &toggelLed);

EXTI_voidEnable(INT1, FALLING_EDGE  );
EXTI_voidSetCallBack(INT1 , &resetSevenSegment);




//LED
DIO_voidSetPinDirction(PORTD , PIN2 , INPUT);
DIO_voidConfigPullUpPin(PORTD , PIN2 ,ON);

DIO_voidSetPinDirction(PORTA , PIN0 , OUTPUT);
LED_voidLedStatus(PORTA , PIN0 ,OFF);

//SEVEN SEGMENT
DIO_voidSetPORTDirction(PORTC,OUTPUT);

DIO_voidSetPinDirction(PORTD , PIN3 , INPUT);
DIO_voidConfigPullUpPin(PORTD , PIN3 ,ON);



while(1){

   _7_SEGMENT_voidprintnumber(PORTC,COMMON_CATHODE,global_counter);
    _delay_ms(100);

    global_counter++;
    if (global_counter >=9) {
      global_counter=1;
    }

 


}

return 0;

 }

 void toggelLed(void){
 
    LED_voidLedToggle(PORTA ,PIN0 );
 }

 void resetSevenSegment(void){

  global_counter =0; 
  
 }

 




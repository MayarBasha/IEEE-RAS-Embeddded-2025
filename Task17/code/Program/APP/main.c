#include <util/delay.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../MCAL/GIE/GIE_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"


int main(){
u16 Local_percentage=0;
u16 ADC_read=0;

 LCD_voidInIt();
 ADC_voidInIt();


 DIO_voidSetPORTDirction (PORTD  ,OUTPUT );
 for(u8 i = 0; i < 8; i++) {
        LED_voidLedStatus(PORTD, i, OFF);
    }
 while(1){
   
    ADC_read = ADC_u16ReadSynchronus(ADC0);
    
    LCD_voidSetPosition(LINE1 ,0);
    LCD_voidSendString("ADC_VALUE ");
   
    LCD_voidWriteNumber(ADC_read );

 Local_percentage = ((u32)ADC_read *100UL) / 1023;
  LCD_voidSetPosition(LINE2 ,0);
    LCD_voidSendString("percentage ");
    LCD_voidWriteNumber(Local_percentage);


 for(u8 i = 0; i < 8; i++) {
            LED_voidLedStatus(PORTD, i, OFF);
        }

   u8 leds_to_light = (Local_percentage * 8) / 100;
        
       
        for(u8 i = 0; i < leds_to_light; i++) {
            LED_voidLedStatus(PORTD, i, ON);
        }
        
        _delay_ms(10);
         //LCD_voidClearDisplay();
}
return 0;

 }





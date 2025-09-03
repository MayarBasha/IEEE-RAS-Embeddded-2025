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
#include "../MCAL/TIMERS/TIMER0/TIMER0_Interface.h"
#include "../MCAL/TIMERS/TIMER1/TIMER1_Interface.h"
#include "../MCAL/WDT/WDT_Interface.h"


int main(){
u16 ADC0_read=0;
u8 PWMValue=0;


 LCD_voidInIt();
 TIMER0_voidInit();

 ADC_voidInIt();
LCD_voidInIt();


 DIO_voidSetPinDirction (PORTA ,PIN0 ,INPUT);

 DIO_voidSetPinDirction (PORTB ,PIN3 ,OUTPUT);
 
    
 while(1){
   
    ADC0_read = ADC_u16ReadSynchronus(ADC0);
    PWMValue  = ((u32)ADC0_read * 255UL) / 1023;
    TIMER0_voidSetCompareMatchValue ( PWMValue);
    
}
return 0;

 }




       
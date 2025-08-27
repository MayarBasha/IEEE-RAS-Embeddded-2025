
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "LCD_Interface.h"
#include "LCD_Private.h"
#include "LCD_Config.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include <util/delay.h>

void  LCD_voidInIt(void){

DIO_voidSetPORTDirction(LCD_DATAPORT,OUTPUT);
DIO_voidSetPinDirction(LCD_CONTROLPORT,LCD_RS,OUTPUT);
DIO_voidSetPinDirction(LCD_CONTROLPORT,LCD_RW,OUTPUT);
DIO_voidSetPinDirction(LCD_CONTROLPORT,LCD_EN,OUTPUT);
_delay_ms(35);

LCD_voidSendCommand(FS_8BIT_2LINES_5x7 );
_delay_ms(1);
LCD_voidSendCommand(DIS_ON_NO_CURSER   );
_delay_ms(1);
LCD_voidSendCommand(DIS_CLEAR);
_delay_ms(2);
LCD_voidSendCommand(ENTRY_MODE_INCREASE_NO_SHIFT );
_delay_ms(1);
}

void LCD_voidSendCommand(u8 copy_u8command){
 DIO_voidSetPinValue(LCD_CONTROLPORT,LCD_RS,LOW);
 DIO_voidSetPinValue(LCD_CONTROLPORT,LCD_RW,LOW);

 DIO_voidSetPortValue(LCD_DATAPORT ,copy_u8command);
 
 LCD_voidSetFallingEadge();
}


void LCD_voidSendChar(u8 copy_u8data){
 DIO_voidSetPinValue(LCD_CONTROLPORT,LCD_RS,HIGH);
 DIO_voidSetPinValue(LCD_CONTROLPORT,LCD_RW,LOW);

 DIO_voidSetPortValue(LCD_DATAPORT ,copy_u8data);
 
 LCD_voidSetFallingEadge();
}


void LCD_voidSendString(u8 *copy_u8data){
 u8 loc_iterator=0;
 while(copy_u8data[loc_iterator] !='\0'){
    LCD_voidSendChar(copy_u8data[loc_iterator]);
    loc_iterator++;
 }

}


void LCD_voidSetPosition(u8 copy_u8line ,u8 copy_u8position){

if(copy_u8line > LINE2 || copy_u8position> 15){
    //do nothing
}
else {
    switch(copy_u8line){
        case LINE1: LCD_voidSendCommand(0x80+copy_u8position);  break;
        case LINE2: LCD_voidSendCommand(0xC0+copy_u8position);  break;
    }
}

}


void LCD_voidDrawPattern(u8 copy_u8patternNumber ,u8 *copy_u8string){

LCD_voidSendCommand(copy_u8patternNumber);

for(u8 i =0; i<8 ;i++ ){
    LCD_voidSendChar(copy_u8string[i]);
 }
}


void LCD_voidrWitePattern(u8 copy_u8pattern , u8 copy_u8line ,u8 copy_u8position){

 LCD_voidSetPosition( copy_u8line , copy_u8position);
 LCD_voidSendChar(copy_u8pattern);

}


void LCD_voidWriteNumber(u16 copy_u16number){

      if (copy_u16number == 0) {
        LCD_voidSendChar('0');
        return;
    }
    
    u8 loc_arr[10]; 
    u8 i = 0;
    
 
    while (copy_u16number > 0) {
        loc_arr[i] = copy_u16number % 10; 
        copy_u16number /= 10; 
        i++;
    }
    
    
    for (s8 j = i - 1; j >= 0; j--) {
        LCD_voidSendChar(loc_arr[j] + '0'); 
    }

}


void LCD_voidShiftRight(void){
 LCD_voidSendCommand(ENTRY_MODE_DECREASE_RIGHT_SHIFT);
}

void LCD_voidShiftLift(void){
    LCD_voidSendCommand(ENTRY_MODE_INCREASE_LEFT_SHIFT );
}


void LCD_voidClearDisplay(void){
   LCD_voidSendCommand(DIS_CLEAR);
}


void LCD_voidSetFallingEadge(void){
DIO_voidSetPinValue(LCD_CONTROLPORT,LCD_EN,HIGH);
_delay_ms(1);
DIO_voidSetPinValue(LCD_CONTROLPORT,LCD_EN,LOW);
}

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "KPAD_Interface.h"
#include "KPAD_Private.h"
#include "KPAD_Config.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include <util/delay.h>


u8 KPAD_u8ColumnsArr[KPAD_COLUMN_NUM] = { KPAD_C0_PIN , KPAD_C1_PIN , KPAD_C2_PIN , KPAD_C3_PIN };
u8 KPAD_u8RowsArr[KPAD_ROW_NUM] = { KPAD_R0_PIN , KPAD_R1_PIN , KPAD_R2_PIN , KPAD_R3_PIN };
u8 KPAD_u8KeysArr[KPAD_ROW_NUM][KPAD_COLUMN_NUM] = KPAD_KEYS ;


void KPAD_voidInIt(void){
  DIO_voidSetPinDirction(KPAD_PORT,KPAD_R0_PIN,INPUT);
  DIO_voidSetPinDirction(KPAD_PORT,KPAD_R1_PIN,INPUT);
  DIO_voidSetPinDirction(KPAD_PORT,KPAD_R2_PIN,INPUT);
  DIO_voidSetPinDirction(KPAD_PORT,KPAD_R3_PIN,INPUT);

  DIO_voidSetPinDirction(KPAD_PORT,KPAD_C0_PIN,OUTPUT);
  DIO_voidSetPinDirction(KPAD_PORT,KPAD_C1_PIN,OUTPUT);
  DIO_voidSetPinDirction(KPAD_PORT,KPAD_C2_PIN,OUTPUT);
  DIO_voidSetPinDirction(KPAD_PORT,KPAD_C3_PIN,OUTPUT);
  
  DIO_voidConfigPullUpPin(KPAD_PORT,KPAD_R0_PIN,ON);
  DIO_voidConfigPullUpPin(KPAD_PORT,KPAD_R1_PIN,ON);
  DIO_voidConfigPullUpPin(KPAD_PORT,KPAD_R2_PIN,ON);
  DIO_voidConfigPullUpPin(KPAD_PORT,KPAD_R3_PIN,ON);

  DIO_voidSetPinValue(KPAD_PORT,KPAD_C0_PIN,HIGH);
  DIO_voidSetPinValue(KPAD_PORT,KPAD_C1_PIN,HIGH);
  DIO_voidSetPinValue(KPAD_PORT,KPAD_C2_PIN,HIGH);
  DIO_voidSetPinValue(KPAD_PORT,KPAD_C3_PIN,HIGH);

}



u8   KPAD_u8GetPressed(void){
 
    u8 loc_columnsItr;
    u8 loc_rowsItr;
    u8 flag=0;
    u8 loc_pinvalue;
    u8 loc_pressedKey=0xff;

    for(loc_columnsItr=0 ; loc_columnsItr < KPAD_COLUMN_NUM ; loc_columnsItr++){
      
    DIO_voidSetPinValue(KPAD_PORT,KPAD_u8ColumnsArr[loc_columnsItr],LOW);

    for(loc_rowsItr=0;loc_rowsItr <KPAD_ROW_NUM;loc_rowsItr++){

     loc_pinvalue=DIO_voidGetPinValue(KPAD_PORT,KPAD_u8RowsArr[loc_rowsItr]);

     if(loc_pinvalue==0){
       while(loc_pinvalue==0){
          loc_pressedKey=KPAD_u8KeysArr[loc_rowsItr][loc_columnsItr];

          loc_pinvalue=DIO_voidGetPinValue(KPAD_PORT,KPAD_u8RowsArr[loc_rowsItr]);
          flag = 1;

       }
       break;
     }
    }

    DIO_voidSetPinValue(KPAD_PORT,KPAD_u8ColumnsArr[loc_columnsItr],HIGH);
     if (flag==1){
        break;
     }  
    }
  return loc_pressedKey;

}
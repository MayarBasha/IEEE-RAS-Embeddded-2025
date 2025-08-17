#include <util/delay.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LED/LED_Interface.h"
#include "../HAL/_7_SEGMENT/_7_SEGMENT_Interface.h"
#include "../HAL/MOTOR/MOTOR_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KPAD/KPAD_Interface.h"

u8 expr[16]; // expression buffer
u32 pos = 0;
s32 evaluateExpression(char* expr);
int main(){



  LCD_voidInIt();
  KPAD_voidInIt();

 LCD_voidSetPosition(LINE1,0);
 LCD_voidSendString("MAYAR BASHA");
 _delay_ms(1000);
 LCD_voidClearDisplay();
 
 LCD_voidSetPosition(LINE1,0);
 LCD_voidSendString("CALCULATOR");
 _delay_ms(1000);
 LCD_voidClearDisplay();
 LCD_voidSetPosition(LINE1,0);

 while(1){

u8 key = KPAD_u8GetPressed();  
if(key != 0xff)
		 {
            if (key == '=') {
                expr[pos] = '\0';  // end string
                s32 result = evaluateExpression(expr);
               LCD_voidClearDisplay();
                
                LCD_voidSendString(" Result: ");
                char resStr[16];
                itoa(result, resStr, 10);
               LCD_voidSendString(resStr);
                pos = 0;
               //  _delay_ms(2000);
               //  LCD_voidClearDisplay();
            } else if (key == '#') {
                pos = 0;
                LCD_voidClearDisplay();
            } else {
                if (pos < 15) {
                    expr[pos++] = key;
                   LCD_voidSendChar(key);
                }
            }
        }


		
}
return 0;

 }


s32 evaluateExpression(char* expr) {
    s32 result = 0;
    s32 num = 0;
    char op = '+';

    for (int i = 0; expr[i]; i++) {
        if (expr[i] >= '0' && expr[i] <= '9') {
            num = num * 10 + (expr[i] - '0');
        } else {
            switch (op) {
                case '+': result += num; break;
                case '-': result -= num; break;
                case '*': result *= num; break;
                case '/': if (num != 0) result /= num; break;
            }
            op = expr[i];
            num = 0;
        }
    }
   
    // Apply last operation
    switch (op) {
        case '+': result += num; break;
        case '-': result -= num; break;
        case '*': result *= num; break;
        case '/': if (num != 0) result /= num; break;
    }
    return result;
}

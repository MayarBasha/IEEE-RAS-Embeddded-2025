#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define LINE1     0
#define LINE2     1

#define    PATTERN_0        0b01000000    // address of First Byte at Sequence 0 at CGRAM            
#define    PATTERN_1        0b01001000    // address of First Byte at Sequence 1 at CGRAM            
#define    PATTERN_2        0b01010000    // address of First Byte at Sequence 2 at CGRAM
#define    PATTERN_3        0b01011000    // address of First Byte at Sequence 3 at CGRAM
#define    PATTERN_4        0b01100000    // address of First Byte at Sequence 4 at CGRAM
#define    PATTERN_5        0b01101000    // address of First Byte at Sequence 5 at CGRAM
#define    PATTERN_6        0b01110000    // address of First Byte at Sequence 6 at CGRAM
#define    PATTERN_7        0b01111000    // address of First Byte at Sequence 7 at CGRAM


void LCD_voidInIt(void);
void LCD_voidSendCommand(u8 copy_u8command);
void LCD_voidSendChar(u8 copy_u8data);
void LCD_voidSendString(u8 *copy_u8data);
void LCD_voidSetPosition(u8 copy_u8line ,u8 copy_u8position);
void LCD_voidDrawPattern(u8 copy_u8patternNumber ,u8 *copy_u8string);
void LCD_voidrWitePattern(u8 copy_u8pattern , u8 copy_u8line ,u8 copy_u8position);
void LCD_voidWriteNumber(u8 copy_u8number);
void LCD_voidShiftRight(void);
void LCD_voidShiftLift(void);
void LCD_voidClearDisplay(void);
void LCD_voidSetFallingEadge(void);



#endif
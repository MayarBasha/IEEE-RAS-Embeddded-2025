#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


#define  ADC0   0
#define  ADC1   1
#define  ADC2   2
#define  ADC3   3
#define  ADC4   4
#define  ADC5   5
#define  ADC6   6
#define  ADC7   7



void ADC_voidInIt(void);
u16  ADC_u16ReadSynchronus(u8 copy_u8channelNumber);
u16  ADC_u16ReadAsynchronus(u8 copy_u8channelNumber, void (*LocalPtToFunction)(void));


#endif
#ifndef TIMER1_INTERFACE_H
#define TIMER1_INTERFACE_H

void TIMER1_voidInit (void);
void TIMER1_voidSetCallBack_OVF (void (*Local_PointerToFunction_OVF) (void));
void TIMER1_voidSetCallBack_CTC (void (*Local_PointerToFunction_CTC) (void));
void TIMER1_voidSetPreloadValue ( u16 Copy_u16PreloadValue );


#endif
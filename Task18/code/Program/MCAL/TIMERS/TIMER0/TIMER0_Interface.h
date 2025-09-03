#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

void TIMER0_voidInit(void);
void TIMER0_voidSetCallBack_OVF (void (*Local_PointerToFunction_OVF) (void), f32 const requiredTime_ms);
void TIMER0_voidSetCallBack_CTC(void(*LocalPtToFunction)(void));
void TIMER0_voidSetPreloadValue(u8 copy_preloadValue);
void TIMER0_voidSetCompareMatchValue ( u8 Copy_u8CompareMatchValue );
void TIMER0_isrCounterCalculations(u32 Copy_u32Time_ms, u8 TimerMode, u8 CompareMatchValue);
void TIMER0_delay_ms ( u32 Copy_u32Time_ms );
#endif
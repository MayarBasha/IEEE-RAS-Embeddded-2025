#include "../../../LIB/STD_TYPES.h"
#include "../../../LIB/BIT_MATH.h"

#include "TIMER0_Interface.h"
#include "TIMER0_Private.h"
#include "TIMER0_Config.h"

void (*Global_PointerToFunction_OVF_T0)(void) = NULL ; 
void (*Global_PointerToFunction_CTC_T0)(void) = NULL ;
f64 CLK_DivisionFactor[5] = {1, 8, 64, 256, 1024};
u16 Global_u8PreloadValue = 0 ;
u16 Global_u8CompareMatchValue = 0 ;
f64 isrCounter_CTC = 0 ;
f64 isrCounter_OVF = 0 ;





void TIMER0_voidInit (void)
{
/*======================================*/
/*         TIMER0 Mode Selection        */
/*--------------------------------------*/
    #if (MODE == NORMAL_OVF)                             // OVF Normal Mode of Timer/Counter0
        CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_WGM00);
        CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_WGM01);
		SET_BIT(TIMSK_REG,TIMER0_TIMSK_TOIE0);          // Enable T0 OVF Interrupt [PIE].        

    #elif (MODE == PWM_PHASECORRECT)                     // PWM_Phase Correct Mode of Timer/Counter0
        SET_BIT(TCCR0_REG,TIMER0_TCCR0_WGM00);
        CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_WGM01);
        /*======================================*/
        /*          OC0 Mode Selection          */
        /*--------------------------------------*/
        #if ( OC0_MODE == DISCONNECTED )
            CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_COM00);
            CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_COM01);
        #elif ( OC0_MODE == SETonCOMPdownCounting_CLEARonCOMPupCounting )
            CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_COM00);
            SET_BIT(TCCR0_REG,TIMER0_TCCR0_COM01);
        #elif ( OC0_MODE == SETonCOMPupCounting_CLEARonCOMPdownCounting )
            SET_BIT(TCCR0_REG,TIMER0_TCCR0_COM00);
            SET_BIT(TCCR0_REG,TIMER0_TCCR0_COM01);
        #else 
            #error  Wrong selection of OC0 mode
        #endif

    #elif (MODE == CTC)                                  // CTC Mode of Timer/Counter0
        CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_WGM00);
        SET_BIT(TCCR0_REG,TIMER0_TCCR0_WGM01);
		SET_BIT(TIMSK_REG,TIMER0_TIMSK_OCIE0);          // Enable T0 CTC Interrupt [PIE]. 

    #elif (MODE == FAST_PWM)                             // Fast-PWM Mode of Timer/Counter0
        SET_BIT(TCCR0_REG,TIMER0_TCCR0_WGM00);
        SET_BIT(TCCR0_REG,TIMER0_TCCR0_WGM01);
        /*======================================*/
        /*          OC0 Mode Selection          */
        /*--------------------------------------*/
        #if ( OC0_MODE == DISCONNECTED )
            CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_COM00);
            CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_COM01);
        #elif ( OC0_MODE == SETonTOP_CLEARonCOMPARE )
            CLEAR_BIT(TCCR0_REG,TIMER0_TCCR0_COM00);
            SET_BIT(TCCR0_REG,TIMER0_TCCR0_COM01);
        #elif ( OC0_MODE == SETonCOMPARE_CLEARonTOP )
            SET_BIT(TCCR0_REG,TIMER0_TCCR0_COM00);
            SET_BIT(TCCR0_REG,TIMER0_TCCR0_COM01);
        #else 
            #error  Wrong selection of OC0 mode
        #endif

    #else 
        #error  Wrong selection of operation mode
    #endif 

/*     TIMER0 Prescaller Selection      */
/*--------------------------------------*/
    TCCR0_REG &= 0xF8;        // Clear Prescaller bits 3-bits LSB 
    TCCR0_REG |= PRESCALER ;  // write Prescaller configuration bits

}

    

void TIMER0_voidSetCallBack_OVF (void (*Local_PointerToFunction_OVF) (void), f32 const requiredTime_ms)
{
    TIMER0_isrCounterCalculations(requiredTime_ms,NORMAL_OVF,0U); // isrCounter_OVF
    u8 preLoadValue = 256U - (256U * (f64)(isrCounter_OVF - ((u32)isrCounter_OVF)));
    if((preLoadValue > 0U) && (preLoadValue < 256U)) {
        TIMER0_voidSetPreloadValue(preLoadValue);
        isrCounter_OVF++;
    }
    Global_PointerToFunction_OVF_T0 = Local_PointerToFunction_OVF ;
}


void TIMER0_voidSetCallBack_CTC(void(*LocalPtToFunction)(void)){

    Global_PointerToFunction_CTC_T0 = LocalPtToFunction;

}

void TIMER0_voidSetPreloadValue(u8 copy_preloadValue){

    #if (MODE == NORMAL_OVF)
        TCNT0_REG = copy_preloadValue ;
        Global_u8PreloadValue = copy_preloadValue ;
    #else
        // No Action
    #endif

}
void TIMER0_voidSetCompareMatchValue ( u8 Copy_u8CompareMatchValue ){

    #if (MODE == CTC)
        OCR0_REG = Copy_u8CompareMatchValue ;
        Global_u8CompareMatchValue = Copy_u8CompareMatchValue;
    #elif ( MODE == FAST_PWM )
        OCR0_REG = Copy_u8CompareMatchValue ;
    #elif (MODE == PWM_PHASECORRECT)
        OCR0_REG = Copy_u8CompareMatchValue ;
    #endif
}

void TIMER0_isrCounterCalculations(u32 Copy_u32Time_ms, u8 TimerMode, u8 CompareMatchValue){
    f64  timerCLK      = (CPU_CLK / CLK_DivisionFactor[PRESCALER - 1]);  // timerCLK (MHz)
    f64  tickTime      = (1 / timerCLK);         // tickTime (us)
    switch(TimerMode)
    {
        case NORMAL_OVF:{
            f64  OVF_Time   = (256U * tickTime);
            isrCounter_OVF = (Copy_u32Time_ms * 1000UL) / OVF_Time; // (Required Time(ms) * 1000) / (Over Flow time)
        break;
        }case CTC:{
            f64  CTC_Time   = (CompareMatchValue * tickTime);
            isrCounter_CTC = (Copy_u32Time_ms * 1000UL) / (u32)CTC_Time; // (Required Time(ms) * 1000) / (Compare Match time)
        break;
        }
    }
}


void TIMER0_delay_ms ( u32 Copy_u32Time_ms ){
    TIMER0_voidSetCompareMatchValue (200);
    CLEAR_BIT(TIMSK_REG,TIMER0_TIMSK_OCIE0);   // Disable T0 CTC Interrupt [PIE].
    f64 timerCLK      = (CPU_CLK / CLK_DivisionFactor[PRESCALER - 1]);  // timerCLK (MHz)
    f64 tickTime      = (1 / timerCLK);        // tickTime (us)
    f64 CTC_Time      = (200 * tickTime);
    u32 Counter_CTC   = (Copy_u32Time_ms * 1000UL) / (u32)CTC_Time; // (Required Time(ms) * 1000) / (Compare Match time)

    for (u32 iter =0 ; iter < Counter_CTC ; iter++)
    {
        u8 Local_u8Flag = GET_BIT(TIFR_REG,TIMER0_TIFR_OCF0);
        while ( Local_u8Flag == 0 )
        {
    		Local_u8Flag = GET_BIT(TIFR_REG,TIMER0_TIFR_OCF0);      // Polling in the CTC Flag
        }
		SET_BIT(TIFR_REG,TIMER0_TIFR_OCF0);						    // Clear Flag
    }

    SET_BIT(TIMSK_REG,TIMER0_TIMSK_OCIE0);     // Enable T0 CTC Interrupt [PIE]. 
}



void __vector_11 (void)   __attribute__((signal));
void __vector_11 (void)
{
    static u32 counter = 0 ;
    counter ++ ;
    if ( counter == (u32)isrCounter_OVF )
    {
        if(Global_PointerToFunction_OVF_T0 != NULL)
		{
    		Global_PointerToFunction_OVF_T0();                 // Action of OVF Application Function
		}
        counter = 0 ; 
        TCNT0_REG = Global_u8PreloadValue ;                 // For Next Period Preload Value.
    }
}


void __vector_10 (void)   __attribute__((signal));
void __vector_10 (void)
{
    static u16 counter = 0 ;
    counter ++ ;
    if ( counter == (u32)isrCounter_CTC )
    {
        if(Global_PointerToFunction_CTC_T0 != NULL)
        {
            Global_PointerToFunction_CTC_T0();               // Action of CTC Application Function 
        }                
        counter = 0 ;                                        // For Next Period.
        OCR0_REG = Global_u8CompareMatchValue ;              // For Next Period Compare Match Value.
    }
}
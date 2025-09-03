#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H


/*===============================================*/
/*       Select Reference Voltage       */
/*--------------------------------------*/
#define     AREF                         0
#define     AVCC                         1
#define     RESERVED                     2
#define     INTERNAL                     3
/*===============================================*/
#define     REFERENCE_VOLTAGE           AVCC
/*===============================================*/
/*     Select RIGHT or LEFT Adjust      */
/*--------------------------------------*/
#define     RIGHT                        0
#define     LEFT                         1
/*===============================================*/
#define     ADJUST                     RIGHT
/*===============================================*/
/*        ADC ENABLE or DISABLE         */
/*--------------------------------------*/
#define     DISABLE                      0
#define     ENABLE                       1
/*===============================================*/
#define     ADEN                       ENABLE
/*===============================================*/
/*    AUTO Trigger Enable or Disable    */
/*--------------------------------------*/
#define     DISABLE                      0
#define     ENABLE                       1
/*===============================================*/
#define     ADATE                      DISABLE
/*===============================================*/
/*       ADC Auto Trigger Source        */
/*--------------------------------------*/
#define  Free_Running_Mode               0
#define  Analog_Comparator               1
#define  External_Interrupt_Request_0    2

/*===============================================*/
#define  AUTO_TRIGGER_SOURCE     Free_Running_Mode
/*===============================================*/
/*    ADC Interrupt Enable or Disable   */
/*--------------------------------------*/
#define     DISABLE                      0
#define     ENABLE                       1
/*===============================================*/
#define     ADIE                       ENABLE
/*===============================================*/
/*        ADC Prescaler Selection        */
/*---------------------------------------*/
#define     NOT_USE_PRESCALER             0
#define     PRESCALER_DIVISION_BY_2       2
#define     PRESCALER_DIVISION_BY_4       4
#define     PRESCALER_DIVISION_BY_8       8
#define     PRESCALER_DIVISION_BY_16      16
#define     PRESCALER_DIVISION_BY_32      32
#define     PRESCALER_DIVISION_BY_64      64
#define     PRESCALER_DIVISION_BY_128     128
/*===============================================*/
#define     PRESCALER           NOT_USE_PRESCALER
/*===============================================*/


#endif
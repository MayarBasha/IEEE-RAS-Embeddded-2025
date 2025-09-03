
#ifndef WDT_PRIVATE_H_
#define WDT_PRIVATE_H_
#define WDT_WDTCR  (*(volatile u8 *)0x41)


#define WDTCR_WDP0   0x00
#define WDTCR_WDP1   0x01
#define WDTCR_WDP2   0x02
#define WDTCR_WDE 	 0x03
#define WDTCR_WDPTOE 0x04

#endif 
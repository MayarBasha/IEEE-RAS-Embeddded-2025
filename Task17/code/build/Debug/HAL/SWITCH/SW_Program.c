#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "SW_Interface.h"
#include "SW_Private.h"
#include "SW_Config.h"

#include "../../MCAL/DIO/DIO_Interface.h"


void SW_voidInIt (u8 copy_u8PORT ,u8 copy_u8PIN , u8 copy_u8pullUpStatus){


if (copy_u8PORT <= PORTD && copy_u8PIN <= PIN7 ){

   DIO_voidSetPinDirction(copy_u8PORT , copy_u8PIN , INPUT);
   DIO_voidConfigPullUpPin(copy_u8PORT , copy_u8PIN ,  copy_u8pullUpStatus);
  
 }

}
u8  SW_u8GetSwitchValue(u8 copy_u8PORT ,u8 copy_u8PIN ){
 u8 loc_u8Status =0;
 if (copy_u8PORT <= PORTD && copy_u8PIN <= PIN7 ){
   loc_u8Status = DIO_voidGetPinValue(copy_u8PORT , copy_u8PIN);
  
 }

return loc_u8Status;
}

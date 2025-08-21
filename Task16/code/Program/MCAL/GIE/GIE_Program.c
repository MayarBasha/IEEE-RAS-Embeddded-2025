#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "GIE_Interface.h"
#include "GIE_Private.h"
#include "GIE_Config.h"


void GIE_voidEnable(u8 copy_u8status){
switch(copy_u8status){
  case ON :       SET_BIT(SREG_REG,7);           break;
  case OFF:       CLEAR_BIT(SREG_REG,7);         break;
 }
}
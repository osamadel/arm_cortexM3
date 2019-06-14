#include "LSTD_TYPES.h"
#include "LDELAY_private.h"
#include "LDELAY_interface.h"

void LDelay_ms(u32 Copy_u32Value) {
    Copy_u32Value -= (LDELAY_U16_CALCULATION_TIME + LDELAY_U16_CONTEXT_SWITCH);
    Copy_u32Value = Copy_u32Value * 1000000 / LDELAY_U8_LOOP_TIME;
    u32 i;
    for (i = 0; i < Copy_u32Value; i++)
        asm("nop");
}
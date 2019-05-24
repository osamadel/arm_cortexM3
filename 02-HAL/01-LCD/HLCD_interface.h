#ifndef __HLCD_INTERFACE_H
#define __HLCD_INTERFACE_H

void HLCD_voidInitialize        (u8 Copy_u8Mode);
void HLCD_voidClearDisplay      (void);
void HLCD_voidWriteCommand      (u8 Copy_u8Command);
void HLCD_voidWriteData         (u8 Copy_u8Data);
void HLCD_voidWriteText         (u8 * Copy_u8Text);
void HLCD_voidSetCursor         (u8 Copy_u8Line, u8 Copy_u8Offset);
void HLCD_voidShiftDisplay      (u8 Copy_u8Direction);
void HLCD_voidShiftCursor       (u8 Copy_u8Direction, u8 Copy_u8Steps);

#define HLCD_U8_MODE            HLCD_U8_8BIT
#define HLCD_U8_8BIT            0
#define HLCD_U8_4BIT            1
#define HLCD_U8_SHFL            0
#define HLCD_U8_SHFR            1

#endif
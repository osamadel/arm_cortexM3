#ifndef __MRCC_INTERACE_H
#define __MRCC_INTERACE_H

void MRCC_voidEnPeriphClk(u8 Copy_u8PeriphIdx);

// will give values depending on which bus they're on
// so by dividing the macro on 32, the register number will indicate
// the enable register, and the reminder will indicate the bit

#define MRCC_U8_DMA1            0
#define MRCC_U8_DMA2            1
#define MRCC_U8_SRAM            2
#define MRCC_U8_FLITFEN         4
#define MRCC_U8_CRCEN           6
#define MRCC_U8_FSMCEN          8
#define MRCC_U8_SDIOEN          10

// #define MRCC_U8_TIM2            32
// #define MRCC_U8_TIM3            33
// #define MRCC_U8_TIM4            34
// #define MRCC_U8_TIM5            35
// #define MRCC_U8_TIM6            36
// #define MRCC_U8_TIM7            37
// #define MRCC_U8_TIM13           38
// #define MRCC_U8_TIM14           39
// #define MRCC_U8_WWDGEN          42
// #define MRCC_U8_SPI2            45
// #define MRCC_U8_SPI3            46
#define MRCC_U8_AFIOEN             32
#define MRCC_U8_IOPAEN             34
#define MRCC_U8_IOPBEN             35
#define MRCC_U8_IOPCEN             36




#endif

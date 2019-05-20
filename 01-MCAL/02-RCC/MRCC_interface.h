#ifndef __MRCC_INTERACE_H
#define __MRCC_INTERACE_H

void MRCC_voidEnPeriphClk(u8 Copy_u8PeriphIdx);

// will give values depending on which bus they're on
// so by dividing the macro on 32, the register number will indicate
// the enable register, and the reminder will indicate the bit

// RCC_AHBEN bits
#define MRCC_U8_DMA1 			0
#define MRCC_U8_DMA2 			1
#define MRCC_U8_SRAM 			2
#define MRCC_U8_FLITF 			4
#define MRCC_U8_CRC 			6
#define MRCC_U8_FSMC 			8
#define MRCC_U8_SDIO 			10

// RCC_APB1ENR bits
#define MRCC_U8_TIM2            64
#define MRCC_U8_TIM3            65
#define MRCC_U8_TIM4            66
#define MRCC_U8_TIM5            67
#define MRCC_U8_TIM6            68
#define MRCC_U8_TIM7            69
#define MRCC_U8_TIM12           70
#define MRCC_U8_TIM13           71
#define MRCC_U8_TIM14           72
#define MRCC_U8_WWDGEN          75
#define MRCC_U8_SPI2            78
#define MRCC_U8_SPI3            79

// RCC_APB2ENR bits
#define MRCC_U8_AFIOEN             32
#define MRCC_U8_IOPAEN             34
#define MRCC_U8_IOPBEN             35
#define MRCC_U8_IOPCEN             36





#endif

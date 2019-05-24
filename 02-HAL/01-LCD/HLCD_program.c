#include "LSTD_TYPES.h"
#include "MDIO_interface.h"
#include "HLCD_private.h"
#include "HLCD_interface.h"
#include "HLCD_config.h"


void HLCD_voidDelay_ms(u8 Copy_u8Delay) {
    /* 
    TICK = 1 / 8e+6
    loop = 4 instructions = 4 cycles
    1 nop = 4 ticks = 1 / 2e+6 = 0.5 microseconds
    delay in ms, 1 ms = 1000 microseconds = 1000 nop
     */
    u32 Local_u8Delay_uSec = Copy_u8Delay * 2000;
    for (u32 i=0; i < Local_u8Delay_uSec; i++)
        asm("nop");
}

void HLCD_voidWriteText (u8 * Copy_u8Text) {
	for (u8 i=0; Copy_u8Text[i]!='\0'; i++)
		HLCD_voidWriteData(Copy_u8Text[i]);
	return;
}

void HLCD_voidClearDisplay(void) {
	HLCD_voidWriteCommand(0b00000001);
	return;
}// end HLCD_clear

void HLCD_voidSetCursor (u8 Copy_u8Line, u8 Copy_u8Offset) {
		u8 cmd = ( (Copy_u8Line * HLCD_LINE_2_ADDR)|(HLCD_SET_RAM_ADDR_B7) ) + Copy_u8Offset;	// AC address is 7-bit while instruction is 8 bit, b7 is 1
		HLCD_voidWriteCommand(cmd);		
	return;
}

void HLCD_voidShiftDisplay (u8 Copy_u8Direction) {
		if (Copy_u8Direction == HLCD_U8_SHFL)
			HLCD_voidWriteCommand(0b00011000);
		else if (Copy_u8Direction == HLCD_U8_SHFR)
			HLCD_voidWriteCommand(0b00011100);
	return;
}// end HLCD_shiftDisplay

void HLCD_voidShiftCursor (u8 Copy_u8Direction, u8 Copy_u8Steps) {
	if (Copy_u8Direction == HLCD_U8_SHFL)
		for (u8 i=0; i<Copy_u8Steps; i++)
			HLCD_voidWriteCommand(0b00010000);
	else if (Copy_u8Direction == HLCD_U8_SHFR)
		for (u8 i=0; i<Copy_u8Steps; i++)
			HLCD_voidWriteCommand(0b00010100);
	return;
}// end

void HLCD_init(u8 m) {
    // initialize LCD pins to output
    MDIO_voidInitialize();
	// set E to (0)
	MDIO_voidSetPinValue(HLCD_E, DIO_U8_LOW);
	// start init
	HLCD_voidDelay_ms(50);
    HLCD_voidWriteCommand(0b00111100); // set LCD to 8-bit mode, 2 lines, 5x10 font size
    HLCD_voidDelay_ms(1);
    HLCD_voidWriteCommand(0b00001111); // set LCD display ON, cursor ON, cursor blink ON
    HLCD_voidDelay_ms(1);
    HLCD_voidWriteCommand(0b00000001); // clear LCD display
    HLCD_voidDelay_ms(2);
    HLCD_voidWriteCommand(0b00000110); // set Address Counter to increasing, NO display shift
	return;
}// end HLCD_init

//LCD in 8-bit mode
void HLCD_voidWriteCommand(u8 cmd) {
	MDIO_voidSetPinValue(HLCD_RS, DIO_U8_LOW);		// set RS to 0 (Command Reg)
	MDIO_voidSetPinValue(HLCD_RW, DIO_U8_LOW);		// Set RW to 0

	// Write the command to D0-D7
    MDIO_voidSetPinValue(HLCD_D0, 1 & (cmd >> 0));
    MDIO_voidSetPinValue(HLCD_D0, 1 & (cmd >> 1));
    MDIO_voidSetPinValue(HLCD_D0, 1 & (cmd >> 2));
    MDIO_voidSetPinValue(HLCD_D0, 1 & (cmd >> 3));
    MDIO_voidSetPinValue(HLCD_D0, 1 & (cmd >> 4));
    MDIO_voidSetPinValue(HLCD_D0, 1 & (cmd >> 5));
    MDIO_voidSetPinValue(HLCD_D0, 1 & (cmd >> 6));
    MDIO_voidSetPinValue(HLCD_D0, 1 & (cmd >> 7));

	MDIO_voidSetPinValue(HLCD_E, DIO_U8_HIGH);		// Set E to 1 (Read Data)
	HLCD_voidDelay_ms(2);							// delay 2ms
	MDIO_voidSetPinValue(HLCD_E, DIO_U8_LOW);			// Set E to 0 (falling edge: Write Data)
	return;
}// end HLCD_voidWriteCommand

void HLCD_writeData(u8 data) {
	MDIO_voidSetPinValue(HLCD_RS, DIO_U8_HIGH);		// set RS to 1 (Data Reg)
	MDIO_voidSetPinValue(HLCD_RW, DIO_U8_LOW); 		// Set RW to 0

    // Write the data to D0-D7
    MDIO_voidSetPinValue(HLCD_D0, 1 & (data >> 0));
    MDIO_voidSetPinValue(HLCD_D0, 1 & (data >> 1));
    MDIO_voidSetPinValue(HLCD_D0, 1 & (data >> 2));
    MDIO_voidSetPinValue(HLCD_D0, 1 & (data >> 3));
    MDIO_voidSetPinValue(HLCD_D0, 1 & (data >> 4));
    MDIO_voidSetPinValue(HLCD_D0, 1 & (data >> 5));
    MDIO_voidSetPinValue(HLCD_D0, 1 & (data >> 6));
    MDIO_voidSetPinValue(HLCD_D0, 1 & (data >> 7));
    
    MDIO_voidSetPinValue(HLCD_E, DIO_U8_HIGH); 		// Set E to 1 (Read Data)
    HLCD_voidDelay_ms(2);							// delay 2ms
    MDIO_voidSetPinValue(HLCD_E, DIO_U8_LOW); 		// Set E to 0 (falling edge: Write Data)

	return;
} // end HLCD_writeData

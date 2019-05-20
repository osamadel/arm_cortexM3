#include "LSTD_TYPES.h"
#include "LUTILS.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"

void MDIO_voidInitialize(void) {
	/* Not Configurable Yet */
    GPIOA_CRL = 0x22222222;
    GPIOA_CRH = 0x22222222;
    GPIOB_CRL = 0x22222222;
    GPIOB_CRH = 0x22222222;
    GPIOC_CRH = 0x22222222;
}

void MDIO_voidSetPinValue (u8 Copy_u8PinNo, u8 Copy_u8PinVal) {

    u8 Local_u8Port = Copy_u8PinNo / DIO_U8_PORT_SIZE;
    u8 Local_u8Pin  = Copy_u8PinNo & DIO_U8_PORT_SIZE;
    if ( Copy_u8PinVal == DIO_U8_HIGH ) {

        switch (Local_u8Port)
        {
        case DIO_U8_PORTA:
            LUTILS_SET_BIT(GPIOA_ODR, Local_u8Pin);
            break;

        case DIO_U8_PORTB:
            LUTILS_SET_BIT(GPIOB_ODR, Local_u8Pin);
            break;

        case DIO_U8_PORTC:
            LUTILS_SET_BIT(GPIOC_ODR, Local_u8Pin);
            break;
        
        default:
        	break;
            /* Report Error */
        }

    } else if ( Copy_u8PinVal == DIO_U8_LOW ) {

        switch (Local_u8Port)
        {
        case DIO_U8_PORTA:
        	LUTILS_CLR_BIT(GPIOA_ODR, Local_u8Pin);
            break;

        case DIO_U8_PORTB:
            LUTILS_CLR_BIT(GPIOB_ODR, Local_u8Pin);
            break;

        case DIO_U8_PORTC:
            LUTILS_CLR_BIT(GPIOC_ODR, Local_u8Pin);
            break;
        
        default:
        	break;
            /* Report Error */
        }

    } else {
        /* Report Error */
    }
}

void MDIO_voidGetPinValue (u8 Copy_u8PinNo, u8 * Copy_u8PinVal) {

}

void MDIO_voidSetPinMode (u8 Copy_u8PinNo, u8 Copy_u8PinMode) {

}

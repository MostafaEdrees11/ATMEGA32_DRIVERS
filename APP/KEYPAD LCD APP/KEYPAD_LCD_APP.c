/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mostafa Edrees
 * @brief          : application file of KEYPAD.
 * @date           : 3/11/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#define F_CPU 1000000UL

#include "../../LIB/stdTypes.h"
#include "../../LIB/Error_States.h"

#include "../../HAL/KEYPAD/KEYPAD_config.h"
#include "../../HAL/KEYPAD/KEYPAD_int.h"

#include "../../HAL/LCD/LCD_config.h"
#include "../../HAL/LCD/LCD_int.h"

#include "../../MCAL/DIO/DIO_int.h"

#include <util/delay.h>

void KEYPAD_LCD_APP(void)
{
	LCD_enuInit();
	KEYPAD_enuInit();

	u8 Local_u8KeyPressed;

    /* Replace with your application code */
    while (1)
    {
		Local_u8KeyPressed = KEYPAD_u8GetPressedKey();
		switch(Local_u8KeyPressed)
		{
			case 'c':
			LCD_vidClearScreen();
			break;

			case KEYPAD_No_Key_Pressed:
			break;

			default:
			LCD_enuDisplayChar(Local_u8KeyPressed);
		};
    }
}


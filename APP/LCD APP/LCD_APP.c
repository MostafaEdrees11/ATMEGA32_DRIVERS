/*
 * LCD_APP.c
 *
 *  Created on: Mar 7, 2024
 *      Author: Mostafa Edrees
 */

#include "../../LIB/stdTypes.h"
#include "../../LIB/Error_States.h"

#include "../../HAL/LCD/LCD_config.h"
#include "../../HAL/LCD/LCD_int.h"

#include "../../MCAL/DIO/DIO_int.h"

#include <util/delay.h>

void LCD_APP(void)
{
	ES_t error = ES_NOK;
	error = LCD_enuInit();

	if(error == ES_OK)
	{
		LCD_enuWriteString("Mostafa Edrees");
		_delay_ms(3000);
		LCD_vidClearScreen();
		LCD_enuWriteString("CAT Reloaded");
		_delay_ms(3000);
		LCD_vidClearScreen();
	}
}

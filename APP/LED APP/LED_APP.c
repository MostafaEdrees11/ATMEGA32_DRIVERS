/*
 * LED_APP.c
 *
 *  Created on: Mar 7, 2024
 *      Author: Mostafa Edrees
 */


/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mostafa Edrees
 * @brief          : application file of LED.
 * @date           : 10/13/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#define F_CPU		1000000UL

#include "../../LIB/stdTypes.h"
#include "../../LIB/Error_States.h"

#include "../../HAL/LED/LED_config.h"
#include "../../HAL/LED/LED_int.h"

#include "../../HAL/SWITCH/Switch_config.h"
#include "../../HAL/SWITCH/Switch_int.h"

#include "../../MCAL/DIO/DIO_int.h"

#include <util/delay.h>

extern LED_t LED_AstrLedConfig[LED_NUM];
extern SW_t SW_AstrSwitchConfig[SW_NUM];


/* snake effect & flower in the same program to check led & switch drivers */
void LED_APP(void)
{
	Switch_enuINIT(&SW_AstrSwitchConfig);
	LED_enuINIT(LED_AstrLedConfig);

	u8 SW1, SW2;

	s8 i, j;

	while(1)
	{
		Switch_enuGetState(&SW_AstrSwitchConfig[0], &SW1);
		Switch_enuGetState(&SW_AstrSwitchConfig[1], &SW2);

		/* if SW1 & SW2 is not pressed so we turn off all leds */
		if(SW1 == 1 && SW2 == 1)
		{
			for(i = 0; i < 8; i++)
			{
				LED_enuTurnOFF(&LED_AstrLedConfig[i]);
			}
			while(SW1 == 1 && SW2 == 1)
			{
				Switch_enuGetState(&SW_AstrSwitchConfig[0], &SW1);
				Switch_enuGetState(&SW_AstrSwitchConfig[1], &SW2);
			}
		}

		/* if SW1 is pressed so we turn on snake effect */
		if(SW1 == 0 && SW2 == 1)
		{
			for(i = 0; i < 8; i++)
			{
				LED_enuTurnON(&LED_AstrLedConfig[i]);
				_delay_ms(150);
			}
			for(i = 7; i >= 0; i--)
			{
				LED_enuTurnOFF(&LED_AstrLedConfig[i]);
				_delay_ms(150);
			}
		}

		/* if SW2 is pressed so we turn on flower effect */
		if(SW2 == 0 && SW1 == 1)
		{
			for(i = 3; i >= 0; i--)
			{
				LED_enuTurnON(&LED_AstrLedConfig[i]);
				LED_enuTurnON(&LED_AstrLedConfig[7-i]);
				_delay_ms(150);
			}
			for(j = 0; j < 3; j++)
			{
				LED_enuTurnOFF(&LED_AstrLedConfig[j]);
				LED_enuTurnOFF(&LED_AstrLedConfig[7-j]);
				_delay_ms(150);
			}
		}
	}
}

void Control_LED_by_SW(void)
{
	DIO_enuINIT();
	LED_enuINIT(&LED_AstrLedConfig);
	Switch_enuINIT(&SW_AstrSwitchConfig);

	u8 Pin_state;

    /* Replace with your application code */
    while (1)
    {
		Switch_enuGetState(&SW_AstrSwitchConfig[1], &Pin_state);
		if(Pin_state == 0)
		{
			LED_enuTurnON(&LED_AstrLedConfig[2]);
		}
		else if(Pin_state == 1)
		{
			LED_enuTurnOFF(&LED_AstrLedConfig[2]);
		}
    }
}

/*
 * SEV_SEG_APP.c
 *
 *  Created on: Mar 7, 2024
 *      Author: Mostafa Edrees
 */


/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mostafa Edrees
 * @brief          : application file of Seven_Segment_Linking_Time.
 * @date           : 20/13/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/
#define F_CPU	1000000UL

#include "../../LIB/stdTypes.h"
#include "../../LIB/Error_States.h"

#include "../../HAL/SEVEN_SEG/Seven_Segment_config.h"
#include "../../HAL/SEVEN_SEG/Seven_Segment_int.h"

#include "../../MCAL/DIO/DIO_int.h"

#include <util/delay.h>

extern SEG_t SEV_SEG_AstrSEGConfig[SEG_NUM];

//POV to display 25
void SEV_SEG_APP(void)
{
	ES_t error;
	error = Seven_Segment_enuInit(SEV_SEG_AstrSEGConfig);

	/* Replace with your application code */
	while (1)
	{
		if(error == ES_OK)
		{
			Seven_Segment_enuDisableCommon(1);
			Seven_Segment_enuDisplayNumber(0,5);
			Seven_Segment_enuEnableCommon(0);
			_delay_ms(10);
			Seven_Segment_enuDisableCommon(0);
			Seven_Segment_enuDisplayNumber(1,2);
			Seven_Segment_enuEnableCommon(1);
			_delay_ms(15);
		}
	}
}

//count up from 0 to 99
//void CountUp0_99(void)
//{
//	ES_t error;
//	error = Seven_Segment_enuInit(SEV_SEG_AstrSEGConfig);
//
//    /* Replace with your application code */
//    while (1)
//    {
//		if(error == ES_OK)
//		{
//			for(u8 i = 0; i < 10; i++)
//			{
//				Seven_Segment_enuDisplayNumber(0,i);
//				Seven_Segment_enuDisplayNumber(1,0);
//				for(u8 j = 0; j < 10; j++)
//				{
//					Seven_Segment_enuDisplayNumber(1,j);
//					_delay_ms(300);
//				}
//			}
//		}
//    }
//}


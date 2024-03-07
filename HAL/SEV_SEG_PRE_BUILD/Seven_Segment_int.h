/**
 ******************************************************************************
 * @file           : Seven_Segment_int.h
 * @author         : Mostafa Edrees
 * @brief          : interface file of Seven Segment.
 * @date           : 10/20/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#ifndef SEVEN_SEGMENT_INT_H_
#define SEVEN_SEGMENT_INT_H_

ES_t Seven_Segment_PreBuild_enuInit(void);

ES_t Seven_Segment_PreBuild_enuDisplayNumber(u8 Copy_u8Number);

ES_t Seven_Segment_PreBuild_enuEnableCommon(void);

ES_t Seven_Segment_PreBuild_enuDisableCommon(void);

ES_t Seven_Segment_PreBuild_enuEnableDot(void);

ES_t Seven_Segment_PreBuild_enuDisableDot(void);

ES_t Seven_Sement_PreBuild_enuTurnOFF(void);


#endif /* SEVEN_SEGMENT_INT_H_ */

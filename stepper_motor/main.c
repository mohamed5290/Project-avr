/*
 * main.c
 *
 *  Created on: Jan 16, 2021
 *      Author: MOHAMED ADEL
 */
#define  F_CPU   8000000UL
#include <util/delay.h>
#include "BIT_MATH.h"
#include "DATA_TYPE.h"

#include "DIO_interface.h"
#include "STEPPER_MOTOR_interfac.h"

int main()
{
	DIO_voidInit();

	DIO_u8SetPinValue(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_LOW);
	DIO_u8SetPinValue(DIO_U8_PORTC,DIO_U8_PIN1,DIO_U8_LOW);
	DIO_u8SetPinValue(DIO_U8_PORTC,DIO_U8_PIN2,DIO_U8_LOW);
	DIO_u8SetPinValue(DIO_U8_PORTC,DIO_U8_PIN3,DIO_U8_HIGH);
	while(1)
	{

	}
/*

	STEPPER_MOTOR_voiddrive(180,1);
	_delay_ms(1000);
	STEPPER_MOTOR_voiddrive(90,2);
	_delay_ms(1000);
	STEPPER_MOTOR_voiddrive(60,2);
	_delay_ms(1000);
*/

}



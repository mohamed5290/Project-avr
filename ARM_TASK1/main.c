/*
 * main.c

 *
 *  Created on: Feb 10, 2021
 *      Author: MOHAMED ADEL
 */

#define F_CPU 8000000UL
#include <util/delay.h>

#include "DATA_TYPE.h"
#include "BIT_MATH.h"


#include  "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"
#include  "KPD_config.h"
#include  "KPD_interface.h"


int main()
{
	u8 x;
	DIO_voidInit();
	while(1)
	{

	KPD_u8getswitch(&x);
	if(x=='1')
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_U8_HIGH);
		_delay_ms(50);
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_U8_LOW);
	}
	if(x=='2')
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_U8_HIGH);
		_delay_ms(100);
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_U8_LOW);
	}
	if(x=='3')
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_U8_HIGH);
		_delay_ms(150);
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN2,DIO_U8_LOW);
	}

}

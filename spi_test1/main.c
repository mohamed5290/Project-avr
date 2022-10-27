/*
 * main.c
 *
 *  Created on: Jan 27, 2021
 *      Author: MOHAMED ADEL
 */

#define F_CPU 8000000UL
#include <util\delay.h>
#include "DATA_TYPE.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SPI_interface.h"


int main ()
{
	u8 local_u8data,x=1;
	DIO_voidInit();

	SPI_voidInit();
	while(1)
	{
		SPI_u8Transieve(5,&local_u8data);
		if(local_u8data == 5);
		{
			if(x==1)
			{
		 	DIO_u8SetPinValue(DIO_U8_PORTA,DIO_U8_PIN0,DIO_U8_HIGH);
			x=2;
			}
		  	 else if(x==2)
			 {
			 DIO_u8SetPinValue(DIO_U8_PORTA,DIO_U8_PIN0,DIO_U8_LOW);
	         x=1;
		}
		}
		_delay_ms(200);
	}
}

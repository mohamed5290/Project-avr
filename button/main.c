/*
 * main.c
 *
 *  Created on: Jan 5, 2021
 *      Author: MOHAMED ADEL
 */
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "bit_math.h"

void main (void)
{
	DDRD =0x00;
	DDRB =0x0f;
	PORTB =0x00;
	PORTD =0x01;

	while(1)
	{

		if(PIND==0x00)
		{
			PORTB=0x01;
		}
		else
		{
		PORTB =0x00;
		}
	}
}

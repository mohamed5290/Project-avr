/*
 * main.c
 *
 *  Created on: Jan 27, 2021
 *      Author: MOHAMED ADEL
 */
#define F_CPU 8000000UL
#include  <util\delay.h>
#include "BIT_MATH.h"
#include "DATA_TYPE.h"

#include "DIO_interface.h"
#include "UART_interface.h"


int main(void)
{
	u16 x='a';

	DIO_voidInit();

	UART_voidInit();
	while(1)
	{

		UART_Transchar(x);

	//UART_Recivechar(&x);
    _delay_ms(1000);
	/*if(x == 'a')
	{
		DIO_u8SetPinValue(DIO_U8_PORTA,DIO_U8_PIN0,DIO_U8_HIGH);
	}*/


}
}

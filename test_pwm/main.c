/*
 * main.c
 *
 *  Created on: Jan 24, 2021
 *      Author: MOHAMED ADEL
 */

#define  F_CPU 16000000UL
#include <util\delay.h>
#include "BIT_MATH.h"
#include "DATA_TYPE.h"
#include "DIO_interface.h"

#include "TMR_interface.h"




int main()
{
	u8 i=0;
	DIO_voidInit();

	/*
	 * select angle*/

	TMR_voidsetcompmatchvalue1a(1999);

	TMR1_voidinit();

	while(1);

}

/*
 * main.c
 *
 *  Created on: Jun 29, 2022
 *      Author: MOHAMED ADEL
 */


#define  F_CPU 8000000UL
#include <util/delay.h>
#include "BIT_MATH.h"
#include "DATA_TYPE.h"

#include "DIO_config.h"
#include "DIO_interface.h"

#include "LCD_interface.h"
#include "LCD_config.h"
int main (void)
{
	DIO_voidInit();
    LCD_voidInit();

    LCD_VoidSendStr("mohamed");

}

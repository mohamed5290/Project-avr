/*
 * main.c
 *
 *  Created on: Jan 18, 2021
 *      Author: MOHAMED ADEL
 */

#include  "DATA_TYPE.h"
#include  "BIT_MATH.h"


#include  "EXTI_interface.h"
#include  "GINT_interface.h"
#include  "DIO_interface.h"
#include  "DIO_private.h"
void App_void_set(void);

int main()
{
	DIO_voidInit();
	EXTI_u8EXTIsetcallback(EXTI_U8_INT0_call,&App_void_set);
	EXTI_u8enable(EXTI_U8_INT0,EXTI_U8_ANY_LOGICAL_CHANGE);

	GINT_u8_enable();
	while(1);


}




void App_void_set(void)
{
	static u8 local_u8flag=0;
	if(local_u8flag==0)
	{
		DIO_u8SetPinValue(DIO_U8_PORTA,DIO_U8_PIN0,DIO_U8_LOW);
		local_u8flag=1;
	}
	else if(local_u8flag==1)
	{DIO_u8SetPinValue(DIO_U8_PORTA,DIO_U8_PIN0,DIO_U8_HIGH);
	local_u8flag=0;
}
}

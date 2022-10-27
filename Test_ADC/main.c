/*
 * main.c
 *
 *  Created on: Jan 19, 2021
 *      Author: MOHAMED ADEL
 */

#define F_CPU  8000000UL

#include  "DATA_TYPE.h"
#include  "BIT_MATH.h"

#include <util\delay.h>
#include  "ADC_interface.h"
#include  "DIO_interface.h"
#include  "GINT_interface.h"
static	u16 App_16digitalval = 2048;
void app_voidadcnot(u16 copy_u16digitalvalue);

int main ()
{

	u16  local_analogeval;
    u16  local_u16resistance;
	f32 local_f32cuurent ;
	DIO_voidInit();
	LCD_voidInit();
	GINT_u8_enable();
    ADC_voidinit();
while(1)
{

	ADC_u8getdigitalvalueAsynvhronous(ADC_U8_CHANNEL_0,&app_voidadcnot);
	if(App_16digitalval != 2048 )
	{
	                  local_analogeval = (  (u32)App_16digitalval  * 5000UL)/1024;
	                //  local_u16resistance = ((u32)local_analogeval * 1000UL)/(5000-local_analogeval);
	                 // local_f32cuurent = 	local_analogeval / local_u16resistance;
	                  //temp_value = local_analogeval/10;

	                  local_analogeval /=500;

	                  if(local_analogeval==1)
	                  {
	                	  DIO_u8AnalogPort(DIO_U8_PORTD,1);
	                  }
	                  else if(local_analogeval==2)
	                  {
	                	  DIO_u8AnalogPort(DIO_U8_PORTD,3);
	                  }
	                  else if(local_analogeval==3)
	                  {
	                	  DIO_u8AnalogPort(DIO_U8_PORTD,7);
	                  }
	                  else if(local_analogeval==4)
	                  {
	                	  DIO_u8AnalogPort(DIO_U8_PORTD,15);
	                  }
	                  else if(local_analogeval==5)
	                  {
	                	  DIO_u8AnalogPort(DIO_U8_PORTD,31);
	                  }
	                  else if(local_analogeval==6)
	                  {
	                	  DIO_u8AnalogPort(DIO_U8_PORTD,63);
	                  }
	                  else if(local_analogeval==7)
	                  {
	                	  DIO_u8AnalogPort(DIO_U8_PORTD,127);
	                  }
	                  else if(local_analogeval==8)
	                  {
	                	  DIO_u8AnalogPort(DIO_U8_PORTD,255);
	                  }

	}
	App_16digitalval != 2048;
}
}

/*
	                    LCD_Clear();
                        LCD_VoidSendStr("V=");
           	        	LCD_voidSendNumber((f32)local_analogeval);
           	        	LCD_VoidSendStr("mv");
           	        	LCD_voidGotoXY(2,0);
           	        	LCD_VoidSendStr("R=");
           	        	LCD_voidSendNumber((f32)local_u16resistance);
           	        	LCD_VoidSendStr("ohms");
           	        	LCD_voidGotoXY(1,10);
           	        	LCD_VoidSendStr("I=");
           	        	LCD_voidSendNumber(local_f32cuurent);
           	        	LCD_VoidSendStr("mA");
                        _delay_ms(1000);
*/
	/*}
	App_16digitalval != 2048;
}
}*/
/*
    while(1)
    {
    //	ADC_u8getdigitalvalue(ADC_U8_CHANNEL_0,&local_16digitalval);

    	ADC_u8getdigitalvalueAsynvhronous(ADC_U8_CHANNEL_0,&app_voidadcnot);
    	if(App_16digitalval != 2048)
    	{
    	local_analogeval = (  (u32)App_16digitalval  * 5000UL)/1024;
    	local_u16resistance = ((u32)local_analogeval * 1000UL)/(50000-local_analogeval);
    	local_f32cuurent = 	local_analogeval / local_u16resistance;
    	//temp_value = local_analogeval/10;

    	if(local_analogeval<=1500)
        {

        	DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN0,DIO_U8_HIGH);
        	DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN1,DIO_U8_LOW);
        	DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN2,DIO_U8_LOW);
        	LCD_Clear();
        	LCD_VoidSendStr("V=");
        	LCD_voidSendNumber((f32)local_analogeval);
        	LCD_VoidSendStr("v");
        	LCD_voidGotoXY(2,0);
        	LCD_VoidSendStr("R=");
        	LCD_voidSendNumber((f32)local_u16resistance);
        	LCD_VoidSendStr("ohms");
        	LCD_voidGotoXY(1,9);
        	LCD_VoidSendStr("I=");
        	LCD_voidSendNumber(local_f32cuurent);
        	_delay_ms(3000);
        	while(1){}
        }
        if(local_analogeval>1500 && local_analogeval<3000)
        {
        	DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN0,DIO_U8_LOW);
        	DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN1,DIO_U8_HIGH);
        	DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN2,DIO_U8_LOW);
        	LCD_Clear();
        	           LCD_VoidSendStr("V=");
        	        	LCD_voidSendNumber((f32)local_analogeval);
        	        	LCD_VoidSendStr("v");
        	        	LCD_voidGotoXY(2,0);
        	        	LCD_VoidSendStr("R=");
        	        	LCD_voidSendNumber((f32)local_u16resistance);
        	        	LCD_VoidSendStr("ohms");
        	        	LCD_voidGotoXY(1,9);
        	        	LCD_VoidSendStr("I=");
        	        	LCD_voidSendNumber(local_f32cuurent);

        }
        if(local_analogeval>3000)
        {
        	LCD_voidSendNumber(local_analogeval);
        	DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN0,DIO_U8_LOW);
        	DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN1,DIO_U8_LOW);
        	DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN2,DIO_U8_HIGH);
        	LCD_Clear();
        	            LCD_VoidSendStr("V=");
        	        	LCD_voidSendNumber((f32)local_analogeval);
        	        	LCD_VoidSendStr("v");
        	        	LCD_voidGotoXY(2,0);
        	        	LCD_VoidSendStr("R=");
        	        	LCD_voidSendNumber((f32)local_u16resistance);
        	        	LCD_VoidSendStr("ohms");
        	        	LCD_voidGotoXY(1,9);
        	        	LCD_VoidSendStr("I=");
        	        	LCD_voidSendNumber(local_f32cuurent);
        	        	_delay_ms(3000);

        }
        App_16digitalval = 2048;
    	}
    }


    return 0;

}
*/
void app_voidadcnot(u16 copy_u16digitalvalue)
{
	App_16digitalval =  copy_u16digitalvalue;
}


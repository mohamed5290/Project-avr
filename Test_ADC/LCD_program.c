#define  F_CPU 8000000UL
#include <util/delay.h>

#include  "DATA_TYPE.h"
#include  "BIT_MATH.h"

  /*MCAL*/
#include "DIO_interface.h"


#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h" 



void LCD_voidInit(void)
{
	_delay_ms(35);
#if LCD_U8_MOODE == LCD_U8_8_BIT_MOODE
	LCD_voidSendCmd(0x38);
	_delay_ms(1);
#elif LCD_U8_MOODE == LCD_U8_4_BIT_MOODE
  	DIO_u8SetPinValue(RS_PORT,RS,DIO_U8_LOW);

	DIO_u8SetPinValue(RW_PORT,RW,DIO_U8_LOW);

	Private_voidwriteHalfPort(0b0010);

	DIO_u8SetPinValue(E_PORT,E,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(E_PORT,E,DIO_U8_LOW);

	LCD_voidSendCmd(0b00101000);
#endif
	LCD_voidSendCmd(LCD_CURSOR_OFF);
	_delay_ms(1);
	LCD_voidSendCmd(LCD_CLEAR);
	_delay_ms(2);
	LCD_voidSendCmd(0x06);
	_delay_ms(1);
	

}
void LCD_voidSendCmd(u8 Copy_u8cmnd)
{
#if LCD_U8_MOODE == LCD_U8_8_BIT_MOODE
  	DIO_u8SetPinValue(LCD_PORT_CONTROL,RS,DIO_U8_LOW);

	DIO_u8SetPinValue(LCD_PORT_CONTROL,RW,DIO_U8_LOW);
	
	DIO_u8AnalogPort(LCD_PORT,Copy_u8cmnd);
	
	DIO_u8SetPinValue(LCD_PORT_CONTROL,E,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(LCD_PORT_CONTROL,E,DIO_U8_LOW);

#elif LCD_U8_MOODE == LCD_U8_4_BIT_MOODE

  	DIO_u8SetPinValue(RS_PORT,RS,DIO_U8_LOW);

	DIO_u8SetPinValue(RW_PORT,RW,DIO_U8_LOW);

	Private_voidwriteHalfPort(Copy_u8cmnd>>4);

	DIO_u8SetPinValue(E_PORT,E,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(E_PORT,E,DIO_U8_LOW);

	Private_voidwriteHalfPort(Copy_u8cmnd);

	DIO_u8SetPinValue(E_PORT,E,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(E_PORT,E,DIO_U8_LOW);


#endif

}
void LCD_voidSendChar(u8 copy_u8data)
{

#if LCD_U8_MOODE == LCD_U8_8_BIT_MOODE

  	DIO_u8SetPinValue(LCD_PORT_CONTROL,RS,DIO_U8_HIGH);

	DIO_u8SetPinValue(LCD_PORT_CONTROL,RW,DIO_U8_LOW);
	
	DIO_u8AnalogPort(LCD_PORT,copy_u8data);
	
	DIO_u8SetPinValue(LCD_PORT_CONTROL,E,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(LCD_PORT_CONTROL,E,DIO_U8_LOW);

#elif LCD_U8_MOODE == LCD_U8_4_BIT_MOODE

  	DIO_u8SetPinValue(RS_PORT,RS,DIO_U8_HIGH);

	DIO_u8SetPinValue(RW_PORT,RW,DIO_U8_LOW);

	Private_voidwriteHalfPort(copy_u8data>>4);

	DIO_u8SetPinValue(E_PORT,E,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(E_PORT,E,DIO_U8_LOW);

	Private_voidwriteHalfPort(copy_u8data);

	DIO_u8SetPinValue(E_PORT,E,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_u8SetPinValue(E_PORT,E,DIO_U8_LOW);
#endif
}


void LCD_VoidSendStr(u8 * pu8_copystr)
{
	u8 Local_u8loop;


		for(Local_u8loop=0;pu8_copystr[Local_u8loop] !='\0';Local_u8loop++)
		{
			LCD_voidSendChar(pu8_copystr[Local_u8loop]);
		}
   }


void LCD_voidSendNumber(f32 copy_f32data)
{


  u32 local_u32temp=0,reminder,local_u32copy;
  f32 local_f64copy;
  local_u32copy = (u32)copy_f32data;
  local_f64copy =  copy_f32data  - local_u32copy;
  if(copy_f32data==0)
  {
	  LCD_voidSendChar('0');
  }
  else
  {
   if(local_f64copy == 0)
  {

	   local_u32copy=(local_u32copy*10)+1;
	  while(local_u32copy!=0)
	  {
	  reminder = local_u32copy %10;
	  local_u32copy /=10;
	  local_u32temp *=10;
	  local_u32temp =local_u32temp+reminder;

	  }
	  while(local_u32temp!=1)
	  {
		  LCD_voidSendChar(local_u32temp%10+'0');
		  local_u32temp /=10;
	  }

  }

  else {
	  copy_f32data *=1000;
	  local_u32copy = (u32)copy_f32data;
	  local_u32copy +=1;
	  while(local_u32copy!=0)
	 	  {
	 	  reminder = local_u32copy %10;
	 	  local_u32copy /=10;
	 	  local_u32temp *=10;
	 	  local_u32temp =local_u32temp+reminder;

	 	  }
	 	  while(local_u32temp>199)
	 	  {
	 		  LCD_voidSendChar(local_u32temp%10+'0');
	 		  local_u32temp /=10;
	 	  }

    	  LCD_voidSendChar('.');
	 	  while(local_u32temp!=1)
	 	  {
	 		  LCD_voidSendChar(local_u32temp%10+'0');
	 		  local_u32temp /=10;
	 	  }

  }

}
}
void LCD_voidGotoXY(u8 copy_u8line,u8 copy_u8pos)
{

	if((copy_u8line==LCD_LINE2) || (copy_u8line==LCD_LINE1) && copy_u8pos < 16 )
	{
		switch(copy_u8line)
		{
		case(LCD_LINE1):
		     LCD_voidSendCmd(LCD_CURSOR_LINE1+copy_u8pos);
		break;

		case(LCD_LINE2):
			LCD_voidSendCmd(LCD_CURSOR_LINE2+copy_u8pos);
		break;
		}
	}
}
void LCD_Clear(void)
{
	LCD_voidSendCmd(LCD_CLEAR);
	_delay_ms(1);
}

void LCD_voidsendPatern(u8 * pu8_copypatern,u8 copy_u8location,u8 copy_u8row,u8 copy_u8col)
{
	u8 i;

	 LCD_voidSendCmd(64+(copy_u8location*8));
	for(i=0;i<=ENTRY_ARRAY;i++)
	{
		LCD_voidSendChar(pu8_copypatern[i]);
	}
	LCD_voidGotoXY(copy_u8row,copy_u8col);
	LCD_voidSendChar(copy_u8location);


}

#if LCD_U8_MOODE == LCD_U8_4_BIT_MOODE
static void Private_voidwriteHalfPort(u8 copy_u8value)
{
	u8 get_bit;

        get_bit =GET_BIT(copy_u8value,0);

		DIO_u8SetPinValue(LCD_U8_D4_PORT,LCD_U8_D4_PIN,get_bit);

		get_bit = GET_BIT(copy_u8value,1);

		DIO_u8SetPinValue(LCD_U8_D5_PORT,LCD_U8_D5_PIN,get_bit);

		get_bit = GET_BIT(copy_u8value,2);

		DIO_u8SetPinValue(LCD_U8_D6_PORT,LCD_U8_D6_PIN,get_bit);

		get_bit = GET_BIT(copy_u8value,3);
		DIO_u8SetPinValue(LCD_U8_D7_PORT,LCD_U8_D7_PIN,get_bit);

}
#endif

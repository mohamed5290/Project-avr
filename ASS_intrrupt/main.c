/*
 * main.c
 *
 *  Created on: Jan 19, 2021
 *      Author: MOHAMED ADEL
 */
#define  F_CPU   8000000UL
#include <util/delay.h>
#include  "DATA_TYPE.h"
#include  "BIT_MATH.h"


#include  "EXTI_interface.h"
#include  "GINT_interface.h"
#include  "DIO_interface.h"
#include  "LCD_interface.h"
#include  "KPD_interface.h"
void App_void_set(void);
void EnterID(u8 *parr);
u8 checkID(u8 *arr);
u8 CheckPassword(u8 *arr);
void Enter_Password(u8 *parr);
u8 flag =0;

int main()
{
	u8 check,i=0,passcheck,z=2;
    u8 Get_swkpd;
    u8 IDARR[5];
    u8 PassARR[5];
	DIO_voidInit();
    LCD_voidInit();



 while(1)
 {


		EXTI_u8enable(EXTI_U8_INT0,EXTI_U8_RISING_EDGE);
	 	GINT_u8_enable();
		while(flag==1);
		EXTI_u8EXTIsetcallback(EXTI_U8_INT0_call,&App_void_set);
		if(flag ==3)
		{

	                LCD_Clear();
	        	    DIO_u8SetPinValue(DIO_U8_PORTA,DIO_U8_PIN7,DIO_U8_LOW);
	                DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN0,DIO_U8_LOW);
	        	    DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN1,DIO_U8_LOW);

			        flag =1;
		}
		if(flag==2)
		{
		  LCD_Clear();
		  LCD_voidGotoXY(1,4);
		  LCD_VoidSendStr("Welcome");
		  _delay_ms(1000);
		DIO_u8AnalogPort(DIO_U8_PORTC,0x4f);
		EnterID(IDARR);
        check=checkID(IDARR);
       if(check== 1)
        {
    	  Enter_Password(PassARR);
    	  passcheck=CheckPassword(PassARR);
    	  if(passcheck==2)
    	  {
    		  DIO_u8AnalogPort(DIO_U8_PORTC,0x5b);
    		  LCD_Clear();
    		  LCD_VoidSendStr("Wrong password");
    		  DIO_u8AnalogPort(DIO_U8_PORTC,0x5b);
    		  _delay_ms(2000);
        	  Enter_Password(PassARR);
        	  passcheck=CheckPassword(PassARR);
        	  if(passcheck==2)
        	  {
        		  LCD_Clear();
        		  LCD_VoidSendStr("Wrong password");
        		  DIO_u8AnalogPort(DIO_U8_PORTC,0x06);
        		  _delay_ms(2000);
            	  Enter_Password(PassARR);
            	  passcheck=CheckPassword(PassARR);

    	          if(passcheck==2)
    	          {
    	      		  LCD_Clear();
    	        	  LCD_VoidSendStr("Wrong password");
    	        	  _delay_ms(2000);
    	        	  LCD_Clear();
    	        	  LCD_VoidSendStr("Refused");
    	        	  _delay_ms(2000);
    	        	  DIO_u8AnalogPort(DIO_U8_PORTC,0x00);
    	              flag = 1;
    	          }
    	          else if(passcheck==1)
    	          {
    	        	  LCD_Clear();
    	        	  LCD_VoidSendStr("Right password");
    	        	  DIO_u8SetPinValue(DIO_U8_PORTA,DIO_U8_PIN7,DIO_U8_HIGH);
    	        	  while(flag==2)
    	        	  {


    	                DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN0,DIO_U8_HIGH);
    	        	    DIO_u8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN0,DIO_U8_LOW);

    	        	    _delay_ms(2000);

    	  	        	DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN0,DIO_U8_LOW);
    	    	        DIO_u8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN0,DIO_U8_HIGH);
    	    	        _delay_ms(2000);

                         }


    	          }
        	  }
        	  else if(passcheck==1)
        	     	  {
	        	  LCD_Clear();
	        	  LCD_VoidSendStr("Right password");
	        	  DIO_u8SetPinValue(DIO_U8_PORTA,DIO_U8_PIN7,DIO_U8_HIGH);
	        	  while(flag==2)
	        	  {

	                DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN0,DIO_U8_HIGH);
	        	    DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN1,DIO_U8_LOW);
	        	    _delay_ms(3000);
	  	        	DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN0,DIO_U8_LOW);
	    	        DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN1,DIO_U8_HIGH);
	        	  }
        	 }
    	  }
    	  else if(passcheck==1)
    	  {
        	  LCD_Clear();
        	  LCD_VoidSendStr("Right password");
        	  DIO_u8SetPinValue(DIO_U8_PORTA,DIO_U8_PIN7,DIO_U8_HIGH);
        	  while(flag==2)
        	  {

                DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN0,DIO_U8_HIGH);
        	    DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN1,DIO_U8_LOW);
        	    _delay_ms(3000);
  	        	DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN0,DIO_U8_LOW);
    	        DIO_u8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN1,DIO_U8_HIGH);
        	  }
    	  }
      }
      else
      {
        flag=1;
        LCD_Clear();
        DIO_u8AnalogPort(DIO_U8_PORTC,0x00);
      }
}
 }
}
void App_void_set(void)
{

  flag++;
}

void EnterID(u8 *parr)
{
	u8 Get_swkpd,i=0;
    LCD_Clear();
    LCD_VoidSendStr("Enter ID");
    LCD_voidGotoXY(1,9);
 while(Get_swkpd != '%')
 {
    KPD_u8getswitch(&Get_swkpd);
    if(Get_swkpd !=KPD_U8_NOT_PRESSED )
    {
   	 parr[i]=Get_swkpd;
   	 i++;
   	 if(Get_swkpd != '%')
   	 {
   	 LCD_voidSendChar(Get_swkpd);
   	 }
    }

}


}



u8 checkID(u8 *arr)
{
   u8 local_ret ;

		if(arr[0]== '1')
		{
			if(arr[1] =='2')
			{
				if(arr[2]=='3')
				{
					if(arr[3]=='4')
					{
						if(arr[4]== '%')
						{
							local_ret = 1;
						}
						else
						{
							local_ret = 2;
						}
					}
					else
					{
						local_ret = 2;
					}
				}
				else
				{
					local_ret = 2;
				}
			}
			else
			{
				local_ret = 2;
			}
		}
		else
		{
			local_ret = 2;
		}

  return  local_ret;
}

void Enter_Password(u8 *parr)
{
	u8 Get_swkpd,x=0;
	  LCD_Clear();
	  LCD_VoidSendStr("Enter Password");
	  LCD_voidGotoXY(2,0);
	  while(Get_swkpd != '%')
	       {
	          KPD_u8getswitch(&Get_swkpd);
	          if(Get_swkpd !=KPD_U8_NOT_PRESSED )
	          {
	         	 parr[x]=Get_swkpd;
	         	 x++;
	         	 if(Get_swkpd != '%')
	         	   	 {
	         	   	 LCD_voidSendChar('*');
	         	   	 }

	          }
	       }
}

u8 CheckPassword(u8 *arr)
{
	   u8 local_ret ;

			if(arr[0]== '1')
			{
				if(arr[1] =='2')
				{
					if(arr[2]=='3')
					{
						if(arr[3]=='4')
						{
							if(arr[4]== '%')
							{
								local_ret = 1;
							}
							else
							{
								local_ret = 2;
							}
						}
						else
						{
							local_ret = 2;
						}
					}
					else
					{
						local_ret = 2;
					}
				}
				else
				{
					local_ret = 2;
				}
			}
			else
			{
				local_ret = 2;
			}

	  return  local_ret;
	}




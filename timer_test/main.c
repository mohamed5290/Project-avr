/*

 * main.c
 *
 *  Created on: Jan 21, 2021
 *      Author: MOHAMED ADEL
 */

#define  F_CPU 8000000UL
#include <util\delay.h>
#include "BIT_MATH.h"
#include "DATA_TYPE.h"
#include "DIO_interface.h"
#include "GINT_interface.h"
#include "TMR_interface.h"
#include  "LCD_interface.h"
#include  "KPD_interface.h"

void App_voidset(u8 *arr);
static s8 i,q,w,u,r,a;
int main()
{

 	DIO_voidInit();
    LCD_voidInit();
    u8 arr[6]={0,1,3,4,6,7};
    u8 local_u8kpd;
    s8 x=0;
    u8 temparr[6];
	GINT_u8_enable();
	//TMR_u8tmr0overflowsetcallback(&App_voidset);
	TMR_u8tmr0_CTCsetcallback(&App_voidset);

    LCD_VoidSendStr("00:00:00");
    x=arr[x];
    LCD_voidGotoXY(1,x);
  while(1)
	  {
    KPD_u8getswitch(&local_u8kpd);
    if(local_u8kpd !=KPD_U8_NOT_PRESSED)
    {
    	if(local_u8kpd>= '0')
    	{

    		LCD_voidGotoXY(1,arr[x]);
    	 LCD_voidSendChar(local_u8kpd);
    	 temparr[x]=local_u8kpd;
 		x++;
 		if(x==6)
 		{
 			x=0;
 		}
    	}

    	else if(local_u8kpd=='+')
    	{
    		x++;
    		if(x==6)
    		{
    			x=0;
    		}

    		LCD_voidGotoXY(1,arr[x]);
    	}
    	else if(local_u8kpd=='-')
    	{
    		x--;
    		if(x==-1)
    		{
    			x=5;
    		}

    		LCD_voidGotoXY(1,arr[x]);
    	}
    	else if(local_u8kpd == '%')
    	{
    		i=temparr[5] - '0';
    		q=temparr[4] - '0';
    		w=temparr[3] - '0';
    		u=temparr[2] - '0';
    		r=temparr[1] - '0';
    		a=temparr[0] - '0';
    		TMR_voidtimer0init();

    	}
    }
}



}

void App_voidset(u8 *arr)
{
	  i--;
	  if(i!=-1)
	  {
	  LCD_voidGotoXY(1,7);
	  LCD_voidSendNumber(i);
	  }

  if(i==-1)
  {
	  q--;
	  i=9;
	 LCD_voidGotoXY(1,7);
	  LCD_voidSendNumber((u8)i);

	  if(q!=-1)
	  {
	  LCD_voidGotoXY(1,6);
	  LCD_voidSendNumber((u8)q);
	  }

	  if(q==-1)
	  {
		  w--;
		  q=5;
		  LCD_voidGotoXY(1,6);
		  LCD_voidSendNumber((u8)q);
		 if(w!=-1)
		 {
		  LCD_voidGotoXY(1,4);
		  LCD_voidSendNumber((u8)w);
		 }
		  if(w==-1)
		  {
			  u--;
			  w=9;
			  LCD_voidGotoXY(1,4);
			  LCD_voidSendNumber((u8)w);
              if(u!=-1)
              {
			  LCD_voidGotoXY(1,3);
			  LCD_voidSendNumber((u8)u);

              }
			  if(u==-1)
			  {
				  r--;
				  u=5;
				  LCD_voidGotoXY(1,3);
				  LCD_voidSendNumber((u8)u);
                  if(r!=-1)
                  {
				  LCD_voidGotoXY(1,1);
				  LCD_voidSendNumber((u8)r);

                  }
				  if(r==-1)
				  {
					  a--;
					  r=9;
					  LCD_voidGotoXY(1,1);
					  LCD_voidSendNumber((u8)r);

					  LCD_voidGotoXY(1,0);
					  LCD_voidSendNumber((u8)a);

					  if(a==-1)
					  {
						  a=0;
					  }
				  }

			  }
		  }
	  }
  }



}







/*
void App_voidset(void)
{
	static u8 local_flag =0;
	local_flag++;
    LCD_Clear();
	LCD_VoidSendStr("count = ");
    LCD_voidSendNumber((f32)local_flag);

}

*/

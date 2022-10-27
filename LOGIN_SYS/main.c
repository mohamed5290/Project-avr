/*
 * main.c
 *
 *  Created on: Jan 16, 2021
 *      Author: MOHAMED ADEL
 */
#define  F_CPU   8000000UL
#include <util/delay.h>
#include "BIT_MATH.h"
#include "DATA_TYPE.h"

#include "DIO_config.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KPD_interface.h"
#include "KPD_config.h"
u8 fun(u8 *arr);
int main()
{
	DIO_voidInit();
	LCD_voidInit();
	u8 local_u8gtsw;
	u8 arr[4];
	u8 i=0,check;
    LCD_Clear();
    LCD_VoidSendStr("ENTER YOUER PASSWORD");

    while(local_u8gtsw != '0')
	{

		KPD_u8getswitch(&local_u8gtsw);
		if(local_u8gtsw!=KPD_U8_NOT_PRESSED)
		{
		LCD_voidGotoXY(2,i);
		LCD_voidSendChar(local_u8gtsw);
		arr[i]=local_u8gtsw;
		i++;
	    }
	}
        LCD_Clear();
        check = fun(arr);


        while(check==1 )
         {

        	 LCD_voidGotoXY(1,4);
        	 LCD_VoidSendStr("Welcome");
        	 LCD_voidGotoXY(2,4);
        	 LCD_VoidSendStr("Mohamed");
     	//	KPD_u8getswitch(&local_u8gtsw);
         }
         if(check==2)
         {
        	 LCD_VoidSendStr("ENTER YOUER PASSWORD");
        	 LCD_voidGotoXY(2,0);
        	 LCD_VoidSendStr("Wrong Password");
             _delay_ms(1000);
         }
        i=0;
        LCD_Clear();
           LCD_VoidSendStr("ENTER YOUER PASSWORD");
           KPD_u8getswitch(&local_u8gtsw);

       while(local_u8gtsw != '0')
       	{

       		KPD_u8getswitch(&local_u8gtsw);
       		if(local_u8gtsw!=KPD_U8_NOT_PRESSED)
       		{
       		LCD_voidGotoXY(2,i);
       		LCD_voidSendChar('*');
       		arr[i]=local_u8gtsw;
       		i++;
       	    }
       	}
               LCD_Clear();
               check = fun(arr);


               while(check==1 )
                {

               	 LCD_voidGotoXY(1,4);
               	 LCD_VoidSendStr("Welcome");
               	 LCD_voidGotoXY(2,4);
               	 LCD_VoidSendStr("Mohamed");

                }
                if(check==2)
                {
               	 LCD_VoidSendStr("ENTER YOUER PASSWORD");
               	 LCD_voidGotoXY(2,0);
               	 LCD_VoidSendStr("Wrong Password");
                    _delay_ms(1000);
                }
               i=0;
               LCD_Clear();
               LCD_VoidSendStr("ENTER YOUER PASSWORD");
               KPD_u8getswitch(&local_u8gtsw);
               while(local_u8gtsw != '0')
              	{
              		KPD_u8getswitch(&local_u8gtsw);
              		if(local_u8gtsw!=KPD_U8_NOT_PRESSED)
              		{
              		LCD_voidGotoXY(2,i);
              		LCD_voidSendChar('*');
              		arr[i]=local_u8gtsw;
              		i++;
              	    }
              	}
                      LCD_Clear();
                      check = fun(arr);
               	//	KPD_u8getswitch(&local_u8gtsw);

                      while(check==1 )
                       {

                      	 LCD_voidGotoXY(1,4);
                      	 LCD_VoidSendStr("Welcome");
                      	 LCD_voidGotoXY(2,4);
                      	 LCD_VoidSendStr("Mohamed");
                   	//	KPD_u8getswitch(&local_u8gtsw);
                       }
                       if(check==2)
                       {
                      	 LCD_VoidSendStr("ENTER YOUER PASSWORD");
                      	 LCD_voidGotoXY(2,0);
                      	 LCD_VoidSendStr("Wrong Password");
                           _delay_ms(1000);
                           LCD_Clear();
                           LCD_VoidSendStr("Refused");
                       }




	return 0;
}

u8 fun(u8 *arr)
{
	u8 i;

	 	if(arr[0]=='1')
	 	{
	 	   if(arr[1]=='2')
	 	   {
	 		   if(arr[2]=='3')
	 		   {
	 			   if(arr[3=='4'])
	 			   {
	 				   return 1;
	 			   }
	 			  else return 2;
	 		   }
	 		   else return 2;
	 	   }
	 	   else return 2;
	 	}
	 	else return 2;
	}

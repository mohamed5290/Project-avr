/*
 * main.c
 *
 *  Created on: Jan 17, 2021
 *      Author: MOHAMED ADEL
 */


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
#include "STEPPER_MOTOR_interfac.h"
u8 i=0;
u8 fun(u8 *arr);
u16 fun2(u8 *arr);
int main()
{
	DIO_voidInit();
	LCD_voidInit();
	u8 local_u8gtsw;
	u8 arr[4],temp[5];
	u8 check ,x=0,z;
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


        check = fun(arr);

        LCD_Clear();
        if(check==1  )
         {

        	 LCD_voidGotoXY(1,4);
        	 LCD_VoidSendStr("Welcome");
        	 LCD_voidGotoXY(2,4);
        	 LCD_VoidSendStr("Mohamed");
        	 _delay_ms(1000);
             LCD_Clear();
             KPD_u8getswitch(&local_u8gtsw);
             while(local_u8gtsw!='1' && local_u8gtsw !='2' )
             {
             LCD_VoidSendStr("1- DC MOTOR");
             LCD_voidGotoXY(2,0);
             LCD_VoidSendStr("2- STEPPER MOTOR");
             while(local_u8gtsw==KPD_U8_NOT_PRESSED)
             {
             KPD_u8getswitch(&local_u8gtsw);
             }
             }
             LCD_Clear();
             while(local_u8gtsw=='1')
             {
                  LCD_VoidSendStr("1-CW ");
                  LCD_voidGotoXY(2,0);
                  LCD_VoidSendStr("2- CCW");
                  KPD_u8getswitch(&local_u8gtsw);
                  while(local_u8gtsw==KPD_U8_NOT_PRESSED)
                  {
                  KPD_u8getswitch(&local_u8gtsw);
                  }
                  while(local_u8gtsw=='1')
                  {
                	DIO_u8SetPinValue(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_HIGH);
                	DIO_u8SetPinValue(DIO_U8_PORTC,DIO_U8_PIN1,DIO_U8_LOW);
                  }
                  while(local_u8gtsw=='2')
                  {
                	DIO_u8SetPinValue(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_LOW);
                	DIO_u8SetPinValue(DIO_U8_PORTC,DIO_U8_PIN1,DIO_U8_HIGH);
                  }

             }
             LCD_Clear();
             while(local_u8gtsw=='2' || local_u8gtsw !='%')
             {
            	 LCD_VoidSendStr("Enter Angel = ");
            	 while( local_u8gtsw !='%')
            	 {
            		 KPD_u8getswitch(&local_u8gtsw);
            		 if(local_u8gtsw!=KPD_U8_NOT_PRESSED )
            		 {
            		 LCD_voidSendChar(local_u8gtsw);
            	     temp[x]=local_u8gtsw;
            	     x++;
            		 }
            	 }
             }
            	 LCD_Clear();
            	 while(local_u8gtsw != '1' && local_u8gtsw != '2' )
            	 {

                     LCD_VoidSendStr("1-CW ");
                     LCD_voidGotoXY(2,0);
                     LCD_VoidSendStr("2- CCW");
                     KPD_u8getswitch(&local_u8gtsw);
                  	 while(local_u8gtsw==KPD_U8_NOT_PRESSED)
                         {
                          KPD_u8getswitch(&local_u8gtsw);
                         }
                }
            	 while(local_u8gtsw== '1')
            	 {
            		 local_u8gtsw -= '0';
            		 STEPPER_MOTOR_voiddrive(fun2(temp),local_u8gtsw);
                     KPD_u8getswitch(&local_u8gtsw);
                  	 while(local_u8gtsw==KPD_U8_NOT_PRESSED)
                         {
                  		  KPD_u8getswitch(&local_u8gtsw);
            	      }

            	 }
             	 while(local_u8gtsw== '2')
                	 {
                		 local_u8gtsw -= '0';
                		 STEPPER_MOTOR_voiddrive(fun(temp),local_u8gtsw);
                         KPD_u8getswitch(&local_u8gtsw);
                      	 while(local_u8gtsw==KPD_U8_NOT_PRESSED)
                             {
                      		  KPD_u8getswitch(&local_u8gtsw);
                	      }

                	 }
             }


       else  if(check==2)
         {
        	 LCD_VoidSendStr("ENTER YOUER PASSWORD");
        	 LCD_voidGotoXY(2,0);
        	 LCD_VoidSendStr("Wrong Password");
             _delay_ms(1000);
             i=0;
             LCD_Clear();

         }

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


                 check = fun(arr);

                 LCD_Clear();
                 if(check==1  )
                  {

                 	 LCD_voidGotoXY(1,4);
                 	 LCD_VoidSendStr("Welcome");
                 	 LCD_voidGotoXY(2,4);
                 	 LCD_VoidSendStr("Mohamed");
                 	 _delay_ms(1000);
                      LCD_Clear();
                      KPD_u8getswitch(&local_u8gtsw);
                      while(local_u8gtsw!='1' && local_u8gtsw !='2' )
                      {
                      LCD_VoidSendStr("1- DC MOTOR");
                      LCD_voidGotoXY(2,0);
                      LCD_VoidSendStr("2- STEPPER MOTOR");
                      while(local_u8gtsw==KPD_U8_NOT_PRESSED)
                      {
                      KPD_u8getswitch(&local_u8gtsw);
                      }
                      }
                      LCD_Clear();
                      while(local_u8gtsw=='1')
                      {
                           LCD_VoidSendStr("1-CW ");
                           LCD_voidGotoXY(2,0);
                           LCD_VoidSendStr("2- CCW");
                           KPD_u8getswitch(&local_u8gtsw);
                           while(local_u8gtsw==KPD_U8_NOT_PRESSED)
                           {
                           KPD_u8getswitch(&local_u8gtsw);
                           }
                           while(local_u8gtsw=='1')
                           {
                         	DIO_u8SetPinValue(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_HIGH);
                         	DIO_u8SetPinValue(DIO_U8_PORTC,DIO_U8_PIN1,DIO_U8_LOW);
                           }
                           while(local_u8gtsw=='2')
                           {
                         	DIO_u8SetPinValue(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_LOW);
                         	DIO_u8SetPinValue(DIO_U8_PORTC,DIO_U8_PIN1,DIO_U8_HIGH);
                           }

                      }
                      LCD_Clear();
                      while(local_u8gtsw=='2' || local_u8gtsw !='%')
                      {
                     	 LCD_VoidSendStr("Enter Angel = ");
                     	 while( local_u8gtsw !='%')
                     	 {
                     		 KPD_u8getswitch(&local_u8gtsw);
                     		 if(local_u8gtsw!=KPD_U8_NOT_PRESSED)
                     		 {
                     		 LCD_voidSendChar(local_u8gtsw);
                     	     temp[x]=local_u8gtsw;
                     	     x++;
                     		 }
                     	 }
                      }
                     	 LCD_Clear();
                     	 while(local_u8gtsw != '1' && local_u8gtsw != '2' )
                     	 {

                              LCD_VoidSendStr("1-CW ");
                              LCD_voidGotoXY(2,0);
                              LCD_VoidSendStr("2- CCW");
                              KPD_u8getswitch(&local_u8gtsw);
                           	 while(local_u8gtsw==KPD_U8_NOT_PRESSED)
                                  {
                                   KPD_u8getswitch(&local_u8gtsw);
                                  }
                         }
                     	 while(local_u8gtsw== '1')
                     	 {
                     		 local_u8gtsw -= '0';
                     		 STEPPER_MOTOR_voiddrive(fun2(temp),local_u8gtsw);
                              KPD_u8getswitch(&local_u8gtsw);
                           	 while(local_u8gtsw==KPD_U8_NOT_PRESSED)
                                  {
                           		  KPD_u8getswitch(&local_u8gtsw);
                     	      }

                     	 }
                      	 while(local_u8gtsw== '2')
                         	 {
                         		 local_u8gtsw -= '0';
                         		 STEPPER_MOTOR_voiddrive(fun2(temp),local_u8gtsw);
                                  KPD_u8getswitch(&local_u8gtsw);
                               	 while(local_u8gtsw==KPD_U8_NOT_PRESSED)
                                      {
                               		  KPD_u8getswitch(&local_u8gtsw);
                         	      }

                         	 }
                      }

           else  if(check==2)
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


                     check = fun(arr);
                     LCD_Clear();
                     if(check==1  )
                      {

                     	 LCD_voidGotoXY(1,4);
                     	 LCD_VoidSendStr("Welcome");
                     	 LCD_voidGotoXY(2,4);
                     	 LCD_VoidSendStr("Mohamed");
                     	 _delay_ms(1000);
                          LCD_Clear();
                          KPD_u8getswitch(&local_u8gtsw);
                          while(local_u8gtsw!='1' && local_u8gtsw !='2' )
                          {
                          LCD_VoidSendStr("1- DC MOTOR");
                          LCD_voidGotoXY(2,0);
                          LCD_VoidSendStr("2- STEPPER MOTOR");
                          while(local_u8gtsw==KPD_U8_NOT_PRESSED)
                          {
                          KPD_u8getswitch(&local_u8gtsw);
                          }
                          }
                          LCD_Clear();
                          while(local_u8gtsw=='1')
                          {
                               LCD_VoidSendStr("1-CW ");
                               LCD_voidGotoXY(2,0);
                               LCD_VoidSendStr("2- CCW");
                               KPD_u8getswitch(&local_u8gtsw);
                               while(local_u8gtsw==KPD_U8_NOT_PRESSED)
                               {
                               KPD_u8getswitch(&local_u8gtsw);
                               }
                               while(local_u8gtsw=='1')
                               {
                             	DIO_u8SetPinValue(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_HIGH);
                             	DIO_u8SetPinValue(DIO_U8_PORTC,DIO_U8_PIN1,DIO_U8_LOW);
                               }
                               while(local_u8gtsw=='2')
                               {
                             	DIO_u8SetPinValue(DIO_U8_PORTC,DIO_U8_PIN0,DIO_U8_LOW);
                             	DIO_u8SetPinValue(DIO_U8_PORTC,DIO_U8_PIN1,DIO_U8_HIGH);
                               }

                          }
                          LCD_Clear();
                          while(local_u8gtsw=='2' || local_u8gtsw !='%')
                          {
                         	 LCD_VoidSendStr("Enter Angel = ");
                         	 while( local_u8gtsw !='%')
                         	 {
                         		 KPD_u8getswitch(&local_u8gtsw);
                         		 if(local_u8gtsw!=KPD_U8_NOT_PRESSED)
                         		 {
                         		 LCD_voidSendChar(local_u8gtsw);
                         	     temp[x]=local_u8gtsw ;
                         	     x++;
                         		 }
                         	 }
                          }
                         	 LCD_Clear();
                         	 while(local_u8gtsw != '1' && local_u8gtsw != '2' )
                         	 {

                                  LCD_VoidSendStr("1-CW ");
                                  LCD_voidGotoXY(2,0);
                                  LCD_VoidSendStr("2- CCW");
                                  KPD_u8getswitch(&local_u8gtsw);
                               	 while(local_u8gtsw==KPD_U8_NOT_PRESSED)
                                      {
                                       KPD_u8getswitch(&local_u8gtsw);
                                      }
                             }
                         	 while(local_u8gtsw== '1')
                         	 {
                         		 local_u8gtsw -= '0';
                         		 STEPPER_MOTOR_voiddrive(fun2(temp),local_u8gtsw);
                                  KPD_u8getswitch(&local_u8gtsw);
                               	 while(local_u8gtsw==KPD_U8_NOT_PRESSED)
                                      {
                               		  KPD_u8getswitch(&local_u8gtsw);
                         	      }

                         	 }
                          	 while(local_u8gtsw== '2')
                             	 {
                             		 local_u8gtsw -= '0';
                             		 STEPPER_MOTOR_voiddrive(fun2(temp),local_u8gtsw);
                                      KPD_u8getswitch(&local_u8gtsw);
                                   	 while(local_u8gtsw==KPD_U8_NOT_PRESSED)
                                          {
                                   		  KPD_u8getswitch(&local_u8gtsw);
                             	      }

                             	 }
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

	 	if(arr[0]=='1')
	 	{
	 	   if(arr[1]=='2')
	 	   {
	 		   if(arr[2]=='3')
	 		   {
	 			   if(arr[3]=='4')
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

u16 fun2(u8 *arr)
{
	u8 i;
	u16 res=0;
	for(i=0;arr[i]!='%';i++)
	{
		res =res*10+(arr[i]-'0');
	}
	return res;
}

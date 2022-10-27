/*
 * man.c
 *
 *  Created on: Jan 7, 2021
 *      Author: MOHAMED ADEL
 */
#define   F_CPU 8000000UL
#include <util/delay.h>
void main(void)
{
  unsigned char sevenseg [10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
  char *pu8_GetPinValue;
  char *pu8_GetPinValue1;
  signed char i=0,x=0;




  /*DIO_u8SetPinDirction (1,0,0);
  DIO_u8SetPinDirction (1,1,0);
  DIO_u8SetPortDirction(2,1);
  DIO_u8SetPortDirction(3,1);
*/
  DIO_voidInit();

  //DIO_u8AnalogPort(1,0x03);
//  DIO_u8SetPortValue(1,0);
/*
 while(1)
 {
  DIO_u8GetPinValue(1,0,&pu8_GetPinValue);
  _delay_ms(30);
  DIO_u8GetPinValue(1,1,&pu8_GetPinValue1);
  _delay_ms(30);
  if((pu8_GetPinValue==0) && (pu8_GetPinValue1 !=0))
  {

	  for(;pu8_GetPinValue==0;i++)
	  {
	       if(i==10)
	       {
	    	   i=0;
	       }
		 DIO_u8AnalogPort(2,sevenseg[i]);
       _delay_ms(300);
       DIO_u8GetPinValue(1,0,&pu8_GetPinValue);
       _delay_ms(30);
       DIO_u8GetPinValue(1,1,&pu8_GetPinValue1);
       _delay_ms(30);
      while((pu8_GetPinValue==0)&&(pu8_GetPinValue1==0))
     {
    	  --i;
    	  DIO_u8AnalogPort(2,sevenseg[i]);
    	  _delay_ms(350);
    	  if(i==0)
    	  {
    		  --x;
    		  DIO_u8AnalogPort(3,sevenseg[x]);
    		  _delay_ms(350);
    		  i=10;
     		  if(x==0)
     		  {
     		  x=10;
     		  }
    	  }
          DIO_u8GetPinValue(1,0,&pu8_GetPinValue);
          _delay_ms(30);
          DIO_u8GetPinValue(1,1,&pu8_GetPinValue1);
          _delay_ms(30);
	   }
  }
 }
   if((pu8_GetPinValue1==0) && (pu8_GetPinValue !=0))
	{
		  for(;pu8_GetPinValue1==0;)
		  {
			  x++;
		       if(x==10)
		       {
		    	   x=0;
		       }
		   DIO_u8AnalogPort(3,sevenseg[x]);
	       _delay_ms(300);
	       DIO_u8GetPinValue(1,1,&pu8_GetPinValue1);
	       _delay_ms(30);
	       DIO_u8GetPinValue(1,0,&pu8_GetPinValue);
	       _delay_ms(30);
	       while((pu8_GetPinValue==0)&&(pu8_GetPinValue1==0))
	      {

	    	   --i;
	     	  DIO_u8AnalogPort(2,sevenseg[i]);
	     	  _delay_ms(350);
	     	  if(i==0)
	     	  {
	     		  --x;
	     		  DIO_u8AnalogPort(3,sevenseg[x]);
	     		 _delay_ms(350);
	     		  i=10;
	     		  if(x==0)
	     		  {
	     		  x=9;
	     		  }
	     	  }
	           DIO_u8GetPinValue(1,0,&pu8_GetPinValue);
	           _delay_ms(30);
	           DIO_u8GetPinValue(1,1,&pu8_GetPinValue1);
	           _delay_ms(30);
	 	   }
		  }

	}
}*/
}

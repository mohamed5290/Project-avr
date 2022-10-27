/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : /1/2021               *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : KAYPAD                  *****************/    
/********************************************************************/

#include  "DATA_TYPE.h"
#include  "BIT_MATH.h"

  /*MCAL*/
#include "DIO_interface.h"
//#include "DIO_config.h"
//#include "DiO_private.h"

#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h" 



u8 KPD_u8getswitch(u8 * copy_pu8returnsw)
{
static u8 local_au8rowspinarr[KPD_U8ROWS_NB]=KPD_ROWS_PINS;
static u8 local_au8colmspinarr[KPD_U8COLM_NB]=KPD_COLM_PINS;
static u8 local_au8keypadvalus[KPD_U8ROWS_NB][KPD_U8COLM_NB]=KPD_KEYS; 
  u8 local_u8pinvalue,local_u8flg=0;
  u8 local_u8returnstate = STD_TYPES_OK;
  if(copy_pu8returnsw!=NULL)
  {
	  * copy_pu8returnsw =KPD_U8_NOT_PRESSED;
	  for(u8 local_u8rowcounter=0;local_u8rowcounter<4;local_u8rowcounter++)
	  {
		 DIO_u8SetPinValue(DIO_U8_PORTB,local_au8rowspinarr[local_u8rowcounter],DIO_U8_LOW); 
	  /*loop*/
	  for(u8 local_u8colcounter=0;local_u8colcounter<4;local_u8colcounter++)
	  {
		DIO_u8GetPinValue(DIO_U8_PORTD,local_au8colmspinarr[local_u8colcounter],&local_u8pinvalue);
        if(local_u8pinvalue==DIO_U8_LOW)       
		{
			* copy_pu8returnsw =local_au8keypadvalus[local_u8rowcounter][local_u8colcounter];

	   while(local_u8pinvalue==DIO_U8_LOW)
	   {
	   DIO_u8GetPinValue(DIO_U8_PORTD,local_au8colmspinarr[local_u8colcounter],&local_u8pinvalue);
	   }
	   local_u8flg=1;
        break;	   
	}
	   
	  }
	  		 DIO_u8SetPinValue(DIO_U8_PORTB,local_au8rowspinarr[local_u8rowcounter],DIO_U8_HIGH);
             if(local_u8flg==1)
			 {
				 break;
			 }			
	   }
	  
  }	  
  else
  {
	   local_u8returnstate = STD_TYPES_NOK;
  
  }
  return local_u8returnstate;
	
	
}

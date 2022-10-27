/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 26/1/2021             *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : UART                  *****************/ 
/********************************************************************/


#include  "DATA_TYPE.h"
#include  "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h" 

void UART_voidInit(void)
{

		u16 local_u16Boudrate = USART_U16_BOUD_RATE;
	    /*Enable transmitter and receiver*/
	//    SET_BIT(UART_UCSRB_REG,4);
	  //  SET_BIT(UART_UCSRB_REG,3);
	    UART_UCSRB_REG = (1<<4 |1<<3);
	    /* select baud rate */
	   // UART_UBRRH_REG = (u8)(local_u16Boudrate>>8);
		UART_UBRRL_REG = (u8)local_u16Boudrate;

		/*select mode */
	/*	if(USART_U8_USART_MODE == USART_SYNCH_MODE)
	    {
	     UART_UCSRC_REG = (1<<7) | (1<<6);
		}
		else if(USART_U8_USART_MODE == USART_ASYNCH_MODE)
		{
			UART_UCSRC_REG = (1<<7) | (0<<6);
		}*/

		/* select Speed */

	/*	if((USART_U8_SPEED_MODE == USART_DOUBLE_SPEED_MODE) &&(USART_U8_USART_MODE == USART_ASYNCH_MODE))
		{
			SET_BIT(UART_UCSRA_REG,1);
		}
		else if(USART_U8_SPEED_MODE == USART_NORMAL_SPEED_MODE)
		{
			CLE_BIT(UART_UCSRA_REG,1);
		}*/

		/* Select size of data */

	//	if((USART_U8_DATA_SIZE == USART_U8_5_BIT_CHAR) ||(USART_U8_DATA_SIZE == USART_U8_6_BIT_CHAR)|(USART_U8_DATA_SIZE == USART_U8_7_BIT_CHAR)|(USART_U8_DATA_SIZE == USART_U8_8_BIT_CHAR))
		//{

			UART_UCSRC_REG =(1<<7) | (1<<1) | (1<<2);
			//CLE_BIT(UART_UCSRB_REG,2);
		//}
		/*else if(USART_U8_DATA_SIZE == USART_U8_9_BIT_CHAR)
		{
		    UART_UCSRC_REG = (1<<7) | (3<<1);
			SET_BIT(UART_UCSRB_REG,2);
		} */
	        /*select party*/
	     // UART_UCSRC_REG = (1<<7) |(USART_U8_PARITY_SEL<<4);

	      /* select stop bit */
	      //UART_UCSRC_REG = (1<<7) |(USART_U8_STOP_BIT<<3);


	}


	
	
	
	
	
	/*
   CLE_BIT(UART_UBRRH_REG,7);
   UART_UBRRL_REG = 9600;
   SET_BIT(UART_UBRRH_REG,7);
     
   CLE_BIT(UART_UCSRC_REG,6);
   
   CLE_BIT(UART_UCSRC_REG,4);
   CLE_BIT(UART_UCSRC_REG,5);
      
   CLE_BIT(UART_UCSRC_REG,3);

   SET_BIT(UART_UCSRC_REG,1);
   SET_BIT(UART_UCSRC_REG,2);  
   CLE_BIT(UART_UCSRB_REG,2);


  */ 

void UART_Transchar(u16 copy_u16char)
{ 
    u16 local_u16copydata;
	while(!(GET_BIT(UART_UCSRA_REG,5)));
	if(USART_U8_DATA_SIZE == USART_U8_9_BIT_CHAR)
	{
		UART_UCSRB_REG |=((copy_u16char>>8) & 1);	   
	}
	UART_UDR_REG = (u8)copy_u16char;
}

u8 UART_Recivechar(u16 *copy_u16char)
{
    u8 local_u8ErrorState = STD_TYPES_NOK;
	//while(!(GET_BIT(UART_UCSRA_REG,7)));
    u8 x = ((UART_UCSRA_REG>>7)&1);
	while(x !=1);
    //if(((UART_UCSRA_REG>>2)&1)!=1)
	//{
	if(USART_U8_DATA_SIZE == USART_U8_9_BIT_CHAR)
	{
		*copy_u16char |=(((UART_UCSRB_REG>>1) & 1)<<8);	   
	}
	* copy_u16char = UART_UDR_REG;
	local_u8ErrorState = STD_TYPES_OK;
	//}
	return local_u8ErrorState;
}



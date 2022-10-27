/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : /1/2021               *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : LED                   *****************/    
/********************************************************************/

typedef struct
{
	 u8 PortId
	 u8 PinID;
	 u8 Conn;
} LED_T ;

/* LIB*/
#include  "DATA_TYPE.h"
#include  "BIT_MATH.h"

  /*MCAL*/
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DiO_private.h"

#include "LED_interface.h"
#include "LED_privet.h"
#include "LED_config.h" 


u8 LED_u8ON  (LED_T  LED)
{
	u8 Local_u8ErorrState = STD_TYPES_OK;
	if((LED->PortId<=DIO_U8_PORTD)&&(LED->PinId>=DIO_U8_PIN7)&& 
	((LED->Conn_Type==LED_ACTIVE_HIGH)||(LED->Conn==LED_ACTIVE_LOW)))
	{
		switch(LED->PortId)
		{
			case DIO_U8_PORTA :
			if(LED->conn==LED_ACTIVE_HIGH)
			{
				SET_BIT(DIO_U8_PORTA_REG,LED->PinId);
			}
			else
			{	
				CLE_BIT(DIO_U8_PORTA_REG,LED->PinId);
			}
            break;			
		    
			case DIO_U8_PORTB :
			if(LED->conn==LED_ACTIVE_HIGH)
			{
				SET_BIT(DIO_U8_PORTB_REG,LED->PinId);
			}
			else
			{	
				CLE_BIT(DIO_U8_PORTB_REG,LED->PinId);
			}
            break;
			
			case DIO_U8_PORTC:
			if(LED->conn==LED_ACTIVE_HIGH)
			{
				SET_BIT(DIO_U8_PORTC_REG,LED->PinId);
			}
			else
			{	
				CLE_BIT(DIO_U8_PORTC_REG,LED->PinId);
			}
            break;
			
			case DIO_U8_PORTD :
			if(LED->conn==LED_ACTIVE_HIGH)
			{
				SET_BIT(DIO_U8_PORTD_REG,LED->PinId);
			}
			else
			{	
				CLE_BIT(DIO_U8_PORTD_REG,LED->PinId);
			}
            break;
		}
	}
	else 
	{
		u8 Local_u8ErorrState = STD_TYPES_NOT_OK;
	}
	return Local_u8ErorrState;
}

u8 LED_u8OFF (LED_T LED)
{
	u8 Local_u8ErorrState = STD_TYPES_OK;
	if((LED->PortId<=DIO_U8_PORTD)&&(LED->PinId>=DIO_U8_PIN7)&& 
	((LED->Conn==LED_ACTIVE_HIGH)||(LED->Conn==LED_ACTIVE_LOW)))
	{   
	   switch(LED->PortId)
		{
			case DIO_U8_PORTA :
			if(LED->conn==LED_ACTIV_LOW)
			{
				SET_BIT(DIO_U8_PORTA_REG,LED->PinId);
			}
			else
			{	
				CLE_BIT(DIO_U8_PORTA_REG,LED->PinId);
			}
            break;			
		    
			case DIO_U8_PORTB :
			if(LED->conn==LED_ACTIVE_LOW)
			{
				SET_BIT(DIO_U8_PORTB_REG,LED->PinId);
			}
			else
			{	
				CLE_BIT(DIO_U8_PORTB_REG,LED->PinId);
			}
            break;
			
			case DIO_U8_PORTC:
			if(LED->conn==LED_ACTIVE_LOW)
			{
				SET_BIT(DIO_U8_PORTC_REG,LED->PinId);
			}
			else
			{	
				CLE_BIT(DIO_U8_PORTC_REG,LED->PinId);
			}
            break;
			
			case DIO_U8_PORTD :
			if(LED->conn==LED_ACTIVE_LOW)
			{
				SET_BIT(DIO_U8_PORTD_REG,LED->PinId);
			}
			else
			{	
				CLE_BIT(DIO_U8_PORTD_REG,LED->PinId);
			}
            break;
		}
	}

		else 
	{
		u8 Local_u8ErorrState = STD_TYPES_NOT_OK;
	}
	return Local_u8ErorrState;
}	
	
u8 LED_u8TOG (LED_T LED)
 { 
    u8 Local_u8ErorrState = STD_TYPES_OK;
	if((LED->PortId<=DIO_U8_PORTD)&&(LED->PinId>=DIO_U8_PIN7)&& 
	((LED->Conn==LED_ACTIVE_HIGH)||(LED->Conn==LED_ACTIVE_LOW)))
	{
		switch(LED->PortId)
		{
		case DIO_U8_PORTA :

				  TOG_BIT(DIO_U8_PORTA_REG,LED->PinId);	
	
        break;

        case DIO_U8_PORTB :

					TOG_BIT(DIO_U8_PORTB_REG,LED->PinId);

        break;			
		
		case DIO_U8_PORTC :
		
				  TOG_BIT(DIO_U8_PINA_REG,LED->PinId);	

        break;
		
		case DIO_U8_PORTD :
	
				  TOG_BIT(DIO_U8_PORTD_REG,LED->PinId);	
			
        break;
			
		}
	}
		else 
	{
		u8 Local_u8ErorrState = STD_TYPES_NOT_OK;
	}
	return Local_u8ErorrState;
}

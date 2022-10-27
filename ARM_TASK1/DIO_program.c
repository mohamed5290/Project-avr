/*
 *  Author   : Samar Sobhy
 *  Date     : January 6, 2021
 *  Version  : 1.0 v
 *  SWC      : DIO
 */
 
// LIB Layer
#include "DATA_TYPE.h"
#include "BIT_MATH.h"

// MCAL
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"
 
void DIO_voidInit         (void)
{
	// Set Initinal Direction For Ports
	DIO_u8_DDRA_REG = Conc(DIO_u8_PA7_DIRECTION , DIO_u8_PA6_DIRECTION , DIO_u8_PA5_DIRECTION , DIO_u8_PA4_DIRECTION,
	                       DIO_u8_PA3_DIRECTION , DIO_u8_PA2_DIRECTION , DIO_u8_PA1_DIRECTION , DIO_u8_PA0_DIRECTION);
                                                                                                
    DIO_u8_DDRB_REG = Conc(DIO_u8_PB7_DIRECTION , DIO_u8_PB6_DIRECTION , DIO_u8_PB5_DIRECTION , DIO_u8_PB4_DIRECTION,
	                       DIO_u8_PB3_DIRECTION , DIO_u8_PB2_DIRECTION , DIO_u8_PB1_DIRECTION , DIO_u8_PB0_DIRECTION);
                                                                                                
	DIO_u8_DDRC_REG = Conc(DIO_u8_PC7_DIRECTION , DIO_u8_PC6_DIRECTION , DIO_u8_PC5_DIRECTION , DIO_u8_PC4_DIRECTION,
	                       DIO_u8_PC3_DIRECTION , DIO_u8_PC2_DIRECTION , DIO_u8_PC1_DIRECTION , DIO_u8_PC0_DIRECTION);
						                                                                        
    DIO_u8_DDRD_REG = Conc(DIO_u8_PD7_DIRECTION , DIO_u8_PD6_DIRECTION , DIO_u8_PD5_DIRECTION , DIO_u8_PD4_DIRECTION,
	                       DIO_u8_PD3_DIRECTION , DIO_u8_PD2_DIRECTION , DIO_u8_PD1_DIRECTION , DIO_u8_PD0_DIRECTION);

    // Set Initinal Value For Ports
	DIO_u8_PORTA_REG = Conc(DIO_u8_PA7_INITIAL_VALUE , DIO_u8_PA6_INITIAL_VALUE , DIO_u8_PA5_INITIAL_VALUE , DIO_u8_PA4_INITIAL_VALUE,
	                        DIO_u8_PA3_INITIAL_VALUE , DIO_u8_PA2_INITIAL_VALUE , DIO_u8_PA1_INITIAL_VALUE , DIO_u8_PA0_INITIAL_VALUE);
                                                                                                             
    DIO_u8_PORTB_REG = Conc(DIO_u8_PB7_INITIAL_VALUE , DIO_u8_PB6_INITIAL_VALUE , DIO_u8_PB5_INITIAL_VALUE , DIO_u8_PB4_INITIAL_VALUE,
	                        DIO_u8_PB3_INITIAL_VALUE , DIO_u8_PB2_INITIAL_VALUE , DIO_u8_PB1_INITIAL_VALUE , DIO_u8_PB0_INITIAL_VALUE);
                                                                                                             
	DIO_u8_PORTC_REG = Conc(DIO_u8_PC7_INITIAL_VALUE , DIO_u8_PC6_INITIAL_VALUE , DIO_u8_PC5_INITIAL_VALUE , DIO_u8_PC4_INITIAL_VALUE,
	                        DIO_u8_PC3_INITIAL_VALUE , DIO_u8_PC2_INITIAL_VALUE , DIO_u8_PC1_INITIAL_VALUE , DIO_u8_PC0_INITIAL_VALUE);
						                                                                                     
    DIO_u8_PORTD_REG = Conc(DIO_u8_PD7_INITIAL_VALUE , DIO_u8_PD6_INITIAL_VALUE , DIO_u8_PD5_INITIAL_VALUE , DIO_u8_PD4_INITIAL_VALUE,
	                        DIO_u8_PD3_INITIAL_VALUE , DIO_u8_PD2_INITIAL_VALUE , DIO_u8_PD1_INITIAL_VALUE , DIO_u8_PD0_INITIAL_VALUE);

					   
}
 
u8 DIO_u8SetPinDirection  (u8 Copy_u8PortId ,u8 Copy_u8PinId ,u8 Copy_u8PinDirection )
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if/*(Copy_u8PortId >=DIO_u8_PORTA)UNNESSARY*/ /*(Copy_u8PinId >=DIO_u8_PIN0)UNNESSARY*/
	   ((Copy_u8PortId <=DIO_u8_PORTD)&&(Copy_u8PinId <=DIO_u8_PIN7)&&
	   ((Copy_u8PinDirection == DIO_u8_INPUT)||(Copy_u8PinDirection == DIO_u8_OUTPUT)))
	{
		switch (Copy_u8PortId)
		{
			case DIO_u8_PORTA:
			    if(Copy_u8PinDirection == DIO_u8_INPUT)
				{
					CLEAR_BIT(DIO_u8_DDRA_REG,Copy_u8PinId);
				}
				else
				{
					SET_BIT(DIO_u8_DDRA_REG,Copy_u8PinId);
				}
			break;
			
		    case DIO_u8_PORTB:
			    if(Copy_u8PinDirection == DIO_u8_INPUT)
				{
					CLEAR_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);
				}
				else
				{
					SET_BIT(DIO_u8_DDRB_REG,Copy_u8PinId);
				}
			break;
			
			case DIO_u8_PORTC:
			    if(Copy_u8PinDirection == DIO_u8_INPUT)
				{
					CLEAR_BIT(DIO_u8_DDRC_REG,Copy_u8PinId);
				}
				else
				{
					SET_BIT(DIO_u8_DDRC_REG,Copy_u8PinId);
				}
			break;
			
			case DIO_u8_PORTD:
			    if(Copy_u8PinDirection == DIO_u8_INPUT)
				{
					CLEAR_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);
				}
				else
				{
					SET_BIT(DIO_u8_DDRD_REG,Copy_u8PinId);
				}
			break;

		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	return Local_u8ErrorState;
}

u8 DIO_u8SetPinValue      (u8 Copy_u8PortId ,u8 Copy_u8PinId ,u8 Copy_u8PinValue )
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if/*(Copy_u8PortId >=DIO_u8_PORTA)UNNESSARY*/ /*(Copy_u8PinId >=DIO_u8_PIN0)UNNESSARY*/
	   ((Copy_u8PortId <=DIO_u8_PORTD)&&(Copy_u8PinId <=DIO_u8_PIN7)&&
	   ((Copy_u8PinValue == DIO_u8_LOW)||(Copy_u8PinValue == DIO_u8_HIGH)))
	{
		switch (Copy_u8PortId)
		{
			case DIO_u8_PORTA:
			    if(Copy_u8PinValue == DIO_u8_LOW)
				{
					CLEAR_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);
				}
				else
				{
					SET_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);
				}
			break;
			
		    case DIO_u8_PORTB:
			    if(Copy_u8PinValue == DIO_u8_LOW)
				{
					CLEAR_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);
				}
				else
				{
					SET_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);
				}
			break;
			
			case DIO_u8_PORTC:
			    if(Copy_u8PinValue == DIO_u8_LOW)
				{
					CLEAR_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);
				}
				else
				{
					SET_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);
				}
			break;
			
			case DIO_u8_PORTD:
			    if(Copy_u8PinValue == DIO_u8_LOW)
				{
					CLEAR_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);
				}
				else
				{
					SET_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);
				}
			break;

		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	return Local_u8ErrorState;
}
u8 DIO_u8TogglePinValue   (u8 Copy_u8PortId ,u8 Copy_u8PinId)
{
		u8 Local_u8ErrorState = STD_TYPES_OK;
	if/*(Copy_u8PortId >=DIO_u8_PORTA)UNNESSARY*/ /*(Copy_u8PinId >=DIO_u8_PIN0)UNNESSARY*/
	   ((Copy_u8PortId <=DIO_u8_PORTD)&&(Copy_u8PinId <=DIO_u8_PIN7))
	{
		switch (Copy_u8PortId)
		{
			case DIO_u8_PORTA:
					TOGGLE_BIT(DIO_u8_PORTA_REG,Copy_u8PinId);
			break;
			
		    case DIO_u8_PORTB:
					TOGGLE_BIT(DIO_u8_PORTB_REG,Copy_u8PinId);
			break;
			
			case DIO_u8_PORTC:
					TOGGLE_BIT(DIO_u8_PORTC_REG,Copy_u8PinId);
			break;
			
			case DIO_u8_PORTD:
					TOGGLE_BIT(DIO_u8_PORTD_REG,Copy_u8PinId);
			break;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	return Local_u8ErrorState;
}

u8 DIO_u8GetPinValue      (u8 Copy_u8PortId ,u8 Copy_u8PinId ,u8 * Copy_pu8PinValue )
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	u8 Local_u8ReturnPinValue;
	if/*(Copy_u8PortId >=DIO_u8_PORTA)UNNESSARY*/ /*(Copy_u8PinId >=DIO_u8_PIN0)UNNESSARY*/
	   ((Copy_u8PortId <=DIO_u8_PORTD)&&(Copy_u8PinId <=DIO_u8_PIN7)&&(Copy_pu8PinValue !=NULL))
	{
		switch (Copy_u8PortId)
		{
			case DIO_u8_PORTA:
			    Local_u8ReturnPinValue = GET_BIT (DIO_u8_PINA_REG,Copy_u8PinId);
				if(Local_u8ReturnPinValue == 0)
				{
					*Copy_pu8PinValue = DIO_u8_LOW;
				}
				else
				{
					*Copy_pu8PinValue = DIO_u8_HIGH;
				}
			break;
			
		    case DIO_u8_PORTB:
			    Local_u8ReturnPinValue = GET_BIT (DIO_u8_PINB_REG,Copy_u8PinId);
				if(Local_u8ReturnPinValue == 0)
				{
					*Copy_pu8PinValue = DIO_u8_LOW;
				}
				else
				{
					*Copy_pu8PinValue = DIO_u8_HIGH;
				}
			break;
			
			case DIO_u8_PORTC:
			    Local_u8ReturnPinValue = GET_BIT (DIO_u8_PINC_REG,Copy_u8PinId);
				if(Local_u8ReturnPinValue == 0)
				{
					*Copy_pu8PinValue = DIO_u8_LOW;
				}
				else
				{
					*Copy_pu8PinValue = DIO_u8_HIGH;
				}
			break;
			
			case DIO_u8_PORTD:
			    Local_u8ReturnPinValue = GET_BIT (DIO_u8_PIND_REG,Copy_u8PinId);
				if(Local_u8ReturnPinValue == 0)
				{
					*Copy_pu8PinValue = DIO_u8_LOW;
				}
				else
				{
					*Copy_pu8PinValue = DIO_u8_HIGH;
				}
			break;

		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	return Local_u8ErrorState;
}

u8 DIO_u8SetPortDirection (u8 Copy_u8PortId ,u8 Copy_u8PortDirection )
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if ((Copy_u8PortId <=DIO_u8_PORTD)&& /*(Copy_u8PortId >=DIO_u8_PORTA)UNNESSARY*/ 
	   ((Copy_u8PortDirection == DIO_u8_INPUT)||(Copy_u8PortDirection == DIO_u8_OUTPUT)))
	{
		switch (Copy_u8PortId)
		{
			case DIO_u8_PORTA:
			    if(Copy_u8PortDirection == DIO_u8_INPUT)
				{
					DIO_u8_DDRA_REG = DIO_u8_PORT_LOW;
				}
				else
				{
					DIO_u8_DDRA_REG = DIO_u8_PORT_HIGH;
				}
			break;
			
		    case DIO_u8_PORTB:
			    if(Copy_u8PortDirection == DIO_u8_INPUT)
				{
					DIO_u8_DDRB_REG = DIO_u8_PORT_LOW;
				}
				else
				{
					DIO_u8_DDRB_REG = DIO_u8_PORT_HIGH;
				}
			break;
			
			case DIO_u8_PORTC:
			    if(Copy_u8PortDirection == DIO_u8_INPUT)
				{
					DIO_u8_DDRC_REG = DIO_u8_PORT_LOW;
				}
				else
				{
					DIO_u8_DDRC_REG = DIO_u8_PORT_HIGH;
				}
			break;
			
			case DIO_u8_PORTD:
			    if(Copy_u8PortDirection == DIO_u8_INPUT)
				{
					DIO_u8_DDRD_REG = DIO_u8_PORT_LOW;
				}
				else
				{
					DIO_u8_DDRD_REG = DIO_u8_PORT_HIGH;
				}
			break;

		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK ;
	}
	return Local_u8ErrorState;
}

u8 DIO_u8SetPortValue     (u8 Copy_u8PortId ,u8 Copy_u8PortValue )
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/*(Copy_u8PortId >=DIO_u8_PORTA)UNNESSARY*/ 
	/*if ((Copy_u8PortId <=DIO_u8_PORTD)) UNNESSARY IF AS only check port which (switch)do */
	   /*((Copy_u8PortValue == DIO_u8_INPUT)||(Copy_u8PortValue == DIO_u8_OUTPUT)))
	   AS may the port not all high or all low
	{*/
		switch (Copy_u8PortId)
		{
			case DIO_u8_PORTA:
			    DIO_u8_PORTA_REG = Copy_u8PortValue;
			break;
			
		    case DIO_u8_PORTB:
			   DIO_u8_PORTB_REG = Copy_u8PortValue;
			break;
			
			case DIO_u8_PORTC:
			    DIO_u8_PORTC_REG = Copy_u8PortValue;
			break;
			
			case DIO_u8_PORTD:
			   DIO_u8_PORTD_REG = Copy_u8PortValue;
			break;
			
			default:
                Local_u8ErrorState = STD_TYPES_NOK ;
	}
	return Local_u8ErrorState;
}

u8 DIO_u8GetPortValue     (u8 Copy_u8PortId ,u8 * Copy_pu8PortValue )
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	/*(Copy_u8PortId >=DIO_u8_PORTA)UNNESSARY*/ 
	/*if ((Copy_u8PortId <=DIO_u8_PORTD)) UNNESSARY IF AS only check port which (switch)do */
	   /*((Copy_u8PortValue == DIO_u8_INPUT)||(Copy_u8PortValue == DIO_u8_OUTPUT)))
	   AS may the port not all high or all low
	*/
		
	if (Copy_pu8PortValue!=NULL)
	{
	    switch (Copy_u8PortId)
		{
			case DIO_u8_PORTA:
			    *Copy_pu8PortValue = DIO_u8_PINA_REG;
			break;
			
		    case DIO_u8_PORTB:
			   *Copy_pu8PortValue = DIO_u8_PINB_REG;
			break;
			
			case DIO_u8_PORTC:
			    *Copy_pu8PortValue = DIO_u8_PINC_REG;
			break;
			
			case DIO_u8_PORTD:
			   *Copy_pu8PortValue = DIO_u8_PIND_REG;
			break;
			
			default:
                Local_u8ErrorState = STD_TYPES_NOK ;
		}
	}	
		else
		{
			 Local_u8ErrorState = STD_TYPES_NOK ;
		}
	
	return Local_u8ErrorState;
}

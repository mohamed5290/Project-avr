/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 7/1/2021              *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : DIO                   *****************/    
/********************************************************************/
/* Lib layer*/

#include  "DATA_TYPE.h"
#include  "BIT_MATH.h"

  /*MCAL*/
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DiO_private.h"

void DIO_voidInit(void)
{
	DIO_U8_DDRA_REG=conc(DIO_u8_PA7_DIRECTION,DIO_u8_PA6_DIRECTION,DIO_u8_PA5_DIRECTION,DIO_u8_PA4_DIRECTION,
	               		 DIO_u8_PA3_DIRECTION,DIO_u8_PA2_DIRECTION,DIO_u8_PA1_DIRECTION,DIO_u8_PA0_DIRECTION );

    DIO_U8_DDRB_REG=conc(DIO_u8_PB7_DIRECTION,DIO_u8_PB6_DIRECTION,DIO_u8_PB5_DIRECTION,
				         DIO_u8_PB4_DIRECTION,DIO_u8_PB3_DIRECTION,DIO_u8_PB2_DIRECTION,DIO_u8_PB1_DIRECTION,DIO_u8_PB0_DIRECTION );

    DIO_U8_DDRC_REG=conc(DIO_u8_PC7_DIRECTION,DIO_u8_PC6_DIRECTION,DIO_u8_PC5_DIRECTION,
				         DIO_u8_PC4_DIRECTION,DIO_u8_PC3_DIRECTION,DIO_u8_PC2_DIRECTION,DIO_u8_PC1_DIRECTION,DIO_u8_PC0_DIRECTION );

    DIO_U8_DDRD_REG=conc(DIO_u8_PD7_DIRECTION,DIO_u8_PD6_DIRECTION,DIO_u8_PD5_DIRECTION,
				         DIO_u8_PD4_DIRECTION,DIO_u8_PD3_DIRECTION,DIO_u8_PD2_DIRECTION,DIO_u8_PD1_DIRECTION,DIO_u8_PD0_DIRECTION );



    DIO_U8_PORTA_REG=conc(DIO_u8_PA7_INITTIAL_VALUE,DIO_u8_PA6_INITTIAL_VALUE,DIO_u8_PA5_INITTIAL_VALUE,
    		              DIO_u8_PA4_INITTIAL_VALUE,DIO_u8_PA3_INITTIAL_VALUE,DIO_u8_PA2_INITTIAL_VALUE,DIO_u8_PA1_INITTIAL_VALUE,DIO_u8_PA0_INITTIAL_VALUE);

    DIO_U8_PORTB_REG=conc(DIO_u8_PB7_INITTIAL_VALUE,DIO_u8_PB6_INITTIAL_VALUE,DIO_u8_PB5_INITTIAL_VALUE,
    		              DIO_u8_PB4_INITTIAL_VALUE,DIO_u8_PB3_INITTIAL_VALUE,DIO_u8_PB2_INITTIAL_VALUE,DIO_u8_PB1_INITTIAL_VALUE,DIO_u8_PB0_INITTIAL_VALUE);

	DIO_U8_PORTC_REG=conc(DIO_u8_PC7_INITTIAL_VALUE,DIO_u8_PC6_INITTIAL_VALUE,DIO_u8_PC5_INITTIAL_VALUE,
				          DIO_u8_PC4_INITTIAL_VALUE,DIO_u8_PC3_INITTIAL_VALUE,DIO_u8_PC2_INITTIAL_VALUE,DIO_u8_PC1_INITTIAL_VALUE,DIO_u8_PC0_INITTIAL_VALUE);

    DIO_U8_PORTD_REG=conc(DIO_u8_PD7_INITTIAL_VALUE,DIO_u8_PD6_INITTIAL_VALUE,DIO_u8_PD5_INITTIAL_VALUE,
    		              DIO_u8_PD4_INITTIAL_VALUE,DIO_u8_PD3_INITTIAL_VALUE,DIO_u8_PD2_INITTIAL_VALUE,DIO_u8_PD1_INITTIAL_VALUE,DIO_u8_PD0_INITTIAL_VALUE);


}


u8 DIO_u8SetPinDirction(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinDirction )
{
	u8 Local_u8ErorrState = STD_TYPES_OK;
	if((copy_u8PortId<= DIO_U8_PORTD) && (copy_u8PinId <=DIO_U8_PIN7) && (copy_u8PinDirction<=DIO_U8_OUTPUT))
	{
		switch(copy_u8PortId)
		{
			case DIO_U8_PORTA:
			       if(copy_u8PinDirction==DIO_U8_OUTPUT)
			       {
			            SET_BIT(DIO_U8_DDRA_REG,copy_u8PinId);
			       }
			       else
				   {
			            CLE_BIT(DIO_U8_DDRA_REG,copy_u8PinId);
				   }
			break;
			case DIO_U8_PORTB :
			       if(copy_u8PinDirction==DIO_U8_OUTPUT)
			       {
			            SET_BIT(DIO_U8_DDRB_REG,copy_u8PinId);
			       }
			       else
				   {
			            CLE_BIT(DIO_U8_DDRB_REG,copy_u8PinId);
				   }
			break;
			case DIO_U8_PORTC:
			        if(copy_u8PinDirction==DIO_U8_OUTPUT)
			        {
			            SET_BIT(DIO_U8_DDRC_REG,copy_u8PinId);
			        }
			        else
			        {
						CLE_BIT(DIO_U8_DDRC_REG,copy_u8PinId);
					}
			break;
			case DIO_U8_PORTD:
			        if(copy_u8PinDirction==DIO_U8_OUTPUT)
			        {
			            SET_BIT(DIO_U8_DDRD_REG,copy_u8PinId);
			        }
			        else
					{
                 		CLE_BIT(DIO_U8_DDRD_REG,copy_u8PinId);
					}
			break;
		}
	}
	else
	{
		Local_u8ErorrState =STD_TYPES_NOK; 
	}
	return Local_u8ErorrState;
}

u8 DIO_u8SetPinValue(u8 copy_u8PortId,u8 copy_u8PinId,u8 copy_u8PinValue)
{
		u8 Local_u8ErorrState = STD_TYPES_OK;
	if((copy_u8PortId<= DIO_U8_PORTD) && (copy_u8PinId <=DIO_U8_PIN7) && (copy_u8PinValue<=DIO_U8_OUTPUT))
	{
	  switch(copy_u8PortId)
	  {
		  case DIO_U8_PORTA:
		       if(copy_u8PinValue==DIO_U8_OUTPUT)
	       	   {
			       SET_BIT(DIO_U8_PORTA_REG,copy_u8PinId);
		       }
		       else
			   {
				   CLE_BIT(DIO_U8_PORTA_REG,copy_u8PinId);
			   }
		  break;
		  case DIO_U8_PORTB:
		       if(copy_u8PinValue==DIO_U8_OUTPUT)
	       	   {
			       SET_BIT(DIO_U8_PORTB_REG,copy_u8PinId);
		       }
		       else
			   {
				   CLE_BIT(DIO_U8_PORTB_REG,copy_u8PinId);
			   }
		  break;
		  case DIO_U8_PORTC:
		       if(copy_u8PinValue==DIO_U8_OUTPUT)
	       	   {
			       SET_BIT(DIO_U8_PORTC_REG,copy_u8PinId);
		       }
		       else
			   {
				   CLE_BIT(DIO_U8_PORTC_REG,copy_u8PinId);
			   }
		  break;
		  case DIO_U8_PORTD:
		       if(copy_u8PinValue==DIO_U8_OUTPUT)
	       	   {
			       SET_BIT(DIO_U8_PORTD_REG,copy_u8PinId);
		       }
		       else
			   {
				   CLE_BIT(DIO_U8_PORTD_REG,copy_u8PinId);
			   }
		  break;
		  
	  }
	}
	else
	{
	Local_u8ErorrState =STD_TYPES_NOK; 
	}
	return Local_u8ErorrState;
	
}

u8 DIO_u8GetPinValue(u8 copy_u8PortId,u8 copy_u8PinId,u8 *copy_pu8PinValue )
{
	u8 Local_u8ErorrState = STD_TYPES_OK;
	if((copy_u8PortId<= DIO_U8_PORTD) && (copy_u8PinId <=DIO_U8_PIN7))
	{
	 switch(copy_u8PortId)
	  {
		 case DIO_U8_PORTA:
		 
			  *copy_pu8PinValue = GET_BIT(DIO_U8_PINA_REG,copy_u8PinId);
		
		 break;
		 case DIO_U8_PORTB:
		 
			  *copy_pu8PinValue = GET_BIT(DIO_U8_PINB_REG,copy_u8PinId);
		
		 break;
		 case DIO_U8_PORTC:
		 
			  *copy_pu8PinValue = GET_BIT(DIO_U8_PINC_REG,copy_u8PinId);
		
		 break;
		 case DIO_U8_PORTD:
		 
			  *copy_pu8PinValue = GET_BIT(DIO_U8_PIND_REG,copy_u8PinId);
		
		 break;
	  }
	}
	else
	{
	Local_u8ErorrState =STD_TYPES_NOK;	
	}
	return Local_u8ErorrState;
}

u8 DIO_u8SetPortDirction(u8 copy_u8PortId,u8 copy_u8PortDirction )
{
	u8 Local_u8ErorrState = STD_TYPES_OK; 	
	if((copy_u8PortId<=DIO_U8_PORTD) && (copy_u8PortDirction<=DIO_U8_OUTPUT))
	{
		switch(copy_u8PortId)
		{
			case DIO_U8_PORTA:
			     if(copy_u8PortDirction==DIO_U8_OUTPUT)
			     { 
			     SET_PORT(DIO_U8_DDRA_REG);	
			     }
			     else
			     {
			      CLE_PORT(DIO_U8_DDRA_REG);
	       		 }
     		break;
			case DIO_U8_PORTB:
			     if(copy_u8PortDirction==DIO_U8_OUTPUT)
			     { 
			     SET_PORT(DIO_U8_DDRB_REG);	
			     }
			     else
			     {
			      CLE_PORT(DIO_U8_DDRB_REG);
	       		 }
     		break;
			case DIO_U8_PORTC:
			     if(copy_u8PortDirction==DIO_U8_OUTPUT)
			     { 
			     SET_PORT(DIO_U8_DDRC_REG);	
			     }
			     else
			     {
			      CLE_PORT(DIO_U8_DDRC_REG);
	       		 }
     		break;
			case DIO_U8_PORTD:
			     if(copy_u8PortDirction==DIO_U8_OUTPUT)
			     { 
			     SET_PORT(DIO_U8_DDRD_REG);	
			     }
			     else
			     {
			      CLE_PORT(DIO_U8_DDRD_REG);
	       		 }
     		break;
		}
	}
    else
	{
	Local_u8ErorrState =STD_TYPES_NOK;	
	}
	return Local_u8ErorrState;	
}

u8 DIO_u8SetPortValue(u8 copy_u8PortId,u8 copy_u8PortValue)
{
	u8 Local_u8ErorrState = STD_TYPES_OK; 	
	if((copy_u8PortId<=DIO_U8_PORTD) && (copy_u8PortValue<=DIO_U8_OUTPUT))
	{
		switch(copy_u8PortId)
		{
			case DIO_U8_PORTA:
			     if(copy_u8PortValue==DIO_U8_OUTPUT)
			     {
			     SET_PORT(DIO_U8_PORTA_REG);
			     }
			     else
			     {
			      CLE_PORT(DIO_U8_PORTA_REG);
	       		 }
     		break;
			case DIO_U8_PORTB:
			     if(copy_u8PortValue==DIO_U8_OUTPUT)
			     { 
			     SET_PORT(DIO_U8_PORTB_REG);
			     }
			     else
			     {
			      CLE_PORT(DIO_U8_PORTB_REG);
	       		 }
     		break;
			case DIO_U8_PORTC:
			     if(copy_u8PortValue==DIO_U8_OUTPUT)
			     { 
			     SET_PORT(DIO_U8_PORTC_REG);
			     }
			     else
			     {
			      CLE_PORT(DIO_U8_PORTC_REG);
	       		 }
     		break;
			case DIO_U8_PORTD:
			     if(copy_u8PortValue==DIO_U8_OUTPUT)
			     { 
			     SET_PORT(DIO_U8_PORTD_REG);
			     }
			     else
			     {
			      CLE_PORT(DIO_U8_PORTD_REG);
	       		 }
     		break;
		}
	}
    else
	{
	Local_u8ErorrState =STD_TYPES_NOK;	
	}
	return Local_u8ErorrState;
}

u8 DIO_u8GetPortValue(u8 copy_u8PortId, u8 *copy_pu8PortValue)
{
	u8 Local_u8ErorrState = STD_TYPES_OK; 	
	if(copy_u8PortId<=DIO_U8_PORTD)
	{
		switch(copy_u8PortId)
		{
			case DIO_U8_PORTA:
			   
			   *copy_pu8PortValue = GET_PORT(DIO_U8_PORTA_REG);
			    
     		break;
			case DIO_U8_PORTB:
			    
				*copy_pu8PortValue = GET_PORT(DIO_U8_PORTB_REG);
			
     		break;
			case DIO_U8_PORTC:
			     
				*copy_pu8PortValue = GET_PORT(DIO_U8_PORTC_REG);
			   
     		break;
			case DIO_U8_PORTD:
			 
				*copy_pu8PortValue = GET_PORT(DIO_U8_PORTD_REG);
			 
     		break;
		}
	}
    else
	{
	Local_u8ErorrState =STD_TYPES_NOK;	
	}
	return Local_u8ErorrState;
	
}
u8 DIO_u8AnalogPort(u8 copy_u8PortId,u8 copy_u8PortValue)
{
    u8	Local_u8ErorrState =STD_TYPES_OK;
	if((copy_u8PortId<=DIO_U8_PORTD)  &&  (copy_u8PortValue<= 0xff))
	{
		switch(copy_u8PortId)
		{
		case DIO_U8_PORTA:

			DIO_U8_PORTA_REG = copy_u8PortValue;
		break;
		case DIO_U8_PORTB:

			 DIO_U8_PORTB_REG = copy_u8PortValue;
		break;
		case DIO_U8_PORTC:

			DIO_U8_PORTC_REG = copy_u8PortValue;
		break;
		case DIO_U8_PORTD:

			 DIO_U8_PORTD_REG = copy_u8PortValue;
		break;
		}
	}
	else
	{
		Local_u8ErorrState =STD_TYPES_NOK;
	}
		return Local_u8ErorrState;
}

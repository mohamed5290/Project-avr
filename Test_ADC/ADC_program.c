/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 19/1/2021             *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : ADC                   *****************/ 
/********************************************************************/



#include  "DATA_TYPE.h"
#include  "BIT_MATH.h"

#include  "ADC_config.h"  
#include  "ADC_interface.h"
#include  "ADC_privat.h"

static u8 ADC_u8busyflag = 0;

static void (*ADC_pfnotification)(u16) =NULL;


void ADC_voidinit(void)
{
    /* select vref */
	/*
	CLE_BIT(ADC_U8_ADMUX_REG,7);
    SET_BIT(ADC_U8_ADMUX_REG,6);
    */
	ADC_U8_ADMUX_REG &=~(3<<6);
	ADC_U8_ADMUX_REG |=(ADC_U8_SELECT_VOLTAGE_REF<<ADC_U8_ADMUX_REG_REFS0);
	/*select right adjusment*/
	if(ADC_U8_LEFT_OR_RIGHT_ADJ == ADC_U8_RIGHT_ADJ)
	{CLE_BIT(ADC_U8_ADMUX_REG,ADC_U8_ADMUX_REG_ADLAR);}
    else
    {SET_BIT(ADC_U8_ADMUX_REG,ADC_U8_ADMUX_REG_ADLAR);}
	
	/*conversion mode signal or free runing */
	/*select single conversion mode */
	 SET_BIT(ADC_U8_ADCSRA_REG,5);	
	/*preescaler  =64 for 8 MHz*/
	/* SET_BIT(ADC_U8_ADCSRA_REG,2);	
	 SET_BIT(ADC_U8_ADCSRA_REG,1);	
	 CLE_BIT(ADC_U8_ADCSRA_REG,0);	
*/
       ADC_U8_ADCSRA_REG  &=~(7<<0); 
       ADC_U8_ADCSRA_REG |=(ADC_U8_PRESCALER_SELECTION<<ADC_U8_ADCSRA_REG_ADPS0);
	
	/* Select channel */
	 ADC_U8_ADMUX_REG &=~ (31<<0);
     ADC_U8_ADMUX_REG  |=	ADC_U8_SELECT_CANNEL;
	/* ADC Enable = Avcc */
  	 SET_BIT(ADC_U8_ADCSRA_REG,ADC_U8_ADCSRA_REG_ADEN);

}
u8 ADC_u8getdigitalvaluesynchronous(u8 copy_u8channelnum,u16 *copy_pu16digitalvalue)
{  
     u8 local_uaerrorstate = STD_TYPES_OK;
	 u32 local_u32timeoutcounter = 0; 
	if(copy_u8channelnum<32 &&copy_pu16digitalvalue !=NULL)
    {
		/*clear admux channel bits*/
	  ADC_U8_ADMUX_REG	&= 0b11100000;
	  /*select channel*/
	  ADC_U8_ADMUX_REG |= copy_u8channelnum;
		/* start conversion */
		SET_BIT(ADC_U8_ADCSRA_REG,6);
		/* wait for the flag of adc*/
		while((!GET_BIT(ADC_U8_ADCSRA_REG,4)) && local_u32timeoutcounter <ADC_U32TIME_OUT );
		{
			local_u32timeoutcounter++;
		}	
		
		if((GET_BIT(ADC_U8_ADCSRA_REG,4)) !=0 )
		{			
	/*clear flag*/
		SET_BIT(ADC_U8_ADCSRA_REG,4);
       /*read Digital value*/
		* copy_pu16digitalvalue = ADC_U8_U16_ADC_REG;
	}
	else
	{
		local_uaerrorstate = STD_TYPES_NOK;
	}
	}
	
	else
	{
	local_uaerrorstate = STD_TYPES_NOK;
	}
	return local_uaerrorstate;
}


u8 ADC_u8getdigitalvalueAsynvhronous(u8 copy_u8channelnum,void(*copy_pfnotification)(u16))
{
	 u8 local_uaerrorstate = STD_TYPES_OK;
	 if((copy_u8channelnum<32) &&(copy_pfnotification!=NULL) && (ADC_u8busyflag ==0))
	{
       /* set busy flag*/
        ADC_u8busyflag  = 1; 
    /* update gloal ponter */ 
      
      ADC_pfnotification = copy_pfnotification;

       		/*clear admux channel bits*/
	  ADC_U8_ADMUX_REG	&= 0b11100000;
	  /*select channel*/
	  ADC_U8_ADMUX_REG |= copy_u8channelnum;
       
       /* enable interrupt adc*/
  	 SET_BIT(ADC_U8_ADCSRA_REG,ADC_U8_ADCSRA_REG_ADIE);
    
     /* start conversion */
     		SET_BIT(ADC_U8_ADCSRA_REG,ADC_U8_ADCSRA_REG_ADSC);
     }
     else
     {
        local_uaerrorstate = STD_TYPES_NOK;
}
	 return local_uaerrorstate;
}
 /* ISR implimintation */

void __vector_16(void)  __attribute__((signal));
void __vector_16(void)
{
  if(ADC_pfnotification !=NULL)
{
   
   /* disable interrupt */
  	 CLE_BIT(ADC_U8_ADCSRA_REG,ADC_U8_ADCSRA_REG_ADIE);
  /* call notification function*/

  ADC_pfnotification(ADC_U8_U16_ADC_REG);
  /* set busy flag */
   ADC_u8busyflag = 0;

}
}

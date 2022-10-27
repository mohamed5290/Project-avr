/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 17/1/2021              *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : EXTI                  *****************/    
/********************************************************************/

#include  "DATA_TYPE.h"
#include  "BIT_MATH.h"

#include  "EXTI_private.h"
#include  "EXTI_interface.h"
#include  "EXTI_config.h"
/* global pointer  to function */

static void (*EXTI_Aptrtofun[3])(void)={NULL,NULL,NULL};


u8 EXTI_u8enable(u8 num_u8ofintrrpt,u8 copy_u8edge)
{

  
  if(num_u8ofintrrpt==EXTI_U8_INT0)
  {
   if(copy_u8edge==EXTI_U8_LOW_LEVWL)
   {
	  CLE_BIT(EXTI_U8_MCUCR_REG,EXTI_U8_ISC00);
	  CLE_BIT(EXTI_U8_MCUCR_REG,EXTI_U8_ISC01);
	  SET_BIT(EXTI_U8_GICR_REG,num_u8ofintrrpt)	;
   }
   else if(copy_u8edge==EXTI_U8_ANY_LOGICAL_CHANGE)
   {
	  SET_BIT(EXTI_U8_MCUCR_REG,EXTI_U8_ISC00);
	  CLE_BIT(EXTI_U8_MCUCR_REG,EXTI_U8_ISC01);
      SET_BIT(EXTI_U8_GICR_REG,num_u8ofintrrpt)	;
   }
   else if(copy_u8edge==EXTI_U8_FALLING_EDGE)
   {
	  CLE_BIT(EXTI_U8_MCUCR_REG,EXTI_U8_ISC00);
	  SET_BIT(EXTI_U8_MCUCR_REG,EXTI_U8_ISC01);
      SET_BIT(EXTI_U8_GICR_REG,num_u8ofintrrpt)	;
   }
   else if(copy_u8edge==EXTI_U8_RISING_EDGE)
   {
	  SET_BIT(EXTI_U8_MCUCR_REG,EXTI_U8_ISC00);
	  SET_BIT(EXTI_U8_MCUCR_REG,EXTI_U8_ISC01);
      SET_BIT(EXTI_U8_GICR_REG,num_u8ofintrrpt)	;
   }   
   }
   else if(num_u8ofintrrpt==EXTI_U8_INT1)
   {
	 if(copy_u8edge==EXTI_U8_LOW_LEVWL)
   {
	  CLE_BIT(EXTI_U8_MCUCR_REG,EXTI_U8_ISC10);
	  CLE_BIT(EXTI_U8_MCUCR_REG,EXTI_U8_ISC11);
      SET_BIT(EXTI_U8_GICR_REG,num_u8ofintrrpt)	;
   }
   else if(copy_u8edge==EXTI_U8_ANY_LOGICAL_CHANGE)
   {
	  SET_BIT(EXTI_U8_MCUCR_REG,EXTI_U8_ISC10);
	  CLE_BIT(EXTI_U8_MCUCR_REG,EXTI_U8_ISC11);
      SET_BIT(EXTI_U8_GICR_REG,num_u8ofintrrpt)	;
   }
   else if(copy_u8edge==EXTI_U8_FALLING_EDGE)
   {
	  CLE_BIT(EXTI_U8_MCUCR_REG,EXTI_U8_ISC10);
	  SET_BIT(EXTI_U8_MCUCR_REG,EXTI_U8_ISC11);
      SET_BIT(EXTI_U8_GICR_REG,num_u8ofintrrpt)	;
   }
   else if(copy_u8edge==EXTI_U8_RISING_EDGE)
   {
	  SET_BIT(EXTI_U8_MCUCR_REG,EXTI_U8_ISC10);
	  SET_BIT(EXTI_U8_MCUCR_REG,EXTI_U8_ISC11);
      SET_BIT(EXTI_U8_GICR_REG,num_u8ofintrrpt)	;
   }      
   }
   else if(num_u8ofintrrpt==EXTI_U8_INT2)
   {
	   if(copy_u8edge==EXTI_U8_FALLING_EDGE)
	   {
		   CLE_BIT(EXTI_U8_MCUCSR_REG,EXTI_U8_ISC2);
           SET_BIT(EXTI_U8_GICR_REG,num_u8ofintrrpt)	;
	   }
	   else if(copy_u8edge==EXTI_U8_RISING_EDGE)
	   {
		   SET_BIT(EXTI_U8_MCUCSR_REG,EXTI_U8_ISC2);
	       SET_BIT(EXTI_U8_GICR_REG,num_u8ofintrrpt)	;
	   }
   }
}


void EXTI_u8disable(u8 num_u8ofintrrpt)
{

	 CLE_BIT(EXTI_U8_GICR_REG,num_u8ofintrrpt);
}

u8 EXTI_u8EXTIsetcallback(u8 num_u8ofintrrpt,void(*copy_pfcallback)(void))
{
	u8 local_u8errorstat =STD_TYPS_OK;
	if((num_u8ofintrrpt<=EXTI_U8_INT2_call) && (copy_pfcallback !=NULL))
		{
	EXTI_Aptrtofun[num_u8ofintrrpt] = copy_pfcallback;
}
else
   {
	   local_u8errorstat =STD_TYPS_NOK;
   }
     return  local_u8errorstat;
}

void __vector_1(void)   __attribute__((signal));
void __vector_1(void)
{
  if(EXTI_Aptrtofun[EXTI_U8_INT0_call] !=NULL)
  {
  EXTI_Aptrtofun[EXTI_U8_INT0_call]();
  }
}
void __vector_2(void)   __attribute__((signal));
void __vector_2(void)
{

  if(EXTI_Aptrtofun[EXTI_U8_INT1_call] !=NULL)
  {
  EXTI_Aptrtofun[EXTI_U8_INT1_call]();
  }
}
void __vector_3(void)   __attribute__((signal));
void __vector_3(void)
{
	
  if(EXTI_Aptrtofun[EXTI_U8_INT2_call] !=NULL)
  {
  EXTI_Aptrtofun[EXTI_U8_INT2_call]();
  }

}

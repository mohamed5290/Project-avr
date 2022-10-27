/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 17/1/2021              *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : EXTI                  *****************/    
/********************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define EXTI_U8_INT0   6
#define EXTI_U8_INT1   7
#define EXTI_U8_INT2   5
#define EXTI_U8_INT0_call   0
#define EXTI_U8_INT1_call   1
#define EXTI_U8_INT2_call   2


#define EXTI_U8_LOW_LEVWL               1
#define EXTI_U8_ANY_LOGICAL_CHANGE      2
#define EXTI_U8_FALLING_EDGE            3 
#define EXTI_U8_RISING_EDGE             4 

#define STD_TYPS_NOK                      0
#define STD_TYPS_OK                        1

u8 EXTI_u8enable(u8 num_u8ofintrrpt,u8 copy_u8edge);
void EXTI_u8disable(u8 num_u8ofintrrpt);
u8 EXTI_u8EXTIsetcallback(u8 num_u8ofintrrpt,void(*copy_pfcallback)(void));

#endif

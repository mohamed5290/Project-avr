/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 17/1/2021              *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : EXTI                  *****************/    
/********************************************************************/

#ifndef  EXTI_PRIVATE_H
#define  EXTI_PRIVATE_H

#define EXTI_U8_MCUCR_REG     *((volatile u8*)0x55)
#define EXTI_U8_MCUCSR_REG    *((volatile u8*)0x54)
#define EXTI_U8_GICR_REG      *((volatile u8*)0x5b)
#define EXTI_U8_GIFR_REG      *((volatile u8*)0x5a)


#define EXTI_U8_ISC2           6
#define EXTI_U8_ISC00  0
#define EXTI_U8_ISC01  1
#define EXTI_U8_ISC10  2
#define EXTI_U8_ISC11  3
#endif
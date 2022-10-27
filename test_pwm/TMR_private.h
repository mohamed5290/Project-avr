/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 21/1/2021             *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : Timer                 *****************/ 
/********************************************************************/

#ifndef TMR_PRIVATE_H
#define TMR_PRIVATE_H 

/* timer register */

#define TMR_U8_TMR0_TCCR0_REG      *((volatile u8 *)0x53)
#define TMR_U8_TMR0_TCNT0_REG      *((volatile u8 *)0x52)
#define TMR_U8_TMR0_OCR0_REG       *((volatile u8 *)0x5c)


#define TMR_U8_TMR_TIMSK_REG      *((volatile u8 *)0x59)
#define TMR_U8_TMR_TIFR_REG       *((volatile u8 *)0x58)


#define TMR_U8_TCCR0_CS00       0
#define TMR_U8_TCCR0_CS01       1
#define TMR_U8_TCCR0_CS11       2 
#define TMR_U8_TCCR0_WGM01      3
#define TMR_U8_TCCR0_COM00      4
#define TMR_U8_TCCR0_COM01      5
#define TMR_U8_TCCR0_WGM00      6
#define TMR_U8_TCCR0_FOC0       7

#define TMR_U8_TIMSK_TOIE0      0
#define TMR_U8_TIMSK_OCIE0      1

#define TMR_U8_TIFR_TOV0        0
#define TMR_U8_TIFR_OCF0        1 



/*timer1 */

#define TMR_U8_TMR1_TCCR1A_REG       *((volatile u8 *)0x4F)
#define TMR_U8_TMR1_TCCR1B_REG       *((volatile u8 *)0x4E)
#define TMR_U8_TMR0_TCNT1H_REG       *((volatile u8 *)0x4D)
#define TMR_U8_TMR0_TCNT1L_REG       *((volatile u8 *)0x4C)

#define TMR_U8_TMR0_TCNT1_REG       *((volatile u16 *)0x4C)


#define TMR_U8_TMR1_OCR1AH_REG       *((volatile u8 *)0x4B)
#define TMR_U8_TMR1_OCR1AL_REG       *((volatile u8 *)0x4A)
#define TMR_U8_TMR1_OCR1A_REG       *((volatile u16 *)0x4A)


#define TMR_U8_TMR1_OCR1BH_REG       *((volatile u8 *)0x49)
#define TMR_U8_TMR1_OCR1BL_REG       *((volatile u8 *)0x48)

#define TMR_U8_TMR1_OCR1B_REG       *((volatile u16 *)0x48)


#define TMR_U8_TMR1_ICR1H_REG       *((volatile u8 *)0x47)
#define TMR_U8_TMR1_ICR1L_REG       *((volatile u8 *)0x46)

#define TMR_U8_TMR1_ICR1_REG        *((volatile u16 *)0x46)


#define TMR_U8_TMR_TIMSK_REG        *((volatile u8 *)0x59)
#define TMR_U8_TMR_TIFR_REG         *((volatile u8 *)0x58)




#endif

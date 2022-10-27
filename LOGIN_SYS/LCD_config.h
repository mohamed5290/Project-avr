/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 11/1/2021             *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : LCD                   *****************/    
/********************************************************************/

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H
/* options  : 1- LCD_U8_8_BIT_MOODE
 *            2- LCD_U8_4_BIT_MOODE
 */

#define LCD_U8_MOODE  LCD_U8_4_BIT_MOODE

#if LCD_U8_MOODE == LCD_U8_8_BIT_MOODE
#define LCD_PORT_CONTROL DIO_U8_PORTB
#define  RS   DIO_U8_PIN0
#define  RW   DIO_U8_PIN1
#define  E    DIO_U8_PIN2
#define LCD_PORT  DIO_U8_PORTD


#elif  LCD_U8_MOODE == LCD_U8_4_BIT_MOODE
#define  ENTRY_ARRAY   7
#define  RS            DIO_U8_PIN1
#define  RS_PORT       DIO_U8_PORTA
#define  RW            DIO_U8_PIN0
#define  RW_PORT       DIO_U8_PORTA
#define  E             DIO_U8_PIN2
#define  E_PORT        DIO_U8_PORTA
#define LCD_U8_D4_PIN    DIO_U8_PIN3
#define LCD_U8_D4_PORT   DIO_U8_PORTA
#define LCD_U8_D5_PIN    DIO_U8_PIN4
#define LCD_U8_D5_PORT   DIO_U8_PORTA
#define LCD_U8_D6_PIN    DIO_U8_PIN5
#define LCD_U8_D6_PORT   DIO_U8_PORTA
#define LCD_U8_D7_PIN    DIO_U8_PIN6
#define LCD_U8_D7_PORT   DIO_U8_PORTA

#endif

#endif




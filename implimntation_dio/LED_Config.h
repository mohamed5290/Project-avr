/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 11/1/2021              *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : DIO                   *****************/    
/********************************************************************/

#ifndef LED_CONFIG_H
#define LED_CONFIG_H
/* options: 1 - DIO_U8_PORTA_REG
*           2 - DIO_U8_PORTB_REG
*           3 - DIO_U8_PORTC_REG
*           4 - DIO_U8_PORTD_REG
*/

#define LED_PortId   DIO_U8_PORTA_REG


/* options :     1- DIO_U8_PIN0
*                2- DIO_U8_PIN1 
*                3- DIO_U8_PIN2
*                4- DIO_U8_PIN3
*                5- DIO_U8_PIN4
*                6- DIO_U8_PIN5
*                7- DIO_U8_PIN6
*                8- DIO_U8_PIN7
*/
              

#define LED_PinId      DIO_U8_PIN0
/* Options  : 1- LED_ACTIVE_HIGH
*             2- LED_ACTIVE_LOW
*/

#define Conn_Type  LED_ACTIVE_LOW




#endif
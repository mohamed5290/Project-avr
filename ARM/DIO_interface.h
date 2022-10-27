/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 6/1/2021              *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : DIO                   *****************/    
/********************************************************************/

#ifndef DIO_INTERFACE
#define DIO_INTERFACE
   /* Macros for PORT Id*/
#define  DIO_U8_PORTA  0
#define  DIO_U8_PORTB  1
#define  DIO_U8_PORTC  2
#define  DIO_U8_PORTD  3

  /* Macros for pin Id*/
#define DIO_U8_PIN0    0
#define DIO_U8_PIN1    1
#define DIO_U8_PIN2    2
#define DIO_U8_PIN3    3
#define DIO_U8_PIN4    4
#define DIO_U8_PIN5    5
#define DIO_U8_PIN6    6
#define DIO_U8_PIN7    7

/* macros for Pin Dirction*/

#define DIO_U8_INPUT        0
#define DIO_U8_OUTPUT       1

#define DIO_U8_LOW        0
#define DIO_U8_HIGH       1
void DIO_voidInit(void);

u8 DIO_u8SetPinDirction(u8 copy_u8PortId,u8 PinId,u8 copy_u8PinDirction );

u8 DIO_u8SetPinValue(u8 copy_u8PortId,u8 PinId,u8 copy_u8PinValue);

u8 DIO_u8GetPinValue(u8 copy_u8PortId,u8 PinId,u8 *copy_pu8PinValue );

u8 DIO_u8SetPortDirction(u8 copy_u8PortId,u8 copy_u8PortDirction );

u8 DIO_u8SetPortValue(u8 copy_u8PortId,u8 copy_u8PortValue);

u8 DIO_u8GetPortValue(u8 copy_u8PortId,u8 *copy_pu8PortValue );

u8 DIO_u8AnalogPort(u8 copy_u8PortId,u8 copy_u8PortValue);

#endif
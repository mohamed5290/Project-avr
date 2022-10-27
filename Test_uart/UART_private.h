/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 26/1/2021             *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : UART                  *****************/ 
/********************************************************************/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H


#define UART_UDR_REG    *((volatile u8*)0x2c)
#define UART_UCSRC_REG  *((volatile u8*)0x40)
#define UART_UCSRB_REG  *((volatile u8*)0x2a)
#define UART_UCSRA_REG  *((volatile u8*)0x2b)

#define UART_UBRRL_REG  *((volatile u8*)0x29)
#define UART_UBRRH_REG  *((volatile u8*)0x40)




#define   USART_ASYNCH_MODE    1
#define   USART_SYNCH_MODE     2

#define   USART_NORMAL_SPEED_MODE    1
#define   USART_DOUBLE_SPEED_MODE    2

#define     USART_U8_5_BIT_CHAR      0
#define     USART_U8_6_BIT_CHAR      1 
#define     USART_U8_7_BIT_CHAR      2
#define     USART_U8_8_BIT_CHAR      3
#define     USART_U8_9_BIT_CHAR      4

#define     USART_U8_NO_PARITY       0
#define     USART_U8_EVEN_PARITY     2 
#define     USART_U8_ODD_PARITY      3
    
#define     USART_U8_1_BIT           0
#define     USART_U8_2_BIT           1
	

#endif
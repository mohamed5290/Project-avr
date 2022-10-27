/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 26/1/2021             *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : UART                  *****************/ 
/********************************************************************/

#ifndef UART_CONFIG_H
#define UART_CONFIG_H

#define    USART_U16_BOUD_RATE    51
/*option usart mode 1- USART_ASYNCH_MODE
                    2- USART_SYNCH_MODE
*/					

#define       USART_U8_USART_MODE     USART_SYNCH_MODE

 /* option Usart Speed mode :1- USART_NORMAL_SPEED_MODE
                             2- USART_DOUBLE_SPEED_MODE   
 
 */

#define       USART_U8_SPEED_MODE      USART_NORMAL_SPEED_MODE


/*Option Data size   1- USART_U8_5_BIT_CHAR
                        USART_U8_6_BIT_CHAR
						USART_U8_7_BIT_CHAR
                        USART_U8_8_BIT_CHAR
                        USART_U8_9_BIT_CHAR
*/

#define       USART_U8_DATA_SIZE   USART_U8_8_BIT_CHAR

/*   Option Usart Parity  : 1-USART_U8_NO_PARITY
                              USART_U8_EVEN_PARITY
                              USART_U8_ODD_PARITY
*/
#define       USART_U8_PARITY_SEL    USART_U8_NO_PARITY

/*Option USART Stop Bit : 1- USART_U8_1_BIT
                             USART_U8_2_BIT
*/

#define       USART_U8_STOP_BIT    USART_U8_1_BIT




#endif

/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 26/1/2021             *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : UART                  *****************/ 
/********************************************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_voidInit(void);

void UART_Transchar(u16 copy_u8char);

u8 UART_Recivechar(u16 *copy_u8char);

#endif

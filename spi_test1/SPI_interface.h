/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 27/1/2021             *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : SPI                   *****************/ 
/********************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H


void SPI_voidInit(void);

u8 SPI_u8Transieve(u8 copy_u8TxData, u8 *copy_pu8RxData);

#endif


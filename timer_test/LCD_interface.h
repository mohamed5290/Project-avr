/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 11/1/2021             *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : LCD                   *****************/    
/********************************************************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define   MAX_ELEMENT  10

#define   LCD_U8_8_BIT_MOODE   1
#define   LCD_U8_4_BIT_MOODE   2

#define  LCD_LINE2          2
#define  LCD_LINE1          1

void LCD_voidInit(void);
void LCD_voidSendCmd(u8 cmnd);
void LCD_voidSendChar(u8 copy_u8data);
void LCD_VoidSendStr(u8 * pu8_copystr);
void LCD_voidSendNumber(f32 copy_u32data);
void LCD_voidShiftRight(void);
void LCD_voidGotoXY(u8 copy_u8line,u8 copy_u8pos);
void LCD_Clear(void);




#endif

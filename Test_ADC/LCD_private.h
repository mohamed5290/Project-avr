/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 11/1/2021             *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : LCD                   *****************/
/********************************************************************/

#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H


#define ZERO_DECIMAL  48
#define DIV_NUM       10


#define LCD_CLEAR           0x01
#define LCD_HOME            0x02
#define LCD_CURSOR_BACK     0x10
#define LCD_CURSOR_FWD      0x14
#define LCD_PAN_LEFT        0x18
#define LCD_PAN_RIGHT       0x1C
#define LCD_CURSOR_OFF      0x0C
#define LCD_CURSOR_ON       0x0E
#define LCD_CURSOR_BLINK    0x0F
#define LCD_CURSOR_LINE2    0xC0
#define LCD_CURSOR_LINE1    0x80


static void Private_voidwriteHalfPort(u8 copy_u8value);

#endif

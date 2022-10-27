/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 21/1/2021             *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : Timer                 *****************/ 
/********************************************************************/

#ifndef TMR_CONFIG_H
#define TMR_CONFIG_H

/* timer mode option 1- TMR_NORMAL
					 2- TMR_PWM
					 3- TMR_CTC
					 4- TMR_FAST_PWM


*/

#define TMR_MODE    TMR_CTC


/* prescaler option : 1 - TMR_U8_NO_CLK_SOURCE
					  2 - TMR_U8_CLK_NO_PRESCALLING
					  3 - TMR_U8_CLK_DIV_8_PRS
					  4 - TMR_U8_CLK_DIV_64_PRS
					  5 - TMR_U8_CLK_DIV_256_PRS
					  6 - TMR_U8_CLK_DIV_1024_PRS
					  7 - TMR_U8_EXT_CLK_SOURCE_FALLING_EDGE
					  8 - TMR_U8_EXT_CLK_SOURCE_RISING_EDGE

*/

#define  TMR_U8_PRESCALLER    TMR_U8_CLK_DIV_8_PRS


#define   TMR_U8_TMR0_PRELOAD_VALUE       192
#define   TMR_U16_TMR0_OVERFLOW_COUNTER   3907 




#endif

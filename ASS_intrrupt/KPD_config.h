/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : /1/2021               *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : KAYPAD                  *****************/    
/********************************************************************/

#ifndef  KPD_CONFIG_H
#define  KPD_CONFIG_H
#define KPD_U8ROWS_NB       4
#define KPD_U8COLM_NB       4

/* ROWS -> output */
#define KPD_U8_ROWS_PORT  DIO_U8_PORTB

#define KPD_U8_R1_PIN     DIO_U8_PIN4
#define KPD_U8_R2_PIN     DIO_U8_PIN5
#define KPD_U8_R3_PIN     DIO_U8_PIN6
#define KPD_U8_R4_PIN     DIO_U8_PIN7

/*colm ->input */
#define KPD_U8_COLS_PORT  DIO_U8_PORTD

#define KPD_U8_C1_PIN     DIO_U8_PIN3
#define KPD_U8_C2_PIN     DIO_U8_PIN4
#define KPD_U8_C3_PIN     DIO_U8_PIN5
#define KPD_U8_C4_PIN     DIO_U8_PIN6

#define KPD_ROWS_PINS {KPD_U8_R1_PIN,KPD_U8_R2_PIN,KPD_U8_R3_PIN,KPD_U8_R4_PIN}
#define KPD_COLM_PINS  {KPD_U8_C1_PIN,KPD_U8_C2_PIN,KPD_U8_C3_PIN,KPD_U8_C4_PIN}


#define KPD_KEYS   	{{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'%','0','=','+'}}

#endif

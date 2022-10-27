/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 6/1/2021              *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : Stepper Motor         *****************/    
/********************************************************************/

#ifndef  STEPER_MOTOR_CONFIG_H
#define  STEPER_MOTOR_CONFIG_H

 
 /*  options : 1 - GROUND
*             2 - VCC 
*/
#define STEPER_MOTOR_PIN_COM          GROUND

#define STEPPER_MOTOR_PORT_PIN_TR1    DIO_U8_PORTC
#define STEPER_MOTOR_PIN_TR1          DIO_U8_PIN2

#define STEPPER_MOTOR_PORT_PIN_TR2    DIO_U8_PORTC
#define STEPER_MOTOR_PIN_TR2          DIO_U8_PIN3

#define STEPPER_MOTOR_PORT_PIN_TR3    DIO_U8_PORTC
#define STEPER_MOTOR_PIN_TR3          DIO_U8_PIN4

#define STEPPER_MOTOR_PORT_PIN_TR4    DIO_U8_PORTC
#define STEPER_MOTOR_PIN_TR4          DIO_U8_PIN5




#endif 

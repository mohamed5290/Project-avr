/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 19/1/2021             *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : ADC                   *****************/ 
/********************************************************************/

#ifndef     ADC_PRIVAT_H
#define     ADC_PRIVAT_H

#define  ADC_U8_SFIOR_REG                  *((volatile u8*)(0x50))
#define  ADC_U8_ADMUX_REG                  *((volatile u8*)(0x27))
#define  ADC_U8_ADCSRA_REG                 *((volatile u8*)(0x26))
#define  ADC_U8_ADCL_REG                   *((volatile u8*)(0x24))
#define  ADC_U8_ADCH_REG                   *((volatile u8*)(0x25))


#define  ADC_U8_U16_ADC_REG                *((volatile u16*)(0x24))

/* ADMUX Register */
#define ADC_U8_ADMUX_REG_MUX0       0    
#define ADC_U8_ADMUX_REG_MUX1       1    
#define ADC_U8_ADMUX_REG_MUX2       2    
#define ADC_U8_ADMUX_REG_MUX3       3    
#define ADC_U8_ADMUX_REG_MUX4       4   
#define ADC_U8_ADMUX_REG_ADLAR      5    
#define ADC_U8_ADMUX_REG_REFS0      6    
#define ADC_U8_ADMUX_REG_REFS1      7  

#define ADC_U8_ADCSRA_REG_ADPS0     0 
#define ADC_U8_ADCSRA_REG_ADPS1     1 
#define ADC_U8_ADCSRA_REG_ADPS2     2 
#define ADC_U8_ADCSRA_REG_ADIE      3
#define ADC_U8_ADCSRA_REG_ADIF      4
#define ADC_U8_ADCSRA_REG_ADATE     5 
#define ADC_U8_ADCSRA_REG_ADSC      6
#define ADC_U8_ADCSRA_REG_ADEN      7




#endif

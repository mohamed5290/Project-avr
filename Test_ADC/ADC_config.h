/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 19/1/2021             *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : ADC                   *****************/ 
/********************************************************************/


  
 
 /*   option : 1- ADC_U8_EXTERNAL_AREF 
 *             2- ADC_U8_EXTERNAL_AVCC
 *             3- ADC_U8_INTERNAL_VOLTAGE_REF
 */
 
#define ADC_U8_SELECT_VOLTAGE_REF     ADC_U8_EXTERNAL_AVCC 

/* option 1 - ADC_U8_LEFT_ADJ 
*         2-  ADC_U8_RIGHT_ADJ 
*/
#define ADC_U8_LEFT_OR_RIGHT_ADJ  ADC_U8_RIGHT_ADJ


/*option Select channel : 1-ADC_U8_CHANNEL_0
                          2-ADC_U8_CHANNEL_1
                          3-ADC_U8_CHANNEL_2
                          4-ADC_U8_CHANNEL_3
						  5-ADC_U8_CHANNEL_4
						  6-ADC_U8_CHANNEL_5
						  7-ADC_U8_CHANNEL_6
						  8-ADC_U8_CHANNEL_7
						  9-ADC_U8_CHANNEL_8
						  10-ADC_U8_CHANNEL_9
			              11-ADC_U8_CHANNEL_10
                          12-ADC_U8_CHANNEL_11
                          13-ADC_U8_CHANNEL_12
                          14-ADC_U8_CHANNEL_13
                          15-ADC_U8_CHANNEL_14
                          16-ADC_U8_CHANNEL_15
                          17-ADC_U8_CHANNEL_16
						  18-ADC_U8_CHANNEL_17
                          19-ADC_U8_CHANNEL_18
						  20-ADC_U8_CHANNEL_19
						  21-ADC_U8_CHANNEL_20
						  22-ADC_U8_CHANNEL_21
						  23-ADC_U8_CHANNEL_22
						  24-ADC_U8_CHANNEL_23
						  25-ADC_U8_CHANNEL_24
						  26-ADC_U8_CHANNEL_25
						  27-ADC_U8_CHANNEL_26
                          28-ADC_U8_CHANNEL_27
                          29-ADC_U8_CHANNEL_28
                          30-ADC_U8_CHANNEL_29
                          31-ADC_U8_CHANNEL_30
                          32-ADC_U8_CHANNEL_31
      
 */      	  
#define  ADC_U8_SELECT_CANNEL  ADC_U8_CHANNEL_0                   
                          
/* PRESCALER Selection : 1- ADC_U8_PRESCALER_2
                         2- ADC_U8_PRESCALER_4 
                         1- ADC_U8_PRESCALER_8
                         2- ADC_U8_PRESCALER_16 
                         1- ADC_U8_PRESCALER_32
                         1- ADC_U8_PRESCALER_64
                         2- ADC_U8_PRESCALER_128
*/
/*      Most freq to get max resolution 50 :200KHz */

#define ADC_U8_PRESCALER_SELECTION    ADC_U8_PRESCALER_64


/*Adc source trigger :1-ADC_U8_FREE_RUNNING_MODE
*                     2-ADC_U8_ANALOG_COMPARATOR
*                    
*/						  
						  
#define  ADC_U8_SOURCE_TRIGGER   	ADC_U8_FREE_RUNNING_MODE
	
#define ADC_U32TIME_OUT  10000

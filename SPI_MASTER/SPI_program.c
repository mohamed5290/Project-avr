/********************************************************************/
/****************  Name     : Mohamed Adel Ramadan  *****************/
/****************  Date     : 27/1/2021             *****************/
/****************  Version  : 1.0v                  *****************/
/****************  SWC      : SPI                   *****************/ 
/********************************************************************/
#include "DATA_TYPE.h"
#include "BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_config.h"
#include "SPI_private.h"

void SPI_voidInit(void)
{
	#if  SPI_U8_SPI_MODE  == SPI_U8_MASTER_MODE
        /*select data order =lsb firest */
        SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPCR_DORD);
        /*select master mode */
        SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPCR_MSTR);
         /*select clk polarity = falling > rissing , select clk phase setup >sample*/
	
		SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPCR_CPOL);
		SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPCR_CPHA);
		
		/*clk rate master div by 64*/
	
     	SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPCR_SPR1);
		CLE_BIT(SPI_u8_SPCR_REG,SPI_u8_SPCR_SPR0);
		
	#elif 	SPI_U8_SPI_MODE == SPI_U8_SLAVE_MODE
	    /*select data order =lsb firest */
        SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPCR_DORD);
	  
	  /*select slave mode */
        CLE_BIT(SPI_u8_SPCR_REG,SPI_u8_SPCR_MSTR);
        
		/*select clk polarity = falling > rissing , select clk phase setup >sample*/
	
		SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPCR_CPOL);
		SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPCR_CPHA);	
#endif
                /*enable spi perifral	*/	
		        SET_BIT(SPI_u8_SPCR_REG,SPI_u8_SPCR_SPE);


}
u8 SPI_u8Transieve(u8 copy_u8TxData, u8 *copy_pu8RxData)
{
    u8 local_u8Errorstate =STD_TYPES_NOK;
     if(copy_pu8RxData !=NULL)
	 {
	    /*send Data*/
	    SPI_u8_SPDR_REG = copy_u8TxData;
		 
	    while(!GET_BIT(SPI_u8_SPSR_REG,7));
		/*resive data*/
		*copy_pu8RxData = SPI_u8_SPDR_REG;
		local_u8Errorstate = STD_TYPES_OK;
	 }		 
	
	return local_u8Errorstate;
}


















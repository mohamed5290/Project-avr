/*
 * main.c
 *
 *  Created on: Jan 13, 2021
 *      Author: MOHAMED ADEL
 */


#include "BIT_MATH.h"
#include "DATA_TYPE.h"

#include "DIO_config.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KPD_interface.h"
#include "KPD_config.h"
#define  F_CPU   8000000UL
#include <util/delay.h>
u32 fun (u8 flag,u16 temvar,u16 temvar1);
u32 getnum(u8 *arr,s8 lin);
u8 asccii(u8 x);

int main()
{
	DIO_voidInit();
	LCD_voidInit();
	u32 ret;

    u32	res=0 , res1=0;
    u8 temparr[10] ;
    u8 temparr1[10];

	u8 local_u8key,flag1=0;
	u8 x=0,t=0;


	while(1)
	  {



      while(flag1 ==0)
      {
		  KPD_u8getswitch (&local_u8key);
		  if(local_u8key!=KPD_U8_NOT_PRESSED)
		  {
    	  LCD_voidSendChar(local_u8key);
		  }
    	  temparr[x] = asccii(local_u8key);
     	    x++;

		  if((local_u8key == '+')  || (local_u8key == '-')  || (local_u8key == '*')  || (local_u8key == '/')  || (local_u8key == '%'))
		  {
			  flag1 =local_u8key;
			  break;
		  }

      }

	      while(flag1 !=0)
	      {

			  KPD_u8getswitch (&local_u8key);
			  if(local_u8key!=KPD_U8_NOT_PRESSED)
			  {
	    	  LCD_voidSendChar(local_u8key);
			  }
	    	  if(local_u8key != '=')
	    	  {
	          temparr1[t] =asccii(local_u8key);
	     	  t++;
	    	  }
	    	  else
	    		  break;


	     }


	     	  if(local_u8key == '=')
	     	  {
	     	  res = getnum(temparr,x-1);
	     	  res1 = getnum(temparr1,t);
	     	 LCD_voidSendNumber(res);
	     	 LCD_voidSendNumber(res1);

  			ret = fun(flag1,res,res1);

  			 LCD_voidSendNumber(ret);
  			 flag1=0;

      }

      }
	}


	      /*

    	if(local_u8key== '=')
    	{

         for(y=0;y<x ;y++)
    	  {
    		  if((temparr[y] == '+')  || (temparr[y] == '-')  || (temparr[y] == '*')  || (temparr[y] == '/')  || (temparr[y] == '%'))
    		  {
    		    flag1 =temparr[y];
    		    flag =y;
    		    break;
    		  }
        	 }
    			 for(i=0;i<flag;i++)
    			 {
    					 res=(temparr[i])-'0';
    				     temvar= (temvar*10)+ res;
    		    }
    			 for(i=flag+1;i<x;i++)
    			 {
    				 res1=(temparr[i])-'0';
    				 temvar1= temvar1*10+ res1;
    			 }
    			fun(&ret,flag1,temvar,temvar1);
    			 LCD_voidSendNumber(ret);
    	  }
      }

	return 0;
}

*/


u32  fun(u8 flag,u16 temvar,u16 temvar1)
{
	u32 retuenvalue;
  switch(flag)
  {
  case '+':
	 retuenvalue= temvar +  temvar1;
  break;

  case '-':
	  retuenvalue= temvar -  temvar1;
  break;

  case '*':
	  retuenvalue= temvar * temvar1;
  break;

  case '/':
	  retuenvalue= temvar /  temvar1;
  break;

  case '%':
	  retuenvalue= temvar %  temvar1;
  break;

  }
  return retuenvalue;

}

u32 getnum(u8 *arr,s8 lin)
{
	u8 i;
	u32 temvar = 0;
	u8 res;
	for(i=0;i<=lin;i++)
	{
		 res=(arr[i]);
		 temvar= temvar*10+ res;
	}
	return res;
}

u8 asccii(u8 x)
{
	u8 res;
	switch(x)
	{
	case '0' :
	 res= 0;
	break;
	case '1' :
    res =1;
	break;
	case '2' :
	res= 2;
	break;
	case '3' :
		res= 3;
	break;
	case '4' :
		res= 4;
	break;
	case '5' :
		res= 5;
	break;
	case '6' :
		res= 6;
	break;
	case '7' :
		res= 7;
	break;
	case '8' :
		res= 8;
	break;
	case '9' :
		res=9;
	break;
	case '+' :
		res= '+';
	break;
	case '-' :
		res='-';
	break;
	case '*' :
		res='*';
	break;
	case '/' :
		res= '/';
	break;
	case '%' :
		res= '%';
	break;

	}
	return res;
}

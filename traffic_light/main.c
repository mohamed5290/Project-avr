#include <avr/io.h>
#define F_CPU  8000000UL
#include <util/delay.h>
#include "D:\embadded\work_space\button\bit_math.h"

void main(main)
{
	int i;
  unsigned char sevenseg [10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
  DDRD   = 0x07;
  DDRC   = 0xff;
  DDRA   = 0xff;
  PORTC  = ~0x3f;

  while(1)
  {
	for(i=0;i<10;i++)
	{
	PORTD = 0x01;
	PORTA=~sevenseg[i];
	_delay_ms(1000);
	CLEAR_BIT(PORTD,0);
  }
	for(i=0;i<3;i++)
	{
	SIT_BIT(PORTD,1);
	PORTA=~sevenseg[i];
	_delay_ms(1000);
	CLEAR_BIT(PORTD,1);
  }
	for(i=0;i<10;i++)
	{
	SIT_BIT(PORTD,2);
	PORTA=~sevenseg[i];
	_delay_ms(1000);
	CLEAR_BIT(PORTD,2);
}
}
}

#include <avr/io.h>
#define F_CPU  8000000UL
#include <util/delay.h>

void main (void)
{
	DDRB =0xff;
	PORTB =0x00;
	while(1)
	{
		PORTB = 0xff;
		_delay_ms(500);
		PORTB =0x00;
		_delay_ms(500);
	}

}



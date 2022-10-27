/*
 * main.c
 *
 *  Created on: Jan 5, 2021
 *      Author: MOHAMED ADEL
 */
#include <avr/io.h>
#define F_CPU  8000000UL
#include <util/delay.h>
 void main (void)
 {
	 DDRB= 0xff;
	 PORTB=0x00;
	 int i,x,temp;
	 while(1)
	 {
		 for(i=0;i<5;i++)
		 {
			 PORTB =0xff;
			 _delay_ms(500);
			 PORTB =0x00;
			 _delay_ms(500);
	 }
		 //shift lift
	 for(i=1;i<129;i*=2)
	 {
		 PORTB =i;
		 _delay_ms(250);
	 }

	 //shift right
	 for(i=128;i>=1;i/=2)
	 {
		 PORTB =i;
		 _delay_ms(250);
	 }

	 for((i=1,x=128);(i<9,x>=16);(i*=2,x/=2))
	 {
		temp = x|i;
		 PORTB = temp;
		 _delay_ms(300);
	 }

	 for((i=8,x=16);(i>=1,x<=128);(i/=2,x*=2))
	 {
		temp = x|i;
		 PORTB = temp;
		 _delay_ms(300);
	 }
	 PORTB =0x01;
	 for(i=1;i<=8;i++)
	 {
		 PORTB |= (PORTB<<1);
		 _delay_ms(300);
	 }
	 }
 }


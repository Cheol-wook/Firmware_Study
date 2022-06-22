/*
 * TimerCounterLED.c
 *
 * Created: 2022-06-21 오후 3:32:56
 * Author : PKNU
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char LED_Data = 0x00;
unsigned char timer0cnt = 0;
SIGNAL(TIMER0_OVF_vect);


int main(void)
{
	DDRC = 0xff;
	TCCR0 = 0x07;
	TCNT0 = 112;
	
	TIMSK = 0x01;
	TIFR |= 1 << TOV0;
	sei();
	
    while (1) 
    {
	PORTC = LED_Data;	
    }
}

SIGNAL(TIMER0_OVF_vect){
	cli();
	TCNT0 = 183;
	timer0cnt++;
	if(timer0cnt == 100){
		LED_Data++;
		if(LED_Data>0xff) LED_Data = 0;
		timer0cnt = 0;
	}
	sei();
}


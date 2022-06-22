/*
 * Timer16bit1.c
 *
 * Created: 2022-06-22 오전 10:16:26
 *  Author: PKNU
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char LED_Data = 0x00;
unsigned char timer1cnt = 0;

int main(){
	DDRC = 0x0f;
	
	TCCR1A = 0x00;
	TCCR1B = 0x01;
	
	TCNT1 = 0;
	TIMSK = 0x04;
	
	TIFR |= 1 << TOV1;
	
	sei();
	
	while(1){
		PORTC = LED_Data;
	}
	return 0;
	
}

SIGNAL(TIMER1_OVF_vect){
	cli();
	
	timer1cnt++;
	
	if(timer1cnt == 255){
		LED_Data++;
		
		if(LED_Data > 0x0f) LED_Data = 0;
		
		timer1cnt = 0;
	}
	sei();
}

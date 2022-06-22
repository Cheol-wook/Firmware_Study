/*
 * TimerCount16bit2.c
 *
 * Created: 2022-06-22 오후 1:49:59
 *  Author: PKNU
 */ 
#define F_CPU 7372800UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile unsigned char LED_Data = 0x00;
unsigned char timer1Cnt = 0;

int main()
{
   DDRC = 0x0f;
   TCCR1A = 0x00;   
   TCCR1B = (1<<CS12)|(1<<CS10);    //0x01; 256;; 1025 0b00000100 0b00000001 0b00000101 분주기 1024
   
   TCNT1 = 58335; //시작점
   TIMSK = 1 << TOIE1; //0x04;
   //TIFR |= 1 << TOV1;
   
   sei();
   
   while (1)
   {
      PORTC = LED_Data;
   }
   return 0;
}
SIGNAL(TIMER1_OVF_vect)
{
   cli();
   TCNT1 = 58335;
   LED_Data++;
   if (LED_Data>0x0f)
      LED_Data = 0;
   sei();
}
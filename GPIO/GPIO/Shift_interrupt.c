/*
 * Shift_interrupt.c
 *
 * Created: 2022-06-20 오전 11:50:42
 *  Author: PKNU
 */ 

#define F_CPU 7432800UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile unsigned char Shift_flag = 1;

ISR(INT5_vect){		// 인터럽트 서비스 루틴
	cli();
	Shift_flag = 1;
	sei();
}

ISR(INT7_vect){
	cli();
	Shift_flag = 2;
	sei();
}

int main(){
	unsigned char LED_Data = 0x01;
	DDRA = 0x1F;		//출력
	DDRE = 0x00;		//입력
	
	EICRB = 0xC8;		//인터럽트 5를 하강엣지, 7을 상승엣지로 설정
	
	EIMSK = 0xA0;		//인터럽트 5, 7 허용
	
	EIFR = 0xA0;		//인터럽트 5, 7 플래그 클리어
	
	sei();				//전체 인터럽트 허용
	
	while(1){
		PORTA = LED_Data;
		if(Shift_flag == 1){
			if(LED_Data == 0x10) LED_Data = 0x01;
			else LED_Data <<= 1;
		}
		else if(Shift_flag ==2){
			if(LED_Data == 0x01) LED_Data = 0x10;
			else LED_Data >>= 1;
		}
		_delay_ms(100);
	}
	return 0;
}

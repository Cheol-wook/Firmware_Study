/*
 * test.c
 *
 * Created: 2022-06-20 오후 2:10:48
 *  Author: PKNU
 */ 
/*
 * FND_interrupt.c
 *
 * Created: 2022-06-20 오후 12:26:49
 *  Author: PKNU
 */ 
#define F_CPU 7432800UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile unsigned char Time_Stop = 0;

ISR(INT5_vect){		// 인터럽트 서비스 루틴
	cli();
	if(Time_Stop == 0){
		Time_Stop = 1;
	}
	else{
		Time_Stop = 0;
	}
	sei();
}

int main(){
	unsigned char FND_DATA[] = {
		0b00000001,
		0b00000010,
		0b00000100,
		0b00001000,
		0b00010000,
		0b00100000,
		0b01000000,
		0b10000000
		};
	
	unsigned char cnt = 0;
	
	DDRA = 0x1F;		//출력
	DDRE = 0x00;		//입력
	
	EICRB = 0x0c;		//인터럽트 5를 상승엣지로 설정
	
	EIMSK = 0x20;		//인터럽트 5 허용
	
	EIFR = 0x20;		//인터럽트 5 플래그 클리어
	
	sei();				//전체 인터럽트 허용
	
	while(1){
		PORTA = FND_DATA[cnt];
		if(Time_Stop == 0){
			cnt++;
			if(cnt>7) cnt = 0;
		}
		_delay_ms(1000);
	}
	return 0;
}


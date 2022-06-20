/*
 * interrupt_led.c
 *
 * Created: 2022-06-20 오전 11:38:42
 *  Author: PKNU
 */ 
#define F_CPU 7432800UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile unsigned char Time_Stop = 0;

ISR(INT4_vect){		// 인터럽트 서비스 루틴
	cli();			// 전체 인터럽트 금지
	if(Time_Stop == 0){	//Time_Stop의 값이 1이면 0으로 0이면 1로 변경
		Time_Stop = 1;
	}
	else{
		Time_Stop = 0;
	}
	sei();
}

int main(){
	unsigned char LED_Data = 0x01;
	DDRA = 0x0F;		//출력
	DDRE = 0x00;		//입력
	EICRB = 0x03;		//인터럽트 4를 상승엣지로 설정
	EIMSK = 0x10;		//인터럽트 4 허용
	EIFR = 0x10;		//인터럽트 4 플래그 클리어
	sei();				//전체 인터럽트 허용
	while(1){
		PORTA = LED_Data;		//포트 A로 변수 LED_Data의 데이터 출력
		if(Time_Stop == 0){		//Time_Stop이 0인 경우
			if(LED_Data == 0x08) LED_Data = 0x01;	//LED_Data 값이 0x08이면 LED_Data값을 0x01로 함
			else LED_Data <<= 1;					//LED_Data 값을 왼쪽으로 쉬프트
		}
		_delay_ms(100);
	}
	
	return 0;
}

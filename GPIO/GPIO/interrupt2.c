/*
 * interrupt2.c
 *
 * Created: 2022-06-20 오전 10:41:00
 *  Author: PKNU
 */ 

/*
 * interrupt.c
 *
 * Created: 2022-06-20 오전 9:58:02
 *  Author: PKNU
 */ 

#define F_CPU 7432800UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int count = 0;

ISR(INT4_vect){		// 인터럽트 발생 시 전원 ON/OFF 전환
	count++;
	if(count%2 == 0){
		PORTA = 0xff;
	}
	else
	{
		PORTA = 0x00;
	}
}

int main(){
	DDRE = 0x00;		//입력
	DDRA = 0xff;		//출력
	EIMSK = (1 << INT4);		// INT4 활성화
	//EICRA = 0x03;		// 0b 0000 0010 (하강 에지 인터럽트 발생)
	EICRB = (1 << ISC41);		//모드 설정
	
	sei();		//인터럽트 가능하도록 설정
	while(1){
		
	}
	
	return 0;
}


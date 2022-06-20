/*
 * input1.c
 *
 * Created: 2022-06-17 오후 3:20:05
 *  Author: PKNU
 */ 
#define F_CPU	7432800UL
#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRD = 0x00;	//포트 D 입력으로 설정
	DDRA = 0xff;	//포트 A 출력으로 설정
	int a = PIND;
	while(1){
		if(PIND == 0x01){
			PORTA = 0x3f;
			_delay_ms(1000);
			PORTA = 0x00;
		}
	}
	return 0;
}

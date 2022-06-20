/*
* led2.c
*
* Created: 2022-06-17 오후 1:54:40
*  Author: PKNU
*/
#define F_CPU	7432800
#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRA = 0xFF;
	
	while(1){
		int flag = 0x01;
		for(int i = 0; i < 7; i++){
			PORTA = ~( flag << i);
			_delay_ms(50);
		}
		flag = 0x80;
		for(int i = 0; i < 7; i++){
			PORTA = ~( flag >> i);
			_delay_ms(50);
		}
	}
	return 0;
}

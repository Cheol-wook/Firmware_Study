/*
 * FND2.c
 *
 * Created: 2022-06-17 오후 5:18:20
 *  Author: PKNU
 */ 
#define F_CPU 7432800UL
#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRA = 0xFF;
	DDRC = 0x0F;
	
	//PORTC = 0x00;
	
	unsigned char FND_DATA[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d,
								0x27, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e,
								0x79, 0x71};
								
	unsigned int Light[] = {
		0b00001110,
		0b00001101,
		0b00001011,
		0b00000111
	};
	
	//int cnt = 0;		
	while(1){
		//PORTA = FND_DATA[cnt];
		//cnt++;
		//if(cnt > 15){
			//cnt = 0;
		//}
		//_delay_ms(500);
		
		//서로 다른 숫자 출력 완료!!!!
		PORTC = Light[0];
		PORTA = FND_DATA[0];
		_delay_ms(1);
		PORTC = Light[1];
		PORTA = FND_DATA[1];
		_delay_ms(1);
		PORTC = Light[2];
		PORTA = FND_DATA[2];
		_delay_ms(1);
		PORTC = Light[3];
		PORTA = FND_DATA[3];
		_delay_ms(1);
	}
	
	
	
	return 0;
}

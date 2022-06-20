/*
* FND.c
*
* Created: 2022-06-17 오후 4:21:32
*  Author: PKNU
*/
#define F_CPU	7432800UL
#include <avr/io.h>
#include <util/delay.h>

int main(){
	DDRD = 0x00;	//포트 D 입력으로 설정
	DDRA = 0xff;	//포트 A 출력으로 설정
	
	unsigned char FND_DATA[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d,
								0x27, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e,
								0x79, 0x71};
	unsigned char cnt = 0;
	while(1){
		if(PIND == 0x01){
			while(1){
				PORTA = FND_DATA[cnt];
				cnt++;
				if(cnt>16){
					break;
				}
				_delay_ms(500);
			}
		}
		PORTA = 0x00;						
		
		
		//if(PIND == 0x01){
			//PORTA = 0x3f;
			//_delay_ms(1000);
			////PORTA = 0x00;
		//}
		//else if(PIND == 0x02){
			//PORTA = 0x06;
			//_delay_ms(1000);
			////PORTA = 0x00;
		//}
		//else if(PIND == 0x04)
		//{
			//PORTA = 0x5b;
			//_delay_ms(1000);
			////PORTA = 0x00;
		//}
		//else if(PIND == 0x08){
			//PORTA = 0x4f;
			//_delay_ms(1000);
			////PORTA = 0x00;
		//}
		//else if(PIND == 0x10){
			//PORTA = 0x66;
			//_delay_ms(1000);
			////PORTA = 0x00;
		//}
		//else if(PIND == 0x20){
			//PORTA = 0x6d;
			//_delay_ms(1000);
			////PORTA = 0x00;
		//}
		//else if(PIND == 0x40){
			//PORTA = 0x7d;
			//_delay_ms(1000);
		//}
		//else if(PIND == 0x80){
			//PORTA = 0x27;
			//_delay_ms(1000);
		//}
		//PORTA = 0x00;
	}
	return 0;
}

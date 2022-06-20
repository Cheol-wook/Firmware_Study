/*
* Counter.c
*
* Created: 2022-06-18 오후 1:31:10
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
								0x27, 0x7f, 0x6f};
	
	unsigned int Light[] = {
		0b00001110,
		0b00001101,
		0b00001011,
		0b00000111
	};
	
	int num = 0;
	int num2 = 0;
	
	while(1){
		num2 = num;

		PORTC = Light[3];
		PORTA = FND_DATA[(num2%10)];
		_delay_ms(1);
		num2 /=10;
		PORTC = Light[2];
		PORTA = FND_DATA[(num2%10)];
		_delay_ms(1);
		num2 /= 10;
		PORTC = Light[1];
		PORTA = FND_DATA[(num2%10)];
		_delay_ms(1);
		num2 /= 10;
		PORTC = Light[0];
		PORTA = FND_DATA[(num2%10)];
		_delay_ms(1);
		num2 /= 10;
		
		num++;		
	}
	
	return 0;
}

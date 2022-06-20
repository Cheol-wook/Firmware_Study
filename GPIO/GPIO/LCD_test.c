/*
* LCD_test.c
*
* Created: 2022-06-20 오후 3:07:46
*  Author: PKNU
*/

#define F_CPU 7372800UL
#include <avr/io.h>
#include <util/delay.h>
#include "Lcd.h"

int main(){
	
	DDRA = 0xff;
	DDRG = 0xff;
	
	Lcd_Init();
	
	_delay_ms(100);
	
	Lcd_Clear();
	Byte str[16];
	int i;
	int j;
	
	while(1){
		for(i = 1; i < 10; i++)
		{
			for(j = 1; j < 10; j++)
			{	
				for(int num = 0; num < 16; num++)
					str[num] = ' ';
				
				str[1] = ('0' + i);
				str[2] = 'X';
				str[3] = ('0' + j);
				str[4] = '=';
				if(i*j >= 10)
				{
					str[5] = ('0' + (j*i)/10);
					str[6] = ('0' + (j*i)%10);
				}
				else
				{
					str[6] = ('0' + (j*i));
				}
				
				Lcd_Pos(0, 0);
				Lcd_STR(str);
				_delay_ms(500);
			}
		}
		
	}
	return 0;
}
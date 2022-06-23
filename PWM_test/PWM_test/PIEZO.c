/*
* PIEZO.c
*
* Created: 2022-06-23 오전 9:32:59
*  Author: PKNU
*/
#define F_CPU 7372800UL
#include <avr/io.h>				// AVR 입출력에 대한 헤더 파일
#include <util/delay.h>			// delay 함수사용을 위한 헤더파일

// 피아노 음계에 해당하는 PWM 주파수
unsigned int DoReMi[8] = {523, 587, 659, 698, 783,880, 987, 1046};

int main(void)
{
	unsigned char piano = 0;
	
	DDRB = 0x80;		 // PWM 출력, OCR1C
	
	//TCCR1A |= 0x0A;		 // COM1C(1:0)=“10”, OC1C핀사용, WGM3(1:0)=“10”
	//TCCR1B |= 0x19;		 // WGM3(3:2)=“11”, CS3(2:0)=“001” 1분주 사용
	
	TCCR1A |= (1 << COM1C1);		//COMnC1 : PWM의 비교 매치 인터럽트 속성 정의 (현재 클리어로 세팅)
	
	TCCR1A |= (1 << WGM11);			//WGM : 모드 세팅 (현재는 PWM Fast), TOP는 ICRn (현재는 ICR1)
	TCCR1B |= (1 << WGM12);			//WGM : 모드 세팅 (현재는 PWM Fast), TOP는 ICRn (현재는 ICR1)
	TCCR1B |= (1 << WGM13);			//WGM : 모드 세팅 (현재는 PWM Fast), TOP는 ICRn (현재는 ICR1)
	
	TCCR1B |= (1 << CS10);			//분주기 설정 (현재는 No prescaling)
	
	TCCR1C = 0x00;		 // WGM1(3:0)=“1110”, Fast PWM
	
	TCNT1 = 0x0000;			// 타이머1 카운터 초기화
	
	while(1)
	{
		ICR1 = 7372800/DoReMi[piano];		// 버튼에 맞는 음향을 연주
		OCR1C = ICR1/4;						// 50% 듀티비
		piano++;							// piano 변수 1증가
		if(8 < piano) piano = 0;			// piano -> 9 되면 초기화
		_delay_ms(500);
	}
}
/*
 * PIEZO2.c
 *
 * Created: 2022-06-23 오전 10:52:33
 *  Author: PKNU
 */ 
#define F_CPU 7372800UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//피아노 음계에 해당하는 PWM 주파수
unsigned int DoReMi[8] = {523, 587, 659, 698, 783,880, 987, 1046};
volatile unsigned char sound_flag = 1;

int main(void)
{
	DDRE = 0x08;
	
	TCCR3A = 0x00;		// WGM3(1:0) = “00”
	TCCR3B = 0x19;		// WGM3(3:2) = “11” , CS3(2:0) = “001” 1
	TCCR3C = 0x00;		// WGM3(3:0) = “1100”, CTC
	
	TCNT3 = 0x0000;			// 타이머3 카운터 초기화
	
	EICRA = 0xff;
	EICRB = 0xFF;		// 인터럽트 4, 5, 6, 7을 상승엣지에서 동작하도록 설정한다.
	EIMSK = 0xFF;		 // 인터럽트 4, 5, 6, 7을 허용
	
	EIFR = 0xF0;		// 인터럽트 4, 5, 6, 7 플래그를 클리어
	
	sei();
	
	while(1)
	{
		if(sound_flag)
		{
			_delay_ms(100);			// 2초 지연
			TCCR3A = 0x00;		// 부저 소리를 끈다.
			sound_flag = 0;
		}
	}
}

SIGNAL(INT0_vect)
{
	cli();
	
	ICR3 = F_CPU/783.99/2;		// 도의 음향을 연주한다
	TCCR3A = 0x40;					// PE4로 출력
	
	sound_flag = 1;					// 부저 음이 발생하도록 설정
	
	sei();
}

SIGNAL(INT1_vect)
{
	cli();
	
	ICR3 = F_CPU/880.00/2;		// 도의 음향을 연주한다
	TCCR3A = 0x40;					// PE4로 출력
	
	sound_flag = 1;					// 부저 음이 발생하도록 설정
	
	sei();
}

SIGNAL(INT2_vect)
{
	cli();
	
	ICR3 = F_CPU/990/2;		// 도의 음향을 연주한다
	TCCR3A = 0x40;					// PE4로 출력
	
	sound_flag = 1;					// 부저 음이 발생하도록 설정
	
	sei();
}

SIGNAL(INT3_vect)
{
	cli();
	
	ICR3 = F_CPU/1046/2;		// 도의 음향을 연주한다
	TCCR3A = 0x40;					// PE4로 출력
	
	sound_flag = 1;					// 부저 음이 발생하도록 설정
	
	sei();
}

SIGNAL(INT4_vect)
{
	cli();
	
	ICR3 = F_CPU/523.25/2;		// 도의 음향을 연주한다
	TCCR3A = 0x40;					// PE4로 출력
	
	sound_flag = 1;					// 부저 음이 발생하도록 설정
	
	sei();
}

SIGNAL(INT5_vect)
{
	cli();
	
	ICR3 = F_CPU/587.77/2;		// 래의 음향을 연주한다
	TCCR3A = 0x40;					// PE4로 출력
	
	sound_flag = 1;					// 부저 음이 발생하도록 설정
	sei();
}

SIGNAL(INT6_vect)
{
	cli();
	
	ICR3 = 7372800/659/2;		// 미의 음향을 연주한다
	TCCR3A = 0x40;					// PE4로 출력
	
	sound_flag = 1;					// 부저 음이 발생하도록 설정
	sei();
}

SIGNAL(INT7_vect)
{
	cli();
	
	ICR3 = 7372800/698/2;		// 파의 음향을 연주한다
	TCCR3A = 0x40;					// PE4로 출력
	
	sound_flag = 1;					// 부저 음이 발생하도록 설정
	sei();
}
/*
 * UART2.c
 *
 * Created: 2022-06-21 오전 11:26:19
 *  Author: PKNU
 */ 
#include <avr/io.h>		//입출력에 대한 헤더 파일

void putch(unsigned char data) {
	while((UCSR0A & 0x20) == 0);	//전송 준비가 될 때까지 대기
	UDR0 = data;					//데이터를 UDR0에 쓰면 전송
	UCSR0A |= 0x20;
}

unsigned char getch(){
	unsigned char data;
	while((UCSR0A & 0x80) == 0);	//데이터를 받을 때 까지 대기
	data = UDR0;					//수신 데이터는 URD0에 저장
	UCSR0A |= 0x80;
	return data;					//읽어온 문자 반환
}

int main(){
	unsigned char text[] =
	"\r\nWelcom! edgeiLAB\r\n USART 0 Test Program.\r\n";
	
	unsigned char echo[] = "ECHO >> ";
	unsigned char i = 0;
	
	DDRE = 0xfe;		//Rx(입력 0), Tx(출력 1)
	
	UCSR0A = 0x00;
	UCSR0B = 0x18;		//Rx, Tx Enable
	UCSR0C = 0x06;		//비동기 방식, No Parity bit, 1 Stop bit
	
	UBRR0H = 0x00;
	UBRR0L = 3;			//115200bps
	
	while(text[i] != '\0'){		//문자열 데이터가 '\0'인 경우 문자열 끝남을 알림
		putch(text[i++]);		//저장된 text 문자열 출력
	}
	i=0;		//카운터 변수 초기화
	while(echo[i] != '\0'){		//문자열 데이터가 '\0'인 경우, 문자열 끝남을 알림
		putch(echo[i++]);		//저장된 echo 문자열 출력
	}
	while(1){
		putch(getch());		//getch()로 입력받은 문자ㅑ를 다시 putch()로 문자열 출력
	}
}
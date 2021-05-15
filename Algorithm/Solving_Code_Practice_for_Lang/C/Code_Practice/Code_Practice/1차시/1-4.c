#include<stdio.h>

int main() {
	printf("\u250C\u252C\u2510\n");
	printf("\u251C\u253C\u2524\n");
	printf("\u2514\u2534\u2518\n");
	//유니코드 특수문자 입력 엔드스케이프시퀸스 \u

	printf("%d, %o, %x, %X", 10, 10, 10, 10);//10을 10, 8, 16진수로 표현
	
	return 0;
}

//C언어의 형식 지정자
/*
	%c : 문자 1개
	%d : 정수(decimal)
	%o : 8진 정수(octal)
	%x : 16진 정수(hexadecimal)
	%f : float 실수
	%lf : double 실수
	%p : 주소출력 (16진수)
	%s : 문자열
*/
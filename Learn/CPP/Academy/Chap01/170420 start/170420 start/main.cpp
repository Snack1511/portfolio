#include <stdio.h>

int main()
{
	// \n -> 줄바꿈
	// "" -> 문자열
	// '' -> 문자

	int iNum1, iNum2;							//변수선언
	int iNum3 = 30, iNum4 = 40;					//선언과 함께 초기화

	//int iNum -> 헝가리안 표기법 => 'i'nt 형 'Num'ber

	iNum1 = 10;								//초기화
	iNum2 = 20;

	// printf 함수를 사용할 때
	// %d -> 정수형을 출력할때 사용
	printf("[ %d ] [ %d ]\n", iNum1, iNum2);
	printf("[ %d ] [ %d ]\n", iNum3, iNum4);
	
	iNum1 = 100;
	iNum2 = 200;
	iNum3 = 300;
	iNum4 = 400;

	printf("[ %d ] [ %d ]\n", iNum1, iNum2);
	printf("[ %d ] [ %d ]\n", iNum3, iNum4);

	return 0;
}
//컴파일러는 메인함수만 실행하고 종료한다
//메인 함수가 종료되면 프로그램이 종료된다
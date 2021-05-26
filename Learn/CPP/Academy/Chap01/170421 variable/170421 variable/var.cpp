#include <stdio.h>

int main()
{
	/*
	int iNum = 0;
	float fNum = 3.141592f;

	iNum = (int)fNum;//(바꾸는 형)기본 형 -> 형태변환

	printf("%d\n", (int)fNum);
	printf("%d\n\n", iNum);
	
	char A, B, C, D;
	A = 'A';
	B = 'B';
	C = 'C';

	printf("A : %c\nB : %c\nC : %c\n\n", A, B, C);
	D = A;
	A = B;
	B = C;
	C = D;
	
	printf("A : %c\nB : %c\nC : %c\n\n", A, B, C);
	D = A;
	A = B;
	B = C;
	C = D;
	
	printf("A : %c\nB : %c\nC : %c\n\n", A, B, C);

	printf("%d\n", 'A');//정수출력
	printf("%c\n", 65);//문자출력
	printf("%x\n", 'A');//16진수출력
	printf("%c\n\n", 'A');//문자출력
	*/

	/*
	int iNum2;
	float fNum2;
	

	printf("iNum2 값 입력 : ");
	scanf("%d",  &iNum2);

	printf("fNum2 값 입력 : ");
	scanf("%f",  &fNum2);

	printf("iNum2 : %d\n", iNum2);
	printf("fNum2 : %f\n\n", fNum2);*/

	//printf("0~127 사이의 값을 입력 : ");
	//scanf("%d", &cStr);

	/*char cStr;
	printf("%d\n", cStr);*/

	char cStr1;
	char cStr2;
	char cStr3;

	printf("첫 번째 문자 입력 : ");
	scanf("%c", &cStr1);

	fflush(stdin); //키 스택 초기화
	printf("두 번째 문자 입력 : ");
	scanf("%c", &cStr3);

	fflush(stdin);
	printf("세 번째 문자 입력 : ");
	scanf("%c", &cStr1);

	printf("%c", cStr1);
	printf("%c", cStr2);
	printf("%c\n", cStr3);

	return 0;
}

//상수
//'A', "문자열"
//0, 3.141592f
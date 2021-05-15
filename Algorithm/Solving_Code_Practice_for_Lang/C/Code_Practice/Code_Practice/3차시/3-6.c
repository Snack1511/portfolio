#include<stdio.h>

int main() {
	char c;
	printf("영문자 입력 : ");
	scanf("%c", &c);
	printf("%c의 아스키 코드는 %d입니다.", c, c);
	return 0;
}
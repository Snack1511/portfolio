#include<stdio.h>

int main() {
	int num;

	printf("0~255 사이의 정수 입력 : ");
	scanf("%d", &num);

	printf("아스키 코드 값 %d의 아스키 문자는 %c입니다.", num, num);
	return 0;
}
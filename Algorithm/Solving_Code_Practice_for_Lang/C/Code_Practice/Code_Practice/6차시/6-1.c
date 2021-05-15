#include<stdio.h>

int main() {
	int num;
	printf("자연수를 입력하세요...");
	scanf("%d", &num);
	printf("%d", num);
	if (num % 7) {
		printf(" is not multiple");
	}
	else {
		printf(" is multiple");

	}
	//조건(삼항) 연산자 -> 조건식 ? 참 : 거짓
	(num%7) ? printf("%d is not multiple", num) : printf("%d is multiple", num);
	return 0;
}
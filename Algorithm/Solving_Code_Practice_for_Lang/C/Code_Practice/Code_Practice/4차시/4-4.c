#include<stdio.h>

int main() {
	int x, y;
	printf("판단 할 두 정수 입력 : ");
	scanf("%d %d", &x, &y);

	printf("결과 : %d", x ^ y);
	return 0;
}
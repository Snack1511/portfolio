#include<stdio.h>

int main() {

	int x;
	printf("10진 정수 입력 : ");
	scanf("%d", &x);
	printf("8진수\t16진수\t16진수\n");
	printf("%o\t%x\t%X\n", x, x, x);
	return 0;
}
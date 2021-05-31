#include<stdio.h>

int main() {
	int a;
	printf("정수를 입력하세요 : ");
	scanf("%d", &a);
	printf("%s\n", (a > 0) ? "양수" : "음수");
	printf("%s\n", (a % 2 == 0) ? "짝수" : "홀수");
	return 0;
}
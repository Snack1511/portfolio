#include<stdio.h>

int main() {

	int a, b, i;
	int sum = 0;

	printf("정수 2개 입력 : ");
	scanf("%d %d", &a, &b);
	for (i = a; i <= b; i++) {
		if (!(i % 3)) sum += i;
	}
	printf("%d", sum);
	return 0;
}
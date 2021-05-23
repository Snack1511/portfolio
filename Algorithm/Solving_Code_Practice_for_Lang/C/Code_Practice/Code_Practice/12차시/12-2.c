#include<stdio.h>

int main() {
	int n, sum = 0;
	printf("10자리 정수 입력 : ");
	scanf("%d", &n);

	while (n != 0) {
		sum += n % 10;
		n /= 10;
		printf("sum : %d \t\t n : %d\n", sum, n);
	}
	return 0;
}

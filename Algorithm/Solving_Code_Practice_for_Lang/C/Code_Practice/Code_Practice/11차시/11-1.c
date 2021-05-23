#include<stdio.h>

int main() {
	int a, b, i;

	printf("정수 2개 입력...: ");
	scanf("%d %d", &a, &b);
	if (a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	for (i = a; i <= b; i++) {
		printf("%d ", i);
	}

	return 0;
}
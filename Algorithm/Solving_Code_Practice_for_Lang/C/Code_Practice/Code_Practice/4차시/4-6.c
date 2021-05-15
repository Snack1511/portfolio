#include<stdio.h>

int main() {
	int x, y, z;
	printf("세 정수 입력 : ");
	scanf("%d %d %d", &x, &y, &z);

	if (x % 2 == 0) {
		printf("%d\n", x);
	}
	if (y % 2 == 0) {
		printf("%d\n", y);
	}
	if (z % 2 == 0) {
		printf("%d\n", z);
	}
	return 0;
}
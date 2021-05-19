#include<stdio.h>

int main() {
	int sum = 0;


	for (int i = 1; i < 101; i++) {
		printf("%3d ", i);
		sum += i;
	}

	printf("\n\n1-100까지 합계 : %d", sum);

	return 0;
}
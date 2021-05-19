#include<stdio.h>

int main() {
	int num;
	printf("판별할 수 입력 : ");
	scanf("%d", &num);
	while (num > 0) {
		if (num % 2) printf("홀수\n");
		else printf("짝수\n");

		printf("판별할 수 입력 : ");
		scanf("%d", &num);
	}

	return 0;
}
#include<stdio.h>

int main() {
	int num;
	int oddmax = 0, evalmax = 0;
	printf("자연수 10개 입력  : ");
	for (int i = 0; i < 10; i++) {
		scanf("%d", &num);
		if (num % 2) {
			if (num > oddmax) oddmax = num;
		}
		else {
			if (num > evalmax) evalmax = num;
		}
	}
	printf("홀수 중 가장 큰 수 : %d", oddmax);
	printf("\n");
	printf("짝수 중 가장 큰 수 : %d", evalmax);


	return 0;
}
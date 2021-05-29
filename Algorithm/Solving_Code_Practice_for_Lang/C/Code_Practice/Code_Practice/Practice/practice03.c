#include<stdio.h>

int main() {
	long long a, b, add;
	long double avg;
	printf("계산할 두 정수 입력 : ");
	scanf("%lld %lld", &a, &b);
	add = a + b;
	avg = (long double)(a + b) / 2;
	printf("두 수의 합계 : %lld\n", add);
	printf("두 수의 평균 : %.1Lf\n", avg);
	return 0;
}
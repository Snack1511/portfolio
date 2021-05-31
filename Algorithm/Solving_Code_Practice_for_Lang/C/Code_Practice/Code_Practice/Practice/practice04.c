#include<stdio.h>

int main() {
	float a, b, c;
	float min;
	printf("세 정수를 입력하세요 : ");
	scanf("%f %f %f", &a, &b, &c);
	min = (a > b) ? ((b > c) ? c : b) : ((a > c) ? c : a);
	printf("가장 작은 수 : %f\n", min);
	return 0;
}
#include<stdio.h>

int main() {
	int x, y;
	printf("연산할 두 정수 입력 : ");
	scanf("%d %d", &x, &y);

	printf("합 : %d\n", x+y);
	printf("차 : %d\n", x-y);
	printf("곱 : %d\n", x*y);
	printf("몫 : %d\n", x/y);
	printf("나머지 : %d\n", x%y);
	printf("%d / %d = %.2f", x, y, (float)x/y);
	
	return 0;
}
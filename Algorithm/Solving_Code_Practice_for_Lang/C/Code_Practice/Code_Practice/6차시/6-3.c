#include<stdio.h>
#define PI 3.141592
int main() {
	int radius;

	float cir, area;
	double Pi = 3.141592;
	printf("=== 원의 둘레와 넓이를 구하기 ===\n");
	printf("원의 반지름 입력[㎝] : ");
	scanf("%d", &radius);

	cir = (float)(2 * radius * Pi);
	area = (float)(radius * radius * Pi);
	printf("원의 둘레 : %.2f[㎝]", cir);
	printf("원의 넓이 : %.2f[㎠]", area);


	return 0;
}
#include<stdio.h>
#define PI 3.141592
int main() {
	int item, radius;

	float cir, area, sur, vol;
	printf("(1.원의 둘레 2.원의 넓이 3.구의 겉넓이 4.구의 부피)\n");
	printf("보기중 구하려는 항목을 선택하세요 : ");
	scanf("%d", &item);
	printf("반지름 입력[㎝] : ");
	scanf("%d", &radius);

	
	switch (item) {
	case 1:
		cir = (2 * radius * PI);
		printf("원의 둘레 : %.2f[㎝]", cir);
		break;
	case 2:
		area = (radius * radius * PI);
		printf("원의 넓이 : %.2f[㎠]", area);
		break;
	case 3:
		sur = 4 * radius * radius * PI;
		printf("구의 겉넓이 : %.2f[㎠]", sur);
		break;
	case 4:
		vol = (4 / 3) * PI * radius * radius * radius;
		printf("구의 부피 : %.2f[㎤]", vol);
		break;
	default:
		printf("\n항목에 없는 숫자를 선택하셨습니다.");
		break;
	}

	


	return 0;
}
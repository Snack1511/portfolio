#include<stdio.h>

int main() {
	int a;
	char plus[4];
	printf("정수를 입력하세요(0~99) : ");
	scanf("%d", &a);
	
	switch (a % 10) {
	case 1:
		if (a == 11) break;
		printf("%dst", a);
		break;
	case 2:
		if (a == 12) break;
		printf("%dnd", a);
		break;
	case 3:
		if (a == 13) break;
		printf("%drd", a);
		break;
	default:
		if (a >= 100) printf("입력 값이 범위를 초과했습니다.\n"); break;
		printf("%dth", a);
		break;
	}
	return 0;
}
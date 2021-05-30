#include<stdio.h>

int main() {
	int a, b, c, d, result;
	printf("윷놀이 시작 숫자 4개를 공백으로 구분하여 입력하세요 : ");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	result = a + b + c + d;
	if (result == 0) printf("모\n");
	else if (result == 1) printf("도\n");
	else if (result == 2) printf("개\n");
	else if (result == 3) printf("걸\n");
	else if (result == 4) printf("윷\n");
	return 0;
}
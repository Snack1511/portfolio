#include<stdio.h>

int main() {
	int a, b, c;
	int num = 0;
	printf("세 정수를 오름차순으로 입력 : ");
	scanf("%d %d %d", &a, &b, &c);

	while (1) {
		if (!(a % num && b % num && c % num)) break;
		num++;
	}
	printf("%d", num);
	return 0;
}
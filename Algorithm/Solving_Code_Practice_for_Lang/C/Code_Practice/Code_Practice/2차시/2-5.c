#include<stdio.h>

int main() {
	int h, m, s;
	printf("시, 분, 초를 입력하세요");
	scanf("%d:%d:%d", &h, &m, &s);

	printf("%d시 입니다.", h);
	return 0;
}

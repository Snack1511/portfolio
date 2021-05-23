#include<stdio.h>

int main() {
	int h, m;

	printf("시 분 입력 : ");
	scanf("%d %d", &h, &m);

	m -= 30;
	if (m < 0) { m += 60; h -= 1; }
	if (h < 0) { h += 24; }
	printf("%d %d", h, m);


	return 0;
}
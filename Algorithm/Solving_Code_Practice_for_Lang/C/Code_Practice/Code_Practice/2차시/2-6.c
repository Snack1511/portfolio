#include<stdio.h>

int main() {
	int y,m,d;
	printf("날짜입력(년-월-일) : ");
	scanf("%d-%d-%d", &y, &m, &d);

	printf("%02d.%02d.%04d", d, m, y);
	return 0;
}

#include<stdio.h>

int main() {
	int h1, h2, h3;

	printf("세 터널의 높이를 공백으로 구분하여 입력하세요....: ");
	scanf("%d %d %d", &h1, &h2, &h3);


	if (h1 <= 170 || h2 <= 170 || h3<= 170) {
		printf("CRASH");
	}
	else {
		printf("PASS");
	}


	return 0;
}
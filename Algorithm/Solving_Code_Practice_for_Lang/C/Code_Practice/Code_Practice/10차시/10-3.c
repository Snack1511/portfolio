#include<stdio.h>

int main() {
	int h1, h2, h3;

	printf("세 터널의 높이를 공백으로 구분하여 입력하세요....\n");
	scanf("%d %d %d", &h1, &h2, &h3);


	if (h1 <= 170 || h2 <= 170 || h3 <= 170) {
		if (h1 <= 170) printf("CRASH %dcm / ", h1);
		if (h2 <= 170) printf("CRASH %dcm / ", h2);
		if (h3 <= 170) printf("CRASH %dcm / ", h3);
	}
	else {
		printf("PASS");
	}


	return 0;
}
#include<stdio.h>

int main() {

	int x = 1;
	printf("숫자를 공백으로 구분해 입력하세요....\n");
	while (x != 0) {
		scanf("%d", &x);
		if (x != 0) {
			printf("%03d\t", x);
		}
	}
	return 0;
}
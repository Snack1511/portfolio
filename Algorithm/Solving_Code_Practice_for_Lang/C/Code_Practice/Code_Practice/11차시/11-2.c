#include<stdio.h>

int main() {
	int w, h;

	int area = 0;
	int tmp = 0;
	for (int i = 0; i < 3; i++) {
		printf("가로 세로 순으로 입력...: ");
		scanf("%d %d", &w, &h);
		tmp = w * h;
		if (area < tmp) {
			area = tmp;
		}
	}
	printf("%d", area);

	return 0;
}
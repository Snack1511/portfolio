#include<stdio.h>


int main() {
	int n;
	int pos[2][16];
	int idx = 0;
	printf("흰 돌을 놓을 개수 입력 : ");
	scanf("%d", &n);
	printf("흰 돌을 놓을 좌표(x, y)를 공백으로 구분하여 입력\n");
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &pos[0][i], &pos[1][i]);
	}
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (pos[0][idx]-1 == i && pos[1][idx]-1 == j) {
				printf(" 1");
				idx++;
			}
			else {
				printf(" 0");
			}
		}
		printf("\n");
	}
	return 0;
}
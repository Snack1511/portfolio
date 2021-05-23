#include<stdio.h>

int main() {
	int w, h;
	printf(".가로 길이와 세로 길이 입력 : ");
	scanf("%d %d", &w, &h);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (i == 0 || i == h - 1) {
				if (j == 0 || j == w - 1) {
					printf("+");
				}
				else printf("-");
			}
			else {
				if (j == 0 || j == w - 1) {
					printf("|");
				}
				else printf(" ");
			}
		}
		printf("\n");
		
		
		
	}
	return 0;
}
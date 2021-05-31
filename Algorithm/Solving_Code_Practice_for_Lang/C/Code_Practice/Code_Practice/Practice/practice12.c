#include<stdio.h>

int main() {
	int n;
	printf("밑변과 높이로 사용할 수 입력 : ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i; j++) {
			printf(" ");
		}
		for (int j = 0; j < n; j++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
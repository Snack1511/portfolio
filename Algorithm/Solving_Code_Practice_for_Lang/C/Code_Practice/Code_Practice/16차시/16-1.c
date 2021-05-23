#include<stdio.h>
int arr[100000000] = { 0, };

int main() {
	int n,i, number, m;
	printf("N개의 숫자 : ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &number);

		arr[number - 1] = 1;
	}

	printf("M개의 질문 : ");
	scanf("%d", &m);

	for (i = 0; i < m; i++) {
		scanf("%d", &number);

		printf("%d ", arr[number - 1]);
	}
}
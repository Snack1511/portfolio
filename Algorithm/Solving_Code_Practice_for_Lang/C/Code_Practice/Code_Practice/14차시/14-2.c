#include<stdio.h>

int main() {
	int n, i, m;
	int arr[50] = { 0, };
	printf("출석 번호를 부를 횟수 입력 : ");
	scanf("%d", &n);

	printf("출석 번호를 공백으로 구분하여 횟수만큼 입력 : \n");
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = n - 1; i >= 0; i--) {
		printf("%d ", arr[i]);
	}
	return 0;
}
#include<stdio.h>

int main() {
	int n, m, a;
	printf("전체 카드수 입력 : ");
	scanf("%d", &n);
	m = ((n + 1) * (n / 2)) + (n % 2) * ((n + 1) / 2);
	for (int i = 0; i < n - 1; i++) {
		printf("카드 번호 입력 : ");
		scanf("%d", &a);
		m -= a;
	}
	printf("빠진 카드 번호 : %d", m);
}
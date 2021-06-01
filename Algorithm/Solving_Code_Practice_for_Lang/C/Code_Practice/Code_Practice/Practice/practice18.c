#include<stdio.h>

int Prime(int n) {
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			printf("composite_number\n");
			return 0;
		}
	}
	printf("prime_number\n");
	return 1;
}

int main() {
	int n;
	printf("1보다 큰 자연수 입력 : ");
	scanf("%d", &n);
	Prime(n);
	return 0;
}
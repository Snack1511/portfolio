#include<stdio.h>

int prime(n) {
	int num = 0;
	for (int i = 2; i <= n; i++) {
		if (!(n % i)) num++;
	}
	return num;
}

int main() {
	int n;
	printf("어떤 길이로 자를까요? ");
	scanf("%d", &n);
	printf("조각 수는 %d입니다.", prime(n));

	return 0;
}
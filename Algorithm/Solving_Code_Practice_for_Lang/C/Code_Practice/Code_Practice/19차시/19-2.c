#include <stdio.h>
long long int reverse(long long int x);

int main() {
	long long int m;

	printf("정수 입력 : ");
	scanf("%lld",&m);

	printf("뒤집은 수 : ");
	printf("%lld", reverse(m));
	return 0;
}

long long int reverse(long long int x) {
	while (x > 9) {
		printf("%lld", x % 10);
		x /= 10;
	}
	return x;
}
#include <stdio.h>
int max(int x, int y);
int min(int x, int y);
int mid(int x, int y, int z);

int main() {
	int l, m, n;

	printf("세 정수 입력 : ");
	scanf("%d %d %d", &l, &m, &n);

	printf("중간 값 : %d", mid(l, m, n));
	return 0;
}
int max(int x, int y) {
	return x >= y ? x : y;
}
int min(int x, int y) {
	return x < y ? x : y;
}

int mid(int x, int y, int z) {
	int result = x + y + z - max(max(x, y), z) - min(min(x, y), z);
	return result;
}
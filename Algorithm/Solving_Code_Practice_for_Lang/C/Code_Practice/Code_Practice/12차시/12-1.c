#include<stdio.h>

int main() {
	int start, multiple, add, idx;
	printf("시작, 곱, 합, 반복 수 입력 : ");
	scanf("%d %d %d %d", &start, &multiple, &add, &idx);
	int result = start;
	for (int i = 0; i < idx - 1; i++) {
		result = (result * multiple) + add;
	}
	printf("%d", result);
	return 0;
}
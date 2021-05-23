#include <stdio.h>
int ranking(int* arr, int idx, int n);

int main() {
	int n;
	int array[1000];
	int i;

	printf("지점 개수 : ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}

	for (i = 0; i < n; i++) {
		printf("%3d -> %3d\n", array[i], ranking(array, i, n));
	}

	return 0;
}

int ranking(int* arr, int idx, int n) {
	int i, rank = 1;
	for (i = 0; i < n; i++) {
		if (*(arr + i) > *(arr + idx))
			rank++;
	}
	return rank;
}
#include<stdio.h>
#include<stdlib.h>

void Sort(int* arr, int n) {
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (arr[j] < arr[i]) {
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int main() {
	int weight[3], tmp;
	printf("몸무게 입력\n");
	scanf("%d %d %d", &weight[0], &weight[1], &weight[2]);
	Sort(weight, 3);
	printf("줄을 세우는 순서 \n%d %d %d", weight[0], weight[1], weight[2]);
	return 0;
}
#include<stdio.h>

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
	int n, m;
	int student[128];
	printf("학생 수와 한 줄에 앉을 수 있는 자리 수 입력 : ");
	scanf("%d %d", &n, &m);
	printf("%d명의 학생 키 입력 : \n", n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &student[i]);
	}
	Sort(student, n);
	printf("좌석배치도\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", student[i]);
		if (i % m == m - 1) printf("\n");
	}
	return 0;
}
#include <stdio.h>
int n, data[100000], m;
int locate(int num);

int main() {
	int i;

	printf("데이터 개수 : ");
	scanf("%d", &n);

	printf("%d개 숫자를 공백으로 구분해 입력\n", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}
	printf("찾은 값 : ");
	scanf("%d", &m);
	printf("찾은 위치 : %d", locate(m));

	return 0;
}

int locate(int num) {
	int i;
	for (i = 0; i < n; i++)
		if (data[i] == m)
			return i + 1;
	return -1;
}
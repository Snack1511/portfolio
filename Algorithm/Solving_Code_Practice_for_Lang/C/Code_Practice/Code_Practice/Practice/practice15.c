#include<stdio.h>



int main() {
	int length[3], tmp;
	printf("용의자 10명의 키 입력 : ");
	for (int i = 0; i < 10; i++) {
		scanf("%d", &tmp);
		if (length[0] < tmp) {
			length[2] = length[1];
			length[1] = length[0];
			length[0] = tmp;
		}
	}
	printf("3번째로 큰 사람의 키 : %d", length[2]);

	return 0;
}


#include <stdio.h>

int main() {
	int no, i, j ,num, sum, count;
	int score[1000] = { 0, };
	float avg;

	printf("테스트할 횟수 입력 : ");
	scanf("%d", &no);

	printf("학생 수와 정수는 공백으로 구분해 입력\n");
	for (i = 0; i < no; i++) {
		scanf("%d", &num);

		sum = 0;

		for (j = 0; j < num; j++) {
			scanf("%d", &score[j]);
			sum += score[j];
		}

		avg = (float)sum / num; 

		count = 0;

		for (j = 0; j < num; j++) {
			if (score[j] > avg)
				count++;
		}
		printf("%.3f%%\n", (float)count / num * 100);
	}
	return 0;
}
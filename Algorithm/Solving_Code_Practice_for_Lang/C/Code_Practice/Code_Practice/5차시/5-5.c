#include<stdio.h>

int main() {
	int score1, score2;

	printf("1과목의 점수 입력 : ");
	scanf("%d", &score1);
	printf("2과목의 점수 입력 : ");
	scanf("%d", &score2);

	if (score1 >= 60) {
		if (score2 >= 60) {
			printf("합격");
		}
		else {
			printf("불합격");
		}
	}
	else {
		printf("불합격");
	}
	return 0;
}

#include<stdio.h>

int main() {

	int score;
	char grade;
	do {
		printf("시험점수입력 : ");
		scanf("%d", &score);
		grade = (score >= 90) ? 'A' : (score >= 80) ? 'B' : (score >= 70) ? 'C' : (score >= 60) ? 'D' : 'F';
		if (score > 0 && score <= 100) {
			printf("%c등급입니다.\n", grade);
		}
	} while (score > 0 && score <= 100);
	return 0;
}
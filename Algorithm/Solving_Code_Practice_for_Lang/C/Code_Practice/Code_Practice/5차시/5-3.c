#include<stdio.h>

int main() {
	int score;

	printf("정수를 입력하세요 : ");
	scanf("%d", &score);

	printf("평가 : ");
	if (score >= 90) {
		printf("A");
	}
	else if(score >= 70){
		printf("B");
	}
	else if (score >= 40) {
		printf("C");
	}
	else {
		printf("D");
	}
	return 0;
}
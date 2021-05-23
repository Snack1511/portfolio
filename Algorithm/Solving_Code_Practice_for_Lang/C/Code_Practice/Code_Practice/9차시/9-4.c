#include<stdio.h>

int main() {
	int year, month, day;

	printf("년 월 일 순으로 정수 3개를 입력 : ");
	scanf("%d %d %d", &year, &month, &day);

	int result = year + month + day;

	if ((result / 100)%2 == 0) {
		printf("대박 %d", result);
	}
	else {
		printf("그럭저럭 %d", result);
	}


	return 0;
}
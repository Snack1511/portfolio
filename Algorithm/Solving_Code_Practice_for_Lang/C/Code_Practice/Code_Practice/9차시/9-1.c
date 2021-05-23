#include<stdio.h>

int main() {
	int num;

	printf("1~100 사이의 정수 입력 : ");
	scanf("%d", &num);

	//입력값 범위 제한
	if (num < 1 || num>100) {
		printf("1~100사이의 숫자가 아닙니다.\n");
		return; // 종료
	}

	while (num != 0) {
		printf("%d\n", num--); // num 변수 값 1 감소
								//num = num - 1과 num-- -> 같은 코드
	}

	return 0;
}
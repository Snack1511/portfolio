#include<stdio.h>

int main() {
	int day;
	printf("요일을 숫자로 입력하세요...");
	scanf("%d", &day);
	
	switch (day) {
	case 1: case 3: case 5: case 7:
		printf("Oops!");
		break;
	case 2: case 4: case 6: 
		printf("Enjoy it");
		break;

	default:
		printf("요일 번호를 잘 못 입력하셨습니다.");
		break;
	}

	return 0;
}
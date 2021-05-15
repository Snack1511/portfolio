#include<stdio.h>

int main() {
	char x;

	printf("평가를 입력하세요 : ");
	scanf("%c", &x);

	printf("평가 : ");

	switch (x) {
	case 'A': case 'a' :
		printf("Best!!");
		break;
	case 'B': case 'b' :
		printf("Good!");
		break;
	case 'C': case 'c' :
		printf("Trying");
		break;
	case 'D': case 'd' :
		printf("Incomplete..");
		break;
	default:
		printf("What?");
		break;
	}
	return 0;
}

#include<stdio.h>

void main(){
	int x=0, y = 0, z = 0;
	char opr = NULL;

	printf("피연산자 1 : \n");
	scanf("%d", &x);

	printf("피연산자 2 : \n");
	scanf("%d", &y);

	printf("연산자 : \n");
	scanf("%c", &opr);

	switch(opr){
	case 75:
		z = x+y;
		printf("정답 : %d\n", z);
		break;
	case 77:
		z = x-y;
		printf("정답 : %d\n", z);
		break;
	case 74:
		z = x*z;
		printf("정답 : %d\n", z);
		break;
	case 79:
		z = x/y;
		printf("정답 : %d\n", z);
		break;
	case 69:
		z = x%y;
		printf("정답 : %d\n", z);
		break;
	default:
		printf("oops!\n");
		break;

	}
}
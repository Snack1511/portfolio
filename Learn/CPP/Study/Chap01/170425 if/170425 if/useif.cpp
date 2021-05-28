#include<stdio.h>

int main(){
	while(true){
	int iInput = 0, iInput2;
	printf("숫자입력 : \n");
	scanf("%d", &iInput);
	
	printf("숫자입력 : \n");
	scanf("%d", &iInput2);

	if(iInput == iInput2){
		printf("%d = %d\n", iInput, iInput2);
	}
	else if(iInput> iInput2){
		printf("%d > %d\n", iInput, iInput2);

	}
	else
		printf("%d < %d\n", iInput, iInput2);
	
	}


	/*if(iInput%3 == 0){
		printf("%d 는 3의 배수이다\n", iInput);
	}
	else if(iInput%3 ==1)
		printf("%d 는 3의 배수 +1이다\n", iInput);
	else
		printf("%d 는 3의 배수 +2이다\n", iInput);*/
	//3배수 판별기


	/*if(iInput%2 == 0){
		printf("%d 는 짝수이다", iInput);
	}
	else
		printf("%d 는 홀수이다", iInput);*/
	//홀짝 판별기

	/*if(iInput <= 0)
	{
		printf("%d : 0보다 작거나 같다\n", iInput);
	}
	else if(iInput > 0&&iInput<10)
	{
		printf("%d : 0보다 크지만 10 보다 작다\n", iInput);
	}
	else if(iInput > 10 && iInput <15||(iInput>20&&iInput<25))
	{
		printf("그러하다");
	}
	else
		printf("else\n");*/
	//양수 음수 판별기

	return 0;
}
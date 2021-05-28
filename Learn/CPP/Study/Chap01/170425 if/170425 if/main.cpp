#include<stdio.h>

int main(){
	int iKor;
	printf("국어 점수 입력 : ");
	scanf("%d", &iKor);
	

	if(iKor > 90){
		printf("만점인대 ");

	}
	else if(iKor >= 50){
		printf("좀더 열심히");

	}
	else if(iKor >= 10){

		printf("국어를 ");
	}
	else
		printf("한국인을 ");



	return 0;
}
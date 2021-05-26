#include<stdio.h>

int main(){

	/*for(int i = 0; i < 10; i++){//for문 안에 int초기화는 cpp에서만 가능하다

		printf("Hello World : %d\n", i);

	}*/

	/*for(int i = 1; i < 10; i++){

		for(int j = 1; j < 10; j++){
			printf("%d x %d = %d\n", i, j, (i*j));
		}
		printf("\n");
	}
	printf("\n");*/

	/*int iYear = 2016-1627;
	float fMoney = 24.0f;
	float fInterest = 0.08f;

	for(int i = 0; i< iYear; i++){
		fMoney +=(fMoney * fInterest);

	}
	printf("%f", fMoney);*/


	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(i > j){
				printf(" ");

			}
			else{


				printf("*");
			}

		}
		printf("\n");
	}

	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(i < j){
				printf(" ");
				
			}
			else{

				
				printf("*");
			}

		}
		printf("\n");
	}

	
	for(int i = 0; i < 10; i++){
		for(int j = 10; j > i; j--){

			printf("*");
		}
		printf("\n");
	}
	//네번쨰
	return 0;
}
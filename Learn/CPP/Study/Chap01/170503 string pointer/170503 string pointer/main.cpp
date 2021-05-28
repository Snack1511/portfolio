#include<stdio.h>

int main(){

	//string

// 	int iKor[3], iEng[3], iMath[3];
// 
// 	for(int i = 0; i < 3; i++){
// 
// 		printf("국어점수 %d명째ㅇㅇ : \n", i+1);
// 		scanf_s("%d", &iKor[i]);
// 
// 		printf("수학점수 %d명ㅇㅇ : \n", i+1);
// 		scanf_s("%d", &iMath[i]);
// 
// 		printf("영어점수 %d명ㅇㅇ : \n", i+1);
// 		scanf_s("%d", &iEng[i]);
// 		printf("\n");
// 	}
// 
// 	printf("국수영 점수\n");
// 
// 	for(int i = 0; i < 3; i++){
// 
// 		printf("%d, %d, %d\n",iKor[i], iMath[i], iEng[i] );
// 
// 	}


	/*
	
	char str1[7];
	printf("이름입력 : ");
	scanf("%s", str1);

	printf("%s\n", str1);
		
	char str[3][7];//2차원 배열 or 다차원 배열이라 부른다
	int iKor[3];
	int iEng[3];
	int iMath[3];

	for(int i = 0; i < 3; i++){

		printf("이름입력 : \n");
		scanf("%s", str[i]);//문자열(%s)을 쓸땐 &가 필요없다, 문자(%c)를 쓸땐 필요하다
		printf("국어점수입력 : \n");
		scanf("%d", &iKor[i]);
		printf("영어점수입력 : \n");
		scanf("%d", &iEng[i]);
		printf("수학점수입력 : \n");
		scanf("%d", &iMath[i]);
	}

	for(int i = 0; i < 3; i++){

		printf("이릅 : %s\n\n", str[i]);

		printf("국어 : %d\n", iKor[i]);
		printf("영어 : %d\n", iEng[i]);
		printf("수학 : %d\n", iMath[i]);

	}

	*/



	//pointer

	//규칙
	//1. & = 주소, * = 데이터
	//2. 
	//3. 

	int* piNum;//주소를 받아오는 정수형 변수, = 10같은 경우는 될수 없다
	int iNum = 10;

	//주소값에 접근하려면 변수앞에 &를 붙인다
	//데이터에 접근하려면 포인터변수 앞에 *을 붙인다.

	piNum = &iNum;// &iNum => iNum의 주소값(레퍼런스)

	printf("%d\n", piNum);
	printf("%d\n", *piNum);
	printf("%d\n", &piNum);

	return 0;
}
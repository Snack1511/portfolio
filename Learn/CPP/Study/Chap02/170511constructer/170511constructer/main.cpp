#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>


/*
typedef struct tagInfo{


	int iIndex1;
	int iIndex2;

	tagInfo(){

	}

	tagInfo(int _iIndex1) : iIndex1(_iIndex1){


	}

	tagInfo(int _iIndex1, int _iIndex2) 
		: iIndex1(_iIndex1), iIndex2(_iIndex2){


	}


}INFO;
*/

typedef struct tagInfo{

	int iKor;
	int iEng;
	int iMath;
	float fResult;

	tagInfo(){

	}
	tagInfo(int _iKor, int _iEng, int _iMath) 
		: iKor(_iKor), iEng(_iEng), iMath(_iMath){

	}
	

}INFO;
int main(){


	/*INFO Info1;
	INFO Info2;

	Info1 = INFO(10);
	Info2 = INFO(20);

	printf("%d\n", Info1.iIndex1);
	printf("%d\n", Info1.iIndex2);
	printf("%d\n", Info2.iIndex1);
	printf("%d\n", Info2.iIndex2);*/


	/*
	INFO Info[3];

	for(int i = 0; i< 3; i++){
		//Info[i].iIndex1 = i*10+10;
		//Info[i].iIndex2 = i*100+100;
		Info[i] = INFO(i*10+10, i*100+100);


	}

	for(int i = 0; i< 3; i++){
		printf("size : %d     [ %d, %d }\n",sizeof(Info[i]),  Info[i].iIndex1, Info[i].iIndex2);
	}
	*/

	/*
	INFO* Info[3];

	for(int i = 0; i< 3; i++){
		
		Info[i] =  (INFO*)malloc(sizeof(INFO));
		*Info[i] = INFO(i*10+10, i*100+100);
	}

	for(int i = 0; i< 3; i++){
		printf("size : %d     [ %d, %d ]\n",sizeof(Info[i]),  Info[i]->iIndex1, Info[i]->iIndex2);
	}

	*/



	//3명의 학생정보를 입력하고 출력하는 구문 작성
	//pointer사용

	//학생별 평균점수를 확인할수 있게 작성

	// 학생별 평균 점수로 순위 정렬


	INFO* Info[3];

	srand(unsigned(time(NULL)));

	for(int i = 0; i < 3; i++){

		Info[i] = (INFO*)malloc(sizeof(INFO));
		*Info[i] = INFO(rand()%100+1, rand()%100+1, rand()%100+1);
		/*int iKor, iEng, iMath;
		printf("%d번쨰 학생의 국어성적 : \n", i+1);
		scanf("%d", &iKor);
		printf("%d번쨰 학생의 영어성적 : \n", i+1);
		scanf("%d", &iEng);
		printf("%d번쨰 학생의 수학성적 : \n", i+1);
		scanf("%d", &iMath);

		*Info[i] = INFO(iKor, iEng, iMath);*/
	}

	for(int i = 0; i < 3; i++){
		float fResult;
		fResult =(float)(Info[i] -> iKor + Info[i] -> iEng + Info[i] -> iMath)/3;
		
		Info[i] -> fResult = fResult;
	}

	for(int i = 0; i < 3; i++){
		float fTemp;
		for(int j = i+1; j < 3; j++){
			if(Info[i] -> fResult < Info[j] -> fResult){
			
				fTemp = Info[i]->fResult;
				Info[i] ->fResult = Info[j] -> fResult;
				Info[j] ->fResult = fTemp;
			}
		}

	}
	for(int i = 0; i < 3; i++){

		//printf("%d등의 국어 : %d    영어 : %d    수학 : %d\n\n\n", i+1, Info[i]->iKor, Info[i]->iEng, Info[i]->iMath);
		printf("%d등의 평균점수 : %f\n\n\n", i+1, Info[i]->fResult);

	}

	
	return 0;
}
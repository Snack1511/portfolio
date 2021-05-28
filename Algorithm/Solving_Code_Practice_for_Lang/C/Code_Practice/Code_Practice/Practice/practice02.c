#include<stdio.h>

int main() {
	int iKor, iEng, iMat;
	float fAverage;
	printf("세 과목의 점수를 입력하세요...\n");
	printf("국어 점수 : ");
	scanf("%d", &iKor);
	printf("영어 점수 : ");
	scanf("%d", &iEng);
	printf("수학 점수 : ");
	scanf("%d", &iMat);
	fAverage = iKor + iEng + iMat;
	fAverage /= 3;
	printf("합계 : %d점, 평균 : %.1f점\n", iKor + iEng + iMat, fAverage);
	
	

	return 0;
}
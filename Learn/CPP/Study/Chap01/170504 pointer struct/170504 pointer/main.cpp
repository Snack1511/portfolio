#include<stdio.h>

typedef struct tagInfo{

	int iKor;
	int iEng;
	int iMath;
}INFO;

int main(){
	/*int iNumber = 10;
	int* piNumber;
	piNumber = &iNumber;

	printf("iNumber : %d\n", iNumber);
	printf("*piNumber : %d\n", *piNumber);
	printf("piNumber : %d\n", piNumber);
	printf("&iNumber : %d\n", &iNumber);
	printf("&piNumber : %d\n", &piNumber);
	*/

	INFO StudentA;
	tagInfo StudentB;

	printf("StudentA : \n");
	printf("Korean : ");
	scanf("%d", &StudentA.iKor);
	
	printf("English : ");
	scanf("%d", &StudentA.iEng);

	printf("Mathmatice : ");
	scanf("%d", &StudentA.iMath);

	printf("Korean : %d, English : %d, Mathmatice : %d\n", StudentA.iKor, StudentA.iEng, StudentA.iMath);

	printf("StudentB : \n");
	printf("Korean : ");
	scanf("%d", &StudentB.iKor);

	printf("English : ");
	scanf("%d", &StudentB.iEng);

	printf("Mathmatice : ");
	scanf("%d", &StudentB.iMath);

	printf("Korean : %d, English : %d, Mathmatice : %d\n", StudentB.iKor, StudentB.iEng, StudentB.iMath);
	return 0;
}
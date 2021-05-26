#include<stdio.h>
#include<malloc.h>

typedef struct tagInfo{

	char* Name;

	int iKor;
	int iMath;
	int iEng;

}INFO;

void Initialize(INFO* _pinfo);

int main(){

	INFO* pInfo = (INFO*)malloc(sizeof(INFO));
	
	INFO Info;
	Info.Name = "아무개";
	Info.iKor = 1;
	Info.iEng = 2;
	Info.iMath = 3;

	printf("%s\n국어 : %d\n영어 : %d\n수학 : %d\n\n\n", Info.Name, Info.iKor, Info.iEng, Info.iMath);

	Initialize(pInfo);

	printf("%s\n국어 : %d\n영어 : %d\n수학 : %d\n\n\n", pInfo->Name, pInfo->iKor, pInfo->iEng, pInfo->iMath);

	printf("\n\n\%d\n", sizeof(INFO));
	printf("%d\n\n\n\n", sizeof(INFO*));

	pInfo -> Name = "홍길동";
	pInfo -> iKor = 10;
	pInfo -> iEng = 20;
	pInfo -> iMath = 30;

	printf("%s\n국어 : %d\n영어 : %d\n수학 : %d\n\n\n\n", pInfo->Name, pInfo->iKor, pInfo->iEng, pInfo->iMath);
}

void Initialize(INFO* _pinfo){

	_pinfo->Name = "임꺽정";
	
	_pinfo->iKor = 100;
	_pinfo->iEng = 100;
	_pinfo->iMath = 100;


}













/*
typedef struct tagInfo{
	//char cName[128];
	char* pCharacter;

}INFO;

int main(){

	INFO* pInfo = (INFO*)malloc(sizeof(INFO));

	/*pInfo -> cName[0] = 'A';
	pInfo -> cName[1] = 'B';
	pInfo -> cName[2] = 'C';
	pInfo -> cName[3] = 'D';
	pInfo -> cName[4] = 'E';
	pInfo -> cName[5] = 'F';
	pInfo -> cName[6] = 'G';
	pInfo -> cName[7] = '\0';*/

	/*pInfo->pCharacter = "ZYXWVUT";

	printf("%s\n\n", pInfo->pCharacter);

	free(pInfo);*/

	/*char cAlphabet;
	char cHanguel;

	cAlphabet = 'A';
	cHanguel = '한';

	printf("Alphabet : %c / Hanguel : %c\n", cAlphabet, cHanguel);

	char cHarray[] = "한";

	printf("%s\n\n", cHarray);

	return 0;
}*/

//typedef를 쓰는 이유 -> c에서 struct의 인수를 참조하려면 struct 구조체이름 구조체변수 식으로 작성해야함
//					  -> 번거로워서 typedef를 이용해 가독성도 늘이고 번거로움도 줄였다.
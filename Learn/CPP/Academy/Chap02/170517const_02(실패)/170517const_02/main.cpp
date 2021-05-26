#include<stdio.h>
#include<malloc.h>
#include <string>
//열거형
/*
enum STATEID
{	//정수형&상수형
	
	LOGO,
	MENU,
	STAGE,
	EXIT,
};*/


enum STATEID
{	

	KOR,
	ENG,
	MATH,
};

typedef struct tagInfo{

	char* Name;

	int iKor;
	int iEng;
	int iMath;

	tagInfo(){};
	tagInfo(char* _name, int _ik, int _ie, int _im) :Name(_name), iKor(_ik), iEng(_ie), iMath(_im){};


}INFO;


INFO* createinfo();
char* setname();

int main()
{
	//상수

	//1, 2, 3, 4, 5, 6, 7, 8, 9, 0
	//A, B, C, D, E, F, G, H, I, J

	/*
	STATEID eState = LOGO;
	int iNum = 0;
	while(true)
	{
		printf("state : ");
		switch(eState)
		{
		case LOGO:
			printf("AAA\n");
			iNum++;
			if(iNum >= 5){
				eState = MENU;
			}
			break;
		case MENU:
			printf("BBB\n");
			iNum++;
			if(iNum >= 10){
				eState = STAGE;
			}
			break;
		case STAGE:
			printf("CCC\n");
			iNum++;
			if(iNum >= 15){
				eState = EXIT;
			}
			break;
		case EXIT:
			printf("InsertCoin\n");
			iNum++;
			if(iNum >= 20){
				eState = LOGO;
				iNum = 0;
			}
			break;
		}
	}
	*/

	STATEID sub = KOR;

	INFO* pInfo;

	printf("%s\n%d\nd\nd\n", pInfo -> Name, pInfo -> iKor, pInfo -> iEng, pInfo -> iMath);



	return 0;

	
}

INFO* createinfo()
{
	INFO* pinfo = (INFO*)malloc(sizeof(INFO));

	pinfo -> Name = setname();
	pinfo -> iKor = 10;
	pinfo -> iEng = 20;
	pinfo -> iMath = 30;


}

char* setname()
{
	char str[128] = "";
	printf("이름 : ");
	scanf_s("%s", str);//배열은 포인터 연산자로 쓸수있어서 &안붙여도됨ㅇㅇ(왜그런지 4단계에서 배움)

	char* pName = (char*)malloc(strlen(str));

	strcpy(pName, str);
	return pName;
}

//게임의 큰틀

//게임로고
//메뉴화면
//스테이지
//엔딩(종료)

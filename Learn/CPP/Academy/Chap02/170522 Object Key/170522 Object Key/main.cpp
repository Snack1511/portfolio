#include <stdio.h>
#include<string>
#include<malloc.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
//프레임워크 시작;;



const int KEY_UP		= 0x0001;
const int KEY_DOWN		= 0x0002;
const int KEY_LEFT		= 0x0004;
const int KEY_RIGHT		= 0x0008;
const int KEY_SPACE		= 0x0010;
const int KEY_RETURN	= 0x0020;//한번 입력을 하고싶은대 프로그램이 너무빨라서 중복입력이되기때문에 이걸 사용





enum OBJID
{
	OBJ_PLAYER,
	OBJ_MONSTER,
	OBJ_END,
};

enum MONSTERID{
	MON_01,
	MON_02,
	MON_03,
	MON_04,
	MON_05,
};





typedef struct tagInfo
{

	char* Name;

	int iX;
	int iY;

	int iAtt;
	int iDef;

	MONSTERID MonsterID;

}INFO;

const int MAX = 5;
int g_iIndex = 0;





INFO* CreatePlayer();
char* SetName();
INFO* CreateMonster();
int CheckKey();

int main()
{
	INFO* pObjList[OBJ_END][MAX];
	

	for(int i = 0; i < MAX; i++){
		pObjList[OBJ_MONSTER][i] = CreateMonster();
	}


	for(int i = 0; i < MAX; i++){
		printf("Name : %s\nAtt : %d\nDef : %d\nX : %d\nY : %d\n", 
			pObjList[OBJ_MONSTER][i]->Name, 
			pObjList[OBJ_MONSTER][i]->iAtt, 
			pObjList[OBJ_MONSTER][i]->iDef, 
			pObjList[OBJ_MONSTER][i]->iX, 
			pObjList[OBJ_MONSTER][i]->iY);

	}


	/*printf("Name : %s\nAtt : %d\nDef : %d\nX : %d\nY : %d\n", 
		pPlayer->Name, pPlayer->iAtt, pPlayer->iDef, pPlayer->iX, pPlayer->iY);
		*/



	while(true){

		system("cls");//화면에 있는 모든 내용을 지워준다
		

		int iKey = CheckKey();

		if(iKey&KEY_UP){
			printf("KEY_UP\n");

		}
		if(iKey&KEY_DOWN){
			printf("KEY_DOWN\n");

		}
		if(iKey&KEY_RIGHT){
			printf("KEY_RIGHT\n");

		}
		if(iKey&KEY_LEFT){
			printf("KEY_LEFT\n");

		}

	
	
	
	}






	return 0;
}


INFO* CreatePlayer()
{

	INFO* pInfo = (INFO*)malloc(sizeof(INFO));

	pInfo->Name = SetName();
	pInfo->iAtt = 10;
	pInfo->iDef = 10;
	pInfo->iX = 100;
	pInfo->iY = 100;

	return pInfo;
}

char* SetName()
{
	char str[128] = "";
	printf("이름 입력 : ");
	scanf("%s", str);

	char* pName = (char*)malloc(strlen(str));
	strcpy(pName, str);

	return pName;
}

INFO* CreateMonster()
{

	srand(time(NULL));
	INFO* pInfo = (INFO*)malloc(sizeof(INFO));
	int iId = rand()%5+1;
	switch(iId){
	case 1:
		pInfo->MonsterID = MON_01;
		break;
	case 2:
		pInfo->MonsterID = MON_02;
		break;
	case 3:
		pInfo->MonsterID = MON_03;
		break;
	case 4:
		pInfo->MonsterID = MON_04;
		break;
	case 5:
		pInfo->MonsterID = MON_05;
		break;
	}
	
	 

	switch(pInfo -> MonsterID){
	case MON_01:
		{
			pInfo->Name = "a";
			pInfo->iAtt = 20;
			pInfo->iDef = 30;
			pInfo->iX = 20;
			pInfo->iY = 30;
		}

		break;
	case MON_02:
		{
			pInfo->Name = "b";
			pInfo->iAtt = 20;
			pInfo->iDef = 30;
			pInfo->iX = 20;
			pInfo->iY = 30;
		}
		break;
	case MON_03:
		{
			pInfo->Name = "c";
			pInfo->iAtt = 20;
			pInfo->iDef = 30;
			pInfo->iX = 20;
			pInfo->iY = 30;
		}
		break;
	case MON_04:
		{
			pInfo->Name = "d";
			pInfo->iAtt = 20;
			pInfo->iDef = 30;
			pInfo->iX = 20;
			pInfo->iY = 30;
		}
		break;
	case MON_05:
		{
			pInfo->Name = "e";
			pInfo->iAtt = 20;
			pInfo->iDef = 30;
			pInfo->iX = 20;
			pInfo->iY = 30;
		}
		break;

	}

	return pInfo;
}

int CheckKey(){

	int iKey = 0;


	if(GetAsyncKeyState(VK_UP)){

		iKey|=KEY_UP;

		//printf("위\n");
	}
	if(GetAsyncKeyState(VK_DOWN)){
		iKey|=KEY_DOWN;
		//printf("아래\n");
	}
	if(GetAsyncKeyState(VK_RIGHT)){

		iKey |=KEY_RIGHT;

		//printf("오른쪽\n");
	}
	if(GetAsyncKeyState(VK_LEFT)){

		iKey |=KEY_LEFT;
		//printf("왼쪽\n");
	}

	return iKey;

}
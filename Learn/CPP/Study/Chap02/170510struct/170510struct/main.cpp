#include <stdio.h>
#include <malloc.h>


/*typedef struct tagInfo{
	
	char* Name;

	int iKor;
	int iEng;
	int iMath;

}INFO;*/

typedef struct tagInfo{

	char* Name;

	int iAtt;
	int iDef;
	int iMP;
	int iHP;

	tagInfo(){
		//기본생성자 : c에서 자동으로 제공but 복사생성자를 사용하려면 반드시 정의를 해줘야 한다
		printf("생성자\n");
		//생성 된 직후에 자동으로 호출이 되는 함수
	};


	//복사생성자 : 기본 생성자가 없으면 사용못함
	tagInfo(char* _name, int _iatt, int _idef, int _ihp, int _imp)
		: Name(_name), iAtt(_iatt), iDef(_idef), iHP(_ihp), iMP(_imp){};//아래에 주석처리한 부분과 같은내용
	/*{

		Name = _name;
		iAtt = _iatt;
		iDef = _idef;
		iMP = _imp;
		iHP = _ihp;
	};*/

}INFO;



void InitPlayer(INFO*_pInfo);
void InitMonster(INFO*_pInfo);
void Render(INFO* _pInfo);



int main(){
	//INFO* pInfo = (INFO*)malloc(sizeof(INFO));


	//Initialize(pInfo);//초기화구문

	//Render(pInfo);//출력구문

	/*INFO* pPlayer = (INFO*)malloc(sizeof(INFO));
	INFO* pMonster = (INFO*)malloc(sizeof(INFO));*/



	//printf("시작\n\n");
	//INFO Player;

	INFO Player("Player", 100, 25, 150, 20);
	INFO Monster("Monster", 100, 25, 150, 20);

	//printf("InitPlayer\n\n");
	//InitPlayer(&Player);

	//printf("Render\n\n");
	Render(&Player);
	Render(&Monster);

	

	/*Render(pPlayer);
	Render(pMonster);*/

	//printf("return\n");
	return 0;
}
/*
void Initialize(INFO*_pInfo){
	
	_pInfo->Name = "홍길동";
	_pInfo->iKor = 10;
	_pInfo->iEng = 10;
	_pInfo->iMath = 10;
}

void Render(INFO* _pInfo){
	printf("%s\n%d\n%d\n%d\n", 
		_pInfo->Name, 
		_pInfo->iKor, 
		_pInfo->iEng, 
		_pInfo->iMath);

}*/

void InitPlayer(INFO*_pInfo){
	/*
	_pInfo->Name = "Player";
	_pInfo->iAtt = 10;
	_pInfo->iDef = 10;
	_pInfo->iHP = 10;
	_pInfo->iMP = 10;
	*/

	*_pInfo = INFO("Player", 100, 25, 150, 20);//데이터에 접근해서 초기화 하기 위해 *을 붙임 * = 데이터
}

void InitMonster(INFO*_pInfo){

	_pInfo->Name = "Monster";
	_pInfo->iAtt = 10;
	_pInfo->iDef = 10;
	_pInfo->iHP = 10;
	_pInfo->iMP = 10;
}

void Render(INFO* _pInfo){
	printf("Name : %s\nAtt : %d\nDef : %d\nHp : %d\nMp : %d\n", 
		_pInfo->Name,
		_pInfo->iAtt, 
		_pInfo->iDef, 
		_pInfo->iHP, 
		_pInfo->iMP);

}
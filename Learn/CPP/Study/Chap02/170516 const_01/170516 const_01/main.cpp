#include<stdio.h>
#include<malloc.h>
#include<string.h>

//변수 : 값이 변한다
//상수 : 변하지 않음
/*
enum{//열거형 == 나열됨.
	
	//정수, 상수식

	AAA, BBB, CCC, DDD, EEE, FFF, GGG, HHH//한번설정되면 값이 바뀌지 않음
//   0    1    2    3    4    5    6    7

};
*/

typedef struct tagInfo{
	int iAtt;
	int iDef;

	int iHP;
	int iMP;

}INFO;

enum OBJID//구조체처럼 정의가 가능하다 이경우엔 typedef필요없음ㅇㅇ
{
	OBJ_PLAYER,
	OBJ_MONSTER,
	OBJ_END
};

enum
{
	OBJ_FRONT,
	OBJ_MAX = 10
};

INFO* CreatePlayer();
INFO* CreateMonster();
void Safe_Delete(INFO* _pInfo);

int main(){
	/*
	int iNum = 10;
	iNum = 30;

	int iArr[HHH];

	//(int * HHH) == 길이값
	//printf("%d\n", sizeof(int)*HHH); 결과값 : 28

	for(int i = 0; i < HHH; i++){
	
		iArr[i] = ((i*1)+1);
	}

	for(int i = 0; i < HHH; i++){
		printf("%d\n", iArr[i]);
		
	}

	printf("CCC : %d\n", iArr[CCC]);
	*/

	INFO* ObjList[OBJ_END][OBJ_MAX];
	for(int i = 0; i < OBJ_END; i++){
		for(int j = 0; j < OBJ_MAX; j++){
			ObjList[i][j] = NULL;
		}
	}

	ObjList[OBJ_PLAYER][OBJ_FRONT] = CreatePlayer();

	for(int i = 0; i < OBJ_MAX; i++){
		ObjList[OBJ_MONSTER][i] = CreateMonster();
	}
	


	/*INFO* ObjList[OBJ_END];
	OBJID objID = OBJ_PLAYER;
	ObjList[objID] = CreatePlayer();
	objID = OBJ_MONSTER;
	ObjList[objID] = CreateMonster();*/
	//위 코드와 같은결과 도출

	/*
	INFO* ObjList[OBJ_END];
	OBJID Player = OBJ_PLAYER;
	OBJID Monster = OBJ_MONSTER;
	ObjList[Player] = CreatePlayer();
	ObjList[Monster] = CreateMonster();*/
	//위 코드와 같은결과 도출

	//OBJ_PLAYER = 0
	//OBJ_MONSTER = 1
	//OBJ_END = 2

	for(int i = 0; i < OBJ_END ; i++){
		for(int j = 0; j < OBJ_MAX; j++){
			if(ObjList[i][j] != NULL){//player의 OBJ_FRONT이후로 값이 NULL값이라 넣지 않으면 에러남ㅇㅇ
				printf("iAtt : %d\niDef : %d\niHP : %d\niMP : %d\n\n\n\n", 
					ObjList[i][j]->iAtt	, 
					ObjList[i][j]->iDef	, 
					ObjList[i][j]->iHP		, 
					ObjList[i][j]->iMP		);
			}
		}

	}

	

	for(int i = 0; i < OBJ_END; i++){
		for(int j = 0; j < OBJ_MAX; j++){
			Safe_Delete(ObjList[i][j]);
		}
	}

	return 0;
}

INFO* CreatePlayer(){
	INFO* pInfo = (INFO*)malloc(sizeof(INFO));
	pInfo->iAtt = 10;
	pInfo->iDef = 20;
	pInfo->iHP = 30;
	pInfo->iMP = 40;

	return pInfo;
}

INFO* CreateMonster(){
	INFO* pInfo = (INFO*)malloc(sizeof(INFO));
	pInfo->iAtt = 20;
	pInfo->iDef = 40;
	pInfo->iHP = 60;
	pInfo->iMP = 80;

	return pInfo;
}

void Safe_Delete(INFO* _pInfo){
	if(_pInfo != NULL){
		free(_pInfo);
		_pInfo = NULL;
	}
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>

//int Add(int _i, int _n);



int WINSIZEX = 1270;
int WINSIZEY = 720;
//보통 이렇게 윈도우 사이즈를 정해놓고 시작한다

typedef struct tagInfo{
	int iAtt;
	int iDef;
	int iGold;
	
	
	int iHp;
	int iMp;
	int iExp;
	
	int iMAX_exp;
	int iMAX_mp;
	int iMAX_hp;
	/*int iKor;
	int iMath;
	int iEng;*/

	tagInfo(){};
	tagInfo(int _iAtt, int _iDef, int _iGold, int _iHp,int _iMp,int _iExp, int _iMAX_exp,int _iMAX_mp,int _iMAX_hp) : iAtt(_iAtt),
					iDef(_iDef),
					iGold(_iGold),


					iHp(_iHp),
					iMp(_iMp),
					iExp(_iExp),

					iMAX_exp(_iMAX_exp),
					iMAX_mp(_iMAX_mp),

					iMAX_hp(_iMAX_hp){
						_iMAX_exp = 30;
						_iMAX_hp = 15;
						_iMAX_mp = 10;
	};

}INFO;

INFO* CreatePlayer();
INFO* CreateMonster();
void initPlayer(INFO* _pinfo);

int main(){

	srand(time(NULL));

	//int iResult = Add(10, 20);
	
	// 이렇게 바로 초기화 할수 있었다.
	

	/*
	INFO Player;
	INFO Monster;
	
	Player.iX = rand()%WINSIZEX;
	Player.iY = rand()%WINSIZEY;

	Monster.iX = rand()%WINSIZEX;
	Monster.iY = rand()%WINSIZEY;

	int iResult = Add(Player.iX, Player.iY);


	printf("%d\n", iResult);

	printf("%d\n", Add(Monster.iX, Monster.iY));
	*/


	/*INFO* Player = (INFO*)malloc(sizeof(INFO));
	*Player = INFO(rand()%WINSIZEX, rand()%WINSIZEY);
	*/

	//INFO* Monster[10];
	
	//for(int i = 0; i < 10; i++){

	//	*Monster[i]= (INFO*)malloc(sizeof(INFO));
	//	*Monster[i] = INFO(rand()%WINSIZEX, rand()%WINSIZEY);
	//	

		//되는 코드이긴 하지만 귀찮고 또 길이가 길어지므로 비추
	//}



	INFO* Player = CreatePlayer();

	//INFO* Monster[10];
	/*for(int i = 0; i < 10; i++){
		Monster[i]= CreateMonster();
	}*/

	
	
	


	printf("%d, %d, %d\n", Player->iKor, Player->iMath, Player->iEng);





	return 0;
}

/*
int Add(int _i, int _n){

	return _i + _n;
}*/

INFO* CreatePlayer(){

	INFO* info = (INFO*)malloc(sizeof(INFO));

	initPlayer(info);

	return info;
}

void initPlayer(INFO* _pinfo){
	*_pinfo = INFO(rand()%WINSIZEX, rand()%WINSIZEY, rand()%WINSIZEX);
}

/*INFO* CreateMonster(){

	INFO* info = (INFO*)malloc(sizeof(INFO));

	*info = INFO(rand()%WINSIZEX, rand()%WINSIZEY);

	return info;
}*/
#pragma warning(disable : 4996)


#include "Include.h"





const int MAX = 5;
STATEID g_eState;
char* Logo[10];

const int StarMax = 100;
INFO* BackGround[StarMax];

INFO* g_tLogo;
DIR g_eDirLogo;

INFO* g_tMenu[2];
INFO* g_tCursor[2];
int CursorIndex_State;
int CursorIndex_Stat;

SCENEID g_eScene;
INFO* g_tVillageSellect[2];
INFO* g_tStoreSellect[2];
INFO* g_tDungeonSellect[2];

INFO* g_tStateSellect[4];

INFO* RenderCharacter;

STATEMENTID g_eStat;



STAT* CreatePlayer();
void InitPlayer(STAT* _pinfo);
STAT* CreateMonster();
void InitMonster(STAT* _pinfo);
char* SetName();
void SetState(STAT* _player, STAT* _monster[]);

void InitLogo();
INFO* CreateBackGround(int _i);
void LogoProgress();
void LogoRender();

void InitMenu();
void MenuProgress();
void MenuRender();

void InitRenderCharacter();
void InitStage();
void StageRender(STAT* _player, STAT* _monster[]);
void StageProgress(STAT* _player, STAT* _monster[]);

void InitVillage();
void VillageProgress(STAT* _player);
void VillageRender(STAT* _player);

void InitStore();
void StoreProgress(STAT* _player);
void StoreRender(STAT* _player);

void InitDungeon();
void DungeonProgress(STAT* _player, STAT* _monster[]);
void DungeonRender(STAT* _player, STAT* _monster[]);

void InitStateMenu();
void StateMenuProgress(STAT* _player);
void StateMenuRender(STAT* _player);

void CheckStat(STAT* _player);
void CheckEquip(STAT* _player);
void CheckInven(STAT* _player);
void CheckExit();


void SetCursorHandle();	// 커서를 숨겨줌.
void SetCursorPosition(int _ix, int _iy);	// 커서 이동
void SetTextColor(int _index);	// 색갈을 바꿔줌.

int CompareKey();



int main()
{
	SetCursorHandle();
	srand(GetTickCount());
	STAT* pPlayer = CreatePlayer();
	STAT* pMonster[MAX];
	//InitRenderCharacter(RenderCharacter);

	for(int i = 0 ; i < MAX ; i++)
	{
		pMonster[i] = CreateMonster();
	}
	
	g_eState = IDS_LOGO;
	InitLogo();
	DWORD dwTime = GetTickCount();

	while(true)
	{
		if(dwTime + 50 < GetTickCount())
		{
			dwTime = GetTickCount();
			system("cls");

			SetState(pPlayer, pMonster);

			
		}
	}

	return 0;
}


STAT* CreatePlayer()
{
	STAT* pInfo = (STAT*)malloc(sizeof(STAT));
	InitPlayer(pInfo);

	return pInfo;
}

void InitPlayer(STAT* _pinfo)
{
	_pinfo->CName = SetName();

	_pinfo->iLv = 1;
	_pinfo->iExp = 0;
	_pinfo->iAtt = 10;
	_pinfo->iDef = 10;
}

STAT* CreateMonster()
{
	STAT* pInfo = (STAT*)malloc(sizeof(STAT));
	InitMonster(pInfo);

	return pInfo;
}

void InitMonster(STAT* _pinfo)
{
	_pinfo->CName = "Monster";
	_pinfo->iLv = 10;
	_pinfo->iExp = 10;
	_pinfo->iAtt = 2;
	_pinfo->iDef = 2;

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



void SetState(STAT* _player, STAT* _monster[])
{
	int iKey = CompareKey();

	switch(g_eState)
	{
	case IDS_LOGO:
		LogoProgress();
		LogoRender();
		break;
	case IDS_MENU:
		MenuProgress();
		MenuRender();

		if(iKey & KEY_F1)
		{
			g_eState = IDS_STAGE;
		}
		break;
	case IDS_STAGE:
		//printf("IDS_STAGE\n");
		StageProgress(_player, _monster);
		StageRender(_player, _monster);

		if(iKey & KEY_F1)
		{
			g_eState = IDS_LOGO;
		}
		if (GetAsyncKeyState(VK_BACK)) 
		{
			StateMenuProgress(_player);
			StateMenuRender(_player);
		}
		break;
	}
}

//로고
void InitLogo()
{
	g_tLogo = (INFO*)malloc(sizeof(INFO));
	g_tLogo->iX = 10;
	g_tLogo->iY = 10;
	g_tLogo->Name = "";
	g_eDirLogo = DIR_DOWN;

	Logo[0] = "8 8888         ,o888888o.         ,o888888o.        ,o888888o."		;
	Logo[1] = "8 8888      . 8888     `88.      8888     `88.   . 8888     `88."	;
	Logo[2] = "8 8888     ,8 8888       `8b  ,8 8888       `8. ,8 8888       `8b"	;
	Logo[3] = "8 8888     88 8888        `8b 88 8888           88 8888        `8b"	;
	Logo[4] = "8 8888     88 8888         88 88 8888           88 8888         88"	;
	Logo[5] = "8 8888     88 8888         88 88 8888           88 8888         88"	;
	Logo[6] = "8 8888     88 8888        ,8P 88 8888   8888888 88 8888        ,8P"	;
	Logo[7] = "8 8888     `8 8888       ,8P  `8 8888       .8' `8 8888       ,8P"	;
	Logo[8] = "8 8888      ` 8888     ,88'      8888     ,88'   ` 8888     ,88'"	;
	Logo[9] = "8 888888888888 `8888888P'         `8888888P'        `8888888P'"		;

	for(int i = 0 ; i < 100 ; i++)
	{
		BackGround[i] = CreateBackGround(i * GetTickCount());
	}
}
INFO* CreateBackGround(int _i)
{
	INFO* BackGround = (INFO*)malloc(sizeof(INFO));
	BackGround->Name = ".";

	srand(_i + GetTickCount() * GetTickCount() + _i);
	BackGround->iX = rand()%120 + 1;
	srand(_i + GetTickCount() * GetTickCount() + _i + BackGround->iX);
	BackGround->iY = rand()%30 + 1;

	return BackGround;
}
void LogoProgress()
{
	int iKey = CompareKey();
	if(g_tLogo->iY == 3)
	{
		g_eDirLogo = DIR_DOWN;
	}
	if(g_tLogo->iY == 10)
	{
		g_eDirLogo = DIR_UP;
	}

	for(int i = 0 ; i < StarMax ; i++)
	{
		BackGround[i]->iX--;

		if(BackGround[i]->iX <= 1)
		{
			BackGround[i]->iX = 120;
			BackGround[i]->iY = rand()%30+1;
		}
	}

	if(g_eDirLogo == DIR_UP)
	{
		g_tLogo->iY--;
	}
	else
	{
		g_tLogo->iY++;
	}

	if(iKey & KEY_SPACE)
	{
		InitMenu();
		g_eState = IDS_MENU;
	}
}
void LogoRender()
{
	for(int i = 0 ; i < StarMax ; i++)
	{
		SetTextColor(rand()%9 + 6);
		SetCursorPosition(BackGround[i]->iX, BackGround[i]->iY);
		printf("%s", BackGround[i]->Name);
	}

	for(int i = 0 ; i < 10 ; i++)
	{
		SetTextColor(연한빨간색);
		SetCursorPosition(g_tLogo->iX, g_tLogo->iY + i);
		printf("%s", Logo[i]);
	}
}

//메뉴
void InitMenu()
{

	
	g_tCursor[0] = (INFO*)malloc(sizeof(INFO));
	for(int i = 0 ; i < 2 ; i++)
		g_tMenu[i] = (INFO*)malloc(sizeof(INFO));

	g_tMenu[0]->iX = 45;
	g_tMenu[0]->iY = 20;
	g_tMenu[0]->Name = "START";

	g_tMenu[1]->iX = 45;
	g_tMenu[1]->iY = 21;
	g_tMenu[1]->Name = "EXIT";


	g_tCursor[0]->iX = g_tMenu[0]->iX - 5;
	g_tCursor[0]->iY = g_tMenu[0]->iY;
	g_tCursor[0]->Name = "▶";
}
void MenuProgress()
{
	int iKey = CompareKey();
	if(iKey & KEY_UP)
	{
		g_tCursor[0]->iY = g_tMenu[0]->iY;
		CursorIndex_State = 0;
	}
	if(iKey & KEY_DOWN)
	{
		g_tCursor[0]->iY = g_tMenu[1]->iY;
		CursorIndex_State = 1;
	}

	switch(CursorIndex_State)
	{
	case 0:
		{
			if(iKey & KEY_SPACE)
			{
				InitStage();
				InitStateMenu();
				g_eState = IDS_STAGE;
			}
		}
		break;
	case 1:
		{
			if(iKey & KEY_SPACE)
				exit(NULL);
		}
		break;
	}
}
void MenuRender()
{
	SetTextColor(연한초록색);
	SetCursorPosition(g_tMenu[0]->iX, g_tMenu[0]->iY);
	printf("%s", g_tMenu[0]->Name);

	SetTextColor(연한빨간색);
	SetCursorPosition(g_tMenu[1]->iX, g_tMenu[1]->iY);
	printf("%s", g_tMenu[1]->Name);

	SetTextColor(연한빨간색);
	SetCursorPosition(g_tCursor[0]->iX, g_tCursor[0]->iY);
	printf("%s", g_tCursor[0]->Name);
}

void InitRenderCharacter()
{
	RenderCharacter = (INFO*)malloc(sizeof(INFO));
	RenderCharacter->Name = "■";
	RenderCharacter->iX = 60;
	RenderCharacter->iY = 15;

	
}

//stage부분
void InitStage()
{
	g_eScene = SCENE_VILLAGE;
	InitVillage();
	InitStore();
	InitDungeon();
}
void StageRender(STAT* _player, STAT* _monster[])
{
	switch(g_eScene)
	{
	case SCENE_VILLAGE:
		VillageRender(_player);
		break;

	case SCENE_STORE:
		StoreRender(_player);
		break;

	case SCENE_DUNGEON:
		DungeonRender(_player, _monster);
		break;

	}
}
void StageProgress(STAT* _player, STAT* _monster[])
{
	switch(g_eScene)
	{
	case SCENE_VILLAGE:
		VillageProgress(_player);
		break;

	case SCENE_STORE:
		StoreProgress(_player);
		break;

	case SCENE_DUNGEON:
		DungeonProgress(_player, _monster);
		break;

	}
	

	
}

//stage-village
void InitVillage()
{
	InitRenderCharacter();
}
void VillageProgress(STAT* _player)
{
	int iKey = CompareKey();
	CursorIndex_State = 0;
	if (RenderCharacter->iY > 0) 
	{
		if (iKey & KEY_UP)
		{
			RenderCharacter->iY--;
		}
		if (RenderCharacter->iY < 2)
		{
			CursorIndex_State = 1;
			RenderCharacter->iY = 25;
		}
	}
	if (RenderCharacter->iY < 29)
	{
		if (iKey & KEY_DOWN)
		{
			RenderCharacter->iY++;
		}
	}
	if (RenderCharacter->iX < 116)
	{
		if (iKey & KEY_RIGHT)
		{
			RenderCharacter->iX += 2;
		}
		if (RenderCharacter->iX > 115)
		{
			CursorIndex_State = 2;
			RenderCharacter->iX = 5;
		}
	}
	if (RenderCharacter->iX > 2)
	{
		if (iKey & KEY_LEFT)
		{
			RenderCharacter->iX -= 2;
		}
	}

	switch(CursorIndex_State)
	{
	case 1:
		{
			
			g_eScene = SCENE_STORE;
		}
		break;
	case 2:
		{
			g_eScene = SCENE_DUNGEON;
		}
		break;
	}
}
void VillageRender(STAT* _player)
{
	SetTextColor(연한초록색);
	printf("Village\n");

	SetTextColor(연한옥색);
	SetCursorPosition(RenderCharacter->iX, RenderCharacter->iY);
	printf("%s", RenderCharacter->Name);

}

//stage-store
void InitStore()
{
	
}
void StoreProgress(STAT* _player)
{
	int iKey = CompareKey();

	CursorIndex_State = 0;
	if (RenderCharacter->iY > 0)
	{
		if (iKey & KEY_UP)
		{
			RenderCharacter->iY--;
		}
		
	}
	if (RenderCharacter->iY < 29)
	{
		if (iKey & KEY_DOWN)
		{
			RenderCharacter->iY++;
		}
		if (RenderCharacter->iY > 27)
		{
			CursorIndex_State = 1;
			RenderCharacter->iY = 5;
		}
	}
	if (RenderCharacter->iX < 116)
	{
		if (iKey & KEY_RIGHT)
		{
			RenderCharacter->iX += 2;
		}
	}
	if (RenderCharacter->iX > 2)
	{
		if (iKey & KEY_LEFT)
		{
			RenderCharacter->iX -= 2;
		}
	}

	switch (CursorIndex_State)
	{
	case 1:
	{

		g_eScene = SCENE_VILLAGE;
	}
	break;
	}
}
void StoreRender(STAT* _player)
{
	SetTextColor(연한파란색);
	printf("Store\n");

	SetTextColor(연한옥색);
	SetCursorPosition(RenderCharacter->iX, RenderCharacter->iY);
	printf("%s", RenderCharacter->Name);
}

//stage-Dungeon
void InitDungeon()
{
	
}
void DungeonProgress(STAT* _player, STAT* _monster[])
{


	int iKey = CompareKey();

	CursorIndex_State = 0;
	if (RenderCharacter->iY > 0)
	{
		if (iKey & KEY_UP)
		{
			RenderCharacter->iY--;
		}

	}
	if (RenderCharacter->iY < 29)
	{
		if (iKey & KEY_DOWN)
		{
			RenderCharacter->iY++;
		}
		
	}
	if (RenderCharacter->iX < 116)
	{
		if (iKey & KEY_RIGHT)
		{
			RenderCharacter->iX += 2;
		}
		
	}
	if (RenderCharacter->iX > 2)
	{
		if (iKey & KEY_LEFT)
		{
			RenderCharacter->iX -= 2;
		}
		if (RenderCharacter->iX < 3)
		{
			CursorIndex_State = 1;
			RenderCharacter->iX = 110;
		}
	}

	switch (CursorIndex_State)
	{
	case 1:
	{

		g_eScene = SCENE_VILLAGE;
	}
	break;
	
	}
}
void DungeonRender(STAT* _player, STAT* _monster[])
{
	SetTextColor(연한빨간색);
	printf("Dungeon\n");

	SetTextColor(연한옥색);
	SetCursorPosition(RenderCharacter->iX, RenderCharacter->iY);
	printf("%s", RenderCharacter->Name);
}

/*void FightProgress(STAT* _player, STAT* _monster[]) 
{
	if (_player->iAtt > _monster[0]->iDef && _player->iDef > _monster[0]->iAtt) {
		_player->iExp += _monster[0]->iExp;
	}
	else 
}*/


//statemenu
void InitStateMenu()
{
	g_tCursor[1] = (INFO*)malloc(sizeof(INFO));
	for(int i = 0 ; i < 4 ; i++)
		g_tStateSellect[i] = (INFO*)malloc(sizeof(INFO));

	g_tStateSellect[0]->iX = 5;
	g_tStateSellect[0]->iY = 10;
	g_tStateSellect[0]->Name = "Stat";

	g_tStateSellect[1]->iX = 5;
	g_tStateSellect[1]->iY = 11;
	g_tStateSellect[1]->Name = "Equip";

	g_tStateSellect[2]->iX = 5;
	g_tStateSellect[2]->iY = 12;
	g_tStateSellect[2]->Name = "Inven";

	g_tStateSellect[3]->iX = 5;
	g_tStateSellect[3]->iY = 13;
	g_tStateSellect[3]->Name = "Exit";



	g_tCursor[1]->iX = g_tStateSellect[0]->iX - 5;
	g_tCursor[1]->iY = g_tStateSellect[0]->iY;
	g_tCursor[1]->Name = "▶";
	g_eStat = STAT_NULL;
}
void StateMenuProgress(STAT* _player)
{
	int iKey = CompareKey();
	if(iKey & KEY_UP)
	{
		g_tCursor[1]->iY--;
		CursorIndex_Stat--;
		if (CursorIndex_Stat <= 0)
		{
			g_tCursor[1]->iY = g_tStateSellect[0]->iY;
			CursorIndex_Stat = 0;
		}
		
	}
	if (iKey & KEY_DOWN)
	{
		g_tCursor[1]->iY++;
		CursorIndex_Stat++;
		if (CursorIndex_Stat > 3)
		{
			g_tCursor[1]->iY = g_tStateSellect[3]->iY;
			CursorIndex_Stat = 3;

		}
		
	}


	switch(CursorIndex_Stat)
	{
	case 0:
		{
			if(iKey & KEY_SPACE)
			{
				g_eStat = STAT_STAT;
			}
		}
		break;
	case 1:
		{
			if(iKey & KEY_SPACE)
			{
				g_eStat = STAT_EQUIP;
			}
		}
		break;
	case 2:
		{
			if(iKey & KEY_SPACE)
			{
				g_eStat = STAT_INVEN;
			}
		}
		break;
	case 3:
		{
			if(iKey & KEY_SPACE)
			{
				g_eStat = STAT_EXIT;
			}
		}
		break;
	}

	switch(g_eStat)
	{
	case STAT_STAT:
		CheckStat(_player);
		break;

	case STAT_EQUIP:
		//MenuEquipProgress(_player);
		CheckEquip(_player);
		break;

	case STAT_INVEN:
		CheckInven(_player);
		break;

	case STAT_EXIT:
		CheckExit();
		break;
	

	}
}
void StateMenuRender(STAT* _player)
{
	SetTextColor(연한빨간색);
	SetCursorPosition(g_tStateSellect[0]->iX, g_tStateSellect[0]->iY - 5);
	printf("State\n");

	SetTextColor(연한초록색);
	SetCursorPosition(g_tStateSellect[0]->iX, g_tStateSellect[0]->iY);
	printf("%s", g_tStateSellect[0]->Name);

	SetTextColor(연한옥색);
	SetCursorPosition(g_tStateSellect[1]->iX, g_tStateSellect[1]->iY);
	printf("%s", g_tStateSellect[1]->Name);

	SetTextColor(연한자주색);
	SetCursorPosition(g_tStateSellect[2]->iX, g_tStateSellect[2]->iY);
	printf("%s", g_tStateSellect[2]->Name);
	
	SetTextColor(진한흰색);
	SetCursorPosition(g_tStateSellect[3]->iX, g_tStateSellect[3]->iY);
	printf("%s", g_tStateSellect[3]->Name);

	SetTextColor(연한파란색);
	SetCursorPosition(g_tCursor[1]->iX, g_tCursor[1]->iY);
	printf("%s", g_tCursor[1]->Name);
}

void CheckStat(STAT* _player) 
{
	SetCursorPosition(RenderCharacter->iX+10, RenderCharacter->iY);
	printf("stat");

	SetTextColor(진한흰색);
	SetCursorPosition(RenderCharacter->iX + 10, RenderCharacter->iY+3);
	printf("LV : %d", _player->iLv);
	SetCursorPosition(RenderCharacter->iX + 10, RenderCharacter->iY+4);
	printf("Exp : %d", _player->iExp);
	SetCursorPosition(RenderCharacter->iX + 10, RenderCharacter->iY+5);
	printf("iAtt : %d", _player->iAtt);
	SetCursorPosition(RenderCharacter->iX + 10, RenderCharacter->iY+6);
	printf("Def : %d", _player->iDef);
}

void CheckEquip(STAT* _player)
{
	SetCursorPosition(RenderCharacter->iX + 10, RenderCharacter->iY);
	printf("Equip");
}

void CheckInven(STAT* _player)
{
	SetCursorPosition(RenderCharacter->iX + 10, RenderCharacter->iY);
	printf("Inven");
}

void CheckExit()
{
	system("cls");
	exit(NULL);
}



//커서
void SetCursorHandle()
{	
	HANDLE HCursor = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO Info;
	Info.dwSize = 100;
	Info.bVisible = FALSE;
	SetConsoleCursorInfo(HCursor, &Info);
}
void SetCursorPosition(int _ix, int _iy)
{
	COORD Pos;
	Pos.X = _ix;
	Pos.Y = _iy;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//색깔
void SetTextColor(int _index)
{
	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), _index);
}


int CompareKey()
{
	int iKey = 0;

	if(GetAsyncKeyState(VK_SPACE))
	{
		iKey |= KEY_SPACE;
	}
	if(GetAsyncKeyState(VK_RETURN))
	{
		iKey |= KEY_RETURN;
	}
	if(GetAsyncKeyState(VK_F1))
	{
		iKey |= KEY_F1;
	}
	if(GetAsyncKeyState(VK_UP))
	{
		iKey |= KEY_UP;
	}
	if(GetAsyncKeyState(VK_DOWN))
	{
		iKey |= KEY_DOWN;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		iKey |= KEY_RIGHT;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		iKey |= KEY_LEFT;
	}
	return iKey;
}






//해야할것

//캐릭터 스탯확인
//배틀씬
//마을 이벤트
//엔딩

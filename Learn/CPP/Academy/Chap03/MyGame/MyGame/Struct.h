#pragma once
#include"Value.h"

typedef struct tagState
{
	int iAtt;
	int iDef;

	int iHP;
	int iMP;
	int iEXP;

	int iMAX_HP;
	int iMAX_MP;
	int iMAX_EXP;

	int iGold;
	

}STATE;
typedef struct mycharcater 
{
	int iSpeed;
	int iJump;
	int iLife;
	int iScore;

	int iMAX_Speed;
	int iMAX_Jump;
	
}CHARACTER;
typedef struct tagInfo 
{
	char * str;

	int iX;
	int iY;
	int iCX;
	int iCY;

	STATE* tState;
	CHARACTER* tCharacter;

	bool bCheck;

	tagInfo() {};

	tagInfo(int _ix, int _iy) : iX(_ix), iY(_iy) {};

	tagInfo(int _ix, int _iy, int _icx, int _icy) 
		: iX(_ix), iY(_iy), iCX(_icx), iCY(_icy) {};
}INFO;

typedef struct tagTile 
{
	char* str;

	int iX;
	int iY;

	int iOption;

	tagTile() {};
	tagTile(int _ix, int _iy) : iX(_ix), iY(_iy) {};

	tagTile(char* _str, int _ix, int _iy, int _option)
		:str(_str), iX(_ix), iY(_iy), iOption(_option) {};
}TILE;
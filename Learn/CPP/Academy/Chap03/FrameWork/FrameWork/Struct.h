#pragma once
#include "Value.h"

typedef struct tagInfo
{
	int iLife;
	int iJump;
	int iSpeed;

	int iScore;

	int iMAX_Life;
	int iMAX_Jump;
	int iMAX_Speed;


	int iX;
	int iY;
	int iCX;
	int iCY;
	tagInfo() {};

	tagInfo(int _ix, int _iy)
		: iX(_ix), iY(_iy) {}; 

	tagInfo(int _ilife, int _ijump, int _ispeed, int _imaxlife, int _imaxjump, int _imaxspeed)
		:iLife(_ilife), iJump(_ijump), iSpeed(_ispeed), iMAX_Life(_imaxlife), iMAX_Jump(_imaxjump), iMAX_Speed(_imaxspeed){};

	tagInfo(int _ix, int _iy, int _icx, int _icy)
		: iX(_ix), iY(_iy), iCX(_icx), iCY(_icy) {}; 

}INFO;

typedef struct tagTile
{
	int iX;
	int iY;
	char* str;
	int iOption;

	tagTile() {};
	tagTile(int _ix, int _iy, char* _str) : iX(_ix), iY(_iy), str(_str) {}; 

}TILE;

typedef struct tagObjSize
{

	int iX[PLAYERSIZE];
	int iMonster_SX[MONSTERSIZE_S];
	int iBullet_X[BULLETSIZE];

	int iY;

}OBJSIZE;


typedef struct tagBullet
{
	char* str;
	int iX;
	int iY;
	int iSizeX;
	int iSizeY;
	bool bCheck;

}BULLET;

typedef struct tagMonster
{
	char* str;
	int iX;
	int iY;
	int iSizeX;
	int iSizeY;
	bool bCheck;

}MONSTER;

typedef struct tagIntPointer
{
	int num;
}INTPOINTER;

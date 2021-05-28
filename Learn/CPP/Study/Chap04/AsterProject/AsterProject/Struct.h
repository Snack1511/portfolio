#pragma once
#include "Value.h"

typedef struct tagTile
{
	char* str[TILEMAX];
	int iX;
	int iY;
	int iCX;
	int iCY;

	int iIndex;
	int iCost;
	int iOption;

}TILE;

typedef struct tagInfo
{
	char* str;
	int iX;
	int iY;
	int iCX;
	int iCY;

}INFO;

typedef struct tagNode
{
	int iCost;
	int iIndex;
	tagNode* pParent;

}NODE;

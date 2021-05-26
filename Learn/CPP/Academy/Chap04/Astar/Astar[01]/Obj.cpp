#include "Obj.h"
#include "BackGround.h"

CObj::CObj(void)
{
}


CObj::~CObj(void)
{
}

int CObj::GetTileIndex(INFO iPos)
{
	int iX = (int)(iPos.iX/TileSizeX);
	int iY = (int)(iPos.iY/TileSizeY);
	int iResult = iY * TileCntX + iX;

	return iResult;
}

bool CObj::CollisionToTile(INFO sCurPos, const TILE* pTileInfo) 
{
	if (sCurPos.iX > pTileInfo->iX - TileSizeX &&		// Rectangle(사각형) 충돌과 같은 방식으로 충돌을 측정한다.
		sCurPos.iX < pTileInfo->iX + TileSizeX &&		// 현제의 마우스 좌표가 사각형의 왼쪽 상단 꼭지점과 
		sCurPos.iY > pTileInfo->iY - TileSizeY &&		// 오른쪽 하단 꼭지점 안에 위치한다면 true를 반환한다.
		sCurPos.iY < pTileInfo->iY + TileSizeY)
	{
		return true;
	}
	return false;
}
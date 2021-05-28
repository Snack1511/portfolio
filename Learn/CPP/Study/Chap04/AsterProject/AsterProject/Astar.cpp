#include "Astar.h"
#include"ObjMgr.h"

Astar::Astar()
{
}


Astar::~Astar()
{
}

void Astar::AStarStar(int& iStartIdx, int& iGoalIdx) 
{
	if (iStartIdx == iGoalIdx) //iStartIdx와 iGoalIdx의 값이 같다면 return
	{
		return;
	}

	const vector<TILE*>*pVecTile = GET_SINGLE(CObjMgr)->getTileInfo();

}
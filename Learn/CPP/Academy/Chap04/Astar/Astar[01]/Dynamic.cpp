#include "Dynamic.h"
#include "AStar.h"
#include "ObjMgr.h"

CDynamic::CDynamic(void)
{
}


CDynamic::~CDynamic(void)
{
}

void CDynamic::AStar_Start(INFO sDestPos, INFO sSourPos)	// Sour, 즉 갈수 있는지 없는지 확인 할 필요가 없기때문에 유통기한이 지난 위치 좌표점.
{															
	int iStartIdx = GetTileIndex(sDestPos);		// 각 타일의 위치를 int 값으로 지정한다. 함수의 매게변수에 우선 sDestPos을 더한다. F12를 눌러 함수를 따라가본다.
	if (iStartIdx < 0)							// 인덱스 값이 0 이하라면 존제하지 않는 벡터 인덱스.
		return;									// return;

	int iGoalIdx = GetTileIndex(sSourPos);		// 위와 같은 방식으로 현제 플레이어가 위치한 sSourPos의 타일의 인덱스값 또한 찾는다. 
	if (iGoalIdx < 0)
		return;

	GET_SINGLE(AStar)->AStarStart(iStartIdx, iGoalIdx);		// 인덱스값은 int값이다. 두 int값을 매게변수로 하여 CAStar클래스의 AStarStart함수를 실행. F12로 함수를 따라가본다.
}


void CDynamic::AStar_Move(const CObj* pTemp)
{
	list<int>* pBestList = GET_SINGLE(AStar)->GetBestList();	//AStar의 m_BestList를 pBestList에 대입한다.

	if (pBestList->empty())
		return;

	pVecTile = GET_SINGLE(CObjMgr)->GetTileInfo();
	
	m_iDestIdx = pBestList->front();

	
	CObj** pObj = GET_SINGLE(CObjMgr)->GetCursor();

	(*pObj)->SetPos((*pVecTile)[m_iDestIdx]->iX + 2, (*pVecTile)[m_iDestIdx]->iY + 1);

	GET_SINGLE(CObjMgr)->SetCursor((*pObj));

	if((*pVecTile)[m_iDestIdx]->iX + 2 == (*pObj)->GetInfo().iX && (*pVecTile)[m_iDestIdx]->iY + 1 == (*pObj)->GetInfo().iY)
		pBestList->pop_front();
}
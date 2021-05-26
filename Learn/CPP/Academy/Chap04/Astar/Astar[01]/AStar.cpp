#include "AStar.h"
#include "ObjMgr.h"

AStar::AStar(void)
{
}


AStar::~AStar(void)
{
}

void AStar::AStarStart(int& iStartIdx, int& iGoalIdx)
{
	if (iStartIdx == iGoalIdx)		// if iStartIdx 와 iGoalIdx 의 값이 같다면 return. 플레이어 현위치를 클릭하였다면 이 조건이 성립할 것이다.
		return;
	
	const vector<TILE*>* pVecTile = GET_SINGLE(CObjMgr)->GetTileInfo();	//AStar의 벡터변수 pVecTile에 CStageBack의 타일벡터들을 추가한다.
	
	if (pVecTile == NULL)								// pVecTile에 타일값들이 추가 되지 않았다면 Error Message를 실행한 뒤 return;
	{
		ERR_MSG("AStar Tile Missing");		
		return;											// 타일 또한 결국 구조체이다. Struct 헤더의 tagTile 구조체를 확인해본다.
	}												 	// tagTile에는 fX, fY 좌표값, fCX, fCY 크기값, 그리고 iOption 과 iDrawID가 있는데
													 	// 여기서 iOption 값은 타일의 접근 가능성 여부를 1 과 0으로 분류하여 놓은 int 변수이다.	
	if ((*pVecTile)[iGoalIdx]->iOption == 1)			// 1 갈수 없는 곳 0 갈수 있는 곳
		return;										 	// 그리고 벡터의 값이 1이라면 return;

	Release();	// 새로운 Route, 길을 만들기 전 혹시나 저장되있을 값들을 지워준다.								
												
	m_iStartIdx = iStartIdx;		// int 값들을 맴버변수로 저장.
	m_iGoalIdx = iGoalIdx;

	MakeRoute();					// MakeRoute(); 길을 만든다.
}


void AStar::MakeRoute(void)
{
	NODE* pParent = new NODE;			// Struct헤더의 NODE 구조체를 확인해본다.
	pParent->iIndex = m_iStartIdx;
	pParent->pParent = NULL;
	pParent->iCost = 0;
	m_CloseList.push_back(pParent);

	const vector<TILE*>* pVecTile = GET_SINGLE(CObjMgr)->GetTileInfo();	//AStar의 벡터변수 pVecTile에 CStageBack의 타일벡터들을 추가한다.

	if (pVecTile == NULL)				// pVecTile에 타일값들이 추가 되지 않았다면 Error Message를 실행한 뒤 return;
	{
		CDoubleBuffer::GetInst()->WriteBuffer(0, 10, "AStar::MakeRoute, 46. [pVecTile] Error");
		return;
	}

	NODE* pNode = NULL;
	int iIndex = 0;
	int iCnt = 0;

	while (true)									// while문에서 route가 만들어진다.
	{												// 조사할 위치의 주변의 상, 하, 좌, 우 (주석 해지시 8방향)의 타일 값들을 조사한다.
		//90		if 의 조건들을 만족할시... 
		iIndex = pParent->iIndex - TileCntX;			// 타일들은 규칙적으로 배열되있기 때문에 인덱스 값에서 지정된 수를 빼면 원하는 방향으로 한칸 이동한 타일인덱스 값을 찾을 수있다.
		if (pParent->iIndex >= TileCntX * 2 &&			// Windows 밖에로는 타일이 존재하지 않기 때문에 검사 대상에서 제외.
			(*pVecTile)[iIndex]->iOption == 0 &&		// iOption = 갈수 있는곳인지 못가는 곳인지 확인. 
			CheckList(iIndex))							// CheckList 함수 내부에서 이미 검사를 진행 했던 타일을 검색한다. 이미 검색한 타일이면 검사 대상에서 제외.
		{
			pNode = MakeNode(iIndex, pParent, pVecTile);	// MakeNode함수를 실행. F12로 함수를 따라가본다.
			m_OpenList.push_back(pNode);					// 그리고 OpenList에 생성된 Node를 추가한다.
		}

		/*
		//45
		iIndex = pParent->iIndex - 39;
		if( pParent->iIndex >= TileCntX && 
			pParent->iIndex % (TileCntX *2) != (TileCntX * 2) -1 && 
			(*pVecTile)[iIndex]->iOption == 0 && 
			CheckList(iIndex))
		{
			pNode = MakeNode(iIndex, pParent, pVecTile);
			m_OpenList.push_back(pNode);
		}
		*/

		//0
		iIndex = pParent->iIndex +1;
		if( pParent->iIndex >= TileCntX && 
			pParent->iIndex % (TileCntX) != (TileCntX) -1 && 
			(*pVecTile)[iIndex]->iOption == 0 && 
			CheckList(iIndex))
		{
			pNode = MakeNode(iIndex, pParent, pVecTile);
			m_OpenList.push_back(pNode);
		}

		/*
		//315
		iIndex = pParent->iIndex + 41;
		if( pParent->iIndex < (TileCntX * TileCntY) - TileCntX && 
			pParent->iIndex % (TileCntX *2) != (TileCntX * 2) -1 && 
			(*pVecTile)[iIndex]->iOption == 0 && 
			CheckList(iIndex))
		{
			pNode = MakeNode(iIndex, pParent, pVecTile);
			m_OpenList.push_back(pNode);
		}
		*/

		//270
		iIndex = pParent->iIndex + TileCntX;
		if( pParent->iIndex < (TileCntX * TileCntY) - TileCntX && 
			(*pVecTile)[iIndex]->iOption == 0 && 
			CheckList(iIndex))
		{
			pNode = MakeNode(iIndex, pParent, pVecTile);
			m_OpenList.push_back(pNode);
		}

		/*
		//225
		iIndex = pParent->iIndex + 39;
		if( pParent->iIndex < (TileCntX * TileCntY) - TileCntX && 
			pParent->iIndex % (TileCntX * 2) != 0 && 
			(*pVecTile)[iIndex]->iOption == 0 && 
			CheckList(iIndex))
		{
			pNode = MakeNode(iIndex, pParent, pVecTile);
			m_OpenList.push_back(pNode);
		}
		*/

		//180
		iIndex = pParent->iIndex -1;
		if( pParent->iIndex % (TileCntX * 2) != 0 && 
			(*pVecTile)[iIndex]->iOption == 0 && 
			CheckList(iIndex) )
		{
			pNode = MakeNode(iIndex, pParent, pVecTile);
			m_OpenList.push_back(pNode);
		}

		/*
		//135
		iIndex = pParent->iIndex - 41;
		if( pParent->iIndex >= TileCntX && 
			pParent->iIndex % (TileCntX * 2) != 0 && 
			(*pVecTile)[iIndex]->iOption == 0 && 
			CheckList(iIndex))
		{
			pNode = MakeNode(iIndex, pParent, pVecTile);
			m_OpenList.push_back(pNode);
		}
		*/
															// Compare 또한 함수이다. AStar클래스의 헤더에 정의 선언되있다. F12로 따라가본다.
		m_OpenList.sort(Compare);							// list에 추가된 NODE들을 fCost값의 크기 순으로 정렬한다.
		list<NODE*>::iterator iter = m_OpenList.begin();	// list를 iterator로 원소들을 찾아본다.
		pParent = (*iter);									// pParent에 list의 원소를 대입한다.
		m_CloseList.push_back(*iter);						// m_CloseList에 같은 원소를 추가. CloseList에 추가되면 더 이상 확인을 하지 않는다.
		m_OpenList.erase(iter);								// m_OpenList에 있는 원소를 삭제.

		++iCnt;												// iCnt 증가;

		if (pParent->iIndex == m_iGoalIdx || iCnt > 100)		// iGoalIdx가 어떤 타일의 값인지 유념해두자. iGoalIdx는 플레이어의 위치. iStartIdx가 마우스 클릭.  
		{
			while(true)
			{
				m_BestList.push_back(pParent->iIndex);		// m_BestList에 추가되는 Node들은 Cost 즉 최단거리의 Node들이다.
				pParent = pParent->pParent;

				if (pParent->iIndex == m_iStartIdx)			// 그리고, iGoalIdx와 iStartIdx의 값이 일치할시 break;
					break;
			}

			m_BestList.reverse();	// 앞서 말했듯이, m_BestList에 추가되있는 Node들은 마우스 클릭 지점으로 부터 현 플레이어 위치 순으로 저장되있음으로,
			break;					// list를 reverse 해준다.
		}							// Route가 완성되었다. 이제 CPlayer 클래스의 Progress로 간다. 그리고 AStar_Move함수를 확인해본다.
	}
}


bool AStar::CheckList(const int& iIndex)
{
	for (list<NODE*>::iterator iter = m_OpenList.begin(); iter != m_OpenList.end(); ++iter)
	{
		if ((*iter)->iIndex == iIndex)
			return false;
	}

	for (list<NODE*>::iterator iter = m_CloseList.begin(); iter != m_CloseList.end(); ++iter)
	{
		if ((*iter)->iIndex == iIndex)
			return false;
	}

	return true;
}


NODE* AStar::MakeNode(int iIndex, NODE* pParent, const vector<TILE*>* pVecTile)
{
	NODE* pNode = new NODE;
	pNode->iIndex = iIndex;
	pNode->pParent = pParent;

	int iCurCost = (*pVecTile)[iIndex]->iCost + (*pVecTile)[pParent->iIndex]->iCost;
	int iEndCost = (*pVecTile)[iIndex]->iCost + (*pVecTile)[m_iGoalIdx]->iCost;

	pNode->iCost = iCurCost + iEndCost;		// 두 거리를 더한다. 그리고 NODE 구조체의 fCost값에 합한 거리의 값을 대입한다.

	return pNode; // 거리가 추가된 NODE를 반환.
}


void AStar::Release(void)
{
	for (list<NODE*>::iterator iter = m_OpenList.begin(); iter != m_OpenList.end(); ++iter)
	{
		SAFE_DELETE(*iter);
	}
	m_OpenList.clear();

	for (list<NODE*>::iterator iter = m_CloseList.begin(); iter != m_CloseList.end(); ++iter)
	{
		SAFE_DELETE(*iter);
	}
	m_CloseList.clear();
	
	m_BestList.clear();
}
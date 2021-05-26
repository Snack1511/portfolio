#pragma once
#include"Include.h"

class CObj;
class Astar
{
public:
	DECLARE_SINGLETON(Astar);
public:
	list<NODE*>m_OpenList;
	list<NODE*>m_CloseList;
	list<int>m_BestList;

	int m_iStartIdx;
	int m_iGoalIdx;
public:
	list<int>* GetBestList()
	{
		return &m_BestList;
	}

	static bool Compare(NODE* pDestNode, NODE* pSourNode) 
	{
		return pDestNode->iCost < pSourNode->iCost;
	}

	void AStarStar(int& iStartidx, int& iSGoalidx);
	void MakeRoute(void);
	bool CheckList(const int& iIndex);
	NODE* MakeNode(int iIndex, NODE* pParent, const vector<TILE*>* pVecTile);
	void Release();
public:
	Astar();
	~Astar();
};


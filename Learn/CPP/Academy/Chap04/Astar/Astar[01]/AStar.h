#pragma once
#include "Include.h"

class CObj;
class AStar
{
public:
	DECLARE_SINGLETON(AStar);
private:
	list<NODE*> m_OpenList;
	list<NODE*> m_CloseList;
	list<int>	m_BestList;

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

	void AStarStart(int& iStartIdx, int& iGoalIdx);
	void MakeRoute(void);
	bool CheckList(const int& iIndex);
	NODE* MakeNode(int iIndex, NODE* pParent, const vector<TILE*>* pVecTile);
	void Release(void);
public:
	AStar(void);
	~AStar(void);
};


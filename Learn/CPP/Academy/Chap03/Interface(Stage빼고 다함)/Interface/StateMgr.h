#pragma once
#include"Define.h"

class StateObj;

class StateMgr
{
private:
	static StateMgr* m_pInst;

public:
	static StateMgr* GetInst() 
	{
		if (m_pInst == nullptr) 
		{
			m_pInst = new StateMgr;
		}
		return m_pInst;
	}
private:
	StateObj* m_pState;
public:
	void SetStateMgr(STATEID _StateID);
	void Progress();
	void Render();
	void Release();
public:
	StateMgr();
	~StateMgr();
};


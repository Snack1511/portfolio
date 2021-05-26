#pragma once
#include "Include.h"

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
	void SetStateMgr(STATEID _stateID);
	void Progess();
	void Render();
	void Release();
public:

	StateMgr();
	~StateMgr();
};


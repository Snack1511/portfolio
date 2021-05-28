
#pragma once
#include "Include.h"

class StateObj;
class StateMgr
{
private:
	static StateMgr * m_pInst;
public:
	static StateMgr * GetInst()
	{
		if (m_pInst == NULL)
		{
			m_pInst = new StateMgr;
		}

		return m_pInst;
	}
private:
	StateObj * m_pState;
public:
	void SetStateMgr(STATEID _stateID);
	void Progress();
	void Render();
	void Release();

public:
	StateMgr(void);
	~StateMgr(void);
};
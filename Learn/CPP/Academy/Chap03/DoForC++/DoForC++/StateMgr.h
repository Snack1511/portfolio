#pragma once
#include"Include.h"
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
	StateMgr * m_pState;

public :
	void SetState(STATE_ID _StateID);
	void Progress();
	void Render();
	void Release();

public:
	StateMgr();
	~StateMgr();
};


#pragma once
#include "Include.h"

class CCursorMgr
{
private:
	static CCursorMgr* m_pInst;
public:
	static CCursorMgr* GetInst()
	{
		if(m_pInst == NULL)
			m_pInst = new CCursorMgr;
		return m_pInst;
	}
public:
	static void SetCursorPosition(int _ix, int _iy)
	{
		COORD Pos;
		Pos.X = _ix;
		Pos.Y = _iy;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
public:
	CCursorMgr(void);
	~CCursorMgr(void);
};


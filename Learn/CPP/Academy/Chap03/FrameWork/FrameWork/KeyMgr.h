#pragma once
#include "Include.h"

class CKeyMgr
{
private:
	static CKeyMgr* m_pInst;
public:
	static CKeyMgr* GetInst()
	{
		if(m_pInst == NULL)
			m_pInst = new CKeyMgr;
		return m_pInst;
	}
private:
	DWORD m_dwKey;	// 키값을 받아놓음.
public:
	DWORD GetKey()
	{
		return m_dwKey;
	}
public:
	void CheckKey();
private:
	CKeyMgr(void);
public:
	~CKeyMgr(void);
};


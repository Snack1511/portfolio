#pragma once
#include "Include.h"

class CKeyMgr
{
public:
	DECLARE_SINGLETON(CKeyMgr)

private:
	DWORD m_dwKey;	// 키값을 받아놓음.
public:
	DWORD GetKey(void) const {return m_dwKey;}
	bool PressKey(DWORD _key) const {return m_dwKey & KEY_UP;}
public:
	void CheckKey();
private:
	CKeyMgr(void);
public:
	~CKeyMgr(void);
};
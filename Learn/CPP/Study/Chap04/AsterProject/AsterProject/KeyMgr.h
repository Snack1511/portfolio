#pragma once
#include"Include.h"
class CKeyMgr
{
private:
	DWORD m_dwKey;
public:
	DWORD GetKey() 
	{
		return m_dwKey;
	}
	bool PressKey(DWORD _key) 
	{
		return m_dwKey & KEY_UP;
	}
public :
	void CheckKey();
public:
	CKeyMgr();
	~CKeyMgr();
};


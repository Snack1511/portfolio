#pragma once
#include "Include.h"
class KeyMgr
{
private:
	static KeyMgr * m_pInst;
public:
	static KeyMgr * GetInst() 
	{
		if (m_pInst == NULL)
		{
			m_pInst = new KeyMgr;
		}
		return m_pInst;
	}

private:
	DWORD m_dwKey;
public :
	DWORD GetKey() 
	{
		return m_dwKey;
	}
public :
	void CheckKey();

public:
	KeyMgr();
	~KeyMgr();
};


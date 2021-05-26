#pragma once
#include "SceneObj.h"

class CEnding : public CSceneObj
{
private:
	int		m_iX;
	int		m_iY;
	char*	m_pString;
	char*	m_pChar[10];
	char*	m_pE[10];
	char*	m_pN[10];
	char*	m_pT[10];
	char*	m_pD[10];
	char*	m_pH[10];
	bool	m_bCheck;
	DWORD	m_tCount;
	int		m_iNumCount;
public:
	virtual void Initialize();
	virtual void Porgress();
	virtual void Render();
	virtual void Release();
public:
	CEnding(void);
	virtual ~CEnding(void);
};





#pragma once
#include "SceneObj.h"
class CGameOver : public CSceneObj
{
private:
	int		m_iX;
	int		m_iY;
	char*	m_pG[10];
	char*	m_pA[10];
	char*	m_pM[10];
	char*	m_pE[10];
	char*	m_pO[10];
	char*	m_pV[10];
	char*	m_pR[10];
	bool	m_bCheck;
	DWORD	m_tCount;
	int		m_iNumCount;
public:
	virtual void Initialize();
	virtual void Porgress();
	virtual void Render();
	virtual void Release();
public:
	CGameOver(void);
	virtual ~CGameOver(void);
};
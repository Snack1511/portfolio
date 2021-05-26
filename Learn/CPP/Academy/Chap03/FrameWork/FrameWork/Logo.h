#pragma once
#include "SceneObj.h"

class CLogo : public CSceneObj
{
private:
	int		m_iX;
	int		m_iY;
	int		m_CC;
	char*	m_pString;
	char*	m_pChar[10];
	char*	m_pE[10];
	char*	m_pL[10];
	char*	m_pN[10];
	char*	m_pZ[10];
	char*	m_pI[10];
	char*	m_pA[10];
	bool	m_bCheck;
	DWORD	m_tCount;
	int		m_iNumCount;
public:
	virtual void Initialize();
	virtual void Porgress();
	virtual void Render();
	virtual void Release();
public:
	void RandText(int _ix, int _iy, TEXTID _etextID,int _inum, int _countmax);
public:
	CLogo(void);
	virtual ~CLogo(void);
};


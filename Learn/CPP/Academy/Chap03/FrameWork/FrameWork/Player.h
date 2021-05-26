#pragma once
#include "Obj.h"

class CPlayer : public CObj
{
private:
	DWORD	m_dwKey;
	char*	m_pBasicPosture[PLAYERSIZE];
	DWORD	m_dwState;
	CObj*	m_pBullet[MAX];
	bool	bCheck[MAX];
	DWORD	m_dwDirection;
	int		m_OutputCount;

public:
	virtual void Initialize(int _idata);
	virtual int Porgress(bool _check);
	virtual void Render();
	virtual void Release();
public:
	void KeyCheck();
	void Motion();
	void CheckBullet();
	void PlayerSizeCheck(int _num0, int _num1, int _num2, int _num3, int _num4, int _num5, int _num6, int _num7, int _iy, int _icx);
	void ObjHpBarOutput();
public:
	CPlayer(void);
	virtual ~CPlayer(void);
};


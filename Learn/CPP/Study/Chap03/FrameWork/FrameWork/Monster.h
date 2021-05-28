#pragma once
#include "Obj.h"

class CMonster : public CObj
{
private:
	MONSTER m_Monster;
	DWORD	m_dwKey;
	DWORD	m_dwState;
	DWORD	m_dwDirection;
	char*	m_pBasicPosture[MONSTERSIZE_S];
	CObj*	m_pBullet[MAX];
	bool	bCheck[MAX];
	int		m_iCount;
	int		m_ObjAction;

public:
	virtual void Initialize(int _idata);
	virtual int Porgress(bool _check);
	virtual void Render();
	virtual void Release();
public:
	void KeyCheck();
	void Motion();
	void PlayerSizeCheck(int _num0, int _num1, int _num2, int _num3, int _num4, int _iy, int _icx);
	//void ObjHpBarOutput();
	//void MonsterLevelChoice(int _playerlevel);
public:
	DWORD GetState()
	{
		return m_dwState;
	}
	MONSTER GetMonster()
	{
		return m_Monster;
	}
public:
	CMonster(void);
	virtual ~CMonster(void);
};


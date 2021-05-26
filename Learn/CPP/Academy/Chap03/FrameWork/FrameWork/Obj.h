#pragma once
#include "Include.h"

class CObj
{
protected:
	INFO	m_Info;
	OBJSIZE m_ObjSize;
	INFO	m_pObjInfo[MONSTERMAX];
	INFO	m_pPlayerInfo;
	bool	m_bObjCheck[MONSTERMAX];
	bool	m_bCheck;
public:
	virtual void Initialize(int _idata)PURE;
	virtual int Porgress(bool _check)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	void SetPos(int _ix, int _iy)
	{
		m_Info.iX = _ix;
		m_Info.iY = _iy;
	}
	INFO GetInfo()
	{
		return m_Info;
	}
	void SetInfo(INFO _info)
	{
		m_Info = _info;
	}
	void SetInfo(int _num1/*, int _num2*/)
	{
		m_Info.iLife = _num1;
		//m_Info.iMP = _num2;
	}
	void SetPlayerInfo(INFO _objinfo)
	{
		m_pPlayerInfo = _objinfo;	
	}
	void SetObjInfo(INFO _objinfo, int _index)
	{
		m_pObjInfo[_index] = _objinfo;	
	}
	void SetObjInfo(int _index)
	{
		m_pObjInfo[_index] = INFO(0, 0);
	}
	INFO GetObjInfo(int _index)
	{
		return m_pObjInfo[_index];
	}
	void SetCheck(bool _check)
	{
		m_bCheck = _check;
	}
	bool GetCheck()
	{
		return m_bCheck;
	}
	
public:
	CObj(void);
	virtual ~CObj(void);
};


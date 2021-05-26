#pragma once
#include "Include.h"

class Obj
{
protected:
	INFO m_Info;
	mycharcater m_myChar;
public:
	virtual void Initialize()PURE;
	virtual int Progress()PURE;
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
	void SetActive(bool _check)
	{
		m_Info.bCheck = _check;
	}
public:
	Obj(void);
	virtual ~Obj(void);
};
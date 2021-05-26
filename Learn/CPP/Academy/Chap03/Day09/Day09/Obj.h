#pragma once
#include "Include.h"
class Obj
{
protected :
	INFO m_info;
public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

public:
	void SetInfo(int _ix, int _iy)
	{
		m_info.iX = _ix;
		m_info.iY = _iy;
	}
public:
	Obj(void);
	virtual ~Obj(void);
};


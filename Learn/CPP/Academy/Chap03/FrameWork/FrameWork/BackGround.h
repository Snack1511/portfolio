#pragma once
#include "Obj.h"
#include "Define.h"

class CBackGround : public CObj
{
private:
	TILE m_Tile;
public:
	virtual void Initialize(int _idata);
	virtual int Porgress(bool _check);
	virtual void Render();
	virtual void Release();
public:
	CBackGround(void);
	virtual ~CBackGround(void);
};


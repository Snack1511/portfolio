#pragma once
#include "Include.h"

class CObj
{
protected:
	INFO m_tInfo;
	const vector<TILE*>* pVecTile;
	int m_iDestIdx;
public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	INFO GetInfo(void) const {return m_tInfo;}
	int GetTileIndex(INFO iPos);
	bool CollisionToTile(INFO sCCatPos, const TILE* pTileInfo);
public:
	void SetPos(int _ix, int _iy)
	{
		m_tInfo.iX = _ix;
		m_tInfo.iY = _iy;
	}
public:
	CObj(void);
	virtual ~CObj(void);
};


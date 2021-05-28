#pragma once
#include"Include.h"
#include"Obj.h"
class CObjMgr
{
public:
	DECLARE_SINGLETON(CObjMgr);
private:
	vector<TILE*>mTileList;
	CObj* m_pCursor;
public:
	void InitTile();
	void InitCursor();
	vector<TILE*>*getTileInfo() 
	{
		return &mTileList;
	}
	void SetCursor(CObj*_pCursor) 
	{
		m_pCursor = _pCursor;
	}
	CObj**GetCursor() 
	{
		return &m_pCursor;
	}
public:
	CObjMgr();
	~CObjMgr();
};


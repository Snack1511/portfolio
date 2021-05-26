#pragma once
#include "Include.h"
#include "Obj.h"

class CObjMgr
{
public:
	DECLARE_SINGLETON(CObjMgr);
private:
	vector<TILE*> m_TileList;
	CObj* m_pCursor;
public:
	void InitTile();
	void InitCursor();
	vector<TILE*>* GetTileInfo() { return &m_TileList; }
	void SetCursor(CObj* _pCursor) { m_pCursor = _pCursor;}
	CObj** GetCursor() { return &m_pCursor; }
private:
	CObjMgr(void);
public:
	~CObjMgr(void);
};


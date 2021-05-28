#pragma once
#include"Include.h"

class CObj;
class CBackGround
{
private:
	vector<TILE*>*m_TileList;
	COBJ** m_pCursor;
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();

public:
	CBackGround();
	~CBackGround();
};


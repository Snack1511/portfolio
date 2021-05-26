#pragma once
#include "Include.h"

class CObj;
class CBackGround
{
private:
	vector <TILE*>* m_TileList;
	CObj** m_pCursor;
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
public:
	CBackGround(void);
	~CBackGround(void);
};


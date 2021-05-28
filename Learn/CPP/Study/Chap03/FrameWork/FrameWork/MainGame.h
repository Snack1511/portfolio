#pragma once
#include "Define.h"

class CMainGame
{
public:
	void Initialize();
	void Porgress();
	void Render();
	void Release();
public:
	CMainGame(void);
	~CMainGame(void);
};


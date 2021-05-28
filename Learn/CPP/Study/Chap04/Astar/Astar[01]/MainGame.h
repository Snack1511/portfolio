#pragma once
#include "Include.h"

class CBackGround;
class CMainGame
{
private:
	CBackGround* m_pScene;
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
public:
	CMainGame(void);
	~CMainGame(void);
};


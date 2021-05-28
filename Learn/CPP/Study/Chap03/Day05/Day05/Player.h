#pragma once
#include "MainGame.h"
class CPlayer : public CMainGame//»ó¼Ó
{
public:
	/*virtual void NewFunction();
	void secondFunction();
	virtual void purevirtual();*/
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

public:
	CPlayer();
	
	virtual ~CPlayer();
};


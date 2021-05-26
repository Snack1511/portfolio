#pragma once
#include "Obj.h"

class Player : public Obj
{
private:
	DWORD m_dwKey;
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	void KeyCheck();
public:
	Player(void);
	virtual ~Player(void);
};


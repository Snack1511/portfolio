#pragma once
#include "Obj.h"
#include<list>

class Player:public Obj
{
private:
	int m_iLife;
	DWORD m_dwKey;
	DWORD m_dwState;
public :
	virtual void Initialize();
	virtual int Progress();
	virtual void Render();
	virtual void Release();
public :
	void KeyCheck();
	void Motion();
	void StatInit();
	void SetHp() 
	{
		m_iLife--;
	}
public:
	Player();
	~Player();
};


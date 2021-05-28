#pragma once
#include"obj.h"

class Player:public Obj
{
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	Player();
	~Player();
};


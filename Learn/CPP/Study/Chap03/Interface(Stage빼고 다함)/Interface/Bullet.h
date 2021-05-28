#pragma once
#include"Obj.h"
class Bullet:public Obj
{

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

public:
	Bullet();
	~Bullet();
};


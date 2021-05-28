#pragma once
#include "Obj.h"

class Monster : public Obj
{
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

public:
	Monster(void);
	virtual ~Monster(void);
};


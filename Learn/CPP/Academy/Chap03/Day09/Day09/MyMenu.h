#pragma once
#include "StateObj.h"
class MyMenu  : public StateObj
{
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

public:
	MyMenu(void);
	virtual ~MyMenu(void);
};


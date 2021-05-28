#pragma once
#include "StateObj.h"
class Menu : public StateObj
{
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	Menu();
	~Menu();
};

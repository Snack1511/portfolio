#pragma once
#include "StateObj.h"
class Stage : public StateObj
{
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	Stage();
	~Stage();
};

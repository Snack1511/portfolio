#pragma once
#include "StateObj.h"
class Logo : public StateObj
{
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	Logo(void);
	virtual ~Logo(void);
};


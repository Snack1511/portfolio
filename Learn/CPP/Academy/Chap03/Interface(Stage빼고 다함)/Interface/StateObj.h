#pragma once
#include"Define.h"
class StateObj
{
public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

public:
	StateObj();
	~StateObj();
};


#pragma once

#include"Define.h"
#define PURE = 0
class Obj
{
public :
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	Obj();
	~Obj();
};


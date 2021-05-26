#pragma once
#include "Include.h"

class CSceneObj
{
public:
	virtual void Initialize()PURE;
	virtual void Porgress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	CSceneObj(void);
	virtual ~CSceneObj(void);
};


#pragma once
#include"Include.h"
class SceneObj
{
public:

	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	SceneObj();
	~SceneObj();
};


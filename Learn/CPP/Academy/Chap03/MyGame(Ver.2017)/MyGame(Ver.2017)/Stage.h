#pragma once
#include"SceneObj.h"
class Stage : public SceneObj
{
public :
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	Stage();
	~Stage();
};


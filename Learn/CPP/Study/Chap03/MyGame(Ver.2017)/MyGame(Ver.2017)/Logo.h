#pragma once
#include "SceneObj.h"
class Logo : public SceneObj
{
public :
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	Logo();
	~Logo();
};


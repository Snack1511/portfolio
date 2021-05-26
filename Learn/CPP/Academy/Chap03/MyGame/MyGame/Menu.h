#pragma once
#include"SceneObj.h"
class Menu : public SceneObj
{
public :
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	Menu();
	~Menu();
};


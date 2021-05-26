#pragma once
#include "StateObj.h"
class Obj;
class Stage  : public StateObj
{
private :
	Obj	* m_Player;
	Obj * m_Monster;
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();

public:
	Stage(void);
	virtual ~Stage(void);
};


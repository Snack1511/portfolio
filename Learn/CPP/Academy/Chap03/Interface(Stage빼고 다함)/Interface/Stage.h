#pragma once
#include"StateObj.h"

class Obj;


class Stage:public StateObj
{
private:
	Obj* player;
	Obj* monster;
	Obj* bullet[20];
	int bulletDist;
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	Stage();
	~Stage();
};


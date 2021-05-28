#pragma once
#include"Obj.h"
class Obj;
class Collision
{
public:
	static bool CollisionMgr(Obj* fObj, Obj* sObj);
public:
	Collision();
	~Collision();
};


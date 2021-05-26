#pragma once
#include "Include.h"

class Obj;
class Collision
{
public:
	static bool CollisionMgr(Obj* _pplayer, Obj* _pmonster);
	static bool CollisionTest(Obj* _pmonster, Obj* _pbullet);
public:
	Collision(void);
	~Collision(void);
};

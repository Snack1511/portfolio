#pragma once
#include "Include.h"

class CObj;
class CCollision
{
public:
	static bool CollisionMgr(CObj* _pplayer, CObj* _pmonster);
	static bool CollisionMgr(INFO _pplayer, INFO _pmonster);
public:
	CCollision(void);
	~CCollision(void);
};
#include "Collision.h"



bool Collision::CollisionMgr(Obj * fObj, Obj * sObj)
{
	if (fObj->GetInfo().ix + fObj->GetInfo().icx >= sObj->GetInfo().ix&&
		fObj->GetInfo().ix <= sObj->GetInfo().ix + sObj->GetInfo().icx&&
		fObj->GetInfo().iy == sObj->GetInfo().iy) 
	{
		return true;
	}
	return false;
}

Collision::Collision()
{
}


Collision::~Collision()
{
}

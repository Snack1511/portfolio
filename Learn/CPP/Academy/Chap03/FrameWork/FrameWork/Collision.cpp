#include "Collision.h"
#include "Player.h"


CCollision::CCollision(void)
{
}


CCollision::~CCollision(void)
{
}

bool CCollision::CollisionMgr(CObj* _pplayer, CObj* _pmonster)
{
	if(_pplayer->GetInfo().iX < _pmonster->GetInfo().iX + _pmonster->GetInfo().iCX &&
		_pmonster->GetInfo().iX < _pplayer->GetInfo().iX + _pplayer->GetInfo().iCX &&
		_pplayer->GetInfo().iY < _pmonster->GetInfo().iY + _pmonster->GetInfo().iCY &&
		_pmonster->GetInfo().iY < _pplayer->GetInfo().iY + _pplayer->GetInfo().iCY)
	{
		return true;
	}
	return false;
}

bool CCollision::CollisionMgr(INFO _pplayer, INFO _pmonster)
{
	if(_pplayer.iX < _pmonster.iX + _pmonster.iCX &&
		_pmonster.iX < _pplayer.iX + _pplayer.iCX &&
		_pplayer.iY < _pmonster.iY + _pmonster.iCY &&
		_pmonster.iY < _pplayer.iY + _pplayer.iCY)
	{
		return true;
	}
	return false;
}
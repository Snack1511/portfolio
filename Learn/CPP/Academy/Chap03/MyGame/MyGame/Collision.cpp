#include "Collision.h"
#include"Player.h"
//#include"Monster.h"


bool Collision::CollisionMgr(Obj* _pplayer, Obj* _pmonster)
{
	if (_pplayer->GetInfo().iX + _pplayer->GetInfo().iCX > _pmonster->GetInfo().iX&&
		_pplayer->GetInfo().iX < _pmonster->GetInfo().iX + _pmonster->GetInfo().iCX &&
		_pplayer->GetInfo().iY == _pmonster->GetInfo().iY)
	{
		return true;
	}
	return false;
}
bool Collision::CollisionTest(Obj* _pmonster, Obj* _pbullet)
{
	if (_pmonster->GetInfo().iX + _pmonster->GetInfo().iCX > _pbullet->GetInfo().iX &&
		_pmonster->GetInfo().iX < _pbullet->GetInfo().iX + _pbullet->GetInfo().iCX &&
		_pmonster->GetInfo().iY == _pbullet->GetInfo().iY)
	{
		return true;
	}

	if (GetAsyncKeyState(VK_TAB))
	{
		ERR_MSG(10, 1, "PLAYER");
		ERR_MSG(10, 2, "X  : ");
		ERR_MSG(15, 2, _pmonster->GetInfo().iX);
		ERR_MSG(10, 3, "Y  : ");
		ERR_MSG(15, 3, _pmonster->GetInfo().iY);
		ERR_MSG(10, 4, "CX : ");
		ERR_MSG(15, 4, _pmonster->GetInfo().iCX);
		ERR_MSG(10, 5, "CY : ");
		ERR_MSG(15, 5, _pmonster->GetInfo().iCY);

		ERR_MSG(25, 1, "BULLET");
		ERR_MSG(25, 2, "X  : ");
		ERR_MSG(30, 2, _pbullet->GetInfo().iX);
		ERR_MSG(25, 3, "Y  : ");
		ERR_MSG(30, 3, _pbullet->GetInfo().iY);
		ERR_MSG(25, 4, "CX : ");
		ERR_MSG(30, 4, _pbullet->GetInfo().iCX);
		ERR_MSG(25, 5, "CY : ");
		ERR_MSG(30, 5, _pbullet->GetInfo().iCY);
	}
	return false;
}




Collision::Collision()
{
}


Collision::~Collision()
{
}

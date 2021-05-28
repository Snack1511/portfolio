#pragma once;
#include "Obj.h"
#include "Player.h"
#include "Monster.h"

class ObjFactory
{
public :
	static Obj * CreatePlayer()
	{
		Obj * pObj = new Player;
		pObj->Initialize();
		return pObj;
	}

	static Obj * CreateMonster()
	{
		Obj * pObj = new Monster;
		pObj->Initialize();
		return pObj;
	}

	static Obj * CreateMonster(int _ix, int _iy)
	{
		Obj * pObj = new Monster;
		pObj->Initialize();
		pObj->SetInfo(_ix, _iy);
		return pObj;
	}

public: 
	ObjFactory(){};
	~ObjFactory(){};
};
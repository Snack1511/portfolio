#include "ObjFactory.h"
#include"Player.h"
#include"Monster.h"
#include"Bullet.h"


Obj * ObjFactory::CreatePlayer()
{
	Obj* pObj = new Player;
	pObj->SetName("oさo");
	return pObj;
}

Obj * ObjFactory::CreateMonster()
{
	Obj* pObj = new Monster;
	pObj->SetName("ぞさぞ");
	return pObj;
}

Obj * ObjFactory::CreateBullet()
{
	Obj* pObj = new Bullet;
	pObj->SetName("=>");
	return pObj;
	
}



ObjFactory::ObjFactory()
{
}


ObjFactory::~ObjFactory()
{
}

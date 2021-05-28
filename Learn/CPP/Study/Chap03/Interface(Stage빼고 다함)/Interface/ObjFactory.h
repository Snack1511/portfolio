#pragma once
#include"Obj.h"
class ObjFactory
{
public:
	static Obj* CreatePlayer();
	static Obj* CreateMonster();
	static Obj* CreateBullet();
public:
	ObjFactory();
	~ObjFactory();
};


#pragma once
#include "Obj.h"

template <typename T>
class CObjFactory
{
public:
	static CObj* CreateObj()
	{
		CObj* pObj = new T;
		pObj->Initialize();

		return pObj;
	}
	static CObj* CreateObj(int _ix, int _iy)
	{
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->SetPos(_ix, _iy);

		return pObj;
	}
};
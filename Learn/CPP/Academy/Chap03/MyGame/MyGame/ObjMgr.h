#pragma once
#include "Include.h"
class Obj;
class ObjMgr
{
private:
	static ObjMgr* m_pInst;
public :
	static ObjMgr* GetInst()
	{
		if (m_pInst == NULL) 
		{
			m_pInst = new ObjMgr;
		}
		return m_pInst;
	}
private:
	Obj* m_pPlayer;
	//Obj* m_pMonster[END];
	Obj* m_pBackGround;

	//Obj*	m_pBullet[MAX];
	bool	bCheck[MAX];
public:
	void Initialize();
	void Progress();
	void Render();
	void Release();
public:
	Obj* GetPlayerInfo() 
	{
		return m_pPlayer;
	}
	void SetBulletActive(bool _bCheck);
	void CheckBullet();
	

private:
	ObjMgr();
public:
	~ObjMgr();
};


#pragma once
#include"Obj.h"
#include"Define.h"
class BackGround : public Obj
{
private:
	TILE m_Tile;

public:
	virtual void Initialize();
	virtual int Progress();
	virtual void Render();
	virtual void Release();

public:
	BackGround();
	virtual ~BackGround();
};


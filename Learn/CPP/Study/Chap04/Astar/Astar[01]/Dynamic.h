#pragma once
#include "Obj.h"

class CDynamic : public  CObj
{
public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	void AStar_Start(INFO sDestPos, INFO sSourPos);
	void AStar_Move(const CObj* pTemp);
public:
	CDynamic(void);
	virtual ~CDynamic(void);
};


#pragma once
#include "Obj.h"
class CBlock : public CObj
{
public:
	virtual void Initialize(int _idata);
	virtual int Porgress(bool _check);
	virtual void Render();
	virtual void Release();
public:
	CBlock(void);
	virtual ~CBlock(void);
};


#pragma once
#include"Define.h"
class Obj
{
private:

	INFO info;
public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

public:
	void SetInfo(int _ix, int _iy) 
	{
		info.ix = _ix;
		info.iy = _iy;
	}
	INFO GetInfo() 
	{
		return info;
	}
	void SetAct(bool act) 
	{
		info.act = act;
	}
	void SetName(char* name)
	{
		info.Name = name;
		info.icx = strlen(info.Name);
	}
public:
	Obj();
	~Obj();
};


#pragma once
#include"StateObj.h"

class Logo : public StateObj
{
private:
	INFO* p_logo;
	char* logo[10];
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
	void Test() {}

public:
	Logo();
	~Logo();
};


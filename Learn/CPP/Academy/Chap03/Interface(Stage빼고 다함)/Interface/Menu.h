#pragma once
#include"StateObj.h"

class Menu:public StateObj
{
private:
	INFO* cursor;
	INFO* menu[2];
	int cursorIndex;

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	Menu();
	~Menu();
};


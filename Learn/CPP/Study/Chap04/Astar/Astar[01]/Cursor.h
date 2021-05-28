#pragma once
#include "Dynamic.h"

class CCursor : public CDynamic
{
private:
	bool m_bClicked;
public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
public:
	void KeyCheck(void);
public:
	CCursor(void);
	virtual ~CCursor(void);
};


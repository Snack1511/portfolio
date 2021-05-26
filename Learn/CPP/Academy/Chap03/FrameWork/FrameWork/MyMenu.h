#pragma once
#include "SceneObj.h"

class CMyMenu : public CSceneObj
{
private:
	int m_iX;
	int m_iY;
public:
	virtual void Initialize();
	virtual void Porgress();
	virtual void Render();
	virtual void Release();
public:
	CMyMenu(void);
	virtual ~CMyMenu(void);
};


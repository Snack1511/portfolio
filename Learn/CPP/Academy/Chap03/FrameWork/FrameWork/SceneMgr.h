#pragma once
#include "Include.h"

class CSceneObj;
class CSceneMgr
{
private:
	static CSceneMgr* m_pInstance;
public:
	static CSceneMgr* GetInstance()
	{
		if(m_pInstance == NULL)
			m_pInstance = new CSceneMgr;
		return m_pInstance;
	}
private:
	CSceneObj* m_pSceneMgr;
public:
	void SetScene(STATEID _estateid);
	void Porgress();
	void Render();
	void Release();
public:
	CSceneMgr(void);
	~CSceneMgr(void);
};
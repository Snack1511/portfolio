#pragma once
#include"Include.h"
class SceneObj;
class SceneMgr
{
private:
	static SceneMgr* m_pInstance;
public:
	static SceneMgr* GetInstance() 
	{
		if (m_pInstance == NULL) 
		{
			m_pInstance = new SceneMgr;
		}
		return m_pInstance;
	}
private:
	SceneObj* m_pSceneMgr;

public:
	void SetScene(State_ID _estateid);
	void Progress();
	void Render();
	void Release();
public:
	SceneMgr();
	~SceneMgr();
};


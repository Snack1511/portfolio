#include "SceneMgr.h"
#include "Include.h"

#include"Logo.h"
#include"Menu.h"
#include"Stage.h"


SceneMgr* SceneMgr::m_pInstance= NULL;


void SceneMgr::SetScene(State_ID _e_stateid) {
	if (m_pSceneMgr != NULL) 
	{
		delete m_pSceneMgr;
		m_pSceneMgr = NULL;
	}
	switch (_e_stateid) 
	{
	case IDS_LOGO:
		m_pSceneMgr = new Logo;
		break;
	case IDS_MENU:
		m_pSceneMgr = new Menu;
		break;
	case IDS_STAGE:
		m_pSceneMgr = new Stage;
		break;
	}
	m_pSceneMgr->Initialize();
}
void SceneMgr::Progress() {
	m_pSceneMgr->Progress();
}
void SceneMgr::Render() {
	m_pSceneMgr->Render();
}
void SceneMgr::Release() {
	m_pSceneMgr->Release();
}

SceneMgr::SceneMgr():m_pSceneMgr(NULL)
{
}


SceneMgr::~SceneMgr()
{
}

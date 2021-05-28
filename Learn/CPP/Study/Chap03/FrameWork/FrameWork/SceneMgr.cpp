#include "SceneMgr.h"
#include "Include.h"

#include "Logo.h"
#include "MyMenu.h"
#include "Stage.h"
#include "Ending.h"
#include "GameOver.h"

CSceneMgr* CSceneMgr::m_pInstance = NULL;

CSceneMgr::CSceneMgr(void)
	:m_pSceneMgr(NULL)
{
}


CSceneMgr::~CSceneMgr(void)
{
}

void CSceneMgr::SetScene( STATEID _estateid )
{
	::Safe_Delete(m_pSceneMgr);

	switch(_estateid)
	{
	case IDS_LOGO:
		m_pSceneMgr = new CLogo;
		break;

	case IDS_MENU:
		m_pSceneMgr = new CMyMenu;
		break;

	case IDS_STAGE:
		m_pSceneMgr = new CStage;
		break;
	case IDS_ENDING:
		m_pSceneMgr = new CEnding;
		break;
	case IDS_GAMEOVER:
		m_pSceneMgr = new CGameOver;
		break;
	}
	m_pSceneMgr->Initialize();
}

void CSceneMgr::Porgress()
{
	m_pSceneMgr->Porgress();
}

void CSceneMgr::Render()
{
	m_pSceneMgr->Render();
}

void CSceneMgr::Release()
{

}

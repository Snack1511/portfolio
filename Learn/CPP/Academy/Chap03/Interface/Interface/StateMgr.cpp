#include "StateMgr.h"
#include"Logo.h"
#include"Menu.h"
#include"Stage.h"

StateMgr* StateMgr::m_pInst = nullptr;

void StateMgr::SetStateMgr(STATEID _stateID)
{
	if (m_pState != nullptr) 
	{
		delete m_pState;
		m_pState = nullptr;
	}

	switch (_stateID) 
	{
	case LOGO_ID:
		m_pState = new Logo;
		break;
	case MENU_ID:
		m_pState = new Menu;
		break;
	case STAGE_ID:
		m_pState = new Stage;
		break;
	}

	m_pState->Initialize();
}

void StateMgr::Progess()
{
	m_pState->Progress();
}

void StateMgr::Render()
{
	m_pState->Render();
}

void StateMgr::Release()
{
	m_pState->Release();
}

StateMgr::StateMgr():m_pState(nullptr)
{
}


StateMgr::~StateMgr()
{
}

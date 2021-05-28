#include "StateMgr.h"
#include "Logo.h"
#include "MyMenu.h"
#include "Stage.h"

StateMgr * StateMgr::m_pInst = NULL;

void StateMgr::SetStateMgr(STATEID _stateID)
{
	if (m_pState != NULL)
	{
		delete m_pState;
		m_pState = NULL;
	}
	
	switch (_stateID)
	{
	case LOGO_ID:
		m_pState = new Logo;
		break;

	case MyMenu_ID:
		m_pState = new MyMenu;
		break;

	case Stage_ID:
		m_pState = new Stage;
		break;
	}

	m_pState->Initialize();
}

void StateMgr::Progress()
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

StateMgr::StateMgr(void) : m_pState(NULL)
{
}


StateMgr::~StateMgr(void)
{
}

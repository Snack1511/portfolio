#include "MainGame.h"
#include "CObjFactory.h"

#include "DoubleBuffer.h"
#include "BackGround.h"
#include "KeyMgr.h"

CMainGame::CMainGame(void)
{
}


CMainGame::~CMainGame(void)
{
	Release();
}


void CMainGame::Initialize()
{
	srand(GetTickCount());
	CDoubleBuffer::GetInst()->SetCursorHandle();
	CDoubleBuffer::GetInst()->CreateBuffer();

	m_pScene = new CBackGround;
	m_pScene->Initialize();
}

void CMainGame::Progress()
{
	GET_SINGLE(CKeyMgr)->CheckKey();
	CDoubleBuffer::GetInst()->FlippingBuffer();
	CDoubleBuffer::GetInst()->ClearBuffer();
	m_pScene->Progress();
}

void CMainGame::Render()
{
	system("cls");

	m_pScene->Render();
}

void CMainGame::Release()
{
	delete m_pScene;
	m_pScene = NULL;

	CDoubleBuffer::GetInst()->DestroyBuffer();
}

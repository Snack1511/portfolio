#include "MainGame.h"
#include "Include.h"
#include "SceneMgr.h"
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
	system("mode con:cols=170 lines=60");		//  Windows창 크기 조절    Value.h 헤더에 있는 WINCX, WINCY 크기도 같이 조절 해야 된다.

	CSceneMgr::GetInstance()->SetScene(IDS_LOGO);
	CDoubleBuffer::GetInst()->CreateBuffer(171, 61);
}

void CMainGame::Porgress()
{
	CSceneMgr::GetInstance()->Porgress();
	CKeyMgr::GetInst()->CheckKey();
	CDoubleBuffer::GetInst()->FlippingBuffer();	
	CDoubleBuffer::GetInst()->ClearBuffer();
}

void CMainGame::Render()
{
	CSceneMgr::GetInstance()->Render();
}

void CMainGame::Release()
{
	CDoubleBuffer::GetInst()->DestroyBuffer();
}

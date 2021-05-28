#include "MainGame.h"
#include "StateMgr.h"
#include "KeyMgr.h"

void MainGame::Initialize()
{
	cout << "MainGame::Initialize" << endl;
	StateMgr::GetInst()->SetStateMgr(LOGO_ID);
}

void MainGame::Progress()
{
	StateMgr::GetInst()->Progress();
	KeyMgr::GetInst()->CheckKey();
}

void MainGame::Render()
{
	StateMgr::GetInst()->Render();
}

void MainGame::Release()
{
	StateMgr::GetInst()->Release();
}


MainGame::MainGame(void)
{
}


MainGame::~MainGame(void)
{
}

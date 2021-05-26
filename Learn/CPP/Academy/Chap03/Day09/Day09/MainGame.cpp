#include "MainGame.h"
#include "StateMgr.h"

void MainGame::Initialize()
{
	cout << "MainGame::Initialize" << endl;
	StateMgr::GetInst()->SetStateMgr(LOGO_ID);
}

void MainGame::Progress()
{
	cout << "MainGame::Progress" << endl;
	StateMgr::GetInst()->Progress();
}

void MainGame::Render()
{
	cout << "MainGame::Render" << endl;
	StateMgr::GetInst()->Render();
}

void MainGame::Release()
{
	cout << "MainGame::Release" << endl;
	StateMgr::GetInst()->Release();
}


MainGame::MainGame(void)
{
}


MainGame::~MainGame(void)
{
}

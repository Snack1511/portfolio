#include "MainGame.h"
#include"StateMgr.h"


void MainGame::Initialize()
{
	StateMgr::GetInst()->SetStateMgr(LOGO);
	DoubleBuffer::GetInst()->CreateBuffer(WINCX, WINCY);
}

void MainGame::Progress()
{
	StateMgr::GetInst()->Progress();
	DoubleBuffer::GetInst()->FlippingBuffer();
	DoubleBuffer::GetInst()->ClearBuffer();


}

void MainGame::Render()
{
	StateMgr::GetInst()->Render();
}

void MainGame::Release()
{
	StateMgr::GetInst()->Release();
}

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}

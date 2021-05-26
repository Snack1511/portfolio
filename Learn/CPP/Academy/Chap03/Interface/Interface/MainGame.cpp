#include "MainGame.h"
#include"StateMgr.h"

void MainGame::Initialize()
{
	DoubleBuffer::GetInst()->CreateBuffer(WINCX, WINCY);
	StateMgr::GetInst()->SetStateMgr(LOGO_ID);
}

void MainGame::Progress()
{
	StateMgr::GetInst()->Progess();
}
void MainGame::Render()
{
	/*DoubleBuffer::GetInst()->WriteBuffer(0, 0, , Èò»ö);
	DoubleBuffer::GetInst()->FlippingBuffer();
	DoubleBuffer::GetInst()->ClearBuffer();*/
}

void MainGame::Release()
{
	DoubleBuffer::GetInst()->DestroyBuffer();
}

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
	MainGame::Release();
}

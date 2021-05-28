#include "Player.h"
#include "Include.h"
#include "KeyMgr.h"
#include"ObjFactory.h"
#include"ObjMgr.h"



void Player::Initialize()
{
	m_Info = INFO(10, 20);
	m_dwState = STATE_STAND;

	m_Info.str = new char[strlen("옷/")];
	strcpy(m_Info.str, "옷/");

	m_Info.iCX = strlen(m_Info.str);
	m_Info.iCY = 1;

	m_Info.tState = new STATE;
	StatInit();


	m_iLife = 1;
}

int Player::Progress()
{
	for (int i = 0; i < m_iLife; i++)
		DoubleBuffer::GetInst()->WriteBuffer(30 + (i * 2), 2, "♥", 연한빨간색);


	if (m_Info.iX == 2)
		m_Info.iX += 1;

	if (m_Info.iX + 1 == (WINCX - 3))
		m_Info.iX -= 1;

	if (m_Info.iY <= 1)
		m_Info.iY = 1;

	if (m_Info.iY == (WINCY - 2))
		m_Info.iY -= 1;

	KeyCheck();
	Motion();

	return 0;
}
void Player::Render()
{
	/*DoubleBuffer::GetInst()->WriteBuffer(5, 1, "PLAYER", 연한초록색);
	DoubleBuffer::GetInst()->WriteBuffer(3, 2, m_Info.tState->iHP, 연한빨간색);
	DoubleBuffer::GetInst()->WriteBuffer(6, 2, " / ", 연한빨간색);
	DoubleBuffer::GetInst()->WriteBuffer(9, 2, m_Info.tState->iMAX_HP, 연한빨간색);	

	DoubleBuffer::GetInst()->WriteBuffer(3, 3, m_Info.tState->iMP, 연한파란색);
	DoubleBuffer::GetInst()->WriteBuffer(6, 3, " / ", 연한파란색);
	DoubleBuffer::GetInst()->WriteBuffer(9, 3, m_Info.tState->iMAX_MP, 연한파란색);

	DoubleBuffer::GetInst()->WriteBuffer(3, 4, m_Info.tState->iEXP, 연한노란색);
	DoubleBuffer::GetInst()->WriteBuffer(6, 4, " / ", 연한노란색);
	DoubleBuffer::GetInst()->WriteBuffer(9, 4, m_Info.tState->iMAX_EXP, 연한노란색);

	DoubleBuffer::GetInst()->WriteBuffer(3, 5, "Gold : ", 연한초록색);
	DoubleBuffer::GetInst()->WriteBuffer(10, 5, m_Info.tState->iGold, 연한초록색);

	DoubleBuffer::GetInst()->WriteBuffer(m_Info.iX, m_Info.iY, m_Info.str, 연한초록색);
	DoubleBuffer::GetInst()->WriteBuffer(m_Info.iX - 2, m_Info.iY - 1, m_Info.tState->iMAX_HP, 연한빨간색);
	DoubleBuffer::GetInst()->WriteBuffer(m_Info.iX + 2, m_Info.iY - 1, m_Info.tState->iMAX_MP, 연한파란색);*/


	DoubleBuffer::GetInst()->WriteBuffer(5, 1, "Player", 연한초록색);
	DoubleBuffer::GetInst()->WriteBuffer(3, 2, m_Info.tCharacter->iLife, 연한빨간색);

	DoubleBuffer::GetInst()->WriteBuffer(3, 3, m_Info.tCharacter->iSpeed, 연한파란색);
	DoubleBuffer::GetInst()->WriteBuffer(6, 3, " / ", 연한파란색);
	DoubleBuffer::GetInst()->WriteBuffer(9, 3, m_Info.tCharacter->iMAX_Speed, 연한파란색);

	DoubleBuffer::GetInst()->WriteBuffer(3, 4, m_Info.tCharacter->iJump, 연한노란색);
	DoubleBuffer::GetInst()->WriteBuffer(6, 4, " / ", 연한노란색);
	DoubleBuffer::GetInst()->WriteBuffer(9, 4, m_Info.tCharacter->iMAX_Jump, 연한노란색);

	DoubleBuffer::GetInst()->WriteBuffer(3, 5, "Score : ", 연한초록색);
	DoubleBuffer::GetInst()->WriteBuffer(10, 5, m_Info.tCharacter->iScore, 연한초록색);

	DoubleBuffer::GetInst()->WriteBuffer(m_Info.iX, m_Info.iY, m_Info.str, 연한초록색);
	DoubleBuffer::GetInst()->WriteBuffer(m_Info.iX - 2, m_Info.iY - 1, m_Info.tCharacter->iLife, 연한빨간색);
	DoubleBuffer::GetInst()->WriteBuffer(m_Info.iX - 2, m_Info.iY - 2, m_Info.tCharacter->iMAX_Speed, 연한파란색);
	DoubleBuffer::GetInst()->WriteBuffer(m_Info.iX + 2, m_Info.iY - 2, m_Info.tCharacter->iMAX_Jump, 연한노란색);
}

void Player::Release()
{

}

void Player::KeyCheck()
{

}

void Player::Motion()
{

}

void Player::StatInit()
{

}
Player::Player()
{
}


Player::~Player()
{
	Release();
}

#include "Player.h"
#include "Include.h"
#include "KeyMgr.h"

void Player::Initialize()
{
	cout << "Player::Initialize" << endl;
}

void Player::Progress()
{
	KeyCheck();
}

void Player::Render()
{
	
}

void Player::Release()
{
	
}

Player::Player(void)
{
}


Player::~Player(void)
{
	Release();
}

void Player::KeyCheck()
{
	m_dwKey = KeyMgr::GetInst()->GetKey();
	if (m_dwKey & KEY_UP) 
	{
		cout << "Key_UP" << endl;
	}
	if (m_dwKey & KEY_DOWN)
	{
		cout << "Key_DOWN" << endl;
	}
	if (m_dwKey & KEY_LEFT)
	{
		cout << "Key_LEFT" << endl;
	}
	if (m_dwKey & KEY_RIGHT) 
	{
		cout << "Key_RIGHT" << endl;
	}
	if (m_dwKey & KEY_SPACE)
	{
		cout << "Key_SPACE" << endl;
	}
	if (m_dwKey & KEY_RETURN)
	{
		cout << "Key_Return" << endl;
	}
}

#include "KeyMgr.h"

KeyMgr * KeyMgr::m_pInst = NULL;

KeyMgr::KeyMgr()
{
}


KeyMgr::~KeyMgr()
{
}


void KeyMgr::CheckKey() 
{
	m_dwKey = 0;
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		m_dwKey |= KEY_UP;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		m_dwKey |= KEY_DOWN;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		m_dwKey |= KEY_LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_dwKey |= KEY_RIGHT;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		m_dwKey |= KEY_SPACE;
	}
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		m_dwKey |= KEY_LBUTTON;
	}
	if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
	{
		m_dwKey |= KEY_RBUTTON;
	}
	if (GetAsyncKeyState(VK_RETURN) & 0x8000)
	{
		m_dwKey |= KEY_RETURN;
	}
}

/*
0x0000		이전에 누른 적이 없고 호출 시점에도 눌려있지 않은 상태
0x0001		이전에 누른 적이 있고 호출 시점에는 눌려있지 않은 상태
0x8000		이전에 누른 적이 없고 호출 시점에는 눌려있는 상태
0x8001		이전에 누른 적이 있고 호출 시점에도 눌려있는 상태
*/
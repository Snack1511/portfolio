#include "MyMenu.h"
#include "SceneMgr.h"

CMyMenu::CMyMenu(void)
{
}


CMyMenu::~CMyMenu(void)
{
}


void CMyMenu::Initialize()
{
	
	m_iX = 0;
	m_iY = 0;
}

void CMyMenu::Porgress()
{
	if(GetAsyncKeyState(VK_RETURN))
	{
		CSceneMgr::GetInstance()->SetScene(IDS_STAGE);
	}
}

void CMyMenu::Render()
{
	CDoubleBuffer::GetInst()->WriteBuffer(0, (WINCY - 26), "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", COLOR_REALWHITE);

	CDoubleBuffer::GetInst()->WriteBuffer((WINCX/2)-17, (WINCY/2) + 2, "직업을 선택 하십시오.", COLOR_REALWHITE);
	CDoubleBuffer::GetInst()->WriteBuffer((WINCX/2)-10, (WINCY/2) + 4, "전사", COLOR_REALWHITE);
	CDoubleBuffer::GetInst()->WriteBuffer((WINCX/2)-10, (WINCY/2) + 6, "마법사", COLOR_REALWHITE);
	CDoubleBuffer::GetInst()->WriteBuffer((WINCX/2)-10, (WINCY/2) + 8, "도적", COLOR_REALWHITE);

	CDoubleBuffer::GetInst()->WriteBuffer((WINCX/2)-10, (WINCY/2) + 8, "▶", COLOR_REALWHITE);
}

void CMyMenu::Release()
{

}

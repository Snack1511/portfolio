#include "Cursor.h"
#include "DoubleBuffer.h"
#include "KeyMgr.h"

CCursor::CCursor(void)
{
}


CCursor::~CCursor(void)
{
}


void CCursor::Initialize()
{
	m_bClicked = false;
	m_tInfo.iX = 2;
	m_tInfo.iY = 1;
	m_tInfo.str = "¡å";

	m_tInfo.iCX = strlen(m_tInfo.str);
	m_tInfo.iCY = 1;
}

void CCursor::Progress()
{
	if(GetAsyncKeyState(VK_UP) && !((m_tInfo.iY - TileSizeY) < 0) )
	{
		m_tInfo.iY -= TileSizeY;
		Sleep(50);
	}
	if(GetAsyncKeyState(VK_DOWN) && !((m_tInfo.iY + TileSizeY) > TileCntY * TileSizeY) )
	{
		m_tInfo.iY += TileSizeY;
		Sleep(50);
	}
	if(GetAsyncKeyState(VK_LEFT) && !((m_tInfo.iX - TileSizeX) < 0))
	{
		m_tInfo.iX -= TileSizeX;
		Sleep(50);
	}
	if(GetAsyncKeyState(VK_RIGHT) && !((m_tInfo.iX + TileSizeX) > TileCntX * TileSizeX))
	{
		m_tInfo.iX += TileSizeX;
		Sleep(50);
	}

	KeyCheck();
	AStar_Move(this);
}

void CCursor::Render()
{
	CDoubleBuffer::GetInst()->WriteBuffer(m_tInfo.iX, m_tInfo.iY, m_tInfo.str);

	CDoubleBuffer::GetInst()->WriteBuffer(0, 20, "X ÁÂÇ¥ : ");
	CDoubleBuffer::GetInst()->WriteBuffer(9, 20, m_tInfo.iX);

	CDoubleBuffer::GetInst()->WriteBuffer(20, 20, "Y ÁÂÇ¥ : ");
	CDoubleBuffer::GetInst()->WriteBuffer(29, 20, m_tInfo.iY);
}

void CCursor::Release()
{

}

void CCursor::KeyCheck(void)
{
	if (PUSH_KEY(KEY_F1))
	{
		if (m_bClicked)
			return;

		m_bClicked = true;

		INFO Info;
		Info.iX = (TileSizeX * TileCntX) - (int)(TileCntX/2);
		Info.iY = (TileSizeY * TileCntY) - (int)(TileCntY/2);

		AStar_Start(m_tInfo, Info);
	}
	else
		m_bClicked = false;
}
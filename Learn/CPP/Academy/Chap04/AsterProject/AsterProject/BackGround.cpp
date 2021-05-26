#include "BackGround.h"
#include"DoubleBuffer.h"
#include"Obj.h"




void CBackGround::Initialize()
{
	GET_SINGLE(CObjMgr)->InitTile();
	m_TileList = GET_SINGLE(CObjMgr)->getTileInfo();
	GET_SINGLE(CObjMgr)->InitCulsor();
	m_pCursor = GET_SINGLE(CObjMgr)->GetCursor();
}

void CBackGround::Progress()
{
	(*m_pCursor)->Progress();
}

void CBackGround::Render()
{
	for (vector<TILE*>::iterator iter = m_TileList->begin(); iter != m_TileList->end(); iter++) 
	{
		CDoubleBuffer::GetInst()->WriteBuffer((*iter)->iX, (*iter)->iY, (*iter)->str[0]);
		CDoubleBuffer::GetInst()->WriteBuffer((*iter)->iX, (*iter)->iY+1, (*iter)->str[1]);
		CDoubleBuffer::GetInst()->WriteBuffer((*iter)->iX, (*iter)->iY+2, (*iter)->str[2]);
		CDoubleBuffer::GetInst()->WriteBuffer((*iter)->iX+2, (*iter)->iY+1, (*iter)->iIndex);
	}

	(*m_pCursor)->Render();
}

void CBackGround::Release()
{
	m_pCursor;
	m_pCursor = NULL;
}

CBackGround::CBackGround()
{
}


CBackGround::~CBackGround()
{
	Release();
}

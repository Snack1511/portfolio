#include "Logo.h"
#include "SceneMgr.h"
#include "DoubleBuffer.h"
#include "Include.h"

CLogo::CLogo(void)
{
}


CLogo::~CLogo(void)
{
}


void CLogo::Initialize()
{
	m_iX = 0;
	m_iY = 0;

	m_pE[0] = "8 8888888888  ";
	m_pE[1] = "8 8888        ";
	m_pE[2] = "8 8888        ";
	m_pE[3] = "8 8888        ";
	m_pE[4] = "8 888888888888";
	m_pE[5] = "8 8888        ";
	m_pE[6] = "8 8888        ";
	m_pE[7] = "8 8888        ";
	m_pE[8] = "8 8888        ";
	m_pE[9] = "8 888888888888";

	m_pL[0] = "8 8888		 ";
	m_pL[1] = "8 8888        ";
	m_pL[2] = "8 8888        ";
	m_pL[3] = "8 8888        ";
	m_pL[4] = "8 8888        ";
	m_pL[5] = "8 8888        ";
	m_pL[6] = "8 8888        ";
	m_pL[7] = "8 8888        ";
	m_pL[8] = "8 8888        ";
	m_pL[9] = "8 888888888888";
	
	m_pN[0] = "b.             8"; 
	m_pN[1] = "888o.          8"; 
	m_pN[2] = "Y88888o.       8"; 
	m_pN[3] = ".`Y888888o.    8"; 
	m_pN[4] = "8o. `Y888888o. 8"; 
	m_pN[5] = "8`Y8o. `Y88888o8"; 
	m_pN[6] = "8   `Y8o. `Y8888"; 
	m_pN[7] = "8      `Y8o. `Y8"; 
	m_pN[8] = "8         `Y8o.`"; 
	m_pN[9] = "8            `Yo"; 

	m_pZ[0] = " 8888888888',8888'";
	m_pZ[1] = "        ,8',8888' ";
	m_pZ[2] = "       ,8',8888'  ";
	m_pZ[3] = "      ,8',8888'   ";
	m_pZ[4] = "     ,8',8888'    ";
	m_pZ[5] = "    ,8',8888'     ";
	m_pZ[6] = "   ,8',8888'      ";
	m_pZ[7] = "  ,8',8888'       ";
	m_pZ[8] = " ,8',8888'        ";
	m_pZ[9] = ",8',8888888888888 ";

	m_pI[0] = "8 8888";
	m_pI[1] = "8 8888";
	m_pI[2] = "8 8888";
	m_pI[3] = "8 8888";
	m_pI[4] = "8 8888";
	m_pI[5] = "8 8888";
	m_pI[6] = "8 8888";
	m_pI[7] = "8 8888";
	m_pI[8] = "8 8888";
	m_pI[9] = "8 8888";

	m_pA[0] = "        .8.         ";
	m_pA[1] = "       .888.        ";
	m_pA[2] = "      :88888.       ";
	m_pA[3] = "     . `88888.      ";
	m_pA[4] = "    .8. `88888.     ";
	m_pA[5] = "   .8`8. `88888.    ";
	m_pA[6] = "  .8' `8. `88888.   ";
	m_pA[7] = " .8'   `8. `88888.  ";
	m_pA[8] = ".888888888. `88888. ";
	m_pA[9] = "8'       `8. `88888.";

	m_CC = 0;
	m_tCount = GetTickCount();
	m_bCheck = true;
	m_iNumCount = 0;
}

void CLogo::Porgress()
{
	/*CSceneMgr::GetInstance()->SetScene(IDS_STAGE);*/

	DWORD tTime = 7000;

	if(GetAsyncKeyState(VK_UP))
	{
		if(m_tCount + 1000 < GetTickCount())
		{
			if(m_iY + 39 == (WINCY/2) + 10)
				m_iY += 6;
			else
				m_iY -= 2;
		}
	}

	if(GetAsyncKeyState(VK_DOWN))
	{
		if(m_tCount + 1000 < GetTickCount())
		{
			if(m_iY + 39 == (WINCY/2) + 16)
				m_iY -= 6;
			else
				m_iY += 2;
		}
	}

	if(GetAsyncKeyState(VK_RETURN) && m_iY == 0 && m_CC == 1)
	{
		CSceneMgr::GetInstance()->SetScene(IDS_STAGE);
	}
	
	if(GetAsyncKeyState(VK_RETURN) && m_iY == 2 && m_CC == 1)
	{
		CSceneMgr::GetInstance()->SetScene(IDS_STAGE);
	}

}

void CLogo::Render()
{
	
	DWORD tTime = 2000;

	if((m_tCount + tTime) < GetTickCount())
	{
		RandText((WINCX/2) - 53, (WINCY/2) - 15, IDS_E, 2000, 30);
	}

	if((m_tCount + tTime + 500) < GetTickCount())
	{
		RandText((WINCX/2) - 38, (WINCY/2) - 15, IDS_L, 2000, 60);
	}

	if((m_tCount + tTime + 1000) < GetTickCount())
	{
		RandText((WINCX/2) - 23, (WINCY/2) - 15, IDS_E, 2000, 90);
	}

	if((m_tCount + tTime + 1500) < GetTickCount())
	{
		RandText((WINCX/2) - 8, (WINCY/2) - 15, IDS_N, 2000, 120);
	}

	if((m_tCount + tTime + 2000) < GetTickCount())
	{
		RandText((WINCX/2) + 9, (WINCY/2) - 15, IDS_Z, 2000, 150);
	}

	if((m_tCount + tTime + 2500) < GetTickCount())
	{
		RandText((WINCX/2) + 28, (WINCY/2) - 15, IDS_I, 2000, 180);
	}

	if((m_tCount + tTime + 3000) < GetTickCount())
	{
		RandText((WINCX/2) + 35, (WINCY/2) - 15, IDS_A, 2000, 210);
	}

	if((m_tCount + tTime + 3500) < GetTickCount())
	{
		CDoubleBuffer::GetInst()->WriteBuffer(0, (WINCY - 26), "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", COLOR_REALWHITE);
		CDoubleBuffer::GetInst()->WriteBuffer((WINCX/2) - 6, (WINCY/2) + 10, "게임 시작", COLOR_REALWHITE);
		CDoubleBuffer::GetInst()->WriteBuffer((WINCX/2) - 6, (WINCY/2) + 12, "관리자 모드로 시작", COLOR_REALWHITE);
		CDoubleBuffer::GetInst()->WriteBuffer((WINCX/2) - 6, (WINCY/2) + 14, "환경 설정 (미구현)", COLOR_REALWHITE);
		CDoubleBuffer::GetInst()->WriteBuffer((WINCX/2) - 6, (WINCY/2) + 16, "불러오기 (미구현)", COLOR_REALWHITE);
		CDoubleBuffer::GetInst()->WriteBuffer(m_iX + 75, m_iY + 39, "▶", COLOR_REALWHITE);
		m_CC = 1;
	}
	
}

void CLogo::Release()
{

}

void CLogo::RandText(int _ix, int _iy, TEXTID _etextID,int _inum, int _countmax)
{
	
	DWORD tTime = _inum;
	char* str[10];
	int RandNum;
	m_iNumCount++;

	RandNum = rand()%5;

	if(m_iNumCount >= _countmax)
	{
		RandNum = _etextID;
	}

	switch(RandNum)
	{
	case IDS_E:
		{
			for (int i = 0 ; i < 10 ; i++)
			{
				str[i] = m_pE[i];
			}
		}
		break;
	case IDS_L:
		{
			for (int i = 0 ; i < 10 ; i++)
			{
				str[i] = m_pL[i];
			}
		}
		break;
	case IDS_N:
		{
			for (int i = 0 ; i < 10 ; i++)
			{
				str[i] = m_pN[i];
			}
		}
		break;
	case IDS_Z:
		{
			for (int i = 0 ; i < 10 ; i++)
			{
				str[i] = m_pZ[i];
			}
		}
		break;
	case IDS_I:
		{
			for (int i = 0 ; i < 10 ; i++)
			{
				str[i] = m_pI[i];
			}
		}
		break;
	case IDS_A:
		{
			for (int i = 0 ; i < 10 ; i++)
			{
				str[i] = m_pA[i];
			}
		}
		break;
	}
		
	if((m_tCount + tTime) < GetTickCount())
	{
		for(int i = 0 ; i < 10 ; i++)
		{
			CDoubleBuffer::GetInst()->WriteBuffer(_ix, _iy + i, str[i], COLOR_REALWHITE);
		}
	}
}

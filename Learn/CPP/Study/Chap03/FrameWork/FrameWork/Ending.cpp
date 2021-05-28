#include "Ending.h"
#include "SceneMgr.h"
#include "DoubleBuffer.h"
#include "Include.h"


CEnding::CEnding(void)
{
}


CEnding::~CEnding(void)
{
}

void CEnding::Initialize()
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

	m_pT[0] = "8888888 8888888888";
	m_pT[1] = "      8 8888      ";
	m_pT[2] = "      8 8888      ";
	m_pT[3] = "      8 8888      ";
	m_pT[4] = "      8 8888      ";
	m_pT[5] = "      8 8888      ";
	m_pT[6] = "      8 8888      ";
	m_pT[7] = "      8 8888      ";
	m_pT[8] = "      8 8888      ";
	m_pT[9] = "      8 8888      ";

	m_pD[0] = "8 888888888o.     ";
	m_pD[1] = "8 8888    `^888.  ";
	m_pD[2] = "8 8888        `88.";
	m_pD[3] = "8 8888         `88";
	m_pD[4] = "8 8888          88";
	m_pD[5] = "8 8888          88";
	m_pD[6] = "8 8888         ,88";
	m_pD[7] = "8 8888        ,88'";
	m_pD[8] = "8 8888    ,o88P'  ";
	m_pD[9] = "8 888888888P'     ";

	m_pH[0] = "8 8888        8";
	m_pH[1] = "8 8888        8";
	m_pH[2] = "8 8888        8";
	m_pH[3] = "8 8888        8";
	m_pH[4] = "8 8888        8";
	m_pH[5] = "8 8888        8";
	m_pH[6] = "8 8888888888888";
	m_pH[7] = "8 8888        8";
	m_pH[8] = "8 8888        8";
	m_pH[9] = "8 8888        8";


	m_tCount = GetTickCount();
	m_bCheck = true;
	m_iNumCount = 0;
}
void CEnding::Porgress()
{
	if(GetAsyncKeyState(VK_RETURN))
	{
		CSceneMgr::GetInstance()->SetScene(IDS_LOGO);
	}
}
void CEnding::Render()
{
	DWORD tTime = 1000;
	for(int i = 0 ; i < 10 ; i++)
	{
		CDoubleBuffer::GetInst()->WriteBuffer((WINCX) - 132, (WINCY) - 49 + i, m_pT[i], COLOR_REALWHITE);
		CDoubleBuffer::GetInst()->WriteBuffer((WINCX) - 113, (WINCY) - 49 + i, m_pH[i], COLOR_REALWHITE);
		CDoubleBuffer::GetInst()->WriteBuffer((WINCX) - 97, (WINCY) - 49 + i, m_pE[i], COLOR_REALWHITE);
		CDoubleBuffer::GetInst()->WriteBuffer((WINCX) - 82, (WINCY) - 49 + i, m_pE[i], COLOR_REALWHITE);
		CDoubleBuffer::GetInst()->WriteBuffer((WINCX) - 67, (WINCY) - 49 + i, m_pN[i], COLOR_REALWHITE);
		CDoubleBuffer::GetInst()->WriteBuffer((WINCX) - 50, (WINCY) - 49 + i, m_pD[i], COLOR_REALWHITE);
	}

	CDoubleBuffer::GetInst()->WriteBuffer((WINCX) - 108, (WINCY) - 35, " ENTER Key 를 누르면 처음으로 돌아갑니다.", COLOR_REALWHITE);

}
void CEnding::Release()
{

}


#include "GameOver.h"

#include "SceneMgr.h"
#include "DoubleBuffer.h"
#include "Include.h"

CGameOver::CGameOver(void)
{
}


CGameOver::~CGameOver(void)
{
} 

void CGameOver::Initialize()
{
	m_iX = 0;
	m_iY = 0;

	m_pG[0] = "    ,o888888o.   ";
	m_pG[1] = "   8888     `88. ";
	m_pG[2] = ",8 8888       `8.";
	m_pG[3] = "88 8888          ";
	m_pG[4] = "88 8888          ";
	m_pG[5] = "88 8888          ";
	m_pG[6] = "88 8888   8888888"; //17
	m_pG[7] = "`8 8888       .8'";
	m_pG[8] = "   8888     ,88' ";
	m_pG[9] = "    `8888888P'   ";

	m_pA[0] = "         .8.         "; 
	m_pA[1] = "        .888.        "; 
	m_pA[2] = "       :88888.       "; 
	m_pA[3] = "      . `88888.      "; 
	m_pA[4] = "     .8. `88888.     ";  //21
	m_pA[5] = "    .8`8. `88888.    "; 
	m_pA[6] = "   .8' `8. `88888.   "; 
	m_pA[7] = "  .8'   `8. `88888.  "; 
	m_pA[8] = " .888888888. `88888. "; 
	m_pA[9] = ".8'       `8. `88888.";

	m_pM[0] = "         ,8.       ,8.         ";
	m_pM[1] = "        ,888.     ,888.        ";
	m_pM[2] = "       .`8888.   .`8888.       ";
	m_pM[3] = "      ,8.`8888. ,8.`8888.      ";
	m_pM[4] = "     ,8'8.`8888,8^8.`8888.     ";
	m_pM[5] = "    ,8' `8.`8888' `8.`8888.    ";
	m_pM[6] = "   ,8'   `8.`88'   `8.`8888.   ";
	m_pM[7] = "  ,8'     `8.`'     `8.`8888.  ";
	m_pM[8] = " ,8'       `8        `8.`8888. ";
	m_pM[9] = ",8'         `         `8.`8888.";
			   
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

	m_pO[0] = "    ,o888888o.    ";
	m_pO[1] = " . 8888     `88.  ";
	m_pO[2] = ",8 8888       `8b ";
	m_pO[3] = "88 8888        `8b";
	m_pO[4] = "88 8888         88";
	m_pO[5] = "88 8888         88";
	m_pO[6] = "88 8888        ,8P";
	m_pO[7] = "`8 8888       ,8P ";
	m_pO[8] = " ` 8888     ,88'  ";
	m_pO[9] = "    `8888888P'    ";

	m_pV[0] = "`8.`888b           ,8'";
	m_pV[1] = " `8.`888b         ,8' ";
	m_pV[2] = "  `8.`888b       ,8'  ";
	m_pV[3] = "   `8.`888b     ,8'   ";
	m_pV[4] = "    `8.`888b   ,8'    ";
	m_pV[5] = "     `8.`888b ,8'     ";
	m_pV[6] = "      `8.`888b8'      ";
	m_pV[7] = "       `8.`888'       ";
	m_pV[8] = "        `8.`8'        ";
	m_pV[9] = "         `8.`         ";

	m_pR[0] = "8 888888888o.  ";
	m_pR[1] = "8 8888    `88. ";
	m_pR[2] = "8 8888     `88 ";
	m_pR[3] = "8 8888     ,88 ";
	m_pR[4] = "8 8888.   ,88' ";
	m_pR[5] = "8 888888888P'  ";
	m_pR[6] = "8 8888`8b      ";
	m_pR[7] = "8 8888 `8b.    ";
	m_pR[8] = "8 8888   `8b.  ";
	m_pR[9] = "8 8888     `88.";

	m_tCount = GetTickCount();
	m_bCheck = true;
	m_iNumCount = 0;
}

void CGameOver::Porgress()
{
	if(GetAsyncKeyState(VK_RETURN))
	{
		CSceneMgr::GetInstance()->SetScene(IDS_LOGO);
	}
}
void CGameOver::Render()
{
	DWORD tTime = 1000;
	for(int i = 0 ; i < 10 ; i++)
	{
		CDoubleBuffer::GetInst()->WriteBuffer(5, (WINCY) - 49 + i, m_pG[i], COLOR_REALWHITE);
		CDoubleBuffer::GetInst()->WriteBuffer(23 , (WINCY) - 49 + i, m_pA[i], COLOR_REALWHITE);
		CDoubleBuffer::GetInst()->WriteBuffer(44 , (WINCY) - 49 + i, m_pM[i], COLOR_REALWHITE);
		CDoubleBuffer::GetInst()->WriteBuffer(75, (WINCY) - 49 + i, m_pE[i], COLOR_REALWHITE);
		CDoubleBuffer::GetInst()->WriteBuffer(90 , (WINCY) - 49 + i, m_pO[i], COLOR_REALWHITE);
		CDoubleBuffer::GetInst()->WriteBuffer(108 , (WINCY) - 49 + i, m_pV[i], COLOR_REALWHITE);
		CDoubleBuffer::GetInst()->WriteBuffer(131 , (WINCY) - 49 + i, m_pE[i], COLOR_REALWHITE);
		CDoubleBuffer::GetInst()->WriteBuffer(145, (WINCY) - 49 + i, m_pR[i], COLOR_REALWHITE);

	}

	CDoubleBuffer::GetInst()->WriteBuffer((WINCX) - 108, (WINCY) - 35, " ENTER Key 를 누르면 처음으로 돌아갑니다.", COLOR_REALWHITE);

}
void CGameOver::Release()
{

}


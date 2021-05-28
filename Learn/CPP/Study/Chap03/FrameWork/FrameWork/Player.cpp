#include "Player.h"
#include "Include.h"
#include "KeyMgr.h"
#include "ObjFactory.h"
#include "Collision.h"


CPlayer::CPlayer(void)
{
}


CPlayer::~CPlayer(void)
{
	Release();
}

void CPlayer::Initialize(int _idata)
{
	m_Info = INFO(1, 1, 1, 100, 10, 10);
	m_Info.iScore = 0;
	m_dwState = STATE_RSTAND;
	m_dwDirection = STATE_RIGHT;
	m_Info.iX = 10;
	m_Info.iY = ((WINCY - 50) - (1 - PLAYERSIZE));
	m_OutputCount = 0;

	m_pBasicPosture[0]	 = " ";
	m_pBasicPosture[1]	 = " ";
	m_pBasicPosture[2]	 = " ";
	m_pBasicPosture[3]	 = " ";
	m_pBasicPosture[4]	 = " ";
	m_pBasicPosture[5]	 = " ";
	m_pBasicPosture[6]	 = " ";
	m_pBasicPosture[7]	 = " ";

	PlayerSizeCheck((m_Info.iX + 10), m_Info.iX, m_Info.iX, m_Info.iX, (m_Info.iX + 2), (m_Info.iX + 4), (m_Info.iX + 8), (m_Info.iX + 8), m_Info.iY, strlen(m_pBasicPosture[0]));
	m_Info.iCY = PLAYERSIZE;

	for(int i = 0 ; i < MAX ; i++)
	{
		bCheck[i] = false;
		m_pBullet[i] = NULL;
	}
	for(int i = 0 ; i < MONSTERMAX ; i++)
	{
		m_bObjCheck[i] = false;
	}

}

int CPlayer::Porgress(bool _check)
{
	KeyCheck();
	Motion();
	//CheckBullet();

	if(!(m_Info.iY > ((WINCY - 27) - PLAYERSIZE))/* && !(GetAsyncKeyState(VK_SPACE))*/)
		m_Info.iY += gravity;

	if(m_Info.iX <= 2)
		m_Info.iX = 2;

	if(m_Info.iX >= (WINCX - 21))
		m_Info.iX = (WINCX - 21);

	if(m_Info.iY <= 2)
	{
		m_Info.iY = 2;
	}
	if(m_Info.iY >= ((WINCY - 25) - PLAYERSIZE))
	{
		m_Info.iY = ((WINCY - 25) - PLAYERSIZE) - 1;
	}
	/*for(int i = 0 ; i < MAX ; i++)
	{
		if(bCheck[i] == true) 
		{
			bool Check = true;

			for (int j = 0 ; j < MONSTERMAX ; j++)
			{				
				if(CCollision::CollisionMgr(m_pBullet[i]->GetInfo(), m_pObjInfo[j]))
				{
					if(m_pObjInfo[j].iLife - m_pBullet[i]->GetInfo().iAtt <= 0)
					{
						m_Info.iExp += m_pObjInfo[j].iExp;
						m_pObjInfo[j].iLife = 0;
					}
					else
					{
						m_pObjInfo[j].iLife -= m_pBullet[i]->GetInfo().iAtt;
					}
					Check = false;
				}
			}
			m_pBullet[i]->Porgress(Check);
		}
	}

	for (int j = 0 ; j < MONSTERMAX ; j++)
	{
		if(CCollision::CollisionMgr(m_Info, m_pObjInfo[j]) && (m_pObjInfo[j].iJob == 1))
		{
			if(m_Info.iLife - m_pObjInfo[j].iAtt <= 0)
			{
				m_Info.iLife = 0;
			}
			else
			{
				m_Info.iLife -= m_pObjInfo[j].iAtt;
			}
		}
		if(CCollision::CollisionMgr(m_Info,m_pObjInfo[j]) && (m_dwState & STATE_LATT || m_dwState & STATE_RATT))
		{
			if(m_pObjInfo[j].iLife - m_Info.iAtt <= 0)
			{
				m_Info.iExp += m_pObjInfo[j].iExp;
				m_pObjInfo[j].iLife = 0;
			}
			else
			{
				m_pObjInfo[j].iLife -= m_Info.iAtt;
			}
		}
	}

	if(m_Info.iExp >= m_Info.iLevel * 200)
	{
		m_Info.iLevel += 1;
		m_Info.iExp = 0;
		m_OutputCount = 1;

		m_Info.iLife = m_Info.iLevel * 100;
		m_Info.iMAX_Life = m_Info.iLevel * 100;
		m_Info.iMP = m_Info.iLevel * 50;
		m_Info.iMAXMP = m_Info.iLevel * 50;
		m_Info.iAtt = m_Info.iLevel * 20;
		m_Info.iDef = m_Info.iLevel * 10;
	}*/
	return 0;
}

void CPlayer::Render()
{
	for (int i = 0 ; i < PLAYERSIZE ; i++)
	{
		CDoubleBuffer::GetInst()->WriteBuffer(m_ObjSize.iX[i], m_Info.iY + i, m_pBasicPosture[i], COLOR_REALWHITE);
	}

	if(m_OutputCount > 0 && m_OutputCount < 30)
	{
		++m_OutputCount;
		CDoubleBuffer::GetInst()->WriteBuffer(m_Info.iX, m_Info.iY - 4, "레벨이 올랐습니다", COLOR_PASTEL_YELLOW);
		if(m_OutputCount == 30)
			m_OutputCount = 0;
	}
	if(m_OutputCount > 30 && m_OutputCount < 45)
	{
		++m_OutputCount;
		CDoubleBuffer::GetInst()->WriteBuffer(m_Info.iX, m_Info.iY - 4, "마력이 부족합니다.", COLOR_PASTEL_BLUE);
		if(m_OutputCount == 45)
			m_OutputCount = 0;
	}


	//ObjHpBarOutput();

	for(int i = 0 ; i < MAX ; i++)
	{
		if(bCheck[i] == true)
			m_pBullet[i]->Render();
	}
	
}

void CPlayer::Release()
{
	delete[] &m_pBullet;
	for(int i = 0 ; i < MAX ; i++)
	{
		m_pBullet[i] = NULL;
	}

	
}

void CPlayer::KeyCheck()
{
	m_dwKey = CKeyMgr::GetInst()->GetKey();

	if(m_dwKey & KEY_UP)
	{
		/*m_Info.iY -= 1;*/
		m_Info.iScore += 50;
	}
	if(m_dwKey & KEY_DOWN)
	{
		/*m_Info.iY += 1;*/

	}
	if(m_dwKey & KEY_LEFT)
	{
		m_Info.iX -= 2;
		m_dwDirection = STATE_LEFT;
	}
	if(m_dwKey & KEY_RIGHT)
	{
		m_Info.iX += 2;
		m_dwDirection = STATE_RIGHT;
	}
	if(m_dwKey & KEY_Z && m_dwDirection & STATE_RIGHT)
	{
		m_dwState = STATE_RATT;
	}
	if(m_dwKey & KEY_Z && m_dwDirection & STATE_LEFT)
	{
		m_dwState = STATE_LATT;
	}
	if(m_dwKey & KEY_ESCAPE)
	{
		EXIT = false;
	}
	if (m_Info.iY > ((WINCY - 27) - PLAYERSIZE))
	{
		
		if (m_dwKey & KEY_SPACE)
		{
			m_Info.iY -= (gravity + JumpPower);
			for (int i = 0; i < m_Info.iJump; i++) {

				m_Info.iY -= JumpPower;
			}
		}
		
	}
	/*if(m_dwKey & KEY_X)
	{
		

		if(m_Info.iMP >= 5)
		{
			m_Info.iMP -= 5;
			for(int i = 0 ; i < MAX ; i++)
			{
				if(bCheck[i] == false)
				{				
					bCheck[i] = true;
					m_pBullet[i] = CObjFactory::CreateBullet(m_Info.iX + 20, m_Info.iY + 4, m_Info.iLevel);
					if((m_dwState & STATE_LATT || m_dwState & STATE_LSTAND))
						m_pBullet[i]->SetCheck(true);
					else
						m_pBullet[i]->SetCheck(false);
					break;
				}
			}
		}
		else
		{
			m_OutputCount = 31;
		}
	}*/
}

void CPlayer::Motion()
{
	if(!(m_dwKey & KEY_Z) && (m_dwDirection & STATE_LEFT || m_dwDirection & STATE_RIGHT))
	{
		if(m_dwDirection & STATE_LEFT)
			m_dwState = STATE_LSTAND;
		if(m_dwDirection & STATE_RIGHT)
			m_dwState = STATE_RSTAND;
	}

	if(!m_dwKey)
	{
		if(m_dwDirection & STATE_LEFT)
		{
			m_dwState = STATE_LSTAND;
			m_pBasicPosture[0]	 = "△    ●●";
			m_pBasicPosture[1]	 = "△  ●    ●      ☞";
			m_pBasicPosture[2]	 = "△  ●    ●    ☞☞";
			m_pBasicPosture[3]	 = "△    ●●    ☞☞☞";
			m_pBasicPosture[4]	 = "■  ▤▤▤▧  ☞☞";
			m_pBasicPosture[5]	 = "■■▨▤▧▥☞☞";
			m_pBasicPosture[6]	 =     "▥♧▨▥";
			m_pBasicPosture[7]	 =     "▧▤▤▨";
			PlayerSizeCheck(m_Info.iX, m_Info.iX, m_Info.iX, m_Info.iX, m_Info.iX, m_Info.iX, (m_Info.iX + 4), (m_Info.iX + 4), m_Info.iY, 20);
		}

		if(m_dwDirection & STATE_RIGHT)
		{
			m_dwState = STATE_RSTAND;

			m_pBasicPosture[0]	 =	         "●●    △";
			m_pBasicPosture[1]	 = "☜      ●    ●  △";
			m_pBasicPosture[2]	 = "☜☜    ●    ●  △";
			m_pBasicPosture[3]	 = "☜☜☜    ●●    △";
			m_pBasicPosture[4]	 =	 "☜☜  ▨▤▤▤  ■";
			m_pBasicPosture[5]	 =     "☜☜▥▨▤▧■■";
			m_pBasicPosture[6]	 =         "▥▧♧▥";
			m_pBasicPosture[7]	 =         "▧▤▤▨";

			PlayerSizeCheck((m_Info.iX + 10), m_Info.iX, m_Info.iX, m_Info.iX, (m_Info.iX + 2), (m_Info.iX + 4), (m_Info.iX + 8), (m_Info.iX + 8), m_Info.iY, 20);
		}
		
	}

	if(m_dwState & STATE_RSTAND && m_dwKey & KEY_RIGHT)
	{
		m_pBasicPosture[0]	 =	         "●●    △";
		m_pBasicPosture[1]	 = "☜      ●    ●  △";
		m_pBasicPosture[2]	 = "☜☜    ●    ●  △";
		m_pBasicPosture[3]	 = "☜☜☜    ●●    △";
		m_pBasicPosture[4]	 =	 "☜☜  ▨▤▤▤  ■";
		m_pBasicPosture[5]	 =     "☜☜▥▨▤▧■■";
		m_pBasicPosture[6]	 =         "▥▧♧▥";
		m_pBasicPosture[7]	 =         "▧▤▤▨";

		PlayerSizeCheck((m_Info.iX + 10), m_Info.iX, m_Info.iX, m_Info.iX, (m_Info.iX + 2), (m_Info.iX + 4), (m_Info.iX + 8), (m_Info.iX + 8), m_Info.iY, 20);
	}

	if(m_dwState & STATE_LSTAND && m_dwKey & KEY_LEFT)
	{
		m_pBasicPosture[0]	 = "△    ●●  ";
		m_pBasicPosture[1]	 = "△  ●    ●      ☞";
		m_pBasicPosture[2]	 = "△  ●    ●    ☞☞";
		m_pBasicPosture[3]	 = "△    ●●    ☞☞☞";
		m_pBasicPosture[4]	 = "■  ▤▤▤▧  ☞☞";
		m_pBasicPosture[5]	 = "■■▨▤▧▥☞☞";
		m_pBasicPosture[6]	 =     "▥♧▨▥";
		m_pBasicPosture[7]	 =     "▧▤▤▨";
		PlayerSizeCheck(m_Info.iX, m_Info.iX, m_Info.iX, m_Info.iX, m_Info.iX, m_Info.iX, (m_Info.iX + 4), (m_Info.iX + 4), m_Info.iY, 20);
	}

	if(m_dwState & STATE_LATT )
	{
		m_pBasicPosture[0]	 =                 "●●";
		m_pBasicPosture[1]	 =               "●    ●      ☞";
		m_pBasicPosture[2]	 =               "●    ●    ☞☞";
		m_pBasicPosture[3]	 =                 "●●    ☞☞☞";
		m_pBasicPosture[4]	 =               "▤▤▤▧  ☞☞";
		m_pBasicPosture[5]	 = "◁◁◁◁■■■▨▤▧▥☞☞";
		m_pBasicPosture[6]	 =               "▥♧▨▥";
		m_pBasicPosture[7]	 =               "▧▤▤▨";
		PlayerSizeCheck((m_Info.iX + 6), (m_Info.iX + 4), (m_Info.iX + 4), (m_Info.iX + 6), (m_Info.iX + 4), (m_Info.iX - 10), (m_Info.iX + 4), (m_Info.iX + 4), m_Info.iY, 20);
	}
	if(m_dwState & STATE_RATT)
	{
		m_pBasicPosture[0]	 = 	         "●●";
		m_pBasicPosture[1]	 = "☜      ●    ●";
		m_pBasicPosture[2]	 = "☜☜    ●    ●";
		m_pBasicPosture[3]	 = "☜☜☜    ●●";
		m_pBasicPosture[4]	 = 	 "☜☜  ▨▤▤▤";
		m_pBasicPosture[5]	 =     "☜☜▥▨▤▧■■■▷▷▷▷";
		m_pBasicPosture[6]	 =         "▥▧♧▥";
		m_pBasicPosture[7]	 =         "▧▤▤▨";
		PlayerSizeCheck((m_Info.iX + 10), m_Info.iX, m_Info.iX, m_Info.iX, (m_Info.iX + 2), (m_Info.iX + 4), (m_Info.iX + 8), (m_Info.iX + 8), m_Info.iY, 29);
	}
}

void CPlayer::CheckBullet()
{
	for(int i = 0 ; i < MAX ; i++)
	{
		if(bCheck[i] == true)
		{
			if(((CBullet*)m_pBullet[i])->GetBullet().bCheck == false)
			{
				bCheck[i] = false;
				m_pBullet[i] = NULL;
			}
		}
	}
}

void CPlayer::PlayerSizeCheck(int _num0, int _num1, int _num2, int _num3, int _num4, int _num5, int _num6, int _num7, int _iy, int _icx)
{
	m_Info.iCX = _icx;
	m_ObjSize.iY = _iy;	

	m_ObjSize.iX[0] = _num0;
	m_ObjSize.iX[1] = _num1;
	m_ObjSize.iX[2] = _num2;
	m_ObjSize.iX[3] = _num3;
	m_ObjSize.iX[4] = _num4;
	m_ObjSize.iX[5] = _num5;
	m_ObjSize.iX[6] = _num6;
	m_ObjSize.iX[7] = _num7;
}

void CPlayer::ObjHpBarOutput()
{
	if(m_Info.iLife >= (m_Info.iMAX_Life * 0.8) && m_Info.iLife <= m_Info.iMAX_Life)
	{
		CDoubleBuffer::GetInst()->WriteBuffer(m_Info.iX + 2, m_Info.iY - 2, "■■■■■ ", m_Info.iLife, "/", m_Info.iMAX_Life, "", COLOR_PASTEL_RED);
	}
	if(m_Info.iLife >= (m_Info.iMAX_Life * 0.6) && m_Info.iLife < (m_Info.iMAX_Life * 0.8))
	{
		CDoubleBuffer::GetInst()->WriteBuffer(m_Info.iX + 2, m_Info.iY - 2, "■■■■□ ", m_Info.iLife, "/", m_Info.iMAX_Life, "", COLOR_PASTEL_RED);
	}
	else if(m_Info.iLife >= (m_Info.iMAX_Life * 0.4) && (m_Info.iLife < m_Info.iMAX_Life * 0.6))
	{
		CDoubleBuffer::GetInst()->WriteBuffer(m_Info.iX + 2, m_Info.iY - 2, "■■■□□ ", m_Info.iLife, "/", m_Info.iMAX_Life, "", COLOR_PASTEL_RED);
	}
	else if(m_Info.iLife >= (m_Info.iMAX_Life * 0.2) && (m_Info.iLife < m_Info.iMAX_Life * 0.4))
	{
		CDoubleBuffer::GetInst()->WriteBuffer(m_Info.iX + 2, m_Info.iY - 2, "■■□□□ ", m_Info.iLife, "/", m_Info.iMAX_Life, "", COLOR_PASTEL_RED);
	}
	else if(m_Info.iLife > (m_Info.iMAX_Life * 0) && (m_Info.iLife < m_Info.iMAX_Life * 0.2))
	{
		CDoubleBuffer::GetInst()->WriteBuffer(m_Info.iX + 2, m_Info.iY - 2, "■□□□□ ", m_Info.iLife, "/", m_Info.iMAX_Life, "", COLOR_PASTEL_RED);
	}
	else if(m_Info.iLife == (m_Info.iMAX_Life * 0))
	{
		CDoubleBuffer::GetInst()->WriteBuffer(m_Info.iX + 2, m_Info.iY - 2, "□□□□□ ", m_Info.iLife, "/", m_Info.iMAX_Life, "", COLOR_PASTEL_RED);
	}
}
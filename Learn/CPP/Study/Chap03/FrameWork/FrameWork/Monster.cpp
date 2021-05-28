#include "Monster.h"
#include "Include.h"
#include "KeyMgr.h"
#include "ObjFactory.h"
#include "Collision.h"


CMonster::CMonster(void)
{
}


CMonster::~CMonster(void)
{
}


void CMonster::Initialize(int _idata)
{
	m_Info = INFO(1, 80, 80, 25, 20, 1);

	//MonsterLevelChoice(_idata);


	m_pBasicPosture[0] = "	   ¡ã\n";
	m_pBasicPosture[1] = "	  ¡á¡á\n";
	m_pBasicPosture[2] = "	 ¡á¡á¡á\n";
	m_pBasicPosture[3] = "¡ã¡á¡á¡á¡á¡ã\n";
	m_pBasicPosture[4] = "¡á¡á¡á¡á¡á¡á\n";

	PlayerSizeCheck((m_Info.iX), (m_Info.iX), (m_Info.iX), (m_Info.iX), (m_Info.iX), (m_Info.iY), 1);

	m_Info.iCY = MONSTERSIZE_S;
	m_Info.iScore = 50;

	m_iCount = 0;

	m_Monster.bCheck = true;
	m_Monster.str = "Monster";
	m_Info.iCX = strlen(m_Monster.str);
}

int CMonster::Porgress(bool _check)
{

	KeyCheck();
	Motion();

	/*if(m_Info.iX <= 15)
		m_Info.iX = 15;
		*/
	if(m_Info.iX >= (WINCX))
		m_Info.iX = (WINCX);

	/*if(m_Info.iY <= 2)
	{
		m_Info.iY = 2;
	}*/
	if(m_Info.iY >= ((WINCY) - MONSTERSIZE_S))
	{
		m_Info.iY = ((WINCY) - MONSTERSIZE_S);
	}

	if(m_Info.iLife <= 0)
	{
		m_Monster.bCheck = false;
		return 1;
	}
	return 0;
}

void CMonster::Render()
{
	for (int i = 0 ; i < MONSTERSIZE_S ; i++)
	{
		CDoubleBuffer::GetInst()->WriteBuffer(m_ObjSize.iMonster_SX[i], m_Info.iY + i, m_pBasicPosture[i], COLOR_PASTEL_PURPLE);
	}

//	ObjHpBarOutput();
}

void CMonster::Release()
{

}

void CMonster::KeyCheck()
{
	m_dwKey |= KEY_LEFT;
	//m_dwKey = 0;
	//m_iCount++;
	
	/*if (m_iCount >= 5)
	{
		m_ObjAction = rand()%5 + 1;

		switch(m_ObjAction)
		{
		case 1:
			m_dwKey |= KEY_UP;
			break;
		case 2:
			m_dwKey |= KEY_DOWN;
			break;
		case 3:
			m_dwKey |= KEY_LEFT;
			break;
		case 4:
			m_dwKey |= KEY_RIGHT;
			break;
		case 5:
			m_dwKey |= KEY_Z;
			break;
		}
		m_iCount = 0;
	}*/

	/*if(m_dwKey & KEY_UP)
	{
		m_Info.iY -= 2;
	}
	if(m_dwKey & KEY_DOWN)
	{
		m_Info.iY += 2;
	}	*/
	if(m_dwKey & KEY_LEFT)
	{
		m_Info.iX -= 2;
		//m_dwDirection = STATE_LEFT;
	}
	/*if(m_dwKey & KEY_RIGHT)
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
	}*/
	/*if(m_dwKey & KEY_X)
	{
		for(int i = 0 ; i < MAX ; i++)
		{
			if(bCheck[i] == false)
			{
				bCheck[i] = true;
				m_pBullet[i] = CObjFactory::CreateBullet(m_Info.iX, m_Info.iY);
				break;
			}
		}
	}*/
}

void CMonster::Motion()
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
			m_pBasicPosture[0] = "	   ¡ã\n";
			m_pBasicPosture[1] = "	  ¡á¡á\n";
			m_pBasicPosture[2] = "	 ¡á¡á¡á\n";
			m_pBasicPosture[3] = "¡ã¡á¡á¡á¡á¡ã\n";
			m_pBasicPosture[4] = "¡á¡á¡á¡á¡á¡á\n";
			//m_Info.iJob = 0;
			PlayerSizeCheck((m_Info.iX ), (m_Info.iX ), (m_Info.iX), (m_Info.iX ), (m_Info.iX ), (m_Info.iY), 16);
		}

		if(m_dwDirection & STATE_RIGHT)
		{
			m_dwState = STATE_RSTAND;

			m_pBasicPosture[0] = "	   ¡ã\n";
			m_pBasicPosture[1] = "	  ¡á¡á\n";
			m_pBasicPosture[2] = "	 ¡á¡á¡á\n";
			m_pBasicPosture[3] = "¡ã¡á¡á¡á¡á¡ã\n";
			m_pBasicPosture[4] = "¡á¡á¡á¡á¡á¡á\n";
			//m_Info.iJob = 0;
			PlayerSizeCheck((m_Info.iX ), (m_Info.iX ), (m_Info.iX ), (m_Info.iX ), (m_Info.iX), (m_Info.iY), 16);
		}

	}

	if(m_dwState & STATE_RSTAND && m_dwKey & KEY_RIGHT)
	{
		m_pBasicPosture[0] = "	   ¡ã\n";
		m_pBasicPosture[1] = "	  ¡á¡á\n";
		m_pBasicPosture[2] = "	 ¡á¡á¡á\n";
		m_pBasicPosture[3] = "¡ã¡á¡á¡á¡á¡ã\n";
		m_pBasicPosture[4] = "¡á¡á¡á¡á¡á¡á\n";
		//m_Info.iJob = 0;
		PlayerSizeCheck((m_Info.iX ), (m_Info.iX ), (m_Info.iX ), (m_Info.iX ), (m_Info.iX), (m_Info.iY), 16);
	}

	if(m_dwState & STATE_LSTAND && m_dwKey & KEY_LEFT)
	{
		m_pBasicPosture[0] = "	   ¡ã\n";
		m_pBasicPosture[1] = "	  ¡á¡á\n";
		m_pBasicPosture[2] = "	 ¡á¡á¡á\n";
		m_pBasicPosture[3] = "¡ã¡á¡á¡á¡á¡ã\n";
		m_pBasicPosture[4] = "¡á¡á¡á¡á¡á¡á\n";
		//m_Info.iJob = 0;
		PlayerSizeCheck((m_Info.iX ), (m_Info.iX ), (m_Info.iX), (m_Info.iX ), (m_Info.iX ), (m_Info.iY), 16);
	}

	if(m_dwState & STATE_LATT )
	{
		m_pBasicPosture[0] = "	   ¡ã\n";
		m_pBasicPosture[1] = "	  ¡á¡á\n";
		m_pBasicPosture[2] = "	 ¡á¡á¡á\n";
		m_pBasicPosture[3] = "¡ã¡á¡á¡á¡á¡ã\n";
		m_pBasicPosture[4] = "¡á¡á¡á¡á¡á¡á\n";
		//m_Info.iJob = 1;
		PlayerSizeCheck((m_Info.iX), (m_Info.iX ), (m_Info.iX ), (m_Info.iX ), (m_Info.iX ), (m_Info.iY), 16);
	}
	if(m_dwState & STATE_RATT)
	{
		m_pBasicPosture[0] = "	   ¡ã\n";
		m_pBasicPosture[1] = "	  ¡á¡á\n";
		m_pBasicPosture[2] = "	 ¡á¡á¡á\n";
		m_pBasicPosture[3] = "¡ã¡á¡á¡á¡á¡ã\n";
		m_pBasicPosture[4] = "¡á¡á¡á¡á¡á¡á\n";
		//m_Info.iJob = 1;
		PlayerSizeCheck((m_Info.iX), (m_Info.iX), (m_Info.iX), (m_Info.iX), (m_Info.iX), (m_Info.iY), 16);
	}
}

void CMonster::PlayerSizeCheck(int _num0, int _num1, int _num2, int _num3, int _num4, int _iy, int _icx)
{
	m_Info.iCX = _icx;
	m_ObjSize.iY = _iy;	

	m_ObjSize.iMonster_SX[0] = _num0;
	m_ObjSize.iMonster_SX[1] = _num1;
	m_ObjSize.iMonster_SX[2] = _num2;
	m_ObjSize.iMonster_SX[3] = _num3;
	m_ObjSize.iMonster_SX[4] = _num4;
}

/*void CMonster::ObjHpBarOutput()
{
	if(m_Info.iLife >= (m_Info.iMAX_Life * 0.8) && m_Info.iLife <= m_Info.iMAX_Life)
	{
		//CDoubleBuffer::GetInst()->WriteBuffer(m_Info.iX - 6, m_Info.iY - 2, "Lv ", m_Info.iLevel, "", COLOR_PASTEL_RED);
		CDoubleBuffer::GetInst()->WriteBuffer(m_Info.iX, m_Info.iY - 2, "¡á¡á¡á¡á¡á ", m_Info.iLife, "/", m_Info.iMAX_Life, "", COLOR_PASTEL_RED);
	}
	if(m_Info.iLife >= (m_Info.iMAX_Life * 0.6) && m_Info.iLife < (m_Info.iMAX_Life * 0.8))
	{
		//CDoubleBuffer::GetInst()->WriteBuffer(m_Info.iX - 6, m_Info.iY - 2, "Lv ", m_Info.iLevel, "", COLOR_PASTEL_RED);
		CDoubleBuffer::GetInst()->WriteBuffer(m_Info.iX, m_Info.iY - 2, "¡á¡á¡á¡á¡à ", m_Info.iLife, "/", m_Info.iMAX_Life, "", COLOR_PASTEL_RED);
	}
	else if(m_Info.iLife >= (m_Info.iMAX_Life * 0.4) && (m_Info.iLife < m_Info.iMAX_Life * 0.6))
	{
		//CDoubleBuffer::GetInst()->WriteBuffer(m_Info.iX - 6, m_Info.iY - 2, "Lv ", m_Info.iLevel, "", COLOR_PASTEL_RED);
		CDoubleBuffer::GetInst()->WriteBuffer(m_Info.iX, m_Info.iY - 2, "¡á¡á¡á¡à¡à ", m_Info.iLife, "/", m_Info.iMAX_Life, "", COLOR_PASTEL_RED);
	}
	else if(m_Info.iLife >= (m_Info.iMAX_Life * 0.2) && (m_Info.iLife < m_Info.iMAX_Life * 0.4))
	{
		//CDoubleBuffer::GetInst()->WriteBuffer(m_Info.iX - 6, m_Info.iY - 2, "Lv ", m_Info.iLevel, "", COLOR_PASTEL_RED);
		CDoubleBuffer::GetInst()->WriteBuffer(m_Info.iX, m_Info.iY - 2, "¡á¡á¡à¡à¡à ", m_Info.iLife, "/", m_Info.iMAX_Life, "", COLOR_PASTEL_RED);
	}
	else if(m_Info.iLife > (m_Info.iMAX_Life * 0) && (m_Info.iLife < m_Info.iMAX_Life * 0.2))
	{
		//CDoubleBuffer::GetInst()->WriteBuffer(m_Info.iX - 6, m_Info.iY - 2, "Lv ", m_Info.iLevel, "", COLOR_PASTEL_RED);
		CDoubleBuffer::GetInst()->WriteBuffer(m_Info.iX, m_Info.iY - 2, "¡á¡à¡à¡à¡à ", m_Info.iLife, "/", m_Info.iMAX_Life, "", COLOR_PASTEL_RED);
	}
	else if(m_Info.iLife == (m_Info.iMAX_Life * 0))
	{
		//CDoubleBuffer::GetInst()->WriteBuffer(m_Info.iX - 6, m_Info.iY - 2, "Lv ", m_Info.iLevel, "", COLOR_PASTEL_RED);
		CDoubleBuffer::GetInst()->WriteBuffer(m_Info.iX, m_Info.iY - 2, "¡à¡à¡à¡à¡à ", m_Info.iLife, "/", m_Info.iMAX_Life, "", COLOR_PASTEL_RED);
	}
}*/

/*void CMonster::MonsterLevelChoice(int _playerlevel)
{
	int Num = rand()%_playerlevel + _playerlevel;

	m_Info = INFO(Num, Num * 50, Num * 50, Num * 10, Num * 20, Num * 10);
}*/
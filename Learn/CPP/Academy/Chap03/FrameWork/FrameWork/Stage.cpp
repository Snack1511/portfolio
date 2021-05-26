#include "Stage.h"
#include "SceneMgr.h"
#include "ObjFactory.h"
#include "Include.h"
#include "Collision.h"
#include "CursorMgr.h"
#include "KeyMgr.h"


CStage::CStage(void)
{
}


CStage::~CStage(void)
{
}


void CStage::Initialize()
{
	m_pBackGround = CObjFactory::CreateBackGround();
	m_pPlayer = CObjFactory::CreatePlayer();
	for (int i = 0 ; i < MONSTERMAX ; i++)
	{
		bCheck[i] = false;
		m_pMonster[i] = NULL;
	}

	m_cBasicAttack[0]	= " 기본 공격";
	m_cBasicAttack[1]	= " Key : Z ";
	m_cBasicAttack[2]	= " ";
	m_cBasicAttack[3]	= " 좌측이동  우측이동";
	m_cBasicAttack[4]	= " Key : ←  Key : →";
	m_cBasicAttack[5]	= " ";
	m_cBasicAttack[6]	= " 날기";
	m_cBasicAttack[7]	= " Key : SPACE ";


	m_cSkillAttack[0]	= " 스킬 공격    ◀■◑";
	m_cSkillAttack[1]	= "   Key : X  ◀■■◑";
	m_cSkillAttack[2]	= "              ◀■◑";

	m_cHpBar100[0]	= "H .  ■■ ■■ ■■ ■■ ■■";
	m_cHpBar100[1]	= "P '  ■■ ■■ ■■ ■■ ■■";

	m_cHpBar80[0]	= "H .  ■■ ■■ ■■ ■■ □□";
	m_cHpBar80[1]	= "P '  ■■ ■■ ■■ ■■ □□";

	m_cHpBar60[0]	= "H .  ■■ ■■ ■■ □□ □□";
	m_cHpBar60[1]	= "P '  ■■ ■■ ■■ □□ □□";

	m_cHpBar40[0]	= "H .  ■■ ■■ □□ □□ □□";
	m_cHpBar40[1]	= "P '  ■■ ■■ □□ □□ □□";

	m_cHpBar20[0]	= "H .  ■■ □□ □□ □□ □□";
	m_cHpBar20[1]	= "P '  ■■ □□ □□ □□ □□";

	m_cHpBar0[0]	= "H .  □□ □□ □□ □□ □□";
	m_cHpBar0[1]	= "P '  □□ □□ □□ □□ □□";

	/*m_cMpBar100[0]	= "M .  ■■ ■■ ■■ ■■ ■■";
	m_cMpBar100[1]	= "P '  ■■ ■■ ■■ ■■ ■■";
	   
	m_cMpBar80[0]	= "M .  ■■ ■■ ■■ ■■ □□";
	m_cMpBar80[1]	= "P '  ■■ ■■ ■■ ■■ □□";
	   
	m_cMpBar60[0]	= "M .  ■■ ■■ ■■ □□ □□";
	m_cMpBar60[1]	= "P '  ■■ ■■ ■■ □□ □□";
	   
	m_cMpBar40[0]	= "M .  ■■ ■■ □□ □□ □□";
	m_cMpBar40[1]	= "P '  ■■ ■■ □□ □□ □□";
	   
	m_cMpBar20[0]	= "M .  ■■ □□ □□ □□ □□";
	m_cMpBar20[1]	= "P '  ■■ □□ □□ □□ □□";
	   
	m_cMpBar0[0]	= "M .  □□ □□ □□ □□ □□";
	m_cMpBar0[1]	= "P '  □□ □□ □□ □□ □□";*/

	//m_iQuestCount = 0;
	m_iMonsterDieCount = 0;
	m_ZenCount = 25;
	m_dwCount = GetTickCount();
}

void CStage::Porgress()
{
	m_ZenCount++;
	if(m_ZenCount >= 30)
	{
		m_MonsterPosX = (WINCX - 21);
		m_MonsterPosY = ((WINCY - 23));
		for (int i = 0 ; i < MONSTERMAX ; i++)
		{
			if(bCheck[i] == false)
			{
				bCheck[i] = true;
				m_pMonster[i] = CObjFactory::CreateMonster(m_MonsterPosX, m_MonsterPosY, 1);
				break;
			}
		}
		m_ZenCount = 0;
	}

	m_pBackGround->Porgress(true);
	for(int i = 0 ; i < MONSTERMAX ; i++)
	{
		if(bCheck[i] == true)
		{
			m_pPlayer->SetObjInfo(m_pMonster[i]->GetInfo(), i);
			m_pMonster[i]->SetPlayerInfo(m_pPlayer->GetInfo());
		}
	}

	m_pPlayer->Porgress(true);



	for(int i = 0 ; i < MONSTERMAX ; i++)
	{
		if(bCheck[i] == true)
		{
			m_pMonster[i]->SetInfo(m_pPlayer->GetObjInfo(i));
			m_pMonster[i]->Porgress(true);
		}
	}
	KeyCheck();
	CheckMonster();	

	/*if(m_iQuestCount >= 10)
	{
		m_pPlayer->SetInfo(m_pPlayer->GetInfo().iMAXHP, m_pPlayer->GetInfo().iMAXMP);
		m_iQuestCount = 0;
	}*/

	if(m_pPlayer->GetInfo().iLife == 0)
	{
		CSceneMgr::GetInstance()->SetScene(IDS_GAMEOVER);
	}

	if(m_iMonsterDieCount >= 20)
	{
		CSceneMgr::GetInstance()->SetScene(IDS_ENDING);
	}
}

void CStage::Render()
{
	CDoubleBuffer::GetInst()->WriteBuffer(0, (WINCY - 26), "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", COLOR_REALWHITE);
	CDoubleBuffer::GetInst()->WriteBuffer(0, (WINCY), "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", COLOR_REALWHITE);

	for (int i = 0 ; i < 25 ; i++)
	{
		CDoubleBuffer::GetInst()->WriteBuffer(0, ((WINCY - 25) + i), "■■                                                                                                                                                                  ■■", COLOR_REALWHITE);
	}

	CDoubleBuffer::GetInst()->WriteBuffer(0, ((WINCY - 13)), "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■", COLOR_REALWHITE);

	for (int i = 0 ; i < 8 ; i++)
	{
		CDoubleBuffer::GetInst()->WriteBuffer(116, ((WINCY - 23)) + i, m_cBasicAttack[i], COLOR_REALWHITE);
	}
	for (int i = 0 ; i < 3 ; i++)
	{
		CDoubleBuffer::GetInst()->WriteBuffer(116, ((WINCY - 7)) + i, m_cSkillAttack[i], COLOR_PASTEL_BLUE);
	}

	for (int i = 0 ; i < 2 ; i++)
	{
		if(m_pPlayer->GetInfo().iLife >= (m_pPlayer->GetInfo().iMAX_Life * 0.8))
			CDoubleBuffer::GetInst()->WriteBuffer(10, ((WINCY - 23)) + i, m_cHpBar100[i], COLOR_PASTEL_RED);
		if(m_pPlayer->GetInfo().iLife >= (m_pPlayer->GetInfo().iMAX_Life * 0.6))
			CDoubleBuffer::GetInst()->WriteBuffer(10, ((WINCY - 23)) + i, m_cHpBar80[i], COLOR_PASTEL_RED);
		if(m_pPlayer->GetInfo().iLife >= (m_pPlayer->GetInfo().iMAX_Life * 0.4))
			CDoubleBuffer::GetInst()->WriteBuffer(10, ((WINCY - 23)) + i, m_cHpBar60[i], COLOR_PASTEL_RED);
		if(m_pPlayer->GetInfo().iLife >= (m_pPlayer->GetInfo().iMAX_Life * 0.2))
			CDoubleBuffer::GetInst()->WriteBuffer(10, ((WINCY - 23)) + i, m_cHpBar40[i], COLOR_PASTEL_RED);
		if(m_pPlayer->GetInfo().iLife > (m_pPlayer->GetInfo().iMAX_Life * 0))
			CDoubleBuffer::GetInst()->WriteBuffer(10, ((WINCY - 23)) + i, m_cHpBar20[i], COLOR_PASTEL_RED);
		if(m_pPlayer->GetInfo().iLife == (m_pPlayer->GetInfo().iMAX_Life * 0))
			CDoubleBuffer::GetInst()->WriteBuffer(10, ((WINCY - 23)) + i, m_cHpBar0[i], COLOR_PASTEL_RED);
	}

	CDoubleBuffer::GetInst()->WriteBuffer(41, ((WINCY - 23)), "", m_pPlayer->GetInfo().iLife, " /", COLOR_REALWHITE);
	CDoubleBuffer::GetInst()->WriteBuffer(43, ((WINCY - 23)) + 1, "/ ", m_pPlayer->GetInfo().iMAX_Life, "", COLOR_REALWHITE);

	/*for (int i = 0 ; i < 2 ; i++)
	{
		if(m_pPlayer->GetInfo().iMP >= (m_pPlayer->GetInfo().iMAXMP * 0.8) && m_pPlayer->GetInfo().iMP <= (m_pPlayer->GetInfo().iMAXMP * 1))
			CDoubleBuffer::GetInst()->WriteBuffer(10, ((WINCY - 19)) + i, m_cMpBar100[i], COLOR_PASTEL_BLUE);
		if(m_pPlayer->GetInfo().iMP >= (m_pPlayer->GetInfo().iMAXMP * 0.6) && m_pPlayer->GetInfo().iMP < (m_pPlayer->GetInfo().iMAXMP * 0.8))
			CDoubleBuffer::GetInst()->WriteBuffer(10, ((WINCY - 19)) + i, m_cMpBar80[i], COLOR_PASTEL_BLUE);
		if(m_pPlayer->GetInfo().iMP >= (m_pPlayer->GetInfo().iMAXMP * 0.4) && m_pPlayer->GetInfo().iMP < (m_pPlayer->GetInfo().iMAXMP * 0.6))
			CDoubleBuffer::GetInst()->WriteBuffer(10, ((WINCY - 19)) + i, m_cMpBar60[i], COLOR_PASTEL_BLUE);
		if(m_pPlayer->GetInfo().iMP >= (m_pPlayer->GetInfo().iMAXMP * 0.2) && m_pPlayer->GetInfo().iMP < (m_pPlayer->GetInfo().iMAXMP * 0.4))
			CDoubleBuffer::GetInst()->WriteBuffer(10, ((WINCY - 19)) + i, m_cMpBar40[i], COLOR_PASTEL_BLUE);
		if(m_pPlayer->GetInfo().iMP > (m_pPlayer->GetInfo().iMAXMP * 0) && m_pPlayer->GetInfo().iMP < (m_pPlayer->GetInfo().iMAXMP * 0.2))
			CDoubleBuffer::GetInst()->WriteBuffer(10, ((WINCY - 19)) + i, m_cMpBar20[i], COLOR_PASTEL_BLUE);
		if(m_pPlayer->GetInfo().iMP == (m_pPlayer->GetInfo().iMAXMP * 0))
			CDoubleBuffer::GetInst()->WriteBuffer(10, ((WINCY - 19)) + i, m_cMpBar0[i], COLOR_PASTEL_BLUE);
	}*/
	/*
	CDoubleBuffer::GetInst()->WriteBuffer(41, ((WINCY - 19)), "", m_pPlayer->GetInfo().iMP, " /", COLOR_REALWHITE);
	CDoubleBuffer::GetInst()->WriteBuffer(43, ((WINCY - 19)) + 1, "/ ", m_pPlayer->GetInfo().iMAXMP, "", COLOR_REALWHITE);

	CDoubleBuffer::GetInst()->WriteBuffer(10, ((WINCY - 14)), "[ 레  벨 : ",m_pPlayer->GetInfo().iLevel, " ]", COLOR_REALWHITE);
	CDoubleBuffer::GetInst()->WriteBuffer(10, ((WINCY - 11)), "[ 경험치 : ",m_pPlayer->GetInfo().iExp, " / ", (m_pPlayer->GetInfo().iLevel * 200)," ]", COLOR_REALWHITE);
	CDoubleBuffer::GetInst()->WriteBuffer(10, ((WINCY - 8)), "[ 공격력 : ",m_pPlayer->GetInfo().iAtt, " ]", COLOR_REALWHITE);
	CDoubleBuffer::GetInst()->WriteBuffer(10, ((WINCY - 5)), "[ 방어력 : ",m_pPlayer->GetInfo().iDef, " ]", COLOR_REALWHITE);
	*/
	//몬스터 죽인수 출력
	//CDoubleBuffer::GetInst()->WriteBuffer(63, ((WINCY - 23)), "[ Kill : ", m_iMonsterDieCount, " ]", COLOR_REALWHITE);


	//퀘스트	
	/*CDoubleBuffer::GetInst()->WriteBuffer(63, ((WINCY - 10)), " [ 퀘스트 ]", COLOR_REALWHITE);
	CDoubleBuffer::GetInst()->WriteBuffer(63, ((WINCY - 8)), " 몬스터 ", m_iQuestCount, " / 10 처치 ", COLOR_REALWHITE);
	CDoubleBuffer::GetInst()->WriteBuffer(63, ((WINCY - 6)), " < 보상 > ", COLOR_REALWHITE);
	CDoubleBuffer::GetInst()->WriteBuffer(63, ((WINCY - 4)), " 체력, 마력 모두 회복 ", COLOR_REALWHITE);
	*/


	m_pBackGround->Render();	
	m_pPlayer->Render();
	for (int i = 0 ; i < MONSTERMAX; i++)
	{
		if(bCheck[i] == true)
		{
			m_pMonster[i]->Render();
		}
	}
}

void CStage::Release()
{

}

void CStage::CheckMonster()
{
	for(int i = 0 ; i < MONSTERMAX ; i++)
	{
		if(bCheck[i] == true)
		{
			if(((CMonster*)m_pMonster[i])->GetMonster().bCheck == false)
			{
				bCheck[i] = false;
				//++m_iMonsterDieCount;
				//++m_iQuestCount;
				m_pMonster[i] = NULL;
				m_pPlayer->SetObjInfo(i);
			}
		}
	}
}

void CStage::KeyCheck()
{
	m_dwKey = CKeyMgr::GetInst()->GetKey();

	if(m_dwKey & KEY_UP)
	{
		++m_iMonsterDieCount;
	}
	if(m_dwKey & KEY_DOWN)
	{
		++m_iQuestCount;
	}
	if(m_dwKey & KEY_LEFT)
	{
	}
	if(m_dwKey & KEY_RIGHT)
	{
	}
	if(m_dwKey & KEY_Z )
	{
	}
	if(m_dwKey & KEY_ESCAPE)
	{
		EXIT = false;
	}
	if(m_dwKey & KEY_SPACE)
	{
	}
	if(m_dwKey & KEY_X)
	{
	}
}
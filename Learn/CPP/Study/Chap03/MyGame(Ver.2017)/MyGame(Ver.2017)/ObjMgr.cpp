#include "ObjMgr.h"
#include"Stage.h"
//#include"Bullet.h"
#include"ObjFactory.h"
#include"Collision.h"

ObjMgr* ObjMgr::m_pInst = NULL;


void ObjMgr::Initialize() 
{
	m_pPlayer = ObjFactory::CreatePlayer();
	m_pBackGround = ObjFactory::CreateBackGround();

	/*for (int i = 0; i < END; i++)
	{
		m_pMonster[i] = ObjFactory::CreateMonster(rand() % (WINCX - 2) + 2, rand() % (WINCY - 1) + 1);
	}
	for (int i = 0; i < MAX; i++) 
	{
		m_pBullet[i] = ObjFactory::CreateBullet();
		bCheck[i] = false;
	}*/
}

void ObjMgr::Progress()
{
	CheckBullet();
	
	m_pPlayer->Progress();
	m_pBackGround->Progress();

	/*for (int i = 0; i < END; i++)
	{
		m_pMonster[i]->Progress();
	}

	for (int i = 0; i < MAX; i++)
	{
		int iCheck = m_pBullet[i]->Progress();

		for (int j = 0; j < END; j++)
		{
			if (bCheck[i] == true)
			{
				if (iCheck == 1)
				{
					bCheck[i] = false;
				}
				if (Collision::CollisionTest(m_pMonster[j], m_pBullet[i]))
				{
					ERR_MSG(10, 20, "총알 충돌 입니다. !!!!  이렇게 사용 하면 됩니다.")
				}
			}
		}
	}

	for (int j = 0; j < END; j++)
	{
		if (Collision::CollisionMgr(m_pPlayer, m_pMonster[j]))
		{
			((Player*)m_pPlayer)->SetHp();
			ERR_MSG(10, 20, "충돌 입니다. !!!!  이렇게 사용 하면 됩니다.")
		}
	}*/
}

void ObjMgr::Render() 
{
	m_pPlayer->Render();
	m_pBackGround->Render();

	/*for (int i = 0; i < END; i++)
	{
		m_pMonster[i]->Render();
	}

	for (int i = 0; i < MAX; i++)
	{
		if (bCheck[i] == true)
			m_pBullet[i]->Render();
	}*/
}

void ObjMgr::Release() 
{
	delete m_pPlayer;
	m_pPlayer = NULL;

	delete m_pBackGround;
	m_pBackGround = NULL;

	/*for (int i = 0; i < END; i++)
	{
		delete m_pMonster[i];
		m_pMonster[i] = NULL;
	}

	for (int i = 0; i < MAX; i++)
	{
		m_pBullet[i] = NULL;
	}
	delete[] & m_pBullet;*/
}

void ObjMgr::SetBulletActive(bool _bCheck) 
{
	/*for (int i = 0; i < MAX; i++) 
	{
		if (bCheck == false) 
		{
			bCheck[i] = bCheck;
			m_pBullet[i]->SetPos(m_pPlayer->GetInfo().iX, m_pPlayer->GetInfo().iY);
			m_pBullet[i]->SetActive(_bCheck);
			break;
		}
	}*/
}
void ObjMgr::CheckBullet() 
{
	/*for (int i = 0; i < MAX; i++) 
	{
		if (bCheck[i] == true) 
		{
			if ((Bullet*)m_pBullet[i]->GetInfo().bCheck == false) 
			{
				bCheck[i] = false;
			}
		}
	}*/
}



ObjMgr::ObjMgr()
{
}


ObjMgr::~ObjMgr()
{
}

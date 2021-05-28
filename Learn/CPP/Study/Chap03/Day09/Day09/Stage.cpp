#include "Stage.h"
#include "ObjFactory.h"

void Stage::Initialize()
{
	cout << "Stage::Initialize" << endl;
	m_Player = ObjFactory::CreatePlayer();
	m_Monster = ObjFactory::CreateMonster(15, 20);
}

void Stage::Progress()
{
	cout << "Stage::Progress" << endl;
	m_Player->Progress();
	m_Monster->Progress();
}

void Stage::Render()
{
	cout << "Stage::Render" << endl;
	m_Player->Render();
	m_Monster->Render();
}

void Stage::Release()
{
	cout << "Stage::Release" << endl;
	delete m_Player;
	m_Player = NULL;
	delete m_Monster;
	m_Monster = NULL;

}

Stage::Stage(void)
{
}


Stage::~Stage(void)
{
}

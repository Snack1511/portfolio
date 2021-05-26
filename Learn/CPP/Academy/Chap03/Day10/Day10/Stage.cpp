#include "Stage.h"
#include "ObjFactory.h"

void Stage::Initialize()
{
	cout << "Stage::Initialize" << endl;
	m_Player = new Player;
	m_Player->Initialize();

}

void Stage::Progress()
{

	m_Player->Progress();

}

void Stage::Render()
{

	m_Player->Render();

}

void Stage::Release()
{

	delete m_Player;
	m_Player = NULL;


}

Stage::Stage(void)
{
}


Stage::~Stage(void)
{
}

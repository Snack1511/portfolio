#include "Monster.h"
#include "Include.h"


void Monster::Initialize()
{
	cout << "Monster::Initialize" << endl;
}

void Monster::Progress()
{
	cout << "Monster::Progress" << endl;
	cout << m_info.iX << " , " << m_info.iY << endl;
}

void Monster::Render()
{
	cout << "Monster::Render" << endl;
}

void Monster::Release()
{
	cout << "Monster::Release" << endl;
}

Monster::Monster(void)
{
}


Monster::~Monster(void)
{
	Release();
}

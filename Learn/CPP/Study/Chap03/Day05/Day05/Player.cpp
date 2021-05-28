#include "Player.h"
#include"Define.h"


/*void CPlayer::NewFunction()
{
	cout << "CPlayer" << endl;
}

void CPlayer::secondFunction()
{
	cout << "Second CPlayer" << endl;
}

void CPlayer::purevirtual()
{
	cout << "순수 가상함수" << endl;
}*/


void CPlayer::Initialize()
{
	cout << "CPlayer :: Initialize" << endl;
}
void CPlayer::Progress()
{
	cout << "CPlayer :: Progress" << endl;
}
void CPlayer::Render()
{
	cout << "CPlayer :: Render" << endl;
}
void CPlayer::Release()
{
	cout << "CPlayer :: Release" << endl;
}

CPlayer::CPlayer()
{
	/*m_iNum = 10;
	cout << m_iNum << endl;
	cout << "자식 클래스의 생성자" << endl;*/
}


CPlayer::~CPlayer()
{
	/*cout << m_iNum << endl;
	cout << "자식 클래스의 소멸자" << endl;*/
}

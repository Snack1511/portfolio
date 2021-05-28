#include "MainGame.h"
#include "Player.h"
#include"Define.h"


/*void CMainGame::NewFunction()
{
	cout << "CMainGame" << endl;
}


void CMainGame::secondFunction() 
{
	cout << "Second CMainGame" << endl;
}

*/

void CMainGame::Initialize()
{
	m_pPlayer = new CPlayer();
	m_pPlayer->Initialize();

}
void CMainGame::Progress()
{
	cout << "CMainGame :: Progress" << endl;
}
void CMainGame::Render()
{
	cout << "CMainGame :: Render" << endl;
}
void CMainGame::Release()
{
	cout << "CMainGame :: Release" << endl;
}

CMainGame::CMainGame()
{
	/*m_iNum = 20;
	cout << m_iNum << endl;*/
	//cout << "부모 클래스의 생성자 " << endl;
	
}


CMainGame::~CMainGame()
{
	//cout << m_iNum << endl;
	//cout << "부모클래스의 소멸자" << endl;
	

}

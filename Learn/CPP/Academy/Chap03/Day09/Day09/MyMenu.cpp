#include "MyMenu.h"
#include "StateMgr.h"
void MyMenu::Initialize()
{
	cout << "MyMenu::Initialize" << endl;
	StateMgr::GetInst()->SetStateMgr(Stage_ID);
}

void MyMenu::Progress()
{
	cout << "MyMenu::Progress" << endl;
}

void MyMenu::Render()
{
	cout << "MyMenu::Render" << endl;
}

void MyMenu::Release()
{
	cout << "MyMenu::Release" << endl;
}

MyMenu::MyMenu(void)
{
}


MyMenu::~MyMenu(void)
{
}

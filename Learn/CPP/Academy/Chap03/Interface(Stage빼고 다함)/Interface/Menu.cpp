#include "Menu.h"
#include"StateMgr.h"


void Menu::Initialize()
{
	cursor = new INFO();
	menu[0] = new INFO();
	menu[1] = new INFO();

	menu[0]->ix = 45; 
	menu[0]->iy = 20;
	menu[0]->Name = "Stage";

	menu[1]->ix = 45;
	menu[1]->iy = 22;
	menu[1]->Name = "Logo";

	cursor->ix = menu[0]->ix - 5;
	cursor->iy = menu[0]->iy;
	cursor->Name = "▶";

	cursorIndex = 0;
}

void Menu::Progress()
{
	if (GetAsyncKeyState(VK_UP)) 
	{
		cursor->iy = menu[0]->iy;
		cursorIndex = 0;


	}
	if (GetAsyncKeyState(VK_DOWN)) 
	{
		cursor->iy = menu[1]->iy;
		cursorIndex = 1;
	}
	if (GetAsyncKeyState(VK_SPACE)) 
	{
		switch (cursorIndex) 
		{
		case 0:
			StateMgr::GetInst()->SetStateMgr(STAGE);
			break;
		case 1:
			StateMgr::GetInst()->SetStateMgr(LOGO);
			break;
		}
	}
	

}

void Menu::Render()
{
	DoubleBuffer::GetInst()->WriteBuffer(menu[0]->ix, menu[0]->iy, menu[0]->Name, 파란색);
	DoubleBuffer::GetInst()->WriteBuffer(menu[1]->ix, menu[1]->iy, menu[1]->Name, 빨간색);
	DoubleBuffer::GetInst()->WriteBuffer(cursor->ix, cursor->iy, cursor->Name, 연한자주색);
}

void Menu::Release()
{
}

Menu::Menu()
{
}


Menu::~Menu()
{
}

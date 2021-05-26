#include "Logo.h"
#include"StateMgr.h"



void Logo::Initialize()
{
	p_logo = new INFO;
	p_logo->ix = 7;
	p_logo->iy = 10;
	p_logo->Name = "";

	logo[0] = "8 8888         ,o888888o.         ,o888888o.        ,o888888o.";
	logo[1] = "8 8888      . 8888     `88.      8888     `88.   . 8888     `88.";
	logo[2] = "8 8888     ,8 8888       `8b  ,8 8888       `8. ,8 8888       `8b";
	logo[3] = "8 8888     88 8888        `8b 88 8888           88 8888        `8b";
	logo[4] = "8 8888     88 8888         88 88 8888           88 8888         88";
	logo[5] = "8 8888     88 8888         88 88 8888           88 8888         88";
	logo[6] = "8 8888     88 8888        ,8P 88 8888   8888888 88 8888        ,8P";
	logo[7] = "8 8888     `8 8888       ,8P  `8 8888       .8' `8 8888       ,8P";
	logo[8] = "8 8888      ` 8888     ,88'      8888     ,88'   ` 8888     ,88'";
	logo[9] = "8 888888888888 `8888888P'         `8888888P'        `8888888P'";


}

void Logo::Progress()
{
	if (GetAsyncKeyState(VK_RETURN)) 
	{
		StateMgr::GetInst()->SetStateMgr(MENU);
	}
}

void Logo::Render()
{
	for (int i = 0; i < 10; i++) 
	{
		DoubleBuffer::GetInst()->WriteBuffer(p_logo->ix, p_logo->iy + i, logo[i], 연한파란색);
	}
}

void Logo::Release()
{
}

Logo::Logo()
{
}


Logo::~Logo()
{
}

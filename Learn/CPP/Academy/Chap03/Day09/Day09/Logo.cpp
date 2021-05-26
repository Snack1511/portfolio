#include "Logo.h"
#include "StateMgr.h"
void Logo::Initialize()
{ 
	cout << "Logo::Initialize" << endl;
	StateMgr::GetInst()->SetStateMgr(MyMenu_ID);
}

void Logo::Progress()
{
	cout << "Logo::Progress" << endl;
}

void Logo::Render()
{
	cout << "Logo::Render" << endl;
}

void Logo::Release()
{
	cout << "Logo::Release" << endl;
}

Logo::Logo(void)
{
}


Logo::~Logo(void)
{
}

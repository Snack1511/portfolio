#include "Stage.h"
#include"ObjFactory.h"


void Stage::Initialize()
{
	player = ObjFactory::CreatePlayer();
	player->SetInfo(10, 10);
	monster = ObjFactory::CreateMonster();
	monster->SetInfo(30, 30);

	for (int i = 0; i < 20; i++) 
	{
		bullet[i] = ObjFactory::CreateBullet();
		bullet[i]->SetInfo(0, 0);
		bullet[i]->SetAct(false);
	}

}

void Stage::Progress()
{
	int x = player->GetInfo().ix;
	int y = player->GetInfo().iy;

	if (GetAsyncKeyState(VK_UP)) 
	{
		y--;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		y++;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		x--;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		x++;
	}

	if (GetAsyncKeyState(VK_SPACE)) 
	{
		for (int i = 0; i < 20; i++)
		{
			if (bullet[i]->GetInfo().act == false)
			{
				bullet[i]->SetInfo(x, y);
				bullet[i]->SetAct(true);
				bulletDist = player->GetInfo().ix + 30;
				break;
			}
		}
	}

	player->SetInfo(x, y);
	if (Collision::CollisionMgr(player, monster)) 
	{
		//라이프 감소
	}

}

void Stage::Render()
{
	DoubleBuffer::GetInst()->WriteBuffer(player->GetInfo().ix, player->GetInfo().iy, "oㅅo", 진한노란색);
	DoubleBuffer::GetInst()->WriteBuffer(monster->GetInfo().ix, monster->GetInfo().iy, "ㅎㅅㅎ", 빨간색);
	
	if (Collision::CollisionMgr(player, monster))
	{
		DoubleBuffer::GetInst()->WriteBuffer(player->GetInfo().ix, player->GetInfo().iy, "충돌", 흰색);
	}

	for (int i = 0; i < 20; i++) 
	{
		if (bullet[i]->GetInfo().act == true) 
		{

			DoubleBuffer::GetInst()->WriteBuffer(bullet[i]->GetInfo().ix, bullet[i]->GetInfo().iy, "=>", 파란색);
			if (bullet[i]->GetInfo().ix >= bulletDist) 
			{
				bullet[i]->SetAct(false);
			}
			else 
			{
				int x = bullet[i]->GetInfo().ix;
				int y = bullet[i]->GetInfo().iy;

				x++;
				bullet[i]->SetInfo(x, y);
				if (Collision::CollisionMgr(bullet[i], monster)) 
				{
					DoubleBuffer::GetInst()->WriteBuffer(bullet[i]->GetInfo().ix, bullet[i]->GetInfo().iy, "충돌", 흰색);
				}
			}
		}
	}
}

void Stage::Release()
{
}

Stage::Stage()
{
}


Stage::~Stage()
{
}

#include "BackGround.h"
#include "Define.h"
#include "DoubleBuffer.h"



void BackGround::Initialize()
{

}

int BackGround::Progress()
{
	for (int Y = 0; Y < WINCY; Y++)
	{
		for (int X = 0; X < WINCX; X += 2)
		{
			if (Y == WINCY - 1 || Y == 1 ||
				X == 0 || X >= (WINCX - 3))
				DoubleBuffer::GetInst()->WriteBuffer(X, Y, "бс");
		}
	}
	return 0;
}

void BackGround::Render()
{

}

void BackGround::Release()
{

}



BackGround::BackGround()
{
}


BackGround::~BackGround()
{
}

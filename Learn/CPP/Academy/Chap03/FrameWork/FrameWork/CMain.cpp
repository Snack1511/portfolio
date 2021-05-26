#pragma once // 오브젝트 풀링 , 프로토타입 패턴
#include "Include.h"
#include "MainGame.h"

bool EXIT;

int main()
{
	srand(unsigned(time(NULL)));
	EXIT = true;
	CMainGame MainGame;
	MainGame.Initialize();

	DWORD dwTime = GetTickCount();


	while(EXIT)
	{
		if(dwTime + 50 < GetTickCount())
		{
			dwTime = GetTickCount();

			MainGame.Porgress();
			MainGame.Render();
		}
	}
	return 0;
}
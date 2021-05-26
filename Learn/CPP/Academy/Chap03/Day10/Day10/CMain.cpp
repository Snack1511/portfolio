#include "Include.h"
#include "MainGame.h"

#define TICK 150

int main()
{
	MainGame game;
	game.Initialize();


	/*time_t	tCount = time(NULL);
	while(true)
	{
		if(tCount < time(NULL))
		{
			tCount = time(NULL);
			game.Progress();
			game.Render();
			
		}
	}*/


	DWORD tCount = GetTickCount();

	while (true) 
	{
		if (tCount + TICK < GetTickCount())
			//TICK만큼의 주기로 실행
		{
			
			tCount = GetTickCount();
			game.Progress();
			game.Render();
		}
	}

	return 0;
}
#include"Define.h"
#include"MainGame.h"

void main() 
{
	DWORD dwTime = GetTickCount();
	MainGame game;
	game.Initialize();


	while (true) 
	{
		if (dwTime + 50 < GetTickCount()) 
		{
			dwTime = GetTickCount();
			game.Progress();
			game.Render();
			system("cls");
		}

	}
}
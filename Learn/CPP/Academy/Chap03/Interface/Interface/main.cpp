#include "Include.h"
#include "MainGame.h"
int main()
{
	MainGame maingame;
	int num = 0;
	DWORD dwTime = GetTickCount();
	maingame.Initialize();
	while (true) 
	{
		if (dwTime + 10 < GetTickCount()) 
		{
			dwTime = GetTickCount();
			maingame.Progress();
			maingame.Render();
			system("cls");
		}
	}
	return 0;
}

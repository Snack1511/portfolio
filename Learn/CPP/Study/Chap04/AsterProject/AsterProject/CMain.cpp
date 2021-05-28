#include"Include.h"
#include"MainGame.h"

int main() 
{
	DWORD dwTime = GetTickCount();
	CMainGame MainGame;
	MainGame.Initialize();

	while (true) 
	{
		if (dwTime + 50 < GetTickCount()) 
		{
			dwTime = GetTickCount();

			MainGame.Progress();
			MainGame.Render();
		}
	}
	return 0;
}
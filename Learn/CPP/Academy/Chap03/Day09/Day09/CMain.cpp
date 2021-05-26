#include "Include.h"
#include "MainGame.h"

int main()
{
	MainGame game;

	time_t	tCount = time(NULL);

	game.Initialize();

	while(true)
	{
		if(tCount < time(NULL))
		{
			tCount = time(NULL);
			game.Progress();
			game.Render();
			
		}
	}

	return 0;
}
#include"Include.h"
#include"MainGame.h"
void main() {
	MainGame game;
	game.Initialize();
	DWORD TickCount = GetTickCount();
	while (true) 
	{
		
		if (TickCount + 50 < GetTickCount()) 
		{
			TickCount = GetTickCount();

			game.Progress();
			game.Render();
		}

	}
}
//1 ~ 30 끝
//31, 32, 35 ~ 38 건너뜀
//Monster부분 구현필요ㅇㅇ
//44.Player.cpp부터 다시시작ㅇㅇ

//점프와 스피드를 스코어로 살수 있는게임

//몬스터(=장애물) 회피시 스코어 추가, struct에 character부분에 추가

//라이프는 무한대로 살수 있음

//
#include<iostream>
#include<windows.h>
using namespace std;


struct charactor 
{
	int x;
	int y;
};
charactor player;





void SetTextColor(int _index)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _index);
}

void SetCursorPosition(int _ix, int _iy)
{
	COORD Pos;
	Pos.X = _ix;
	Pos.Y = _iy;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void SetCursorPosition(int _ix, int _iy, int _color)
{
	COORD Pos;
	Pos.X = _ix;
	Pos.Y = _iy;
	SetTextColor(_color);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}



void CheckKey()
{
	if (GetAsyncKeyState(VK_UP))
	{
		player.y--;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		player.y++;
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		player.x--;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		player.x++;
	}
	if (GetAsyncKeyState(VK_SPACE))
	{

	}
	if (GetAsyncKeyState(VK_RETURN))
	{

	}


}

void randerer() 
{
	SetCursorPosition(player.x, player.y);
	cout << "yeah" <<endl;
}

void progress()
{
	randerer();
	CheckKey();
}
int main()
{
	while (true)
	{
		system("cls");
		progress();
		Sleep(30);
	}
}



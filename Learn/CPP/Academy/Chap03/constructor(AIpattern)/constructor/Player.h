#pragma once
#include"basesystem.h"
class Player
{
private:

	int x;
	int y;
public:
	Player();

	Player(int _x, int _y);
	~Player();
public:
	int GetXPosition() 
	{
		return x;
	}
	int GetYPosition()
	{
		return y;
	}
	void SetX(int _x)
	{
		x = _x;
	}
	void SetY(int _y)
	{
		y = _y;
	}
	void SetXY(int _x, int _y) 
	{
		x = _x;
		y = _y;
	}
	void SetCursorPosition(int _ix, int _iy)
	{
		COORD Pos;
		Pos.X = _ix;
		Pos.Y = _iy;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	void renderer()
	{
		SetCursorPosition(x, y);
		cout << "(¢Ù 0 ¢×)" << endl;
		
	}

};


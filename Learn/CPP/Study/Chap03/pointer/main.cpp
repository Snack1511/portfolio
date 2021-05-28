#include<iostream>

using namespace std;

class Vector2
{
private:
	int x;
	int y;
public:

	Vector2(int _x, int _y) 
	{
		x = _x;
		y = _y;
	}
	
	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}

};

class Player 
{
private:
	Vector2 currentPosition;
	Vector2 targetPosition;

public:
	Player(const int &cx, const int &cy, const int &tx, const int &ty) : currentPosition(cx, cy), targetPosition(tx, ty)
	{
		
	}

	void ShowInfo();

};


void main() 
{
	Player player(10, 10, 30, 45);
	player.ShowInfo();
}

void Player::ShowInfo() 
{
	cout << "ÇöÀç ÁÂÇ¥´Â : (" << currentPosition.GetX() << ", " << currentPosition.GetY() << ")" << endl;
	cout << "¸ñÇ¥ ÁÂÇ¥´Â : (" << targetPosition.GetX() << ", " << targetPosition.GetY() << ")" << endl;
}

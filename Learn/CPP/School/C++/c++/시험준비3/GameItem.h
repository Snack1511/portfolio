#include <iostream>
#include <string>
using namespace std;

class GameItem {
	string weapon;
	int power;
	double duration;
public:
	GameItem(string w = "gun", int pow = 0, double dur = 0) {
		this->weapon = w;
		this->power = pow;
		this->duration = dur;
	}
	// const를 붙이는 것은 확실하게 하기 위함
	GameItem operator+(GameItem& p);
	GameItem operator+(int v);
	GameItem operator-(GameItem& p);
	GameItem operator-(int v);
	GameItem operator*(GameItem& p);

	GameItem operator++(); //전위 연산자 ++
	GameItem operator--(); //전위 연산자 --

	GameItem operator++ (int x); //후위 연산자 ++
	GameItem operator-- (int x); //후위 연산자 --


	bool operator==(const GameItem& p);
	bool operator!=(const GameItem& p);
	bool operator<(const GameItem& p);
	bool operator>(const GameItem& p);

	friend GameItem operator+(int val, GameItem& p);
	friend GameItem operator-(int val, GameItem& p);
	friend ostream& operator<<(ostream& os, GameItem& p);
	friend istream& operator >> (istream& is, GameItem& p);
};
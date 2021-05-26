#pragma once
#include<iostream>

using namespace std;

class Power {
	int kick, punch;

public :
	Power(int k = 0, int p = 0) {
		kick = k; punch = p;
	}
	void show() { cout << "kick : " << kick << endl << "punch : " << punch << endl; }
	Power operator+(Power a);//operator : 연산자 지정
	bool operator==(Power a);
	bool operator<(Power a);
	Power operator++();
	Power operator += (Power a);
};
#pragma once

#include <iostream>
using namespace std;

class MyPoint {
	int x, y;
public:
	MyPoint(int _x = 0, int _y = 0) { x = _x; y = _y; }
	MyPoint operator+(const MyPoint& p);
	MyPoint operator+(const int v);
	friend MyPoint operator+(int val, const MyPoint& p);
	MyPoint operator-(const MyPoint& p);
	MyPoint operator-(const int v);
	friend MyPoint operator-(int val, const MyPoint& p);
	MyPoint operator++(); //전위 연산자 ++
	MyPoint operator++ (int x); //후위 연산자 ++
	MyPoint operator--(); //전위 연산자 --
	MyPoint operator-- (int x); //후위 연산자 --
	bool operator<(const MyPoint& p);
	bool operator==(const MyPoint& p);
	bool operator!=(const MyPoint& p);
	friend ostream& operator<< (ostream& os, const MyPoint& p);
	friend istream& operator >> (istream& is, MyPoint& p);
};
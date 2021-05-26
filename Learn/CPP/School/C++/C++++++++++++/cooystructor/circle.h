#pragma once
#include <iostream>
using namespace std;

class circle {
	double radius;

public :
	circle() {};
	circle(double r) { cout << "생성자 수행\n"; radius = r; };

	circle(const circle &c)
	{
		radius = c.radius; cout << "복사 생성자 수행\n";
	};// 특수한 생성자라 생각해도 무방

	double getRadius()
	{
		return radius;
	};
	void setRadius(double r) { radius = r; };
	~circle()
	{
		cout << "소멸자 수행\n";
	};
};
#pragma once
#include <iostream>
using namespace std;

class Person {
	int money;
	static int sharedMoney;
	static int numberOfPerson;
public:
	Person(int m = 0) { money = m; numberOfPerson++; }
	void addMoney(int m);
	static void addShared(int m);
	int getMoney();
	static int getsharedMoney() { return sharedMoney; }
};
#include "Person.h"

int Person::sharedMoney = 0;

void Person::addMoney(int m) {
	this->money += m;
}

void Person::addShared(int m) {
	sharedMoney += m;
}

int Person::getMoney() {
	return this -> money;
}
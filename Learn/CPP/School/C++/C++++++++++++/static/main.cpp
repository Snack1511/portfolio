#include "Person.h"

int main() {
	Person sun(2100000), gun(10000000), moon, ahn;
	gun.addShared(100);
	Person::addShared(1000);
	cout << "sun : " << sun.getMoney << endl;
	cout << "gun : " << gun.getMoney << endl;
	cout << "moon : " << moon.getMoney << endl;
	cout << "ahn : " << ahn.getMoney << endl;
}
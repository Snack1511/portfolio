#include "circle.h"

int main() {
	circle pizza(30);
	circle waffle(pizza);

	cout << "pizza : " << pizza.getRadius() << endl;
	cout << "waffle : " << waffle.getRadius() << endl;

	return 0;
}
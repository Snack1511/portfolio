#include"family.h"

family::family(string name, int size) {
	this->name = name;
	this->size = size;
	p = new person[size];
}

void family::setName(int index, string name) {

	this->p[index].setName(name);
	
}

void family::show() {
	for (int i = 0; i < this->size; i++) {
		cout << this->p[i].getName() << "  ";
	}
}
family :: ~family() {
	delete [] p;
}
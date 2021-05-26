#include "Person.h"

Person::Person(int id, char* name) {
	this->id = id;

	int length = strlen(name);
	this->name = new char[length + 1];
	strcpy(this->name, name);
}

Person::Person(const Person& p) {

	cout << "복사 생성자 실행" << endl;
	this->id = p.id;
	this->name = new char[strlen(p.name)+1];
	strcpy(this->name, p.name);
	
}

Person :: ~Person() {
	if(name)
		delete[] this->name;
}

void Person::changeName(char* newname) {
	if (strlen(this->name) < strlen(newname)) {
		delete[] this->name;
		this->name = new char[strlen(newname) + 1];
		strcpy(this->name, newname);
	}
	else {
		strcpy(this->name, newname);
	}
}

void Person::changeName(Person p) {
	if (strlen(this->name) < strlen(p.name)) {
		delete[] this->name;
		this->name = new char[strlen(p.name) + 1];
		strcpy(this->name, p.name);
	}
	else {
		strcpy(this->name, p.name);
	}
}
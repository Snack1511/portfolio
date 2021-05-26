#pragma once
#include <iostream>

using namespace std;

class Person {
	int id;
	char* name;

public:
	Person(int id, char* name);
	Person(const Person& p);// 복사 생성자
	~Person();
	void changeName(char* newname);
	void changeName(Person p);
	void show() { cout << "이름 : " << name << endl; };
};
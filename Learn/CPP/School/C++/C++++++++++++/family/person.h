#pragma once
#include<string>
#include<iostream>
using namespace std;
class person {
	string name;
public:
	person() { name = ""; }
	person(string name) { this->name = name; }
	string getName() { return name; }
	void setName(string name) { this->name = name; }
};
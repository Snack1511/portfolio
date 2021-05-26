#pragma once
#include <iostream>
using namespace std;
class Book {
	char *title;
	int price;

public :
	Book(char *title, int price);
	~Book();
	void set(char *title, int price);
	void show() { cout << title << '' << price << "¿ø" << endl; }

};
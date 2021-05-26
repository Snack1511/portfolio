#pragma once
#include <iostream>


class MyIntStack {
	int *p;
	int size;
	int tos;

public:
	MyIntStack(int size = 10);
	MyIntStack(const MyIntStack& s);
	~MyIntStack();
	bool push(int n);
	bool pop(int &n);
};
#pragma once
#ifndef _1234567894561531032
#define _1234567894561531032
#include<iostream>
using namespace std;

class MyIntStack {
	int *p;
	int size;
	int tos;

public:
	MyIntStack(int size = 10);
	MyIntStack(const MyIntStack &s);
	~MyIntStack();
	bool push(int n);
	bool pop(int &n);

};

#endif // !_1234567894561531032

#include"MyIntStack.h"

MyIntStack::MyIntStack(int size) {
	this->p = new int[size];
	this->size = size;
	this->tos = -1;
}
MyIntStack::MyIntStack(const MyIntStack &s) {
	this->size = s.size;
	this->p = new int[s.size];
	this->tos = s.tos;
	for (int i = 0; i < size; i++) {
		this->p[i] = s.p[i];
	}
}

MyIntStack::~MyIntStack() {
	delete[]this->p;
}

bool MyIntStack::push(int n) {
	if (this->tos < size) {
		tos++;
		this->p[tos] = n;
		return true;
	}
	else return false;
}
bool MyIntStack::pop(int &n) {
	if (this->tos > -1) {
		n = this->p[tos];
		tos--;
		return true;
	}
	else return false;
}
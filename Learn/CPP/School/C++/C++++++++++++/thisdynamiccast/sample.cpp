#include<iostream>
#include "sample.h"
using namespace std;

void sample::read() {
	cout << this->size << "개의 정수입력";
	for (int i = 0; i < this->size; i++) {
		cin >> this->p[i];
	}
}

void sample::write(){
	for (int i = 0; i < this->size; i++) {
		cout << this->p[i] << " ";
	}
}

int sample :: big() {
	int max = this -> p[0];
	for (int i = 0; i < this->size; i++) {
		if (max < this -> p[i]) {
			max = this -> p[i];
		}
	}
	return max;
}

sample::~sample() {
	delete[]p;
}
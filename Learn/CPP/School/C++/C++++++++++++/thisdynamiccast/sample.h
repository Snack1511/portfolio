#pragma once
#include<iostream>

using namespace std;



class sample {
	int *p;
	int size;
public :
	sample(int n){
		size = n; p = new int[n];
	}
	void read();
	void write();
	int big();
	~sample();
};
#pragma once
#include<iostream>

using namespace std;
#define interface class
interface iStudy {
private:
	virtual void Description() = 0;
public : 
	virtual void Main() = 0;
};
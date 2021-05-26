#include<iostream>
using namespace std;

class Calculator {
	
public :
	void run() {
		int a_C, b_C;
		cout << "두 정수를 입력";
		cin >> a_C >> b_C;
		Adder.Adder(a_C, b_C);

	}
};
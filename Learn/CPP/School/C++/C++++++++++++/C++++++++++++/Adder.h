#ifndef ADDER_H
#define ADDER_H

class Adder {
	int a, b;
public :
	Adder(int a_A, int b_A) {
		this -> a = a_A, this -> b = b_A;
	}
	int processor() {
		return (this -> a + this -> b);
	}
};

#endif // !ADDER_H
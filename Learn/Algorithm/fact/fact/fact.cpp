// fact.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include "stdafx.h"
#include <iostream>
using namespace std;
//시스템 스택

int fact(int n) {
	cout << "n: " << n << endl;
	if (n == 1) return 1;
	cout << n << "*fact(" << n - 1 << ")" << endl;
	int result = n*fact(n - 1);
	cout << result << endl;
	return result;
}

int fib(int n) {
	cout << "n : " << n << endl;
	if (n == 0) return 0;
	else if (n == 1) return 1;
	cout << "fib(" << n - 1 << ")+fib(" << n - 2 << ")" << endl;
	int result = fib(n - 1) + fib(n - 2);
	cout << result << endl;
	return result ;
}

void hanoi_tower(int n, char from, char tmp, char to) {
	if (n == 1) {
		cout << n << ": " << from << "from " << to << "to move\n";
	}
	else {
		hanoi_tower(n - 1, from, to, tmp);
		cout << n << ": " << from << "from " << to << "to move\n";
		hanoi_tower(n - 1, tmp, from, to);
	}
}

int power(int x, int n)
{
	static int count = 0;
	count++;
	cout << "Call Count: " << count << endl;
	if (n == 0) return 1;
	else if (n % 2 == 0)
		return power(x*x, n / 2);
	else
		return x * power(x*x, (n - 1) / 2);
}

int main()
{
	int n, x;
	//char from = 'A', tmp = 'B', to = 'C';
	cout << "Input x: ";
	cin >> x;
	cout << "Input n:";
	cin >> n;
	cout << "Result : " <<  power (x, n);
	getchar();
    return 0;
}


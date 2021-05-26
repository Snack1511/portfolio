#include "Random.h"
#include <iostream>

using namespace std;

int main() {
	Random r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
	for (int i = 0; i<10; i++) {
		int n = r.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl << endl;
	cout << "숫자를 적어봐" << endl;
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	cout << endl << endl << "-- "<< a << "에서 " << 10 << "까지의 랜덤 정수" << c << "개--" << endl;
		for (int i = 0; i<c; i++) {
			int n = r.nextlnRange(a, b); // 2에서 10 사이의 랜덤한 정수
			cout << n << ' ';
		}
	cout << endl;
}
#include "random.h"

int main() {
	Random::seed();
	cout << "1에서 100사이의 정수 10개 출력 : " << endl;

	for (int i = 0; i < 10; i++) {
		cout << Random::nextInt(1, 100);
	}
		cout << endl;
		cout << "알파벳 10개 출력 : ";
		for (int i = 0; i < 10; i++) {
			cout << Random::nextAlphabet();
	}
		cout << endl;
		cout << "0에서 1사이의 실수 10개 출력 : ";
		for (int i = 0; i < 10; i++) {
			cout << Random::nextDouble();
		}
		cout << endl;
}
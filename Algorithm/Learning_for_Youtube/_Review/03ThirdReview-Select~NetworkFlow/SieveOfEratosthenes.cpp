#include<iostream>
#include<math.h>
using namespace std;

void SieveOfEratosthenes(bool* check, int num) {
	for (int i = 2; i < num; i++) {
		if (check[i]) continue;
		else {
			for (int j = i+i; j < num; j += i) {
				check[j] = true;
			}
		}
	}
}

void PrintPrimenum(bool* check, int num) {
	int n = 0;
	for (int i = 2; i < num; i++) {
		if (!check[i]) {
			cout << i << " ";
			if (n % 12 == 11) {
				cout << endl;
			}
			n++;
		}
	}

}

int main() {
	int max = 1554;
	bool C[1554] = {};
	SieveOfEratosthenes(C, max);
	PrintPrimenum(C, max);

	return 0;
}
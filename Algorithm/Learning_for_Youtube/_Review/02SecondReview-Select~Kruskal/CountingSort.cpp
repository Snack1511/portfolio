#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;
int Arr[30];
int Count[15];
void Counting() {
	for (int i = 0; i < 30; i++) {
		Count[Arr[i]] += 1;
	}
	for (int i = 0; i < 15; i++) {
		while (Count[i] != 0) {
			cout << i << " ";
			Count[i]--;
		}
		cout << endl;
	}
}

int main() {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 30; i++) {
		Arr[i] = (rand() % 13) + 1;

	}
	for (int i = 0; i < 30; i++) {
		cout << Arr[i] << " ";
		if (i % 10 == 9) {
			cout << endl;
		}

	}
	Counting();
	cout << endl;
	return 0;
}
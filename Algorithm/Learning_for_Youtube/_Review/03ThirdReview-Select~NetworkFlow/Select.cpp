#include<iostream>
using namespace std;

int arr[10] = {
	7, 5, 6, 9, 8, 1, 2, 4, 3, 10
};

void Selectsort() {
	int min = 999999;
	int tmp;
	for (int i = 0; i < 10; i++) {
		min = arr[i];
		for (int j = i; j < 10; j++) {
			if (min > arr[j]) {
				min = arr[j];
				arr[j] = arr[i];
				arr[i] = min;
			}
		}
		
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;
	Selectsort();
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
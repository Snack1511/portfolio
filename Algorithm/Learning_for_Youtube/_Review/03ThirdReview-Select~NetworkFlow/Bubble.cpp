#include<iostream>
using namespace std;

int arr[10] = {
	7, 5, 6, 9, 8, 1, 2, 4, 3, 10
};
void Bubblesort() {
	int tmp;
	for (int n = 0; n < 10; n++) {
		for (int i = 0; i < 9; i++) {
			if (arr[i] > arr[i + 1]) {
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}

		}
	}
}
int main() {
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;
	Bubblesort();
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
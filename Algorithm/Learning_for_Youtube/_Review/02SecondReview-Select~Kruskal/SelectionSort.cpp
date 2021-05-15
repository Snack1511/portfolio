#include<iostream>

using namespace std;

int num = 10;

int arr[10]{
	7, 10, 2, 8, 4, 5, 1, 9, 3, 6
};

void Selection() {
	int Min = 100000;
	int tmp = 0;
	for (int i = 0; i < num; i++) {
		Min = arr[i];
		for (int j = i + 1; j < num; j++) {
			if (Min > arr[j]) {
				Min = arr[j];
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}

}

int main() {
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;
	Selection();
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
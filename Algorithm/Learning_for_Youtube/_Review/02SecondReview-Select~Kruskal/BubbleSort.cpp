#include<iostream>

using namespace std;

int num = 10;

int arr[10]{
	7, 10, 2, 8, 4, 5, 1, 9, 3, 6
};

void Bubble() {
	int tmp = 0;
	for (int j = num - 1; j >= 0; j--) {
		for (int i = 0; i < j; i++) {
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
	Bubble();
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}


	return 0;
}
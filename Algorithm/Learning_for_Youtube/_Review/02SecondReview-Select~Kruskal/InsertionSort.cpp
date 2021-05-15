#include<iostream>

using namespace std;
int num = 10;
int arr[10] = {
	7, 10, 2, 8, 4, 5, 1, 9, 3, 6
};

void Insertion() {
	int key = 0;
	int tmp = 0;
	for (int i = 1; i < num; i++) {
		key = arr[i];
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] > key) {
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}//비교용
	}//반복용
}
int main() {
	for (int i = 0; i < num; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;
	Insertion();
	for (int i = 0; i < num; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
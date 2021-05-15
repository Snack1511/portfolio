#include<iostream>
using namespace std;

int arr1[10] = {
	7, 5, 6, 9, 8, 1, 2, 4, 3, 10
};

int arr2[10] = {
	10, 9, 8, 7, 6, 5, 4, 3, 2, 1
};
int arr3[10] = {
	4, 7, 8, 9, 6, 3, 2, 1, 5, 10
};
int arr4[10] = {
	5, 8, 7, 10, 4, 1, 2, 3, 6, 9,
};
bool check[10];
void Swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void Heap(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		int me = i;
		while (me != 0) {
			int parent = (me - 1) / 2;
			if (arr[me] > arr[parent]) {
				Swap(arr + parent, arr + me);
			}
			me = parent;
		}
	}
}

void Heapsort(int* arr) {
	for (int i = 10; i > 0; i--) {
		Swap(arr, arr + (i - 1));
		Heap(arr, i - 1);
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		cout << arr4[i] << " ";
	}
	cout << endl << endl;
	Heap(arr4, 10);
	for (int i = 0; i < 10; i++) {
		cout << arr4[i] << " ";
	}
	cout << endl << endl;

	Heapsort(arr4);
	for (int i = 0; i < 10; i++) {
		cout << arr4[i] << " ";
	}
	return 0;
}
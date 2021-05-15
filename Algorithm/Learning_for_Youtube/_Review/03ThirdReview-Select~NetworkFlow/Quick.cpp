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

void Swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void Quick(int *arr, int start, int end) {
	if (start >= end) return;
	int i, j;
	i = start;
	j = end;
	while (i < j) {
		while (arr[i] < arr[start]) {
			i++;
		}
		while (arr[j] > arr[start]) {
			j--;
		}

		if (i < j) {
			Swap(arr + i, arr + j);
		}
		else {
			Swap(arr + start, arr + j);
		}
	}
	Quick(arr, start, j);
	Quick(arr, j + 1, end);
}
int main() {
	for (int i = 0; i < 10; i++) {
		cout << arr4[i] << " ";
	}
	cout << endl << endl;
	Quick(arr4, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << arr4[i] << " ";
	}
	return 0;
}
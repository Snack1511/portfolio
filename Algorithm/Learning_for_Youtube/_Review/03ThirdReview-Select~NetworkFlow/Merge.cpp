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
int tmp[10];
void Swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void Merge(int *arr, int start, int mid, int end) {
	int i, j, k;
	i = start;
	k = start;
	j = mid + 1;
	
	while (i <= mid && j <= end) {
		if (arr[i] > arr[j]) {
			tmp[k] = arr[j];
			k++;
			j++;
		}
		else {
			tmp[k] = arr[i];
			k++;
			i++;
		}
	}
	if (i <= mid) {
		for (int n = k; n <= end; n++) {
			tmp[n] = arr[i];
			i++;
		}
	}
	else {
		for (int n = k; n <= end; n++) {
			tmp[n] = arr[j];
			j++;
		}
	}

	for (int i = 0; i <= end; i++) {
		arr[i] = tmp[i];
	}
}

void Mergesort(int* arr, int start, int end) {
	if (start >= end) return;
	int mid = (start + end) / 2;
	Mergesort(arr, start, mid);
	Mergesort(arr, mid+1, end);

	Merge(arr, start, mid, end);
}
int main() {
	for (int i = 0; i < 10; i++) {
		cout << arr4[i] << " ";
	}
	cout << endl << endl;
	Mergesort(arr4, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << arr4[i] << " ";
	}
	return 0;
}
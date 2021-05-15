#include<iostream>

using namespace std;

int Arr[10] = {
	7, 10, 2, 8, 4, 5, 1, 9, 3, 6
};
int tmp[10];
void Merge(int start, int mid, int end) {
	int i, j, k;
	i = start;
	j = mid + 1;
	k = start;
	while (i <= mid && j <= end) {
		if (Arr[i] < Arr[j]) {
			tmp[k] = Arr[i];
			k++;
			i++;
		}
		else {
			tmp[k] = Arr[j];
			k++;
			j++;
		}
	}
	if (i > mid) {
		while (k <= end) {
			tmp[k] = Arr[j];
			j++;
			k++;
		}
	}
	else {
		while (k <= end) {
			tmp[k] = Arr[i];
			i++;
			k++;
		}
	}
	
	for (int n = start; n < k; n++) {
		Arr[n] = tmp[n];
	}
	
}

void MergeSort(int start, int end) {
	if (start >= end) return;

	int mid = (start + end) / 2;

	//분할
	MergeSort(start, mid);
	MergeSort(mid+1, end);

	//병합
	Merge(start, mid, end);
	
}

int main() {
	for (int i = 0; i < 10; i++) {
		cout << Arr[i] << " ";
	}
	cout << endl << endl;
	MergeSort(0, 9);
	
	for (int i = 0; i < 10; i++) {
		cout << Arr[i] << " ";
	}
	return 0;
}
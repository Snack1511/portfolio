#include<iostream>

using namespace std;
int num = 10;
int arr[10] = {
	7, 10, 2, 8, 4, 5, 1, 9, 3, 6
};

void Quick(int start, int end) {
	if (start >= end) { return; }
	int i, j, tmp;
	int pivot = start;
	i = start;
	j = end - 1;
	while (i < j) {
		
		while (arr[i] <= arr[pivot] && i <= end-1) {
			i++;
		}
		while (arr[j] > arr[pivot] && j > start) {
			j--;
		}

		if (i < j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
		else {
			tmp = arr[j];
			arr[j] = arr[pivot];
			arr[pivot] = tmp;
			pivot = j;
		}

	}


	Quick(pivot + 1, end);
	Quick(start, pivot);

}

int main() {
	for (int i = 0; i < num; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;

	Quick(0, num);
	for (int i = 0; i < num; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
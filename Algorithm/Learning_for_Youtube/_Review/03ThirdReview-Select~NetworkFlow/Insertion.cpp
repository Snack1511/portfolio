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

void Swap(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void Insertion(int arr[]) {
	int tmp;
	for (int n = 9; n >= 0; n--) {
		for (int i = 0; i < n; i++) {
			if (arr[i] > arr[i + 1]) {
				Swap(arr + i, arr + i + 1);
			}
			
		}
	}
}
int main() {
	/*for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}*/
	cout << endl << endl;
	Insertion(arr2);
	for (int i = 0; i < 10; i++) {
		cout << arr2[i] << " ";
	}
	return 0;
}
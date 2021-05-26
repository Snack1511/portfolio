#include <iostream>
#include <time.h>
#define N 15
using namespace std;
int call_count = 0;

void selectSort(int data[], int n){

	for (int i = n - 1; i > 0; i--){
		int maxIndex = i;
		for (int j = maxIndex - 1; j >= 0; j--){
			if (data[j] > data[maxIndex])
				maxIndex = j;
		}
		swap(data[i], data[maxIndex]);
	}
}

void bubbleSort(int data[], int n){
	int numKeys;
	numKeys = n;
	bool isSorted = false;

	while ( !isSorted ){
		isSorted = true;
		for (int i = 1; i < numKeys; i++){
			if (data[i - 1] > data[i]){
				swap(data[i - 1], data[i]);
				isSorted = false;
			}
		}
		numKeys--;
	}

}

void merge(int data[], int low, int mid, int high) {
	int B[N];
	int leftPtr, rightPtr, bufferPtr;
	leftPtr = low;
	rightPtr = mid + 1;
	bufferPtr = low;
	while (leftPtr <= mid && rightPtr <= high)
	{
		if (data[leftPtr] < data[rightPtr])
			B[bufferPtr++] = data[leftPtr++];
		else
			B[bufferPtr++] = data[rightPtr++];

	}
	if (leftPtr > mid) {
		for (int i = rightPtr; i <= high; i++)
			B[bufferPtr++] = data[i];
	}
	else {
		for (int i = leftPtr; i <= mid; i++)
			B[bufferPtr++] = data[i];
	}
	for (int i = low; i <= high; i++)
		data[i] = B[i];
}

void mergeSort(int data[], int low, int high)
{
	if (low < high){
		int mid = (low + high) / 2;
		mergeSort(data, low, mid);
		mergeSort(data, mid+1, high);
		merge(data, low, mid, high);
	}
}

int Partition(int data[], int low, int high)
{
	int i, j, base;
	base = data[high];
	i = low - 1;
	for (j = low; j < high; j++){
		if (data[j] < base){
			swap(data[j], data[++i]);
		}
	}
	swap(data[high], data[++i]);
	return i;
}

void quickSort(int data[], int low, int high)
{
	if (low < high){
		int mid = Partition(data, low, high);
		quickSort(data, low, mid - 1);
		quickSort(data, mid + 1, high);
	}
}

void heapify(int data[], int k, int n){
	int left = 2 * k;
	int right = left + 1;
	int small;
	if (right <= n){ //자식이 두개
		if (data[left] < data[right])
			small = left;
		else
			small = right;
	}
	else if (left <= n){ //왼쪽 자식만 한개 있는 경우 
		small = left;
	}
	else { //자식이 없는 경우 
		return;
	}
	if (data[k] > data[small]){
		swap(data[k], data[small]);
		heapify(data, small, n);
	}
}

void buildHeap(int data[], int n){
	for (int i = n / 2; i > 0; i--){
		heapify(data, i, n);
	}

}

void heapSort(int data[], int n){
	buildHeap(data, n);
	//cout << "초기힙 결과: ";
	//for (int i = 1; i <= n; i++)
		//cout << data[i] << " ";
	//cout << endl;
	for (int i = n; i > 1; i--){
		swap(data[1], data[i]);
		heapify(data, 1, i - 1);
	}

}

int BinarySearch(int data[], int low, int high, int key){
	

	if (low <= high){
		call_count++;
		int mid = (low + high) / 2;
		if (data[mid] == key){
			cout << call_count << "비교만에 찾았습니다.\n";
			return mid;
		}
		else if (data[mid] > key)
			BinarySearch(data, low, mid - 1, key);
		else
			BinarySearch(data, mid + 1, high, key);
	}
	else return -1;
}

int main() {
	int *data = new int[N];
	srand((unsigned int)time(NULL));
	for (int i = 0; i < N; i++){
		data[i] = rand()%1000;
		cout << data[i] << " ";
	}
	
	clock_t start, end;
	//start = clock();
	//selectSort(data, N);
	//bubbleSort(data, N);
	//mergeSort(data, 0, N - 1);
	quickSort(data, 0, N - 1);
	//heapSort(data, N);
	//end = clock();
	//cout << "\nSort Time: " << (double)(end - start)/ CLOCKS_PER_SEC;

	cout << "\nheap Sort Result \n";
	for (int i = 0; i < N; i++)
		cout << data[i] << " ";
	
	int key;
	cout << "\n찾고자 하는 키를 입력:";
	cin >> key;
	while (key != -1){
		call_count = 0;
		int pos = BinarySearch(data, 0, N-1, key);
		if (pos != -1)
			cout << "찾고자 하는 키는 " << pos << "위치에 있습니다.\n";
		else
			cout << "찾고자 하는 키가 없습니다.\n";

		cout << "찾고자 하는 키를 입력:";
		cin >> key;
	}

	delete[] data;
	return 0;
}
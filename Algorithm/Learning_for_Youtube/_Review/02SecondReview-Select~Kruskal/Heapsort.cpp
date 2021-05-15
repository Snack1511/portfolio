#include<iostream>

using namespace std;

int Arr[10] = {
	7, 10, 2, 8, 4, 5, 1, 9, 3, 6
};

void MaxHeap(int n) {
	int tmp;
	for (int i = 0; i < n; i++) {
		int Me = i;
		do{
			int parent = (Me - 1) / 2;//부모 인덱스 설정
			if (Arr[parent] < Arr[Me]) {
				tmp = Arr[parent];
				Arr[parent] = Arr[Me];
				Arr[Me] = tmp;
			}
			Me = parent;
		} while (Me != 0);//0번째 노드를 만날 때 까지
	}
}//최대힙으로 만듦

void Heapsort() {
	int tmp;
	for (int i = 9; i >= 0; i--) {
		tmp = Arr[0];
		Arr[0] = Arr[i];
		Arr[i] = tmp;
		MaxHeap(i);
	}
}

int main() {
	cout << "No TreeStructure" << endl;
	for (int i = 0; i < 10; i++) {
		cout << Arr[i] << " ";
	}
	cout << endl << endl;

	MaxHeap(10);
	cout << "MaxHeap" << endl;
	for (int i = 0; i < 10; i++) {
		cout << Arr[i] << " ";
	}
	cout << endl << endl;

	Heapsort();
	cout << "Heapsort" << endl;
	for (int i = 0; i < 10; i++) {
		cout << Arr[i] << " ";
	}
	return 0;
}
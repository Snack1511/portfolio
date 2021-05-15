#include<iostream>


using namespace std;
int arr[8];
int Getparent(int n) {
	if (arr[n] == n) return n;

	return arr[n] = Getparent(arr[n]);
}

void UnionParent(int a, int b) {
	a = Getparent(a);
	b = Getparent(b);

	if (a < b) {
		arr[b] = a;
	}
	else {
		arr[a] = b;
	}
}

bool Findparent(int a, int b) {
	a = Getparent(a);
	b = Getparent(b);

	if (a == b) return true;
	else return false;
}

int main() {
	for (int i = 1; i < 8; i++) {
		arr[i] = i;
	}
	for (int i = 1; i < 8; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;
	UnionParent(1, 2);
	UnionParent(2, 3);
	UnionParent(5, 4);
	UnionParent(4, 6);
	UnionParent(1, 7);

	for (int i = 1; i < 8; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << endl;
	cout << "hava same parent 4, 7 ?   " ;

	if (Findparent(4, 7)) {
		cout << "TRUE" << endl;
	}
	else {
		cout << "FALSE"<<endl;
		UnionParent(4, 7);
		cout << "Union" << endl;
	}

	for (int i = 1; i < 8; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
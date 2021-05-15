#include<iostream>

using namespace std;

int Getparent(int parent[], int idx) {
	if (parent[idx] == idx) return idx;
	return parent[idx] = Getparent(parent, parent[idx]);
}

void UnionParent(int parent[], int idx1, int idx2) {
	idx1 = Getparent(parent, idx1);
	idx2 = Getparent(parent, idx2);

	if (idx1 > idx2) parent[idx1] = idx2;
	else parent[idx2] = idx1;
}

bool FindParent(int parent[], int idx1, int idx2) {
	idx1 = Getparent(parent, idx1);
	idx2 = Getparent(parent, idx2);

	if (idx1 == idx2) return true;
	else return false;
}



int main() {
	int parent[11];
	for (int i = 1; i <= 10; i++) {
		parent[i] = i;
	}

	UnionParent(parent, 1, 2);
	UnionParent(parent, 2, 3);
	UnionParent(parent, 3, 4);
	UnionParent(parent, 5, 6);
	UnionParent(parent, 6, 7);
	UnionParent(parent, 7, 8);

	cout << "Is Union 1 and 5? : " << FindParent(parent, 1, 5) << endl;

	UnionParent(parent, 1, 5);
	cout << "Is Union 1 and 5? : " << FindParent(parent, 1, 5) << endl;

	return 0;
}
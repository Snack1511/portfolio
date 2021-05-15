#include<iostream>
#include<algorithm>
using namespace std;

int arr[8];
const int MAX = 12;

typedef struct Edge {
public:
	int dist;
	int node[2];
public:
	Edge(int n, int a, int b) {
		this->dist = n;
		this->node[0] = a;
		this->node[1] = b;
	}


}E;

int Getparent(int* arr, int n) {
	if (arr[n] == n) return n;

	return arr[n] = Getparent(arr, arr[n]);
}

void Unionparent(int* arr, int a, int b) {
	a = Getparent(arr, a);
	b = Getparent(arr, b);

	if (a < b) {
		arr[b] = a;
	}
	else {
		arr[a] = b;
	}
}

bool Findparent(int* arr, int a, int b) {
	a = Getparent(arr, a);
	b = Getparent(arr, b);

	if (a == b) return true;
	else return false;
}

int kruskal(E* e, int* arr) {
	int a = 0;
	int result = 0;
	for (int a = 0; a < MAX; a++) {
		while (!Findparent(arr, e[a].node[0], e[a].node[1])) {
			result += e[a].dist;
			Unionparent(arr, e[a].node[0], e[a].node[1]);
		}
	}
	return result;
}

bool compare(const E& a, const E& b) {
	if (a.dist < b.dist)return true;
	else return false;
}

int main() {
	for (int i = 0; i < 8; i++) {
		arr[i] = i;
	}

	E e[MAX] = {
		Edge(9, 0, 1),
		Edge(19, 5, 1),
		Edge(23, 3, 4),
		Edge(31, 4, 2),
		Edge(16, 5, 6),
		Edge(7, 7, 4),
		Edge(10, 6, 7),
		Edge(18, 3, 1),
		Edge(15, 4, 1),
		Edge(8, 2, 1),
		Edge(4, 0, 5),
		Edge(6, 7, 2),
	};
	sort(e, e + MAX, compare);
	cout << kruskal(e, arr);
	return 0;
}
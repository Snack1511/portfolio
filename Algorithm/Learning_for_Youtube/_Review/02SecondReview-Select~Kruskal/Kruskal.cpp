#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Edge {
public:
	int node[2];
	int distance;
public:
	Edge(int a, int b, int _distance) {
		node[0] = a;
		node[1] = b;
		distance = _distance;
	}

	bool operator < (Edge &e) {
		return this->distance < e.distance;
	}
};

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

int Kruskal(vector <Edge> v, int set[]) {
	int result = 0;
	
	for (int i = 0; i < v.size(); i++) {
		if (!FindParent(set, v[i].node[0] - 1, v[i].node[1] - 1)) {
			result += v[i].distance;
			UnionParent(set, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}

	return result;
}

int main() {
	const int n = 7;//노드
	int m = 11;//간선

	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 26));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));

	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));

	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));

	v.push_back(Edge(4, 7, 13));

	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	sort(v.begin(), v.end());

	int Set[n];
	for (int i = 0; i < n; i++) {

		Set[i] = i;
	}

	cout << Kruskal(v, Set) << endl;
	return 0;
}
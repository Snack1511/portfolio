#include<iostream>
#include<vector>

using namespace std;
vector<int> tree[8];
bool Check[7];

void DFS(int start) {
	cout << start << " ";
	Check[start] = true;
	for (int i = 0; i < tree[start].size(); i++) {
		if (!Check[tree[start][i]]) {
			DFS(tree[start][i]);
			Check[tree[start][i]] = true;
		}
	}
	
}

int main() {
	tree[1].push_back(2);
	tree[1].push_back(3);

	tree[2].push_back(1);
	tree[2].push_back(3);
	tree[2].push_back(4);
	tree[2].push_back(5);

	tree[3].push_back(1);
	tree[3].push_back(2);
	tree[3].push_back(6);
	tree[3].push_back(7);

	tree[4].push_back(2);
	tree[4].push_back(5);

	tree[5].push_back(2);
	tree[5].push_back(4);

	tree[6].push_back(3);
	tree[6].push_back(7);

	tree[7].push_back(3);
	tree[7].push_back(6);

	DFS(1);
	return 0;
}

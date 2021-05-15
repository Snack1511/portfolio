#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> tree[8];
bool check[7];


void BFS(int start) {
	queue<int> q;
	q.push(start);
	check[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << " ";
		for (int y = 0; y < tree[x].size(); y++) {
			if (!check[tree[x][y]]) {
				q.push(tree[x][y]);
				check[tree[x][y]] = true;
			}
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

	BFS(1);
	return 0;
}
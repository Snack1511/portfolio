#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 100
#define INF 100000001;

using namespace std;

int n = 6;
int result;
int capacity[MAX][MAX];
int flow[MAX][MAX];
int check[MAX];
vector<int> edges[MAX];

void Maxflow(int start, int end) {
	while (true) {
		fill(check, check + 10, -1);
		queue<int> q;
		q.push(start);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < edges[x].size(); i++) {
				int y = edges[x][i];
				if (capacity[x][y] - flow[x][y] > 0 && check[y] == -1) {
					q.push(y);
					check[y] = x;
					if (y == end) break;
				}

			}
		}
		if (check[end] == -1) break;
		int _flow = INF;
		for (int i = end; i != start; i = check[i]) {
			_flow = min(_flow, capacity[check[i]][i] - flow[check[i]][i]);
		}
		for (int i = end; i != start; i = check[i]) {
			flow[check[i]][i] += _flow;
			flow[i][check[i]] -= _flow;

		}
		result += _flow;
	}
}

int main() {
	edges[1].push_back(2);
	edges[2].push_back(1);
	capacity[1][2] = 12;

	edges[1].push_back(4);
	edges[4].push_back(1);
	capacity[1][4] = 11;

	edges[2].push_back(3);
	edges[3].push_back(2);
	capacity[2][3] = 6;

	edges[2].push_back(4);
	edges[4].push_back(2);
	capacity[2][4] = 3;

	edges[2].push_back(5);
	edges[5].push_back(2);
	capacity[2][5] = 5;

	edges[2].push_back(6);
	edges[6].push_back(2);
	capacity[2][6] = 9;

	edges[3].push_back(6);
	edges[6].push_back(3);
	capacity[3][6] = 8;

	edges[4].push_back(5);
	edges[5].push_back(4);
	capacity[4][5] = 9;

	edges[5].push_back(3);
	edges[3].push_back(5);
	capacity[5][3] = 3;

	edges[5].push_back(6);
	edges[6].push_back(5);
	capacity[5][6] = 4;

	Maxflow(1, 6);
	cout << result << endl;

	return 0;
}
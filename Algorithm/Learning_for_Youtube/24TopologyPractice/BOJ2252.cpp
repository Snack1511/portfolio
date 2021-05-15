/*
	첫째 줄에 N 과 M   N(1 ~ 32000)    M(1 ~ 100000)
	N -> 노드 수
	M -> 비교 횟수
	다음 M개의 줄 -> 비교 정보 -> 앞의 번호가 뒤의 번호보다 먼저 와야 한다.

*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;
vector<int> v[100001];
int InDeg[32001];
int Result[100001];
bool Check[32001];
int n, m;

void Topology() {
	queue<int> q;
	for (int i = 1; i < n; i++) {
		if (InDeg[i] == 0) {
			q.push(i);
		}
	}
	for (int i = 0; i <= n; i++) {
		int x = q.front();
		q.pop();
		Result[i] = x;
		for (int j = 0; j < v[x].size(); j++) {
			int y = v[x][j];
			if (--InDeg[y] == 0) {
				q.push(y);
			}
		}
	}

}

int main() {
	cin >> n;
	cin >> m;
	int a, b;
	int Start = 0;
	for (int i = 0; i < m; i++) {
		cin >> a;
		cin >> b;
		v[a].push_back(b);
		InDeg[b]++;
	}
	Topology();
	for (int i = 1; i <= n; i++) {
		cout << Result[i] << " ";
	}
	return 0;
}


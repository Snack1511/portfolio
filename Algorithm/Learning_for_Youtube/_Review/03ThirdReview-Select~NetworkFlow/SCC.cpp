#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int id;
int d[11];
bool finished[11];

vector<int> nodes[11];
vector<vector<int> > SCC;
stack<int> s;

int dfs(int n) {
	d[n] = ++id;
	s.push(n);

	int parent = d[n];
	for (int i = 0; i < nodes[n].size(); i++) {
		int other = nodes[n][i];
		if (d[other] == 0) {
			parent = min(parent, dfs(other));
		}
		else if(!finished[other]){
			parent = min(parent, d[other]);
		}
	}

	if (parent == d[n]) {
		vector<int> scc;
		while (true) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == n) break;
		}
		SCC.push_back(scc);
	}
	return parent;
}

int main() {
	nodes[1].push_back(2);
	nodes[2].push_back(3);
	nodes[3].push_back(1);
	nodes[4].push_back(5);
	nodes[5].push_back(9);
	nodes[6].push_back(4);
	nodes[6].push_back(7);
	nodes[7].push_back(2);
	nodes[7].push_back(8);
	nodes[8].push_back(6);
	nodes[9].push_back(4);

	for (int i = 1; i <= 11; i++) {
		if (d[i] == 0) dfs(i);
	}
	cout << "SCCÀÇ °¹¼ö : " << SCC.size() << endl;
	for (int i = 0; i < SCC.size(); i++) {
		cout << i + 1 << " ¹øÂ° SCC : ";
		for (int j = 0; j < SCC[i].size(); j++) {
			cout << SCC[i][j];
		}
		cout << endl;
	}

	return 0;
}
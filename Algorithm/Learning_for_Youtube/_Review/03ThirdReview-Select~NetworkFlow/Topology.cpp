#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> Graph[7];
int inDegree[7];
void topologysort(){
	int result[7];
	queue<int> q;
	for (int i = 0; i < 7; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
		}
	}
	for (int i = 0; i < 7; i++) {
		if (q.empty()) { cout << "Acycled" << endl; return; }
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int j = 0; j < Graph[x].size(); j++) {
			int y = Graph[x][j];
			if (--inDegree[y] == 0) {
				q.push(y);
			}
		}
	}
	for (int i = 0; i < 7; i++) {
		cout << result[i] << " ";
	}
}

int main() {
	Graph[0].push_back(1);
	inDegree[1]++;
	Graph[0].push_back(4);
	inDegree[4]++;
	Graph[1].push_back(2);
	inDegree[2]++;
	Graph[2].push_back(3);
	inDegree[3]++;
	Graph[3].push_back(5);
	inDegree[5]++;
	Graph[4].push_back(5);
	inDegree[5]++;
	Graph[5].push_back(6);
	inDegree[6]++;

	topologysort();

	return 0;
}
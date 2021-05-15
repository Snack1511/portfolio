#include<iostream>
#include<queue>
#include<vector>
#define INF 100000001
using namespace std;

int arr[5][5] = {
		{0, 7, 1, 8, INF},
		{7, 0, INF, INF, 2},
		{1, INF, 0, 5, 4},
		{8, INF, 5, 0, 3},
		{INF, 2, 4, 3, 8}
};
bool check[5];
int dist[5];

int GetShortIDX() {
	int min = INF;
	int idx = 0;
	for (int i = 0; i < 5; i++) {
		if (dist[i] < min && !check[i]) {
			min = dist[i];
			idx = i;
		}
	}
	return idx;
}

void Dijkstra(int start) {
	for (int i = 0; i < 5; i++) {
		dist[i] = arr[start][i];
	}
	check[start] = true;
	for (int i = 0; i < 3; i++) {
		int shortidx = GetShortIDX();
		check[shortidx] = true;
		for (int j = 0; j < 5; j++) {
			if (!check[j]) {
				if (dist[shortidx] + arr[shortidx][j] < dist[j]) {
					dist[j] = dist[shortidx] + arr[shortidx][j];
				}
			}
		}
	}

}

vector<pair<int, int> > graph[5];
int dist2[5];
void Dijkstra_useHeap(int start){
	dist2[start] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(start, 0));
	while (!pq.empty()) {
		int currentidx = pq.top().first;
		int distance = -pq.top().second;

		pq.pop();

		if (dist2[currentidx] < distance) continue;
		for (int i = 0; i < graph[currentidx].size(); i++) {
			int nextidx = graph[currentidx][i].first;

			int nextdist = distance + graph[currentidx][i].second;

			if (nextdist < dist2[nextidx]) {
				dist2[nextidx] = nextdist;
				pq.push(make_pair(nextidx, -nextdist));
			}
		}
	}
}

int main() {
	cout << "Dijkstra" << endl;
	Dijkstra(0);
	for (int i = 0; i < 5; i++) {
		cout << dist[i] << " ";
	}
	cout << endl<<endl;

	cout << "Dijkstra Using heap" << endl;
	graph[0].push_back(make_pair(1, 1));
	graph[0].push_back(make_pair(2, 4));
	graph[0].push_back(make_pair(3, 5));
	
	graph[1].push_back(make_pair(0, 1));
	graph[1].push_back(make_pair(2, 2));
	graph[1].push_back(make_pair(3, 1));

	graph[2].push_back(make_pair(0, 4));
	graph[2].push_back(make_pair(1, 2));
	graph[2].push_back(make_pair(3, 2));
	graph[2].push_back(make_pair(4, 8));

	graph[3].push_back(make_pair(0, 7));
	graph[3].push_back(make_pair(1, 1));
	graph[3].push_back(make_pair(2, 2));
	graph[3].push_back(make_pair(4, 6));

	graph[4].push_back(make_pair(2, 1));
	graph[4].push_back(make_pair(3, 1));

	for (int i = 0; i < 5; i++) {
		dist2[i] = INF;
	}
	Dijkstra_useHeap(0);

	for (int i = 0; i < 5; i++) {
		cout << dist2[i] << " ";
	}

	return 0;
}

//******
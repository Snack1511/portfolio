#include<iostream>
#define INF 100000001
using namespace std;

int arr[5][5] = {
		{0, 7, 1, 8, INF},
		{7, 0, INF, INF, 2},
		{1, INF, 0, 5, 4},
		{8, INF, 5, 0, 3},
		{INF, 2, 4, 3, 8}
};

int dist[5][5];

void FloydWarshall() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dist[i][j] = arr[i][j];
		}
	}

	for (int A = 0; A < 5; A++) {
		for (int Start = 0; Start < 5; Start++) {
			for (int End = 0; End < 5; End++) {
				if (dist[Start][End] > dist[Start][A] + dist[A][End]) {
					dist[Start][End] = dist[Start][A] + dist[A][End];
				}
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	FloydWarshall();
	return 0;
}
//*********
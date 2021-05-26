#include "AdjacentMatrix.h"

int main()
{
	AdjacentMatrix g1(10);
	for (int i = 0; i < 8; i++) g1.insertVertex(i);

	g1.insertEdge(0, 3, 8);
	g1.insertEdge(0, 1, 11);
	g1.insertEdge(0, 2, 9);
	g1.insertEdge(1, 4, 8);
	g1.insertEdge(1, 6, 8);
	g1.insertEdge(2, 1, 3);
	g1.insertEdge(2, 3, 6);
	g1.insertEdge(2, 5, 1);
	g1.insertEdge(3, 5, 10);
	g1.insertEdge(4, 6, 7);
	g1.insertEdge(5, 7, 2);
	g1.insertEdge(6, 2, 12);
	g1.insertEdge(6, 7, 5);
	g1.insertEdge(7, 4, 4);

	cout << g1;
	g1.Dijkstra(0);

	while (1){
		int dest;
		cout << "목적지 입력(-1이면 종료): ";
		cin >> dest;
		if (dest == -1) break;
		cout << "최단경로 값: " << g1.dist[dest] << endl;
		g1.printShortestPath(0, dest);
		cout << endl;
	}

	return 0;
}
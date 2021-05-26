#ifndef ADJACENT_MATRIX_H
#define ADJACENT_MATRIX_H
#include <iostream>
using namespace std;

enum { 대전 = 0, 전주, 광주, 대구, 부산, 울산 };
class AdjacentMatrix
{
private:
	int **adMatix;
	int numVertex;
	int vertexMaxNumber;
	bool *visited;
	bool *found;
	int *path;

public:
	int *dist;
	AdjacentMatrix(int num = 100);
	~AdjacentMatrix();
	void insertVertex(int v);
	void insertEdge(int u, int v, int w);
	void insertEdge(int u, int v);
	int isAdjacent(int u, int v);
	int getDegree(int u);
	friend ostream& operator<<(ostream&os, const AdjacentMatrix &g);
	void DFS();
	void aDFS(int v);
	void Dijkstra(int r);
	int extractMin();
	void printShortestPath();
	void printShortestPath(int start, int dest);
};



#endif
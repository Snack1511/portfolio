#include "AdjacentMatrix.h"
#include <iomanip>
#define INF 10000

void AdjacentMatrix::printShortestPath(){

	for (int i = 0; i < this->numVertex; i++)
		cout << "dist[" << i << "]= " << dist[i] << endl;

}

void AdjacentMatrix::printShortestPath(int start, int dest) {
	if (start == this->path[dest])
		cout << "중간 경로: " << start ; 
	else 
		printShortestPath(start, this->path[dest]);

	cout << "  " <<  dest  ;
}

int AdjacentMatrix::extractMin() {

	int min_dist, min_index;
	min_dist = INF; min_index = -1;
	for (int i = 0; i < this->numVertex; i++){
		if (!this->found[i] && min_dist >  dist[i]) {
			min_dist = dist[i];
			min_index = i;
		}
	}
	return min_index;
}

void AdjacentMatrix::Dijkstra(int r){
	found = new bool[this->numVertex];
	dist = new int[this->numVertex];
	path = new int[this->numVertex];

	for (int i = 0; i < this->numVertex; i++){
		found[i] = false; dist[i] = INF;
	}
	dist[r] = 0; 	path[r] = r;

	for (int i = 0; i < this->numVertex; i++){
		int u = extractMin();
		this->found[u] = true;
		for (int j = 0; j < this->numVertex; j++){
			if (this->adMatix[u][j] != INF &&
				dist[j] > dist[u] + this->adMatix[u][j]){
				dist[j] = dist[u] + this->adMatix[u][j];
				path[j] = u;
			}
		}
	}
	printShortestPath();
	for (int i = 0; i < this->numVertex; i++)
		cout << "path[" << i << "]=" << path[i] << endl;

}


void AdjacentMatrix::DFS(){
	
	visited = new bool[this->numVertex];
	memset(visited, 0, sizeof(bool)*this->numVertex);

	for (int i = 0; i < this->numVertex; i++){
		if (!visited[i]) {
			cout << "시작정점: " << i << "로 출발하여 순회 시작: ";
			aDFS(i);
			cout << endl;
		}
	}
	delete[] visited;
}

void AdjacentMatrix::aDFS(int v){
	this->visited[v] = true;
	cout << v << " ";
	for (int w = 0; w < this->numVertex; w++)
	if (this->adMatix[v][w] == 1 && !this->visited[w])
		aDFS(w);
}

AdjacentMatrix::AdjacentMatrix(int num){
	this->vertexMaxNumber = num;
	this->numVertex = 0;

	this->adMatix = new int*[num];
	for (int i = 0; i < num; i++)
		this->adMatix[i] = new int[num];

	for (int i = 0; i < this->vertexMaxNumber; i++ )
	for (int j = 0; j < this->vertexMaxNumber; j++)
		this->adMatix[i][j] = INF;
}

AdjacentMatrix::~AdjacentMatrix(){

	for (int i = 0; i < this->vertexMaxNumber; i++)
		delete[] this->adMatix[i];
	delete[] this->adMatix;

	delete[] found;
	delete[] dist;
	delete[] path;

}

int AdjacentMatrix::isAdjacent(int u, int v) {
	return this->adMatix[u][v];
}

int AdjacentMatrix::getDegree(int u) {
	int count = 0;
	for (int i = 0; i < this->numVertex; i++)
	if (this->adMatix[u][i] != 0) count++;
	return count++;
}

void AdjacentMatrix::insertVertex(int v)
{
	if (numVertex > vertexMaxNumber){
		printf("\n 그래프 정점의 개수를 초과!");
		return;
	}
	this->numVertex++;
}

void AdjacentMatrix::insertEdge(int u, int v, int w)
{
	if (u >= numVertex || v >= numVertex) {
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	this->adMatix[u][v] = w;
}

void AdjacentMatrix::insertEdge(int u, int v)
{
	if (u >= numVertex || v >= numVertex) {
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	this->adMatix[u][v] = 1;
}

ostream& operator<<(ostream&os, const AdjacentMatrix &g)
{
	for (int i = 0; i < g.numVertex; i++){
		for (int j = 0; j < g.numVertex; j++)
			os << setw(5) << g.adMatix[i][j] << " ";
		os << endl;
	}
	return os;
}

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	Kruskal Algorithm
	
	 모든 노드를 최소한의 비용으로 연결하는 알고리즘 --> 최소비용신장트리(Minimal spanning Tree, MST)를 구하는 대표 알고리즘 이다 
*/

int GetParent(int arr[], int n){
	if(arr[n] == n) return n;
	
	arr[n] = GetParent(arr, arr[n]);
	
}

int UnionParent(int arr[], int a, int b){
	a = GetParent(arr, a);
	b = GetParent(arr, b);
	
	if(a < b) arr[b] = GetParent(arr, a);
	else arr[a] = GetParent(arr, b);
}

bool FindParent(int arr[] , int a, int b){  
	a = GetParent(arr, a);
	b = GetParent(arr, b);
	
	if(a == b) return true;
	else return false;
}

//간선 클래스 선언
class Edge{ // 필요 변수 -> 간선의 크기, 연결된 노드 
	public:
		int node[2];
		int distance;
		Edge(int a, int b, int Dist){
			this -> node[0] = a;
			this -> node[1] = b;
			this -> distance = Dist;
		}
		
		bool operator < (Edge &edge){
			return this->distance < edge.distance;
		}
}; 
int main(){
	int n = 7;
	int edgecount = 11;
	vector<Edge> edges;
	edges.push_back(Edge(1, 7, 12));
	edges.push_back(Edge(1, 4, 28));
	edges.push_back(Edge(1, 2, 67));
	edges.push_back(Edge(1, 5, 17));
	edges.push_back(Edge(2, 4, 24));
	edges.push_back(Edge(2, 5, 62));
	edges.push_back(Edge(3, 5, 20));
	edges.push_back(Edge(3, 6, 37));
	edges.push_back(Edge(4, 7, 13));
	edges.push_back(Edge(5, 6, 45));
	edges.push_back(Edge(5, 7, 73));
	
	//간선비용기준 오름차순
	sort(edges.begin(), edges.end());
	
	int parent[n];//각 정점이 포함된 그래프가 어디인지 저장 
	for(int i = 0; i < n; i++){
		parent[i] = i;
	}
	
	int sum = 0;
	for(int i = 0; i < edges.size(); i++){
		//사이클 발생X일때 그래프에 포함
		if(!FindParent(parent, edges[i].node[0]-1, edges[i].node[1]-1)){ //node-1 --> ㅔparent의 index와 같아야 하므로 
			sum += edges[i].distance;
			UnionParent(parent, edges[i].node[0]-1, edges[i].node[1]-1);
		} 
		
	}
	
	cout << sum << endl;
	return 0;
}

#include<iostream>
#include<stdio.h>

/*
	FLoyd-Warshall
	
	플로이드 와샬 알고리즘

	vs. 다익스트라
	-다-
	하나의 정점 -> 다른 모든 정점으로의 최단경로
	가장적은 비용을 하나씩 선택
	
	-플-
	모든정점 -> 모든정점
	거쳐가는 정점을 기준으로 수행
	
	--> 다이나믹프로그래밍에 의거함
	
	간선그래프를 바탕으로 간선정보를 값으롣 가지는 이차원 배열 생성 
	
	어떤 정점 A를 커쳐가는 경우 출발점부터 A까지의 간선과 A부터 도착점 까지의 합이 기본 간선보다 작을경우 스왑
	
	반복  
	
	거쳐가는 정점 : A
	
	Dist(출, 도) > Dist(출, A) + Dist(A, 도) 
	 	Dist(출, 도) =  Dist(출, A) + Dist(A, 도);
	
*/

using namespace std;

int num = 4;
int Infinite = 10000000;

//자료배열(이차배열) 초기화
int a[4][4] = {
	{0, 3, Infinite, 3},
	{5, 0, Infinite, 10},
	{7, 4, 0, 1},
	{3, Infinite, 2, 0}
	
};

void FloydWarshall(){
	//결과 그래프 초기화
	int dist[num][num];
	
	//초기 거리정보 할당 
	for(int i = 0; i < num; i++){
		for(int j = 0; j < num; j++){
			dist[i][j] = a[i][j];
		}
	} 
	
	//A = 거쳐가는 노드
	for(int A = 0; A < num; A++){
		//start = 출발노드 
		for(int start = 0; start < num; start++){
			//end = 도착노드  
			for(int end = 0; end < num; end++){
				if(dist[start][end] > dist[start][A] + dist[A][end] )
				dist[start][end] = dist[start][A] + dist[A][end];
			}
		}
	} 
	
	//결과 출력
	for(int i = 0; i < num; i++){
		for(int j = 0; j < num; j++){
			printf("%3d", dist[i][j]);
		}
		printf("\n");
	} 
}

int main(){
	FloydWarshall();
	return 0;
} 

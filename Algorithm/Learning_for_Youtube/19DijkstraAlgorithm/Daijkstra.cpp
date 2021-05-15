#include<iostream>
/*
	다이나믹 프로그래밍을 활용한 대표적인 최단경로탐색 알고리즘
	최단 거리 = 작은 단위의 최단거리의 집합
		--> 큰 하나의 문제를 작은 단위로 쪼개 계산 -> 다이나믹 프로그래밍
		
	1. 간선정보 저장(이차배열) 
	2. 출발노드를 인덱스로 가장 값이 작고 방문하지 않은 인덱스 추가 
	3. 방문정보 업데이트
	4. 출발~현재 노드의 간선정보 + 현재 ~다음 노드의 간선정보 
				< 출발 ~ 다음노드 간선 -> 값 변경 
	 
	 
*/
using namespace std;

int number = 6;

int Infinite = 1000000000;


//전체 그래프 초기화

int a[6][6] = {	
	{0, 2, 5, 1, Infinite, Infinite},
	{2, 0, 3, 2, Infinite, Infinite},
	{5, 2, 0, 3, 1, 5},
	{1, 2, 3, 0, 1, Infinite},
	{Infinite, Infinite, 1, 1, 0, 2},
	{Infinite, Infinite, 5, Infinite, 2, 0},
		
} ;

bool Visit[6];//방문한 노드 확인 
int dist[6];//최단거리 저장

 //가장 최소거리를 가지는 정점을 반환
 int getSmallIndex(){
 	int min = Infinite;//최대값 삽입 
 	int index = 0;
 	for(int i = 0; i < number; i++){
 		if(dist[i] < min && !Visit[i]){//방문하지 않은 노드중 현재 인덱스가 지닌 거리보다 더 작은값이 존재 
 			min = dist[i];//최소값 전환 
 			index = i;//인덱스 저장 
		 }
	 }//처음부터 하나씩 검사하기에 선형검색이라 한다. 
	 //첫시도라 가장 쉬운 방법으로 했지만 원래 이렇게 하면 비 효율적이라 쓰지 않는다. 
	 return index; 
 } 
 
 //실질적 다익스트라 수행 함수
 void dijkstra(int start){//특정한 점에서 다른 모든 노드로 가는 최소비용 
 	for(int i = 0; i < number; i++){
 		dist[i] = a[start][i];
	 }
	 Visit[start] = true;//시작점 방문 확인
	 for(int i = 0; i < number -2; i++){
	 	int current = getSmallIndex();//최소거리 노드의 인덱스 반환 
 		Visit[current] = true;//해당 노드 방문처리 
 		for(int j = 0; j < 6; j++){
 			if(!Visit[j]){//방문하지 않은 노드중 선택 
 				if(dist[current] + a[current][j] < dist[j]){//현재노드의 최단거리와 현재노드에서 방문하지 않는 노드의 거리 합 < 다음노드의 최단거리 
 					dist[j] = dist[current] + a[current][j];//최단거리 교체 
				 }
			 }
		 }
	 	
	 } 
	 
 } 
int main(){
	
	dijkstra(0);
	for(int i = 0; i < number; i++){
		printf("%d", dist[i]);
	}
	return 0;
}

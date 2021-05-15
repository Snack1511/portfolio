#include<iostream>
#include<vector>
#include<queue>//우선순위 큐라는 방식으로 작동하기에 굳이 힙을 구현하지 않아도 힙을 사용할 수 있게 된다. 
using namespace std;

int number = 6;

int Infinite = 1000000000;


vector<pair<int, int> > a[7];//간선정보
int dist[7];//최소비용 

void dijkstra(int start){
	dist[start] = 0;
	priority_queue<pair<int, int> > pq; //힙구조 
	pq.push(make_pair(start, 0));//make_pair(변수1, 변수2) -> 변수1과 변수2가 들어간 pair를 만들어 준다. 
	//가까운 순서대로 처리하므로 큐를 사용 
	//위 구조의 경우 큰값이 먼저 들어가는 최대 힙이다. 
	while(!pq.empty()){
		int current = pq.top().first;
		//짧은 것이 먼저 오도록 음수화(-)
		int distance = -pq.top().second;
		pq.pop();
		//최단 거리 x -> 스킵 
		if(dist[current] < distance) continue; 
		for(int i = 0; i < a[current].size();i++ ){
			//선택된 노드의 인접노드
			int next = a[current][i].first;
			//선택된 노드를 거쳐 인접노드로 가는 비용
			int nextDistance = distance + a[current][i].second; 
			//기존의 최소 비용보다 더 저렴하다면 교체
			if(nextDistance < dist[next]){
				dist[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			} 
		}
	}
}//이렇게 인접리스트 방식을 활용하면 보기에는 이해하기 힘들지만
// 훨씬더 효율적으로 동작한다. 

int main(){
	//기본적으로 연결 되지 않은 경우 비용은 무한
	for(int i = 1; i <= number; i++){
		dist[i] = Infinite;
	} 
	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));
	
	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));
	
	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));
	
	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));
	
	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));
	
	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));
	
	dijkstra(1);
	
	//결과를 출력
	for(int i = 1; i <= number; i++){
		printf("%d ", dist[i]);
	} 
	return 0;
}

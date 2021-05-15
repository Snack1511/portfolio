#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*
	너비 우선 탐색(Breadth First Search)
	
	알고리즘 특성상 queue를 이용 
	
	탐색을 할 때 너비를 우선으로 해서 수행하는 탐색알고리즘
		특히 '맹목적인 탐색'을 하고자 할 때 사용할 수 있는 탐색기법
	
	'최단경로'를 찾아준다는 점에서 최단 길이를 보장해야 할 때 많이 사용됨
	
	알고리즘 동작서순
		1. 큐에서 하나의 노드를 꺼냄
		2. 해당 노드에 연결된 노드중 방문하지않은 노드를 방문하고, 차례로 큐에 삽입
		3. 반 복 
*/
int num = 7;
int c[7];//방문체크 
vector<int> a[8];// -> num + 1 

void bfs(int start){// 트리구조부터 구현 X -> 탐색만 
	queue<int> q;
	q.push(start);
	c[start] = true;
	while(!q.empty()){//반복처리 -> queue가 빌때까지 
		int x = q.front();
		q.pop();
		printf("%d ", x); 
		for(int i = 0; i < a[x].size(); i++){//a[x]의 자식 수만틈 반복 
			int y = a[x][i];//연결이다. --> 2차배열로 보면 안됨 
			if(!c[y]){
				q.push(y);
				c[y] = true;
			}
		}
	}//1(root)부터 '가까운'노드들 부터 탐색이 이루어진다. 
}//BFS그 자체로는 의미가 없고 다른알고리즘에서 적용한다는 것이 핵심
 
int main(){
	a[1].push_back(2);
	a[2].push_back(3);
	//1-2연결 
	
	a[1].push_back(3);
	a[3].push_back(2);
	//1-3연결 
	
	a[2].push_back(3);
	a[3].push_back(2);
	//2-3연결 
	
	a[2].push_back(4);
	a[4].push_back(2);
	//2-4연결 
	
	a[2].push_back(5);
	a[5].push_back(2);
	//2-5연결 
	
	a[3].push_back(6);
	a[6].push_back(3);
	//3-6연결 
	
	a[4].push_back(5);
	a[5].push_back(4);
	//4-5연결 
	
	a[6].push_back(7);
	a[7].push_back(6);
	//6-7연결 
	
	bfs(1);
	
	return 0;
}

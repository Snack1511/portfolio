/*
위상정렬 Topology sort
시간 복잡도 O(V+E)
순서가 정해져 있는 작업을 차례로 수행해야 할 때 그 순서를 결정해 주기 위해 사용하는 알고리즘

그래프의 흐름은 사실 '조건'으로 해석가능

위상정렬은 Directed Acyclic Graph에만 적용가능

Directed Acyclic Graph : 사이클이 발생하지 않는 방향 그래프

**사이클이 발생하는 경우 위상정렬 수행 X
	-> 위상정렬은 시작점이 존재해야 하는대 사이클이 발생하는 경우 시작점이 모호해짐

위상정렬알고리즘은 두 가지 해결책을 낸다는 특징이 있다.
	1. 현재 그래프는 위상정렬이 가능한가?
	2. 가능하다면 결과는 무엇인가?

수행방법또한 두 가지가 존재
	1. Stack
	2. Queue

 * Queue를 이용하는 방식
	1. 진입차수가 0인 정점을 큐에 삽입
	2. 큐에서 원소를 꺼내 연결된 모든 간선 제거
	3. 간선제거 이후 진입차수가 0이 된 정점을 큐에 삽입
	4. 큐가 빌때까지 2~3반복,
		만약 모든 원소 방문전 큐가 빌경우 사이클 존재,
		모든원소 방문시 큐에서 꺼낸 순서가 위상정렬 결과
*/

#include<iostream>
#include<vector>
#include<queue>
#define MAX 10
using namespace std;

int n, inDegree[MAX];
vector<int> a[MAX];

void topologySort() {
	int result[MAX];
	queue <int> q;
	//진입차수가 0인 노드를 큐에 삽입
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}

	//정렬이 완전히 수행되려면 정확히 n개의 노드를 방문해야한다.
	for (int i = 1; i <= n; i++) {
		//n개의 노드를 방문하기 전에 큐가 비어버리면 사이클이 발생한것
		if (q.empty()) {
			cout << "사이클 발생 ";
			return;
		}
		//result[i] = q.front();
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			//새롭게 진입차수가 0이 된 정점을 큐에 삽입한다.
			if (--inDegree[y] == 0) {
				q.push(y);
			}
		}
		
	}
	for (int i = 1; i <= n; i++) {
		cout << result[i];
	}


}

void main() {
	n = 7;
	a[1].push_back(2);
	inDegree[2]++;
	a[1].push_back(5);
	inDegree[5]++;
	a[2].push_back(3);
	inDegree[3]++;
	a[3].push_back(4);
	inDegree[4]++;
	a[4].push_back(6);
	inDegree[6]++;
	a[5].push_back(6);
	inDegree[6]++;
	a[6].push_back(7);
	inDegree[7]++;

	topologySort();
}
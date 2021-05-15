
/*
	네트워크 플로우(Network Flow)
	특정한 지점에서 다른 지점으로 데이터가 얼마나 많이 흐로고있는가를 측정하는 알고리즘
	용량 : 한 간선이 최대한 통과 시킬 수 있는 양
	유량 : 현재 흐르고 있는 량
	한 정점에서 다른 정점으로 최대한 많은 유량을 보내려고 할 때 가장 합리적인 양을 구하는 문제를 최대유량 문제라고 정의한다.

	기본적으로 최대유량문제는 단순하게 하능한 모든 경우의 수를 탐색하는 방법을 사용한다.
	이때, BFS(너비우선탐색)을 이용하는것이 일반적이다. --> 이를 에드몬드 카프(Edmonds-Karp)알고리즘이라고도 한다.

	1. 가능한 모든 경우의 수를 탐색하기 위해 현재 흐르고 있는 유량을 모두0으로 설정한다.
	2. 정해진 용량안에서 가능한 용량의 양을 반복적으로 더해준다.
	3. 주의할 점은 음의 유량 또한 계산해야 한다.

	최대유량 알고리즘은 수서 상관 없이 남아이쓴ㄴ 양이 1이 넘으면 계속해서 흘려 보내주면 알아서 최적화가 이루어 진다.
*/

#include<iostream>
#include <vector>

#include<queue>
#include<algorithm>

#define MAX 100
#define INF 1000000000

using namespace std;

int n = 6, result;//n:정점의 갯수, result : 흘려보낼 총 유량
int c[MAX][MAX], f[MAX][MAX], d[MAX];//d : 현재 특정한 노드를 방문했는 지 확인하는 변수
vector<int> a[MAX];// 연결된 모든 간선

void maxFlow(int start, int end) {

	while (true) {
		fill(d, d + MAX, -1);//방문하지 않은 상태로 초기화
		queue<int> q;
		q.push(start);//시작점 큐에 삽입
		while (!q.empty()) {//bfs시작
			int x = q.front();//현재 노드
			q.pop();
			for (int i = 0; i < a[x].size(); i++)
			{
				int y = a[x][i];
				//방문하지 않은 노드 중에 용량이 남은 경우
				if (c[x][y] - f[x][y] > 0 && d[y] == -1) {//c-f 흐를 수 있는 용량 > 0 && 노드y(다음 인접노드)를 방문하지 않은 경우
					q.push(y);//해당 노드를 큐에 삽입
					d[y] = x;//방문처리 후 경로를 기억 --> 현재의 노드를 해당인접노드로 가는 값으로 넣어줌
					if (y == end) break;//도착지에 도달한 경우
				}
			}
		}//bfs끝
		if (d[end] == -1)break;//모든 경로를 찾은 뒤 탈출
		int flow = INF;//flow는 기본적으로 무한대 값으로 초기화 -> 가능한 경로에서 가장작은 가능한 유량 만큼 흘려줘야함 -> 최솟값 확인
		for (int i = end; i != start; i = d[i]) {//i = d[i] 선택한 노드의 이전에 거친 노드
														//--> 거꾸로 최소 유량 탐색

			flow = min(flow, c[d[i]][i] - f[d[i]][i]);//둘중 더 작은값으로 갱신
															//-> 자기 자신의 이전노드의 용량(c[d[i]][i])에서 자기 자신의 이전 노드의 유량(f[d[i]][i])을 뺌
		}
		//최소 유량만큼 추가
		for (int i = end; i != start; i = d[i]) {
			f[d[i]][i] += flow;//d[i]-> i 노드로 가는 방향의 유량 
			f[i][d[i]] -= flow;// i -> d[i]노드로 가는 방향의 유량
		}
		result += flow;
	}
}

int main() {

	a[1].push_back(2);
	a[2].push_back(1);
	c[1][2] = 12;

	a[1].push_back(4);
	a[4].push_back(1);
	c[1][4] = 11;

	a[2].push_back(3);
	a[3].push_back(2);
	c[2][3] = 6;

	a[2].push_back(4);
	a[4].push_back(2);
	c[2][4] = 3;

	a[2].push_back(5);
	a[5].push_back(2);
	c[2][5] = 5;

	a[2].push_back(6);
	a[6].push_back(2);
	c[2][6] = 9;

	a[3].push_back(6);
	a[6].push_back(3);
	c[3][6] = 8;

	a[4].push_back(5);
	a[5].push_back(4);
	c[4][5] = 9;

	a[5].push_back(3);
	a[3].push_back(5);
	c[5][3] = 3;

	a[5].push_back(6);
	a[6].push_back(5);
	c[5][6] = 4;

	maxFlow(1, 6);
	cout << result << endl;
	return 0;
}
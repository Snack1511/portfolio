
/*
	강한 결합요소(Strongly Connected Component)

	시간복잡도 O(V+E)

	그래프 안에서 '강하게 결합된 정점집합'을 의미

	서로가 긴밀하게 연결되어 있기에 강한 결합요소라고 말함

	이와 관련된 알고리즘으로 SCC알고리즘이 존재
	SCC의 특징으로 '같은 SCC에 속하는 두 정점은 서로 도달이 가능하다'라는 특징이 있다.

	사이클이 발생하는 경우 무조건 SCC에 해당 -> 방향그래프일때만 의미있다.
		-> 무향 그래프의 경우 그 그래프 전체는 무조건 SCC이기 때문

	SCC를 추출하는 대표적인 알고리즘은 코사라주(Kosaraju's) 알고리즘과 타잔(Tarjan's)알고리즘이 있다.

	일반적으로 코사라주가 구현은 더 쉽지만 타잔이 더 적용이 쉽다.

	타잔알고리즘
		모든 정점에 대해 DFS를 수행하여 SCC를 찾는 알고리즘

	부모로 돌아올 수 있는 경로에 한해서 SCC가 성립됨
		-> 구체적으로 이를 검증하기 위해 부모에서 자식으로 나아가는 DFS알고리즘이 사용된다.

	강한 결합 요소는 그자체로의 의미보다 위상정렬과 함께 생각해볼때 큰 의미가 있다.
		-> 모든 SCC를 각 정점으로 고려했을 때 각 SCC를 위상 정렬할 수 있다.
*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#define MAX 10001

using namespace std;

int id, d[MAX];//각 노드만다 고유한 번호를 할당 할 수 있게 함
bool finished[MAX];//현재 특정한 노드에 대한 DFS가 끝났는지 확인하는 bool배열 
							//ex)123을 판별할 경우 1이 아직 실행중에 자식이 1로 설정되면 사이클이 존재
vector<int> a[MAX];//실질적으로 인접한 노드를 담는 배열
vector<vector<int> > SCC;//한 그래프에서 여러개가 나올 수 있으므로 이차원 배열을 사용함
stack<int> s;//SCC그래프들을 담을 그릇

//DFS는 총 정점의 갯수만큼 실행

int dfs(int x) {
	d[x] = ++id;//노드마다 고유한 번호 할당
	//d[x] : 맨처음 부모로 설정된 값(자기 자신)
	s.push(x);//스택에 자기 자신을 삽입

	int parent = d[x];//맨 처음의 경우 자기 자신이 부모로 설정
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];//인접한 노드 자체를 가리킴
		//방문한 적이 없다면 더 작은값을 부모로 가리키게 함
		if (d[y] == 0) parent = min(parent, dfs(y));// 방문하지 않은 이웃

		//아직 dfs가 끝나지 않은(처리되지 않은)값의 경우 현재 부모와 비교해서 더 작은값을 부모로 처리
		else if (!finished[y]) parent = min(parent, d[y]);//처리중인 이웃
		//현재 처리중인 노드까지 SCC에 포함하기 위해 넣음
	}//모든 인접노드 확인

	if (parent == d[x]) {//부모노드가 자기 자신인 경우
		vector<int> scc;//한 SCC그룹을 받을 그릇
		while (true) {
			int t = s.top();//stack에서 가장 상단의 값을 뽑아내서
			s.pop();
			scc.push_back(t);//여기에 넣어줌
			finished[t] = true;//처리완료 확인
			if (t == x) break;//자기자신(한 SCC그래프의 부모)이 나온경우 루프에서 빠져나옴
		}
		SCC.push_back(scc);//전체SCC에 담음
	}

	//자신의 부모값을 반환
	return parent;
}

int main() {
	int v = 9;//노드갯수
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(5);
	a[5].push_back(9);
	a[6].push_back(4);
	a[6].push_back(7);
	a[7].push_back(2);
	a[7].push_back(8);
	a[8].push_back(6);
	a[9].push_back(4);
	for (int i = 1; i <= v; i++) {
		if (d[i] == 0) dfs(i);//각 정점에 대해서 DFS수행
	}
	cout << "SCC의 갯수 : " << SCC.size() << endl;
	for (int i = 0; i < SCC.size(); i++) {
		cout << i+1 << " 번째 SCC : ";
		for (int j = 0; j < SCC[i].size(); j++) {
			cout << SCC[i][j];
		}
		cout << endl;
	}
	return 0;
}
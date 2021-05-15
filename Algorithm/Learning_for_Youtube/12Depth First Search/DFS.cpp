#include<iostream>
#include<vector>

using namespace std;
/*
	깊이 우선 탐색(Depth First Search) 
	
	알고리즘 특성상 stack을 이용
	하지만 컴퓨터 특성상 이미 스택구조를 활용하고 있으므로 재귀함수를 사용할 경우 stack을 사용하는 것보다 더 빠르다. 
	
	탐색을 함에 있어서 보다 깊은 것을 우선적으로 하여 탐색하는 알고리즘 
	맹목적으로 각 노드들을 탐색할 때 주로 사용
	
	알고리즘 작동순서
	
	1. 스택의 최상단 노드 확인
	2. 최상단 노드에게 방문하지 않은 인접노드가 있으면 그 노드를 스택에 push후 방문처리
	3. 방문하지 않은 인접노드 없을경우 스택에서 최상단 노드 pop
	4. 반복 
	
*/
int num = 7;
int c[7];
vector<int> a[8];

void dfs(int x){
	if(c[x]) return;
	c[x] = true;
	cout << x << ' ';
	for(int i = 0; i < a[x].size(); i++){
		int y = a[x][i];//자식노드 탐색 
		dfs(y);//재귀함수로 자식 수만큼 반복 
	}
	
	
}
//BFS와 마찬가지로 탐색 자체로는 의미가 없고 다른알고리즘에서 적용한다는 것이 핵심
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
	dfs(1);
}

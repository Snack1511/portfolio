#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> Tree[11];
bool check[10];
void BFS(int start){
	queue<int> q;
	q.push(start);
	check[start] = true;
	
	while(!q.empty()){
		int me = q.front();
		q.pop();
		cout << me <<" ";
		for(int next = 0; next < Tree[me].size(); next++){
			if(!check[Tree[me][next]]){
			
				q.push(Tree[me][next]);
				check[Tree[me][next]] = true;
			}
			
		}
	}
	
	
	
}
int main(){
	Tree[1].push_back(2);
	Tree[1].push_back(3);
	
	Tree[2].push_back(1);
	Tree[2].push_back(3);
	Tree[2].push_back(4);
	Tree[2].push_back(5);
	
	Tree[3].push_back(1);
	Tree[3].push_back(2);
	Tree[3].push_back(6);
	Tree[3].push_back(7);
	
	Tree[4].push_back(2);
	Tree[4].push_back(5);
	Tree[4].push_back(8);
	Tree[4].push_back(9);
	
	Tree[5].push_back(2);
	Tree[5].push_back(4);
	Tree[5].push_back(10);
	
	Tree[6].push_back(3);
	Tree[6].push_back(7);
	
	Tree[7].push_back(3);
	Tree[7].push_back(6);
	
	Tree[8].push_back(4);
	Tree[8].push_back(9);
	
	Tree[9].push_back(4);
	Tree[9].push_back(8);
	
	Tree[10].push_back(5);
	
	
	BFS(1);
	return 0;
}

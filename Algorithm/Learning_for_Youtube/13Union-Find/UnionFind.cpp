#include<iostream>
/*
	Union-Find
	
	서로소 집합(Disjoint - Set) 알고리즘 이라고도 함
	
	여러개의 노드가 존재할 때 두개의 노드를 선택 후 같은 그래프에 속하는지 판별하는 알고리즘
	
	FInd알고리즘은 두개의 노드의 부모노드를 확인하여 현재 같은 집합에 속하는지 확인하는 알고리즘
	
	Union-Find알고리즘은 다른 고급 그래프알고리즘의 베이스가 된다는 점에서 반드시 익혀야 한다.
*/


using namespace std;

int GetParent(int arr[], int n){//부모 불러오기 
	if(arr[n] == n) return n;// n노드의 부모가 n자기 자신일때 리턴
	
	return arr[n] = GetParent(arr, arr[n]); // n노드의 부모가 n이 아닐때 n노드의 부모를 상대로 부모 확인후 교체 
	
}//1. 부모설정

void UnionParent(int arr[], int a, int b)//a와 b노드의 부모를 같게함
{//보통 작은값이 부모를 맡음
	a = GetParent(arr, a);//a노드의 부모값 
	b = GetParent(arr, b);//b노드의 부모값
	
	if(a < b) arr[b] = a;// a노드의 부모값이 작을때 b의 부모로 a를 할당 
	else arr[a] = b;
	 
} 

bool CompareParent(int arr[], int a, int b){
	a = GetParent(arr, a);
	b = GetParent(arr, b);
	if( a == b) return true;
	else return false;
} 

 

int main(){
	int parent[11];
	for(int i = 1; i <= 10; i++){
		parent[i] = i;//자기자신만을 자식으로 가지는 노드들 생성 
	} 
	
	UnionParent(parent, 1, 2);
	UnionParent(parent, 2, 8);
	UnionParent(parent, 1, 9);
	UnionParent(parent, 6, 1);	//부모가 1인 그래프 
	
	UnionParent(parent, 3, 4);
	UnionParent(parent, 7, 5);
	UnionParent(parent, 5, 3);
	UnionParent(parent, 4, 10); // 부모가 3인 그래프 
	
	cout << "1과 5는 연결되어 있는가?" << CompareParent(parent, 2, 5) << endl;
	cout << GetParent(parent, 1) << ", " <<GetParent(parent, 5)<<endl << endl; 
	
	 UnionParent(parent, 1, 5);
	cout << "1과 5는 연결되어 있는가?" << CompareParent(parent, 1, 5) << endl;
	return 0;
}

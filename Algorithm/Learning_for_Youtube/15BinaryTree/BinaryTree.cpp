#include<iostream>
/*
	BinaryTree
	
	기본적으로 가장 많이 사용되는 비선형 자료구조 
		이진트리 -> 트리자료구조 활용한 대표적 예
		--> 데이터의 탐색속도 증진 위해 사용하는 구조
	
	실제로 트리를 제대로 구현하기 위해서는 포인터가 필요
	
	하나의 노드 -> 왼쪽자식과 오른쪽 자식을 가지도록 설계
		   -> 구현시 반드시 '포인터' 사용
			왜? -> 완전이진트리가 아닌 이진트리는 배열로 표현하기 어렵기 때문
	
	포인터 사용해 이진트리 구현시 굉장히 유동적으로 트리 자료구조 활용 가능
	
	이진트리에서 데이터를 탐색하는 방법은 크게 세 가지 방법이 존재
	
	1. 전위 순회(Preorder Trversal)
		자기자신 출력
		왼쪽 자식 재귀
		오른쪽 자식 재귀
	
	2. 중위 순회(Inorder Traversal)
		왼쪽 자식 재귀
		자기자신 출력
		오른쪽 자식 재귀
	
	3. 후위 순회(Postor Traversal)
		왼쪽 자식 재귀
		오른쪽 자식 재귀
		자기자신 출력
	
	구현순서
	
	struct이용한 노드 선언
		노드 인자 : int 데이터, 
			   struct* leftchild, rightchild
	순회 구현
		if -> 데이터 존재 시
		먼저 출력할 노드의 데이터 출력
		순회 종류 따라 앞의 노드에 이은 데이터로 재귀
		

*/
using namespace std;

int num = 15;

typedef struct Node *nodepointer;//자식의 Node구조체를 참조할 주소값 선언 

typedef struct Node{
	int Value;
	nodepointer LeftChild, RightChild;
	
} Node; //노드변수타입 선언

//1. 전위 순회
void PreorderTravelsal(nodepointer node){
	if(node){
		
		cout << node -> Value << " ";
	
		PreorderTravelsal(node -> LeftChild);
		PreorderTravelsal(node -> RightChild);
	}
	
	
	
} 

//2. 중위 순회
void InorderTravelsal(nodepointer node){
	if(node){
		
		InorderTravelsal(node -> LeftChild);
		cout << node -> Value << " ";
		InorderTravelsal(node -> RightChild);
	}
	
	
	
} 
//3. 후위 순회 

void PostorTravelsal(nodepointer node){
	if(node){
		
		InorderTravelsal(node -> LeftChild);
		InorderTravelsal(node -> RightChild);
		cout << node -> Value << " ";
	}
	
	
	
} 
int main(){
	Node nodes[num - 1];
	
	for(int n = 0; n < num; n++){
		nodes[n].Value = n;
		nodes[n].LeftChild = NULL;
		nodes[n].RightChild = NULL;
	}
	for(int n = 0; n < num; n++){
		if(n % 2 == 0){//n이 짝수일 때 왼쪽 -> 현재 0부터 시작하므로 짝수는 항상 홀수보다 작다 
			nodes[ n / 2 ].LeftChild = &nodes[n]; // n/연결 노드수  -> 부모 위치 인덱스
		}										  // n*연결 노드수  -> 자식 위치 인덱스
		else{									  // 트리구조만 가능한 방법 
			nodes[ n / 2 ].RightChild = &nodes[n];
		}
	}
	
	cout << "PreorderTravelsal : ";
	PreorderTravelsal(&nodes[1]);
	cout << endl << endl;
	
	cout << "InorderTravelsal : ";
	InorderTravelsal(&nodes[1]);
	cout << endl << endl;
	
	cout << "PostorTravelsal : ";
	PostorTravelsal(&nodes[1]);
	
	return 0;
}

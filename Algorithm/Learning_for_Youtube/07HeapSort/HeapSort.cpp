#include<iostream>
/*
	HeapSort -> 1/2 N * logN -> O(N)
	
	요지 
	"힙(heap)을 이용해 데이터를 정렬하면 어떨까?"
	
	들어가기에 앞서..
	
	이진트리란? 
		트리 : 컴퓨터에서 데이터를 표현할 때, 데이터들을 각 노드들에 담고 다음에 오는 노드들을 이어붙인 구조
		이진트리 :  하나의 노드에 2개 이하의 노드들이 붙어있는 구조
		완전이진트리 : 데이터가 루트부터 시작해 자식 노드가 왼쪽에서 오른쪽으로 차근차근 들어가는 구조 
		
	Heap이란?
		 최솟값이나 최댓값을 빠르게 찾아내기 위해 완전이진트리를 기반으로 하는 트리
		 힙에는 최대힙과 최소힙이 존재
		 최대힙 : 부모노드가 자식노드 보다 큰 힙  	-> 가지를 뻗을 수록 값이 작아짐 
		 최소힙 : 부모노드가 자식 노드보다 작은 힙 	-> 가지를 뻗을 수록 값이 커짐 
		 
	CheckPoint
	힙 정렬을 수행하기 위해서는 힙 생성 알고리즘을 사용해야 한다. 
	힙 생성 알고리즘 (Heapify Algorithm) O(LogN)
		특정한 하나의 노드에 대해서 수행
		자식이 더 이상 존재하지 않을 때 까지 특정한 노드의 두 자식 중 더 큰 자식과 자신의 위치를 바꾸는 알고리즘
		조건 : 하나의 노드를 제외하고는 최대힙이 구성되어 있는 상태 
	
	
*/
using namespace std;

int length = 10;
int heap[10] = {2, 3, 5, 6, 9, 10, 7, 8, 1, 4};
int tmp;
int main(){
	
	//먼저 전체 트리구조를 힙 구조로 바꿔줌
	for(int i = 1; i < length; i++){
		int Me = i;
		do{
			int parent = (Me-1)/2;
			//부모노드 접근 식 : (int)(노드 - 1)/부모노드가 가진 자식 수
			if(heap[parent] < heap[Me]){
				tmp = heap[parent];
				heap[parent] = heap[Me];
				heap[Me] = tmp;
			} 
			Me = parent;
		}while(Me != 0);
	}//아래 ->  위 
	
	
	 //크기를 줄여가며 반복적으로 힙을 구성 
	 for(int i = length - 1; i >= 0; i--){
	 	tmp = heap[0];
	 	heap[0] = heap[i];
	 	heap[i] = tmp;
	 	int Me = 0;
	 	int child = 1;
	 	do{
	 		child = (Me *2) + 1;
	 		//자식 중에 더 큰 값을 찾기
			 if(heap[child] < heap[child + 1] && child < i - 1){
			 	child++;
			 } 
			 //루트보다 자식이 더 크다면 교환
			 if(heap[Me] < heap[child] && child < i) {
				tmp = heap[Me];
				heap[Me] = heap[child];
				heap[child] = tmp;
			 } 
			 Me = child;
		 }while(child < i);
	}//위 -> 아래 
	
	
	for(int i = 0; i < length; i++){
		cout << heap[i] << " ";
	}
	return 0;
}


#include<stdio.h>
/*
	Quick Sort
	
	요지
	"특정한 값을 기준으로 큰 숫자와 작은 숫자를 나누면 어떨까?"
	특정한 값(기준값)을 먼저 정렬후 고정 하는 느낌 
	
	Checkpoint
	특정한 값을 기준으로 큰 숫자와 작은숫자를 서로 교환한 뒤 배열을 반으로 나눈다.
	퀵정렬은 대표적인 '분할 정복' 알고리즘이다. 
	앞서 한것들은 모두 O(N*N)이라면 이번에 할 것은 O(N*logN)이다.
	
	왜 O(N*logN)인가?
		 기본적으로 N번씩 탐색하되, 피벗이 고정됨에 따라 반씩 집합을 나눠 탐색을 재개한다.
		 10 * 10 = 100 과 (5 * 5) + (5 * 5) = 50인 점과 유사하다. 
	
	그 러 나
	
		기준값(pivot)의 설정이 어떠한가에 따라 최악의 경우 O(N * N)이 될 수 있는 알고리즘이다. 
	
	
	
	
	기준값(pivot)을 제외하고 좌에서 우로 기준값보다 큰 값 탐색
							우에서 좌로 기준값보다 작은 값 탐색을 한다.
	탐색 후 큰값과 작은값의 위치 바꿈 
	만약 기준보다 큰값의 인덱스와 작은값의 인덱스가 서로 엇갈리면
		기준값과 작은값의 위치를 바꿔준다
			이경우 기준값의 좌측의 경우 기준보다 작은값이
							우측에는 기준보다 큰값이 오게 된다. 
	기준값을 기준으로 두 집합으로 나뉘게 되면 집합들 내에서 각자의 기준값을 가지고 다시 반복한다.
		예) 1 2 3 4 5 6 7 8 9
		   [1]2 3 4 5 6 7 8 9
	 
	 
*/

void show(int* arr, int length){
	int i;
	for(i = 0; i < length; i++){
		if(i == length - 1){
			printf("%d\n",arr[i]);
		}
		else{
			printf("%d, ",arr[i]);
		}
		
	}
} 

void QuickSort(int* arr, int start, int length){
	if(start >= length - 1){// start = length -> 원소가 1개다 -> 할필요가 없다. 
		return;
	}
	int tmp, pivot;
	
	pivot = start;
	int i = start + 1;//pivot보다 큰값 증가 탐색 
	int j = length - 1;//pivot보다 작은값 감소 탐색 
	
	while(i <= j){
		while(arr[i] <= arr[pivot] && i <= length - 1){// 데이터가 같은 값까지는 포함이 되야 하므로 
			i++;
		}//좌측탐색
		while(arr[j] >= arr[pivot] && j > start){
			j--;
		} //우측탐색 
		
		// --> 피벗과 비교해 탐색하는 부분 
		
		if(j < i){//인덱스가 엇갈린 경우 
			tmp = arr[pivot];
			arr[pivot] = arr[j];
			arr[j] = tmp;
		}
		else{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp; 
		}
		// --> 인덱스 따라 스왑 
	}//반복
	
	show(arr, length);
	
	QuickSort(arr, start, j);//start ~ pivot-1
	QuickSort(arr, j + 1, length);// pivot+1 ~ j
}

int main(){
	int arr[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	int i, j, k, n;
	int pivot, maxidx, minidx, tmp;
	
	QuickSort(arr, 0, 10);
	 
	show(arr, 10);
	
	return 0;
}



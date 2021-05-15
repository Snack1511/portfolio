/*
	MergeSort
	
	BigO(N*logN)
	
	요지
	반으로 나누고 나중에 합쳐서 정렬한다.
	
	Checkpoint
	병합도 앞서 했던 퀵과 같이 '분할정복'알고리즘을 채댁한 정렬이다.
	퀵의 경우 pivot의 설정에 따라 N*N의 시간복잡도를 가지지만,
	병합의 경우 어떤 상황에서도 반으로 나눠 정렬하기에 N*logN의 복잡도를 유지한다.
	 


*/

 

#include<iostream>

int n = 8;
int sorted[8];//정렬배열의 경우 함수 내에서 생성을 반복생성하게 될 가능성이 있다
				//반복할 경우 예상치 못한 비효율이 발생할 수 있다.
				  //이를 방지하기 위해서 전역으로 설정한다. 



void Merge(int* a, int start, int mid, int end){  
	int i = start;
	int j = mid + 1;
	int k = start;
	
	while(i <= mid && j <= end){
		if(a[i] <= a[j]){
			sorted[k] = a[i];
			i++;
		}
		else{
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	
	//남은 데이터 삽입부분
	if(i > mid){
		for(int t = j; t <= end; t++){
			sorted[k] = a[t];
			k++;
		}
	} 
	else{
		for(int t = i; t <= mid; t++){
			sorted[k] = a[t];
			k++;
		}
	}
	//정렬배열 삽입
	for(int t = start; t <= end; t++){
		a[t] = sorted[t];
		
	} 
}

void MergeSort(int* a, int start, int end){
	if(start < end){
		int mid = (start + end)/2;
		MergeSort(a, start, mid);
		MergeSort(a, mid + 1, end);
		Merge(a, start, mid, end);
		for(int i = 0; i < n; i++){
			std :: cout << a[i] << " ";
		}
		std :: cout << std :: endl <<std :: endl;
	}
	
}

using namespace std;

int main(){
	int arr[n] = {7,6,5,8, 3,5,9,1};
	MergeSort(arr, 0, n - 1);
	
	cout << "----------------------------"<<endl;
	for(int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	
	
	return 0;
}

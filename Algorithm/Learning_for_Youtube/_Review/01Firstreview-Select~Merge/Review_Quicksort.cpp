#include<iostream>

using namespace std;

int length = 10;

void swap(int* a, int* b){
	int tmp;
	tmp = *a;
	a = b;
	*b = tmp;
}

void Quicksort(int* a, int start, int end){
	
	if(start >= end){
		return ;
	}
	
	int i, j, tmp;
	i = start+1;
	j = end;
	
	while(i <= j){
		while (a[i] < a[start] && i <= end){
		
			i++;
		}
		while (a[j] > a[start] && j > start){
			j--;
		}
		if(i > j)
			swap(a[start], a[j]);
		else
			swap(a[i], a[j]);
			
	}
	Quicksort(a, start, j-1);
	Quicksort(a, j+1, end);
	
}

int main(){
	int arr[length] = {2, 4, 5, 3, 6, 8, 9, 10, 7, 1};
	
	Quicksort(arr, 0, length-1);
	
	for(int i = 0; i < length; i++){
		cout << arr[i] << " ";
	}
	return 0;
}

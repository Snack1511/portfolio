#include<iostream>

using namespace std;

int length = 10;
int Array[10];
void swap(int* a, int* b){
	int tmp;
	tmp = *a;
	a = b;
	*b = tmp;
}



void Merge(int a[], int start, int center, int end){
	int i, j, k;
	i = start;
	j = center + 1;
	k = start;
	while(i <= center && j <= end){
		if(a[i] < a[j]){
			Array[k] = a[i];
			i++;
		}
		else{
			Array[k] = a[j];
			j++;
		}
		k++;
	}
	
	
	if(i > center){
		for(int n = j; n <= end; n++){
		
			Array[k] = a[n];
			k++;
		}
	}
	else{
		for(int n = i; n <= center; n++){
		
			Array[k] = a[n];
			k++;
		}
	}
	for(int n = start; n <= end; n++){
		a[n] = Array[n];
	}
}

void Mergesort(int a[], int start, int end){
	
	if(start >= end){
		return ;
	}
	int center = (end+start)/2;
	
	Mergesort(a, start, center);
	Mergesort(a, center+1, end);
	Merge(a, start, center, end);
	
	
}




int main(){
	int arr[length] = {2, 4, 5, 3, 6, 8, 9, 10, 7, 1};
	
	Mergesort(arr, 0, length-1);
	
	for(int i = 0; i < length; i++){
		cout << arr[i] << " ";
	}
	return 0;
}

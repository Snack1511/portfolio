#include<iostream>

using namespace std;

void swap(int* a, int* b){
	int tmp;
	tmp = *a;
	a = b;
	*b = tmp;
}

int length = 10;

int main(){
	int arr[length] = {10, 4, 5, 3, 6, 8, 9, 2, 7, 1};
	int tmp;
	for(int key = 0; key < length; key++){
		for(int j =key - 1; j >= 0 ; j--){
			if(arr[key] < arr[j]){
				swap(arr[key], arr[j]);
				key--;
				
			}
			else{
				break;
			}
			
		}
	}
	
	
	for(int i = 0; i < length; i++){
		cout << arr[i] << " ";
	}
	return 0;
}

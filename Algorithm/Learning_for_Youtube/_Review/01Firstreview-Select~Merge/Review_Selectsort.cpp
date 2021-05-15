#include<iostream>

using namespace std;

int length = 10;

int main(){
	int arr[length] = {2, 4, 5, 3, 6, 8, 9, 10, 7, 1};
	int tmp;
	
	for(int n = 0; n < length - 1; n++){
		for(int i = n + 1; i < length; i++){
			if(arr[i] < arr[n]){
				tmp = arr[i];
				arr[i] = arr[n];
				arr[n] = tmp;
			}
				
		}
	}
	
	for(int i = 0; i < length; i++){
		cout << arr[i] << " ";
	}
	return 0;
}

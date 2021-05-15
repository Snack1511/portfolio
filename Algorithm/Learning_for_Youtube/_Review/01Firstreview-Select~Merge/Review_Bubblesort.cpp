#include<iostream>

using namespace std;

int length = 10;

int main(){
	int arr[length] = {2, 4, 5, 3, 6, 8, 9, 10, 7, 1};
	int tmp;
	for(int i = 0; i < length; i++){
		for(int j = 0; j < length - i; j++){
			if(arr[j] > arr[j+1]){
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
		
		for(int n = 0; n < length; n++){
			cout << arr[n] << " ";
		}
		
		cout << endl;
	}
	cout << endl << "--------------Result-----------------"<<endl<<endl;
	for(int i = 0; i < length; i++){
		cout << arr[i] << " ";
	}
	return 0;
}

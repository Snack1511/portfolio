#include<iostream>
using namespace std;
int arr[10001];//실 출력용 

int main(){
	int n, m;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &m);
		arr[m]++;
		  
	}
	for(int i = 0; i < 10001; i++){
		while(arr[i] != 0){
			printf("%d\n", i);
			arr[i]--;
		}
	}
	//입출력시 cin과 cout 보다 printf와 scanf가 더 빠르다. 
}

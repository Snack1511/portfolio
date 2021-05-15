#include<stdio.h>

int main(){
	int arr[3] = {};
	scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
	int i, j, tmp;
	for(i = 0; i < 2; i++){
		for(j = i+1; j <3; j++)
		if(arr[j] < arr[i]){
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	
	for(i = 0; i < 3; i++){
		printf("%d ", arr[i]);
	}
	return 0;
}

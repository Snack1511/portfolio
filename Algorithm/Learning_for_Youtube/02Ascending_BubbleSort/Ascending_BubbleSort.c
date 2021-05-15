#include<stdio.h>
/*
	BubbleSort
	
	요지 
	"옆에 있는 값과 비교해서 더 작은값을 앞으로 보내면 어떨까?"
	
	Checkpoint
	시간복잡도는 선택정렬과 같지만 세부적인 연산에서 차이가 난다.
	선택정렬과 버블정렬의 연산과정을 비교해보면 바로 알 수 있다. 
*/
int main(){
	int arr[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	int i, j, tmp;
	int k;
	
	for(i = 10; i > 0; i--){//N 
	
		for(j = 0; j < i - 1; j++){//N
			if(arr[j] >= arr[j + 1]){
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp; 
			}
		}
		
		for(k = 0; k < 10; k++){
			if(k == 9){
				printf("%d\n",arr[k]);
			}
			else{
				printf("%d ",arr[k]);
			}
			
		}
	}
	printf("\n------------Result------------\n\n");
	for(i = 0; i < 10; i++){
		if(i == 9){
			printf("%d\n",arr[i]);
		}
		else{
			printf("%d ",arr[i]);
		}
		
	}
	return 0;
}



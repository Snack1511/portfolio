#include<stdio.h>
/*
	Selection Sort
	
	요지 
	 "가장 작은 것을 선택해 앞으로 보내면 어떨까?"
	 
	 하나를 선택해 뒤의 나머지들과 비교해서
	 뒤의 인자가 선택된 것보다 크면 통과
	 작으면 선택한 인자와 스왑 
*/
int main(){
	int arr[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	int tmp = 0;
	int i, j;//, n, idx = 0, min = 999;
	
	/*for(i = 0; i < 9; i++){//N
		min = arr[i];
		for(j = i+1; j < 10; j++){//N
			if(arr[j] < min){
				min = arr[j];
				idx = j;
			}
		}
		if(arr[i] > min){
			tmp = arr[i];
			arr[i] = min;
			arr[idx] = tmp;
		}
	}*/
	//21-03-27 지금 보니 굉장히 쓸데없는 구문이 많다. 
	//창피하다. 아마 뇌를 빼고 우동사리를 넣어서 코드를 짠게 분명하다. 
	//min과 tmp를 강박적으로 쓸 필요가 없었는데, 이걸 써버린게 문제인것 같다.
	//시작점을 잘못 잡은 코드의 예시로 보자. 
	
	for(i = 0; i < 9; i++){
		for(j = i+1; j < 10; j++){
			if(arr[i] > arr[j]){
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	} 
	
	for(i = 0; n < 10; n++){
		if(n == 9){
			printf("%d\n",arr[n]);
		}
		else{
			printf("%d, ",arr[n]);
		}
		
	}
	
	
	
	
	return 0;
}
//Big O -> N*(N+1)/2 + N
//		-> O(N * N)
//Big O 표기는 계산식의 최고차항만 고려해 표기한다. 


//Big O 계산 시 꿀팁 -> For문은 N으로 계산된다. 
//					 -> 이중 For문 같이 겹쳐진 건 곱셈으로, 단일 포문 여러개는 덧샘으로 계산한다. 

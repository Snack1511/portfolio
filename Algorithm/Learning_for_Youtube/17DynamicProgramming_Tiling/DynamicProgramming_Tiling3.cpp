/*
	BOJ 2133
	
	3. 3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수
	
	n = 1 -> x
	n = 2 -> 3
	n = 3 -> x
	n = 4 -> 11 
	
	D(n) = 3 * D(n-2) + (2 * D(n - i)) 3 <= i <= n, i++,  D(0) = 1
	
	n=4일 때부터 고유한 모양이 2개씩 추가된다. 
*/
#include<stdio.h>
int arr[31];
int Result(int n){
	if(n == 0) return 1;
	if(n == 1) return 0;
	if(n == 2) return 3;
	if(arr[n] != 0) return arr[n];
	int result = 3*Result(n-2);
	
	for(int i = 3; i <= n; i++){
		if(i%2 == 0){
			result += (2*Result(n-i));
		}
	}
	arr[n] = result;
	return arr[n];
}

int main(){
	int n;
	scanf("%d", &n);
	
	printf("%d", Result(n));
	return 0;
}

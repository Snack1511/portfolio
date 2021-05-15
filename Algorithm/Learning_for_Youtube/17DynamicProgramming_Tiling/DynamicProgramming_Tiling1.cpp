
/*	BOJ 11726
	DynamicProgramming-Tiling
	
	1. 2*n크기의 직사각형을 1*2, 2*1로 채우는 방법의 수를 구하는 프로그램
	
		-> Dn = D [n-1] + D [n-2]
			D1 = 1
			D2 = 2
			D3 = 3
			D4 = 5
			...
			Dn = D[n-2]+D[n-1]
	
*/
#include<stdio.h>

int arr[1001];

int Result(int n){
	
	if( n == 1 ) return 1;
	if(n == 2)return 2;
	if(arr[n] != 0) return arr[n];
	arr[n] = (Result(n-1) + Result(n-2)) % 10007;
	return arr[n];
}

int main(){
	int n;
	scanf("%d", &n);
	
	printf("%d", Result(n));
	return 0;
}

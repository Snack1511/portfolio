/* BOJ 11727
	2. 2*n 직사각형을 1*2, 2*1, 2*2타일로 채우는 방법의 수
		D8 -> 171
		D12 -> 2731
		-> Dn = 
			D1 = 1
			D2 = 3 = 1+2 = (n-1) + 2
			D3 = 5 = 3+2 = (n-1) + 2
			D4 = 11
			D5 = 21
			Dn = D[n-1] + D[n-2]*2 ..?
*/

#include<stdio.h>

int arr[1001];

int Result(int n){
	
	if( n == 1 ) return 1;
	if(n == 2)return 3;
	if(arr[n] != 0) return arr[n];
	arr[n] = (Result(n-1) + (2 * Result(n-2))) % 10007;
	return arr[n];
}

int main(){
	int n;
	scanf("%d", &n);
	
	printf("%d", Result(n));
	return 0;
}

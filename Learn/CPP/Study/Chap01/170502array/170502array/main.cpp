#include<stdio.h>

int main(){

	int iArrayA[5] = {1, 2, 3, 4, 5};
	int iArrayB[] = {1, 2, 3, 4, 5};
	int iArrayC[5] = {1, 2};
	int iArrayD[5] = {0};
	char cStr2[] = "Morning!";


	for(int i = 0; i < 5; i++){

		printf("%d¹ø - [A : %d] [B : %d] [C : %d] [D : %d]\n\n", i, iArrayA[i], iArrayB[i], iArrayC[i], iArrayD[i]);
	
		
	}
		printf("%s\n", cStr2);
	

	
	

	return 0;
}
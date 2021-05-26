#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

	srand(unsigned(time(NULL) * time(NULL)));

	int iRand = rand()%45 + 1;
	printf("%d\n\n\n\n", iRand);

	int iLottery[6];

	for(int i = 0; i < 6; i++ ){

		iLottery[i] = rand()%45+1;

	}

	for(int i = 0; i < 6; i++ ){

		printf("%d\n", iLottery[i]);

	}
	printf("\n");

	for(int i = 1; i < 6; i++ ){

		for(int j = i+1;j<6;j++){
			
			if(iLottery[i] < iLottery[j]){
				int iTemp = 0;
				iTemp = iLottery[i];
				iLottery[i] = iLottery[j];
				iLottery[j] = iTemp;
			
			}
		}

	}

	for(int i = 0; i < 6; i++ ){

		printf("%d\n", iLottery[i]);
		
	}

	return 0;
}
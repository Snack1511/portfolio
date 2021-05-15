#include<iostream>
#include<stdlib.h>
#include<Time.h>
/*
	CountingSort
	
	요지
	크기를 기준으로 갯수를 세면 정렬과 비슷한 효과를 내며 더 빠르지 않을까?
	
	 CheckPoint
	정렬은 아니지만 정렬과 비슷한 효과를 내는 방법이다. 
	인자의 갯수를 파악한 후 인자를 인덱스로 한 배열에 넣고
	출력시 인자의 갯수만큼 인덱스를 반복출력한다. 
*/



using namespace std; 

void swap(int* a, int* b){
	int tmp;
	tmp = *a;
	a = b;
	*b = tmp;
}

int main(){
	int tmp;
	int count[5];
	int array[30];
	srand((int)time(NULL));
	for(int i = 0; i < 30; i++){
		array[i] = (rand()%5) + 1;
	}
	
	for(int i = 0; i < 30; i++){
		cout << array[i] << " ";
		if((i+1)%10 == 0){
			cout << endl;
		}
	}
	
	cout << "==========Input==========" << endl;
	
	for(int i = 0; i < 5; i++){
		count[i] = 0;
	}
	for(int i = 0; i < 30; i++){
		count[array[i] - 1]++;
	}
	
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < count[i]; j++){
			cout << i + 1 << " ";
			
		}
		
	}
	
	
	
	
	return 0;
}

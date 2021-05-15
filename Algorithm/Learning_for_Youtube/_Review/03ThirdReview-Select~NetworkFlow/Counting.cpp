#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int arr[30];
int counting[15];

void RandomInput(){
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 30; i++) {
		arr[i] = (rand() % 13) + 1;

	}
	
	for (int i = 0; i < 30; i++) {
		cout << arr[i] << " ";
		if (i % 10 == 9) {
			cout << endl;
		}

	}
	cout << endl << endl;
}

void Counting(){
	for(int i = 0; i < 30; i++){
		counting[arr[i]] += 1;
	}
	
	for(int i = 0; i < 15; i++){
		while(counting[i]>0){
			cout << i << " ";
			counting[i]--;
		}
	}
}

int main(){
	
	RandomInput();
	Counting();
	return 0;
}

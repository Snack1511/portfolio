#include<stdio.h>


int main(){
	int i = 0;
	/*while(i < 10){
		i++;
		if(i%2 == 1){
			continue;
		}
		printf("%d\n", i);
		

		
	}*/

	while(1){
		i++;

		if((i % 2 == 1)||(i % 3 == 0)||(i % 4 == 0)||(i % 5 == 0))
			continue;
		if(i >= 100)
			break;
		
		printf("%d\n", i);
	}
	

}
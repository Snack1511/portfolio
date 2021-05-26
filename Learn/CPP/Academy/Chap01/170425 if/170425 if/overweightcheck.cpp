#include<stdio.h>

int main(){
	int iHeight;
	int iWeight;

	float fHeight;
	float fBMI;
	

	printf("키(cm) : \n");
	scanf("%f", &iHeight);

	printf("몸무게(kg) : \n");
	scanf("%f", &iWeight);
	fHeight = iHeight/100.0f;
	fBMI = iWeight/(fHeight*fHeight);
	
	printf("BMI : %f\n",fBMI);

	if(fBMI >= 30.0){
		printf("고도비만");

	}
	else if(fBMI >= 25.0&&fBMI < 30.0){
		printf("비만");

	}
	else if(fBMI >= 23.0&&fBMI < 25.0){
		printf("과체중");

	}
	else if(fBMI >= 18.5&&fBMI < 23.0){
		printf("표준");

	}
	else if(fBMI < 18.5){
		printf("체중미달");

	}
	return 0;
}
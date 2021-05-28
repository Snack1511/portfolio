#include<stdio.h>

int main(){

	int iMon;
	while(1){
		printf("탄생월 입력 : ");
		scanf("%d", &iMon);

		switch(iMon){

		case 1:
			printf("1월의 탄생석은 가넷입니다.\n");
			break;
		case 2:
			printf("2월의 탄생석은 자수정입니다.\n");
			break;
		case 3:
			printf("3월의 탄생석은 아쿠아마린입니다.\n");
			break;
		case 4:
			printf("4월의 탄생석은 다이아몬드입니다.\n");
			break;
		case 5:
			printf("5월의 탄생석은 에메랄드입니다.\n");
			break;
		case 6:
			printf("6월의 탄생석은 진주입니다.\n");
			break;
		case 7:
			printf("7월의 탄생석은 루비입니다.\n");
			break;
		case 8:
			printf("8월의 탄생석은 페리도트입니다.\n");
			break;
		case 9:
			printf("9월의 탄생석은 사파이어입니다.\n");
			break;
		case 10:
			printf("10월의 탄생석은 오팔입니다.\n");
			break;
		case 11:
			printf("11월의 탄생석은 토파즈입니다.\n");
			break;
		case 12:
			printf("12월의 탄생석은 터키석입니다.\n");
			break;
		default:
			printf("1년은 12개월 입니다. 너님은 지구인이 아니신가요?\n");


		}
	}
	/*printf("01. 무  기 상점\n");
	printf("02. 방어구 상점\n");
	printf("03. 장신구 상점\n");
	printf("04. 물  약 상점\n");
	printf("05. 잡  화 상점\n");
	int iNum;

	scanf("%d", &iNum);

	switch(iNum){

	case 1:
		printf("01. 무  기 상점\n");
		break;
	case 2:
		printf("02. 방어구 상점\n");
		break;
	case 3:
		printf("03. 장신구 상점\n");
		break;
	case 4:
		printf("04. 물  약 상점\n");
		break;
	case 5:
		printf("05. 잡  화 상점\n");
		break;

	default:
		printf("잘못입력ㅇㅇ\n");
	}*/

	return 0;
}
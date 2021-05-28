#include<stdio.h>
#include<malloc.h>
#include<string>
#include<time.h>




//const = 상수화

int g_iNum;//전역변수는 선언만해도 0으로 초기화 된다
const int MAX = 100;//const 변수는 선언과 동시에 값을 세팅해줘야 한다
					  //지역변수로 써도 바뀌지 않는다.




enum OBJID{
	OBJ_PLAYER,
	OBJ_MONSTER,
	OBJ_END,

};

typedef struct tagInfo{
	char* Name;


	int iKor;
	int iEng;
	int iMath;

	tagInfo(){};
	tagInfo(char* pName, int _ik, int _ie, int _im) :Name(pName), iKor(_ik), iEng(_ie), iMath(_im){};
}INFO;



//전역변수 선언부

//INFO* ObjList[OBJ_END];//전역변수를 많이 쓰면 무거워진다


//함수 전방선언부
char* SetName();


//메인
int main(){
	INFO* ObjList[OBJ_END][MAX];//잠깐쓰고 필요없는건 지역변수로 써야 가볍다
				//키값    인덱스  ===> 유지보수 편하다
	for(int i = 0; i < OBJ_END; i++){
		for(int j = 0; j < MAX; j++){
			ObjList[i][j] = (INFO*)malloc(sizeof(INFO));

			ObjList[i][j]->iKor = (i*MAX+j);  

		}

	}

	for(int i = 0; i < OBJ_END; i++){
		for(int j = 0; j < MAX; j++){
			printf("%d\n", ObjList[i][j]->iKor);
		}

	}



	return 0;									
}


//함수정의

char* SetName(){
	char str[128] = "";

	printf("이름입력 : ");
	scanf("%s", str);

	char* pName = (char*)malloc(strlen(str));
	strcpy(pName, str);

	return pName;

}

void Initialize(INFO* _info){

	int ikor, ieng, imath;

	printf("국어점수입력 : ");
	scanf("%d", &ikor);
	printf("영어점수입력 : ");
	scanf("%d", &ieng);
	printf("수학점수입력 : ");
	scanf("%d", &imath);


	

}

//GG
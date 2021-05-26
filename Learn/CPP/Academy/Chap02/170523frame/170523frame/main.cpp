#include<stdio.h>
#include<time.h>
#include<Windows.h>
//더블버퍼의 시작
//하나의 버퍼에 지우고 다시 그림


int main(){
	//time() => 매초마다 루프
	DWORD dwTime = GetTickCount();//1000분의 1초
	//DWORD = unsigned long
	//int iTime = time(NULL);//현재시간으로 초기화
	int iNum = 0;
	while(true){
		if(dwTime + 50 < GetTickCount()){//time함수가 증가함에 따라 자연스럽게 성립하는 순간이 온다
			//iTime = time(NULL);//다시 시간을 맞춰준다 -> 게임을 돌리기엔 좋지않다
			dwTime = GetTickCount();

			system("cls");

			printf("%d : hellow world\n", iNum++);
		}
	
	}


	return 0;
}//엔터를 치면 로고에서 스테이지
//다시 치면 스테이지에서 메인메뉴
#include "GameRoom.h"



GameRoom::GameRoom()
{
	USER user1;
	user1.userName = "aaa";
	user1.level = 1;
	user1.exp = 0;

	USER user2;
	user2.userName = "bbb";
	user2.level = 2;
	user2.exp = 0;

	USER user3;
	user3.userName = "ccc";
	user3.level = 3;
	user3.exp = 0;

	USER user4;
	user4.userName = "ddd";
	user4.level = 4;
	user4.exp = 0;

	USER user5;
	user5.userName = "eee";
	user5.level = 5;
	user5.exp = 0;

	USER user6;
	user6.userName = "fff";
	user6.level = 6;
	user6.exp = 0;

}


GameRoom::~GameRoom()
{
	Clear();
}



bool GameRoom::AddUser(USER& tUserInfo) 
{
	if (IsFull()) 
	{
		cout << "꽉찼습니다" << endl;
	}
	users.push_back(tUserInfo);
}
bool GameRoom::DelUser(char* userName)
{
	
	if (IsEmpty()) 
	{
		cout << "방이 비었습니다" << endl;
	}
	else {
		users.erase();
		if (userName == masterUserName)
		{
			cout << "방장이 나갔습니다" << endl << "맨 앞사람을 방장으로 선출합니다" << endl;
		}
	}

}
bool GameRoom::IsEmpty()
{
	
}
bool GameRoom::IsFull()
{
	
}
USER& GameRoom::GetUserInfo(char* userName)
{
	
}
USER& GameRoom::GetMasterUser()
{
	
}
USER& GameRoom::GetLastUserInfo()
{
	
}
bool GameRoom::BanUser(int num)
{
	
}
void GameRoom::Clear()
{
	users.clear();
}
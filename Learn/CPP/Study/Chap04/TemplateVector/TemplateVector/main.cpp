#include<iostream>
#include<vector>

using namespace std;
typedef struct taginfo 
{
	char * name;
	int Level;
	int HP;
}INFO;


void main() 
{
	INFO Player;
	Player.name = "Player";
	Player.Level = 1;
	Player.HP = 10;

	INFO Monster;
	Monster.name = "Monster";
	Monster.Level = 10;
	Monster.HP = 1;

	INFO NPC;
	NPC.name = "NPC";
	NPC.Level = 99;
	NPC.HP = 99;

	INFO BossMon;
	BossMon.name = "BossMon";
	BossMon.Level = 99;
	BossMon.HP = 99;

	INFO BossNPC;
	BossNPC.name = "BossNPC";
	BossNPC.Level = 99;
	BossNPC.HP = 99;

/*
	//저장할 벡터
	vector<INFO> characters;

	//추가하기
	characters.push_back(Player);
	characters.push_back(Monster);
	characters.push_back(NPC);

	//반복자 생성
	//(1) container-type::const_iterator // 값을 읽기만 할 때 사용
	//(2) container-type::iterator       // 값의 변경이 있을 때 사용
	//(3) container-type::reverse_iterator // 정방향 반복자를 역방향 반복자로 변환

	//순방향 접근
	vector<INFO>::iterator iTerPos;
	for (iTerPos = characters.begin(); iTerPos != characters.end(); iTerPos++) 
	{
		cout << iTerPos->name << " 의 레벨 : " << iTerPos->Level << " HP : " << iTerPos->HP << endl;
	}
	cout << endl;

	//역방향 접근
	vector<INFO>::reverse_iterator Re_iTerPos;
	for (Re_iTerPos = characters.rbegin(); Re_iTerPos != characters.rend(); Re_iTerPos++)
	{
		cout << Re_iTerPos->name << " 의 레벨 : " << Re_iTerPos->Level << " HP : " << Re_iTerPos->HP << endl;
	}
	cout << endl;



	int totalChar = characters.size();//vector에 들어가 있는 수

	//배열방식으로 접근
	for (int i = 0; i < totalChar; i++) 
	{
		cout << characters[i].name << " 의 레벨 : " << characters[i].Level << " HP : " << characters[i].HP << endl;
	}
	cout << endl;

	//각 캐릭터에 접근
	INFO& firstChar = characters.front();//처음
	INFO& lastChar = characters.back();//마지막
	INFO& atChar = characters.at(1);//n번째 캐릭터

	//각 캐릭터 이름 접근
	cout << firstChar.name << endl;
	cout << lastChar.name << endl;
	cout << atChar.name << endl;

	//삭제
	characters.pop_back();

	totalChar = characters.size();
	for (int i = 0; i < totalChar; i++)
	{
		cout << characters[i].name << " 의 레벨 : " << characters[i].Level << " HP : " << characters[i].HP << endl;
		cout << "Pop_back!" << endl;
	}
	cout << endl;

	totalChar = characters.size();
	cout << "캐릭터의 사이즈는 : " << totalChar << endl;
	if (!characters.empty()) 
	{
		characters.clear();
		cout << "clear!" << endl;
	}

	totalChar = characters.size();

	cout << "캐릭터의 사이즈는 : " << totalChar << endl;
*/


	cout << "삽입" << endl << endl;

	//저장할 새 vector 만들기
	vector<INFO> characters;

	characters.push_back(Player);
	//characters.push_back(NPC);
	characters.push_back(Monster);

	vector<INFO>::iterator iTerPos;

	iTerPos = characters.begin();
	for (iTerPos = characters.begin(); iTerPos != characters.end(); iTerPos++)
	{
		cout << iTerPos->name << " 의 레벨 : " << iTerPos->Level << " HP : " << iTerPos->HP << endl;
	}
	cout << endl;



	iTerPos = characters.begin();
	characters.insert(iTerPos, NPC);
	for (iTerPos = characters.begin(); iTerPos != characters.end(); iTerPos++)
	{
		cout << iTerPos->name << " 의 레벨 : " << iTerPos->Level << " HP : " << iTerPos->HP << endl;
	}
	cout << endl;


	
	characters.insert(iTerPos, 2, BossMon);
	for (iTerPos = characters.begin(); iTerPos != characters.end(); iTerPos++)
	{
		cout << iTerPos->name << " 의 레벨 : " << iTerPos->Level << " HP : " << iTerPos->HP << endl;
	}
	cout << endl;



	//새로운 캐릭터vector 생성
	vector<INFO> characters2;

	characters2.push_back(BossNPC);
	characters2.push_back(BossNPC);
	characters2.push_back(BossNPC);
	//character1에 삽입
	characters.insert(iTerPos, characters2.begin(), characters2.end());

	for (iTerPos = characters.begin(); iTerPos != characters.end(); iTerPos++)
	{
		cout << iTerPos->name << " 의 레벨 : " << iTerPos->Level << " HP : " << iTerPos->HP << endl;
	}
	cout << endl;


	for (iTerPos = characters2.begin(); iTerPos != characters2.end(); iTerPos++)
	{
		cout << iTerPos->name << " 의 레벨 : " << iTerPos->Level << " HP : " << iTerPos->HP << endl;
	}
	cout << endl;

	
	//삭제
	cout << "삭제" << endl << endl;
	characters2.erase(characters2.begin());

	for (iTerPos = characters2.begin(); iTerPos != characters2.end(); iTerPos++)
	{
		cout << iTerPos->name << " 의 레벨 : " << iTerPos->Level << " HP : " << iTerPos->HP << endl;
	}
	cout << endl;


	characters.erase(characters.begin());

	for (iTerPos = characters.begin(); iTerPos != characters.end(); iTerPos++)
	{
		cout << iTerPos->name << " 의 레벨 : " << iTerPos->Level << " HP : " << iTerPos->HP << endl;
	}
	cout << endl;


	characters2.erase(characters2.begin(), characters2.end());

	if (characters2.empty()) 
	{
		cout << "다 지워짐" << endl;
	}

	characters.clear();

	if (characters2.empty()) 
	{
		cout << "첫번째 것도 지워짐" << endl;
	}

}
#include <iostream>
#include <map>
using namespace std;

typedef struct tagInfo
{
	char * name;
	int Level;
	int HP;

}INFO;

void main()
{
	map<int, INFO > characters;

	INFO player;
	player.name = "Player";
	player.Level = 1;
	player.HP = 10;

	INFO npc;
	npc.name = "NPC";
	npc.Level = 99;
	npc.HP = 99;

	INFO monster;
	monster.name = "Monster";
	monster.Level = 10;
	monster.HP = 1;

	characters.insert(map<int, INFO>::value_type(0, player));
	characters.insert(map<int, INFO>::value_type(1, npc));
	characters.insert(map<int, INFO>::value_type(2, monster));

	map<int, INFO>::iterator iterPos;

	for (iterPos = characters.begin(); iterPos != characters.end(); iterPos++)
	{
		cout << "Key : " << iterPos->first << endl;
		cout << "HP : " << iterPos->first << endl;
	}

	iterPos = characters.find(1);
	if (iterPos == characters.end()) {
		cout << "no data" << endl;
	}
	else 
	{
		cout << iterPos->second.HP << endl;
	}

	characters.erase(iterPos);

	for (iterPos = characters.begin(); iterPos != characters.end(); iterPos++) 
	{
		cout << "Key : " << iterPos->first << endl;
		cout << "HP : " << iterPos->second.HP << endl;
	}

	characters.clear();

	if (characters.empty()) 
	{
		cout << characters.size() << endl;
	}
}

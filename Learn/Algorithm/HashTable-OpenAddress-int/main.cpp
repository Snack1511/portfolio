#include "hash.h"

int main()
{ 
	HashTable hashTable(17);
	int key;

	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		key = rand() % 100;
		hashTable.set(key);
	}
	hashTable.printAll();

	while (1) 	{
		cout << "삭제할 key 값 입력(종료 -1입력): ";
		cin >> key;
		if (key != -1)
		{
			if (hashTable.get(key) != 0)  {
				hashTable.del(key);
				hashTable.printAll();
			}
			else cout << "해시테이블 안에 " << key << "가 없습니다.\n";
		}
		else break;
	}
	cin.ignore();
	return 0;
}


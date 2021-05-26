#include "hash.h"

int main()
{ 
	HashTable hashTable(17);
	string key;

	while (1)
	{
		cout << "입력할 key 값 입력(종료  exit 입력): ";
		cin >> key;
		if (key != "exit")
		{
			hashTable.set(key);
		}
		else break;

	}

	hashTable.printAll();
	while (1)
	{
		cout << "삭제할 key 값 입력(종료  exit 입력): ";
		cin >> key;
		if (key != "exit")
		{
			if (hashTable.get(key) != "")  {
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


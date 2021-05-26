#include "hash.h"

HashTable::HashTable( int size)
{
	//코드 추가
}

HashTable::~HashTable()
{
	//코드 추가
}

void HashTable::set(int key)
{
	int addr1, addr2;
	double usage;
	
	usage = this->occupiedCount / (double)this->tableSize;
	if (usage > 0.5) { // 적재율 50% 넘으면 재해싱
		reHash();
	}

	addr1 = hash(key); //해시주소 계산
	cout << key << "의  주소: " << addr1 << "  ";
	while (this->table[addr1] != 0 && this->table[addr1] != key) //다른 키가 이미 들어있는 경우
	{
		//코드 추가
	}
	this->table[addr1] = key;
	this->occupiedCount++;
	cout << "키가 들어간 주소: " << addr1 << endl;
}

int HashTable::get(int key)
{

	int addr1 = hash(key);
	int addr2;

	while (this->table[addr1] !=0 &&	this->table[addr1] != key ) //다른 키가 이미 들어있는 경우
	{
		//코드 추가
	}
	return this->table[addr1];

}

void HashTable::del(int key)
{
	int addr1, addr2;

	addr1 = hash(key);
	if (this->table[addr1] == key) 	{
		this->table[addr1] =DELETE;
	}
	else 	{
		while (this->table[addr1] !=0 && this->table[addr1] != key) 		{
			//코드 추가
		}
		this->table[addr1] =DELETE;
	}
}

int HashTable::hash(int key)
{
	//코드 추가
}

int HashTable::hash2(int key)//두번째 해시 함수
{
	//코드 추가
}


void HashTable::reHash()
{

	int i = 0;
	int* oldTable = this->table;
	int oldSize = this->tableSize;

	// 새 해시 테이블 만들기
	int* newTable = new int [this->tableSize*2];
	this->tableSize = this->tableSize * 2;
	memset(newTable, 0, sizeof(int)* this->tableSize);
	this->occupiedCount = 0;
	this->table = newTable;

	cout << "\n해시 데이블 증가 새로운 테이블 크기 : " << this->tableSize;
	for (i = 0; i < oldSize; i++) // 이전 해시 테이블에 있던 데이터를 새 해시 테이블로 옮김
	{
		if (oldTable[i] !=0) 	{
			this->set( oldTable[i] );
		}
	}	
	delete[] oldTable; // 이전 해시 테이블 해제
}


void HashTable::printAll()
{
	cout << "## 해시 테이블 내용 \n";
	for (int i = 0; i < this->tableSize; i++){
		if (this->table[i] ==0 || this->table[i] == DELETE)
			cout << "(index:" << i << "): " << "데이터 없음" << endl;
		else cout << "(index:" << i << "): " << this->table[i] << endl;

	}
}
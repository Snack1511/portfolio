#include "hash.h"

HashTable::HashTable( int size)
{
	this->table = new  string[size];
	for (int i = 0; i < size; i++)
		this->table[i] = "";
	this->tableSize = size;
	this->occupiedCount = 0;
}

HashTable::~HashTable()
{
	delete[] this->table;
}

void HashTable::set(string key)
{
	int addr1, addr2;
	double usage;
	
	usage = this->occupiedCount / (double)this->tableSize;
	if (usage > 0.5) { // 적재율 50% 넘으면 재해싱
		reHash();
	}

	addr1 = hash(key);
	cout << key << "의 해시주소: " << addr1 << endl;
	while (this->table[addr1] != "" && this->table[addr1] != key)//공백이 아니면서 다른 키가 이미 들어있는 경우
	{
		addr2 = hash2(key);
		addr1 = (addr1 + addr2) % this->tableSize; //이중해싱 주소 계산
		cout << "충동발생 : key(" << key << ") 새 주소: " << addr1 << endl;
	}

	this->table[addr1] = key;
	this->occupiedCount++;
	cout << "키(" << key << ")가 들어간 주소: " << addr1 << endl;

}

string HashTable::get(string key)
{

	int addr1 = hash(key);
	int addr2;

	while (this->table[addr1] != "" &&	this->table[addr1] != key )
	{
		addr2 = hash2(key);
		addr1 = (addr1 + addr2) % this->tableSize;
	}
	return this->table[addr1];

}

void HashTable::del(string key)
{
	int addr1, addr2;

	addr1 = hash(key);
	if (this->table[addr1] == key)
	{
		this->table[addr1] = "del";
	}
	else
	{
		while (this->table[addr1] != "" && this->table[addr1] != key)
		{
			addr2 = hash2(key);
			addr1 = (addr1 + addr2) % this->tableSize; //이중해싱 주소 계산
		}
		this->table[addr1] = "del";
	}
}


int HashTable::hash(string key)
{
	int i = 0;
	int hashValue = 0;
	
	for (i = 0; i < key.size(); i++)
	{
		hashValue = (hashValue << 3) + key[i];
	}
	hashValue = hashValue % this->tableSize;
	return hashValue;
}

int HashTable::hash2(string key)//두번째 해시 함수
{
	int i = 0;
	int hashValue = 0;
	for (i = 0; i < key.size(); i++)
	{
		hashValue = (hashValue << 2) + key[i];
	}

	hashValue = hashValue % (tableSize - 3); 
	return hashValue + 1;

}


void HashTable::reHash()
{

	int i = 0;
	string* oldTable = this->table;
	int oldSize = this->tableSize;

	// 새 해시 테이블 만들기
	string* newTable = new string[this->tableSize*2];
	for (int i = 0; i < this->tableSize * 2; i++)
		newTable[i] = "";
	this->tableSize = this->tableSize * 2;
	this->occupiedCount = 0;
	this->table = newTable;

	cout << "\nrehashed. 새로운 테이블 크기 : " << this->tableSize;
	for (i = 0; i < oldSize; i++) // 이전 해시 테이블에 있던 데이털르 새 해시 테이블로 옮김
	{
		if (oldTable[i] != "")
		{
			this->set( oldTable[i] );
		}
	}	
	delete[] oldTable; // 이전 해시 테이블 해제
}


void HashTable::printAll()
{
	cout << "## 해시 테이블 내용 \n";
	for (int i = 0; i < this->tableSize; i++){
		if (this->table[i] == "" || this->table[i] == "del")
			cout << "(index:" << i << "): " << "데이터 없음" << endl;
		else cout << "(index:" << i << "): " << this->table[i] << endl;

	}
}
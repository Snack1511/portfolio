#include "hash.h"
HashTable::HashTable( )
{
	for (int i = 0; i < TABLE_SIZE; i++)
		this->table[i] = NULL;
	this->tableSize = TABLE_SIZE;
}

void HashTable::put (int key)
{
	Node *node = new Node;
	node->key = key;
	node->next = NULL;
	//코드 추가
	int pos = hash(key);
	if (this->table[pos] == NULL){
		this->table[pos] = node;
	}
	else {
		node->next = this->table[pos];
		this->table[pos] = node;
	}
}


void HashTable::del(int key)
{
	int addr = hash(key); //해시 값 계산
	if (this->table[addr] == NULL) {
		cout << key << "가 없습니다. " << endl;
		return;
	}

	Node* delNode = NULL;
	if (this->table[addr]->key == key) 	{
		delNode = this->table[addr];
		this->table[addr] = this->table[addr]->next;
	}
	else 	{
		Node* node = this->table[addr];
		Node* next = node->next;
		//코드 추가
		while (next){
			if (next->key == key){
				delNode = next;
				node->next = next->next;
				break;
			}
			else{
				node = next;
				next = next->next;
				
			}
		}
	}
	delete delNode;
}

Node*  HashTable::get(int key)
{
	int addr = hash(key); //해시 값 계산
	if (this->table[addr] == NULL)
		return NULL;

	if (this->table[addr]->key == key)
	{
		return this->table[addr];
	}
	else
	{
		Node* node = this->table[addr]->next;
		while (node != NULL){
			if (node->key == key) return node;
			node = node->next;
		}
	}
	return  NULL;
}

int HashTable::hash(int key)
{
	return key % this->tableSize;
}

void HashTable::printAll()
{
	cout << "\n## 해시 테이블 내용 \n";
	for (int i = 0; i < this->tableSize; i++)	{
		cout << "(index:" << i <<"): " ;
		if (this->table[i] != NULL)		{
			Node* node = this->table[i];
			while (node->next)	{
				cout << node->key << "  ";
				node = node->next;
			}
			cout << node->key << endl;
		}
		else	{
			cout << "데이터 없음" << endl;
		}
	}
}


#include <iostream>
#include <time.h>
using namespace std;

#define TABLE_SIZE 13

typedef struct node
{
	int key;
	struct node* next;
} Node;

class HashTable
{
	Node* table[TABLE_SIZE];
	int tableSize;

public:
	HashTable();
	void put (int key);
	Node*  get(int key);
	void del(int key);
	int hash(int key);
	void printAll();
};

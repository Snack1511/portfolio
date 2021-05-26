#include <iostream>
#include <string>
#include <time.h>
#define DELETE -1
using namespace std;

class HashTable {
	int *table;
	int occupiedCount;
	int tableSize;

public:
	HashTable(int size = 13);
	~HashTable();
	void set(int key);
	int get(int key);
	void del(int key);
	int hash(int key);
	int hash2(int key);
	void reHash();
	void printAll();
};
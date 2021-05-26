#include <iostream>
#include <string>

using namespace std;

class HashTable {
	string *table;
	int occupiedCount;
	int tableSize;

public:
	HashTable(int size = 13);
	~HashTable();
	void set(string key);
	string get(string key);
	void del(string key);
	int hash(string key);
	int hash2(string key);
	void reHash();
	void printAll();
};
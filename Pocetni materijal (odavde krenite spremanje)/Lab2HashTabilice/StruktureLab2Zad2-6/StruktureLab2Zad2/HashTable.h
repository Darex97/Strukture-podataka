#include"SLList.h"
class HashTable 
{
public:
	SLList *niz;
	int count;
	int length;
public:
	HashTable(int l);
	~HashTable();

	int h(HashObject);
	int f(int);
	
	void insert(HashObject);
	HashObject* find(HashObject);
	void printAll();


	
};
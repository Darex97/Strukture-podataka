#include "SLList.h"
class ChainedHashTable
{
public:
	int n;
	int t;
	SLList *array;

	ChainedHashTable(int);
	~ChainedHashTable();
	void insert(HashObject& obj);
	void withdraw(HashObject obj);
	/*void withdraw(int key);*/
	HashObject find(int key);
	void display();
	int f(int);
	int f(char*);
	int h(HashObject);
};
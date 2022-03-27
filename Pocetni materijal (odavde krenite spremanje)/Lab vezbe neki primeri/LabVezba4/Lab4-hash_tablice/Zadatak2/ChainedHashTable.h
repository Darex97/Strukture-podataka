#include "LList.h"
class ChainedHashTable
{
public:
	int n;
	int t;
	LList *array;

	ChainedHashTable(int);
	~ChainedHashTable();
	void insert(HashObject& obj);
	void withdraw(HashObject obj);
	void display();
	int h(HashObject);
};
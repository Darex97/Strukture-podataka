#include "HashObject.h"
#include <iostream>
using namespace std;
class HashTable
{
	int n;
	int t;
	HashObject *a;
public:
	HashTable(int);
	~HashTable();
	int h(HashObject obj);
	void insert(HashObject& obj);
	void withdraw(char*);
	void display();
};
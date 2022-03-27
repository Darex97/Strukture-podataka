#include "HashObject.h"
#include <iostream>
using namespace std;
class OpenScatterTable
{
	int n;
	int t;
	HashObject *a;
public:
	OpenScatterTable(int);
	~OpenScatterTable();
	int h(HashObject obj);
	int f(char*);
	int findunocupied(HashObject);
	int findmatch(char*);
	void insert(HashObject& obj);
	void withdraw(char*);
	void display();
};
#include "HashObject.h"
#include <string>
using namespace std;
class OpenScatterTable
{
	int n;
	int t;
	HashObject *a;
public:
	OpenScatterTable(int);
	~OpenScatterTable();
	int f(char*);
	int h(HashObject obj);
	int findunocupied(HashObject);
	int findmatch(char*);
	void insert(HashObject& obj);
	void withdraw(char*);
	void display();
};
#include <iostream>
using namespace std;
#include <string>
using namespace std;
class HashObject
{
	int key;
	char* record;
	HashObject *next;
public:
	HashObject();
	HashObject(char*);
	HashObject(int,char*);
	HashObject(int x,char*,HashObject*);
	HashObject operator=(const HashObject);
	bool operator==(HashObject& o){return this->record==o.getrecord();};
	void deleterecord();
	int getkey(){return key;};
	char* getrecord(){return record;};
	bool IsEqualKey(int k){return this->key==k;};
	void print();
	void setnext(HashObject* sl){this->next=sl;};
	HashObject* getnext(){return this->next;};
};
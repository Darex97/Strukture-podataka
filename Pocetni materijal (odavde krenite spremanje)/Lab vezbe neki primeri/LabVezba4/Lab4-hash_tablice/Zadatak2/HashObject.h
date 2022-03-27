#include <iostream>
using namespace std;
#include <string>
using namespace std;
class HashObject
{
	int key;
	char* ime;
	char* prezime;
	char *tel;
	HashObject *next;
public:
	HashObject();
	HashObject(char*,char*,char*n);
	HashObject(char*,char*,char*n,HashObject*);
	HashObject operator=(HashObject);
	void deleteobj();
	int getkey(){return key;};
	void setkey(int k){this->key=k;};
	bool IsEqualKey(int k){return this->key==k;};
	void print();
	void setnext(HashObject* sl){this->next=sl;};
	HashObject* getnext(){return this->next;};
	void setime(char* im){this->ime=im;};
	void setprez(char* pr){this->prezime=pr;};
	void settel(char* tl){this->tel=tl;};
	char* getime(){return ime;};
	char* getprezime(){return prezime;};
	char* gettel(){return tel;};
};
#include <iostream>
using namespace std;
class HashObject
{
	char* ime;
	char* prezime;
	char *tel;
	bool free;
public:
	HashObject();
	HashObject(char*,char*,char*);
	HashObject& operator=(HashObject&);
	void set_ime(char* rec){this->ime=rec;};
	void set_prezime(char* rec){this->prezime=rec;};
	void set_tel(char* rec){this->tel=rec;};
	void set_free(bool t){this->free=t;};
	char* get_ime(){return ime;};
	char* get_prezime(){return prezime;};
	char* get_tel(){return tel;};
	bool get_free(){return free;};
	void deleterecord();
	void print();
};
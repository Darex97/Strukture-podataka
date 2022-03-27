#include <iostream>
using namespace std;
class HashObject
{
	char* ime;
	char* prezime;
	char *tel;
	bool free;
	int next;
public:
	HashObject();
	HashObject(char*, char*, char*);
	HashObject(char*, char*, char*, int);
	HashObject& operator=(HashObject&);
	void set_ime(char* rec){ this->ime = rec; };
	void set_prezime(char* rec){ this->prezime = rec; };
	void set_tel(char* rec){ this->tel = rec; };
	void set_next(int sl){ this->next = sl; };
	void set_free(bool t){ this->free = t; };
	char* get_ime(){ return ime; };
	char* get_prezime(){ return prezime; };
	char* get_tel(){ return tel; };
	int get_next(){ return next; };
	bool get_free(){ return free; };
	void deleterecord();
	void print();
};
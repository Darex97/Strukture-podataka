#include <iostream>
using namespace std;
class HashObject
{
	char* keyword;
	bool free;
public:
	HashObject();
	HashObject(char*);
	HashObject& operator=(HashObject&);
	void set_keyword(char* rec){ this->keyword = rec; };
	void set_free(bool s){ this->free = s; };
	char* get_keyword(){ return keyword; };
	bool get_free(){ return free; };
	void deleterecord();
	void print();
};
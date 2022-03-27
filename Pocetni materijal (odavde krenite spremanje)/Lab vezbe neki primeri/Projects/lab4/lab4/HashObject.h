#pragma once
#include <iostream>
using namespace std;
class HashObject
{
	char* keyword;
	bool free;
	int next;
public:
	HashObject();
	HashObject(char*);
	HashObject(char*, int);
	HashObject& operator=(HashObject&);
	void set_keyword(char* rec){ this->keyword = rec; };
	void set_next(int sl){ this->next = sl; };
	void set_free(bool s){ this->free = s; };
	char* get_keyword(){ return keyword; };
	int get_next(){ return next; };
	bool get_free(){ return free; };
	void deleterecord();
	void print();
};
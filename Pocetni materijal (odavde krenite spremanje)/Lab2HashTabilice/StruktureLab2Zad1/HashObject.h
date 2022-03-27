#pragma once
//Ovu klasu cemo koristiti umesto SLLNode
//Jer je nasa lancana lista sacinjena od HashObjekata
#include<iostream>
using namespace std;
class HashObject 
{
public:
//Pronadji slicnosti sa klasom SLLNode
//Mozes da posmatras key i info kao
// info deo SLLNode-a i next je pointer na sledeci

	char* key;
	int record;
	HashObject* next;
public:
	HashObject();
	HashObject(char* k);
	HashObject(char* k, int r);
	HashObject(char* k, int r, HashObject* obj);
	~HashObject();

	char* getKey() { return this->key; }
	bool isEqualKey(char* s) 
	{
		return this->key == s; 
	}
	//Zasto su identicni stringovi sacuvani na istom mestu u memoriji.
	bool operator==(HashObject*);
	int getRecord() { return this->record; }

	void print();




};
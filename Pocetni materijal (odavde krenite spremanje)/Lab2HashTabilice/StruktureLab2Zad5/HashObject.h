#pragma once
/*Zad 5. Projektovati klasu za rad sa hash tablicom 
sa unutrašnjim ulanèavanjem koja služi za smeštanje
kljuènih reèi programskog jezika C++, sa korišæenjem 
posebnog prostora za smeštanje sinonima. */
#include<iostream>
using namespace std;
class HashObject 
{
public:
	char* key;
	int record;
	bool free;
	int next;
	
public:
	
	HashObject();
	HashObject(char*);
	HashObject(char*,int);
	HashObject(char*, int, int);
	HashObject(HashObject&);
	~HashObject();

	HashObject& operator=(HashObject);
	bool operator==(HashObject obj) { return getKey() == obj.getKey(); }
	char* getKey() { return this->key; }
	int getRecord() { return record; }
	bool isEqualKey(char* s) { return s==getKey(); }
	bool isFree() { return this->free; }
	void print();
	void deleteRecord();


};
#pragma once
#include<string>
#include<iostream>
using namespace std;

class HashObject
{
public:
	int key;
	char *record;
	HashObject *next;

	HashObject(int key,char *word);
	HashObject(int key,char *word,HashObject *next);
	int getKey();
	char* getRecord();
	void print();
	~HashObject();
};


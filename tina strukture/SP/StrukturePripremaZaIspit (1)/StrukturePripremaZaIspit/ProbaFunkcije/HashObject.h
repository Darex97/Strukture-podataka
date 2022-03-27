#pragma once
#include <iostream>
using namespace std;

template <class T, class R>
class HashObject{
protected:
	T key;
	R record;

public :
	HashObject() { /*key = (T)0; record = (R)0;*/ }
	HashObject(T key) { this->key = key, record = NULL; }
	HashObject(T key, R record) { this->key = key; this->record = record; }
	~HashObject() { deleteRecord(); }
	void deleteRecord() { /*if (record) { delete record; record = NULL;*/  }
	bool operator==(const HashObject& obj) { return this->record == obj.record; }
	bool operator!=(const HashObject& obj) { return this->record != obj.record; }
	HashObject& operator=(const HashObject& obj) {
		key = obj.key;
		record = obj.record;
		return *this;
	}
	T getKey() { return key; }
	R getRecord() { return record; }
	bool isEqualKey(T key) { return this->key == key; }
	void print() { cout << key << "|" << record; } 
};
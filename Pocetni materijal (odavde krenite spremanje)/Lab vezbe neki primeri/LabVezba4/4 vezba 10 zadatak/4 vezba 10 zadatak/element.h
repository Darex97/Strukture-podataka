#pragma once
#include <iostream>
using namespace std;

template <class T, class R>
class element
{
protected:
	T key;
	R* record;
public:
	bool free;
	element() { key=(T)0; record=NULL; }
	element(T k) { key=k; record=NULL; }
	element(T k, R* object) { key=k, record=object; }
	element& operator=(element const &obj)
	{
		key=obj.key;
		record=obj.record;
		return *this;
	}
	bool operator== (element const &obj)
	{
		if(record==obj.record)
			return true;
		return false;
	}
	void deleteRecord() { if(record) { delete record; record=NULL; } }
	T getKey() { return key; }
	R* getRecord() { return record; }
	bool isEqualKey(T k)
	{
		return (key==k);
	}
	void print() { cout << key << "|" << record; }
};
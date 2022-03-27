#pragma once

#include <iostream>
#include <string.h>

using namespace std;

template <class K, class T>
class HashObject
{
protected:
	K key;
	T record;

public:
	HashObject() { this->key = 0; }
	HashObject(K key) { this->key = 0; }
	HashObject(K key, T object) { this->key = key; this->record = object; }

	virtual ~HashObject() { }

	HashObject& operator=(const HashObject& hashObject);

	K getKey() const { return this->key; }
	bool isEqualByKey(K key) const { return this->key == key; }
	bool isEqualByCharKey(const char* key) const { return strcmp(this->key, key) == 0; }
	void print() const { cout << this->key << " | " << this->record; }
};

template <class K, class T>
HashObject<K, T>& HashObject<K, T>::operator=(const HashObject<K, T>& hashObject)
{
	if (this != &hashObject)
	{
		this->key = hashObject.key;
		this->record = hashObject.record;
	}

	return *this;
}
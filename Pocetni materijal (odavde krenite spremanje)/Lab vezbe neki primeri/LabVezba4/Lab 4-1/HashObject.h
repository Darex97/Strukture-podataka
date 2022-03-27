#pragma once
#include <iostream>

using namespace std;

template <class K, T>
class HashObject
{
private
	K key;
	T* record;
public:
	HashObject();
	HashObject(K key, T* record);
	T getRecord();
	K getKey();
	void deleteRecord();
	~HashObject(void);

	HashObject& operator= (const HashObject& obj) {
		key = obj.key;
		record = obj.record;
		
		return *this;
	}
};

template <class K, T>
HashObject<K, T>::HashObject() {
	key = (K)0;
	record = NULL;
}

template <class K, T>
HashObject<K, T>::HashObject(K key, T* record) {
	this->key = key;
	this->record = record;
}

template <class K, T>
T HashObject<K, T>::getRecord() {
	return record;
}

template <class K, T>
K HashObject<K, T>::getKey() {
	return key;
}

template <class K, T>
void HashObject<K, T>::deleteRecord() {
	if (record)
		delete record;
}

template <class K, T>
HashObject<K, T>::~HashObject() {
	deleteRecord();
}
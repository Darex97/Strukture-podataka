#pragma once

#include <iostream>

using namespace std;

#include "HashTable.h"
#include "ScatterObject.h"
#include "DSException.h"

template <class K, class T>
class OpenScatterTable : public HashTable<K, T>
{
private:
	ScatterObject<K, T>* arrayOfObjects;

public:
	OpenScatterTable(unsigned int length);

	~OpenScatterTable();

	void display() const;

private:
	unsigned int findUnoccupied(const ScatterObject<K, T>& scatterObject) const;

public:
	void insert(const ScatterObject<K, T>& scatterObject);

private:
	unsigned int findMatch(K key) const;

public:
	ScatterObject<K, T> find(K key) const;

	void withdraw(K key);
};

template <class K, class T>
OpenScatterTable<K, T>::OpenScatterTable(unsigned int length) : HashTable<K, T>(length)
{
	this->arrayOfObjects = new ScatterObject<K, T>[this->length];
}

template <class K, class T>
OpenScatterTable<K, T>::~OpenScatterTable()
{
	if (this->arrayOfObjects)
	{
		delete[] this->arrayOfObjects;
	}
}

template <class K, class T>
void OpenScatterTable<K, T>::display() const
{
	for (unsigned int i = 0; i < this->length; i++)
	{
		cout << "[ " << i << " ]";

		if (this->arrayOfObjects[i].status == 2)
		{
			cout << " | ";

			this->arrayOfObjects[i].print();
		}

		cout << endl;
	}
}

template <class K, class T>
unsigned int OpenScatterTable<K, T>::findUnoccupied(const ScatterObject<K, T>& scatterObject) const
{
	unsigned int hash = this->hashCode(scatterObject);
	unsigned int probe = hash;

	int i = 1;

	do
	{
		if (this->arrayOfObjects[probe].status != 2)
		{
			return probe;
		}

		probe = this->secondaryTransformation(probe, i++);
	} while (probe != hash);

	throw DSException("Hash Table is full!");
}

template <class K, class T>
void OpenScatterTable<K, T>::insert(const ScatterObject<K, T>& scatterObject)
{
	if (this->count == this->length)
	{
		cout << "Hash Table is full!" << endl;
	}
	else
	{
		unsigned int offset = this->findUnoccupied(scatterObject);

		this->arrayOfObjects[offset] = scatterObject;
		this->arrayOfObjects[offset].status = 2;

		this->count++;
	}
}

template <class K, class T>
unsigned int OpenScatterTable<K, T>::findMatch(K key) const
{
	unsigned const result = 2654435769 * this->primaryTransformation(key);
	unsigned int probe = result >> (32 - 10);

	for (unsigned int i = 0; i < this->length; i++)
	{
		if (this->arrayOfObjects[probe].status == 0)
		{
			return -1;
		}

		/* 
		   isEqualByCharKey(char* key) metoda sluzi samo za char*, 
		   u ostalim slucajevima je potrebno koristiti isEqualByKey(K key) metodu.
		*/
		if (this->arrayOfObjects[probe].isEqualByCharKey(key))
		{
			return probe;
		}

		probe = this->secondaryTransformation(probe, i);
	}

	return -1;
}

template <class K, class T>
ScatterObject<K, T> OpenScatterTable<K, T>::find(K key) const
{
	unsigned int offset = this->findMatch(key);

	if (offset == -1)
	{
		throw DSException("Element not found!");
	}

	return this->arrayOfObjects[offset];
}

template <class K, class T>
void OpenScatterTable<K, T>::withdraw(K key)
{
	if (this->count == 0)
	{
		cout << "Hash Table is empty!" << endl;
	}
	else
	{
		unsigned int offset = this->findMatch(key);

		if (offset == -1)
		{
			cout << "Element not found!" << endl;
		}
		else
		{
			this->arrayOfObjects[offset].status = 1;
			this->arrayOfObjects[offset].deleteRecord();

			this->count--;
		}
	}
}
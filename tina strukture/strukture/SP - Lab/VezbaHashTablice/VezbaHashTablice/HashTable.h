#pragma once

#include "HashObject.h"

template <class K, class T>
class HashTable
{
protected:
	unsigned int length;
	unsigned int count;

public:
	HashTable(unsigned int length) { this->length = length; this->count = 0; }

	virtual ~HashTable() { }

protected:
	unsigned int primaryTransformation(const char* str) const;
	unsigned int hashCode(const HashObject<K, T>& hashObject) const;
	unsigned int secondaryTransformation(unsigned int value, unsigned int i) const;

public:
	unsigned int getLength() const { return this->length; }
	double getLoadFactor() const { return (double)this->count / this->length; }
};

template <class K, class T>
unsigned int HashTable<K, T>::primaryTransformation(const char* str) const
{
	unsigned int i = 0, result = 0, a = 7;

	while (i < 3)
	{
		result = result << a ^ str[i];

		i += 2;
	}

	i++;

	while (i < 10)
	{
		result = result << a ^ str[i];

		i += 2;
	}

	result = result << a ^ str[strlen(str) - 1];

	return result;
}

template <class K, class T>
unsigned int HashTable<K, T>::hashCode(const HashObject<K, T>& hashObject) const
{
	unsigned const int a = 2654435769;
	unsigned const int k = this->primaryTransformation(hashObject.getKey());

	unsigned const result = a * k;

	return result >> (32 - 10);
}

template <class K, class T>
unsigned int HashTable<K, T>::secondaryTransformation(unsigned int value, unsigned int i) const
{
	return (value + i * i) % this->length;
}
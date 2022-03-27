#include "HashTable.h"

HashTable::HashTable(int length)
{
	this->length = length;
	count = 0;
	array = new HashObject[length];
}

HashTable::~HashTable(void)
{
	delete [] array;
}

void HashTable::insert(HashObject& obj) {
	if (count == length)
		throw "Table is full.";
	
	int index = findUnoccupied(obj);

	array[index] = obj;
	array[index].setStatus(2);
	count++;
}

void HashTable::withdraw(char* key) {
	if (count == 0)
		throw "Table is empty.";
	
	int index = findMatch(key);

	if (index < 0)
		throw "Object is not found.";

	array[index].setStatus(1);
	array[index].deleteRecord();
	count--;
}

void HashTable::withdraw(HashObject& obj) {
	withdraw(obj.getKey());
}

int HashTable::findUnoccupied(HashObject& obj) {
	int test = hash(obj.getKey());
	int index = test;

	if (array[index].getStatus() < 2)
		return index;

	do {
		index = secHash(index);

		if (array[index].getStatus() < 2)
			return index;
	} while(test != index);

	throw "This shouldn't happen.";
}

int HashTable::findMatch(char* key) {
	int index = hash(key);

	for (int i = 0; i < length; i++) {
		if (array[index].getStatus() < 2)
			return -1;

		if (strcmp(array[index].getKey(), key) == 0)
			return index;

		index = secHash(index);
	}

	return -1;
}

int HashTable::hash(char* key) {
	int res = 0;
	int a = 7;

	for (int i = 0; key[i] != 0; i++)
		res = res << a ^ key[i];

	return res % length;
}

int HashTable::secHash(int index) {
	return (3 * index + 1) % length;
}

void HashTable::printTable() {
	for (int i = 0; i < length; i++) {
		cout << i << ": "; array[i].print();
		cout << endl;
	}
}

HashObject& HashTable::find(char* key) {
	int index = findMatch(key);

	if (index >= 0)
		return array[index];

	throw "Element not found.";
}
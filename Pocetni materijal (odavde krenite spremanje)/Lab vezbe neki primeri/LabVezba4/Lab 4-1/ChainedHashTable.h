#pragma once
#include "LList.h"
#include "HashObject.h"

template <class T, K>
class ChainedHashTable
{
private:
	CLList<HashObject<K, T>>* array;
	int capacity;
	int count;
public:
	ChainedHashTable(int length);
	void insert(HashObject<K, T> obj);
	void withdraw(K key);
	void withdraw(HashObject<K, T> obj);
	HashObject<K, T> find (K key);
	~ChainedHashTable(void);

	int hash(char* key) {
		int res = 0;
		int a = 7;

		for (int i = 0; s[i] != 0; i++)
			res = res << a ^ s[i];
		
		return res;
	}
};

template <class T, K>
ChainedHashTable<K, T>::ChainedHashTable(int length) {
	capacity = length;
	count = 0;
	array = new CLList<HashObject<K, T>>[length];
}

template <class T, K>
void ChainedHashTable<K, T>::insert(HashObject<K, T> obj) {
	int index = hash(obj.getKey());
	array[index].addToHead(obj);
	count++;
}

template <class T, K>
void ChainedHashTable<K, T>::withdraw(K key) {
	int index = hash(key);

	CNode* ptr = array[index]->head;

	while (((ptr->data).getKey() != key) && ptr->next != NULL)
		ptr = ptr->next;

	if (ptr->next != NULL)
		array[index].deleteNode(ptr);
}
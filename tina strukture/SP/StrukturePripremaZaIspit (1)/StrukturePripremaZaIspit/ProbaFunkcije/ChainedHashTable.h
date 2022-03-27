#pragma once
#include "HashTable.h"
#include "SLList.h"

template<class T,class R>
class ChainedHashTable :public HashTable<T, R> {
protected:
	SLList < HashObject<T, R> >* niz;

public:
	ChainedHashTable() { HashTable<T, R>::length = 0; HashTable<T, R>::count = 0; this->niz = nullptr; }
	ChainedHashTable(int l) { HashTable<T,R>::length = l; HashTable<T, R>::count = 0; this->niz = new SLList < HashObject<T, R>>[l]; }
	~ChainedHashTable() {
		for (unsigned int i = 0; i < HashTable<T, R>::length; i++)
		{
			SLNode<HashObject<T, R>>* obj = niz[i].getHead();
			while (obj != nullptr) {
				((HashObject<T, R>)obj->getValue()).deleteRecord();
				obj = obj->getNext();
			}
		}
		delete[] niz;
	}

	void insert(HashObject<T, R> obj) {
		niz[HashTable<T,R>::h(obj)].insertHead(obj);
		HashTable<T, R>::count++;
	}
	void withdraw(T key) {
		HashObject<T, R> obj = find(key);
		withdraw(obj);
	}
	void withdraw(HashObject<T, R> obj) {
		niz[HashTable<T, R>::h(obj)].remove(obj.getKey());
		HashTable<T, R>::count--;
	}
	HashObject<T, R>& find(T key) {
		HashObject<T, R> obj;
		unsigned int i = HashTable<T, R>::f(key) % HashTable<T, R>::length;
		obj = niz[i].getHead()->getValue();
	}
	void print() {
		for (unsigned int i = 0; i < HashTable<T, R>::length; i++)
		{
			
			SLNode<HashObject<T, R>>* obj = niz[i].getHead();
			if (obj) {
				cout << obj->getValueRef()->getKey() << " | ";
				while (obj != nullptr) {
					cout << (obj->getValueRef()->getRecord()) << " -> ";
					obj = obj->getNext();
				}
			}
		}
	}

};
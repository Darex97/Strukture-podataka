#pragma once
#include <iostream>
using namespace std;

template<class T,class R>
class KeySLNode {
protected:
	T value;
	R key;
	KeySLNode<T,R>* next;
public:
	KeySLNode() {
		this->value = (T)0;
		this->key = (R)0;
		next = nullptr;
	}
	KeySLNode(T value,R key) {
		this->value = value;
		this->key = key;
		next = nullptr;
	}
	KeySLNode(T value,R key, KeySLNode<T,R>* next)
	{
		this->value = value;
		this->key = key;
		this->next = next;
	}
	~KeySLNode() { /*if (next) { delete next; next = nullptr; }*/ }
	T getValue() { return value; }
	T& getValueRef() { return value; }
	R getKey() { return key; }
	R& getKeyRef() { return key; }
	KeySLNode<T,R>* getNext() { return next; }
	KeySLNode<T,R>*& getNextRef() { return next; }
};
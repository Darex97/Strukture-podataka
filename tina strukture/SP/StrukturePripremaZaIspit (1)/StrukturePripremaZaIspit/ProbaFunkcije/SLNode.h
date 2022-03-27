#pragma once
#include <iostream>
using namespace std;

template<class T>
class SLNode {
protected :
	T value;
	SLNode<T>* next;
public:
	SLNode() {
		this->value = (T)0;
		next = nullptr;
	}
	SLNode(T value) {
		this->value = value;
		next = nullptr;
	}
	SLNode(T& value, SLNode<T>* next)
	{
		this->value = value;
		this->next = next;
	}
	~SLNode() { /*if (next) { delete next; next = nullptr; }*/ }
	T getValue() { return value; }
	T* getValueRef() { return &value; }
	SLNode<T>* getNext() { return next; }
	SLNode<T>*& getNextRef() { return next; }
};

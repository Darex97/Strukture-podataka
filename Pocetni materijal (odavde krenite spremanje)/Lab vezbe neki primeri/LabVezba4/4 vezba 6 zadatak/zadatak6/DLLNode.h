#pragma once
#include <cstring>

template <class T>
class DLLNode
{
public:
	T info;
	DLLNode<T> *prev, *next;
	DLLNode(void);
	DLLNode(T el);
	DLLNode(T el, DLLNode<T>* p, DLLNode<T>* n);
	virtual ~DLLNode(void);
	T print();
	bool isEqual(T el);
};
template <class T>
DLLNode<T>::DLLNode()
{
	prev = NULL;
	next = NULL;
}
template <class T>
DLLNode<T>::DLLNode(T el)
{
	info = el;
	prev = NULL;
	next = NULL;
}
template <class T>
DLLNode<T>::DLLNode(T el, DLLNode<T> *p, DLLNode<T> *n)
{
	info = el;
	this->next=n;
	this->prev=p;
}
template <class T>
T DLLNode<T>::print()
{
	return info;
}
template <class T>
bool DLLNode<T>::isEqual(T el)
{
	if(el==this->info)
		return true;
	else return false;
}
template <class T>
DLLNode<T>::~DLLNode()
{
}
